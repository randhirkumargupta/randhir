<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate articleRSSFeed
 *
 * @return string
 */
function article_rss_feed() {
  global $base_url;

  $section_id = $_GET['section_id'];
  $output = "";
  $term_name = '';
  $section_url = NULL;
  if (!empty($section_id)) {
    $term_name = taxonomy_term_load($section_id)->name;
    $section_url = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $section_id);
  }
  $redis_key = "itgd_rss_articleRSSFeed_" . $section_id;
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_article($term_name, $section_url);

    $output .= get_article_item_rss($section_id, $term_name, $section_url);

    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * Function for get article feed
 * @global string $base_url
 * @param int $section_id
 * @param string $term_name
 * @param string $section_url
 * @return string
 */
function get_article_item_rss($section_id, $term_name, $section_url) {
  global $base_url;
  $tid_list = array();
  $tid = $section_id;
  $tid_list = array();
  if (!empty($tid)) {
    $tid_list[] = $tid;
  }
  $output = "";
  $range_min = 0;
  $range_max = 25;
  //$type = array("videogallery", "photogallery", "story");
  $type = array("story");

  if (!empty($tid)) {
    $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
  }
  $term_tree_count = count($term_tree);
  if ($term_tree_count) {
    foreach ($term_tree as $key => $value) {
      $tid_list[] = $value->tid;
    }
  }
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  if (!empty($section_id)) {
    $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $tid_list, 'IN');
  }
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $list_cont = 0;
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
    $body_value = $resvalue['body_value'];
    $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $image_data = get_thumbnails_by_fid($field_story_extra_large_image_fid);
    $img_url = $image_data->imageurl;
    $created = $resvalue['created'];
    $field_story_kicker_text_value = $resvalue['field_story_kicker_text_value'];
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);
    $output .= '<item><title><![CDATA[' . $title . ']]></title><link><![CDATA[' . $url . '/?utm_source=rss]]></link><description><![CDATA[<a href="' . $url . '/?utm_source=rss"><img src="' . $img_url . '" align="left" hspace="2" height="180" width="305" alt="" border="0"/></a>' . $field_story_kicker_text_value . ']]></description><pubDate>' . $created_date . ' GMT</pubDate></item>';
  }
  return $output;
}

/**
 * Function for generate google newsstand feed
 * @global string $base_url
 */
function article_rss_feed_google_newsstand() {
  global $base_url;

  $section_id = $_GET['section_id'];
  $output = "";
  $term_name = '';
  $section_url = NULL;
  if (!empty($section_id)) {
    $term_name = taxonomy_term_load($section_id)->name;
    $section_url = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $section_id);
  }
  $redis_key = "itgd_rss_article_google_newsstandRSSFeed_" . $section_id;
