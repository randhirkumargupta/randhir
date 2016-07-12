<?php
/**
 * @file
 * feature_for_home_page_feature_widget.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_for_home_page_feature_widget_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_nodequeues:admin/structure/nodequeue.
  $menu_links['management_nodequeues:admin/structure/nodequeue'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/nodequeue',
    'router_path' => 'admin/structure/nodequeue',
    'link_title' => 'Nodequeues',
    'options' => array(
      'attributes' => array(
        'title' => 'Create and maintain simple nodequeues.',
      ),
      'identifier' => 'management_nodequeues:admin/structure/nodequeue',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_structure:admin/structure',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Nodequeues');

  return $menu_links;
}
