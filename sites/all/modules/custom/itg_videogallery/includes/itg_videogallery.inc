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
  $form['ftp_upload_video_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Folder'),
    '#default_value' => variable_get('ftp_upload_video_folder', ''),
    '#required' => TRUE,
  );
  $form['ftp_move_archive'] = array(
    '#type' => 'textfield',
    '#title' => t('Video Moved In'),
    '#default_value' => variable_get('ftp_move_archive', ''),
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
  $form['ftp_root_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Ftp Root Folder'),
    '#default_value' => variable_get('ftp_root_folder', ''),
    '#required' => TRUE,
  );
  $form['xml_root_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Video XML Folder'),
    '#default_value' => variable_get('xml_root_folder', ''),
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
    '#description' => 'Example : s3fs-public/dailymotion_video/',
    '#required' => TRUE,
  );
  $form['aws_video_dir_to_move'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Old Video Dir'),
    '#default_value' => variable_get('aws_video_dir_to_move', ''),
    '#description' => 'Example : s3fs-public/dailymotion_video/',
    '#required' => TRUE,
  );

  $form['aws_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Bucket'),
    '#default_value' => variable_get('aws_bucket', ''),
    '#required' => TRUE,
  );

  $form['api_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('API S3 Bucket'),
    '#default_value' => variable_get('api_bucket', ''),
  );

  $form['aws_video_dm_data'] = array(
    '#type' => 'textfield',
    '#title' => t('AWS S3 Video DM Data Folder'),
    '#default_value' => variable_get('aws_video_dm_data', ''),
    '#required' => TRUE,
  );
  $form['local_s3_video_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Local Video Folder'),
    '#default_value' => variable_get('local_s3_video_folder', ''),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

/**
 * Impelements form for ITG DFP Tags .
 * {@inheritdoc}
 */
function itg_videogallery_dfp_tags_setting_form($form, &$form_state) {
  $website_options = array(
    'indiatoday' => 'Indiatoday',
    'idaplex' => 'Idaplex',
  );
  $form['wesbite'] = array(
    '#type' => 'select',
    '#title' => t('Website'),
    '#options' => $website_options,
    '#required' => TRUE
  );

  $client_options = array(
    'internal' => 'Internal',
    'ruptly' => 'Ruptly',
  );
  $form['client'] = array(
    '#type' => 'select',
    '#title' => t('Client'),
    '#options' => $client_options,
    '#required' => TRUE,
  );
  $form['dfp_tags'] = array(
    '#type' => 'textarea',
    '#title' => t('Page DFP Tags '),
  );
  $form['dfp_tags_internal'] = array(
    '#type' => 'textarea',
    '#title' => t('Embed DFP Tags Internal'),
  );
  $form['dfp_tags_external'] = array(
    '#type' => 'textarea',
    '#title' => t('Embed DFP Tags External'),
  );
  $form['ga_tag_internal'] = array(
    '#type' => 'textfield',
    '#title' => t('GA Tags Internal'),
  );
  $form['ga_tag_extarnal'] = array(
    '#type' => 'textfield',
    '#title' => t('GA Tags External'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

/**
 * {@inheritdoc}
 * @param type $form
 * @param type $form_state
 */
function itg_videogallery_dfp_tags_setting_form_submit($form, &$form_state) {

  $wesbite = $form_state['values']['wesbite'];
  $client = $form_state['values']['client'];
  $dfp_tags = $form_state['values']['dfp_tags'];
  $dfp_tags_internal = $form_state['values']['dfp_tags_internal'];
  $dfp_tags_external = $form_state['values']['dfp_tags_external'];
  $ga_tag_internal = $form_state['values']['ga_tag_internal'];
  $ga_tag_extarnal = $form_state['values']['ga_tag_extarnal'];
  $result = db_merge('itg_dfp_tags_setting')
      ->key(array('wesbite' => $wesbite, 'client' => $client))
      ->fields(array(
        'wesbite' => $wesbite,
        'client' => $client,
        'dfp_tags' => $dfp_tags,
        'dfp_tags_internal' => $dfp_tags_internal,
        'dfp_tags_external' => $dfp_tags_external,
        'ga_tag_internal' => $ga_tag_internal,
        'ga_tag_extarnal' => $ga_tag_extarnal
      ))
      ->execute();
  drupal_set_message(t('DFP Tags Configuration Saved successfully '));
  drupal_goto('itg-dfp-tags-list');
}

/**
 * Custom form defination for DFP Tags list .
 * @param array $form
 * @param array $form_state
 */
function itg_videogallery_dfp_tags_list() {

  $form['fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => 'DFP Tags List',
  );

  $form['markup'] = array(
    '#markup' => itg_videogallery_dfp_tags_list_data(),
  );

  return $form;
}

/**
 * This method returns the number of rows
 */
function itg_videogallery_dfp_tags_list_data() {
  global $base_url;
  drupal_add_js(drupal_get_path('module', 'itg_videogallery') . '/js/itg_videogallery_dashbord.js', array('weight' => 1, 'scope' => 'footer'));

  $data = array();
  $html = '';
  $rows = array();
  $header = array(
    t('Sn no.'),
    t('Website'),
    t('Client'),
    t('Action'),
  );

  $query = db_select('itg_dfp_tags_setting', 'idts');
  $query->fields('idts');

  $pagelimit = 20;
//print strtr((string) $query, $query->arguments());die;
  $query = $query->extend('PagerDefault')->limit($pagelimit);
  $query->orderBy('idts.id', 'DESC');
  $result = $query->execute();
  $num_of_results = $result->rowCount();
  $sn = 1;
  if (isset($_GET['page']) && !empty($_GET['page'])) {
    $sn = $pagelimit * $_GET['page'] + 1;
  }
  while ($record = $result->fetchObject()) {
    $edit_link = "<a  class='itg-dfp-tags-edit' href='" . $base_url . "/itg-dfp-tags-setting/" . $record->id . "' > Edit </a>";
    $page_no = $_GET['page'];
    $rows[] = array(
      $sn++,
      ucfirst($record->wesbite),
      ucfirst($record->client),
      $edit_link
    );
  }
  $total = count($rows);
  $html .= theme('table', array('header' => $header, 'rows' => $rows));
  //$html .= theme('pager');
  $html .= theme('pager');
  return $html;
}
