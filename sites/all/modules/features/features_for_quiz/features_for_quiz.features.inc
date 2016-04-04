<?php
/**
 * @file
 * features_for_quiz.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_for_quiz_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function features_for_quiz_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function features_for_quiz_node_info() {
  $items = array(
    'quiz' => array(
      'name' => t('Quiz'),
      'base' => 'node_content',
      'description' => t('Use <em>Quiz</em> to start new quiz on site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
