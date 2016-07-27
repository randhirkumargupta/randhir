<?php
/**
 * @file
 * feature_for_recipe.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_recipe_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_recipe_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function feature_for_recipe_node_info() {
  $items = array(
    'cooking_tips' => array(
      'name' => t('Cooking Tips'),
      'base' => 'node_content',
      'description' => t('Provide cooking tips for recipe.'),
      'has_title' => '1',
      'title_label' => t('Strap headline (Short headline)'),
      'help' => '',
    ),
    'food_news' => array(
      'name' => t('Food News'),
      'base' => 'node_content',
      'description' => t('Provide food news.'),
      'has_title' => '1',
      'title_label' => t('Strap headline (Short headline)'),
      'help' => '',
    ),
    'recipe' => array(
      'name' => t('Recipe'),
      'base' => 'node_content',
      'description' => t('Use recipe for your recipe content.'),
      'has_title' => '1',
      'title_label' => t('Strap headline (Short headline)'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
