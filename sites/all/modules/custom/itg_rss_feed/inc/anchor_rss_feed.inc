<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate anchorRSSFeed
 *
 * @return string
 */
function anchor_rss_feed() {
  global $base_url;
  $output = "";

  $redis_key = "itgd_rss_anchorRSSFeed";
  //~ $result_get = getRedis($redis_key);
  if (FALSE && $result_get['key_value'] != "") {
    $output = $result_get['key_value'];
  }
  else {
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $output .= get_rss_feed_header();
    $output .= get_rss_feed_sub_header_anchors();

    $output .= get_anchor_item_rss();

    $output .= get_rss_feed_footer();
    // set into redis
//        $result_set = setRedis($redis_key, $output, $ttl);
  }
  header('Content-Type: application/xml; charset=utf-8');
  print $output;
  drupal_exit();
}

/**
 * function for get anchor node item
 *
 * @return string
 */
function get_anchor_item_rss() {
  global $base_url;
  $output = "";

  $query = db_select('node', 'n');
  $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  //$query->leftJoin('field_data_field_itg_content_publish_date', 'npd', 'npd.entity_id=n.nid');
  $query->innerJoin('field_data_field_celebrity_pro_occupation', 'fco', 'n.nid=fco.entity_id');
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->fields('n', array('nid', 'title', 'created'));
  $query->fields('dbody', array('body_value'));
  //$query->fields('npd', array('field_itg_content_publish_date_value'));
  $query->fields('eli', array('field_story_extra_large_image_fid'));
  $query->condition('fco.field_celebrity_pro_occupation_tid', 285903);
  $query->condition('n.status', 1);
  $query->condition('n.type', 'reporter');
  $query->orderBy('n.title', 'ASC');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $list_cont = 0;
  foreach ($result as $reskey => $resvalue) {
    $title = $resvalue['title'];
    $nid = $resvalue['nid'];
    $body_value = $resvalue['body_value'];
    $field_story_extra_large_image_fid = $resvalue['field_story_extra_large_image_fid'];
    $url = $base_url . "/" . drupal_get_path_alias('node/' . $nid);
    $image_data = get_thumbnails_by_fid($field_story_extra_large_image_fid);
    $img_url = $image_data->imageurl;
    $created = $resvalue['created'];
    $created_date = date("D, d M Y H:i:s", $created);
    $output .= '<item><title><![CDATA[' . $title . ']]></title><link><![CDATA[' . $url . ']]></link><description>&lt;a href=' . $url . '&gt;&lt;img src="' . $img_url . '" align="left" hspace="2" height="82" width="107" alt="" border="0" /&gt;&lt;/a&gt;<![CDATA[' . $body_value . ']]></description><pubDate>' . $created_date . '</pubDate></item>';
  }
  return $output;
}
