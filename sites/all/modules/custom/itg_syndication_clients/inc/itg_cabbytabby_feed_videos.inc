<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_cabbytabby_feed_videos_syndication() {
  $sections = get_cabbytabby_feed_videos_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_cabbytabby_feed_videos_syndication($section_id, $file_name);
  }
}

/**
 * menu callback for bsb story syndication
 */
function itg_genrate_cabbytabby_feed_videos_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = 'CabbyTabby';
    $type = array('videogallery');
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_expert_description', 'sed', 'sed.entity_id=n.nid');


    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sst', array('field_story_source_type_value'));
    $query->fields('sed', array('field_story_expert_description_value'));

    $query->condition('ti.tid', $section_id, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 10);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_cabbytabby_feed_videos_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'sites/default/files/rss-feeds/ver1.0/cabbytabby/71dea842/it/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_cabbytabby_feed_videos_syndication_xml($result = NULL, $section_id, $category) {
  $xml_pub_date = end($result);
  $xml_pub_date = date("Y-m-d H:i:s", $xml_pub_date['created']);
  $xml = '';
  $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" version="2.0">';
  $xml .= '<channel>';
  $xml .= '<title><![CDATA['.$category.']]></title>';
  $xml .= '<link><![CDATA[feeds]]></link>';
  $xml .= '<description><![CDATA[CabbyTabby MRSS Feed]]></description>';
  $xml .= '<pubDate><![CDATA['.$xml_pub_date.']]></pubDate>';
  
  if (!empty($result)) {
    
    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("Y-m-d H:i:s", $value['created']);
      $catname = get_term_name_by_tid($section_id);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $source_type = $value['field_story_source_type_value'];
      $videotag = video_detail_formats($nid, $source_type);
      $video_data = get_itg_video_transcoding($nid);
      $meta_tags = get_node_metatags_by_nid($nid);
      $tags = get_content_tags($nid, TRUE);
      $byline = get_byline_name_by_nid($nid);
      $key_words = '';
      if(!empty($meta_tags['data'])){
        $meta_tags = unserialize($meta_tags['data']);
        $key_words = $meta_tags['keywords']['value'];
      }
      
      $duration= '';
      if(count($video_data) > 0){
        $duration = $video_data[0]->video_duration;
      }
      
      $video_url = '';
      if (!empty($videotag['migrated'])) { //migrated video
        $video_url = $videotag['migrated']['video_path_mp4'];
      }
      elseif (!empty($videotag['dailymotion'])) {
        $video_url = $videotag['dailymotion']['bitate_url']['videoparts_mp4'];
      }
      $xml .= '<item>';
      $xml .= '<guid isPermaLink="false">'.$nid.'</guid>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<description><![CDATA[' . $value['field_story_expert_description_value'] . ']]></description>';
      $xml .= '<pubDate>' . $created_date . '</pubDate>';
      $xml .= '<category><![CDATA[' . $catname . ']]></category>';
      $xml .= '<enclosure url="'.$video_url.'" type="video/mp4"/>';
      $xml .= '<media:content url="'.$video_url.'" type="video/mp4" duration="'.$duration.'">';
      $xml .= '<media:category>'.$catname.'</media:category>';
      $xml .= '<media:tags><![CDATA['.$tags.']]></media:tags>';
      $xml .= '<media:keywords><![CDATA['.$key_words.']]></media:keywords>';
      $xml .= '<media:thumbnail url="' . $small_img['imag_url'] . '"></media:thumbnail>';
      $xml .= '<media:credit role="producer" scheme="urn:ebu"><![CDATA[' . $byline . ']]></media:credit>';
      $xml .= '</media:content>';
      $xml .= '</item>';
    }
  }
  $xml .= '</channel>';
  $xml .= '</rss>';
  return $xml;
}

