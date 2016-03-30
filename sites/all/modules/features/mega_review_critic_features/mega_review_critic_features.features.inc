<?php
/**
 * @file
 * mega_review_critic_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mega_review_critic_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function mega_review_critic_features_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function mega_review_critic_features_node_info() {
  $items = array(
    'itg_celebrity_profile' => array(
      'name' => t('Celebrity profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'mega_review_critic' => array(
      'name' => t('Mega Review & Critic'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Movie Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
