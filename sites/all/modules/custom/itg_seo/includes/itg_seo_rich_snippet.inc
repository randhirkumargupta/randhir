<?php

/*
 * add_nofollow_in_body
 */
function add_nofollow_in_body($bodytext) {
  $site_name = $_SERVER['SERVER_NAME'];
  $live_url = 'indiatoday.intoday.in';
  $body_html_dom = filter_dom_load($bodytext);
  $body_links = $body_html_dom->getElementsByTagName('a');
  foreach ($body_links as $body_link) {
    $body_url = parse_url($body_link->getAttribute('href'));
    if ($body_url['host']) {
      $path = $body_url['host'];
    }
    else {
      $path_arr = explode('/', $body_url['path']);
      if (is_array($path_arr) && !empty($path_arr[0])) {
        $path = $path_arr['0'];
      }
    }

    $skip_sites = array($site_name, $live_url);
    if (!in_array($path, $skip_sites)) {
      $body_link->setAttribute('rel', 'nofollow');
    }
  }
  $new_body_text = filter_dom_serialize($body_html_dom);
  return $new_body_text;
}

/*
 * Updating rich snippet for node type story, videogallery and mega review critic
 */
function itg_seo_node_data($node) {
  $arg = arg();
  global $base_url, $theme_key; 
  
  // Rich Snippet for Story
  if ($node->type == 'story') {
    // Adding noindex, nofollow for making content search engin friendly
    if(isset($node->field_story_configurations[LANGUAGE_NONE])) {
      $configurableopt = $node->field_story_configurations[LANGUAGE_NONE];
    }
    if(isset($configurableopt) && is_array($configurableopt) && !empty($configurableopt)){
      foreach ($configurableopt as $key => $value){
        $opt_value[] = $value['value'];
      }
      if (in_array("noindex_nofollow", $opt_value) && in_array("nofollow", $opt_value)) {
        $element = array(
           '#tag' => 'meta',
           '#attributes' => array(
             'name' => 'robots',
             'content' => 'noindex, nofollow',
           ),
        );
      } 
      else if(in_array("nofollow", $opt_value)) {
        $element = array(
           '#tag' => 'meta',
           '#attributes' => array(
             'name' => 'robots',
             'content' => 'nofollow',
           ),
        );
      }
      else if(in_array("noindex_nofollow", $opt_value)) {
        $element = array(
           '#tag' => 'meta',
           '#attributes' => array(
             'name' => 'robots',
             'content' => 'noindex',
           ),
        );
      }
     if (!empty($element)) {
      drupal_add_html_head($element, 'robots');
     }
    }
    
    // Rich Snippet for Story
    $mainEntityOfPage = $base_url . '/' . $node->path['alias'];
    $headline = $node->field_story_short_headline[LANGUAGE_NONE][0]['value'];
    if (is_array($node->workbench_moderation) && !empty($node->workbench_moderation) && $node->workbench_moderation['current']->state == 'published') {
      //$publisheddate = date('Y-m-d\Th:i:s+5:30', $node->workbench_moderation['current']->timestamp);
      $publisheddate = date('Y-m-d\TH:i:s+5:30', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value']));
    } else {
      $publisheddate = date('Y-m-d\TH:i:s+5:30', $node->changed);
    }
    $modified_date = date('Y-m-d\TH:i:s+5:30', $node->changed);
    $description = strip_tags(substr(str_replace("&#13;", "", $node->body[LANGUAGE_NONE][0]['value']),0,120));
    $story_kicker = strip_tags(str_replace(array('&#13;','"'), "", $node->field_story_kicker_text[LANGUAGE_NONE][0]['value']));
    $meta_description = $node->metatags[LANGUAGE_NONE]['description']['value'];
    $description_text = !empty($story_kicker) ? $story_kicker : $meta_description; 
    $bylines = itg_get_multi_byline_details($node->nid, 1);
    $authname = array();
    foreach ($bylines AS $bylines_val) {
      $authname[] = $bylines_val['title'];
    }
    if (is_array($authname) && count($authname) > 0) {
      $authors = implode(',', $authname);
    } else {
      $authors = 'India Today';
    }
    $logo = $base_url . '/' . drupal_get_path('theme', $theme_key) . '/logo.png';
    if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
      $largimage = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']); //explode('//', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    } else {
      $largimage = $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image647x363.jpg';
    }
    $primary_category = $node->field_primary_category[LANGUAGE_NONE][0]['value'];
    if (isset($primary_category) && $primary_category == '1207047') {
        $review_item_type = 'Movie';
        $worstrate = 0;
        $bestrate = 5;
        $auth_name = str_replace(' ', '-', trim($authname[0]));
        $auth_title = ($authname[0]) ? $authname[0] : 'India Today';
        $author_url = FRONT_URL . '/topic/' . $auth_name;
        $moviename = trim($node->field_mega_review_movie_plot[LANGUAGE_NONE][0]['value']);
        $directorname = trim($node->field_mega_review_director[LANGUAGE_NONE][0]['value']);
        $imdb_url = trim($node->field_review_movie_imdb_url[LANGUAGE_NONE][0]['value']);
        $story_rating = trim($node->field_story_rating[LANGUAGE_NONE][0]['value']);
     
        $pathalias = drupal_get_path_alias('node/' . $node->nid);
        $pageurl = $base_url . '/' . $pathalias;
		$markup = array(
				'#type' => 'markup',
				'#markup' => '<script type="application/ld+json">
								{
									  "@context": "http://schema.org",
									  "@type": "Review",
									  "author": {
										  "@type": "Person",
										  "name": "' . $auth_title . '",
										  "sameAs": "' . $author_url . '"
									  },

									  "datePublished": "' . $publisheddate . '",
									  "name": "' . $moviename . '",
									  "itemReviewed": {
										  "@type": "' . $review_item_type . '",
										  "name": "' . $moviename . '",
										  "image": "' . $largimage . '",
										  "datePublished": "' . $publisheddate . '",
										  "sameAs": "' . $imdb_url . '",
										  "director": "' . $directorname . '"
									  },
									  "reviewRating": {
										  "@type": "Rating",
										  "worstRating": ' . $worstrate . ',
										  "bestRating": ' . $bestrate . ',
										  "ratingValue": ' . $story_rating . '
									  },
									  "url": "' . $pageurl . '",
									  "description": "' . $description_text . '",
									  "publisher": {
										  "@type": "Organization",
										  "name": "India Today"
									  }
								  }
								</script>',
			);
    }elseif (isset($primary_category) && $primary_category == '1207760'){
        $start = strpos($node->body[LANGUAGE_NONE][0]['value'], '<p>');
        $end = strpos($node->body[LANGUAGE_NONE][0]['value'], '</p>', $start);
        $first_para = substr($node->body[LANGUAGE_NONE][0]['value'], $start, $end);
        $first_paragraph = str_replace('</p>', '', $first_para);
        $first_paragraph = str_replace('<p>', '', $first_paragraph);
        $first_paragraph = str_replace('"', "'", $first_paragraph);
        $first_paragraph = str_replace('”', "'", $first_paragraph);
        $first_paragraph = str_replace('“', "'", $first_paragraph);
        $first_paragraph = strip_tags($first_paragraph);
        $page_title = explode(":",$node->title);
        $review_title = !empty($page_title[0]) ? $page_title[0] : $node->title;
        $review_title = str_replace('"', "'", $review_title);
        $review_title = str_replace('”', "'", $review_title);
        $review_title = str_replace('“', "'", $review_title);
        $auth_name = str_replace(' ', '-', trim($authname[0]));
        $auth_title = ($authname[0]) ? $authname[0] : 'India Today';
        $author_url = ''.FRONT_URL.'/topic/'.$auth_name;
        $keywords = $node->metatags[LANGUAGE_NONE]['keywords']['value'];
        $rating = !empty($node->field_story_tech_pros_cons_ratin[LANGUAGE_NONE][0]['value']) ? $node->field_story_tech_pros_cons_ratin[LANGUAGE_NONE][0]['value'] : 0;

        $pathalias = drupal_get_path_alias('node/' . $node->nid);
        $pageurl = $base_url . '/' . $pathalias;

        $markup = array(
            '#type' => 'markup',
            '#markup' => '<script type="application/ld+json">
                      {
                "@context": "https://schema.org",
                "@type": "Review",
                "reviewBody": "'.$first_paragraph.'",
                "author": [
                  {
                    "@type": "Person",
                    "url": "'.$author_url.'",
                    "name": "'.$auth_name.'"
                  }
                ],
                "datePublished": "'.$publisheddate.'",
                "keywords": ["'.$keywords.'"],
                "itemReviewed": "'.$review_title.'",
                "reviewRating": [
                  {
                    "@type": "Rating",
                    "ratingValue": "'.$rating.'",
                    "bestRating": "10",
                    "worstRating": "0"
                  }
                ],
                "sourceOrganization": [
                  {
                    "@type": "Organization",
                    "name": "India Today",
                    "url": "'.FRONT_URL.'",
                    "logo": [
                      {
                        "@type": "ImageObject",
                        "url": "'.FRONT_URL.'/sites/all/themes/itg/logo.png",
                        "width": "128px",
                        "height": "128px"
                      }
                    ]
                  }
                ]
              }
              </script>',
        );
    } else {
        $markup = array(
             '#type' => 'markup',
             '#markup' => '<script type="application/ld+json"> {  
                         "@context": "http://schema.org",
                         "@type": "NewsArticle",
                         "mainEntityOfPage": "' . $mainEntityOfPage . '",
                         "headline": "' . $headline . '",
                         "datePublished": "' . $publisheddate . '",
                         "dateModified": "' . $modified_date . '",
                         "description": "' . $description_text . '",
                         "author": {
                         "@type": "Person",
                         "name": "' . $authors . '"
                         },
                         "publisher": {
                         "@type": "Organization",
                         "name": "India Today",
                         "logo": {
                         "@type": "ImageObject",
                         "url": "' . $logo . '",
                         "width": 600,
                         "height": 60
                         }
                         },
                         "image": {
                         "@type": "ImageObject",
                         "url": "' . $largimage . '",
                         "width": 647,
                         "height": 363
                         }
                         }  </script>',
           );
    }
     
    drupal_add_html_head($markup, 'sd_json');
    
    if (is_array($node->field_story_configurations[LANGUAGE_NONE]) && !empty($node->field_story_configurations[LANGUAGE_NONE])) {
        $configurableopt = $node->field_story_configurations[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $node->path['alias'];
          $google_standout = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
          drupal_add_html_head($google_standout, 'standout');
        }
    }
  }
  // Rich Snippet for Movie Review
  elseif ($node->type == 'mega_review_critic') {
    $pathalias = drupal_get_path_alias('node/' . $node->nid);
    $pageurl = $base_url . '/' . $pathalias;
    $megreview_value = $node->field_mega_review_review[LANGUAGE_NONE];
    foreach ($megreview_value as $k => $v) {
      $fc_value = field_collection_item_load($v['value']);
      $reviewtype[] = $fc_value->field_story_review_type[LANGUAGE_NONE][0]['value'];
      $rating[] = $fc_value->field_story_rating[LANGUAGE_NONE][0]['value'];
    }
    $element_key = array_search("internal", $reviewtype);
    if ($reviewtype[$element_key] == 'internal') {
      $internal_fcid = $megreview_value[$element_key]['value'];
      $internalfc_value = field_collection_item_load($internal_fcid);
      $author_name = $internalfc_value->field_story_reporter[LANGUAGE_NONE][0]['entity']->title;
      $worstrate = min($rating);
      $bestrate = max($rating);
      $avaragrate = number_format(array_sum($rating) / sizeof($rating), 1);
    }
    $fieldcollections = $node->field_mega_review_review[LANGUAGE_NONE];
    $moviename = $node->title;
    $review_item_type = $node->field_mega_review_type[LANGUAGE_NONE][0]['taxonomy_term']->name;
    $imgarray = explode('//', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    $largimage = $base_url . '/' . 'sites/default/files/' . $imgarray[1];
    //$publisheddate = date('Y-m-d\Th:i:s+5:30', $node->changed);
    $publisheddate = date('Y-m-d\TH:i:s+5:30', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value']));
    $directorname = $node->field_mega_review_director[LANGUAGE_NONE][0]['value'];
    $moviedescription = $node->field_story_movie_description[LANGUAGE_NONE][0]['value'];
    $markup = array(
        '#type' => 'markup',
        '#markup' => '<script type="application/ld+json">
                        {"@context" : "http://schema.org",
                            "@type" : "Review",
                            "author" : {"@type" : "Person",  "name" : "' . $author_name . '","sameAs":"' . $pageurl . '"},

                                        "datePublished" : "' . $publisheddate . '",
                            "name" : "' . $moviename . '",
                            "itemReviewed" : {"@type": "' . $review_item_type . '","name" : "' . $moviename . '","image":"' . $largimage . '","datePublished" : "' . $publisheddate . '","sameAs":"http://indiatoday.intoday.in/story/jolly-llb-2-movie-review-akshay-kumar/1/879596.html"  ,"director":"' . $directorname . '" },
                            "reviewRating" : {"@type" : "Rating","worstRating" : ' . $worstrate . ',"bestRating" : ' . $bestrate . ',"ratingValue" : ' . $avaragrate . '},
                            "url" : "' . $pageurl . '",
                            "description" : "' . $moviedescription . '",
                            "publisher" : {"@type" : "Organization","name" : "India Today"}
                        }
                        </script>',
    );

    drupal_add_html_head($markup, 'sd_json');
  }
  // Rich Snippet for Videos Rich Snippet
  elseif ($node->type == 'videogallery') {
	$logo = $base_url . '/' . drupal_get_path('theme', $theme_key) . '/logo.png';
    $video_time = explode(':', $node->field_video_duration[LANGUAGE_NONE][0]['value']);
    $video_duration = t("PT" . $video_time[0] . "M" . $video_time[1] . "S");
    $name = $node->field_story_short_headline[LANGUAGE_NONE][0]['value'];
    $description = $node->title;
    if (is_array($node->workbench_moderation) && !empty($node->workbench_moderation) && $node->workbench_moderation['current']->state == 'published') {
      //$publisheddate = date('Y-m-d\Th:i:s+5:30', $node->workbench_moderation['current']->timestamp);
      $publisheddate = date('Y-m-d\TH:i:s+5:30', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value']));
    } else {
      $publisheddate = date('Y-m-d\TH:i:s+5:30', $node->changed);
    }
    $createdate = date('Y-m-d\Th:i:s+5:30', $node->created);
    $contenturl = $base_url . '/' . $node->path['alias'];
    //$imgarray = explode('//', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    $thumb_uri = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
    $extra_large_image = file_create_url($thumb_uri);
    //$thumbnail_url = $base_url . '/' . 'sites/default/files/' . $imgarray[1];
    $markup = array(
        '#type' => 'markup',
        '#markup' => '<script type="application/ld+json">
        {
        "@context": "http://schema.org",
        "@type": "VideoObject",
        "name": "' . $name . '",
          "description":"' . $description . '",
          "thumbnailUrl": "' . $extra_large_image . '",
            "duration":"' . $video_duration . '",
            "genre":"",  
            "inLanguage":"",
            "thumbnail": "' . $extra_large_image . '",
            "uploadDate":"' . $createdate . '",
            "contentURL":"' . $contenturl . '",
            "url":"' . $contenturl . '",
            "releasedEvent": {
                        "@type": "PublicationEvent",
                        "startDate": "' . $publisheddate . '"
                        },
            "publisher": {
            "@type": "Organization",
            "name": "India Today",
            "logo": {
            "@type": "ImageObject",
            "url": "' . $logo . '",
            "width": 600,
            "height": 60
            }
            },
                "potentialAction": [
                               {
                                 "@type": "ViewAction",
                                 "target": {
                                   "url": "' . $contenturl . '",
                                   "inLanguage": "English",
                                   "actionPlatform": [
                                     "http://schema.org/DesktopWebPlatform",
                                     "http://schema.org/MobileWebPlatform"
                                    
                                   ]
                                 }
                               }
                             ]
          }        
 
        </script>  ',
    );
    drupal_add_html_head($markup, 'sd_json');
    
    if (is_array($node->field_video_configurations[LANGUAGE_NONE]) && !empty($node->field_video_configurations[LANGUAGE_NONE])) {
        $configurableopt = $node->field_video_configurations[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $node->path['alias'];
          $google_standout = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
          drupal_add_html_head($google_standout, 'standout');
        }
      }
  } 
  elseif ($node->type == 'photogallery') {
      if (is_array($node->field_photogallery_configuration[LANGUAGE_NONE]) && !empty($node->field_photogallery_configuration[LANGUAGE_NONE])) {
        $configurableopt = $node->field_photogallery_configuration[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $node->path['alias'];
          $google_standout = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
          drupal_add_html_head($google_standout, 'standout');
        }
      }
    } 
    else if ($node->type == 'podcast') {
      if (is_array($node->field_podcast_configuration[LANGUAGE_NONE]) && !empty($node->field_podcast_configuration[LANGUAGE_NONE])) {
        $configurableopt = $node->field_podcast_configuration[LANGUAGE_NONE];
        foreach ($configurableopt as $key => $value) {
          $opt_value[] = $value['value'];
        }
        if (in_array("google_standout", $opt_value)) {
          $standout_path = $base_url . '/' . $node->path['alias'];
          $google_standout = array(
            '#type' => 'html_tag',
            '#tag' => 'link',
            '#attributes' => array('rel' => 'standout', 'href' => $standout_path),
          );
          drupal_add_html_head($google_standout, 'standout');
        }
      }
    }
}

/*
 * Returns Story Author Name for story rich snippett
 */
function itg_get_story_author_name($auth_id){
  if(!empty($auth_id)) {
  $author_name = db_query("SELECT title from {node} WHERE nid = :nid ", array(":nid" => $auth_id))->fetchField();
  return $author_name;
  }
}

/*
 * Returns Story Author Name for story rich snippett
 */

function itg_get_story_authors_name($auth_ids) {
  $auth_ids = explode(',', $auth_ids);
  if (!empty($auth_ids)) {
    $query = db_select('node', 'n');
    $query->fields('n', array('title'));
    $query->condition('n.nid', $auth_ids, 'IN');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $auth_names = '';
    if (count($result) > 0) {
      foreach ($result as $value) {
        $auth_names[] = $value['title'];
      }
      return implode(',', $auth_names);
    }
    return $auth_names;
  }
}

/*
 * Returns Edited by
 */

function itg_get_story_edited_authors_name($uid) {
  if (!empty($uid)) {
    $author_name = db_query("SELECT name from {users} WHERE uid = :uid ", array(":uid" => $uid))->fetchField();
    return $author_name;
  }
}
