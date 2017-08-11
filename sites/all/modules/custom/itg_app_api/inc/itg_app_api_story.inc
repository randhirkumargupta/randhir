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

  $field_story_select_templates = $node->field_story_select_templates['und'][0]['value'];
  if ($field_story_select_templates == "buzz") {
    $buzz_temp_flag = "Yes";
  }
  else {
    $buzz_temp_flag = "No";
  }

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
  $story_tech = getStoryTechs($node);
  $listicle_data = buildListicleNode($node);
  $factoid_data = buildFactoidNode($node);
  $buzz_data = buildBuzzNode($node);
  $expertchunk_data = buildExpertchunkNode($node);
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
  $data_array['buzzflag'] = "$buzz_temp_flag";
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
  $data_array['listicles'] = $listicle_data;
  $data_array['factoids'] = $factoid_data;
  $data_array['buzz'] = $buzz_data;
  $data_array['tech-photo'] = $story_tech;
  $data_array['expert-chunk'] = $expertchunk_data;
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

/**
 * function for get tech node
 * @pram $node
 *
 * @return array
 */
function getStoryTechs($node) {
  $storytech = array();
  $listcont = 0;
  $tect_img = array();
  $rating = $node->field_story_technology_rating['und'][0]['value'];
  $content = $node->field_story_tech_review_chunk['und'][0]['value'];
  $content_org = $content; // pros & cons function
  /* remove pros & cons from contents start */
  $content = preg_replace('#<div class="tech-pros"(.|\s)+</div>#', '', $content);
  $content = preg_replace('#<div class="tech-cons"(.|\s)+</div>#', '', $content);
  /* remove pros & cons from contents start */
  $tect_img = $node->field_story_technology['und'];
  $storytech['rating'] = $rating;
  $storytech['content'] = $content;
  foreach ($tect_img as $key => $value) {
    $val_fid = $value['value'];
    $load_collection = field_collection_item_load($val_fid);
    $photo_ttile = $load_collection->field_technology_photo_title['und'][0]['value'];
    $img_url = completeFilePath($load_collection->field_technology_sample_photo['und'][0]['fid']);
    $storytech['data'][$listcont]['title'] = $photo_ttile;
    $storytech['data'][$listcont]['img'] = $img_url;
    $listcont++;
  }
  //get tech pros
  $tech_pros = getTechPros($content_org);
  $storytech['tech-pros'] = $tech_pros;
  //get tech pros
  $tech_cons = getTechCons($content_org);
  $storytech['tech-cons'] = $tech_cons;
  // static photo section

  $storytech['photos']['p_id'] = "358749";
  $storytech['photos']['p_image'] = ITGD_MUM_DEV_FILES_PATH . "/crop_image/intoday-mag2_54441497856379.jpeg";

  return $storytech;
}

/**
 * function for get build listicle node
 * @pram $node
 *
 * @return array
 */
function buildListicleNode($node) {
  $listiclenode = array();
  $listcont = 0;

  //get listcle temp
  $field_story_templates = $node->field_story_templates['und'][0]['value'];
  // get title
  $field_story_template_guru = $node->field_story_template_guru['und'][0]['value'];
  $listiclenode['templates'] = $field_story_templates;
  $listiclenode['title'] = $field_story_template_guru;
  //listicle loop data
  $field_story_listicle = $node->field_story_listicle['und'];

  foreach ($field_story_listicle as $key => $value) {
    $collection_id = $value['value'];
    $load_collection = field_collection_item_load($collection_id);
    $color = $load_collection->field_listicle_color['und'][0]['value'];
    $type = $load_collection->field_story_listicle_type['und'][0]['value'];
    $description = $load_collection->field_story_listicle_description['und'][0]['value'];
    // loop data
    $listiclenode['data'][$listcont]['description'] = $description;
    $listiclenode['data'][$listcont]['type'] = $type;
    $listiclenode['data'][$listcont]['color'] = $color;
    $listcont++;
  }
  return $listiclenode;
}

/**
 * function for get build factoid node
 * @pram $node
 *
 * @return array
 */
function buildFactoidNode($node) {

  $factoidnode = array();
  $listcont = 0;
  // get title
  $field_story_factoids_title = $node->field_story_factoids_title['und'][0]['value'];
  $factoidnode['title'] = $field_story_factoids_title;
  // loop data - field_story_template_factoids
  $field_story_template_factoids = $node->field_story_template_factoids['und'];
  foreach ($field_story_template_factoids as $key => $value) {
    $factoids = $value['value'];
    $factoidnode['data'][$listcont]['Factoids'] = $factoids;
    $listcont++;
  }
  return $factoidnode;
}

/**
 * function for get build buzz node
 * @pram $node
 *
 * @return array
 */
function buildBuzzNode($node) {

  $buzznode = array();
  $listcont = 0;
  // loop data
  $field_story_template_buzz = $node->field_story_template_buzz['und'];
  foreach ($field_story_template_buzz as $key => $value) {
    $collection_id = $value['value'];
    $load_collection = field_collection_item_load($collection_id);
    // collection data
    $headLine = $load_collection->field_buzz_headline['und'][0]['value'];
    $img_fid = $load_collection->field_buzz_image['und'][0]['fid'];
    $img_url = completeFilePath($img_fid);
    $description = $load_collection->field_buzz_description['und'][0]['value'];

    $buzznode[$listcont]['headLine'] = $headLine;
    $buzznode[$listcont]['img'] = $img_url;
    $buzznode[$listcont]['description'] = $description;
    $listcont++;
  }

  return $buzznode;
}

/**
 * function for get build buzz node
 * @pram $node
 *
 * @return array
 */
function buildExpertchunkNode($node) {
  $expert_chunk = array();
  // get data
  $field_story_expert_description = $node->field_story_expert_description['und'][0]['value'];
  $field_story_expert_image_fid = $node->field_story_expert_image['und'][0]['fid'];
  $field_story_expert_name = $node->field_story_expert_name['und'][0]['value'];
  $field_story_expertise = $node->field_story_expertise['und'][0]['value'];
  $img_url = completeFilePath($field_story_expert_image_fid);

  $expert_chunk['name'] = $field_story_expert_name;
  $expert_chunk['image'] = $img_url;
  $expert_chunk['expertise'] = $field_story_expertise;
  $expert_chunk['description'] = $field_story_expert_description;

  return $expert_chunk;
}

/**
 * function for  getTechPros
 * @pram $content_org
 *
 * @return array
 */
function getTechPros($content_org) {
  $techpross = array();
  $listcont = 0;
  $html = $content_org;
  $dom = new DOMDocument();
  $dom->loadHTML($html);
  $xpath = new DOMXPath($dom);
  $nodes = $xpath->query('//*[@class="pros-list"]');
  $data = array();
  for ($i = 0; $i < $nodes->length; $i++) {
    $temp = $nodes->item($i)->textContent;
    $techpross[$listcont]['pros'] = $temp;
    $listcont++;
  }

  return $techpross;
}

/**
 * function for  getTechCons
 * @pram $content_org
 *
 * @return array
 */
function getTechCons($content_org) {

  $techpcons = array();
  $listcont = 0;
  $html = $content_org;
  $dom = new DOMDocument();
  $dom->loadHTML($html);
  $xpath = new DOMXPath($dom);
  $nodes = $xpath->query('//*[@class="cons-list"]');
  $data = array();
  for ($i = 0; $i < $nodes->length; $i++) {
    $temp = $nodes->item($i)->textContent;
    $techpcons[$listcont]['cons'] = $temp;
    $listcont++;
  }

  return $techpcons;
}
