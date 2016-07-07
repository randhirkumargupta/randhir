<?php
/**
 * @file
 * feature_for_autosave.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_autosave_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'autosave_settings';
  $view->description = 'List of all form ids which are part of autosave.';
  $view->tag = 'default';
  $view->base_table = 'itg_autosave_forms';
  $view->human_name = 'Autosave Settings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Autosave Settings';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer itg_autosave settings';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Autosave Forms Id: Form Id */
  $handler->display->display_options['fields']['form_name']['id'] = 'form_name';
  $handler->display->display_options['fields']['form_name']['table'] = 'itg_autosave_forms';
  $handler->display->display_options['fields']['form_name']['field'] = 'form_name';
  /* Field: Autosave Forms Id: Time interval */
  $handler->display->display_options['fields']['autosave_time']['id'] = 'autosave_time';
  $handler->display->display_options['fields']['autosave_time']['table'] = 'itg_autosave_forms';
  $handler->display->display_options['fields']['autosave_time']['field'] = 'autosave_time';
  $handler->display->display_options['fields']['autosave_time']['separator'] = '';
  /* Field: Autosave Forms Id: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'itg_autosave_forms';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Delete';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'itg-autosave-formid-delete/[id]';
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'delete-link';
  $handler->display->display_options['fields']['nothing']['alter']['target'] = 'my_form';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Autosave Settings';
  $export['autosave_settings'] = $view;

  return $export;
}
