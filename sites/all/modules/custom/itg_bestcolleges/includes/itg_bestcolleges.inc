<?php
/**
 * @file
 * This inc file contains functions related to Best colleges features.
 *
 */
 
/**
* Implementation of hook_form for itg_layout_manager_page_setting_form
* @param array $form
* @param array $form_state
* @return array
*/
function bestcollege_rhssearch_form($form, &$form_state) {
  global $base_url;
  $year = arg(1);
  $settings['base_url'] = $base_url;
  $settings['year'] = $year;
  drupal_add_js(array('itg_bestcolleges' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_bestcolleges') . '/js/itg_bestcolleges.js', array('weight' => 1));
  
  
  $getstream = itg_bestcollege_getStreamYear('emerging', $year);
  $getsyears = itg_bestcollege_getStreamYear('year-comparecollege', NULL);
  $directory_stream = itg_bestcollege_getStreamYear('readyrecnor-directory-list', $year);
  $form = array();
  if (count($getstream) > 0) {
    $form['emerging_rhs'] = array(
      '#type' => 'fieldset', 
      '#title' => t('EMERGING BEST COLLEGES'), 
      '#weight' => 0, 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      '#prefix' => '<div class = "emerging_rhsdiv">',
      '#suffix' => '</div>',
    );
    $form['emerging_rhs']['emerging_select'] = array(
      '#type' => 'select',
      '#title' => t(''),
      '#options' => $getstream,
    );
  }
  
  $form['yearcompare_rhs'] = array(
    '#type' => 'fieldset', 
    '#title' => t('YEAR-WISE COMPARISON'), 
    '#weight' => 1, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#prefix' => '<div class = "yearcompare_rhsdiv">',
    '#suffix' => '</div>',
  );
  $form['yearcompare_rhs']['yearcompare_yr1'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['year']
  );
  $form['yearcompare_rhs']['yearcompare_yr2'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['year']
  );
  $form['yearcompare_rhs']['yearcompare_stream'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['stream']
  );
  $form['streamcompare_rhs'] = array(
    '#type' => 'fieldset', 
    '#title' => t('STREAM-WISE COMPARISON'), 
    '#weight' => 2, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#prefix' => '<div class = "streamcompare_rhsdiv">',
    '#suffix' => '</div>',
  );
  $form['streamcompare_rhs']['streamcompare_rhs_stream1'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['stream']
  );  
  $form['streamcompare_rhs']['streamcompare_rhs_stream2'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['stream']
  );
  $form['streamcompare_rhs']['streamcompare_rhs_yr'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => $getsyears['year']
  );
  $form['clgsurvey_rhs'] = array(
    '#type' => 'fieldset', 
    '#title' => t('LAST 19 YEARS BEST COLLEGE SURVEYS'), 
    '#weight' => 3, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#prefix' => '<div class = "clgsurvey_rhsdiv">',
    '#suffix' => '</div>',
  );
  $form['clgsurvey_rhs']['clgsurvey_stream'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes'),
    ),
  );
  if (count($directory_stream) > 0) {
    $form['clgdir_rhs'] = array(
      '#type' => 'fieldset', 
      '#title' => t('DIRECTORY OF BEST COLLEGES'), 
      '#weight' => 4, 
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,
      '#prefix' => '<div class = "clgdir_rhsdiv">',
      '#suffix' => '</div>',
    );
    $form['clgdir_rhs']['clgdir_stream'] = array(
      '#type' => 'select',
      '#title' => t(''),
      '#options' => $directory_stream
    );
  }
  $form['clgzone_rhs'] = array(
    '#type' => 'fieldset', 
    '#title' => t('ZONEWISE BEST COLLEGES'), 
    '#weight' => 5, 
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
    '#prefix' => '<div class = "clgzone_rhsdiv">',
    '#suffix' => '</div>',
  );
  $form['clgzone_rhs']['clgzone_select'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#options' => array(
      'engineering' => t('ENGINEERING'),
      'medical' => t('MEDICAL'),
      'law' => t('LAW'),
    ),
  );
  return $form;
}


