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
    $data = get_layout_details($_GET['section'], $_GET['template_name'], 'admin'); 
  }
  drupal_add_css(drupal_get_path('theme', FRONT_THEME_NAME) . '/css/layout-manager.css');
  return theme('itg_layout_admin_page', array('widget_data' => $data));  
}

/**
 * Implements page callback.
 * @return
 */
function insert_layout_setting_ajax() {
  global $user;  
  $arg = arg();
      
  // Get tpl id by section_name and template_name
  $tpl_id_array = get_template_id($_GET['section_name'], $_GET['template_name']);
  
  $publish_tpl_id = $tpl_id_array[1];
  $unpublish_tpl_id = $tpl_id_array[0];  
  
  // code for layout setting
  if ($arg[1] == 'layout' || $arg[1] == 'title') {
    // insert layout tpl details
    if (empty($unpublish_tpl_id)) {        
      $query_layout_tpl = db_insert('itg_layout_tpl');
      $query_layout_tpl->fields(array(
        'section_name' => $_GET['section_name'],
        'template_name' => $_GET['template_name'],
        'created_by' => $user->uid,
        'created_date' => time(),
        'status' => 0
      ));
      $unpublish_tpl_id = $query_layout_tpl->execute(); 
      
      if (!empty($publish_tpl_id)) {
        // copy  layout_manager  details
        
        $layout_manager_array = get_layout_block_details($publish_tpl_id, $unpublish_tpl_id);
        
        $query_layout_manager = db_insert('itg_layout_manager');
        $query_layout_manager->fields(array('layout_id', 'widget_name', 'block_name', 'block_title', 'filter_url', 'status'));
        
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
      $query_layout_manager = db_insert('itg_layout_manager');
      $query_layout_manager->fields(array(
        'layout_id' => $unpublish_tpl_id,        
        'widget_name' => $_GET['widget_name'],
        'block_name' => $_GET['block_name'],
        'block_title' => $_GET['block_title'],
        'status' => true
      ));
      $query_layout_manager->execute();
    } 
    else {
      if ($arg[1] == 'title') {
        db_update('itg_layout_manager')
            ->fields(array('block_title' => $_GET['block_title']))
            ->condition('id', $layout_id)->execute();
      } else {
        db_update('itg_layout_manager')
              ->fields(array('widget_name' => $_GET['widget_name']))
              ->condition('id', $layout_id)->execute();
      }
    }
    
    // Set widget in block
    $output = get_itg_widget($_GET['widget_name']);
    
    print $output;
  }
  elseif ($arg[1] == 'publish') {
    //delete code
    
    if (!empty($publish_tpl_id)) {
      db_delete('itg_layout_manager')->condition('layout_id', 10)->execute();
      db_delete('itg_layout_tpl')->condition('id', $publish_tpl_id)->execute();
    }
    
    //update code
    db_update('itg_layout_tpl')
           ->fields(array('status' => $_GET['status_val']))
           ->condition('id', $unpublish_tpl_id)->execute();
    exit;
  }
  
    // watchdog("test shravan", '<pre>'. print_r($_GET, TRUE) .'</pre>');
 
  
}

/**
 * Get itg layout list
 * @return array $output
 */
function itg_layout_list() {
  # configure the table header columns
  $header = array(
    array('data' => t('ID'), 'field' => 'layout_tpl.id', 'sort' => 'ASC'),
    array('data' => t('Section name')),
    array('data' => t('Template name')),
    array('data' => t('Created Date'), 'field' => 'layout_tpl.story_modified', 'sort' => 'ASC'),
    array('data' => t('Action')),
  );
  
  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_tpl', array('id','section_name', 'template_name', 'status'));
 // $itg_query->orderByHeader($header)
            $itg_query->extend('PagerDefault')->limit($items_per_page);
  if (!empty($_GET['section'])) {
    $itg_query->condition('layout_tpl.section_name', $_GET['section']);
  }
 // $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  $rows = array();
  $count = 0;
  foreach ($itg_result as $row) {
    $rows[] = array(
      array('data' => $row->id),
      array('data' => $row->section_name),
      array('data' => $row->template_name),
      array('data' => date('d/m/Y', $row->created_date)),
      array('data' => l(t('Edit'), 'itg-layout-manager/section', array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
    );
    $count++;
  }
  
  $output = render(drupal_get_form('itg_layout_manager_filter_form'));
  $output .= '<span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/section');  
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  # add the pager
  $output .= theme('pager');

  return $output;
 
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
  $query->fields('layout', array('widget_name', 'block_name', 'block_title', 'filter_url', 'status'));  
  $query->condition('layout_id', $layout_id);  
  $itg_result = $query->execute()->fetchAll();
  
  $rows = array();
  
  foreach ($itg_result as $row) {
    $data['layout_id'] = $id;
    $data['widget_name'] = $row->widget_name;
    $data['block_name'] = $row->block_name;
    $data['block_title'] = $row->block_title;
    $data['filter_url'] = $row->filter_url;
    $data['status'] = $row->status;
    $data_array[] = $data;
  }
  
  
  return $data_array;
}