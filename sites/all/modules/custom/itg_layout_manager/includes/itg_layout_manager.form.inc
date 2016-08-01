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
  
  drupal_add_js(array('itg_story' => array('settings' => $settings)), array('type' => 'setting'));
  
  drupal_add_js(drupal_get_path('module', 'itg_layout_manager') . '/js/itg_layout_manager.js', array('weight' => 1));
  
  
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  
  if ($arg1 == 'section') {
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
    '#suffix' => '<a class="layout-reset" href="' . base_path() . 'itg-layout-list">Reset</a></div>',
  );
  
  return $form;
}

/**
 * Implements hook_submit()
 * {@inheritdoc}
 */
function itg_layout_manager_filter_form_submit($form, &$form_state) {
  $form_state['redirect'] = array(
    'itg-layout-list',
      array(
        'query' => array(
          'section' => $form_state['values']['section'],
          'items_per_page' => $form_state['values']['items_per_page'],
        ),
      ),
  );
}

/**
 * Implementation of hook_form
 * {@inheritdoc}
 */
function layout_section_widgets_search_form($form, &$form_state) {

  $form['section_name'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'itg_category_autocomplete_list/'.$_GET['section'],
    '#maxlength' => 128,
  );  
  
  $form['section_save'] = array(
    '#markup' => '<a class="btn btn-save" href="javascript:void(0)" id="layout-section-save">+</a>',
    '#weight' => 20,
  );  
  
  return $form;
}