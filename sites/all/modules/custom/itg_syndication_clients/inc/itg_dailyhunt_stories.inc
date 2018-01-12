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
 * Function is used to generate Dailyhunt Story
 * @param int $section_id
 * @param string $file_name
 */
function itg_genrate_dailyhunt_story_syndication($section_id = NULL, $file_name) {
  if (!empty($section_id)) {
    $type = array('story');
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
    $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_large_image', 'smi', 'smi.entity_id=n.nid');

    $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
    $query->condition('ti.tid', $section_id, '=');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('dbody', array('body_value'));
    $query->fields('npd', array('field_itg_content_publish_date_value'));
    $query->fields('synopsis', array('field_story_kicker_text_value'));
    $query->fields('smi', array('field_story_extra_large_image_fid'));

    if ($days_ago = get_content_fetch_time($section_id)) {
      $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
      $query->condition('n.created', $days_ago, '>=');
    }

    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->orderBy('n.created', 'DESC');
    $query->groupBy('n.nid')->range(0, 25);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $xml = genrate_dailyhunt_story_syndication_xml($result);
    $destination = "public://rss-feeds/xml_data/dailyhunt/it/stories/";
    $file_path = $destination . $file_name;
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
function genrate_dailyhunt_story_syndication_xml($result = NULL) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml = '<Data>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $publish_date = date("D, j M Y H:i:s", strtotime($value['field_itg_content_publish_date_value']));
      $medium_img = get_image_info_by_fid($value['field_story_extra_large_image_fid']);
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $body = remove_extra_tag_in_body($value["body_value"]);
      $body = itg_replace_token_with_data($body, $value['nid']);
      $body = itg_remove_extra_custom_tags($body);
      $kicker_text = preg_replace('/&(?!#?[a-z0-9]+;)/', ' ', html_entity_decode($value['field_story_kicker_text_value']));
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<pubdate><![CDATA[' . $publish_date . ' +0000 ]]></pubdate>';
      $xml .= '<image>' . $medium_img['imag_url'] . '</image>';
      $xml .= '<youtubeEmbedURL></youtubeEmbedURL>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<content><![CDATA[' . $body . ']]></content>';
      $xml .= '</item>';
    }
    $xml .= '</Data>';
  }
  return $xml;
}

/**
 * Generate Breaking news feed
 */
