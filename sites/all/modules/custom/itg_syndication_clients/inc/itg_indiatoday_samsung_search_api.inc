<?php

/**
 * @file
 * The ITG Syndication clients for samsung search
 */

/**
 * Function itg_indiatoday_samsung_search_api
 * @param str $key
 * @param string $result
 */
function itg_indiatoday_samsung_search_api() {
    $data = array();
    $video_list = array();
    $video_list = itg_indiatoday_samsung_search_api_video_list();
    $data['status_code'] = 1;
    $data['status_message'] = "Video";
    $data['data']['id'] = "2";
    $data['data']['title'] = "Video";
    $data['data']['video'] = $video_list;

    $jdata = json_encode($data);
    $jdata = utf8_encode($jdata);
    //$jdata = fixBadUnicodeForJson2($jdata);
    echo $jdata;
}

/**
 * 
 */
function itg_indiatoday_samsung_search_api_video_list() {
    $key = arg(2);
    $i_arg = array();
    $i_arg[0] = $key;   
    $fields = "entity_id,type,title,link";
    $searchpage = solr_search_custom_results($key);
    //$searchpage = views_get_view_result('front_end_global_search', 'default', $i_arg);
    $video_list = array();
    $loopc = 0;
    foreach ($searchpage as $key => $value) {
        //$nid = $value->entity_id;
        $nid = $value;
        $node = node_load($nid);        
        if ($node->type != "videogallery") {
            continue;
        }
        $title = $node->title;
        $extra_large_image = file_create_url($node->field_story_extra_large_image['und'][0]['uri']);
        $field_story_medium_image = file_create_url($node->field_story_medium_image['und'][0]['uri']);
        $img_info = getInfoData2($large_image_fid);
        $image_courtesy = $img_info['image_courtesy'];
        $image_caption = $img_info['image_caption'];
        $caption = $node->field_story_extra_large_image['und'][0]['title'];
        $body = $node->field_story_expert_description['und'][0]['value'];
        $firebase_url = 'http://indiatoday.in/' . drupal_get_path_alias('node/' . $nid . '');
        $changed = $node->changed;
        if ($changed) {
            $changed_datetime = date("Y-m-d H:i:s", $changed);
        }
        $source_type = $node->field_story_source_type['und'][0]['value'];
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

        $video_list[$loopc]['v_id'] = (int) $nid;
        $video_list[$loopc]['v_title'] = "$title";
        $video_list[$loopc]['v_credit'] = "$image_courtesy";
        $video_list[$loopc]['v_byline'] = "$image_caption";
        $video_list[$loopc]['v_desc'] = "$body";
        $video_list[$loopc]['v_small_image'] = "$field_story_medium_image";
        $video_list[$loopc]['v_large_image'] = "$extra_large_image";
        $video_list[$loopc]['v_download_url'] = "$bitrate_url";
        $video_list[$loopc]['v_updated_datetime'] = "$changed_datetime";
        $video_list[$loopc]['v_duration'] = "";
        $video_list[$loopc]['v_show_ad'] = "0";
        $loopc++;
    }
    //p($video_list);

    return $video_list;
}

/**
 * function for get getInfoData
 * @pram int
 *
 * @return array
 */
function getInfoData2($fid) {
    $data = array();
    if ($fid) {
        $query = db_select('image_info', 'iminfo');
        $query->fields('iminfo', array('image_courtesy', 'image_caption', 'image_date'));
        $query->condition('iminfo.fid', $fid, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        foreach ($result as $k => $res) {
            $data['image_courtesy'] = $res['image_courtesy'];
            $data['image_caption'] = $res['image_caption'];
            $data['image_date'] = $res['image_date'];
        }
    }
    return $data;
}

function fixBadUnicodeForJson2($str) {
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3")).chr(hexdec("$4"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2")).chr(hexdec("$3"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1")).chr(hexdec("$2"))', $str);
    $str = preg_replace("/\\\\u00([0-9a-f]{2})/e", 'chr(hexdec("$1"))', $str);
    return $str;
}
/**
 * Callback for solr service.
 */
function solr_search_custom_results($key, $fields, $facets = FALSE, $page = 0) {
    $link_ar = array();
    $nid_ar = array();
  $stdkeys = explode(',', str_replace(' ', '', $fields));
  $results = array();
  watchdog('solr_service', 'search.solr invoked for !keys', array('!keys' => $key));

  try {
    $condition = apachesolr_search_conditions();
    $filter = array('fq'=>array('type' => 'videogallery'));
    $results = apachesolr_search_search_execute($key, $filter);
  }
  catch (Exception $e) {
    watchdog('solr_service', $e->getMessage(), NULL, WATCHDOG_ERROR);
    apachesolr_failure(t('Solr search'), $key);
  }

  watchdog('solr_service', 'search.solr returned !count results for !keys', array('!count' => count($results), '!keys' => $key));

  if ($results and is_array($results) and count($results)) {
    // If specific fields requested, remove extra data.
    if ($fields) {
      $num = count($results);
      for ($i = 0; $i < $num; $i++) {
        $value = array_keys($results[$i]);
        foreach ($value as $keys) {
          if (!in_array($keys, $stdkeys)) {
            unset($results[$i][$keys]);
          }
        }
      }
    }
    // Result count.
    $env_id = apachesolr_default_environment();
    $query = apachesolr_current_query($env_id);
    if (is_object($query)) {
      $response = apachesolr_static_response_cache($query->getSearcher());
      $results['total'] = $response->response->numFound;
    }
    // If Facets enabled then show.
    if ($facets) {
      $searcher = $query->getSearcher();
      $results['facets'] = facetapi_build_realm($searcher, 'block');
    }
    foreach ($results as $key => $value) {
        
        $entity_id = $value['fields']['entity_id'];
        $nid_ar[] = $entity_id;
        
    }
    return $nid_ar;
  }
  return services_error(t('Search returned no results.'));
}
