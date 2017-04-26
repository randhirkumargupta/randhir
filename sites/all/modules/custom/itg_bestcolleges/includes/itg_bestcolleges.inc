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
  $path_request = request_path();
  $path_request_array = explode('/', $path_request);
  $year = $path_request_array[1];
  $settings['base_url'] = $base_url;
  $settings['year'] = $year;
  drupal_add_js(array('itg_bestcolleges' => array('settings' => $settings)), array('type' => 'setting'));
  drupal_add_js(drupal_get_path('module', 'itg_bestcolleges') . '/js/itg_bestcolleges.js', array('weight' => 1));
  $search_option = bestcollege_set_option_val($_GET['q']);
  $getstream = itg_bestcollege_getStreamYear('emerging', $year);
  $getsyears = itg_bestcollege_getStreamYear('year-comparecollege', NULL);
  $directory_stream = itg_bestcollege_getStreamYear('readyrecnor-directory-list', $year);
  $form = array();
  $block = block_load('itg_ads', ADS_RHS1);
  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));

   $form['bestcolleg_adds_rhs'] = array(
    '#markup' => '<div class = "bestcolleg_adds_rhs">' . render($render_array) . '</div>',
    '#weight' => -7,
  );
  $form['bestcollege_year_item'] = array(
     '#type' => 'item',
     '#title' => t('BEST COLLEGES YEAR'),
     '#weight' => -6,
     '#prefix' => '<div class = "right_view">',
     '#suffix' => '</div>',
   );

  $form['bestcollege_year_select'] = array(
    '#type' => 'select',
    '#weight' => -5,
    '#options' => $getsyears['year'],
    '#default_value' => $year,
    '#attributes' => array('class' => array('bestcollege_year_wise')),
    '#prefix' => '<div class = "right_side"><div class = "detail_box">',
    '#suffix' => '</div>',
  );

  if (count($getstream) > 0) {
    $form['emerging_rhs'] = array(
      '#type' => 'item',
      '#title' => t('EMERGING BEST COLLEGES'),
      '#weight' => 0,
      '#prefix' => '<div class = "right_view">',
      '#suffix' => '</div>',
    );
    $form['emerging_select'] = array(
      '#type' => 'select',
      '#title' => t(''),
      '#weight' => 1,
      '#options' => $getstream,
      '#default_value' => $search_option['emerging_stream'],
      '#attributes' => array('class' => array('city_wise')),
      '#prefix' => '<div class = "detail_box">',
      '#suffix' => '</div>',
    );
  }
  $form['yearcompare_rhs'] = array(
    '#type' => 'item',
    '#title' => t('YEAR-WISE COMPARISON'),
    '#weight' => 2,
    '#prefix' => '<div class = "right_view">',
    '#suffix' => '</div>',
  );
  $form['yearcompare_yr'] = array(
      '#type' => 'item',
      '#title' => t('YEAR'),
      '#weight' => 2.5,
      '#prefix' => '<div class = "detail_box"><div class = "col-md-2 col-sm-2 col-xs-2 remove_padd_left">',
      '#suffix' => '</div>',
    );
  $form['yearcompare_yr1'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 3,
    '#options' => $getsyears['year'],
    '#default_value' => $search_option['year_fy'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class = "col-sm-4 col-xs-4 remove_padd_left">',
    '#suffix' => '</div>',
  );
  $form['yearcompare_vs'] = array(
      '#type' => 'item',
      '#title' => t('Vs'),
      '#weight' => 3.5,
      '#prefix' => '<div class = "col-md-2 col-sm-1 col-xs-2 control-label remove_padd_left">',
      '#suffix' => '</div>',
    );

  // get first array element
  $year_com = $getsyears['year'];
  $second_year_key = array_slice($year_com, 1, 1);
  // unset year value
  unset($year_com[$second_year_key[0]]);
  $form['yearcompare_yr2'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 4,
    '#options' => $year_com,
    '#default_value' => $search_option['year_sy'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class = "col-sm-4 col-xs-4 remove_padd_left remove_padd_right">',
    '#suffix' => '</div>',
  );
  $form['yearcompare_streamlabel'] = array(
      '#type' => 'item',
      '#title' => t('For Stream'),
      '#weight' => 4.5,
      '#prefix' => '<div class ="stream"><div class ="col-lg-4 col-md-12 col-sm-12 control-label remove_padd_left">',
      '#suffix' => '</div>',
    );
  $form['yearcompare_stream'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 5,
    '#options' => $getsyears['stream'],
    '#default_value' => $search_option['year_stream'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class ="col-lg-8 col-sm-12 col-md-12 remove_padd_left remove_padd_right">',
    '#suffix' => '</div></div><p><small>*Not available for new streams</small></p><div class="clearfix"></div></div>',
  );
  $form['streamcompare_rhs'] = array(
    '#type' => 'item',
    '#title' => t('STREAM-WISE COMPARISON'),
    '#weight' => 6,
    '#prefix' => '<div class = "right_view">',
    '#suffix' => '</div>',
  );
  $form['yearcompare_st'] = array(
      '#type' => 'item',
      '#title' => t('STREAM'),
      '#weight' => 6.5,
      '#prefix' => '<div class = "detail_box"><div class = "col-md-3 col-sm-3 col-xs-3 remove_padd_left">',
      '#suffix' => '</div>',
  );
  $form['streamcompare_rhs_stream1'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 7,
    '#options' => $getsyears['stream'],
    '#default_value' => $search_option['stream_fstream'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class = "col-sm-4 col-xs-4 remove_padd_left">',
    '#suffix' => '</div>',
  );
  $form['streamcompare_rhs_vs'] = array(
      '#type' => 'item',
      '#title' => t('Vs'),
      '#weight' => 7.5,
      '#prefix' => '<div class = "col-md-1 col-sm-1 col-xs-1 control-label remove_padd_left">',
      '#suffix' => '</div>',
  );

  // get first array element
  $stream_com = $getsyears['stream'];
  $second_stream_key = key(array_slice($stream_com, 1, 1));
  // unset year value
  unset($stream_com[$second_stream_key]);

  $form['streamcompare_rhs_stream2'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 8,
    '#options' => $stream_com,
    '#default_value' => $search_option['stream_sstream'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class = "col-sm-4 col-xs-4 remove_padd_left remove_padd_right">',
    '#suffix' => '</div>',
  );
  $form['streamcompare_rhs_label'] = array(
    '#type' => 'item',
      '#title' => t('For Year'),
      '#weight' => 8.5,
      '#prefix' => '<div class = "stream"><div class = "col-lg-4 col-md-12 col-sm-12 control-label remove_padd_left">',
      '#suffix' => '</div>',
  );
  $form['streamcompare_rhs_yr'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 9,
    '#options' => $getsyears['year'],
    '#default_value' => $search_option['stream_year'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class ="col-lg-8 col-sm-12 col-md-12 remove_padd_left remove_padd_right">',
    '#suffix' => '</div></div><p><small>*Not available for new streams</small></p><div class="clearfix"></div></div>',
  );
  if (count($directory_stream) > 0) {
    $form['clgdir_rhs'] = array(
      '#type' => 'item',
      '#title' => t('DIRECTORY OF BEST COLLEGES'),
      '#weight' => 12,
      '#prefix' => '<div class = "right_view">',
      '#suffix' => '</div>',
    );
    $form['clgdir_stream'] = array(
      '#type' => 'select',
      '#title' => t(''),
      '#weight' => 13,
      '#options' => $directory_stream,
      '#default_value' => $search_option['directory_stream'],
      '#attributes' => array('class' => array('city_wise')),
      '#prefix' => '<div class = "detail_box">',
      '#suffix' => '</div>',
    );
  }
  $form['clgzone_rhs'] = array(
    '#type' => 'item',
    '#title' => t('ZONEWISE BEST COLLEGES'),
    '#weight' => 14,
    '#prefix' => '<div class = "right_view">',
    '#suffix' => '</div>',
  );

  $clgzone_option = array('_none' => t('---Select Course---'), 'engineering' => t('ENGINEERING'), 'medical' => t('MEDICAL'), 'law' => t('LAW'));
  $form['clgzone_select'] = array(
    '#type' => 'select',
    '#title' => t(''),
    '#weight' => 15,
    '#options' => $clgzone_option,
    '#default_value' => $search_option['zonewise_stream'],
    '#attributes' => array('class' => array('city_wise')),
    '#prefix' => '<div class = "detail_box">',
    '#suffix' => '</div>',
  );
  return $form;
}


