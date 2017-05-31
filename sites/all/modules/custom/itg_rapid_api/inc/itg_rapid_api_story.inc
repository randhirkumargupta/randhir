<?php


/**
 * main function for generate StoryDetailPageRerourceValue array
 *
 * @return array
 */

function StoryDetailPageRerourceValue($id){
    // variable decalartion
    $output_array = array();
    $data_array = array();
    $photo_list_array = array();
       
    
    // list array building
    $data = generateStoryDeatilList($id); 
    if(!empty($data['data']['title'])){
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";  
    }
    else{
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";  
    }
    
    $output_array['data'] = $data['data'];
    
    return $output_array;
}


/**
 * function for generate generateStoryDeatilList JSON
 *
 * @return array
 */

function generateStoryDeatilList($id){
    // variable declaration    
    global $base_url; 
    $data = array();
    $nid = $id;
    $photo_list_array = array();
    $data_array = array();
    $node = node_load($nid);
    //print_r($node);
    // variable for feed
    $title = $node->title;
    $tid = $node->field_primary_category['und'][0]['value'];
    $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
    $body_without_html = $node->body['und'][0]['value'];
    //$body_without_html = "";
    $director = $node->field_mega_review_director[LANGUAGE_NONE]['0']['value'];
    $movie_plot = $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value'];
    $body_with_html = story_body_with_html($node);
    //$body_with_html = "";
    $load_city = taxonomy_term_load($node->field_stroy_city['und'][0]['tid']);
    $location = $load_city->name;
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    //$comment_cont = $node->comment;
    $alias = drupal_get_path_alias('node/'.$nid.'');
    $weburl = $base_url ."/". $alias;
    $galleryimg = $node->field_gallery_image['und'];
    $toptlapics = count($galleryimg);
    $changed = $node->changed;
    $changed_datetime = date("Y-m-d H:i:s", $changed);
    $comment_cont = getCommentsCount($nid);
    $tag = getTag($nid);
    $heighligth = getHighlight($nid);
    $author = getAuthor($nid);
    $rating = getRating($nid);
    
    //data array building
    
    $data_array['category_id'] = "$tid";
    $data_array['category_title'] = "$term_name";
    $data_array['id'] = "$nid";
    $data_array['title'] = "$title";
    $data_array['large_image'] = "$extra_large_image";
    $data_array['image_credit'] = "";
    $data_array['image_caption'] = "";
    $data_array['updated_datetime'] = "$changed_datetime";
    $data_array['published_datetime'] = "";
    $data_array['location'] = "$location";
    $data_array['director'] = "$director";
    $data_array['movie_plot'] = "$movie_plot";
    $data_array['star_cast'] = "";
    $data_array['share_link'] = "Universal link";
    $data_array['comment_count'] = "$comment_cont";
    $data_array['is_sponsored'] = "";
    $data_array['sponsored_icon'] = "";
    $data_array['sponsored_url'] = "";
    $data_array['desc_withouthtml'] = "$body_without_html";
    $data_array['desc_withhtml'] = "$body_with_html";
    $data_array['tag'] = $tag;
    $data_array['highlight'] = $heighligth;
    $data_array['author'] = $author;
    $data_array['rating'] = $rating;
    
    $data['data'] = $data_array;
    return $data;
}

/**
 * function for get story tag
 * @pram $nid
 *
 * @return array
 */
function getTag($nid){
    $tag = array();
    
    $tag[0]['t_id'] = "1";
    $tag[0]['t_title'] = "text";    
    $tag[1]['t_id'] = "1";
    $tag[1]['t_title'] = "text";
    
    return $tag;
}

/**
 * function for get story highlight
 * @pram $nid
 *
 * @return array
 */
function getHighlight($nid){
    $heighlight = array();
    
    $heighlight[0]['h_title'] = "text";
    $heighlight[1]['h_title'] = "text";
    
    return $heighlight;
}


/**
 * function for get story author
 * @pram $nid
 *
 * @return array
 */
function getAuthor($nid){
    $author = array();
    
    $author['a_id'] = "11";
    $author['a_title'] = "11";
    $author['a_image'] = "11";
    $author['a_twitter_handler'] = "11";
    
    return $author;
}

/**
 * function for get story rating
 * @pram $nid
 *
 * @return array
 */
function getRating($nid){
    $rating = array();
    
    $rating['r_cur_value'] = "3";
    $rating['r_upper_range'] = "5";
    $rating['r_is_star_rating'] = "0";
    
    return $rating;
    
    
}

/**
 * function for story body html
 * @pram $node
 * @return string
 */

