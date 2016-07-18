<?php

/*
 * Inc file contains the functions
 */

/**
 * Implements page callback.
 * @return
 */

function itg_layout_admin() {
  
  if (isset($_GET['section']) && isset($_GET['template_name'])) {
   $data = get_layout_details($_GET['section'], $_GET['template_name']); 
  }
  
  return theme('itg_layout_admin_page', array('widget_data' => $data));  
}

/**
 * Implements page callback.
 * @return
 */
function insert_layout_setting_ajax() {
  global $user;  
  $arg = arg();  
  //watchdog("test shravan", '<pre>'. print_r($_GET, TRUE) .'</pre>');
      
  // Get tpl id by section_name and template_name
  $tpl_id = get_template_id($_GET['section_name'], $_GET['template_name']);

  // get layout id by tpl id and block name    
  $layout_id = get_layout_manager_id($tpl_id, $_GET['block_name']);

  // code for layout setting
  if ($arg[1] == 'layout') {
    // insert layout tpl details
    if (empty($tpl_id)) {        
      $query_layout_tpl = db_insert('itg_layout_tpl');
      $query_layout_tpl->fields(array(
        'section_name' => $_GET['section_name'],
        'template_name' => $_GET['template_name'],
        'created_by' => $user->uid,
        'created_date' => time(),
        'status' => 0
      ));
      $tpl_id = $query_layout_tpl->execute();       
    }

    // Insert and update layout widget setting details
    if (empty($layout_id)) {
      $query_layout_manager = db_insert('itg_layout_manager');
      $query_layout_manager->fields(array(
        'layout_id' => $tpl_id,        
        'widget_name' => $_GET['widget_name'],
        'block_name' => $_GET['block_name'],                 
        'status' => true
      ));
      $query_layout_manager->execute();
    } 
    else {
      db_update('itg_layout_manager')
            ->fields(array('widget_name' => $_GET['widget_name']))
            ->condition('id', $layout_id)->execute();
    }
    
    // Set widget in block
    $output = get_itg_widget($_GET['widget_name']);
    
    print $output;
  }
  elseif ($arg[1] == 'publish') {
    db_update('itg_layout_tpl')
           ->fields(array('status' => $_GET['status_val']))
           ->condition('id', $tpl_id)->execute();
    exit;
  }
  elseif ($arg[1] == 'title') {
    db_update('itg_layout_manager')
            ->fields(array('block_title' => $_GET['block_title']))
            ->condition('id', $layout_id)->execute();
    exit;
    // watchdog("test shravan", '<pre>'. print_r($_GET, TRUE) .'</pre>');
  }
  
}