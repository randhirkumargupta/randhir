<?php
/**
 * @file
 * features_for_print_team.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function features_for_print_team_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_pti_idea_status'.
  $field_bases['field_pti_idea_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pti_idea_status',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Approved' => ' Approve',
        'Rejected' => ' Reject',
        'Not Decided' => ' Not Decided (On Hold)',
        'Needs Modification' => ' Needs Modification',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_pti_words_limit'.
  $field_bases['field_pti_words_limit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pti_words_limit',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
