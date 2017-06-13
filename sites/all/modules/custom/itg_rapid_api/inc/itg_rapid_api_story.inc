<?php

/**
 * main function for generate StoryDetailPageRerourceValue array
 *
 * @return array
 */
function StoryDetailPageRerourceValue($id) {
  // variable decalartion
  $output_array = array();
  $data_array = array();
  $photo_list_array = array();


  // list array building
  $data = generateStoryDeatilList($id);
  if (!empty($data['data']['title'])) {
    $output_array['status_code'] = "1";
    $output_array['status_message'] = "";
  }
  else {
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
function generateStoryDeatilList($id) {
  // variable declaration    
  global $base_url;
  $data = array();
  $nid = $id;
  $photo_list_array = array();
  $data_array = array();
  $node = node_load($nid);
  // variable for feed
  $title = $node->title;
  $tid = $node->field_primary_category['und'][0]['value'];
  $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
  $large_image_fid = $node->field_story_extra_large_image['und'][0]['fid'];
  $body_without_html = $node->body['und'][0]['value'];

  $director = $node->field_mega_review_director[LANGUAGE_NONE]['0']['value'];
  $movie_plot = $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value'];
  $star_cast = $node->field_mega_review_cast['und'][0]['target_id'];
  $star_cast_name = getCastName($star_cast);
  $body_with_html = story_body_with_html($node);

  $load_city = taxonomy_term_load($node->field_stroy_city['und'][0]['tid']);
  $location = $load_city->name;
  $term = taxonomy_term_load($tid);
  $term_name = $term->name;

  $alias = drupal_get_path_alias('node/' . $nid . '');
  $weburl = $base_url . "/" . $alias;
  $galleryimg = $node->field_gallery_image['und'];
  $toptlapics = count($galleryimg);
  $changed = $node->changed;
  $changed_datetime = date("Y-m-d H:i:s", $changed);
  $comment_cont = getCommentsCount($nid);
  $tag = getTag($node);
  $heighligth = getHighlight($node);
  $author = generateAuthorTag($node);
  $rating = getRating($node);
  $caption = getImgCaption($large_image_fid);
  // custom function for get img byline
  $byline = getImgByline($large_image_fid);
  $published_stamp = $node->workbench_moderation['published']->stamp;

  $published_date = date("Y-m-d H:i:s", $published_stamp);
  $firebase_url = get_node_firebase_weburl($nid);

  //data array building

  $data_array['category_id'] = "$tid";
  $data_array['category_title'] = "$term_name";
  $data_array['id'] = "$nid";
  $data_array['title'] = "$title";
  $data_array['large_image'] = "$extra_large_image";
  $data_array['image_credit'] = "$byline";
  $data_array['image_caption'] = "$caption";
  $data_array['updated_datetime'] = "$changed_datetime";
  $data_array['published_datetime'] = "$published_date";
  $data_array['location'] = "$location";
  $data_array['director'] = "$director";
  $data_array['movie_plot'] = "$movie_plot";
  $data_array['star_cast'] = "$star_cast_name";
  $data_array['share_link'] = "$firebase_url";
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
 * @pram $node
 *
 * @return array
 */
function getTag($node) {
  $tag = array();

  $tag_obj = $node->field_story_itg_tags['und'];
  $loop_cont = 0;
  foreach ($tag_obj as $key => $value) {
    $tid = $value['tid'];
    $term = taxonomy_term_load($tid);
    $term_name = $term->name;
    $tag[$loop_cont]['t_id'] = "$tid";
    $tag[$loop_cont]['t_title'] = "$term_name";
    $loop_cont++;
  }

  return $tag;
}

/**
 * function for get story highlight
 * @pram $node
 *
 * @return array
 */
function getHighlight($node) {
  $heighlight = array();

  $heighlight_obj = $node->field_story_highlights['und'];
  $loop_cont = 0;
  foreach ($heighlight_obj as $key => $value) {
    $text = $value['value'];
    $heighlight[$loop_cont]['h_title'] = "$text";
    $loop_cont++;
  }

  return $heighlight;
}

/**
 * function for get story rating
 * @pram $node
 *
 * @return array
 */
function getRating($node) {
  $rating = array();
  $field_story_rating = $node->field_story_rating['und'][0]['value'];
  $rating['r_cur_value'] = "$field_story_rating";
  $rating['r_upper_range'] = "$field_story_rating";
  $rating['r_is_star_rating'] = "$field_story_rating";

  return $rating;
}

/**
 * function for get story cast name
 * @pram $nid
 *
 * @return array
 */
function getCastName($nid) {
  $query = db_select('node', 'n');
  $query->fields('n', array('title'));
  $query->condition('n.nid', $nid);

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['title'];
}

/**
 * function for story body html
 * @pram $node
 * @return string
 */
function story_body_with_html($node) {
  $full_body = $node->body['und']['0']['value'];
  $body_android = getBodyDataForAndroid($full_body);
  $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
  $large_image_fid = $node->field_story_extra_large_image['und'][0]['fid'];
  $caption = getImgCaption($large_image_fid);
  $getHighlight_ar = getHighlight($node);
  $getHighlight_str = "";
  foreach ($getHighlight_ar as $key => $value) {
    $text = $value['h_title'];
    $getHighlight_str .= "<li>" . $text . "</li>";
  }
  $output = '';
  $output .= '<div class="story-section">
<div class="story-right ">
                      <div class="">
                                    
                              <div class="stryimg"><img alt="" title="" src="' . $extra_large_image . '">
                                    
                                      <div class="photoby">
                                                                    <div class="photoby-text">' . $caption . '</div>
                                          </div>
                       



                </div>
                    
                  <div class="image-alt">' . $caption . '</div>
                                            
              </div>

                                <div class="briefcase desktop-hide">
                    <h4>Briefcase</h4>
                    <ul>
                      ' . $getHighlight_str . '                   </ul>
                  </div>
                  
              <div class="story-movie">
                                <div class="movie-detail">
                                                                      </div>                            
              </div>
              <div class="ad-blocker"></div>';
  $output .= '<div class="description">' . $body_android . '
                </div>';
  $output .= ' <!-- render story technology chunk -->
                          </div>
</div>';

  return $output;
}
