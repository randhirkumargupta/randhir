<?php
/**
 * @file
 * feature_for_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_for_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-admin-left-menu.
  $menus['menu-admin-left-menu'] = array(
    'menu_name' => 'menu-admin-left-menu',
    'title' => 'ITG Admin Menu',
    'description' => 'Admin menu for Management.',
  );
  // Exported menu: menu-ask-an-expert-menu.
  $menus['menu-ask-an-expert-menu'] = array(
    'menu_name' => 'menu-ask-an-expert-menu',
    'title' => 'Ask an expert menu',
    'description' => 'Ask an expert menu',
  );
  // Exported menu: menu-blog-admin-menu.
  $menus['menu-blog-admin-menu'] = array(
    'menu_name' => 'menu-blog-admin-menu',
    'title' => 'Blog admin menu',
    'description' => '',
  );
  // Exported menu: menu-mega-review-menu.
  $menus['menu-mega-review-menu'] = array(
    'menu_name' => 'menu-mega-review-menu',
    'title' => 'Mega review menu',
    'description' => '',
  );
  // Exported menu: menu-photogallery-admin-menu.
  $menus['menu-photogallery-admin-menu'] = array(
    'menu_name' => 'menu-photogallery-admin-menu',
    'title' => 'Photogallery admin menu',
    'description' => '',
  );
  // Exported menu: menu-story-content-admin-menu.
  $menus['menu-story-content-admin-menu'] = array(
    'menu_name' => 'menu-story-content-admin-menu',
    'title' => 'Story content admin menu',
    'description' => '',
  );
  // Exported menu: menu-task-allocation-menu.
  $menus['menu-task-allocation-menu'] = array(
    'menu_name' => 'menu-task-allocation-menu',
    'title' => 'Task Allocation Menu',
    'description' => '',
  );
  // Exported menu: menu-ugc-comment-menu.
  $menus['menu-ugc-comment-menu'] = array(
    'menu_name' => 'menu-ugc-comment-menu',
    'title' => 'ugc comment menu',
    'description' => 'ugc comment menu',
  );
  // Exported menu: menu-ugc-content-menu.
  $menus['menu-ugc-content-menu'] = array(
    'menu_name' => 'menu-ugc-content-menu',
    'title' => 'ugc content menu',
    'description' => 'ugc content menu',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin menu for Management.');
  t('Ask an expert menu');
  t('Blog admin menu');
  t('ITG Admin Menu');
  t('Main menu');
  t('Mega review menu');
  t('Photogallery admin menu');
  t('Story content admin menu');
  t('Task Allocation Menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');
  t('ugc comment menu');
  t('ugc content menu');

  return $menus;
}
