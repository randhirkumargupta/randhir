<?php

/**
 * @file
 * Itg_social_media.views.inc file for adding custom table to views.
 */

/**
 * Implements hook_views_data().
 *
 * {@inheritdoc}.
 */
function itg_autosave_views_data() {
  $data['itg_autosave_forms']['table']['group'] = t('Autosave Forms Id');
  $data['itg_autosave_forms']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Autosave Forms Id'),
    'help' => t('Node form ids are saved into database.'),
    'weight' => -10,
  );

  // Plain text field.
  $data['itg_autosave_forms']['form_name'] = array(
    'title' => t('Form Id'),
    'help' => t('Node form id'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // Example timestamp field.
  $data['itg_autosave_forms']['autosave_time'] = array(
    'title' => t('Time interval'),
    'help' => t('Given time interval in which form will update.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['itg_autosave_forms']['id'] = array(
    'title' => t('ID'),
    'help' => t('Form primary key.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
