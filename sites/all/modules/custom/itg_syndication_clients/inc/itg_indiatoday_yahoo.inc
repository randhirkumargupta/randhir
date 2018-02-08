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
 * Menu callback
 */
function itg_indiatoday_yahoo_static_section_syndication() {
  $sections = getindiatoday_yahoo_client_sections();
  foreach ($sections as $key => $value) {
    itg_genrate_indiatoday_yahoo_static_section_syndication($key, $value);
  }
}

/**
 * Menu callback
 */
function itg_indiatoday_yahoo_static_mailtoday_syndication() {
  itg_genrate_indiatoday_yahoo_static_mailtoday_syndication(1206572);
}

/**
 * Menu callback
 */
function itg_indiatoday_yahoo_static_latest_stories_syndication() {
  itg_genrate_indiatoday_yahoo_static_latest_stories_syndication();
}

/**
 * @file
 * The ITG Syndication clients for yahoo budget Story
 */
function itg_indiatoday_yahoo_unionbudget2018_syndication() {
  $sections = itg_indiatoday_yahoo_unionbudget2018_section();
  foreach ($sections as $key => $value) {
    itg_genrate_indiatoday_yahoo_unionbudget2018_syndication($value, $key);
  }
}

/**
 * Menu callback
 */
function itg_indiatoday_yahoo_static_latest_issue_syndication() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  itg_genrate_indiatoday_yahoo_static_latest_issue_syndication($result);
}

/**
 * Function for generate Yahoo story feed
 * @param int $section_ids
 * @param string $file_name
 */
