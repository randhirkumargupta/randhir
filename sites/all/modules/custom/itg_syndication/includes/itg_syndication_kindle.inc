<?php

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form($form, &$form_state) {

  $options_first = magazine_options();
  $selected = isset($form_state['values']['magazine']) ? $form_state['values']['magazine'] : key($options_first);
  if (isset($_GET['magazine'])) {
    $selected = $_GET['magazine'];
  }

  $form['magazine'] = array(
    '#type' => 'select',
    '#title' => 'Magazine',
    '#options' => $options_first,
    '#default_value' => $selected,
    '#ajax' => array(
      'callback' => '_get_issues_callback',
      'wrapper' => 'dropdown-second-replace',
    ),
  );

  $issue_default = isset($form_state['values']['issues']) ? $form_state['values']['issues'] : '';
  if (isset($_GET['issue'])) {
    $issue_default = $_GET['issue'];
  }

  $form['issues'] = array(
    '#type' => 'select',
    '#title' => t('Issues'),
    '#prefix' => '<div id="dropdown-second-replace">',
    '#suffix' => '</div>',
    '#required' => TRUE,
    '#options' => _ajax_issue_options($selected),
    '#default_value' => $issue_default,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['reset'] = array(
    '#type' => 'markup',
    '#markup' => l('cancle', 'itg-kindle-feed', array("attributes" => array("class" => array("button"))))
  );
  return $form;
}

/**
 * Function is used to get option for magazine
 * 
 * @return array
 */
function magazine_options() {
  return itg_syndication_get_issue_list('magazine');
}

/**
 * {@inheritdocs}
 */
function _get_issues_callback($form, $form_state) {
  return $form['issues'];
}

/**
 * Function is used to get options for issues during ajaz call
 * @param string $key
 * @return array
 */
function _ajax_issue_options($key = '') {
  $options = _issues_options($key);
  if (isset($options[$key])) {
    return $options[$key];
  } else {
    return array();
  }
}

/**
 * Function which is used to get issues
 * 
 * @param string $magazine
 * @return array
 */
function _issues_options($magazine) {
  $issue_list = array();
  $issue_list[$magazine]['_none'] = '- None -';
  $itg_query = db_select('node', 'n');
  $itg_query->fields('n', array('title'));
  $itg_query->fields('sc', array('field_issue_magazine_target_id'));
  $itg_query->join('field_data_field_issue_magazine', 'sc', 'n.nid = sc.entity_id');
  $itg_query->condition('sc.field_issue_magazine_target_id', $magazine);
  $itg_query->condition('n.type', 'issue');
  $itg_query->range(0, 10);
  $itg_result = $itg_query->execute()->fetchAll();
  foreach ($itg_result as $key => $data) {
    $issue_title = explode(" ", $data->title);
    $issue_list[$magazine][$data->title] = $issue_title[0];
  }
  return $issue_list;
}

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form_validate($form, &$form_state) {
  $issue = $form_state['values']['issues'];
  if ($issue == '_none') {
    form_set_error('issue', t("Please select issue"));
  }
  if (isset($_GET['issue']) && empty($_GET['issue'])) {
    form_set_error('issue', t("Please select issue"));
  }

  if (isset($_GET['magazine']) && empty($_GET['magazine'])) {
    form_set_error('magazine', t("Please select magazine"));
  }
}

/**
 * {@inheritdocs}
 */
function kindle_feed_generate_form_submit($form, &$form_state) {
  $issue = $form_state['values']['issues'];
  $magazine = $form_state['values']['magazine'];
  drupal_goto('itg-kindle-feed', array('query' => array("issue" => $issue, "magazine" => $magazine)));
}
