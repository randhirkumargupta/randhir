<?php

/*
 * Inc file contains the functions
 */

/**
 * Callback function for category name autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category filter view
 */
function itg_category_autocomplete_list($string) {
  $itg_query = db_select('taxonomy_term_data', 'itg');
  $itg_query->condition('vid', CATEGORY_MANAGMENT, '=');
  $itg_query->condition('name', '%' . $string . '%', 'LIKE')
      ->fields('itg', array('tid', 'name'));
  $itg_result = $itg_query->execute();
  $result = array();
  foreach ($itg_result as $value) {
    $name = $value->name.'('.$value->tid.')';
    $result[$name] = $value->name.'('.$value->tid.')';
  }
  
  return drupal_json_output($result);
}