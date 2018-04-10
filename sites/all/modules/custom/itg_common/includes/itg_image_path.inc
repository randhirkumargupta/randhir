<?php

/*
 * Inc file contains the update image form
 */


/**
 * Impelements form for update image path.
 * {@inheritdoc}
 */
function itg_image_path_update($form) {
  $arg = arg(1);
  $fid = ($arg) ? $arg : '';
  $file = file_load($fid);

  $form['itg_previous_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Previous path'),
    '#value' => ($file->uri) ? $file->uri : '',
    '#required' => TRUE,
  );
  $form['itg_updated_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Updated path'),
    '#default_value' => '',
    '#required' => TRUE,
  );
  
  $form['itg_previous_file_count'] = array(
    '#type' => 'textarea',
    '#title' => t('File count'),
    '#default_value' => ($file->uri) ? strlen($file->uri) : '',
    '#required' => TRUE,
  );
  
  $form['itg_fid'] = array(
    '#type' => 'hidden',
    '#value' => ($file->fid) ? $file->fid : '',
    '#required' => TRUE,
  );
  
  $form['itg_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}


/**
 * form submit.
 * {@inheritdoc}
 */
function itg_image_path_update_submit($form, &$form_state) {
  $itg_previous_path = $form_state['values']['itg_previous_path'];
  $itg_updated_path = $form_state['values']['itg_updated_path'];
  $fid = $form_state['values']['itg_fid'];
  $file_name = end(explode('/', $itg_updated_path));
  $file_uri = file_create_url($itg_updated_path);

  $insert_count = db_select('file_managed', 'sr')
    ->fields('sr')
    ->condition('sr.uri', $itg_updated_path)
    ->execute()
    ->rowCount();
  if (!$insert_count) {
  /*  $inserted_data = db_delete('s3fs_file')->condition('uri', $file_uri, '=')
      ->execute(); */

    $inserted_data = db_update('file_managed')->fields(array(
        'filename' => $file_name,
        'uri' => $itg_updated_path))->condition('fid', $fid, '=')
      ->execute();

    db_update('itg_all_orignal_image')
      ->fields(array(
        'url' => $file_uri,
      ))
      ->condition('fid', $fid, '=')
      ->execute();
    drupal_set_message(t('The form has been updated'));
  }
  else {
    drupal_set_message('Exist!, Please use another file url ' . $itg_updated_path);
  }
}
