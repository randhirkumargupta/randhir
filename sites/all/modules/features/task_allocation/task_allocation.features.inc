<?php
/**
 * @file
 * task_allocation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function task_allocation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function task_allocation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function task_allocation_node_info() {
  $items = array(
    'task_idea_allocation_tracking' => array(
      'name' => t('Task / Idea Allocation & Tracking'),
      'base' => 'node_content',
      'description' => t('used for allocating tasks'),
      'has_title' => '1',
      'title_label' => t('Task Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
