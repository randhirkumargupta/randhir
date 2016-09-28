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
  if (arg(2) == 'preview') {
    $data['preview'] = 'yes';
  }
  drupal_add_js('jQuery(document).ready(function(){ jQuery("#views-exposed-form-video-list-of-category-block-1 , #views-exposed-form-photo-list-of-category-block").hide(); });', array('scope' => 'footer', 'type' => 'inline'));
  drupal_add_css(drupal_get_path('theme', FRONT_THEME_NAME) . '/css/layout-manager.css');
  
  return theme('itg_layout_admin_page', array('widget_data' => $data));  
}


/**
 * Get itg layout list
 * @return array $output
 */
function itg_layout_list() {
  // configure the table header columns
  $header = array(
    array('data' => t('ID')),
    array('data' => t('Section name')),
    array('data' => t('Template name')),
    array('data' => t('Template type')),
    array('data' => t('Created Date')),
    array('data' => t('Action')),
  );
  
  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_tpl', array('id','section_name', 'template_name', 'layout_type', 'status', 'created_date'));  
  $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
  $itg_query->fields('ttd', array('name'));
  $itg_query->groupBy('layout_tpl.section_name');
  $itg_query->extend('PagerDefault')->limit($items_per_page);
  $itg_query->condition('layout_tpl.layout_type', arg(1));
  if (!empty($_GET['section'])) {
    $itg_query->condition('layout_tpl.section_name', $_GET['section']);
  }
//  else {
//    $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
//  } 
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  $rows = array();
  
  $count = 0;
  
  foreach ($itg_result as $row) {
    $rows[] = array(
      array('data' => $count+1),
      array('data' => $row->name),
      array('data' => $row->template_name),
      array('data' => $row->layout_type),
      array('data' => date('d/m/Y', $row->created_date)),
      array('data' => l(t('Edit'), 'itg-layout-manager/'.  arg(1), array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
    );
    $count++;
  }
  
  $output = render(drupal_get_form('itg_layout_manager_filter_form'));
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/'.  arg(1)).'</div></div>';  
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  // add the pager
  $output .= theme('pager');

  return $output;
 
}


/**
 * Get itg layout list for admin
 * @return array $output
 */
function itg_layout_list_delete() {
  // configure the table header columns
  $header = array(
    array('data' => t('ID')),
    array('data' => t('Section name')),
    array('data' => t('Template name')),
    array('data' => t('Delete')),
    array('data' => t('Edit')),
  );
  
  if ($_GET['items_per_page']) {
    $items_per_page = $_GET['items_per_page'];
  }
  else {
    $items_per_page = 10;
  }
  if (arg(1) == 'home') {
    $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
    $itg_query->fields('layout_tpl', array('id','section_name', 'template_name', 'status', 'created_date'));  
    
    $itg_query->condition('layout_tpl.section_name', 'home_page', '=');
    
    $itg_query->extend('PagerDefault')->limit($items_per_page);
  }
  else {
    $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
    $itg_query->fields('layout_tpl', array('id','section_name', 'template_name', 'status', 'created_date'));  
    $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
    $itg_query->fields('ttd', array('name'));
    $itg_query->groupBy('layout_tpl.section_name');
    $itg_query->extend('PagerDefault')->limit($items_per_page);
  }
  
  /*if (!empty($_GET['section'])) {
    $itg_query->condition('layout_tpl.section_name', $_GET['section']);
  }
  else {
    $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
  } */
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  $rows = array();
  
  $count = 0;
  
  foreach ($itg_result as $row) {
    $rows[] = array(
      array('data' => $count+1),
      array('data' => $row->name),
      array('data' => $row->template_name),
      array('data' => l(t('delete'), 'itg-delete-layout/'.$row->id)),
      array('data' => l(t('Edit'), 'itg-layout-manager/section', array('query' => array('section' => $row->section_name, 'template_name' => $row->template_name)))),
    );
    $count++;
  }
  
  $output = render(drupal_get_form('itg_layout_manager_filter_form'));
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/section').'</div></div>';  
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  // add the pager
  $output .= theme('pager');

  return $output;
 
}

/**
 * for layout delete for admin
 * @return array $output
 */
function itg_layout_delete() {
  db_delete('itg_layout_manager')->condition('layout_id', arg(1))->execute();
  db_delete('itg_layout_tpl')->condition('id', arg(1))->execute();
  drupal_goto('itg-admin-layout-list');
}

/**
 * for layout delete for admin
 * @return array $output
 */
function itg_section_widgets_list_delete() {
  $result = db_truncate('itg_section_widgets_list')->execute();
  echo 'truncate';exit;
}
 
/**
 * for layout delete for admin
 * @return array $output
 */
function itg_update_table() {
  $check2 = db_field_exists('itg_section_widgets_list', 'widget_type');
  $check = db_field_exists('itg_layout_tpl', 'layout_type');
  $check1 = db_field_exists('itg_layout_manager', 'widget_info');
  
  if(empty($check)) {
      db_query("ALTER TABLE `itg_layout_tpl` ADD `layout_type` TEXT NOT NULL AFTER `template_name`")->execute();
  }
  if(empty($check1)) {
   db_query("ALTER TABLE `itg_layout_manager` ADD `widget_info` TEXT NULL AFTER `block_title`")->execute();   
  }
   if(empty($check2)) {
   db_query("ALTER TABLE `itg_section_widgets_list` ADD `widget_type` TEXT NULL AFTER `category_id`")->execute();   
  }
  
  db_query("UPDATE `itg_layout_tpl` SET `layout_type` = 'home' WHERE template_name = 'page--front'")->execute();
  db_query("UPDATE `itg_layout_tpl` SET `layout_type` = 'section' WHERE template_name = 'page--section_photo'")->execute();
  db_query("UPDATE `itg_layout_tpl` SET `layout_type` = 'section' WHERE template_name = 'page--section_default'")->execute();
  db_query("UPDATE `itg_layout_tpl` SET `layout_type` = 'section' WHERE template_name = 'page--section_video'")->execute();
  
  echo '@@@@';exit;
}
 
