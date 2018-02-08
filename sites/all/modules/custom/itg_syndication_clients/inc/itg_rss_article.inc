<?php

/**
 * unction for Generate Article xml feed
 * @global string $base_url
 */
function itg_rss_article() {
  global $base_url;
  $sid = (isset($_GET['sid']) ? $_GET['sid'] : 1206584); // other wise top story section

  $section_name = get_term_name_by_tid($sid);
  $type = array('story');
  $query = db_select('node', 'n');

  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  if($days_ago = get_content_fetch_time($sid)){
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
  }
  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('ti.tid', $sid, '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_rss_feed_from_sid_xml($result, $sid, $section_name);

  header('Content-Type: text/xml');
  print $xml;
  drupal_exit();
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param int $sid
 * @param string $section_name
 * @return string
 */
function get_rss_feed_from_sid_xml($result, $sid, $section_name) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $last_build_date = end($result);
    $last_build_date = date("D, j M Y H:i:s P", strtotime($last_build_date['field_itg_content_publish_date_value']));
    $logo = theme_get_setting('logo');
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $sid);
    $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ India Today | ' . $section_name . ']]></title>';
    $xml .= '<description>India Today</description>';
    $xml .= '<link><![CDATA[ ' . FRONT_URL . ']]></link>';
    $xml .= '<lastBuildDate>' . $last_build_date . '</lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . $logo . '</url>';
    $xml .= '<title><![CDATA[ India Today | ' . $section_name . ']]></title>';
    $xml .= '<link><![CDATA[' . $cat_link . ']]></link>';
    $xml .= '<description>India Today</description>';
    $xml .= '</image>';
    foreach ($result as $key => $value) {
      if (is_lock_story($value['nid'])) {
        continue;
      }
      $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $value['nid']);
      $pub_date = date("D, j M Y H:i:s P", strtotime($value['field_itg_content_publish_date_value']));
      $kicker_text = $value['field_story_kicker_text_value'];
      $xml .= '<item>';
      $xml .= '<title><![CDATA[' . $value['title'] . ']]></title>';
      $xml .= '<link><![CDATA[' . $url . ']]></link>';
      $xml .= '<description><![CDATA[' . $kicker_text . ']]></description>';
      $xml .= '<pubDate>' . $pub_date . '</pubDate>';
      $xml .= '</item>';
    }
    $xml .= '</channel>';
    $xml .= '</rss>';
    return $xml;
  }
  else {
    return not_found_syndication_xml();
  }
}
