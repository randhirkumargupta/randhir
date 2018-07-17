<?php

/**
 * Implement itg_get_reporter_list
 * @param string $name
 */
function itg_get_reporter_list($name) { 

  $reporter_name = db_select('node', 'n');
  $reporter_name->join('field_data_field_celebrity_pro_occupation', 'rpn', 'n.nid = rpn.entity_id');
  $reporter_name->fields('n', array('title', 'nid'));
  //$reporter_name->condition('field_celebrity_pro_occupation_tid', $term->tid, '=');
  $reporter_name->condition('n.type', 'reporter', '=');
  $reporter_name->condition('n.title', '%' . $name . '%', 'LIKE');
  $result = $reporter_name->execute();

  while ($record = $result->fetchAssoc()) {
    $r_title = strtolower($record['title']);
    $options[$r_title] = $r_title;
  }
  drupal_json_output($options);
}