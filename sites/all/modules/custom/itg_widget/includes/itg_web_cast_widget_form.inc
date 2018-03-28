<?php

/*
 * Inc file Web cast widget functions
 *
 *
 */

/**
 * This function is used to Web cast widget form
 * @return string
 */
function itg_manage_webcast_widget() {
  $form = array();
  $form['itg_webcast_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Webcast status'),
    '#default_value' => get_itg_variable('itg_webcast_status', 0),
  );
  
  $form['itg_webcast_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Widget Title'),
    '#default_value' => get_itg_variable('itg_webcast_title', ''),
    '#required' => TRUE
  );

  $form['itg_webcast_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Widget URL'),
    '#default_value' => get_itg_variable('itg_webcast_url', ''),
  );
  
  $form['itg_content_webcast_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Webcast Title'),
    '#default_value' => get_itg_variable('itg_content_webcast_title', ''),
    '#required' => TRUE
  );

  $form['itg_content_webcast_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Webcast URL'),
    '#default_value' => get_itg_variable('itg_content_webcast_url', ''),
  );

  $form['itg_webcast_iframe'] = array(
    '#type' => 'textarea',
    '#title' => t('Webcast iframe'),
    '#default_value' => get_itg_variable('itg_webcast_iframe', ''),
    '#required' => TRUE
  );
  $form['itg_webcast_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * This function is used to score form submit.
 * {@inheritdoc}
 */
function itg_manage_webcast_widget_submit($form, &$form_state) {
  set_itg_variable('itg_webcast_status', $form_state['values']['itg_webcast_status']);
  set_itg_variable('itg_webcast_title', $form_state['values']['itg_webcast_title']);
  set_itg_variable('itg_webcast_url', $form_state['values']['itg_webcast_url']);
  set_itg_variable('itg_content_webcast_title', $form_state['values']['itg_content_webcast_title']);
  set_itg_variable('itg_content_webcast_url', $form_state['values']['itg_content_webcast_url']);
  set_itg_variable('itg_webcast_iframe', $form_state['values']['itg_webcast_iframe']);
  drupal_set_message(t("WebCast Setting saved!"), 'success');
}