//    $result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
//        $output = $result_get['key_value'];
  }
  else {
    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_google_stand_header();
    $output .= get_rss_feed_sub_header_article_news_stand($term_name, $section_url);

    $output .= get_article_google_stand_item_rss($section_id, $term_name, $section_url);

    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * Function for Editors Pic feed
 * @global string $base_url
 */
function indiatoday_editors_pic() {
  global $base_url;
  $section_id = $_GET['section_id'];
  $output = "";
  $term_name = '';
  $section_url = NULL;
    //anchorRSSFeed writing...
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_google_stand_header();
    $output .= get_rss_feed_sub_header_editors_pic();
    $output .= get_article_editors_pic_item_rss();
    $output .= get_rss_feed_footer();

  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 *
 * @global string $base_url
 * @param int $section_id
 * @param string $term_name
 * @param string $section_url
 * @return string
 */
function get_article_google_stand_item_rss($section_id, $term_name, $section_url) {
  global $base_url;
  $tid = ($section_id) ? $section_id : '1206723';
  $tid_list = array();
  if (!empty($tid)) {
    $tid_list[] = $tid;
  }
  $output = "";
  $range_min = 0;
  $range_max = 25;
  //$type = array("videogallery", "photogallery", "story");
  $type = array("story");

  if (!empty($tid)) {
    $term_tree = taxonomy_get_tree(CATEGORY_MANAGMENT, $tid, $max_depth = NULL, $load_entities = FALSE);
  }
  $term_tree_count = count($term_tree);
  if ($term_tree_count) {
    foreach ($term_tree as $key => $value) {
      $tid_list[] = $value->tid;
    }
  }

  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_reporter', 'sr', 'sr.entity_id=n.nid');
 // $query->leftJoin('node', 'reporter', 'sr.field_story_reporter_target_id=reporter.nid');
  $query->fields('n', array('nid', 'title', 'created'));
 // $query->fields('reporter', array('title'));
  $query->fields('dbody', array('body_value'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->condition('n.nid', '1144609', '!=');
  if (!empty($tid)) {
    $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $tid, '=');
    $query->leftJoin('field_data_field_primary_category', 'pc', 'pc.entity_id=n.nid');
    $query->condition('pc.field_primary_category_value', $tid_list, 'IN');
  }
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    if (is_lock_story_rss_feed($resvalue['nid'])) {
      continue;
    }
    $title = stripInvalidXml($resvalue['title']);
    $nid = $resvalue['nid'];
    $body_value = stripInvalidXml($resvalue['body_value']);
    $body_value = remove_extra_tag_in_body($body_value);
    $body_value = remove_iframe_img_tags($body_value);

    $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $reporter = get_byline_name_by_nid($nid);
    $created = $resvalue['created'];
    $field_story_kicker_text_value = stripInvalidXml($resvalue['field_story_kicker_text_value']);
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);
    $file_data = get_image_info_by_fid($field_story_extra_large_image_fid);
    $img_url = $file_data['imag_url'];
    $caption = $file_data['caption'];
    $figure  = "<figure><img src='".$img_url."' width='505' /><figcaption>". $caption ."</figcaption></figure>";
    $output .= '<item><title><![CDATA[' . $title . ']]></title>';
    $output .= '<link><![CDATA[' . $url . ']]></link>';
    $output .= '<guid>' . $url . '</guid>';
    $output .= '<pubDate>' . $created_date . '</pubDate>';
    $output .= '<dc:creator>' . $reporter . '</dc:creator>';
    $output .= '<description><![CDATA[' . $field_story_kicker_text_value . ']]></description>';
    $output .= '<content:encoded><![CDATA[' . $figure . $body_value . ']]></content:encoded>';
    $output .= '</item>';
  }
  return $output;
}

/**
 *
 * @global string $base_url
 * @param int $section_id
 * @param string $term_name
 * @param string $section_url
 * @return string
 */
function get_article_editors_pic_item_rss() {
  global $base_url;
  $tid = '1206641';
  $output = "";
  $range_min = 0;
  $range_max = 5;
  //$type = array("videogallery", "photogallery", "story");
  $result = editor_pic_node_list($tid,$range_min,$range_max);
  foreach ($result as $reskey => $resvalue) {
    if (is_lock_story_rss_feed($resvalue['nid'])) {
      continue;
    }
    $title = stripInvalidXml($resvalue['title']);
    $nid = $resvalue['nid'];

    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $reporter = get_byline_name_by_nid($nid);
    $created = $resvalue['created'];
    $field_story_kicker_text_value = stripInvalidXml($resvalue['field_story_kicker_text_value']);
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);

    $output .= '<item><title><![CDATA[' . $title . ']]></title>';
    $output .= '<link><![CDATA[' . $url . ']]></link>';
    $output .= '<guid><![CDATA[' . $url . ']]></guid>';
    $output .= '<description><![CDATA[' . $field_story_kicker_text_value . ']]></description>';
    $output .= '<dc:creator><![CDATA[' . $reporter . ']]></dc:creator>';
    $output .= '<pubDate><![CDATA[' . $created_date . ']]></pubDate>';
    $output .= '</item>';
  }
  return $output;
}
/**
* Common function to get the node
* @args: tid
* @$range_min
* @range_max
* @return array
**/
function editor_pic_node_list($tid,$range_min,$range_max){

  $type = array("story");
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
 // $query->fields('reporter', array('title'));
  //$query->fields('dbody', array('body_value'));
  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->condition('n.status', 1);
  $query->condition('n.type', 'story', '=');
  $query->leftJoin('field_data_field_story_category', 'sc', 'sc.entity_id=n.nid');
  $query->condition('sc.field_story_category_tid', $tid, '=');
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($range_min, $range_max);
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}
