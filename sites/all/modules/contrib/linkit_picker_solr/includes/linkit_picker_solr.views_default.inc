<?php

/**
 * @file
 *
 */

/**
 * Implements hook_views_default_views().
 */
function linkit_picker_solr_views_default_views() {
  /*
   * View 'linkit_picker_solr'
   */
  $view = new view();
  $view->name = 'linkit_picker_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Linkit picker solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'External content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'label' => 'label',
    'url' => 'url',
    'linkit_picker' => 'linkit_picker',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'linkit_picker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Title';
  /* Field: Apache Solr: bundle_name */
  $handler->display->display_options['fields']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['label'] = 'Type';
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Linkit Picker: Linkit Picker */
  $handler->display->display_options['fields']['linkit_picker']['id'] = 'linkit_picker';
  $handler->display->display_options['fields']['linkit_picker']['table'] = 'linkit_picker_solr';
  $handler->display->display_options['fields']['linkit_picker']['field'] = 'linkit_picker';
  /* Sort criterion: Apache Solr: label */

  $handler->display->display_options['sorts']['label']['id'] = 'label';
  $handler->display->display_options['sorts']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['label']['field'] = 'label';
  /* Filter criterion: Apache Solr: label */
  $handler->display->display_options['filters']['label']['id'] = 'label';
  $handler->display->display_options['filters']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['label']['field'] = 'label';
  $handler->display->display_options['filters']['label']['operator'] = 'word';
  $handler->display->display_options['filters']['label']['group'] = 1;
  $handler->display->display_options['filters']['label']['exposed'] = TRUE;
  $handler->display->display_options['filters']['label']['expose']['operator_id'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['label']['expose']['operator'] = 'label_op';
  $handler->display->display_options['filters']['label']['expose']['identifier'] = 'label';

  $views[$view->name] = $view;

  return $views;
}