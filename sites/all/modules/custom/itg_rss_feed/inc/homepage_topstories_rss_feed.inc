<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate articleRSSFeed
 *
 * @return string
 */
function homepage_topstories_rss_feed() {
  global $base_url;
  $output = "";
  $redis_key = "itgd_rss_articleRSSFeed";
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_home_top();

    $output .= get_home_top_article_item_rss();

    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * function for get home page articles xml feed
 *
 * @return string
 */
function get_home_top_article_item_rss() {
  global $base_url;
  $widget_name = "top_stories_widget";
  $output = "";
  $range_min = 0;
  $range_max = 25;
  $order_by = 'ASC';
  //$type = array("videogallery", "photogallery", "story");
  $type = array("story");
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->condition('iwo.widget', $widget_name);
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->groupBy('n.nid');
  $query->orderBy('iwo.weight', $order_by);
  $query->orderBy('n.nid', 'DESC')->range($range_min, $range_max)->fields('iwo', array('nid', 'extra', 'weight'));

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('kt', array('field_story_kicker_text_value'));

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $counter = 0;
  foreach ($result as $reskey => $resvalue) {
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
    $output .= '<link><![CDATA[' . $url . '?utm_source=rss]]></link>';
    $output .= '<description><![CDATA[' . $field_story_kicker_text_value . ']]></description>';
    $output .= '<pubDate>' . $created_date . ' GMT</pubDate>';
    $output .= '</item>';
  }
  return $output;
}
