<?php

/**
 * @file
 * Budget Predictor
 */

/**
 * Function returns budget predictor data for cutom tables widgets.
 * @global string $base_url
 * @return string
 */
function itg_budget_predictor_cheaper_dearer_data() {
  $arg = arg();
  global $base_url;
  if ( $arg[0] == 'taxonomy' && isset($arg[2]) ) {
    $section_id = $arg[2];
    $query = db_select('itg_manage_budget' , 'm');
    $query->fields('m' , array('id' , 'budget_title' , 'file_id'));
    $query->condition('m.budget_section' , $section_id);
    $record = $query->range(0 , 1)->execute()->fetchAssoc();
    $budget_title = $record['budget_title'];
    $fid = $record['file_id'];
    $file = file_load($fid);
    $uri = $file->uri;
    $links = $base_url . $_SERVER['REQUEST_URI'];
    $variables = array(
      'path' => $uri ,
      'alt' => $budget_title ,
      'title' => $budget_title ,
      'width' => '100%' ,
      'height' => '100%' ,
      'attributes' => array('class' => 'budget-predictor-img' , 'id' => 'budget-predictor-img') ,
    );
    return $html = l(theme('image' , $variables) , $links , array('query' => array('type' => 'budget-predictor') , 'html' => TRUE , 'attributes' => array('target' => '_blank')));
  }
}
