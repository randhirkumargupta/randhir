<?php
/**
 * @file
 * task_allocation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function task_allocation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_task_idea_allocation_tracking';
  $strongarm->value = '0';
  $export['comment_anonymous_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_task_idea_allocation_tracking';
  $strongarm->value = 1;
  $export['comment_default_mode_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_task_idea_allocation_tracking';
  $strongarm->value = '50';
  $export['comment_default_per_page_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_task_idea_allocation_tracking';
  $strongarm->value = 1;
  $export['comment_form_location_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_task_idea_allocation_tracking';
  $strongarm->value = '0';
  $export['comment_preview_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_task_idea_allocation_tracking';
  $strongarm->value = 0;
  $export['comment_subject_field_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_task_idea_allocation_tracking';
  $strongarm->value = '2';
  $export['comment_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__task_idea_allocation_tracking';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_task_idea_allocation_tracking';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_task_idea_allocation_tracking';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_task_idea_allocation_tracking';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_task_idea_allocation_tracking';
  $strongarm->value = '0';
  $export['node_preview_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_task_idea_allocation_tracking';
  $strongarm->value = 0;
  $export['node_submitted_task_idea_allocation_tracking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_task_idea_allocation_tracking_pattern';
  $strongarm->value = '';
  $export['pathauto_node_task_idea_allocation_tracking_pattern'] = $strongarm;

  return $export;
}
