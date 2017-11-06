<?php

/**
 * Function for ajax request callback
 */
function cricket_live_blog_content_callback() {
  $match_id = $_POST['match_id'];
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
 * function for show Cricket data from json.
 * @param string $match_id
 * @param int $start
 * @param int $total
 * @param int $commentary_id
 * @param boolean $latest
 * @return array
 */
function get_cricket_live_blog_data($match_id, $limit = NULL) {
  if (!empty($match_id)) {
    $api_base_url = 'http://feeds.intoday.in/xml_it/commentary/';
    $match_commentary = file_get_contents($api_base_url . $match_id . '_ballbyball.json');

    if ($match_commentary) {
      $commentary = array();
      $match_commentary = json_decode($match_commentary);
      $innings = $match_commentary->Match->Innings;
      if (!is_array($innings)) {
        $innings = array($innings);
      }
      $innings = array_reverse($innings, TRUE);

      if (!is_array($innings)) {
        $innings = array($innings);
      }
      foreach ($innings as $key => $value) {
        $nodes = array();
        if (!empty($value->Node)) {
          $nodes = array_reverse($value->Node);
        }
        foreach ($nodes as $node_key => $node_value) {
          $commentary[] = $node_value;
        }
      }
      if (!empty($limit)) {
        $commentary = array_slice($commentary, 0, $limit);
      }
      return theme('cricket_live_blog_commentary', array('data' => $commentary));
    }
  }
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
  die;
}

/**
 * 
 * @param int $nid
 * @param int $page
 * @return boolean/array
 */
function get_commentary_data_db($nid, $page) {
  $data = FALSE;  
    if (isset($nid) && !empty($nid)) {
      $query = db_select('field_data_field_breaking_content_details', 'bcd');
      $query->addField('bt', 'field_breaking_tile_value', 'Commentary');
      $query->addExpression($page, 'innings');
      $query->leftJoin('field_data_field_breaking_tile', 'bt', '(bt.entity_id = bcd.field_breaking_content_details_value)');
      $query->isNotNull('bcd.field_breaking_content_details_value');
      $query->condition('bcd.entity_id', $nid, '=');
      $query->condition('bcd.bundle', 'breaking_news', '=');
      $query->condition('bcd.entity_type', 'node', '=');
      $query->condition('bt.bundle', 'field_breaking_content_details', '=');
      $query->condition('bt.entity_type', 'field_collection_item', '=');
      $query->range((20 * $page), 20);
      $query_result = $query->execute()->fetchAll();
      if (!empty($query_result) && count($query_result) > 0) {
        return theme('cricket_live_blog_commentary', array('data' => $query_result));
      }
    }
  return $data;
}