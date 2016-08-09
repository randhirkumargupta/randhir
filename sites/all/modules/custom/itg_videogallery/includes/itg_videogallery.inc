<?php

/**
 * @file
 * ITG Videogallery inc.
 */

/**
 * Impelements form for configuration.
 * {@inheritdoc}
 */
function itg_videogallery_ftp_video_form($form) {
  $form['dailymotion_ftp_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host Name'),
    '#default_value' => variable_get('dailymotion_ftp_host', ''),
    '#required' => TRUE,
  );
  $form['dailymotion_ftp_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Username'),
    '#default_value' => variable_get('dailymotion_ftp_username'),
    '#required' => TRUE,
  );
  $form['dailymotion_ftp_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Password'),
    '#default_value' => variable_get('dailymotion_ftp_password', ''),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}
