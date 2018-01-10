<?php

/**
 * Function is used to generate JSON file
 * @global string $base_url
 */
function itg_education_rss_article() {
  global $base_url;
  $cid = (isset($_GET['cid']) ? $_GET['cid'] : 1207412); // other wise Education Today category
  $cat_name = get_term_name_by_tid($cid);
  $type = array('story');
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_kicker_text', 'synopsis', 'synopsis.entity_id=n.nid');
  $query->join('field_data_field_story_syndication', 'ss', 'ss.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created', 'changed'));
  $query->fields('synopsis', array('field_story_kicker_text_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));

  if ($days_ago = get_content_fetch_time($cid)) {
    $days_ago = strtotime(date('Y-m-d', strtotime('-' . $days_ago . ' days')));
    $query->condition('n.created', $days_ago, '>=');
  }

  $query->condition('ss.field_story_syndication_value', 'Yes', 'LIKE');
  $query->condition('ti.tid', $cid, '=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $xml = get_education_rss_feed_from_cid_xml($result, $cid, $cat_name);
  header('Content-Type: text/xml');
  print $xml;
  drupal_exit();
}

/**
 * 
 * @global string $base_url
 * @param array $result
 * @param int $cid
 * @param string $cat_name
 * @return string
 */
function get_education_rss_feed_from_cid_xml($result, $cid, $cat_name) {
  $xml = '';
  if (!empty($result)) {
    global $base_url;
    $parent_cat_name = get_parent_category_name_by_tid($cid);
    $last_build_date = end($result);
    $last_build_date = date("D, j M Y H:i:s P", strtotime($last_build_date['field_itg_content_publish_date_value']));
    $logo = theme_get_setting('logo');
    $cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $cid);
    $edu_cat_link = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/1207412');
    $xml .= '<rss xmlns:media="http://search.yahoo.com/mrss/" xmlns:atom="http://www.w3.org/2005/Atom" version="2.0">';
    $xml .= '<channel>';
    $xml .= '<title><![CDATA[ Education Today | ' . $parent_cat_name . ' | ' . $cat_name . ']]></title>';
    $xml .= '<description>Education Today</description>';
    $xml .= '<link><![CDATA[ ' . $edu_cat_link . ']]></link>';
    $xml .= '<lastBuildDate>' . $last_build_date . '</lastBuildDate>';
    $xml .= '<generator>FeedCreator 1.7.2</generator>';
    $xml .= '<image>';
    $xml .= '<url>' . $logo . '</url>';
    $xml .= '<title><![CDATA[ Education Today | ' . $parent_cat_name . ' | ' . $cat_name . ']]></title>';
    $xml .= '<link><![CDATA[' . $cat_link . ']]></link>';
    $xml .= '<description>Education Today</description>';
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
