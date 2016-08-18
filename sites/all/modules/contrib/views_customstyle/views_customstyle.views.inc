<?php

/**
 * @file views_customstyle.views.inc
 * Just describing our Views style plugin; nothing much to see here.
 */

/**
 * Implements hook_views_plugins().
 */
function views_customstyle_views_plugins() {
  return array(
    'style' => array(
      'customstyle' => array(
        'title' => t('Custom Style'),
        'help' => t('Add a custom style with only 1 template file'),
        'handler' => 'views_customstyle_style_plugin',
        'theme' => 'views_view_custom',
        'uses row plugin' => FALSE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
				'uses fields' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}