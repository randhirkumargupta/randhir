<?php

/**
 * @file
 * The ITG Syndication clients for Ola Video
 */
function videsectionlist_india_rss_fun_on_go() {
  itg_genrate_india_rss_fun_on_go_videos_syndication();
}

/**
 * Function for Generate OLA xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_india_rss_fun_on_go_videos_syndication($file_name = 'videsectionlist_india_rss_fun_on_go.xml') {
  $type = array('videogallery');
  $query = db_select('node', 'n');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_expert_description', 'sed', 'sed.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('ssi', array('field_story_small_image_fid'));
  $query->fields('sst', array('field_story_source_type_value'));
  $query->fields('sed', array('field_story_expert_description_value'));

  $days_ago = strtotime(date('Y-m-d', strtotime('-30 days')));
  $query->condition('n.created', $days_ago, '>=');
  
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'videogallery', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = genrate_fun_on_go_videos_syndication_xml($result);
  $xml_path = 'public://xml_it/videos/';
  $file_path = $xml_path . $file_name;
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param array $result
 * @param int $section_id
 * @param string $category
 * @return string
 */
function genrate_fun_on_go_videos_syndication_xml($result = NULL) {
  global $base_url;
  $xml_pub_date = end($result);
  $xml_pub_date = date("Y-m-d H:i:s", $xml_pub_date['created']);
  $xml = '';
  $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" version="2.0">';
  $xml .= '<channel>';
  $xml .= "<title>India Today's Videos Feed</title>";
  $xml .= '<link>' . FRONT_URL . '</link>';
  $xml .= "<description>India Today's Videos Feed</description>";
  if (!empty($result)) {
    foreach ($result as $value) {
      $nid = $value['nid'];
      $created_date = date("Y-m-d\TH:i:sP", $value['created']);
      $catname = get_term_name_by_tid($section_id);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $source_type = $value['field_story_source_type_value'];
      $video_data = get_itg_video_transcoding($nid);
      $meta_tags = get_node_metatags_by_nid($nid);
      $key_words = '';
      if (!empty($meta_tags['data'])) {
        $meta_tags = unserialize($meta_tags['data']);
        $key_words = $meta_tags['keywords']['value'];
      }

      $video_url = '';
      if ($source_type = 'migrated') { //migrated video
        $videoids = get_video_in_fieldcollection_by_nid_mirtaed($nid);
        foreach ($videoids as $keys => $video_value) {
          $url = $video_value->field_migrated_video_url_value;
        }
        $data_video = itg_videogallery_get_video_bitrate_by_url($url, $nid);
        $bitrate_url = $data_video['bitrate_url'];
        $mp4_url = $data_video['file_url'];
        $video_url = $mp4_url;
      }
      else {
        $videotag = itg_video_detail_formats($nid, $source_type);
        $video_url = $videotag['dailymotion']['bitate_url']['videoparts_mp4'];
      }

      $xml .= '<item>';
      $xml .= '<id>' . $nid . '</id>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $video_url . ']]></link>';
      $xml .= '<description><![CDATA[' . $value['field_story_expert_description_value'] . ']]></description>';
      $xml .= '<pubDate>' . $created_date . '</pubDate>';

      $xml .= '<media:content url="' . $video_url . '" type="video/mp4">';
      $xml .= '<media:title>' . $value['title'] . '</media:title>';
      $xml .= '<media:description><![CDATA[' . $value['field_story_expert_description_value'] . ']]></media:description>';
      $xml .= '<media:thumbnail url="' . $small_img['imag_url'] . '"></media:thumbnail>';
      $xml .= '<media:keywords><![CDATA[' . $key_words . ']]></media:keywords>';
      $xml .= '<media:category>' . $catname . '</media:category>';
      $xml .= '<guid></guid>';
      $xml .= '</media:content>';
      $xml .= '</item>';
    }
  }
  $xml .= '</channel>';
  $xml .= '</rss>';
  return $xml;
}
