<?php

/**
 * @file
 * The ITG Syndication clients for micromax
 */
function itg_rss_micromax_videsectionlist_feed() {
  $sections = get_micromax_videsectionlist_sections();
  foreach ($sections as $file_name => $section) {
    itg_genrate_micromax_video_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * Function for generate Micromax xml feed
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_micromax_video_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $section_id, '=');
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('sst', array('field_story_source_type_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $json = genrate_micromax_programme_xml($result);
    $json_path = 'public://indiatoday/micromax/';
    $file_path = $json_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $json);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function genrate_micromax_programme_xml($result) {
  global $base_url;
  $json_output = array();
  $json_output['title'] = "India Today's Videos Feed";
  $json_output['link'] = FRONT_URL;
  $json_output['description'] = "India Today's Videos Feed";
  $json_output['item'] = array();
  if (!empty($result)) {
    $count = 0;
    foreach ($result as $value) {
      $nid = $value['nid'];
      $created_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $source_type = $value['field_story_source_type_value'];
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $videotag = itg_video_detail_formats($nid, $source_type);
      $json_output['item'][$count]['id'] = $nid;
      $json_output['item'][$count]['title'] = $value['title'];

      if (!empty($videotag['migrated'])) { //migrated video  
        $json_output['item'][$count]['videourl'] = $videotag['migrated']['video_path_mp4'];
      }
      elseif (!empty($videotag['dailymotion'])) {
        $json_output['item'][$count]['videourl'] = $videotag['dailymotion']['bitate_url']['videoparts_mp4'];
      }
      $json_output['item'][$count]['description'] = $kicker_text;
      $json_output['item'][$count]['pubDate'] = $created_date;
      $json_output['item'][$count]['thumbnailurl'] = $small_img['imag_url'];
      $count++;
    }
  }
  return json_encode($json_output);
}
