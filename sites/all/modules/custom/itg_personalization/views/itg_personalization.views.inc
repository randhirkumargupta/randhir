<?php
/**
 * @file
 */

/**
 * Implements hook_views_data_alter().
 *
 * @param $data
 *   Information about Views tables and fields.
 */
function itg_personalization_views_data_alter(&$data) {  
  // Add the Title form field to the node-related fields.
  $data['taxonomy_term_data']['tid_edit'] = array(
    'field' => array(
      'title' => t('Range Slider'),
      'help' => t('Set user preferences.'),
      'handler' => 'itg_personalization_field_handler_tid_edit',
    ),
  );
}