function itg_rss_breakingnewsOctober072017_syndication() {

//  $end_time = strtotime(date('Y-m-d', strtotime('+1 day', strtotime('07-10-2017'))));
  $end_time = strtotime(date('Y-m-d', strtotime('+1 day', strtotime('19-09-2017'))));
  $start_time = strtotime(date('Y-m-d', strtotime('-1 day', strtotime('19-09-2017'))));

  $query = db_select('node', 'n');

  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->join('field_data_field_type', 'ft', 'ft.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));

  $query->condition('ft.field_type_value', 'Breaking News', '=');
  $query->condition('n.created', array($start_time, $end_time), 'BETWEEN');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'breaking_news', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $destination = "public://indiatoday/";
  $xml = genrate_breaking_news_7oct2017($result);
  $file_path = $destination . 'breakingnewsOctober072017-dailyhunt.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @param array $result
 * @return string
 */
function genrate_breaking_news_7oct2017($result) {
  $xml_detail = '';
  if (!empty($result)) {
    $result = $result[0];
    $nid = $result['nid'];
    $publish_date = date("D, j M Y H:i", strtotime($result['field_itg_content_publish_date_value']));
    $updated_date = date("D, j M Y H:i", $result['changed']);
    $query = db_select('field_data_field_breaking_content_details', 'bcd');
    $query->leftJoin('field_data_field_breaking_tile', 'bt', '(bt.entity_id = bcd.field_breaking_content_details_value)');
    $query->leftJoin('field_data_field_breaking_publish_time', 'bpt', '(bpt.entity_id = bcd.field_breaking_content_details_value)');

    $query->fields('bt', array('field_breaking_tile_value'));
    $query->fields('bpt', array('field_breaking_publish_time_value'));

    $query->condition('bcd.entity_id', $nid, '=');
    $query->condition('bcd.bundle', 'breaking_news', '=');
    $query->condition('bcd.entity_type', 'node', '=');
    $query->condition('bt.bundle', 'field_breaking_content_details', '=');
    $query->condition('bt.entity_type', 'field_collection_item', '=');
    $query_result = $query->execute()->fetchAll();

    $xml_detail = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml_detail .= '<channel>';
    $xml_detail .= '<item>';
    $xml_detail .= '<pubDate>' . $publish_date . '</pubDate>';
    $xml_detail .= '<updatedDate>' . $updated_date . '</updatedDate>';
    $xml_detail .= '<title><![CDATA[' . $result['title'] . ']]></title>';
    foreach ($query_result as $_value) {
      $time = '';
      if (!empty($_value->field_breaking_publish_time_value)) {
        $time = date("H.i A", strtotime($_value->field_breaking_publish_time_value)) . '>>';
      }
      $xml_detail .= '<headline><![CDATA[ ' . $time . $_value->field_breaking_tile_value . ' ]]></headline>';
    }
    $xml_detail .= '</item>';
    $xml_detail .= '</channel>';
    $xml_detail .= '</rss>';
  }
  return $xml_detail;
}

/**
 * Generate breakingnewscategorypageurl.xml feed
 */
function itg_dailyhunt_feed_breakingnews_syndication() {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->join('field_data_field_type', 'ft', 'ft.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));

  $query->condition('ft.field_type_value', 'Breaking News', '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'breaking_news', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 3);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $destination = "public://indiatoday/";
  $xml = get_breaking_news_root_xml($result, $destination);
  $file_path = $destination . 'breakingnewscategorypageurl.xml';
  $fp = fopen($file_path, "w");
  fwrite($fp, $xml);
  fclose($fp);
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param string $file_path
 * @return string
 */
function get_breaking_news_root_xml($result, $file_path) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml .= "<channel>";
    $xml .= "<item>";
    foreach ($result as $key => $value) {
      $publish_date = date("D, j M Y H:i", strtotime($value['field_itg_content_publish_date_value']));
      $updated_date = date("D, j M Y H:i", $value['changed']);
      $filename = 'breakingnews' . date('FdY') . '-dailyhunt.xml';
      $file_path = "public://indiatoday/" . $filename;

      $xml .= '<pubDate>' . $publish_date . '</pubDate>';
      $xml .= '<updatedDate>' . $updated_date . '</updatedDate>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<url><![CDATA[' . file_create_url($file_path) . ']]></url>';
      genrate_breaking_news_lists($value['nid'], $file_path, $value['title'], $publish_date, $updated_date);
    }
    $xml .= "</item>";
    $xml .= "</channel>";
    $xml .= '</rss>';
  }
  return $xml;
}

/**
 * 
 * @param int $nid
 * @param string $file_path
 * @param string $title
 * @param string $pub_date
 * @param string $change_date
 */
function genrate_breaking_news_lists($nid, $file_path, $title, $pub_date, $change_date) {
  if (isset($nid) && !empty($nid)) {
    $query = db_select('field_data_field_breaking_content_details', 'bcd');
    $query->leftJoin('field_data_field_breaking_tile', 'bt', '(bt.entity_id = bcd.field_breaking_content_details_value)');
    $query->leftJoin('field_data_field_breaking_publish_time', 'bpt', '(bpt.entity_id = bcd.field_breaking_content_details_value)');

    $query->fields('bt', array('field_breaking_tile_value'));
    $query->fields('bpt', array('field_breaking_publish_time_value'));

    $query->condition('bcd.entity_id', $nid, '=');
    $query->condition('bcd.bundle', 'breaking_news', '=');
    $query->condition('bcd.entity_type', 'node', '=');
    $query->condition('bt.bundle', 'field_breaking_content_details', '=');
    $query->condition('bt.entity_type', 'field_collection_item', '=');
    $query_result = $query->execute()->fetchAll();

    $xml_detail = '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" xmlns:content="http://purl.org/rss/1.0/modules/content/" version="2.0">';
    $xml_detail .= '<channel>';
    $xml_detail .= '<item>';
    $xml_detail .= '<pubDate>' . $pub_date . '</pubDate>';
    $xml_detail .= '<updatedDate>' . $change_date . '</updatedDate>';
    $xml_detail .= '<title><![CDATA[' . $title . ']]></title>';
    foreach ($query_result as $_value) {
      $time = '';
      if (!empty($_value->field_breaking_publish_time_value)) {
        $time = date("H.i A", strtotime($_value->field_breaking_publish_time_value)) . '>>';
      }
      $xml_detail .= '<headline><![CDATA[ ' . $time . $_value->field_breaking_tile_value . ' ]]></headline>';
    }
    $xml_detail .= '</item>';
    $xml_detail .= '</channel>';
    $xml_detail .= '</rss>';
    $file_detail = $file_path;
    $fp1 = fopen($file_detail, "w");
    fwrite($fp1, $xml_detail);
    fclose($fp1);
  }
}
