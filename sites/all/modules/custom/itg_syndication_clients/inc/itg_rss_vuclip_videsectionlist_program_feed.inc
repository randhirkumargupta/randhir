<?php

/**
 * @file
 * The ITG Syndication clients for vuclip
 */

/**
 * menu callback
 * Function for generate vuclip programme video feed
 */
function itg_rss_vuclip_videsectionlist_program_videos_feed() {
  $sections = get_vuclip_sections();
  foreach ($sections as $file_name => $section) {
    itg_genrate_vuclip_programme_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * menu callback
 * Function for generate mauj video feed
 */
function itg_rss_mauj_videsectionlist_program_videos_feed() {
  $sections = get_mauj_sections();
  foreach ($sections as $file_name => $section) {
    itg_genrate_mauj_video_syndication($section['section'], $file_name, $section['limit']);
  }
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_vuclip_programme_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $section_id, '=');
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sst', array('field_story_source_type_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_vuclip_programme_xml($result, $section_name, $section_id);
    $xml_path = 'public://headlinestoday/vuclip/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $section_name
 * @param int $section_id
 * @return string
 */
function genrate_vuclip_programme_xml($result, $section_name, $section_id) {
  global $base_url;
  $xml = '<rss xmlns:media="http://search.yahoo.com/mrss" version="2.0">';
  $xml .= '<channel>';
  $xml .= "<title>India Today's Videos Feed</title>";
  $xml .= '<link>' . FRONT_URL . '</link>';
  $xml .= "<description>India Today's Videos Feed</description>";

  if (!empty($result)) {
    foreach ($result as $value) {
      $flag = FALSE;
      $nid = $value['nid'];
      $created_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $body = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['body_value']));
      $source_type = $value['field_story_source_type_value'];
      $videotag = itg_video_detail_formats($nid, $source_type);
      $metatags = get_node_metatags_by_nid($nid);
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      if (!empty($videotag['migrated'])) { //migrated video  
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        foreach ($videoids as $keys => $video_value) {
          $url = $video_value->field_migrated_video_url_value;
        }
        $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
        $bitrate_url = $data_video['bitrate_url'];
        $mp4_url = $data_video['file_url'];
        $xml .= '<link><![CDATA[' . $mp4_url . ']]></link>';
      }
      elseif (!empty($videotag['dailymotion'])) {
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        foreach ($videoids as $keys => $video_value) {
          if ($video_value->video_id != '') {
            $video_id = $video_value->video_id;
          } elseif ($video_value->solr_video_id != '') {
            $video_id = $video_value->solr_video_id;
          }
        }
        $inter_video_details = itg_internal_video_bitrate_data($video_id);
        //$videotag = itg_video_detail_formats($nid, $source_type);
        $video_url = $inter_video_details['file_url'];
        $xml .= '<link><![CDATA[' . $video_url . ']]></link>';
      }
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<pubDate>' . $created_date . '</pubDate>';
      if (!empty($videotag['migrated'])) { //migrated video  
        $xml .= '<media:content url="' . $videotag['migrated']['video_path_mp4'] . '" type="video/flv">';
        $flag = TRUE;
      }
      elseif (!empty($videotag['dailymotion'])) {
        $xml .= '<media:content url="' . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . '" type="video/flv">';
        $flag = TRUE;
      }
      if ($flag) {
        $xml .= '<media:title>' . $value['title'] . '</media:title>';
        $xml .= '<media:description>' . $body . '</media:description>';
        $xml .= '<media:thumbnail url="' . $small_img['imag_url'] . '"></media:thumbnail>';
        $xml .= '<media:keywords>' . $keywords . '</media:keywords>';
        $xml .= '<media:category></media:category>';
        $xml .= '<guid></guid>';
        $xml .= '</media:content>';
      }
      $xml .= '</item>';
    }
  }
  $xml .= '</channel>';
  $xml .= '</rss>';
  return $xml;
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 * @param int $limit
 */
function itg_genrate_mauj_video_syndication($section_id = NULL, $file_name, $limit = 25) {
  if (!empty($section_id)) {

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

    if (!empty($section_id) && $section_id != -1) {
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->condition('ti.tid', $section_id, '=');
      if($days_ago = get_content_fetch_time($section_id)){
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }

    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('sst', array('field_story_source_type_value'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, $limit);

    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_mauj_programme_xml($result);
    $xml_path = 'public://headlinestoday/mauj/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function genrate_mauj_programme_xml($result) {
  global $base_url;
  $xml = '<rss xmlns:media="http://search.yahoo.com/mrss" version="2.0">';
  $xml .= '<channel>';
  $xml .= "<title>India Today's Videos Feed</title>";
  $xml .= '<link>' . FRONT_URL . '</link>';
  $xml .= "<description>India Today's Videos Feed</description>";

  if (!empty($result)) {
    foreach ($result as $value) {
      $flag = FALSE;
      $nid = $value['nid'];
      $created_date = date("Y-m-d\TH:i:sP", strtotime($value['field_itg_content_publish_date_value']));
      $source_type = $value['field_story_source_type_value'];
      $videotag = itg_video_detail_formats($nid, $source_type);
      $xml .= '<item>';
      $xml .= '<id>' . $nid . '</id>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      if (!empty($videotag['migrated'])) { //migrated video  
        $xml .= '<link><![CDATA[' . $videotag['migrated']['video_path_mp4'] . ']]></link>';
      }
      elseif (!empty($videotag['dailymotion'])) {
        $xml .= '<link><![CDATA[' . $videotag['dailymotion']['bitate_url']['videoparts_mp4'] . ']]></link>';
      }
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<pubDate>' . $created_date . '</pubDate>';
      $xml .= '</item>';
    }
  }
  $xml .= '</channel>';
  $xml .= '</rss>';
  return $xml;
}
