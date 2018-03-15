<?php
/**
 * Implements hook_form().
 */
function global_point_report_history_form($form, &$form_state) {
  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Search Content'),
  );

  $form['fieldset']['uid'] = array(
    '#type' => 'textfield',
    '#title' => t('Uid'),
    '#description' => t('Please enter uid'),
    '#default_value' => isset($_GET['uid']) ? $_GET['uid'] : '',
    '#element_validate' => array('element_validate_integer_positive'),
  );

  $form['fieldset']['display_button'] = array(
    '#prefix' => '<div class="submit">',
    '#suffix' => l(t('Reset'), 'admin/config/people/global-point-report-history', array('attributes' => array('class' => array('reset')))) . '| '.l(t('Delete Point, Redem point, order table history'), 'del-point-history-data', array('attributes' => array('class' => array('reset')))). '</div">',
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('global_point_report_history_form_submit'),
  );
  
  $global_point_report_history_rows = global_point_report_history_rows();
  
  $form['markup'] = array(
    '#markup' => drupal_render($global_point_report_history_rows),
  );

  return $form;
}

/**
 * Implements global_point_report_history_form_submit().
 */
function global_point_report_history_form_submit($form, &$form_state) {
  $uid = $form_state['values']['uid'];
  
  drupal_goto('admin/config/people/global-point-report-history', array(
    'query' => array(
      'uid' => $uid,
    ),
  )
  );
}

/**
 * Function returns list of point history.
 */
function global_point_report_history_rows() {
global $base_url;
  $rows = array();
  $parameters = drupal_get_query_parameters();
  $uid = isset($parameters['uid']) ? $parameters['uid'] : '';
  $header = array(
    t('Sn no.'),
    t('Uid'),
    t('Type'),
    t('Loyalty points'),
    t('Remaining points'),
    t('Property'),
    t('Status'),
    t('Created date'),
    t('Expiry date'),
  );

  $query = db_select('itg_global_loyality_point', 'a');
  $query->fields('a');
  $query->orderBY('id', 'DESC');

  if (isset($uid) && !empty($uid)) {
    $query->condition('a.uid', $uid);
  }
  $query = $query->extend('PagerDefault')->limit(50);
  $query->orderBy('a.uid', 'DESC');

  $result = $query->execute();
  $sn = 0;
  while ($record = $result->fetchObject()) {
    $rows[] = array(
      ++$sn,
      $record->sso_id,
      check_plain($record->loyalty_type),
      check_plain($record->loyalty_points),
      check_plain($record->remaining_points),
      check_plain($record->property),
      check_plain($record->status),
      date('Y-m-d', $record->created),
      date('Y-m-d h:i:s', $record->expiry_date),
    );
  }

  $render_array['global_point_report_history'] = array(
    array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
      '#empty' => t('No Record found!'),
    ),
    array(
      '#theme' => 'pager',
    ),
  );

  return $render_array;
}