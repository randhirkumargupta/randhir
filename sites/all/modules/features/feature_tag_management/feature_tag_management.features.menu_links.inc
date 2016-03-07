<?php
/**
 * @file
 * feature_tag_management.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function feature_tag_management_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin-left-menu_tag-management:tags-management.
  $menu_links['menu-admin-left-menu_tag-management:tags-management'] = array(
    'menu_name' => 'menu-admin-left-menu',
    'link_path' => 'tags-management',
    'router_path' => 'tags-management',
    'link_title' => 'Tag Management',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-left-menu_tag-management:tags-management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Tag Management');

  return $menu_links;
}
