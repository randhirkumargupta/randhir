<?php

/**
 * @file
 * Provide views data for linkit_picker_solr.module.
 */


/**
 * Implements hook_views_data().
 */
function linkit_picker_solr_views_data() {

  // Apachesolr document field
  $data['linkit_picker_solr']['table']['group'] = t('Linkit Picker');
  foreach (apachesolr_load_all_environments() as $env_id => $environment) {
    $apachesolr_base_table = 'apachesolr__' . $env_id;
    $data['linkit_picker_solr']['table']['join'][$apachesolr_base_table] = array();
  }

  $data['linkit_picker_solr']['linkit_picker'] = array(
    'group' => t('Linkit Picker'),
    'field' => array(
      'title' => t('Linkit Picker'),
      'help' => t('Provides info to Linkit Picker (Solr document)'),
      'handler' => 'linkit_picker_handler_field_solr_info',
    ),
  );

  return $data;
}