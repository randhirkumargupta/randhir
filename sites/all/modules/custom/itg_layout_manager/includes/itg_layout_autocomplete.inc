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
  
  if (arg(1) == 'home_page') {    
    $itg_query = db_select('taxonomy_term_data', 'itg');
    $itg_query->condition('vid', CATEGORY_MANAGMENT, '=');
    $itg_query->condition('name', '%' . $string . '%', 'LIKE')
            ->fields('itg', array('tid', 'name'));
    $result = $itg_query->execute()->fetchAll();    
  }
  elseif (arg(1) != 'home_page') {
    /*$query = db_select('taxonomy_term_data', 'itg');
    $query->join('taxonomy_term_hierarchy', 'tth', 'tth.tid = itg.tid');  
    $query->condition('vid', CATEGORY_MANAGMENT, '=');
    $query->condition('parent', 0, '=');
    $query->condition('name', arg(1), '=')
        ->fields('itg', array('tid'));
    $result_tid = $query->execute()->fetchField();*/

    $result = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = arg(1), $max_depth = NULL, $load_entities = FALSE);
  }
  
  foreach ($result as $value) {    
    $name = $value->name.'('.$value->tid.')';
    $data[$name] = $name;
  }  
  
  return drupal_json_output($data);
}