function itg_genrate_indiatoday_yahoo_story_syndication($section_ids = NULL, $file_name) {
  if (!empty($section_ids)) {

    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'ssi', 'ssi.entity_id=n.nid');

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_extra_large_image_fid'));
    $query->fields('ssi', array('field_story_extra_small_image_fid'));
    $query->fields('ti', array('tid'));
    
    $max_day_ago = 10;
    foreach($section_ids as $sec_id){
      $temp = get_content_fetch_time($sec_id);      
      if($max_day_ago < $temp){
        $max_day_ago = $temp;
      }
    }
    
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $max_day_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_ids, 'IN');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    $xml = genrate_indiatoday_yahoo_story_syndication_xml($result);
    $xml_path = 'public://indiatoday/yahoo/';
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
function genrate_indiatoday_yahoo_story_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $uniq_id = "indiatoday.in".$value['nid'];
      $guid = itg_genrate_uniqui_guid($uniq_id);
      $publish_date = gmdate("D, d M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $section_name = get_term_name_by_tid($value['tid']);
      $metatags = get_node_metatags_by_nid($value['nid']);
      $small_img = get_image_info_by_fid($value['field_story_extra_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $kicker_text = stripInvalidXml($kicker_text);
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . stripInvalidXml($value['title']) . ']]></title>';
      $xml .= '<link>' . $url . '</link>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '<pubDate>' . $publish_date . ' +0000</pubDate>';
      $xml .= '<guid>' . $guid . '</guid>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '<media:content url="' . $medium_img["imag_url"] . '" type="image/' . $medium_img["mime_type"] . '"/>';
      $xml .= '<media:thumbnail url="' . $small_img["imag_url"] . '" type="image/' . $small_img["mime_type"] . '"/>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '</item>';
    }
    $load_xml = simplexml_load_file("http://feeds.intoday.in/indiatoday/yahoo/top-businesstoday.xml");
    if (!empty($load_xml->children()->children())) {
      foreach ($load_xml->children()->children() as $load_xml_item) {
        $xml .= $load_xml_item->asXML();
      }
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * 
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_indiatoday_yahoo_static_section_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'ssi', 'ssi.entity_id=n.nid');

    if ($section_id != 'top') {
      $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
      $query->fields('ti', array('tid'));
      $query->condition('ti.tid', $section_id, '=');
      if($days_ago = get_content_fetch_time($section_id)){
        $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
        $query->condition('n.created', $days_ago, '>=');
      }
    }

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_medium_image_fid'));
    $query->fields('ssi', array('field_story_small_image_fid'));

    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_indiatoday_yahoo_static_section_syndication_xml($result, $section_id);
    $xml_path = 'public://indiatoday/yahoo/';
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
 * @param int $section_id
 * @return string
 */
function genrate_indiatoday_yahoo_static_section_syndication_xml($result = NULL, $section_id) {
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $guid = genrate_uniqui_guid();
      $publish_date = date("Y-m-d\TH:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      if ($section_id != 'top') {
        $section_name = get_term_name_by_tid($section_id);
      }
      else {
        $section_name = get_term_name_by_tid($value['tid']);
      }

      $metatags = get_node_metatags_by_nid($value['nid']);
      $small_img = get_image_info_by_fid($value['field_story_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_medium_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link>' . $url . '</link>';
      $xml .= '<pubDate>' . $publish_date . '</pubDate>';
      $xml .= '<guid>' . $guid . '</guid>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '<media:content url="' . $medium_img["imag_url"] . '" type="image/' . $medium_img["mime_type"] . '"/>';
      $xml .= '<media:thumbnail url="' . $small_img["imag_url"] . '" type="image/' . $small_img["mime_type"] . '"/>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * 
 * @param int $section_id
 */
function itg_genrate_indiatoday_yahoo_static_mailtoday_syndication($section_id) {
  if (!empty($section_id)) {
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));

    if($days_ago = get_content_fetch_time($section_id)){
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $xml = genrate_indiatoday_yahoo_static_mailtoday_syndication_xml($result, $section_id);
    $xml_path = 'public://indiatoday/yahoo/';
    $file_path = $xml_path . 'mailtoday.xml';
    $fp = fopen($file_path, "w");
    fwrite($fp, $xml);
    fclose($fp);
  }
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param int $section_id
 * @return string
 */
function genrate_indiatoday_yahoo_static_mailtoday_syndication_xml($result, $section_id) {
  if (!empty($result)) {
    global $base_url;
    $last_pub_date = end($result);
    $last_pub_date = date("F d, Y H:i:s P", strtotime($last_pub_date['field_itg_content_publish_date_value']));
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ MAIL TODAY ]]></title>';
    $xml .= '<description><![CDATA[ MAIL TODAY ]]></description>';
    $xml .= '<pubDate>' . $last_pub_date . '</pubDate>';
    $xml .= '<image>';
    $xml .= '<title><![CDATA[ MAIL TODAY ]]></title>';
    $xml .= '</image>';
    $xml .= '<language>en</language>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $guid = genrate_uniqui_guid();
      $publish_date = date("Ymd\THis", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $section_name = get_term_name_by_tid($section_id);
      $metatags = get_node_metatags_by_nid($value['nid']);
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title>' . $value['title'] . '</title>';
      $xml .= '<pubDate>' . $publish_date . '</pubDate>';
      $xml .= '<guid>' . $guid . '</guid>';
      $xml .= '<description><![CDATA[' . $body . ']]></description>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * Generate latest-stories.xml xml feed
 */
function itg_genrate_indiatoday_yahoo_static_latest_stories_syndication() {
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('pc', array('field_primary_category_value'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));

  $days_ago = strtotime(date('Y-m-d', strtotime('-10 days')));
  $query->condition('n.created', $days_ago, '>=');
  
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = genrate_indiatoday_yahoo_static_latest_stories_syndication_xml($result);
  $xml_path = 'public://indiatoday/yahoo/';
  $file_path = $xml_path . 'latest-stories.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @return string
 */
function genrate_indiatoday_yahoo_static_latest_stories_syndication_xml($result) {
  if (!empty($result)) {
    global $base_url;
    $last_node = end($result);
    $last_node_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $last_node['nid']);
    $last_pub_date = date("F d, Y H:i:s P", strtotime($last_node['field_itg_content_publish_date_value']));
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ INDIA TODAY ]]></title>';
    $xml .= '<description><![CDATA[ INDIA TODAY ]]></description>';
    $xml .= '<link><![CDATA[ ' . FRONT_URL . ' ]]></link>';
    $xml .= '<pubDate>' . $last_pub_date . '</pubDate>';
    $xml .= '<image>';
    $xml .= '<title><![CDATA[ INDIA TODAY ]]></title>';
    $xml .= '<link><![CDATA[ ' . $last_node_url . ' ]]></link>';
    $xml .= '<url><![CDATA[ ' . FRONT_URL . ' ]]></url>';
    $xml .= '</image>';
    $xml .= '<language>en</language>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $guid = genrate_uniqui_guid();
      $publish_date = date("Ymd\THis", strtotime($value['field_itg_content_publish_date_value']));
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $section_name = get_term_name_by_tid($value['field_primary_category_value']);
      $metatags = get_node_metatags_by_nid($value['nid']);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[ ' . $url . ' ]]></link>';
      $xml .= '<pubDate>' . $publish_date . '</pubDate>';
      $xml .= '<guid>' . $url . '</guid>';
      $xml .= '<description><![CDATA[' . $value['field_story_kicker_text_value'] . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * Function is used to generate indiatoday-magazine-latest-issue-rss-feed.xml feed
 * @param array $issue_result
 */
function itg_genrate_indiatoday_yahoo_static_latest_issue_syndication($issue_result) {
  $title = $issue_result[0]['title'];
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
  $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');

  $query->fields('ti', array('tid'));
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));

  $query->condition('isuue.field_story_issue_date_value', $title, '=');
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = genrate_indiatoday_yahoo_static_section_syndication_xml($result, 'top');
  $xml_path = 'public://indiatoday/yahoo/';
  $file_path = $xml_path . 'indiatoday-magazine-latest-issue-rss-feed.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}


/**
 * 
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_indiatoday_yahoo_unionbudget2018_syndication($section_ids = NULL, $file_name) {
  if (!empty($section_ids)) {
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'smi', 'smi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'ssi', 'ssi.entity_id=n.nid');

    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_extra_large_image_fid'));
    $query->fields('ssi', array('field_story_extra_small_image_fid'));
    $query->fields('ti', array('tid'));
    
    
    $days_ago = strtotime(date('Y-m-d', strtotime('-60 days')));
    $query->condition('n.created', $days_ago, '>=');
    
    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_ids, 'IN');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    
    $xml = genrate_indiatoday_yahoo_story_unionbudget2018_syndication_xml($result);
    $xml_path = 'public://rss-feeds/xml_data/yahoo/it/stories/budget/2018/';
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
function genrate_indiatoday_yahoo_story_unionbudget2018_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= '<channel>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $uniq_id = "indiatoday.in".$value['nid'];
      $guid = itg_genrate_uniqui_guid($uniq_id);
      $publish_date = gmdate("D, d M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $section_name = get_term_name_by_tid($value['tid']);
      $metatags = get_node_metatags_by_nid($value['nid']);
      $small_img = get_image_info_by_fid($value['field_story_extra_small_image_fid']);
      $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $keywords = '';
      if ($metatags) {
        $temp = unserialize($metatags['data']);
        $keywords = $temp['keywords']['value'];
      }
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link>' . $url . '</link>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '<pubDate>' . $publish_date . ' +0000</pubDate>';
      $xml .= '<guid>' . $guid . '</guid>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content:encoded><![CDATA[' . $body . ']]></content:encoded>';
      $xml .= '<keywords><![CDATA[' . $keywords . ']]></keywords>';
      $xml .= '<media:content url="' . $medium_img["imag_url"] . '" type="image/' . $medium_img["mime_type"] . '"/>';
      $xml .= '<media:thumbnail url="' . $small_img["imag_url"] . '" type="image/' . $small_img["mime_type"] . '"/>';
      $xml .= '<category>' . $section_name . '</category>';
      $xml .= '</item>';
    }
    
    $xml .= '</channel>';
    $xml .= '</rss>';
  }
  return $xml;
}
