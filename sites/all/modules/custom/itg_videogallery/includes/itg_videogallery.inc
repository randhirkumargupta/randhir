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
  $form['dailymotion_ftp_url'] = array(
    '#type' => 'textfield',
    '#title' => t('FTP URL'),
    '#default_value' => variable_get('dailymotion_ftp_url', ''),
    '#required' => TRUE,
  );
  
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

/**
 * Impelements form for configuration.
 * {@inheritdoc}
 */
function itg_videogallery_s3_video_form($form) {
  $form['aws_access_key'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Access Key'),
    '#default_value' => variable_get('aws_access_key', ''),
    '#required' => TRUE,
  );
  $form['aws_secret_key'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Secret Key'),
    '#default_value' => variable_get('aws_secret_key', ''),
    '#required' => TRUE,
  );
  $form['aws_region'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Region'),
    '#default_value' => variable_get('aws_region', ''),
    '#required' => TRUE,
  );
   $form['aws_video_dir'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Video Dir'),
    '#default_value' => variable_get('aws_video_dir', ''),
    '#description'=>'Example : s3fs-public/dailymotion_video/',
    '#required' => TRUE,
  );
    $form['aws_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Bucket'),
    '#default_value' => variable_get('aws_bucket', ''),
    '#required' => TRUE,
  );
     $form['aws_video_dm_data'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Video DM Data Folder'),
    '#default_value' => variable_get('aws_video_dm_data', ''),
    '#required' => TRUE,
  );
    
  return system_settings_form($form);
}
