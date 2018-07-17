<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate photo_rss_feed
 *
 * @return string
 */
function photo_rss_feed() {
  global $base_url;
  $section_id = $_GET['section_id'];
  $output = "";
  $term_name = '';
  $section_url = NULL;
  if (!empty($section_id)) {
    $term_name = taxonomy_term_load($section_id)->name;
    $section_url = FRONT_URL . "/" . drupal_get_path_alias('taxonomy/term/' . $section_id);
  }
  $redis_key = "itgd_rss_videoRSSFeed_" . $section_id;
  //$result_get = getRedis($redis_key);

  if (FALSE && $result_get['key_value'] != "") {
    $output = $result_get['key_value'];
  }
  else {
    //videoRSSFeed writing...
    //$ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_photo($term_name, $section_url);

    $output .= get_photo_item_rss($section_id, $term_name, $section_url);

    $output .= get_rss_feed_footer();
    // set into redis
    // $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  echo $output;
  drupal_exit();
}

/**
 * Function is used to generate photo rss feed
 * @global string $base_url
 * @param int $section_id
 * @param string $term_name
 * @param string $section_url
 * @return string
 */
function get_photo_item_rss($section_id, $term_name, $section_url) {
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
  $type = array("photogallery");

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
  $query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');

  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $days_ago = strtotime(date('Y-m-d', strtotime('-7 days')));
  $query->condition('n.created', $days_ago, '>=');
  $query->condition('n.status', 1);
  $query->condition('n.type', 'photogallery', '=');
  if (!empty($section_id)) {
    $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
    $query->condition('ti.tid', $tid_list, 'IN');
  }
  $query->orderBy('n.created', 'DESC');
  $query->groupBy('n.nid')->range($range_min, $range_max);

  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $counter = 0;
  $copyright_yr = date("Y");
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
    $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
    $url = FRONT_URL . "/" . drupal_get_path_alias('node/' . $nid);
    $image_data = get_thumbnails_by_fid($field_story_extra_large_image_fid);
    $img_url = $image_data->imageurl;

    $image_mime_type = $image_data->filemime;
    $created = $resvalue['created'];
    date_default_timezone_set("GMT");
    $created_date = date("D, d M Y H:i:s e", $created);

    $output .= '<item>';
    $output .= '<title><![CDATA[' . $title . ']]></title>';
    $output .= '<link><![CDATA[' . $url . '?utm_source=rss]]></link>';
    $output .= '<description><![CDATA[ <a href="' . $url . '?utm_source=rss"><img src="' . $img_url . '" align="left" hspace="2" height="82" width="107" alt="" border="0"/></a>]]>' . $title . '</description>';
    $output .= '<media:description type="html"><![CDATA[ <a href="' . $url . '?utm_source=rss"><img src="' . $img_url . '" /></a><br/>]]></media:description>';
    $output .= '<media:thumbnail url="' . $img_url . '" />';
    $output .= '<media:content medium="image" type="' . $image_mime_type . '" url="' . $img_url . '" />';
    $output .= '<media:copyright>© ' . $copyright_yr . ' India Today Group. All Rights Reserved.</media:copyright>';
    $output .= '<pubDate><![CDATA[' . $created_date . ']]></pubDate>';
    $output .= '</item>';
  }
  return $output;
}
