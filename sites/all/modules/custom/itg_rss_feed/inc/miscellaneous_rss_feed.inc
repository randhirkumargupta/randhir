<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate miscellaneous rss feed
 *
 * @return string
 */
function miscellaneous_rss_feed() {
  global $base_url;
  $output = "";
  $redis_key = "itgd_rss_miscellaneousRSSFeed";
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_miscellaneous();
    $output .= get_miscellaneous_item_rss();
    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * Function is used to generate miscellaneous rss feed
 * @global string $base_url
 * @return string
 */
function get_miscellaneous_item_rss() {
  global $base_url;
  $output = "";
  $range_min = 0;
  $range_max = 25;
  $miscellaneous_section = 1206633;
  
  $type = array("story");

  //Get top 1 stories from top stories section
  $query = db_select('node', 'n');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->condition('ti.tid', $miscellaneous_section, '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 100);
  $miscellaneous_story = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($miscellaneous_story as $reskey => $resvalue) {
    if (is_lock_story_rss_feed($resvalue['nid'])) {
      continue;
    }
    $title = $resvalue['title'];
    $nid = $resvalue['nid'];
    $created = $resvalue['created'];
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);
    $output .= '<item><title><![CDATA[' . $title . ']]></title>';
    $output .= '<pubDate>' . $created_date . ' GMT</pubDate>';
    $output .= '</item>';
  }
  return $output;
}
