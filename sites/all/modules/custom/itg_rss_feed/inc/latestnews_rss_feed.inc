<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate latestnews rss feed
 *
 * @return string
 */
function latestnews_rss_feed() {
  global $base_url;
  $output = "";
  $redis_key = "itgd_rss_latestnewsRSSFeed";
  $top_stories_section = 1206584;
  $section_url = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $top_stories_section);
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_latestnews($section_url);
    $output .= get_latest_news_item_rss();
    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;
  drupal_exit();
}

/**
 * Function is used to generate latest news rss feed
 * @global string $base_url
 * @return string
 */
function get_latest_news_item_rss() {
  global $base_url;
  $output = "";
  $range_min = 0;
  $range_max = 25;
  $top_stories_section = 1206584;
  $must_read_section = 1206638;
  //$type = array("videogallery", "photogallery", "story");
  $type = array("story");

  //Get top 1 stories from top stories section
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', $type, 'IN');
  $query->condition('ti.tid', $top_stories_section, '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 1);
  $top_stories = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $exclude_ids = array($top_stories[0]['nid']);
  //Get top 25 stories from Must read section
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->join('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->condition('ti.tid', $must_read_section, '=');
  $query->condition('n.nid', $exclude_ids, 'NOT IN');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range(0, 25);
  $must_read = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $total_result = array_merge($top_stories, $must_read);

  $counter = 0;
  foreach ($total_result as $reskey => $resvalue) {
    if (is_lock_story_rss_feed($resvalue['nid'])) {
      continue;
    }
    $counter++;
    if ($counter == 5) {
      $output .= '<item>';
      $output .= '<title><![CDATA[Subscribe Now]]></title>';
      $output .= '<link><![CDATA[http://indiatoday.intoday.in/subscription.html?utm_source=rss]]></link>';
      $output .= '<description><![CDATA[Subscribe now for your favourite magazines]]></description>';
      $output .= '</item>';
    }
    $title = $resvalue['title'];
    $nid = $resvalue['nid'];
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $created = $resvalue['created'];
    $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);
    $output .= '<item><title><![CDATA[' . $title . ']]></title>';
    $output .= '<link><![CDATA[' . $url . ']]></link>';
    $output .= '<description><![CDATA[' . $field_story_kicker_text_value . ']]></description>';
    $output .= '<pubDate>' . $created_date . ' GMT</pubDate>';
    $output .= '</item>';
  }
  return $output;
}
