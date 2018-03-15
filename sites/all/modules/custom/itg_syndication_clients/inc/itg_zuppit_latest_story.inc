<?php

/**
 * menu callback
 * function for generate zuppit feed
 * @global string $base_url
 */
function itg_zuppit_feed_latest_story() {
  global $base_url;
  $page_number = (isset($_GET['pageNumber']) ? $_GET['pageNumber'] : 0);
  $pagesize = (isset($_GET['pagesize']) ? $_GET['pagesize'] : 50);
  $partner = 'zuppit';
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');

  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('sli', array('field_story_large_image_fid'));
  $query->fields('pc', array('field_primary_category_value'));

  $days_ago = strtotime(date('Y-m-d', strtotime('-30 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($page_number, $pagesize);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $json_output = array();
  $json_output['code'] = 200;
  $json_output['error'] = NULL;
  $json_output['data']['size'] = count($result);
  $json_output['data']['nextPage'] = FRONT_URL . '/ucbrowser/story/feed/??pageNumber=' . ($page_number + 1) . '&pagesize=' . $pagesize . '&partner=' . $partner;
  // For Top key
  $top_stories = get_top_story_for_zupit();
  $json_output['data']['top'] = array();
  foreach ($top_stories as $top_story) {
    if (is_lock_story($top_story['nid'])) {
      continue;
    }
    $pub_date = strtotime($top_story['field_itg_content_publish_date_value']);
    $larg_img = get_image_info_by_fid($top_story['field_story_large_image_fid']);
    $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $top_story['nid']);
    $category_name = get_term_name_by_tid($top_story['field_primary_category_value']);
    $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($top_story['field_story_kicker_text_value']));
    $json_output['data']['top'][] = array(
      'id' => $top_story['nid'],
      'title' => $top_story['title'],
      'category' => $category_name,
      'short_introtext' => $kicker_text,
      'url' => $content_url,
      'kicker_image' => $larg_img['imag_url'],
      'publishTime' => $pub_date
    );
  }
  // For Rows key
  $json_output['data']['rows'] = array();
  foreach ($result as $value) {
    if (is_lock_story($value['nid'])) {
      continue;
    }
    $nid = $value['nid'];
    $publish_date = strtotime($value['field_itg_content_publish_date_value']);
    $city = get_content_city($value['nid']);
    $tags = get_content_tags($value['nid']);
    $large_img = get_image_info_by_fid($value['field_story_large_image_fid']);

    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
    $body = remove_extra_tag_in_body($value["body_value"]);
    $body = itg_replace_token_with_data($body, $value['nid']);
    $body = itg_remove_extra_custom_tags($body);
    $category_name = get_term_name_by_tid($value['field_primary_category_value']);
    $json_output['data']['rows'][] = array(
      'id' => $nid,
      'language' => "English",
      'title' => $value["title"],
      'category' => $category_name,
      'tags' => $tags,
      'summary' => $value["title"],
      'detailUrl' => $url,
      'pages' => array(
        'pageNumber' => 1,
        'pageContent' => $body,
        'originalUrl' => $url,
      ),
      'articleFrom' => '',
      'publishTime' => $publish_date,
      'createTime' => $value['created'],
      'coverPic' => array($large_img['imag_url']),
      'province' => '',
      'city' => $city,
    );
  }
  drupal_json_output($json_output);
  drupal_exit();
}

/**
 * 
 * @return string
 */
function get_top_story_for_zupit() {
  $type = array('story');
  $query = db_select('node', 'n');

  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

  $query->fields('n', array('nid', 'title'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('sli', array('field_story_large_image_fid'));
  $query->fields('pc', array('field_primary_category_value'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));

  $days_ago = strtotime(date('Y-m-d', strtotime('-30 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 10);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * function for generate samsung video detail for Tizen clients
 * @return json
 */
function client_samsung_video_detail() {
  $output_array = array();
  $nid = arg(2);
  $output_array['status_code'] = "1";
  $output_array['status_message'] = "Video";
  $node = node_load($nid);
  $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
  $v_credit = itg_common_get_node_title($byline_id);
  if (is_null($v_credit)) {
    $v_credit = "";
  }
  $video_description = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($node->field_video_kicker['und'][0]['value']));
  $video_small_image = completeFilePath($node->field_story_small_image['und'][0]['fid']);
  $video_large_image = completeFilePath($node->field_story_large_image['und'][0]['fid']);

  $source_type = $node->field_story_source_type[LANGUAGE_NONE][0]['value'];
  $videotag = video_detail_formats($nid, $source_type);
  $video_transcoding_data = get_itg_video_transcoding($nid);
  $duration = '';
  if (count($video_transcoding_data) > 0) {
    $duration = $video_transcoding_data[0]->video_duration;
  }
  if (!empty($videotag['migrated'])) {
    $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
    foreach ($videoids as $keys => $video_value) {
      $url = $video_value->field_migrated_video_url_value;
    }
    $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
    $bitrate_url = $data_video['bitrate_url'];
  }
  elseif (!empty($videotag['dailymotion'])) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
    foreach ($videoids as $keys => $video_value) {
      if ($video_value->video_id != '') {
        $video_id = $video_value->video_id;
      }
      elseif ($video_value->solr_video_id != '') {
        $video_id = $video_value->solr_video_id;
      }
    }
    $inter_video_details = internal_video_bitrate_data($video_id);
    $bitrate_url = $inter_video_details['bitrate_url'];
  }
  $bitrate_url = str_replace(',156,', ',', $bitrate_url);
  $pub_date = get_content_publish_date($nid);
  if (!empty($pub_date)) {
    $pub_date = date('Y-m-d H:i:s', strtotime($pub_date[0]['field_itg_content_publish_date_value']));
  }
  $upload_video = $node->field_video_upload['und'][0]['value'];
  $load_collection = field_collection_item_load($upload_video);
  $show_add = $load_collection->field_include_ads['und'][0]['value'];
  if ($show_add == 'yes') {
    $show_add = '1';
  }
  else {
    $show_add = '0';
  }
  $byline = get_byline_name_by_nid($nid);
  $created_date = date("Y-m-d H:i:s", $node->created);
  $video_data['id'] = $node->nid;
  $video_data['title'] = html_entity_decode($node->title);
 
  $video_detail['v_id'] = $node->nid;
  $video_detail['v_title'] = html_entity_decode($node->title);
  $video_detail['v_credit'] = FRONT_URL;
  $video_detail['v_byline'] = $byline;
  $video_detail['v_desc'] = $video_description;
  $video_detail['v_small_image'] = $video_small_image;
  $video_detail['v_large_image'] = $video_large_image;
  $video_detail['v_download_url'] = $bitrate_url;
  $video_detail['v_updated_datetime'] = $created_date;
  $video_detail['v_duration'] = $duration;
  $video_detail['v_show_ad'] = '0';
  
  $video_data['video'][] = $video_detail;
  $output_array['data'] = $video_data;
  $jsondata = drupal_json_output($output_array);
  return $jsondata;
}
