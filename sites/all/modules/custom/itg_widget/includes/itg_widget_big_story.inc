<?php

/**
 * @file
 * Big story main file.
 */

/**
 * Function big sotry funtionality.
 * @param array $big_story_data
 */
function save_big_story_widget_data($big_story_data) {
  $widget = 'big_story_format_widget';
  $content_type = isset($_GET['type']) ? $_GET['type'] : "breaking_news";
  $selected_node = $big_story_data['selection'][0];
  $related_nodes_json = '[]';
  // Delete entry first.
  // Remove except livetv.
  try {
    db_delete('itg_widget_order')
        ->condition('widget' , $widget)
        ->condition('extra' , '[]')
        ->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }

  try {
    $query = db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $selected_node ,
          'widget' => $widget ,
          'content_type' => $content_type ,
          'cat_id' => 0 ,
          'weight' => 0 ,
          'extra' => $related_nodes_json ,
        ))
        ->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
}

/**
 * Function to get nodeid's server.
 * 
 * @param string $related_content_string
 * @return json
 */
function get_related_content_with_server_prefix($related_content_string) {
  $relates_content_array_with_prefix = explode("," , $related_content_string);
  $temp_related_content_array = array();
  foreach ($relates_content_array_with_prefix as $key => $value) {
    $temp_related_exploded_array = explode('_' , $value);
    $temp_related_content_array[] = array($temp_related_exploded_array[0] => $temp_related_exploded_array[1]);
  }
  return json_encode($temp_related_content_array);
}

/**
 * Function to get block data into array.
 * @param array $info
 * @return array
 */
function itg_widget_big_story_block_data($info) {
  $big_story_block_data = array();
  $widget_name = isset($info['widget']) ? $info['widget'] : "";
  if ( !empty($widget_name) ) {
    $query = db_select('itg_widget_order' , 'iwo')
        ->fields('iwo' , array('nid' , 'extra'))
        ->orderBy('iwo.nid' , 'ASC')
        ->condition('widget' , $widget_name);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $big_story_data) {
      if ( $big_story_data['extra'] == 'big_story_live_tv_active' && $big_story_data['nid'] == 0 ) {
        $big_story_block_data[] = array("is_live_tv" => TRUE);
      }
      elseif ( $big_story_data['nid'] ) {
        $big_story_block_data[] = array("node_load_data" => node_load($big_story_data['nid']));
      }
    }
    return $big_story_block_data;
  }
}