function story_body_with_html($node){
    
$output = '';
//Basic Variable details
// get related content associated with story
  $related_content = $content['related_content'];
  // condition for buzz
  if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
    $class_buzz = 'buzz-feedback';
  }
  if (!empty($related_content)) {
    $class_related = ' buzz-related';
  }
  if (!empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
    $class_listicle = ' buzz-feedback listicle-feedback';
  }
  // prepare url for sharing
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
  $short_url = shorten_url($actual_link, 'goo.gl');
  $fb_title = addslashes($node->title);
  $share_desc = '';
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);

  // get total share count
  $tot_count = $content['total_share_count'];

  // get global comment config    

  $config_name = trim($global_comment_last_record[0]->config_name);

  // get comment count

  $get_comment_count = $content['comment_count'];

  // get developing story status

  $get_develop_story_status = $content['develop_story_status'];

  //get follow story status

  $follow_status = $content["follow_status"];

  $migrated_count = $content["migrated_count"];
  //get byline id based on order reorder

  $byline_id = $content["byline_id"];

  //get byline detail
  if (!empty($byline_id)) {
    $reporter_node = node_load($byline_id);
  }
  
  // get posted by info
  $node_author = $content["author"];
  /*if (function_exists('itg_get_front_activity_info')) {
    $opt = $content["front_activity_info"];
  }*/
  $opt = $content["front_activity_info"];
  
  if ($node->field_story_type[LANGUAGE_NONE][0]['value'] == 'photo_story') {
    $photo_story_section_class = ' photo-story-section';
  }

//End of the Variables
$list_class = '';

 //code for Associate lead
      $associate_type = '';
      $associate_id = '';

      if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
        $associate_type = 'gallery';
        $associate_id = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
      }
      else if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') {
        $associate_type = 'video';
        $associate_id = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
      }

      $clidk_class_slider = "";
      $widget_data = '';

      if ($associate_type != "" && $associate_id != "") {
        $clidk_class_slider = 'associate-content-block';
        $widget_data = $associate_type . '-' . $associate_id;
      }

      //code end for Associate lead

$list_class = '';

