<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_bsb_video_syndication() {
  $sections = getbsb_client_video_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_bsb_video_syndication($section_id, $file_name);
  }
}

/**
 * Function is used to generate BSB video xml
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_bsb_video_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = 'Latest Videos'; 
    
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_courtesy', 'sc', 'sc.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('pc', array('field_primary_category_value'));
    $query->fields('sc', array('field_story_courtesy_value'));
    $query->fields('sst', array('field_story_source_type_value'));
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_bsb_video_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'public://bsb/videos/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @param array $result
 * @param int $section_id
 * @param string $category
 * @return string
 */
function genrate_bsb_video_syndication_xml($result = NULL, $section_id, $category) {
  $xml = '';
  $xml .= '<Root>';
  $xml .= '<idsection>1</idsection>';
  $xml .= '<section>' . $category . '</section>';
  $xml .= '<totalvideos>' . count($result) . '</totalvideos>';

  if (!empty($result)) {
    $xml .= '<start_index>0</start_index>';
    $xml .= '<end_index>' . count($result) . '</end_index>';

    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("Y-m-d", $value['created']);
      $created_datetime = date("Y-m-d\TH:i:sP", $value['created']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $related = related_content_node_type($nid, 'videogallery');
      $is_fav = get_nid_is_favorite($nid);
      genrate_video_detail_xml($value, $section_id, $category, $video_file_name, $small_img, $related);

      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<mediumimage><![CDATA[' . $small_img['imag_url'] . ']]></mediumimage>';
      $xml .= '<thumbimage><![CDATA[' . $medium_img['imag_url'] . ']]></thumbimage>';
      $xml .= '<url>' . $video_file_name . '</url>';
      $xml .= '<create_date>' . $created_date . '</create_date>';
      $xml .= '<create_datetime>' . $created_datetime . '</create_datetime>';
      $xml .= '<is_favorite>' . $is_fav . '</is_favorite>';
      $xml .= '<relateds>';
      $xml .= '<photos>' . $related['photos'] . '</photos>';
      $xml .= '<videos>' . $related['videos'] . '</videos>';
      $xml .= '<stories>' . $related['stories'] . '</stories>';
      $xml .= '</relateds>';
      $xml .= '</item>';
    }
  }
  $xml .= '</Root>';
  return $xml;
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_id
 * @param string $category
 * @param string $filename
 * @param array $small_img
 * @param array $related
 */
function genrate_video_detail_xml($result, $section_id, $category, $filename, $small_img, $related) {

  global $base_url;
  $nid = $result['nid'];
  $title = $result['title'];
  $primary_cat = get_term_name_by_tid($result['field_primary_category_value']);
  $credit = $result['field_story_courtesy_value'];
  $content_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
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
  $videotag = itg_video_detail_formats($nid, $source_type);
  $video_size = migrated_video_transcoding($nid);

  if (!empty($videotag['migrated'])) { //migrated video
    $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
    foreach ($videoids as $keys => $video_value) {
      $url = $video_value->field_migrated_video_url_value;
    }
    $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
    $bitrate_url = $data_video['bitrate_url'];
    $mp4_url = $data_video['file_url'];
    $video_xml .= "<videoparts><part>" . $bitrate_url . "</part></videoparts><size_364bit>" . $video_size . "</size_364bit><videoparts_mp4><part>" . $mp4_url . "</part></videoparts_mp4><videoparts_m3u8><part>" . $bitrate_url . "</part></videoparts_m3u8><flvvideoparts><part>" . $mp4_url . "</part></flvvideoparts><videoparts_3gp><part>" . $mp4_url . "</part></videoparts_3gp>";
  }
  elseif (!empty($videotag['dailymotion'])) {
    $videoids = get_video_in_fieldcollection_by_nid($nid);
    foreach ($videoids as $keys => $video_value) {
      if ($video_value->video_id != '') {
        $video_id = $video_value->video_id;
      } elseif ($video_value->solr_video_id != '') {
        $video_id = $video_value->solr_video_id;
      }
    }
    $inter_video_details = internal_video_bitrate_data($video_id);
    $video_xml .= "<videoparts><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts><size_364bit>" . $videotag['dailymotion']['filsize'] . "</size_364bit><videoparts_mp4><part>" . $inter_video_details['file_url'] . "</part></videoparts_mp4><videoparts_m3u8><part>" . $inter_video_details['bitrate_url'] . "</part></videoparts_m3u8><flvvideoparts><part>" . $inter_video_details['file_url'] . "</part></flvvideoparts><videoparts_3gp><part>" . $inter_video_details['file_url'] . "</part></videoparts_3gp>";
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

  $xml_path = 'public://bsb/videos/';
  $file_path = $xml_path . $filename;
  $fp = fopen($file_path, "w");
  fwrite($fp, $video_xml);
  fclose($fp);
}
