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
 * Function is used to generate Cabbytabby feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_cabbytabby_feed_videos_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = 'CabbyTabby';
    
    $query = db_select('node', 'n');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_source_type', 'sst', 'sst.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_expert_description', 'sed', 'sed.entity_id=n.nid');


    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('sst', array('field_story_source_type_value'));
    $query->fields('sed', array('field_story_expert_description_value'));
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'videogallery', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 10);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_cabbytabby_feed_videos_syndication_xml($result, $section_id, $section_name);
    $xml_path = 'public://rss-feeds/xml_data/cabbytabby/it/videos/';
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
 * @param string$category
 * @return string
 */
function genrate_cabbytabby_feed_videos_syndication_xml($result = NULL, $section_id, $category) {
  $xml_pub_date = end($result);
  $xml_pub_date = date("Y-m-d H:i:s", $xml_pub_date['created']);
  $xml = '';
  $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" version="2.0">';
  $xml .= '<channel>';
  $xml .= '<title><![CDATA[' . $category . ']]></title>';
  $xml .= '<link><![CDATA[feeds]]></link>';
  $xml .= '<description><![CDATA[CabbyTabby MRSS Feed]]></description>';
  $xml .= '<pubDate><![CDATA[' . $xml_pub_date . ']]></pubDate>';

  if (!empty($result)) {

    foreach ($result as $value) {
      $nid = $value['nid'];
      $video_file_name = 'video' . $nid . '.xml';
      $created_date = date("Y-m-d H:i:s", $value['created']);
      $catname = get_term_name_by_tid($section_id);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $source_type = $value['field_story_source_type_value'];
      //$videotag = itg_video_detail_formats($nid, $source_type);
      $video_data = get_itg_video_transcoding($nid);
      $meta_tags = get_node_metatags_by_nid($nid);
      $tags = get_content_tags($nid, TRUE);
      $byline = get_byline_name_by_nid($nid);
      $key_words = '';
      if (!empty($meta_tags['data'])) {
        $meta_tags = unserialize($meta_tags['data']);
        $key_words = $meta_tags['keywords']['value'];
      }

      $duration = '';
      if (count($video_data) > 0) {
        $duration = $video_data[0]->video_duration;
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
      }
      $xml .= '<item>';
      $xml .= '<guid isPermaLink="false">' . $nid . '</guid>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<description><![CDATA[' . $value['field_story_expert_description_value'] . ']]></description>';
      $xml .= '<pubDate>' . $created_date . '</pubDate>';
      $xml .= '<category><![CDATA[' . $catname . ']]></category>';
      $xml .= '<enclosure url="' . $video_url . '" type="video/mp4"/>';
      $xml .= '<media:content url="' . $video_url . '" type="video/mp4" duration="' . $duration . '">';
      $xml .= '<media:category>' . $catname . '</media:category>';
      $xml .= '<media:tags><![CDATA[' . $tags . ']]></media:tags>';
      $xml .= '<media:keywords><![CDATA[' . $key_words . ']]></media:keywords>';
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