if ((!empty($node->field_story_type) && $node->field_story_type[LANGUAGE_NONE][0]['value'] == 'other_story') || (empty($node->field_story_type))) { 
    if (!empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
            $list_class = ' listicle-page';
    }
    $output  .= "<div class='story-right ".$list_class."'>";
    
    $associate_lead = $node->field_story_associate_lead[LANGUAGE_NONE][0]['value'];
    $associate_photo = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
    $associate_video = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
    
    $class = '';
    if (!empty($associate_lead) && (isset($associate_photo) || isset($associate_video))) {
        $class = 'story-associate-content';
    }
    
    $output  .= "<div class='".$class."'>";
     if (!empty($associate_lead) && (isset($associate_photo) || isset($associate_video))) {
        $output  .= "<div id='videogallery-iframe'>
        <img class='loading-popup' src='".$base_url."'/sites/all/themes/itg/images/reload.gif' alt='loading' />
        </div>";
     }
     if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
         $output .= "<div class='stryimg'>";
         
          if (empty($widget_data)) {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    else {
                      $file_uri = $base_url . '/sites/all/themes/itg/images/itg_image647x363.jpg';
                    }
                    
                    $output .= "<img  alt='".$node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']."' title='".$node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']."' src='" . $file_uri . "'>";
                    }else {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    else {
                      $file_uri = $base_url . '/sites/all/themes/itg/images/itg_image647x363.jpg';
                    }
                    $output .= "<a href='javascript:void(0);' class='" . $clidk_class_slider . "' data-widget='" . $widget_data . "'><img  alt='' title='" . $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] . "' src='" . $file_uri . "'><span class='story-photo-icon'>";
                    if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') {
                      $output .= "<i class='fa fa-play-circle'></i>";
                    
                    }
                    else if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
                      $output .= "<i class='fa fa-camera'></i>";
                    
                    }
                    $output .= "</span></a>";
                  }
                  
                   if (!empty($getimagetags)) {
                    foreach ($getimagetags as $key => $tagval) {
                      $urltags = addhttp($tagval->tag_url);
                      $output .= "<div class='tagview' style='left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;' ><div class='square'></div><div  class='person' style='left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;'><a href=' . $urltags . ' target='_blank'>' . ucfirst($tagval->tag_title) . '</a></div></div>";
                    }
                  }
         
     }else{
         
         $output .= "<div class='stryimg'>";
         $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    $file_uri = file_create_url($story_image);
                    $output .= "<a href='javascript:void(0);' class=' . $clidk_class_slider . ' data-widget=' . $widget_data . '><img  alt='.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'].' title=' . $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] . ' src=' . $file_uri . '><span class='story-photo-icon'>        
                                    <i class='fa fa-play-circle'></i>
                                    <i class='fa fa-camera'></i></span></a>";
                    if (!empty($getimagetags)) {
                      foreach ($getimagetags as $key => $tagval) {
                        $urltags = addhttp($tagval->tag_url);
                        $output .= "<div class='tagview' style='left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;' ><div class='square'></div><div  class='person' style='left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;'><a href=' . $urltags . ' target='_blank'>" . ucfirst($tagval->tag_title) . "</a></div></div>";
                      }
                    }
         
     }
     
      if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) {
                    $output .= "<div class='photoby'>";
                    if (!empty($node->field_story_technology_rating[LANGUAGE_NONE][0]['value'])) {
                        $output .= "<div class='story-img-rating'>";
                        $tech_rating = $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'];
                        $output .= $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'] . '/10';
                        
                        $output .= "</div>";
                      } 
                      if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'])) {
                        $output .= "<div class='photoby-text'>";
                        $output .= $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'];
                        $output .= "</div>";
                      }
                    $output .= "</div>";
                  } 
            $output .= "</div>";
            
           if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'])) {    
                $output .= "<div class='image-alt'>";
                     $output .= $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'];
                $output .= "</div>";
            }
            $output .= "</div>";
            
              if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) {
                 $output .= "<div class='briefcase desktop-hide'>";
                 $output .= '<h4>'.t('Briefcase').'</h4>';
                 $output .= "<ul>";
                      foreach ($node->field_story_highlights['und'] as $high) {
                        $output .= "<li>" . $high['value'] . "</li>";
                      }
                    $output .= "</ul>";
                  $output .= "</div>";
                }
              }
            $output .= "<div class='story-movie'>";
                if (!empty($node->field_story_rating)){
                 $rate = print $node->field_story_rating[LANGUAGE_NONE]['0']['value'] * 20 . "%";
                 $output .= "<div class='movie-rating' data-star-value=".$rate.">";
                 $output .= "</div>";                            
                }
                $output .= "<div class='movie-detail'>";
                if (!empty($node->field_mega_review_cast)){
                $output .= "<div class='cast'>";
                $prt = print t('Cast:');
                $output .= "<span class='title'>".$prt.'';
                        
                $output .= "<span class='detail'>";
                $cast_ref_id = $node->field_mega_review_cast[LANGUAGE_NONE];
                $count = sizeof($cast_ref_id);
                        for ($i = 0; $i < $count; $i++) {
                          $entity_obj = entity_load('node', array($cast_ref_id[$i]['target_id']));
                          $cast = $entity_obj[$cast_ref_id[$i]['target_id']]->title;
                          $output .= $cast;
                          if ($i < ($count - 1)) {
                            $output .= ', ';
                          }
                        }
                    $output .= "</span>";
                    $output .= "</div>";
                }
                if (!empty($node->field_mega_review_director)){
                    $direct = print t('Director:');
                    $output .= "<div class='director'><span class='title'>.$direct.</span>";                                 
                    $output .= "<span class=detail>".$node->field_mega_review_director[LANGUAGE_NONE]['0']['value']."</span></div>";
                }
                if (!empty($node->field_mega_review_movie_plot)){
                    $output .= "<div class='plot'>";
                    $output .= "<span class='title'>'".print t('Plot:').'</span>";                                    
                    $output .= "<span class=detail>'.print $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value']."</span></div>";
                   }
                $output .= "</div>";                            
                $output .= "</div>"; 
                
            $output .= "<div class='ad-blocker'></div><div class='description'>";
            
            $story_body = $node->body['und'][0]['value'];
                // check video is delete form video content   
                if (function_exists('itg_videogallery_remove_delete_video_form_body_html_body')) {
                  itg_videogallery_remove_delete_video_form_body_html_body($story_body);
                }
                if (strpos($story_body, '[ITG:SURVEY:')) {
                  if (preg_match('/ITG:SURVEY:([0-9]+)/', $story_body, $matches_survey)) {
                    $survey_nid = $matches_survey[1];
                  }
                  $story_body = str_replace('[ITG:SURVEY:' . $survey_nid . ']', '', $story_body);
                }
                if (strpos($story_body, '[ITG:QUIZ:')) {
                  if (preg_match('/ITG:QUIZ:([0-9]+)/', $story_body, $matches_quiz)) {
                    $quiz_nid = $matches_quiz[1];
                  }
                  $story_body = str_replace('[ITG:QUIZ:' . $quiz_nid . ']', '', $story_body);
                }
                if (strpos($story_body, '[ITG:POLL:')) {
                  if (preg_match('/ITG:POLL:([0-9]+)/', $story_body, $matches_poll)) {
                    $poll_nid = $matches_poll[1];
                  }
                  $story_body = str_replace('[ITG:POLL:' . $poll_nid . ']', '', $story_body);
                }
                
            if (strpos($story_body, '[ITG:FACTOIDS]')) {
                  $factoidsBlock = '';
                  if (isset($node->field_story_template_factoids) && !empty($node->field_story_template_factoids)) {
                    $factoidsSocialShare['title'] = $node->field_story_factoids_title[LANGUAGE_NONE][0]['value'];
                    $factoidsSocialShare_title = preg_replace("/'/", "\\'", $factoidsSocialShare['title']);
                    $factoidsSocial_share_title = htmlentities($factoidsSocialShare_title, ENT_QUOTES);
                    $factoidsSocialShare['share_desc'] = $node->field_story_template_factoids[LANGUAGE_NONE][0]['value'];
                    $factoidsSocialShare['icons'] = '<div class=\"factoids-page\"><div class="fun-facts"><h2>' . $factoidsSocialShare['title'] . '</h2> </div>';
                    $factoidsSocialShare['icons'] .= '<div class="social-share"><ul>';
                    $factoidsSocialShare['icons'] .= '<li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>';
                    $factoidsSocialShare['icons'] .= '<li><a title = "share on facebook" class="facebook" href="javascript:void(0)" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $factoidsSocial_share_title . "'" . ', ' . "'" . $factoidsSocialShare['share_desc'] . "'" . ', ' . "'" . $image . "'" . ')"><i class="fa fa-facebook"></i></a></li>';
                    $factoidsSocialShare['icons'] .= '<li><a title = "share on twitter" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="twitter_share" data-status="1" class="user-activity twitter" href="javascript:" onclick="twitter_popup(\'' . urlencode($factoidsSocialShare['share_desc']) . ',' . urlencode($short_url) . '\')"><i class="fa fa-twitter"></i></a></li>';
                    $factoidsSocialShare['icons'] .= '<li><a class="user-activity google" rel="' . $node->nid . '" data-tag="' . $node->type . '" data-activity="google_share" data-status="1" title="share on google+" href="javascript:void(0)" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')"></a></li>';
                    $factoidsSocialShare['icons'] .= '</ul></div></div>';
                    
                    $factoidsSocialShare['slider'] = "<div class='factoids-slider'><ul>";
                    foreach ($node->field_story_template_factoids[LANGUAGE_NONE] as $key => $value) {
                      $factoidsSocialShare['slider'] .="<li><span>" . $value['value'] . "'</span></li>";
                    }
                    $factoidsSocialShare['slider'] .= "</ul></div>";
                    $factroid_icn = $factoidsSocialShare['icons'];
                    $factoidsBlock =  "$factroid_icn". $factoidsSocialShare['slider'];
                  }
                  
                  $story_body = str_replace('[ITG:FACTOIDS]', $factoidsBlock, $story_body);
                }
            if (strpos($story_body, '[ITG:EXPERT-CHUNK]')) {
                  $expertDetails = '';
                  if (!empty($node->field_story_expert_name)) {
                    $expertDetails .= "<div class='story-expert-opinion'><h4>" . t('Expert Opinion') . '</h4>';
                    $expertDetails .= "<div class='expert-detail row'><div class='left-side col-md-8 col-sm-8 col-xs-8'><p class='name'>'" . $node->field_story_expert_name['und'][0]['value'] . '</p>';
                    if (!empty($node->field_story_expertise)) {
                      $expertDetails .= "<p>" . $node->field_story_expertise[LANGUAGE_NONE][0]['value'] . "</p>";
                    }
                    $expertDetails .= "</div>";
                  }
                  if (!empty($node->field_story_expert_image)) {
                    if (!empty($node->field_story_expert_image[LANGUAGE_NONE][0]['uri'])) {
                      $expertDetailsImage = file_create_url($node->field_story_expert_image[LANGUAGE_NONE][0]['uri']);
                    }
                    else {
                      $expertDetailsImage = $base_url . '/sites/all/themes/itg/images/user-default-expert.jpg';
                    }
                  }
                  $expertDetails .= "<div class='right-side col-md-4 col-sm-4 col-xs-4'><img src='" . $expertDetailsImage . "' alt='' /></div></div>";
                  if (!empty($node->field_story_expert_description)) {
                    $expertDetails .= '<h2>' . $node->field_story_expert_description['und'][0]['value'] . '</h2>';
                  }
                  $expertDetails .= "</div>";

                  if (!empty($node->field_story_expert_description['und'][0]['value']) && !empty($node->field_story_expert_name)) {
                    $story_body = str_replace('[ITG:EXPERT-CHUNK]', $expertDetails, $story_body);
                  }
                  else {
                    $story_body = str_replace('[ITG:EXPERT-CHUNK]', '', $story_body);
                  }
                }
                
                $movie_html = itg_story_movie_image_plugin_data($node->nid);
                if (strpos($story_body, '[ITG:TECH-PHOTOS]')) {
                  if (!empty($node->field_story_technology['und'])) {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', $movie_html, $story_body);
                  }
                  else {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', '', $story_body);
                  }
                }
                if ($node->field_story_template_guru[LANGUAGE_NONE][0]['value']) {
                  $output .= "<h3 class='listical_title'>" . $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] . '</h3>';
                }
                
                if (!empty($node->field_story_listicle[LANGUAGE_NONE]) && !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
                  $buzz_output.= '';
                  $num = 1;
                  foreach ($node->field_story_listicle['und'] as $buzz_item) {
                    $listicletype = '';
                    $listicle_output.= "<div class='listicle-detail'>";
                    $field_collection_id = $buzz_item['value'];
                    $entity = entity_load('field_collection_item', array($field_collection_id));
                    $type = $entity[$field_collection_id]->field_story_listicle_type['und'][0]['value'];
                    $description = $entity[$field_collection_id]->field_story_listicle_description['und'][0]['value'];
                    $color = $entity[$field_collection_id]->field_listicle_color['und'][0]['value'];
                    $li_type = $node->field_story_templates[LANGUAGE_NONE][0]['value'];
                    $color = ($color) ? $color : '#000000';
                    if ($li_type == 'bullet_points') {
                      $listicle_output.= '<span class="bullet_points"></span>';
                    }
                    else {
                      $listicle_output.= '<span>' . $num . '</span>';
                    }
                    if (isset($type)) {
                      $listicletype = '<span class="listicle-type" style="color: ' . $color . '">' . $type . ': </span>';
                    }
                    $listicle_output.= "<div class='listicle-description'>" . $listicletype . $description . "</div>";
                    $listicle_output.= "</div>";
                    $num++;
                  }
                  $output .= $listicle_output;
                }else {
                  // Print story body
                  //$output .= $story_body;
                }
                
                // If survey is associated with story, render survey form
                if (strpos($node->body['und'][0]['value'], '[ITG:SURVEY:')) {
                  $story_body_survey = str_replace($story_body, itg_survey_pqs_associate_with_story('[ITG:SURVEY:' . $survey_nid . ']'), $story_body);
                  $output .= $story_body_survey;
                }
                // If quiz is associated with story, render quiz form
                if (strpos($node->body['und'][0]['value'], '[ITG:QUIZ:')) {
                  $story_body_quiz = str_replace($story_body, itg_survey_pqs_associate_with_story('[ITG:QUIZ:' . $quiz_nid . ']'), $story_body);
                  $output .= $story_body_quiz;
                }
                // If Poll Associated with story node.
                if (strpos($node->body['und'][0]['value'], '[ITG:POLL:')) {
                  $story_body_poll = str_replace($story_body, itg_survey_pqs_associate_poll_with_story($poll_nid), $story_body);
                  $output .= $story_body_poll;
                }
            
            $output .= $story_body;
            $output .= "</div>";
              //render story technology chunk
              
              if (!empty($node->field_story_tech_review_chunk[LANGUAGE_NONE][0]['value'])) {
              $output .= "<div class='story-tech-chunk'>";
              if (!empty($node->field_story_technology_rating[LANGUAGE_NONE][0]['value'])) {
                    $output .= "<span class='tech-rating'>";
                    $output .= $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'] . '/10';
                    $output .= "</span>";
                   }
                  $output .= render($content['field_story_tech_review_chunk']);
                $output .= "</div>";
              }
              $output .= "</div></div>";
          
            
    
}else{
    $pts = '';
    if (!empty($node->field_story_type[LANGUAGE_NONE])) {
        $pts = 'photo-story';
      }
      $aa = 'story-right '.$pts.'';
      $output .= "<div class='.$aa.'>";
      
      if (!empty($node->field_photo_story)) {
        $output2 = itg_story_photo_story_html($node->nid);
        $output .= $output2;
       }
       
       if (!empty($node->field_photo_story)) {
              $html_output = itg_story_photo_story_bottom_html($node->nid);
              $output .= $html_output;
        }
        $output .= "</div>";
    
}
$output .= "<div class='clearfix'></div>";
$out = str_replace("\"", "", $output);
return $out;
}

