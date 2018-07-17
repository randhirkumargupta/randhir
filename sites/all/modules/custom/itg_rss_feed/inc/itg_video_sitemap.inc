<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate video_rss_feed
 *
 * @return string
 */
function itg_video_sitemap() {
  global $base_url;
  $output = "";

  $redis_key = "itgd_rss_video_sitemap";
  //$result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
    $output = $result_get['key_value'];
  }
  else {
    //videoRSSFeed writing...
    //$ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_video_sitemap_item();

    // set into redis
    // $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * Function for generate Video rss feed
 * @global string $base_url
 * @return string
 */
function get_video_sitemap_item() {
  global $base_url;
  $output = "";
  $range_min = 0;
  $range_max = 205;
  //$type = array("videogallery", "photogallery", "story");
  $type = array("videogallery");


  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_short_headline', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_source_type', 'st', 'st.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('field_story_short_headline_value'));
  $query->fields('st', array('field_story_source_type_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'videogallery', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($range_min, $range_max);

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $output = '<urlset xmlns="http://www.sitemaps.org/schemas/sitemap/0.9" xmlns:video="http://www.google.com/schemas/sitemap-video/1.1">';
  foreach ($result as $reskey => $resvalue) {
    if (is_lock_story_rss_feed($resvalue['nid'])) {
      continue;
    }
    $videotag = _itg_rss_video_detail_formats($resvalue['nid'], $resvalue['field_story_source_type_value']);
    $duration = 0;
    $video_dur = explode(':', $videotag->video_duration);
    if (count($video_dur) > 1) {
      $m = (int) $video_dur[0] * 60;
      $s = (int) $video_dur[1];
      $duration = $m + $s;
    }
    else {
      $duration = $videotag->video_duration;
    }
    $title = $resvalue['title'];
    $nid = $resvalue['nid'];
    $body_value = $resvalue['field_story_short_headline_value'];
    $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $image_data = get_thumbnails_by_fid($field_story_extra_large_image_fid);
    $img_url = $image_data->imageurl;
    $created = $resvalue['created'];
    $created_date = date("Y-M-d\TH:i:sP", $created);
    $output .= '<url>';
    $output .= '<loc>' . $url . '</loc>';
    $output .= '<video:video>';
    $output .= '<video:thumbnail_loc>' . $img_url . '</video:thumbnail_loc>';
    $output .= '<video:title><![CDATA[' . $title . ']]></video:title>';
    $output .= '<video:description><![CDATA[' . $body_value . ']]></video:description>';
    $output .= '<video:content_loc>' . $videotag->video_url . '</video:content_loc>';
    $output .= '<video:duration>' . $duration . '</video:duration>';
    $output .= '<video:publication_date>' . $created_date . '</video:publication_date>';
    $output .= '</video:video></url>';
  }
  $output .= '</urlset>';
  return $output;
}

/**
 * Function is used to get video detail by nid
 * @param int $nid
 * @param string $source_type
 * @return array
 */
function _itg_rss_video_detail_formats($nid, $source_type) {
  $video_detail = array();
  if ($source_type != 'migrated') {
    $videoids = itg_get_video_in_fieldcollection_by_nid($nid);
    if (count($videoids) > 0) {
      $file_detail = file_load($videoids[0]->fid);
      $videoids[0]->type = 'dailymotion';
      $videoids[0]->video_url = file_create_url($file_detail->uri);
      $video_detail = $videoids[0];
    }
  }
  elseif ($source_type == 'migrated') {
    $video_status = 'migrated';
    $videoids = itg_get_video_in_fieldcollection_by_nid_mirtaed($nid);
    if (count($videoids) > 0) {
      $video_detail[0]['video_url'] = $videoids[0]->field_migrated_video_url_value;
      $video_detail[0]['video_duration'] = $videoids[0]->field_video_duration_value;
    }
  }
  return $video_detail;
}

/**
 * 
 * @param int $nid
 * @return array
 */
function itg_get_video_in_fieldcollection_by_nid($nid) {
  $query = db_select('field_data_field_video_upload', 'up_video');
  $query->join('field_data_field_videogallery_video_upload', 'fvu', 'up_video.field_video_upload_value = fvu.entity_id');
  $query->leftJoin('dailymotion_response_details', 'drd', 'drd.fid = fvu.field_videogallery_video_upload_fid');
  $query->leftJoin('field_data_field_video_title', 'desc_inc', 'desc_inc.entity_id = fvu.entity_id');
  $query->fields('drd', array('fid', 'dailymotion_thumb_url', 'video_duration'));
  $query->fields('desc_inc', array('field_video_title_value'));
  $query->condition('up_video.entity_id', $nid);
  $query->orderBy('up_video.delta', 'ASC')->range(0, 1);
  $result = $query->execute()->fetchAll();
  return $result;
}

/**
 * 
 * @param int $nid
 * @return array
 */
function itg_get_video_in_fieldcollection_by_nid_mirtaed($nid) {
  $query = db_select('field_data_field_video_upload', 'up_video');
  $query->join('field_data_field_migrated_video_url', 'fvu', 'up_video.field_video_upload_value = fvu.entity_id');
  $query->leftJoin('field_data_field_video_duration', 'video_duration', 'video_duration.entity_id = ' . $nid);
  $query->fields('up_video', array('entity_id'));
  $query->fields('fvu', array('field_migrated_video_url_value'));
  $query->fields('video_duration', array('field_video_duration_value'));
  $query->condition('up_video.entity_id', $nid);
  $query->orderBy('field_video_upload_value', 'ASC');
  $result = $query->execute()->fetchAll();
  return $result;
}
