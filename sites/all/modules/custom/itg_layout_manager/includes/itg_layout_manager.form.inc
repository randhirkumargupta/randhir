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
  
  //$tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  
  if ($arg1 == 'section' || $arg1 == 'special') {
    $op = get_section_of_associate_tpl($arg1);
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
  //$tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);  
  
  
//  foreach ($tax as $key => $val) {
//    $op[$val->tid] = $val->name;
//  } 
  if(!empty(arg(1))) {
    $op = get_all_section_of_tpl(arg(1));
  }
  
  
  $form['section'] = array(
    '#type' => 'select',
    '#title' => t('Select Section'),
    '#options' => $op,
    //'#required' => TRUE,
    '#default_value' => isset($_GET['section']) ? $_GET['section'] : "",       
  );
  
  $form['items_per_page'] = array(
    '#type' => 'select',
    '#title' => 'Items per page',
    '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60),
    '#default_value' => isset($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
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
    $arg = !empty($_GET['section']) ? $_GET['section'] : '';
  }
  
  // condition base widget
  if (!empty($_GET["template_name"]) && $_GET["template_name"] == 'page--section_photo') {
    $widgets_type = 'photo_list_of_category';
  }
  else if (!empty($_GET["template_name"]) && $_GET["template_name"] == 'page--section_video') {
    $widgets_type = 'video_list_of_category';
  }
  else {
    $widgets_type = 'section_wise_order';
  }
  
  if (arg(1) != 'home') {
    $form['all_section'] = array(
      '#type' =>'checkbox',
      '#title' => t('All Categories'),
    );

    $form['section_name_all'] = array(
      '#type' => 'textfield',
      '#size' => 60,
      '#attributes' => array('placeholder' => t('Search')),
      '#autocomplete_path' => 'itg_category_autocomplete_list/all/'.$arg,
      '#maxlength' => 128,
    );
    $custom_url = 'itg_category_autocomplete_list/section/'.$arg;
  } else {
      $custom_url = 'itg_category_autocomplete_list/all/home';
  }
  
  $form['section_name'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => $custom_url,
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

/**
 * Implementation of hook_form for section cards
 * {@inheritdoc}
 */
function highlights_widgets_search_form($form, &$form_state) {  
    
  $form['highlights_title'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'content-title-list/heighlights/autocomplete',
    '#maxlength' => 128,
  );  
  
  $form['highlights_submit'] = array(
    '#markup' => '<div class="go-btn-div"><a class="btn btn-save fright" href="javascript:void(0)" id="layout-highlights-submit">Go</a></div>',
    '#weight' => 20,
  );  

  return $form;
}

/**
 * Implementation of hook_form for html widgets
 * {@inheritdoc}
 */
function html_widgets_search_form($form, &$form_state) {  
    
  $form['html_title'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'content-title-list/custom_html_widgets/autocomplete',
    '#maxlength' => 128,
  );  
  
  $form['html_submit'] = array(
    '#markup' => '<div class="go-btn-div"><a class="fright" href="javascript:void(0)" id="layout-html-submit">Go</a></div>',
    '#weight' => 20,
  );  

  return $form;
}

/**
 * get all selected section of tpl
 * {@inheritdoc}
 */
function get_all_section_of_tpl($type) {
  $data = array("_none" => "-- All --");
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_tpl', array('section_name'));  
  $itg_query->join('taxonomy_term_data', 'ttd', 'ttd.tid = layout_tpl.section_name');
  $itg_query->fields('ttd', array('name'));
  $itg_query->groupBy('layout_tpl.section_name');
  $itg_query->condition('layout_tpl.layout_type', $type);
  $itg_query->condition('layout_tpl.section_name', 'home_page', '!=');
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  $rows = array();
  foreach ($itg_result as $row) {
    $data[$row->section_name] = $row->name;
  }
  return $data;
}


/**
 * Implementation of hook_form for html widgets
 * {@inheritdoc}
 */
function content_widgets_search_form($form, &$form_state) {  
    
  $form['custom_content_title'] = array(
    '#type' => 'textfield',
    '#size' => 60,
    '#attributes' => array('placeholder' => t('Search')),
    '#autocomplete_path' => 'custom-content-widgets/autocomplete',
    '#maxlength' => 128,
  );  
  
  $form['content_widget_submit'] = array(
    '#markup' => '<div class="go-btn-div"><a class="fright" href="javascript:void(0)" id="layout-content-submit">Go</a></div>',
    '#weight' => 20,
  );  

  return $form;
}


/**
 * get all associate section with tpl
 * {@inheritdoc}
 */
function get_section_of_associate_tpl($tpl_type) {
  
  $op = array("" => "-- Section --");
  $itg_query = db_select('taxonomy_term_data', 'term');
  $itg_query->fields('term', array('name', 'tid'));
  $itg_query->fields('sty', array('field_cm_select_template_type_value'));
  $itg_query->join('taxonomy_term_hierarchy', 'tth', 'tth.tid = term.tid');
  $itg_query->join('field_data_field_cm_select_template_type', 'sty', 'sty.entity_id = term.tid');
  $itg_query->condition('tth.parent', 0);
  $itg_query->condition('term.vid', CATEGORY_MANAGMENT);
  $itg_query->condition('sty.field_cm_select_template_type_value', $tpl_type);
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  $rows = array();
  foreach ($itg_result as $row) {
    $op[$row->tid] = $row->name;
  }
  
  return $op;
}