<?php
/**
 * Implements hook_form().
 */
function refer_friend_history_form($form, &$form_state) {
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
    '#suffix' => l(t('Reset'), 'admin/config/people/refer-friend-history', array('attributes' => array('class' => array('reset')))) . '</div">',
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('refer_friend_history_form_submit'),
  );
  
  $refer_friend_history_rows = refer_friend_history_rows();
  
  $form['markup'] = array(
    '#markup' => drupal_render($refer_friend_history_rows),
  );

  return $form;
}

/**
 * Implements sso_email_history_form_submit().
 */
function refer_friend_history_form_submit($form, &$form_state) {
  $uid = $form_state['values']['uid'];
  
  drupal_goto('admin/config/people/refer-friend-history', array(
    'query' => array(
      'uid' => $uid,
    ),
  )
  );
}

/**
 * Function returns list of email history.
 */
function refer_friend_history_rows() {
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

  $query = db_select('itg_lrp_refer_friend', 'a');
  $query->fields('a');

  if (isset($uid) && !empty($uid)) {
    $query->condition('a.uid', $uid);
  }
  $query = $query->extend('PagerDefault')->limit(50);
  $query->orderBy('a.uid', 'DESC');

  $result = $query->execute();
  $sn = 0;
  while ($record = $result->fetchObject()) {
    $del_link = "<a href='$base_url/sso-refer-history-del/$record->id'>Delete</a>";
    $rows[] = array(
      ++$sn,
      $record->uid,
      check_plain($record->mail),
      check_plain($record->friend_name),
      date('Y-m-d', $record->created),
      $del_link,
    );
  }

  $render_array['refer_friend_history'] = array(
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