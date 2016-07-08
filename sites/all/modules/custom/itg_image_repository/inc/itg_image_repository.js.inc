<?php

/**
 * @file
 * Handles ajax file operations.
 */

/**
 * Ajax operation: navigate
 */
function itg_image_repository_js_navigate(&$itg_image_repository) {
  return array(
    'files' => theme('itg_image_repository_file_list', array('itg_image_repository_ref' => array('itg_image_repository' => &$itg_image_repository))),
    'dirsize' => format_size($itg_image_repository['dirsize']),
    'subdirectories' => array_map('rawurlencode', $itg_image_repository['subdirectories']),
    'perm' => $itg_image_repository['perm']
  );
}

/**
 * Ajax operation: upload
 */
function itg_image_repository_js_upload(&$itg_image_repository) {
  if ($itg_image_repository['perm']['upload']) {
    $_POST['op'] = t('Upload');
    drupal_get_form('itg_image_repository_upload_form', array('itg_image_repository' => &$itg_image_repository));
    return array('added' => isset($itg_image_repository['added']) ? $itg_image_repository['added'] : NULL, 'dirsize' => format_size($itg_image_repository['dirsize']));
  }
}

/**
 * Ajax operation: thumbnails
 */
function itg_image_repository_js_thumb(&$itg_image_repository) {
  if ($itg_image_repository['perm']['thumb']) {
    $_POST['op'] = t('Create thumbnails');
    return itg_image_repository_process_fileop($itg_image_repository);
  }
}

/**
 * Ajax operation: delete
 */
function itg_image_repository_js_delete(&$itg_image_repository) {
  if ($itg_image_repository['perm']['delete']) {
    $_POST['op'] = t('Delete');
    return itg_image_repository_process_fileop($itg_image_repository);
  }
}

/**
 * Ajax operation: resize
 */
function itg_image_repository_js_resize(&$itg_image_repository) {
  if ($itg_image_repository['perm']['resize']) {
    $_POST['op'] = t('Resize');
    return itg_image_repository_process_fileop($itg_image_repository);
  }
}

/**
 * Process file operations form
 */
function itg_image_repository_process_fileop(&$itg_image_repository) {
  drupal_get_form('itg_image_repository_fileop_form', array('itg_image_repository' => &$itg_image_repository));
  return array('added' => isset($itg_image_repository['added']) ? $itg_image_repository['added'] : NULL, 'removed' => isset($itg_image_repository['removed']) ? $itg_image_repository['removed'] : NULL, 'dirsize' => format_size($itg_image_repository['dirsize']));
}