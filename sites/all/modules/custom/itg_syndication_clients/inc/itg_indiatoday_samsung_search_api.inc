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
  $searchpage = solr_search_custom_results($key);
  if($nids === FALSE){
		return array();
	}
  
  $video_list = array();
  $loopc = 0;
  foreach ($searchpage as $key => $result) {
    $nid = $result->entity_id;
    $title = $result->label;
    $image_courtesy = FRONT_URL;
    
    $extra_large_image = empty($result->sm_field_custom_story_extra_large_url[0]) ? '' : $result->sm_field_custom_story_extra_large_url[0];
    $field_story_medium_image = empty($result->sm_field_custom_story_medium_large_url[0]) ? '' : $result->sm_field_custom_story_medium_large_url[0];
    $byline = empty($result->sm_field_itg_common_by_line_name[0]) ? '' : $result->sm_field_itg_common_by_line_name[0];
    $body = empty($result->content) ? '' : $result->content;
    $changed = date("Y-m-d H:i:s", strtotime($result->ds_changed));
    $source_type =  $result->sm_field_story_source_type[0];
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
    $video_list[$loopc]['v_byline'] = "$byline";
    $video_list[$loopc]['v_desc'] = "$body";
    $video_list[$loopc]['v_small_image'] = $field_story_medium_image;
    $video_list[$loopc]['v_large_image'] = $extra_large_image;
    $video_list[$loopc]['v_download_url'] = "$bitrate_url";
    $video_list[$loopc]['v_updated_datetime'] = "$changed";
    $video_list[$loopc]['v_duration'] = "$duration";
    $video_list[$loopc]['v_show_ad'] = "0";
    $loopc++;
  }
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
  
  try {
		$key = preg_replace('/\s+/', ' OR ', $key);
    $solr = apachesolr_get_solr();
		$query = apachesolr_drupal_query("custom", array('q' => $key));
		$query->setSolrsort('ds_changed', 'desc');
		$query->removeFilter('bundle_name');
		$query->addParam('fq', "hash:(".apachesolr_site_hash().")");
		$query->addParam('fq', "bundle_name:Video");
		$query->addParam('sort', "ds_changed DESC");
		$resp = $query->search();
		if(!empty($resp->data)){
			$data = json_decode($resp->data);
		}
    $results = $data->response->docs;
  }
  catch (Exception $e) {
    watchdog('solr_service', $e->getMessage(), NULL, WATCHDOG_ERROR);
    apachesolr_failure(t('Solr search'), $key);
  }

  if ($results and is_array($results) and count($results)) {   
    return $results;
  }
  return FALSE;
}

function get_node_data_from_nids($nids) {
  if (count($nids) <= 0) {
    return array();
  }
  $query = db_select('node', 'n');

  $query->leftJoin('field_data_field_story_large_image', 'sli', 'sli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_expert_description', 'sed', 'sed.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('smi', array('field_story_medium_image_fid'));
  $query->fields('sc', array('field_story_courtesy_value'));
  $query->fields('sst', array('field_story_source_type_value'));
  $query->fields('sli', array('field_story_large_image_fid'));
  $query->fields('sed', array('field_story_expert_description_value'));

  $query->condition('n.nid', $nids, 'IN');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'videogallery', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}
