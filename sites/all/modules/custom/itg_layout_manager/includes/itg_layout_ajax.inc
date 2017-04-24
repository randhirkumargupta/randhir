<?php

/*
 * Inc file contains the functions
 */

/**
 * Implements page callback.
 * @return
 */
function insert_layout_setting_ajax() {
  
  global $user;  
  $arg = arg();
  
  //code for If already a section is dragged while configuration and 
  //if same section is being dragged again on default,photo and video page then system should show an ALERT
  
    /*$widget_check = explode('#', $_GET['widget_name']);
    if (!empty($widget_check[0]) 
            && ($widget_check[0] == 'photo_list_of_category' 
                    || $widget_check[0] == 'video_list_of_category' 
                    || $widget_check[0] == 'section_wise_order')) {
      $check_drag_tid = get_use_category_on_tpl($_GET['section_name'], $widget_check[1]);
      if (!empty($check_drag_tid)) {
        echo 'already_configured_section';        
        exit;
      }    
    }*/
    
  // code end
      
  // Get tpl id by section_name and template_name
  $tpl_id_array = get_template_id($_GET['section_name'], $_GET['template_name']);
  
  $publish_tpl_id = $tpl_id_array[1];
  $unpublish_tpl_id = $tpl_id_array[0];  
  
  // code for layout setting
  if ($arg[1] == 'layout' || $arg[1] == 'title' || $arg[1] == 'widget_delete') {
    
    // insert layout tpl details
    if (empty($unpublish_tpl_id)) {        
      $query_layout_tpl = db_insert('itg_layout_tpl');
      $query_layout_tpl->fields(array(
        'section_name' => $_GET['section_name'],
        'template_name' => $_GET['template_name'],
        'layout_type' => $_GET['layout_type'],
        'created_by' => $user->uid,
        'created_date' => time(),
        'status' => 0
      ));
      
      $unpublish_tpl_id = $query_layout_tpl->execute(); 
      
      if (!empty($publish_tpl_id)) {
        // copy  layout_manager  details
        
        $layout_manager_array = get_layout_block_details($publish_tpl_id, $unpublish_tpl_id);
        
        $query_layout_manager = db_insert('itg_layout_manager');
        $query_layout_manager->fields(array('layout_id', 'widget_name', 'block_name', 'block_title', 'widget_info','filter_url', 'status'));
        
        foreach ($layout_manager_array as $record) {
          $query_layout_manager->values($record);
        }
        
        $query_layout_manager->execute();
      }
    }
    
    // get layout id by tpl id and block name    
    $layout_id = get_layout_manager_id($unpublish_tpl_id, $_GET['block_name']);    

    // Insert and update layout widget setting details
    if (empty($layout_id)) {
      // for widget name
      $widget = explode('#', $_GET['widget_name']);
      
     /* if ($widget[0] == 'photo_list_of_category' || $widget[0] == 'video_list_of_category') {
        $query = db_select('taxonomy_term_data', 'ttd');
        $query->fields('ttd', array('name'));  
        $query->condition('tid', $widget[1], '=');
        $cat_name = $query->execute()->fetchField();
        
        $block_title = $cat_name;
      }
      else {        
        $block_title = $_GET['block_title'];
      }*/
      
      $block_title = $_GET['block_title'];
      
      if (!empty($widget[0]) && !empty($_GET['block_name'])) {
        $query_layout_manager = db_insert('itg_layout_manager');
        $query_layout_manager->fields(array(
          'layout_id' => $unpublish_tpl_id,        
          'widget_name' => $widget[0],
          'block_name' => $_GET['block_name'],
          'block_title' => $block_title,
          'widget_info' => $_GET['widget_info'],
          'filter_url' => $widget[1],
          'status' => true
        ));
        $query_layout_manager->execute();
      }
    } 
    else {
      if ($arg[1] == 'title') {
          if($_GET['widget_info']!="") {
            db_update('itg_layout_manager')
                ->fields(array('block_title' => $_GET['block_title'],'widget_info' => $_GET['widget_info']))
                ->condition('id', $layout_id)->execute();
          } else {
               db_update('itg_layout_manager')
                  ->fields(array('block_title' => $_GET['block_title']))
                  ->condition('id', $layout_id)->execute();
          }
      } else if ($arg[1] == 'widget_delete') {        
        db_delete('itg_layout_manager')->condition('id', $layout_id)->execute();
      } else {
          $block_title = $_GET['block_title'];
          $widget = explode('#', $_GET['widget_name']);

          if($_GET['widget_info'] != "") {
            if (!empty($widget[0])) {
              db_update('itg_layout_manager')
                    ->fields(array('widget_name' => $widget[0], 'block_title' => $block_title, 'widget_info' => $_GET['widget_info'],'filter_url' => $widget[1]))              
                    ->condition('id', $layout_id)->execute();
            }
          } else {
            if (!empty($widget[0])) {
                db_update('itg_layout_manager')
                  ->fields(array('widget_name' => $widget[0], 'block_title' => $block_title,'filter_url' => $widget[1]))              
                  ->condition('id', $layout_id)->execute();
            }
          }        
      }
    }
   
    // Set widget in block
   
    if (isset($_GET['widget_name'])) {
      $widget = explode('#', $_GET['widget_name']);
    }
    
    $output = get_itg_widget($widget[0], $_GET['widget_info'], $widget[1]);   
    
    print $output;
  }
  elseif ($arg[1] == 'publish') {
    //delete code    
    if (!empty($unpublish_tpl_id)) {
      db_delete('itg_layout_manager')->condition('layout_id', $publish_tpl_id)->execute();
      db_delete('itg_layout_tpl')->condition('id', $publish_tpl_id)->execute();
    }
    
    //update code
    db_update('itg_layout_tpl')
           ->fields(array('status' => $_GET['status_val']))
           ->condition('id', $unpublish_tpl_id)->execute();
    exit;
  }
  elseif ($arg[1] == 'delete') {
    //delete code    
    if (!empty($unpublish_tpl_id)) {
      db_delete('itg_layout_manager')->condition('layout_id', $unpublish_tpl_id)->execute();
      db_delete('itg_layout_tpl')->condition('id', $unpublish_tpl_id)->execute();
    }
    
    exit;
  }
  // watchdog("test shravan", '<pre>'. print_r($_GET, TRUE) .'</pre>'); 
  
}

