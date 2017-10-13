<?php

/**
 * @file
 * The ITG Syndication clients for dailyhunt Story
 */
function itg_dailyhunt_feed_stories_syndication() {
  $sections = get_dailyhunt_sections_for_feed();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_dailyhunt_story_syndication($section_id, $file_name);
  }
}

/**
 * menu callback for dailyhunt story syndication
 */
function itg_genrate_dailyhunt_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');

    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));

    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $xml = genrate_dailyhunt_story_syndication_xml($result);
    $xml_path = 'sites/default/files/rss-feeds/ver1.0/dailyhunt/83951470/it/stories/';
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_dailyhunt_story_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<Data>';
    foreach ($result as $key => $value) {
      $publish_date = date("D, j M Y H:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<pubdate><![CDATA[' . $publish_date . ']]></pubdate>';
      $xml .= '<image>'. $medium_img['imag_url'] . '</image>';
      $xml .= '<youtubeEmbedURL></youtubeEmbedURL>';      
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content><![CDATA[' . $body . ']]></content>';
      $xml .= '</item>';
    }
    $xml .= '</Data>';
  }
  return $xml;
}
