<?php
/**
 * @file
 * blocks_features.features.blockexport_settings.inc
 */

/**
 * Implements hook_default_blockexport_settings().
 */
function blocks_features_default_blockexport_settings() {
  $export = array();
  $export['block'][] = array(
  'bid' => 1,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 2,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => -1,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 3,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 10,
  'region' => 'dashboard_main',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 4,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 5,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 6,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 10,
  'region' => 'footer',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 7,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 0,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 8,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 9,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 10,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 10,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 11,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'dashboard_sidebar',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 12,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'seven',
  'status' => 1,
  'weight' => -10,
  'region' => 'dashboard_inactive',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 13,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 14,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 15,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 16,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 17,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 18,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 19,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 20,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 21,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 22,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'dashboard_inactive',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 23,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 24,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 25,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 26,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 27,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 28,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 29,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 30,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'dashboard_inactive',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 31,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => -11,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 32,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 33,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 34,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 35,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'seven',
  'status' => 1,
  'weight' => -99,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 36,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 37,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 38,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 39,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 40,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 41,
  'module' => 'menu',
  'delta' => 'menu-admin-menu',
  'theme' => 'bartik',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 42,
  'module' => 'menu',
  'delta' => 'menu-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 43,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 44,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 45,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 46,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => -12,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 47,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 48,
  'module' => 'menu',
  'delta' => 'menu-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 49,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 50,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 51,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'itg',
  'status' => 0,
  'weight' => -1,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 52,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 53,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 54,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -62,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 55,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 56,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 57,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 58,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 59,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 60,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 61,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 62,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 63,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 64,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 65,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 66,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -63,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 67,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 68,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -24,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 69,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 70,
  'module' => 'menu',
  'delta' => 'menu-admin-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -8,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 71,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 72,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 73,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -1,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 74,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 75,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => 0,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 76,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -10,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 77,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 78,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 79,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -7,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 80,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 81,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 82,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 83,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 84,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 85,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 86,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 87,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 88,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -9,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 89,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 90,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 91,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 92,
  'module' => 'menu',
  'delta' => 'menu-admin-menu',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 93,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 94,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 95,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'tao',
  'status' => 0,
  'weight' => -1,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 96,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 97,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 0,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 98,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 99,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 100,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 101,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 102,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 10,
  'region' => 'footer',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 103,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 104,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'tao',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 105,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 106,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 107,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 108,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 109,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 110,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'tao',
  'status' => 1,
  'weight' => -11,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 111,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 112,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 113,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 114,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 115,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 116,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 117,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 118,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 119,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -12,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 120,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 121,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 122,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 123,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 124,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 125,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 126,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 127,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 128,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 129,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 130,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 131,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 132,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 133,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 134,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 135,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 136,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 137,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 138,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 139,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 140,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 141,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 142,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 143,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 144,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 145,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 146,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 147,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 148,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 149,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 150,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 151,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 152,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 153,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 154,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'zen',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 155,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 156,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'zen',
  'status' => 1,
  'weight' => 5,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 157,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 158,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 159,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 160,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 161,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 162,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 163,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 164,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'zen',
  'status' => 1,
  'weight' => -99,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 165,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 166,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 167,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 168,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => -13,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 169,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -15,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 170,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 171,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 172,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 173,
  'module' => 'menu',
  'delta' => 'menu-menu-admin-left-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 174,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'header',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 175,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 176,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 177,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 178,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 179,
  'module' => 'menu',
  'delta' => 'menu-itg-user-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 180,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 181,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 182,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -29,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 183,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 184,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 185,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 186,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 187,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -28,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 188,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 189,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 190,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 191,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 192,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 193,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 194,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -14,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 195,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 196,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 197,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 198,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 199,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 200,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -13,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 201,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 202,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 203,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 204,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 205,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => -13,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 206,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 207,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 208,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 209,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 210,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/revisions/*/view',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 211,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 212,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 213,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 214,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 215,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 216,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 217,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 218,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 219,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 220,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 221,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 222,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 223,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 224,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*/edit',
  'title' => 'Category Log',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 225,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 226,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 227,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 228,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 229,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 230,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 231,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 232,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 233,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 234,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 235,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 236,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 237,
  'module' => 'menu',
  'delta' => 'devel',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 238,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 239,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 240,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 241,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -27,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 242,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 243,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 244,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 245,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 246,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 247,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 248,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 249,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'seven',
  'status' => 1,
  'weight' => 0,
  'region' => 'dashboard_inactive',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 250,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 251,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 252,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 253,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 254,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -20,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 255,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 256,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 257,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 258,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 259,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 260,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -22,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 261,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 262,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 263,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 264,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -66,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 265,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 266,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 267,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 268,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 269,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -59,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 270,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -60,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 271,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 272,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -9,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 273,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 274,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 275,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 276,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 277,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -8,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 278,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 279,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 280,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 281,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -16,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 282,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 283,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 284,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -11,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 285,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -15,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 286,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 287,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 288,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 289,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 290,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 291,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 292,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 293,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 294,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 295,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 296,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 297,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 298,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 299,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 300,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 301,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 302,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 303,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 304,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/poll
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 305,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 306,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 307,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -18,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 308,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 309,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 310,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 311,
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 312,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 313,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 314,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 315,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 316,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 317,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 318,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 319,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -21,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 320,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 321,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 322,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 323,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 324,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 325,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 326,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 327,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 328,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 329,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 330,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 331,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -26,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 332,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 333,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 334,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 335,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 336,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 337,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 338,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -23,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 339,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 340,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 341,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/quiz
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 342,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 343,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 344,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -12,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 345,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 346,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 347,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 354,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 355,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 356,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -19,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 357,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 358,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 359,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 360,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 361,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -25,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 362,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 363,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 364,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 365,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 366,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 367,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 369,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 370,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -61,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 372,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 373,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 375,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 376,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 378,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 379,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 381,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 382,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 384,
  'module' => 'autologout',
  'delta' => 'info',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 385,
  'module' => 'backup_migrate',
  'delta' => 'quick_backup',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 386,
  'module' => 'blog',
  'delta' => 'recent',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 387,
  'module' => 'comment',
  'delta' => 'recent',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 388,
  'module' => 'devel',
  'delta' => 'execute_php',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 389,
  'module' => 'devel',
  'delta' => 'switch_user',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 390,
  'module' => 'diff',
  'delta' => 'inline',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 391,
  'module' => 'formblock',
  'delta' => 'ask_an_expert',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -32,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/lorem-ipsum-simply-dummy-text',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 392,
  'module' => 'formblock',
  'delta' => 'breaking_news',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 393,
  'module' => 'formblock',
  'delta' => 'user_register',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 394,
  'module' => 'formblock',
  'delta' => 'user_password_request',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 397,
  'module' => 'itg_api',
  'delta' => 'api_form_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'content/api-widgets',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 398,
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -40,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/astro
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 399,
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -39,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/breaking-news
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 400,
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 401,
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -36,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/mega-review-critic
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 403,
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -38,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/photogallery
node/add/photogallery/*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 404,
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -30,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 405,
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -35,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 406,
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -34,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/recipe
node/add/recipe/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 408,
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -41,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/story/*
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 409,
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -33,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/survey
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 410,
  'module' => 'menu',
  'delta' => 'menu-ask-an-expert-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -42,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'ask-an-expert
ask-an-expert-history',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 411,
  'module' => 'menu',
  'delta' => 'menu-blog-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -43,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-blogs
published-blogs
my-unpublished-blogs
mydraft-blogs
my-published-blogs
my-queue-blogs
in-queue-blogs
archive-blogs
my-rejected-blogs',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 412,
  'module' => 'menu',
  'delta' => 'features',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 413,
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'navigation',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 414,
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -44,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'movie-review-list
movie-review-draft-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 415,
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -47,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-photogallery
published-photogallery
my-unpublished-photogallery
mydraft-photogallery
my-published-photogallery
my-queue-photogallery
in-queue-photogallery
archive-photogallery
my-rejected-photogallery',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 416,
  'module' => 'menu',
  'delta' => 'menu-site-setting',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 417,
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -46,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'my-unpublished-story
published-story
unpublished-story
mydraft-story
my-published-story
my-queue-story
in-queue-story
my-expired-story
expired-story
archive-story
my-rejected-story
ugc-published-story',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 418,
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -45,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'created-task-list
assigned-task-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 419,
  'module' => 'node',
  'delta' => 'syndicate',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 420,
  'module' => 'node',
  'delta' => 'recent',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 421,
  'module' => 'search',
  'delta' => 'form',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 422,
  'module' => 'shortcut',
  'delta' => 'shortcuts',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 423,
  'module' => 'superfish',
  'delta' => 1,
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 424,
  'module' => 'superfish',
  'delta' => 2,
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 425,
  'module' => 'superfish',
  'delta' => 3,
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 426,
  'module' => 'superfish',
  'delta' => 4,
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 427,
  'module' => 'system',
  'delta' => 'main',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -27,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 428,
  'module' => 'system',
  'delta' => 'powered-by',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 10,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 429,
  'module' => 'system',
  'delta' => 'help',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 5,
  'region' => 'help',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 430,
  'module' => 'system',
  'delta' => 'navigation',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 431,
  'module' => 'system',
  'delta' => 'management',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 432,
  'module' => 'system',
  'delta' => 'user-menu',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 433,
  'module' => 'system',
  'delta' => 'main-menu',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 434,
  'module' => 'user',
  'delta' => 'login',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 435,
  'module' => 'user',
  'delta' => 'new',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 436,
  'module' => 'user',
  'delta' => 'online',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 437,
  'module' => 'workbench',
  'delta' => 'block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -28,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 438,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -30,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 439,
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 440,
  'module' => 'views',
  'delta' => 'poll_listing-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 441,
  'module' => 'views',
  'delta' => 'poll_listing-block_2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 442,
  'module' => 'views',
  'delta' => 'workbench_edited-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 443,
  'module' => 'views',
  'delta' => 'workbench_current_user-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 444,
  'module' => 'views',
  'delta' => '9cf22433e0efbd8b206c8e4c2edb177c',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 445,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 446,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'rubik',
  'status' => 1,
  'weight' => -17,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 447,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 448,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -27,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 449,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 450,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 451,
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-ugc
reject-ugc-content-list',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 452,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 453,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 454,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 455,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 456,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 457,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 458,
  'module' => 'msnf',
  'delta' => 'msnf_step_data',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 459,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 460,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 461,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 462,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 463,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -31,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 464,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -29,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 465,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 466,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 467,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 468,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 469,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 470,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 471,
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 472,
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/sponsor
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 473,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 474,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 475,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -37,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 476,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 477,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 478,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 479,
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/blog
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 480,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 481,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -28,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 482,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 483,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 484,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 485,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 486,
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'in-queue-ugc-comments
publish-ugc-comments',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 487,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 488,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 489,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 490,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 491,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 492,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 493,
  'module' => 'itg_newsletter',
  'delta' => 'newsletter_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 494,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 495,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 496,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 497,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 498,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 499,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 500,
  'module' => 'itg_social_media',
  'delta' => 'social_media_form',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 501,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 502,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 503,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -31,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 504,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 505,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 506,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 507,
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/story
node/add/breaking-news
node/add/blog
node/add/podcast
node/add/videogallery
node/add/photogallery
node/add/survey
node/*/edit',
  'title' => 'Related Content',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 508,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 509,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 512,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 513,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 514,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 515,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 516,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 517,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 518,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 519,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 520,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 521,
  'module' => 'views',
  'delta' => 'story_widget-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 522,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 523,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 526,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 527,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 528,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 529,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 530,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 531,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 532,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 533,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 534,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 535,
  'module' => 'views',
  'delta' => 'story_widget-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 536,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 537,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 538,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 539,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 540,
  'module' => 'menu',
  'delta' => 'menu-recipe-content-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'manage-poll
draft-manage-poll',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 541,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 542,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 543,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 544,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 545,
  'module' => 'menu',
  'delta' => 'menu-astro-content-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-astro
draft-manage-astro',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 556,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -65,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 557,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 558,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 559,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 560,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 561,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 562,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 563,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 564,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 565,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 566,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 567,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 568,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 569,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 570,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 571,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 572,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 573,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 574,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 575,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 576,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 577,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 578,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 579,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 580,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 581,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 582,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 583,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 584,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 585,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 586,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 587,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 588,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 589,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 590,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 591,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 592,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 593,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 594,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 595,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 596,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 597,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 598,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 599,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 600,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 601,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 602,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 603,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 604,
  'module' => 'apachesolr_search',
  'delta' => 'mlt-001',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 605,
  'module' => 'apachesolr_search',
  'delta' => 'sort',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 606,
  'module' => 'itg_widget',
  'delta' => 'section_ordering',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 607,
  'module' => 'itg_widget',
  'delta' => 'top_stories_ordering',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 608,
  'module' => 'itg_widget',
  'delta' => 'home_page_feature',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 609,
  'module' => 'itg_widget',
  'delta' => 'we_may_suggest',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 610,
  'module' => 'itg_widget',
  'delta' => 'section_wise_order',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 611,
  'module' => 'shorten',
  'delta' => 'shorten',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'shorten',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 612,
  'module' => 'shorten',
  'delta' => 'shorten_short',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 4,
);
  $export['block'][] = array(
  'bid' => 613,
  'module' => 'views',
  'delta' => 'nodequeue_1-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 614,
  'module' => 'views',
  'delta' => 'nodequeue_2-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 615,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 616,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 617,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'header',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 618,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'footer',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 619,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 620,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 621,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 622,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 623,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 624,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 625,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 626,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 627,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 628,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 629,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 630,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 631,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 632,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 633,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 634,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 635,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 636,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 637,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 638,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 639,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 640,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 641,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => -26,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 642,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 643,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 644,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 645,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 646,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 647,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 648,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 649,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 650,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 651,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 652,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 653,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 654,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 655,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 656,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 657,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 658,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 659,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 660,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 661,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 662,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 663,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 664,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 665,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_manager_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 666,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 667,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 668,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 669,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 670,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widgets',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 671,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 672,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 673,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 674,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 675,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_widget_list_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 676,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 677,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 678,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 679,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 680,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_button_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'itg-layout-manager/home
itg-layout-manager/section',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 681,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 682,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 683,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 684,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 685,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 686,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 687,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 688,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 689,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 690,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 691,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 692,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 693,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 694,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 695,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 696,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 697,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 698,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 699,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 700,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 701,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 702,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 703,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 704,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 705,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 706,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 707,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 708,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 709,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 710,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 711,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 712,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 713,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 714,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 715,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 716,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 717,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 718,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 719,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 720,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 721,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 722,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 723,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 724,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 725,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 726,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 727,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 728,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 729,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 730,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 731,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 732,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 733,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 734,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 735,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 736,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 737,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 738,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 739,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 740,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 741,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 742,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 743,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 744,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 745,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 746,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 747,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 748,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 749,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 750,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 751,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 752,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 753,
  'module' => 'itg_layout_manager',
  'delta' => 'header_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 754,
  'module' => 'itg_layout_manager',
  'delta' => 'footer_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 755,
  'module' => 'menu',
  'delta' => 'menu-itg-distribution-menu-foote',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 756,
  'module' => 'menu',
  'delta' => 'menu-itg-events-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 757,
  'module' => 'menu',
  'delta' => 'menu-itg-music-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 758,
  'module' => 'menu',
  'delta' => 'menu-itg-printing-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 759,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-manu-foote',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 760,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 761,
  'module' => 'menu',
  'delta' => 'menu-itg-shopping-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 762,
  'module' => 'menu',
  'delta' => 'menu-itg-syndication-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 763,
  'module' => 'menu',
  'delta' => 'menu-itg-television-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 764,
  'module' => 'menu',
  'delta' => 'menu-itg-useful-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 765,
  'module' => 'menu',
  'delta' => 'menu-itg-welfare-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 766,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 767,
  'module' => 'menu',
  'delta' => 'menu-itg-main-manu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 768,
  'module' => 'menu',
  'delta' => 'menu-itg-top-manu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 769,
  'module' => 'views',
  'delta' => 'test_views-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 770,
  'module' => 'views',
  'delta' => 'autosave_settings-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 771,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 772,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 773,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 774,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 775,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 776,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 777,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 778,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 779,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 780,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 781,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 782,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 783,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 784,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 785,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 786,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 787,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 788,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 789,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 790,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 791,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 792,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 793,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 794,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 795,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 796,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 797,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -63,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 798,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 799,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 800,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 801,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 802,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 803,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 804,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 805,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -64,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 806,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 807,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 808,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 809,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 810,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 811,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 812,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 813,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 814,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 815,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 816,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 817,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'top',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 818,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 819,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 820,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 821,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 822,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 823,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 824,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 825,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 826,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 827,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 828,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 829,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 830,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 831,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 832,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 833,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 834,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 835,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 836,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 837,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 838,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 839,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 840,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 841,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 842,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 843,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 844,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 845,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 846,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 847,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 848,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 849,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 850,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 851,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 852,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 853,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 854,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 855,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 856,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 857,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 858,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 859,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 860,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 861,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 862,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 863,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 864,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 865,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 866,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 867,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 868,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 869,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 870,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 871,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 872,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 873,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 874,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 875,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 876,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 877,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 878,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 879,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 880,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 881,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 882,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 883,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 884,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 885,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 886,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 887,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 888,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 889,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 890,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 891,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 892,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 893,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 894,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 895,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 896,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 897,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 898,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 899,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 900,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 901,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 902,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 903,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 904,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 905,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 906,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 907,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 908,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 909,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 910,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 911,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 912,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 913,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 914,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 915,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 916,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 917,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 918,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 919,
  'module' => 'itg_widget',
  'delta' => 'trending_videos_widget',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 920,
  'module' => 'itg_widget',
  'delta' => 'top_takes_videos_widget',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 921,
  'module' => 'itg_widget',
  'delta' => 'big_story_format',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 922,
  'module' => 'itg_widget',
  'delta' => 'most_popular',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 923,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 924,
  'module' => 'itg_widget',
  'delta' => 'featured_photo_carousel_r',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 925,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 926,
  'module' => 'itg_widget',
  'delta' => 'featured_video_carousel_r',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 927,
  'module' => 'itg_widget',
  'delta' => 'dont_miss',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 928,
  'module' => 'itg_widget',
  'delta' => 'watch_right_now_videos_widget',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 929,
  'module' => 'menu',
  'delta' => 'menu-itg-publications-menu-foote',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 930,
  'module' => 'menu',
  'delta' => 'menu-itg-radio-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 931,
  'module' => 'menu',
  'delta' => 'menu-itg-education-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 932,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-footer',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 933,
  'module' => 'menu',
  'delta' => 'menu-itg-main-menu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 934,
  'module' => 'menu',
  'delta' => 'menu-itg-top-menu-header',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 935,
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'manage-print-team
manage-print-team-approved
manage-print-team-rejected
manage-print-team-needs-modification
manage-print-team-not-decided
manage-print-team/*
manage-print-team-approved/*
manage-print-team-rejected/*
manage-print-team-needs-modification/*
manage-print-team-not-decided/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 936,
  'module' => 'menu',
  'delta' => 'menu-podcast-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'unpublished-podcast
published-podcast
my-unpublished-podcast
mydraft-podcast
my-published-podcast
my-queue-podcast
in-queue-podcast
archive-podcast
my-rejected-podcast',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 937,
  'module' => 'views',
  'delta' => 'nodequeue_4-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 938,
  'module' => 'views',
  'delta' => 'nodequeue_5-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 939,
  'module' => 'views',
  'delta' => 'nodequeue_6-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 940,
  'module' => 'views',
  'delta' => 'nodequeue_7-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 941,
  'module' => 'views',
  'delta' => 'nodequeue_8-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 942,
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 943,
  'module' => 'views',
  'delta' => 'b5b878b48e462dca5337da3470065640',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 944,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 945,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'header',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 946,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 947,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 948,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 949,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 950,
  'module' => 'itg_layout_manager',
  'delta' => 'header_snap_post_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'snappost',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 951,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 952,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 953,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 954,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 955,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 956,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => -59,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 957,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 958,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 959,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 960,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 961,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 962,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 963,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 964,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 965,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 966,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 967,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 968,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 969,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 970,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 971,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 972,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 973,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 974,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 975,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 976,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 977,
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/reporter
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 978,
  'module' => 'menu',
  'delta' => 'menu-left-sidebar',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 979,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 980,
  'module' => 'views',
  'delta' => 'video_list_of_category-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 981,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 982,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 983,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 984,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 985,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 986,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 987,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 988,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 989,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 990,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 991,
  'module' => 'itg_poll',
  'delta' => 'itg_poll_past_poll',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 992,
  'module' => 'menu',
  'delta' => 'menu-videogallery-admin-menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'mydraft-video
in-queue-video
my-queue-video
my-published-video
published-video
my-rejected-video
my-unpublished-video
unpublished-video
archive-video',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 993,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 994,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 995,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 996,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 997,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 998,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 999,
  'module' => 'itg_front_end_common',
  'delta' => 'taboola_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1007,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1008,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1009,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1010,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1011,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1012,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1013,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/videogallery
node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1014,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1015,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1016,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'itgadmin',
  'status' => 1,
  'weight' => 0,
  'region' => 'form_tab',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1017,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1018,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1019,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1020,
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'node/add/podcast
node/add/podcast*
node/*/edit',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1021,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1022,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -58,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1023,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1024,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1025,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1026,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1027,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1028,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'header',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1029,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'header',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1030,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1031,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1032,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1033,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1034,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1035,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1036,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1037,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1038,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1039,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1040,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1041,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1042,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1043,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1044,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1045,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1046,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1047,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1048,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1049,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1050,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1051,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1052,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1053,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1054,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1055,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1056,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1057,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1058,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1059,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1060,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1061,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1062,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1063,
  'module' => 'itg_front_end_common',
  'delta' => 'vukkul_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1064,
  'module' => 'views',
  'delta' => 'nodequeue_10-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1065,
  'module' => 'views',
  'delta' => 'nodequeue_9-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1066,
  'module' => 'views',
  'delta' => 'past_polls-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1067,
  'module' => 'views',
  'delta' => 'video_landing_header-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1068,
  'module' => 'views',
  'delta' => 'video_landing_header-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1069,
  'module' => 'views',
  'delta' => '4a62aa197128cf9da87aeef978472f9b',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'taxonomy/term/*',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1070,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -64,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1071,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1072,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1073,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1074,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1075,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1076,
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1077,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1078,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1079,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1080,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1081,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1082,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1083,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1084,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -66,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1085,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1086,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1087,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1088,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1089,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1090,
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/add/*
node/*/edit',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1091,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => -65,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1092,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1093,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1094,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1095,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1096,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1097,
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'node/*/edit',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1098,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1099,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1100,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'itg',
  'status' => 1,
  'weight' => -67,
  'region' => 'sidebar_second',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1101,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1102,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1103,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1104,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1105,
  'module' => 'block',
  'delta' => 1,
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => 'user
user/*
taxonomy/term/*
<front>
snappost
personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1106,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1107,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1108,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1109,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1110,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1111,
  'module' => 'itg_widget',
  'delta' => 'rhs_section_wise_order',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1112,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1113,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1114,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1115,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1116,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1117,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1118,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1119,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1120,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1121,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1122,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1123,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1124,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1125,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1126,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1127,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1128,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1129,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1130,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1131,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1132,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1133,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1134,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1135,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1136,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1137,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1138,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1139,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1140,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1141,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1142,
  'module' => 'itg_layout_manager',
  'delta' => 'layout_section_widget2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1143,
  'module' => 'itg_widget',
  'delta' => 'anchor_langing_page_menu',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 1,
);
  $export['block'][] = array(
  'bid' => 1144,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1145,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1146,
  'module' => 'views',
  'delta' => 'video_list_of_category-block_3',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1147,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1148,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1149,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1150,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1151,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1152,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1153,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1154,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1155,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1156,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1157,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1158,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'personalization',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1159,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1160,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1161,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1162,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1163,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1164,
  'module' => 'itg_personalization',
  'delta' => 'personalized_content_menu_tab',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries
personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1165,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1166,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1167,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1168,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1169,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1170,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1171,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1172,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1173,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1174,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1175,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1176,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1177,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1178,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1179,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1180,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1181,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1182,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1183,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1184,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1185,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1186,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1187,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1188,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1189,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1190,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1191,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1192,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1193,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1194,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1195,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1196,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1197,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1198,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1199,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1200,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1201,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1202,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1203,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1204,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1205,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1206,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1207,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1208,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1209,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1210,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1211,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1212,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1213,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1214,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1215,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1216,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1217,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1218,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1219,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1220,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_1',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1221,
  'module' => 'itg_ads',
  'delta' => 'ad_right_sidebar_2',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1222,
  'module' => 'itg_personalization',
  'delta' => 'personalized_saved_content',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all
personalization/saved-items/articles
personalization/saved-items/videos
personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1223,
  'module' => 'itg_personalization',
  'delta' => 'user_saved_content',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1224,
  'module' => 'itg_personalization',
  'delta' => 'user_my_content',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => 8,
);
  $export['block'][] = array(
  'bid' => 1225,
  'module' => 'views',
  'delta' => '38f0346c2132f36b14636c66a4924d6e',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items
personalization/saved-items/all',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1226,
  'module' => 'views',
  'delta' => '769b5173b8b634c80e7494097fe05bf3',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/articles',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1227,
  'module' => 'views',
  'delta' => 'f4b87536c91052455f4426444a611153',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/videos',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1228,
  'module' => 'views',
  'delta' => '889f82f979b23a28427520a7b9e1407e',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/saved-items/photogalleries',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1229,
  'module' => 'views',
  'delta' => '5f0de47af37ec8c53c0802af39dd9626',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1230,
  'module' => 'views',
  'delta' => '7a788d5fc14ed02cf09fe6aa1d609c28',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 1,
  'pages' => 'personalization/my-content',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1231,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'content',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1232,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'itg',
  'status' => 1,
  'weight' => 0,
  'region' => 'sidebar_first',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1233,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'itg',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1234,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1235,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1236,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'bartik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1237,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1238,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1239,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'itgadmin',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1240,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1241,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1242,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'rubik',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1243,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1244,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1245,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'seven',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1246,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1247,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1248,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'tao',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1249,
  'module' => 'views',
  'delta' => 'anchor_landing_page-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1250,
  'module' => 'views',
  'delta' => 'programmes-rhs_programmes',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => '',
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '<none>',
  'cache' => -1,
);
  $export['block'][] = array(
  'bid' => 1251,
  'module' => 'views',
  'delta' => 'programme_content-block',
  'theme' => 'zen',
  'status' => 0,
  'weight' => 0,
  'region' => -1,
  'custom' => 0,
  'visibility' => 0,
  'pages' => '',
  'title' => '',
  'cache' => -1,
);
  $export['block_custom'][] = array(
  'bid' => 1,
  'body' => '<div class="ad-display-block">Ad</div>
',
  'info' => 'Ad display block for second side bar',
  'format' => 'full_html',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_astro',
  'delta' => 'astro_tab_form_block',
  'type' => 'astro',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_blog',
  'delta' => 'blog_tab_form_block',
  'type' => 'blog',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'blog',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'type' => 'blog',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_breaking_news',
  'delta' => 'breaking_news_tab_form_block',
  'type' => 'breaking_news',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'breaking_news',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_event_backend',
  'delta' => 'event_backend_tab_form_block',
  'type' => 'event_backend',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'type' => 'mega_review_critic',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photo_menu_landing_block',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'photo_landing_slider-block',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'photo_list_of_category-block',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'photo_list_of_category-block_2',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'type' => 'photogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'type' => 'podcast',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'podcast',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'type' => 'podcast',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'type' => 'poll',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'type' => 'quiz',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_recipe',
  'delta' => 'recipe_tab_form_block',
  'type' => 'recipe',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_reporter',
  'delta' => 'reporter_tab_form_block',
  'type' => 'reporter',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_event_backend',
  'delta' => 'sponsor_tab_form_block',
  'type' => 'sponsor',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'story',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'type' => 'story',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'type' => 'story',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_2',
  'type' => 'story',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'survey',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'type' => 'survey',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_related',
  'delta' => 'related_form_block',
  'type' => 'videogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_menu_video_block',
  'type' => 'videogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'itg_videogallery',
  'delta' => 'videogallery_tab_form_block',
  'type' => 'videogallery',
);
  $export['block_node_type'][] = array(
  'module' => 'views',
  'delta' => 'view_moderation_history-block_1',
  'type' => 'videogallery',
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 4,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 5,
);
  $export['block_role'][] = array(
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 6,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 7,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 8,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 8,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 9,
);
  $export['block_role'][] = array(
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 10,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 11,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 11,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 11,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 12,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 12,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 12,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 13,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 13,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 13,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 14,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 14,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 14,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 15,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 15,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 15,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 16,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 16,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 16,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 17,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 17,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 17,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 18,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 19,
);
  $export['block_role'][] = array(
  'module' => 'itg_category_manager',
  'delta' => 'sef_url_log',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_mega_reviews_critics',
  'delta' => 'mega_reviews_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_podcast',
  'delta' => 'podcast_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_poll',
  'delta' => 'poll_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_quiz',
  'delta' => 'quiz_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'itg_survey',
  'delta' => 'survey_tab_form_block',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-mega-review-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-movie-review-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-print-team-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-story-content-admin-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'superfish',
  'delta' => 1,
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'system',
  'delta' => 'main',
  'rid' => 20,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-task-allocation-menu',
  'rid' => 21,
);
  $export['block_role'][] = array(
  'module' => 'itg_photogallery',
  'delta' => 'photogallery_tab_form_block',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'itg_story',
  'delta' => 'story_tab_form_block',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-photogallery-admin-menu',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-comment-menu',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-ugc-content-menu',
  'rid' => 22,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 23,
);
  $export['block_role'][] = array(
  'module' => 'menu',
  'delta' => 'menu-admin-left-menu',
  'rid' => 24,
);
return $export;
}
