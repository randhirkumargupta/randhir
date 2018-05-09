<?php

/**
 * Inc file contains the functions photo API
 */

/**
 * main function for generate photoCategoryPage array
 * @pram int $tid, $pageno
 *
 * @return array
 */
function photocategoryPageRerourceValue($tid = 0, $pageno = 0) {
  // variable decalartion
  $output_array = array();
  $data_array = array();
  $photo_list_array = array();
  $updated_datetime = "";

  $term = taxonomy_term_load($tid);
  $term_name = $term->name;
  if (!$tid) {
    $term_name = "Latest";
  }
  // list array building
  $data = generatePhotoCategoryList($tid, $pageno);

  if ($data['lcount'] > 0) {
    $output_array['status_code'] = "1";
    $output_array['status_message'] = "";
  }
  else {
    $output_array['status_code'] = "0";
    $output_array['status_message'] = "customised_message";
  }

  //data array building
  $datacount = $data['lcount'];
  $data_up_time = $data['updated_datetime'];

  $data_array['id'] = "$tid";
  $data_array['title'] = "$term_name";
  $data_array['layout_id'] = "0";
  $data_array['photo_count'] = "$datacount";
  $data_array['photo_display_count'] = "10";
  $data_array['photo_pagination_cap'] = "50";
  $data_array['updated_datetime'] = "$data_up_time";

  $data_array['photo'] = $data['data'];
  $output_array['data'] = $data_array;

  return $output_array;
}

/**
 * function for generate photoCategoryPage xml feed
 * @pram int $tid, $pageno
 *
 * @return array
 */
function generatePhotoCategoryList($tid, $pageno) {
  // variable declaration
  global $base_url;
  $node_count = "";
  // filter user data list
  $filter_user_data = array(2744, 1584, 1162, 1155, 1141, 1137, 970, 1156, 1190, 1522, 3, 1350, 1148, 2573);
  $output = "";
  $data = array();
  $tid_list = array();
  $tid_list[] = $tid;
  $listcount = 0;
  $range_max = 10;
  $range_min = 0;
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }

  $order_by = 'ASC';
  $type = "photogallery";
  $photo_list_array = array();
  $loop_count = 0; {
    $listcount = 0;

    // code vid=14  start
    if ($tid > 0) {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
    }
    else {
      $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, 1208521, $max_depth = NULL, $load_entities = FALSE);
    }
    $term_tree_count = count($term_tree);
    if ($term_tree_count) {
      foreach ($term_tree as $key => $value) {
        $tid_list[] = $value->tid;
      }
    }

    $query = db_select('taxonomy_index', 'ti');
    $query->leftJoin('node', 'n', 'n.nid=ti.nid');
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');

    $query->leftJoin('field_data_field_common_related_content', 'rc', 'rc.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'fpc', 'fpc.entity_id=n.nid');
    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));
    $query->fields('li', array('field_story_large_image_fid'));
    $query->fields('mi', array('field_story_medium_image_fid'));
    $query->fields('si', array('field_story_small_image_fid'));
    $query->fields('eli', array('field_story_extra_large_image_fid'));
    $query->fields('rc', array('field_common_related_content_value'));

    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid', 'changed'));
    $query->fields('fpc', array('field_primary_category_value'));

    if (count($tid_list) > 0) {
      $query->condition('ti.tid', $tid_list, 'IN');
    }
    $d1 = date('Y-m-d', strtotime("-175 days"));
    $d2 = date(strtotime($d1));
    $query->condition('n.created', $d2, '>=');
    //change in query
    $query->condition('n.uid', $filter_user_data, 'NOT IN');
    $query->condition('n.status', 1)->condition('n.type', $type)->orderBy('n.created', 'DESC')->groupBy('n.nid')->range($range_min, $range_max);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $reskey => $resvalue) {
      // node feed tag
      $listcount++;
      $title = $resvalue['title'];
      $type = $resvalue['type'];
      $nid = $resvalue['nid'];
      $created = $resvalue['created'];
      $changed = $resvalue['changed'];
      $comment_cont = getCommentsCount($nid);
      $node = node_load($nid);

      $galleryimg = $node->field_gallery_image['und'];
      $toptlapics = count($galleryimg);
      $field_gallery_image = $resvalue['field_gallery_image'];
      $field_gallery_image_cont = count($field_gallery_image);
      $alias = drupal_get_path_alias('node/' . $nid . '');
      $weburl = $base_url . "/" . $alias;
      // file url
      $file_small_img_url = completeFilePath($resvalue['field_story_small_image_fid']);
      $file_medium_img_url = completeFilePath($resvalue['field_story_medium_image_fid']);
      $file_large_img_url = completeFilePath($resvalue['field_story_large_image_fid']);
      $file_extra_large_img_url = completeFilePath($resvalue['field_story_extra_large_image_fid']);

      //related content
      $related = relatedContentNodeType($resvalue['field_common_related_content_value']);
      $field_primary_category_value = $resvalue['field_primary_category_value'];

      $term = taxonomy_term_load($tid);
      $term_name = $term->name;

      // create date formating
      $firebase_url = get_node_firebase_weburl($nid);
      $create_date = date("Y-m-d H:i:s", $created);
      $changed_datetime = date("Y-m-d H:i:s", $changed);
      if ($created) {
        $create_date = date("Y-m-d H:i:s", $created);
      }
      else {

        $create_date = "";
      }
      if ($changed) {
        $changed_datetime = date("Y-m-d H:i:s", $changed);
      }
      else {
        $changed_datetime = "";
      }
      // Get Publish time:
      $pub_date = get_content_publish_date($nid);
      if (!empty($pub_date)) {  
        $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
      } else {
        $pub_date = "";
      }
      // photo detail for listing
      $term_pri = taxonomy_term_load($field_primary_category_value);
      $term_name_pri = $term_pri->name;
      $photo_list_array[$loop_count]['p_id'] = "$nid";
      $photo_list_array[$loop_count]['p_title'] = "$title";
      $photo_list_array[$loop_count]['p_small_image'] = "$file_small_img_url";
      $photo_list_array[$loop_count]['p_large_image'] = "$file_large_img_url";
      $photo_list_array[$loop_count]['p_extralarge_image'] = "$file_extra_large_img_url";
      $photo_list_array[$loop_count]['p_count'] = "$toptlapics";
      $photo_list_array[$loop_count]['p_comment_count'] = "$comment_cont";
      $photo_list_array[$loop_count]['p_share_link'] = "$firebase_url";
      $photo_list_array[$loop_count]['p_updated_datetime'] = "$pub_date";
      $photo_list_array[$loop_count]['p_subcategory_id'] = "$field_primary_category_value";
      $photo_list_array[$loop_count]['p_subcategory_title'] = "$term_name_pri";
      $loop_count++;
    }
  }
  $data['lcount'] = $listcount;
  $data['data'] = $photo_list_array;
  $data['updated_datetime'] = $pub_date;
  return $data;
}

