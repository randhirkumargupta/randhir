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
  
  /*if (!empty(arg(1))) {
   $result = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = arg(1), $max_depth = NULL, $load_entities = FALSE);
  }
  else {
    $itg_query = db_select('taxonomy_term_data', 'itg');
    $itg_query->condition('vid', CATEGORY_MANAGMENT, '=');
    $itg_query->condition('name', '%' . $string . '%', 'LIKE')
            ->fields('itg', array('tid', 'name'));
    $result = $itg_query->execute()->fetchAll();
 }*/
 
  $itg_query = db_select('taxonomy_term_data', 'itg');
  $itg_query->condition('vid', CATEGORY_MANAGMENT, '=');
  $itg_query->condition('name', '%' . $string . '%', 'LIKE')
          ->fields('itg', array('tid', 'name'));
  $result = $itg_query->execute()->fetchAll();
    
 if (isset($result)) { 
   foreach ($result as $value) {    
     $name = $value->name.'('.$value->tid.')';
     $data[$name] = $name;
   }  

   return drupal_json_output($data);
 }
}

/**
 * Implements page callback.
 * @return
 */
function section_widgets_ajax() {
  global $user;  
  $arg = arg();
  
  if($arg[1] == 'insert') {
    // insert query
    if ((isset($_GET['section_name']) && ($_GET['section_name'] != '_none')) && (isset($_GET['template_name']) && ($_GET['template_name'] != '_none'))) {
      //widgets_type
      $category_array = explode('(', $_GET['category_name']);
      $cid = substr($category_array[1], 0,-1);
      // category exit or not for this section
      $check_cid = get_section_widgets_id($cid, $_GET['section_name']);
      
      if (empty($check_cid)) {
        $query_layout_tpl = db_insert('itg_section_widgets_list');
            $query_layout_tpl->fields(array(
              'template_section_name' => $_GET['section_name'],
              'template_name' => $_GET['template_name'],
              'category_name' => $category_array[0],
              'category_id' => $cid,
              'widget_type' => $_GET['widgets_type'],
              'created_date' => time()        
            ));

            $unpublish_tpl_id = $query_layout_tpl->execute();
      }
    }
  }
  elseif ($arg[1] == 'delete') {
    db_delete('itg_section_widgets_list')->condition('id', $_GET['id'])->execute();
  }
  
  $content = display_section_widgets_list($_GET['section_name'], $_GET['template_name'], $_GET['widgets_type']); 
  echo $content;
  exit;
  
}