/**
 * Get layout tpl id
 * @param string $section_name
 * @param string $template_name 
 * @return int $id
 */
function get_template_id($section_name, $template_name) {  
  $query = db_select('itg_layout_tpl', 'tpl');
  $query->fields('tpl', array('id', 'status'));  
  $query->condition('section_name', $section_name)
        ->condition('template_name', $template_name);        
  $itg_result = $query->execute()->fetchAll();
  
  $rows = array();
  
  foreach ($itg_result as $row) {
    $id[$row->status] = $row->id;
  }
  
  return $id;
}

/**
 * Get layout block details
 * @param int $layout_id
 * @param string $block_name 
 * @return array $data_array
 */
function get_layout_block_details($layout_id, $id) {
  $query = db_select('itg_layout_manager', 'layout');
  $query->fields('layout', array('widget_name', 'block_name', 'block_title', 'widget_info','filter_url', 'status'));  
  $query->condition('layout_id', $layout_id);  
  $itg_result = $query->execute()->fetchAll();
  
  $rows = array();
  
  foreach ($itg_result as $row) {
    $data['layout_id'] = $id;
    $data['widget_name'] = $row->widget_name;
    $data['block_name'] = $row->block_name;
    $data['block_title'] = $row->block_title;
    $data['widget_info'] = $row->widget_info;
    $data['filter_url'] = $row->filter_url;
    $data['status'] = $row->status;
    $data_array[] = $data;
  }  
  
  return $data_array;
}