function genrate_video_detail_xml($result, $section_id, $category, $filename, $small_img, $related) {

  global $base_url;
  $nid = $result['nid'];
  $title = $result['title'];
  $primary_cat = get_term_name_by_tid($result['field_primary_category_value']);
  $credit = $result['field_story_courtesy_value'];
  $content_url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
  $created_date = date("Y-m-d", $result['created']);
  $created_datetime = date("Y-m-d\TH:i:sP", $result['created']);
  $is_fav = get_nid_is_favorite($nid);
  $syndications = get_nid_is_syndications($nid);
  $meta_tags = get_node_metatags_by_nid($nid);
  $meta_title = '';
  $meta_description = '';
  if ($meta_tags) {
    $temp = unserialize($meta_tags['data']);
    $meta_title = $temp['title']['value'];
    $meta_description = $temp['description']['value'];
  }
  $video_xml .= '<Root>';
  $video_xml .= '<videoid>' . $nid . '</videoid>';
  $video_xml .= '<idsection>' . $section_id . '</idsection>';
  $video_xml .= '<section><![CDATA[' . $primary_cat . ']]></section>';
  $video_xml .= '<credit><![CDATA[' . $credit . ']]></credit>';
  $video_xml .= '<date><![CDATA[' . $created_date . ']]></date>';
  $video_xml .= '<datetime><![CDATA[' . $created_datetime . ']]></datetime>';
  $video_xml .= '<title><![CDATA[' . $title . ']]></title>';
  $video_xml .= '<thumbimage><![CDATA[' . $small_img['imag_url'] . ']]></thumbimage>';
  $video_xml .= '<mediaid></mediaid><uurl></uurl>';
  $source_type = $result['field_story_source_type_value'];
  $videotag = video_detail_formats($nid, $source_type);
  
  if (!empty($videotag['migrated'])) { //migrated video
    $video_xml .= "<videoparts><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts><size_364bit></size_364bit><videoparts_mp4><part>" . $videotag['migrated']['video_path_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['migrated']['flv_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['migrated']['videoparts_3gp'] . "</part></videoparts_3gp>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $video_xml .= "<videoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_hq_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $videotag['dailymotion']['bitate_url']['stream_h264_ld_url'] . "</part></videoparts_3gp>";
  }
  $video_xml .= "<create_date><![CDATA[" . $created_date . "]]></create_date><create_datetime><![CDATA[" . $created_datetime . "]]></create_datetime><syndications>" . $syndications . "</syndications><is_favorite>" . $is_fav . "</is_favorite><metakeyword><![CDATA[" . $meta_title . "]]></metakeyword><metadescription><![CDATA[" . $meta_description . "]]></metadescription><weburl>" . $content_url . "</weburl>";

  //get body img tag
  $imgtag = get_img_tag_detail($result);
  if ($imgtag) {
    $video_xml .= $imgtag;
  }
  else {
    $video_xml .= empty_get_img_tag_detail();
  }

  $video_xml .= '<related>';
  $video_xml .= '<stories>';
  if (!empty($related['related_story_xml'])) {
    $video_xml .= $related['related_story_xml'];
  }
  else {
    $video_xml .= get_empty_related_story_tag();
  }

  $video_xml .= '</stories>';

  $video_xml .= '<photos>';
  if (!empty($related['related_photo_xml'])) {
    $video_xml .= $related['related_photo_xml'];
  }
  else {
    $video_xml .= get_empty_related_photo_tag();
  }

  $video_xml .= '</photos>';

  $video_xml .= '<videos>';

  if (!empty($related['related_video_xml'])) {
    $video_xml .= $related['related_video_xml'];
  }
  else {
    $video_xml .= get_empty_related_video_tag();
  }

  $video_xml .= '</videos>';
  $video_xml .= '</related>';
  $video_xml .= get_comment_xml_tag($nid);
  $video_xml .= '</Root>';
  
  $xml_path = 'sites/default/files/bsb/videos/';
  $file_path = $xml_path . $filename;
  $fp = fopen($file_path, "w");
  fwrite($fp, $video_xml);
  fclose($fp);
}


/*
 * All video format responce
 * @param $nid
 * @return the details video xml tags
 */

function video_detail_formats($nid, $source_type) {

  $video_detail = array();
  if ($source_type != 'migrated') {
    $video_status = 'dailymotion';
    $videoids = get_video_in_fieldcollection_by_nid($nid);
    foreach ($videoids as $keys => $video_value) {
      if ($video_value->video_id != '') {
        $video_id = $video_value->video_id;
      }
      elseif ($video_value->solr_video_id != '') {
        $video_id = $video_value->solr_video_id;
      }
      else {
        
      }
      $video_detail[$video_status]['video_id'] = $video_id;
      $file_id = $video_value->fid;
    }

    $query = db_select('file_managed', 'fm');
    $query->condition('fm.fid', $file_id);
    $query->fields('fm', array('filename', 'uri', 'filemime', 'filesize', 'status'));
    $query->orderBy('fm.fid', 'DESC');
    $query->range(0, 1);
    $results = $query->execute()->fetchAll();
    $uri = $results[0]->uri;
    $video_detail[$video_status]['filename'] = $results[0]->filename;
    $video_detail[$video_status]['filsize'] = $results[0]->filesize;

    $query = db_select('itg_video_bitrates_data', 'itgv');
    $query->fields('itgv', array('bitate_url', 'bitates_field'));
    $query->condition('itgv.video_id', $video_id);
    $result2 = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $video_format = array();
    foreach ($result2 as $res_data) {
      $video_format[$res_data['bitates_field']] = $res_data['bitate_url'];
    }
    $video_path_mp4 = "https://www.dailymotion.com/video/" . $video_id . "";
    $video_format['videoparts_mp4'] = $video_path_mp4;
    $video_detail[$video_status]['bitate_url'] = $video_format;
    $dailymotion_download = dailymotion_download_video_uri($video_id);
    $video_detail[$video_status]['bitate_url']['download_url'] = "$dailymotion_download";
  }
  elseif ($source_type == 'migrated') {
    $video_status = 'migrated';
    $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
    foreach ($videoids as $keys => $video_value) {
      $video_path_mp4 = $video_value->field_migrated_video_url_value;
    }
    $video_detail[$video_status]['video_path_mp4'] = $video_path_mp4;
    $flv_url = str_replace(".mp4", ".flv", $video_path_mp4);
    $videoparts_3gp = str_replace(".mp4", ".3gp", $video_path_mp4);
    $video_detail[$video_status]['flv_url'] = $flv_url;
    $video_detail[$video_status]['videoparts_3gp'] = $videoparts_3gp;    
  }
  return $video_detail;
}

function get_itg_video_transcoding($nid){
  if(empty($nid))
    return '';
  $query = db_select('itg_video_transcoding', 'tra');
  $query->fields('tra', array('file_size', 'video_duration'));
  $query->condition('tra.nid', $nid);
  $result = $query->execute()->fetchAll();
  return $result;
}


/**
 * Get the dailymotion download video url
 * @param type $video_id
 * @return type
 */
function dailymotion_download_video_uri($video_id) {
  $query = db_select('field_data_field_bitrate_video_id', 'bvi');
  $query->leftJoin('field_data_field_video_url', 'v_url', 'v_url.entity_id = bvi.entity_id');
  $query->fields('v_url', array('field_video_url_value'));
  $query->condition('bvi.field_bitrate_video_id_value', $video_id);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['field_video_url_value'];
}
