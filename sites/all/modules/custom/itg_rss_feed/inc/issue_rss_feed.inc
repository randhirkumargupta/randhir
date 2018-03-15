<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate issue rss feed
 *
 * @return string
 */
function issue_rss_feed() {
  global $base_url;
  $output = "";
  $redis_key = "itgd_rss_issueRSSFeed";
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'issue');
  $query->orderBy('n.nid', "DESC");
  $query->range(0, 1);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

//    $latest_issue = 
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    if (count($result) > 0) {
      $issue_title = date('F d, Y', strtotime($result[0]['title']));
      $issue_url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $result[0]['nid']);
    }

    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_issue($issue_title, $issue_url);

    $output .= get_issue_article_item_rss($result[0]['title'], $issue_url);

    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * Function for get issue article xml feed
 * @global string $base_url
 * @param string $issue_title
 * @param string $issue_url
 * @return string
 */
function get_issue_article_item_rss($issue_title = NULL, $issue_url = NULL) {
  if ($issue_title == NULL) {
    return '';
  }
  global $base_url;

  $output = "";
  $range_min = 0;
  $range_max = 25;
  $order_by = 'ASC';
  //$type = array("videogallery", "photogallery", "story");
  $type = array("story");
  $query = db_select('field_data_field_story_issue_date', 'isuue');
  $query->leftJoin('node', 'n', 'n.nid=isuue.entity_id');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
  $query->condition('isuue.field_story_issue_date_value', $issue_title);
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story');
  $query->groupBy('n.nid');
  $query->orderBy('n.nid', 'ASC')->range($range_min, $range_max);

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('pc', array('field_primary_category_value'));
  $query->fields('kt', array('field_story_kicker_text_value'));

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $counter = 0;
  foreach ($result as $reskey => $resvalue) {
    $story_section_name = '';
    if (!empty($resvalue['field_primary_category_value'])) {
      $story_section = array_reverse(taxonomy_get_parents_all($resvalue['field_primary_category_value']));
      $story_section_name = $story_section[0]->name;
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
    $output .= '<sectionname>' . $story_section_name . '</sectionname>';
    $output .= '<link><![CDATA[' . $url . '?utm_source=rss]]></link>';
    $output .= '<description><![CDATA[' . $field_story_kicker_text_value . ']]></description>';
    $output .= '<pubDate>' . $created_date . '</pubDate>';
    $output .= '</item>';
  }
  return $output;
}
