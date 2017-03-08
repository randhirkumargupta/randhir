<?php

/*
 * Updating rich snippet for node type story, videogallery and mega review critic
 */
function itg_seo_node_data($node) {
  global $base_url, $theme_key;
  
  // Adding noindex, nofollow for making content search engin friendly
  if($node->type == 'story') {
    $configurableopt = $node->field_story_configurations[LANGUAGE_NONE];
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
  } 
  
  
  // Rich Snippet for Story
  if ($node->type == 'story') {
    $mainEntityOfPage = $base_url . '/' . $node->path['alias'];
    $headline = $node->field_story_short_headline[LANGUAGE_NONE][0]['value'];
    if (is_array($node->workbench_moderation) && !empty($node->workbench_moderation) && $node->workbench_moderation['current']->state == 'published') {
      $publisheddate = date('Y-m-d\Th:i:s+5:30', $node->workbench_moderation['current']->timestamp);
    } else {
      $publisheddate = date('Y-m-d\Th:i:s+5:30', $node->changed);
    }
    $modified_date = date('Y-m-d\Th:i:s+5:30', $node->changed);
    $description = strip_tags(substr($node->body[LANGUAGE_NONE][0]['value'],0,120));
    if (isset($node->field_story_reporter[LANGUAGE_NONE][0]['target_id'])) {
      $get_author_name = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
    }
    if(!empty($get_author_name) && ($get_author_name > 0)){
      $auth_name = itg_get_story_author_name($get_author_name);
    } else {
      $auth_name = '';
    }
    $logo = $base_url . '/' . drupal_get_path('theme', $theme_key) . '/logo.png';
    $imgarray = explode('//', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    $largimage = $base_url . '/' . 'sites/default/files/' . $imgarray[1];

    $markup = array(
        '#type' => 'markup',
        '#markup' => '<script type="application/ld+json"> {  
                    "@context": "http://schema.org",

                    "@type": "NewsArticle",
                    "mainEntityOfPage": "' . $mainEntityOfPage . '",
                    "headline": "' . $headline . '",
                    "datePublished": "' . $publisheddate . '",
                    "dateModified": "' . $modified_date . '",
                    "description": "' . $description . '",
                    "author": {
                    "@type": "Person",
                    "name": "' . $auth_name . '"
                    },
                    "publisher": {
                    "@type": "Organization",
                    "name": "India Today",
                    "logo": {
                    "@type": "ImageObject",
                    "url": "' . $logo . '",
                    "width": 109,
                    "height": 90
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

    drupal_add_html_head($markup, 'sd_json');
  }

  // Rich Snippet for Movie Review
  if ($node->type == 'mega_review_critic') {
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
    $publisheddate = date('Y-m-d\Th:i:s+5:30', $node->changed);
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
  if ($node->type == 'videogallery') {
    $video_time = explode(':', $node->field_video_duration[LANGUAGE_NONE][0]['value']);
    $video_duration = t("PT" . $video_time[0] . "M" . $video_time[1] . "S");
    $name = $node->field_story_short_headline[LANGUAGE_NONE][0]['value'];
    $description = $node->title;
    if (is_array($node->workbench_moderation) && !empty($node->workbench_moderation) && $node->workbench_moderation['current']->state == 'published') {
      $publisheddate = date('Y-m-d\Th:i:s+5:30', $node->workbench_moderation['current']->timestamp);
    } else {
      $publisheddate = date('Y-m-d\Th:i:s+5:30', $node->changed);
    }
    $createdate = date('Y-m-d\Th:i:s+5:30', $node->created);
    $contenturl = $base_url . '/' . $node->path['alias'];
    $imgarray = explode('//', $node->field_story_extra_small_image[LANGUAGE_NONE][0]['uri']);
    $thumbnail_url = $base_url . '/' . 'sites/default/files/' . $imgarray[1];
    $markup = array(
        '#type' => 'markup',
        '#markup' => '<script type="application/ld+json">
        {
        "@context": "http://schema.org",
        "@type": "VideoObject",
        "name": "' . $name . '",
          "description":"' . $description . '",
          "thumbnailUrl": "' . $thumbnail_url . '",
            "duration":"' . $video_duration . '",
            "name": "IndiaToday",
            "genre":"",  
            "inLanguage":"",
            "thumbnail": "' . $thumbnail_url . '",
            "thumbnailUrl": "' . $thumbnail_url . '",
            "playerType":"Dailymotion",
            "uploadDate":"' . $createdate . '",
            "contentURL":"' . $contenturl . '",
            "url":"' . $contenturl . '",
            "releasedEvent": {
                        "@type": "PublicationEvent",
                        "startDate": "' . $publisheddate . '"
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
  }
}

/*
 * Returns Story Author Name for story rich snippett
 */
function itg_get_story_author_name($auth_id){
  $author_name = db_query("SELECT title from {node} WHERE nid = :nid ", array(":nid" => $auth_id))->fetchField();
  return $author_name;
}