/**
 * main function for generate photoDetailPage array
 * @pram int $id
 *
 * @return array
 */
function photoDetailPageRerourceValue($id) {
  $output_array = array();
  $data_array = array();
  $photo_list_array = array();
  $data = generatePhotoDeatilList($id);
  if ($data['data']['photo_count'] > 0) {
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
 * function for generate generatePhotoDeatilList JSON
 * @pram int $id
 *
 * @return array
 */
function generatePhotoDeatilList($id) {
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
  $term = taxonomy_term_load($tid);
  $term_name = $term->name;
  $alias = drupal_get_path_alias('node/' . $nid . '');
  $weburl = $base_url . "/" . $alias;
  $galleryimg = $node->field_gallery_image['und'];
  $toptlapics = count($galleryimg);
  $changed = $node->changed;
  if ($changed) {
    $changed_datetime = date("Y-m-d H:i:s", $changed);
  }
  else {
    $changed_datetime = "";
  }
  $comment_cont = getCommentsCount($nid);

  //data array building
  $firebase_url = get_node_firebase_weburl($nid);
  $data_array['id'] = "$nid";
  $data_array['title'] = "$title";
  $data_array['updated_datetime'] = "$changed_datetime";
  $data_array['subcategory_id'] = "$tid";
  $data_array['subcategory_title'] = "$term_name";
  $data_array['photo_count'] = "$toptlapics";
  $data_array['comment_count'] = "$comment_cont";
  $data_array['share_link'] = "$firebase_url";
  $galleryimg = $node->field_gallery_image['und'];

  // list array building
  $photo_list_array = generatePhotoDetailList($galleryimg);
  $data_array['photo'] = $photo_list_array;
  $data['data'] = $data_array;
  return $data;
}

/**
 * function for generate photo list array
 * @pram array $galleryimg
 *
 * @return array
 */
function generatePhotoDetailList($galleryimg) {

  $photo_list_array = array();
  $listcont = 0;
  if (count($galleryimg) > 0) {
    // loop on gallery img
    $output = "";
    foreach ($galleryimg as $key => $value) {
      $fc = field_collection_field_get_entity($value);
      $fid = $fc->field_image_id['und'][0]['value'];
      if (!$fid > 0) {
        $fid = $fc->field_images['und'][0]['fid'];
      }
      //$uri = $fc->field_images['und'][0]['filename'];
      $uri = $fc->field_images['und'][0]['uri'];
      $file_uri = file_create_url($uri);
      $fid_file = $fid;
      $img_url = completeFilePath($fid_file);
      $caption = $fc->field_image_caption['und'][0]['value'];

      $byline = $fc->field_credit['und'][0]['value'];
      $photo_story_img = $file_uri; //image_style_url('photo_slider_753x543', $uri);
      $photo_list_array[$listcont]['p_id'] = "$fid";
      $photo_list_array[$listcont]['p_image'] = "$photo_story_img";
      $photo_list_array[$listcont]['p_credit'] = "$byline";
      $photo_list_array[$listcont]['p_caption'] = "$caption";
      $listcont++;
    }
  }
  return $photo_list_array;
}

/**
 * sprint2 function start
 * main function for generate photoStoryDetailPage array
 * @pram int $id
 *
 * @return array
 */
function photoStoryDetailPageRerourceValue($id) {
  $output_array = array();
  $data_array = array();
  $photo_list_array = array();
  // list array building
  $data = generatePhotoStoryDeatilList($id);
  if ($data['data']['photo_count'] > 0) {
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
 * function for generate generatePhotoStoryDeatilList JSON
 * @pram int $id
 *
 * @return array
 */
function generatePhotoStoryDeatilList($id) {
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
  $term = taxonomy_term_load($tid);
  $term_name = $term->name;
  $alias = drupal_get_path_alias('node/' . $nid . '');
  $weburl = $base_url . "/" . $alias;

  $changed = $node->changed;
  if ($changed) {
    $changed_datetime = date("Y-m-d H:i:s", $changed);
  }
  else {
    $changed_datetime = "";
  }
  $comment_cont = getCommentsCount($nid);
  $published_datetime = getNodePublishedDate($id);
  // list array building
  $photo_list_array = generatePhotoStoryDetailList($nid);
  $toptlapics = $photo_list_array['listcont'];
  $title = strip_tags($title);
  //data array building
  $firebase_url = get_node_firebase_weburl($nid);
  $data_array['id'] = "$nid";
  $data_array['title'] = "$title";
  $data_array['photo_count'] = "$toptlapics";
  $data_array['comment_count'] = "$comment_cont";
  $data_array['share_link'] = "$firebase_url";
  $data_array['updated_datetime'] = "$changed_datetime";
  $data_array['published_datetime'] = "$published_datetime";
  $data_array['is_sponsored'] = "";
  $data_array['sponsored_icon'] = "";
  $data_array['sponsored_url'] = "";
  $data_array['subcategory_id'] = "$tid";
  $data_array['subcategory_title'] = "$term_name";

  $data_array['photo'] = $photo_list_array['data'];
  $data_array['author'] = generateAuthorTag($node);

  $data['data'] = $data_array;
  return $data;
}

/**
 * function for generate photo list array
 *
 * @return array
 */
function generatePhotoStoryDetailList($nid) {
  $photo_list_array_data = array();
  $photo_list_array = array();
  $listcont = 0;


  // generate the html for photo story top slider
  if (!empty($nid)) {
    $node = node_load($nid);

    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    // function from
    $photo_story_html = photoSotryHtml($nid);

    foreach ($photo_story as $key => $val) {

      $entity_obj = entity_load('field_collection_item', array($val['value']));
      $photo_story_img_path = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['uri'];
      $photo_story_img_fid = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['fid'];
      $photo_story_file_name = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['filename'];
      $photo_story_img = completeFilePath($photo_story_img_fid);
      $photo_story_desc_html = $photo_story_desc = $entity_obj[$val['value']]->field_photo_story_description['und'][0]['value'];
      $caption = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['alt'];
      $byline = $entity_obj[$val['value']]->field_credit['und'][0]['value'];
      //$byline = getImgByline($photo_story_img_fid);
      $caption = strip_tags($caption);
      $img_info = getInfoData($large_image_fid);
      $photo_image_info = itg_story_get_image_info($photo_story_img_fid);
      $image_caption = strip_tags($photo_image_info[0]->image_caption);
      $image_courtesy = strip_tags($photo_image_info[0]->image_courtesy);
      $photo_story_desc_html = str_replace('<div class="body_caption">', '<div class="body_caption" style="padding:0.5em!important; color:#767676!important; font-size:10px!important;line-height:15px!important;">', $photo_story_desc_html);
      $photo_story_desc = strip_tags($photo_story_desc);
      $photo_list_array[$listcont]['p_id'] = "$photo_story_img_fid";
      $photo_list_array[$listcont]['p_image'] = "$photo_story_img";
      $photo_list_array[$listcont]['p_credit'] = "$image_courtesy";
      $photo_list_array[$listcont]['p_caption'] = "$image_caption";
      $photo_list_array[$listcont]['p_desc_withouthtml'] = "$photo_story_desc";
      $photo_list_array[$listcont]['p_desc_withhtml'] = "$photo_story_desc_html";
      $listcont++;
    }
  }
  $photo_list_array_data['data'] = $photo_list_array;
  $photo_list_array_data['listcont'] = $listcont;
  return $photo_list_array_data;
}

/**
 * function for photoSotryHtml
 *
 * @param int $node_id
 *
 * @return string
 */
function photoSotryHtml($node_id) {
  // generate the html for photo story top slider
  if (!empty($node_id)) {
    $node = node_load($node_id);
    $photo_story = $node->field_photo_story[LANGUAGE_NONE];
    $next = itg_story_photo_story_redirect($node_id, 'next');
    $previous = itg_story_photo_story_redirect($node_id, 'prev');
    $next_link_count = count($photo_story) - 1;
    $html = '';
    $html .= '<div class="photo-story-img multiple-photo-disc">';
    foreach ($photo_story as $key => $val) {
      if ($key == 0 && !empty($previous)) {
        $previous_link = "<a class='fa fa-chevron-left prev-story-link' href='" . $previous . "'></a>";
      }
      else {
        $previous_link = "";
      }
      if ($key == $next_link_count && !empty($next)) {
        $next_link = "<a class='fa fa-chevron-right next-story-link' href='" . $next . "'></a>";
      }
      else {
        $next_link = "";
      }
      $entity_obj = entity_load('field_collection_item', array($val['value']));
      $photo_story_img_path = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['uri'];
      $photo_story_file_name = $entity_obj[$val['value']]->field_photo_story_image['und'][0]['filename'];
      $photo_story_img = image_style_url('photo_story_771x432', $photo_story_img_path);
      $photo_story_desc = $entity_obj[$val['value']]->field_photo_story_description['und'][0]['value'];
      $html .= '<div class="photo-slider">';
      $html .= $next_link . '<img src="' . $photo_story_img . '" title="' . $photo_story_file_name . '" alt="photo_story_img" />' . $previous_link;
      $html .= '<div class="description"><p>' . $photo_story_desc . '</p></div>';
      $html .= '</div>';
    }
    $html .= '</div>';
    return $html;
  }
}

/**
 * function for generate photo list array
 * @pram object $node
 *
 * @return array
 */
function generateAuthorTag($node) {
  $field_itg_common_by_line_name = $node->field_itg_common_by_line_name['und'][0]['value'];
  $field_itg_common_by_line_twitter = $node->field_itg_common_by_line_twitter['und'][0]['value'];
  $field_reporter_unique_id = $node->field_reporter_unique_id['und'][0]['value'];
  $output = array();
  $output['a_id'] = "$field_reporter_unique_id";
  $output['a_title'] = "$field_itg_common_by_line_name";
  $output['a_image'] = "";
  $output['a_twitter_handler'] = "$field_itg_common_by_line_twitter";
  return $output;
}

/**
 * function for generate photo list array
 * @pram int $rvid
 *
 * @return array
 */
function field_data_field_story_large_image($rvid) {
  if ($rvid) {
    $query = db_select('field_data_field_story_large_image', 'lid');
    $query->fields('lid', array('field_story_large_image_fid'));
    $query->condition('lid.entity_id', $rvid);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result[0]['field_story_large_image_fid'];
  }
}

