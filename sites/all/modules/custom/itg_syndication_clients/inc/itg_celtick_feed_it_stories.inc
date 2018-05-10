<?php

/**
 * @file
 * The ITG Syndication clients for celtick
 */
function itg_celtick_feed_it_stories() {
  $sections = getceltick_feed_story_client_array();
  foreach ($sections as $section_id => $file_name) {
    itg_genrate_celtick_feed_story_syndication($section_id, $file_name);
  }
}

/**
 * Function for Generate celtick xml feed
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_celtick_feed_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $section_name = get_term_name_by_tid($section_id);

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'sli', 'sli.entity_id=n.nid');
    
    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created', 'changed'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('sli', array('field_story_extra_large_image_fid'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 10);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $xml = genrate_celtick_feed_story_syndication_xml($result, $section_name);
    $xml_path = 'public://rss-feeds/xml_data/celtick/it/stories/';
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
function genrate_celtick_feed_story_syndication_xml($result = NULL, $category) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<root>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $nid = $value['nid'];
      $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $large_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $byline = get_byline_name_by_nid($nid);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = $value["body_value"];
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $article_type = slugify(preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($category)));
      $xml .= '<article>';
      $xml .= '<magazine>India Today</magazine>';
      $xml .= '<articletype>' . $article_type . '</articletype>';
      $xml .= '<edition>' . $publish_date . ' +05:30</edition>';
      $xml .= '<page></page>';
      $xml .= '<frequency></frequency>';
      $xml .= '<author></author>';
      $xml .= '<byline>' . $byline . '</byline>';
      $xml .= '<volumenumber></volumenumber>';
      $xml .= '<intellectualpropertyowner>Living Media India Limited</intellectualpropertyowner>';
      $xml .= '<headline><![CDATA[' . $value['title'] . ']]></headline>';
      $xml .= '<secondaryheadline><![CDATA[' . $kicker_text . ']]></secondaryheadline>';
      $xml .= '<link>' . $url . '</link>';
      $xml .= '<image>' . $large_img['imag_url'] . '</image>';
      $xml .= '<bodytext><![CDATA[' . $body . ']]></bodytext>';
      $xml .= '</article>';
    }
    $xml .= '</root>';
  }
  return $xml;
}
