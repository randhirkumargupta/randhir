<?php

/**
 * @file
 * The ITG Syndication clients for BSB Story
 */
function itg_indiatoday_yahoo_syndication() {
  $sections = getindiatoday_yahoo_client_array();
  itg_genrate_indiatoday_yahoo_story_syndication($sections['ids'], $sections['filename']);
}

/**
 * menu callback for bsb story syndication
 */
function itg_genrate_indiatoday_yahoo_story_syndication($section_ids = NULL, $file_name) {
  if (!empty($section_ids)) {

    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));
    $query->fields('ti', array('tid'));

    $query->condition('ti.tid', $section_ids, 'IN');
    $query->condition('n.status', 1);
    $query->condition('n.type', $type, 'IN');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $xml = genrate_indiatoday_yahoo_story_syndication_xml($result);
<<<<<<< HEAD
    $xml_path = 'public://files/Yahoo/';
=======
    $xml_path = 'public://indiatoday/Yahoo/';
>>>>>>> c4c0c905dca8304947d5f8ba62aaf62cb0e960f6
    $file_path = $xml_path . $file_name;
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

function genrate_indiatoday_yahoo_story_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';

    foreach ($result as $key => $value) {
      $guid = genrate_uniqui_guid();
      $publish_date = date("Y-m-d\TH:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $url = $base_url . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $section_name = get_term_name_by_tid($value['tid']);
      $metatags = get_node_metatags_by_nid($value['nid']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $keywords = '';
      if ($metatags) {
        $keywords = $metatags['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<category>' . $section_name . '></category>';
      $xml .= '<pubDate>' . $publish_date . '></pubDate>';
      $xml .= '<guid>' . $guid . '</guid>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '<media:content url="' . $medium_img["imag_url"] . '" type="image/' . $medium_img["mime_type"] . '"/>';
      $xml .= '<media:thumbnail url="' . $small_img["imag_url"] . '" type="image/' . $small_img["mime_type"] . '"/>';
      $xml .= '<category>' . $section_name . '></category>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
