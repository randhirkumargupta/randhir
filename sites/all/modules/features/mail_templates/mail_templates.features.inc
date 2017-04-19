<?php
/**
 * @file
 * mail_templates.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mail_templates_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function mail_templates_node_info() {
  $items = array(
    'mail_templates' => array(
      'name' => t('Mail Templates'),
      'base' => 'node_content',
      'description' => t('This content type holds the mail subject and body for each and every events in system'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
