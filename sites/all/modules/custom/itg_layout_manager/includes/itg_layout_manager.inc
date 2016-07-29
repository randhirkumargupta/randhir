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
  $output .= '<div class="view"><div class="attachment"><span class="count">Count (' . $count . ') </span>';
  $output .= l(t('Add New Template'), 'itg-layout-manager/section').'</div></div>';  
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => 'No results found'));

  # add the pager
  $output .= theme('pager');

  return $output;
 
}