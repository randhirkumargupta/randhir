<?php
/**
 * @file
 * features_for_loyalty_and_rewards.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function features_for_loyalty_and_rewards_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_loyalty_and_rewards';
  $strongarm->value = '0';
  $export['comment_anonymous_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_loyalty_and_rewards';
  $strongarm->value = 1;
  $export['comment_default_mode_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_loyalty_and_rewards';
  $strongarm->value = '50';
  $export['comment_default_per_page_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_loyalty_and_rewards';
  $strongarm->value = 1;
  $export['comment_form_location_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_loyalty_and_rewards';
  $strongarm->value = '1';
  $export['comment_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_loyalty_and_rewards';
  $strongarm->value = '1';
  $export['comment_preview_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_loyalty_and_rewards';
  $strongarm->value = 1;
  $export['comment_subject_field_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__loyalty_and_rewards';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'flag' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_loyalty_and_rewards';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_loyalty_and_rewards';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_loyalty_and_rewards';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_loyalty_and_rewards';
  $strongarm->value = '0';
  $export['node_preview_loyalty_and_rewards'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_loyalty_and_rewards';
  $strongarm->value = 0;
  $export['node_submitted_loyalty_and_rewards'] = $strongarm;

  return $export;
}
