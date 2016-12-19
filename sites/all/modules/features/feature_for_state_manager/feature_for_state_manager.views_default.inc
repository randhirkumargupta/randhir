<?php
/**
 * @file
 * feature_for_state_manager.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_state_manager_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'state_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'State Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'State Manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'state_managment' => 'state_managment',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    10 => '10',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Sr.No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['label'] = 'Actions';
  $handler->display->display_options['fields']['edit_term']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['alter']['text'] = '<span class="edit-link">[edit_term]</span>';
  $handler->display->display_options['fields']['edit_term']['text'] = 'Edit';
  $handler->display->display_options['path'] = 'state-manager';
  $export['state_manager'] = $view;

  return $export;
}
