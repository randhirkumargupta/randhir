<?php
/**
 * @file
 * Inc file for form releted function of layout manager.
 *
 */

/**
 * Implementation of hook_form for itg_layout_manager_form
 * {@inheritdoc}
 */
function itg_layout_manager_page_setting_form($form, &$form_state) {  

  $arg1 = arg(1);
  
  global $base_url;
  
  $settings['base_url'] = $base_url;
  $settings['layout_type'] = $arg1;
  drupal_add_js(array('itg_story' => array('settings' => $settings)), array('type' => 'setting'));  
  drupal_add_js(drupal_get_path('module', 'itg_layout_manager') . '/js/itg_layout_manager.js', array('weight' => 1));  
  
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  
  if ($arg1 == 'section' || $arg1 == 'special') {
    $op = array("" => "-- Section --");
    foreach ($tax as $key => $val) {
      $op[$val->tid] = $val->name;
    }
  } 
  elseif ($arg1 == 'home') {
      $op = array('home_page' => 'Home Page');
  }
  
  $template = get_template_name($arg1);
    
  $form['section'] = array(
       '#type' => 'select',
       '#title' => t('Select Section'),
       '#options' => $op,
       '#required' => TRUE,
       '#default_value' => isset($_GET['section']) ? $_GET['section'] : "",       
   );
  
  $form['template_name'] = array(
       '#type' => 'select',
       '#title' => t('Select template'),
       '#options' => $template,
       '#required' => TRUE,
       '#default_value' => isset($_GET['template_name']) ? $_GET['template_name'] : "",       
   );
   
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
  );

  return $form;
}

/**
 * Custom submit callback for itg_layout_manager_form_submit.
 * {@inheritdoc}
 */
function itg_layout_manager_page_setting_form_submit($form, &$form_state) { 
  $options = array('query' => array('section' => $form_state['input']['section'], 'template_name' => $form_state['input']['template_name']));
  drupal_goto('itg-layout-manager/' . arg(1), $options);  
}

/**
 * Custom validate callback for itg_layout_manager_form_submit.
 * {@inheritdoc}
 */
function itg_layout_manager_page_setting_form_validate($form, &$form_state) {
  
  $template_id = check_template_of_section($form_state['input']['section'], $form_state['input']['template_name']);
  
  if (!empty($template_id)) {
    form_set_error('edit-section', t('Already tpl select for this section.'));
  }
   
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 */
function itg_layout_manager_filter_form($form, &$form_state) {
  $form = array();
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);  
  
  $op = array("_none" => "-- All --");
  foreach ($tax as $key => $val) {
    $op[$val->tid] = $val->name;
  }  
  
  $form['section'] = array(
       '#type' => 'select',
       '#title' => t('Select Section'),
       '#options' => $op,
       '#required' => TRUE,
       '#default_value' => isset($_GET['section']) ? $_GET['section'] : "",       
  );
  
  $form['items_per_page'] = array(
    '#type' => 'select',
    '#title' => 'Items per page',
    '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60),
    '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
  );
  
  $form['submit'] = array(
    '#value' => 'Apply',
    '#type' => 'submit',
    '#attributes' => array('class' => array('layout-apply')),
    '#prefix' => '<div class = "layout-filter-btn">',
    '#suffix' => '<a class="layout-reset" href="' . base_path() . 'itg-layout-list/'.arg(1).'">Reset</a></div>',
  );
  
  return $form;
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_layout_manager_filter_form_submit($form, &$form_state) {
  $form_state['redirect'] = array(
    'itg-layout-list/'.arg(1).'',
      array(
        'query' => array(
          'section' => $form_state['values']['section'],
          'items_per_page' => $form_state['values']['items_per_page'],
        ),
      ),
  );
}

/**
 * Implementation of hook_form for section cards
 * {@inheritdoc}
 */
function layout_section_widgets_search_form($form, &$form_state) {
  
  if ($_GET['template_name'] != 'page--front' ) {
    $arg = $_GET['section'];
  }
  
  // condition base widget
  if ($_GET["template_name"] == 'page--section_photo') {
    $widgets_type = 'photo_list_of_category';
  }
  else if ($_GET["template_name"] == 'page--section_video') {
    $widgets_type = 'video_list_of_category';
  }
  else {
    $widgets_type = 'section_wise_order';
  }
  
  $form['section_name'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'itg_category_autocomplete_list/'.$arg,
    '#maxlength' => 128,
  );  
  
  $form['section_save'] = array(
    '#markup' => '<a data-tabwidget='.$widgets_type.' class="btn btn-save" href="javascript:void(0)" id="layout-section-save">+</a>',
    '#weight' => 20,
  );  

  return $form;
}

/**
 * Implementation of hook_form for section_widgets
 * {@inheritdoc}
 */
function layout_section_widget2_search_form($form, &$form_state) {
  
  if ($_GET['template_name'] != 'page--front' ) {
    $arg = $_GET['section'];
  }
  
  
  $widgets_type = 'section_widget2_wise_order';
  
  $form['section_widget2_name'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'itg_category_autocomplete_list/'.$arg,
    '#maxlength' => 128,
  );  
  
  $form['section_widget2_save'] = array(
    '#markup' => '<a data-section-widget2='.$widgets_type.' class="btn btn-save" href="javascript:void(0)" id="layout-section_widget2-save">+</a>',
    '#weight' => 20,
  );  

  return $form;
}