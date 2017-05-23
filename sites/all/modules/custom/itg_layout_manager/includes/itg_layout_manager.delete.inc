<?php

/*
 * Inc file contains the functions
 */

/**
 * for layout delete for admin
 * @return array $output
 */
function itg_layout_delete() { 
  if (is_numeric(arg(1))) {    
    $query = db_select('itg_layout_tpl', 'tpl');
    $query->fields('tpl', array('id', 'status'));  
    $query->condition('section_name', arg(1));                
    $itg_result = $query->execute()->fetchAll();  
    $rows = array();

    foreach ($itg_result as $row) {
      db_delete('itg_layout_manager')->condition('layout_id', $row->id)->execute();
      db_delete('itg_layout_tpl')->condition('id', $row->id)->execute();      
    }

    drupal_set_message('deleted');
    //drupal_goto('itg-admin-layout-list');
  }
}