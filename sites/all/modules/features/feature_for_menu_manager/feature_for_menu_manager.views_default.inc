<?php
/**
 * @file
 * feature_for_menu_manager.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_menu_manager_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'menu_manager';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'itg_menu_manager';
  $view->human_name = 'menu manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Menu manager';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Menu Manager: ITG */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'itg_menu_manager';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Menu Manager: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Menu Manager: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: Draggableviews: Taxonomy term */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'tid';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Menu Manager: Section */
  $handler->display->display_options['fields']['section_id']['id'] = 'section_id';
  $handler->display->display_options['fields']['section_id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['section_id']['field'] = 'section_id';
  $handler->display->display_options['fields']['section_id']['label'] = 'Section Id';
  $handler->display->display_options['fields']['section_id']['empty'] = 'n/a';
  $handler->display->display_options['fields']['section_id']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="?tid=[id]"><span class="remove-link"> Remove  </span></a>';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['relationship'] = 'tid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'tid';
  /* Field: Menu Manager: title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  /* Sort criterion: Menu Manager: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_menu_manager';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Menu Manager: Menu Level */
  $handler->display->display_options['arguments']['menu_level']['id'] = 'menu_level';
  $handler->display->display_options['arguments']['menu_level']['table'] = 'itg_menu_manager';
  $handler->display->display_options['arguments']['menu_level']['field'] = 'menu_level';
  $handler->display->display_options['arguments']['menu_level']['default_action'] = 'default';
  $handler->display->display_options['arguments']['menu_level']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['menu_level']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['menu_level']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['menu_level']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['menu_level']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['menu_level']['limit'] = '0';
  /* Filter criterion: Menu Manager: Category Manager Table */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'itg_menu_manager';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Term Id';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    21 => 0,
    19 => 0,
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
    22 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
  );
  /* Filter criterion: Menu Manager: Section */
  $handler->display->display_options['filters']['section_id']['id'] = 'section_id';
  $handler->display->display_options['filters']['section_id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['filters']['section_id']['field'] = 'section_id';
  $handler->display->display_options['filters']['section_id']['group'] = 1;
  $handler->display->display_options['filters']['section_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['section_id']['expose']['operator_id'] = 'section_id_op';
  $handler->display->display_options['filters']['section_id']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['section_id']['expose']['operator'] = 'section_id_op';
  $handler->display->display_options['filters']['section_id']['expose']['identifier'] = 'section_id';
  $handler->display->display_options['filters']['section_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    21 => 0,
    19 => 0,
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
    22 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
  );

  /* Display: Menu manager */
  $handler = $view->new_display('page', 'Menu manager', 'menu_manager_page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Menu Manager: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Menu Manager: Category Manager Table */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Term Tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Menu Manager: Weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['separator'] = '';
  /* Field: Menu Manager: title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  /* Field: Menu Manager: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Link';
  /* Field: Menu Manager: Menu name */
  $handler->display->display_options['fields']['menu_name']['id'] = 'menu_name';
  $handler->display->display_options['fields']['menu_name']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['menu_name']['field'] = 'menu_name';
  $handler->display->display_options['fields']['menu_name']['label'] = 'Icon';
  /* Field: Menu Manager: Url Type */
  $handler->display->display_options['fields']['url_type']['id'] = 'url_type';
  $handler->display->display_options['fields']['url_type']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['url_type']['field'] = 'url_type';
  $handler->display->display_options['fields']['url_type']['label'] = 'Menu Type';
  /* Field: Draggableviews: Taxonomy term */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'tid';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Draggable View';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['path'] = 'menu-manager';

  /* Display: menu manager */
  $handler = $view->new_display('block', 'menu manager', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Menu Manager: ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Menu Manager: title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Menu Manager: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  /* Field: Draggableviews: Taxonomy term */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['relationship'] = 'tid';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Menu Manager: Category Manager Table */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = 'Term ID';
  /* Field: Menu Manager: Section */
  $handler->display->display_options['fields']['section_id']['id'] = 'section_id';
  $handler->display->display_options['fields']['section_id']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['section_id']['field'] = 'section_id';
  $handler->display->display_options['fields']['section_id']['label'] = 'Section Id';
  $handler->display->display_options['fields']['section_id']['empty'] = 'n/a';
  $handler->display->display_options['fields']['section_id']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="?tid=[id]"><span class="remove-link"> Remove  </span></a>';
  /* Field: Menu Manager: Menu Level */
  $handler->display->display_options['fields']['menu_level']['id'] = 'menu_level';
  $handler->display->display_options['fields']['menu_level']['table'] = 'itg_menu_manager';
  $handler->display->display_options['fields']['menu_level']['field'] = 'menu_level';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Menu Manager: Menu Level */
  $handler->display->display_options['arguments']['menu_level']['id'] = 'menu_level';
  $handler->display->display_options['arguments']['menu_level']['table'] = 'itg_menu_manager';
  $handler->display->display_options['arguments']['menu_level']['field'] = 'menu_level';
  $handler->display->display_options['arguments']['menu_level']['default_action'] = 'default';
  $handler->display->display_options['arguments']['menu_level']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['menu_level']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['menu_level']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['menu_level']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['menu_level']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['menu_level']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $export['menu_manager'] = $view;

  return $export;
}
