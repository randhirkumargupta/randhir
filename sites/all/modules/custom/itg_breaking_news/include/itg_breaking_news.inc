<?php

/**
 * Function for ajax request callback
 */
function cricket_live_blog_content_callback() {
  $match_id = $_GET['match_id'];
  if (isset($match_id)) {
    $html = get_cricket_live_blog_data($match_id);
    print json_encode(array('status' => 'success', 'data' => $html));
  }
  else {
    print json_encode(array('status' => 'error'));
  }
  drupal_exit();
}



/**
 * Menu callback for load commentary from db
 * @param int $nid
 * @param int $page
 * 
 */
function get_commentary_data_db_callback($nid, $page = 0) {
  $data = get_commentary_data_db($nid, $page);
  if ($data) {
    print json_encode(array('status' => 'success', 'data' => $data));
  }
  else {
    print json_encode(array('status' => 'error'));
  }
  drupal_exit();
}
