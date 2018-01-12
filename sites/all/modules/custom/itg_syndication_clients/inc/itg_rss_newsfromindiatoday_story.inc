<?php

/**
 * @file
 * The ITG Syndication
 */
function itg_rss_newsfromindiatoday_syndication() {
  itg_genrate_newsfromindiatoday_syndication(1206578, 'newsfromindiatoday.xml');
}

/**
 * Function for generate newsfromindiatoday feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_newsfromindiatoday_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_short_headline', 'sheadline', 'sheadline.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_itg_tags', 'story_tags', 'story_tags.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('sheadline', array('field_story_short_headline_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 30);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_newsfromindiatoday_story_syndication_xml($result, $section_name);
    $xml_path = 'public://indiatoday/rss/';
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
 * @param string $category
 * @return string
 */
function genrate_newsfromindiatoday_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $publish_date = date("Y-m-d H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $modify_date = date("Y-m-d\TH:i:sP", $value['changed']);
      $place = get_content_city($value['nid']);
      $keyword = get_content_tags($value['nid'], TRUE);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<description><![CDATA[' . $value['field_story_short_headline_value'] . ']]></description>';
      $xml .= '<ContentItem Href="' . $small_img['imag_url'] . '"><![CDATA[ <MediaType FormalName="Picture" /> <MimeType FormalName="image/jpg"/><Property FormalName="caption" value="' . $small_img["caption"] . '"/>]]></ContentItem>';
      $xml .= '<revision_number>1</revision_number>';
      $xml .= '<pubdate><![CDATA[' . $publish_date . ']]></pubdate>';
      $xml .= '<story_id><![CDATA[' . $value['nid'] . ']]></story_id>';
      $xml .= '<headline><![CDATA[' . $value['field_story_short_headline_value'] . ']]></headline>';
      $xml .= '<abstract><![CDATA[' . $kicker_text . ']]></abstract>';
      $xml .= '<keywords><![CDATA[' . $keyword . ']]></keywords>';
      $xml .= '<subject_matter><![CDATA[' . $value['field_story_short_headline_value'] . ']]></subject_matter>';
      $xml .= '<body><![CDATA[' . $body . ']]></body>';
      $xml .= '<image_caption><![CDATA[' . $medium_img['caption'] . ']]></image_caption>';
      $xml .= '<short_caption><![CDATA[' . $small_img['caption'] . ']]></short_caption>';
      $xml .= '<story_type><![CDATA[Picture]]></story_type>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
