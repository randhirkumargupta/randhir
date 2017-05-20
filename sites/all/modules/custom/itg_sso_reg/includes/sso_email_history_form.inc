<?php
/**
 * Implements hook_form().
 */
function sso_email_history_form($form, &$form_state) {
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
    '#suffix' => l(t('Reset'), 'admin/config/people/sso-email-history', array('attributes' => array('class' => array('reset')))) . '</div">',
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('sso_email_history_form_submit'),
  );
  $sso_email_history_rows = sso_email_history_rows();
  $form['markup'] = array(
    '#markup' => drupal_render($sso_email_history_rows),
  );

  return $form;
}

/**
 * Implements sso_email_history_form_submit().
 */
function sso_email_history_form_submit($form, &$form_state) {

  $uid = $form_state['values']['uid'];
  drupal_goto('admin/config/people/sso-email-history', array(
    'query' => array(
      'uid' => $uid,
    ),
  )
  );
}

/**
 * Function returns list of email history.
 */
function sso_email_history_rows() {
global $base_url;
  $rows = array();
  $parameters = drupal_get_query_parameters();
  $uid = isset($parameters['uid']) ? $parameters['uid'] : '';
  $header = array(
    t('Sn no.'),
    t('Uid'),
    t('Email'),
    t('Domain'),
    t('Date'),
    t('Action'),
  );

  $query = db_select('itg_sso_email_history', 'a');
  $query->fields('a');

  if (isset($uid) && !empty($uid)) {
    $query->condition('a.uid', $uid);
  }
  $query = $query->extend('PagerDefault')->limit(50);
  $query->orderBy('a.uid', 'DESC');

  $result = $query->execute();
  $sn = 0;
  while ($record = $result->fetchObject()) {
    $del_link = "<a href='$base_url/sso-email-history-del/$record->id'>Delete</a>";
    $rows[] = array(
      ++$sn,
      $record->uid,
      check_plain($record->email),
      check_plain($record->domain),
      $record->created,
      $del_link,
    );
  }

  $render_array['sso_email_history'] = array(
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