<?php
/**
 * @file
 * feature_tag_management.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_tag_management_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'follow_tags';
  $view->description = 'List of featured tag.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Follow Tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Followed By Me';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personalized content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );
  /* Filter criterion: Taxonomy term: Feature Tags (field_tags_display) */
  $handler->display->display_options['filters']['field_tags_display_value']['id'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['table'] = 'field_data_field_tags_display';
  $handler->display->display_options['filters']['field_tags_display_value']['field'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['value'] = array(
    'Yes' => 'Yes',
  );
  /* Filter criterion: Taxonomy term: Tag Status (field_tags_status) */
  $handler->display->display_options['filters']['field_tags_status_value']['id'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['table'] = 'field_data_field_tags_status';
  $handler->display->display_options['filters']['field_tags_status_value']['field'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['value'] = array(
    'Published' => 'Published',
  );

  /* Display: Follow View */
  $handler = $view->new_display('block', 'Follow View', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'To be Follow';
  $handler->display->display_options['display_description'] = 'List of tags to follow.';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );
  /* Filter criterion: Taxonomy term: Feature Tags (field_tags_display) */
  $handler->display->display_options['filters']['field_tags_display_value']['id'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['table'] = 'field_data_field_tags_display';
  $handler->display->display_options['filters']['field_tags_display_value']['field'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['value'] = array(
    'Yes' => 'Yes',
  );
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['flagged']['id'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['table'] = 'flagging';
  $handler->display->display_options['filters']['flagged']['field'] = 'flagged';
  $handler->display->display_options['filters']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['filters']['flagged']['value'] = '0';
  /* Filter criterion: Taxonomy term: Tag Status (field_tags_status) */
  $handler->display->display_options['filters']['field_tags_status_value']['id'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['table'] = 'field_data_field_tags_status';
  $handler->display->display_options['filters']['field_tags_status_value']['field'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['value'] = array(
    'Published' => 'Published',
  );

  /* Display: Following */
  $handler = $view->new_display('block', 'Following', 'block_1');
  $handler->display->display_options['display_description'] = 'My following tags. ';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $export['follow_tags'] = $view;

  $view = new view();
  $view->name = 'tags_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'itg_category_manager';
  $view->human_name = 'Tags Management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Tags';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    19 => '19',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = TRUE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'name' => 'name',
    'field_tags_status' => 'field_tags_status',
    'field_tags_display' => 'field_tags_display',
    'tid' => 'tid',
    'created' => 'created',
    'changed' => 'changed',
    'edit_term' => 'edit_term',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags_display' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_term' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Tags Found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Category Manager: ITG */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'itg_category_manager';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  $handler->display->display_options['relationships']['tid']['required'] = TRUE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'tid';
  /* Field: Taxonomy term: Feature Tags */
  $handler->display->display_options['fields']['field_tags_display']['id'] = 'field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['table'] = 'field_data_field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['field'] = 'field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['relationship'] = 'tid';
  /* Field: Taxonomy term: Tag Status */
  $handler->display->display_options['fields']['field_tags_status']['id'] = 'field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['table'] = 'field_data_field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['field'] = 'field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['relationship'] = 'tid';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Category Manager: created field */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'itg_category_manager';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Category Manager: changed field */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'itg_category_manager';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['relationship'] = 'tid';
  $handler->display->display_options['fields']['edit_term']['label'] = 'Edit link';
  $handler->display->display_options['fields']['edit_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="edit-link">[edit_term]</span><span class ="views-action-separator"> | </span><span class="delete-link"><a href="./texonomy/confirm/ajax/[tid]">Delete</a></span>';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Sort criterion: Category Manager: changed field */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'itg_category_manager';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Sort criterion: Category Manager: created field */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'itg_category_manager';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'tid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Tag Name';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );
  /* Filter criterion: Taxonomy term: Feature Tags (field_tags_display) */
  $handler->display->display_options['filters']['field_tags_display_value']['id'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['table'] = 'field_data_field_tags_display';
  $handler->display->display_options['filters']['field_tags_display_value']['field'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['relationship'] = 'tid';
  $handler->display->display_options['filters']['field_tags_display_value']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_display_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_display_value']['expose']['operator_id'] = 'field_tags_display_value_op';
  $handler->display->display_options['filters']['field_tags_display_value']['expose']['label'] = 'Feature Tags';
  $handler->display->display_options['filters']['field_tags_display_value']['expose']['operator'] = 'field_tags_display_value_op';
  $handler->display->display_options['filters']['field_tags_display_value']['expose']['identifier'] = 'field_tags_display_value';
  $handler->display->display_options['filters']['field_tags_display_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );
  /* Filter criterion: Taxonomy term: Tag Status (field_tags_status) */
  $handler->display->display_options['filters']['field_tags_status_value']['id'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['table'] = 'field_data_field_tags_status';
  $handler->display->display_options['filters']['field_tags_status_value']['field'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['relationship'] = 'tid';
  $handler->display->display_options['filters']['field_tags_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_tags_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_tags_status_value']['expose']['operator_id'] = 'field_tags_status_value_op';
  $handler->display->display_options['filters']['field_tags_status_value']['expose']['label'] = 'Tag Status';
  $handler->display->display_options['filters']['field_tags_status_value']['expose']['operator'] = 'field_tags_status_value_op';
  $handler->display->display_options['filters']['field_tags_status_value']['expose']['identifier'] = 'field_tags_status_value';
  $handler->display->display_options['filters']['field_tags_status_value']['expose']['remember_roles'] = array(
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
    22 => 0,
  );
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['relationship'] = 'tid';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  /* Filter criterion: Category Manager: created field */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'itg_category_manager';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['value']['max'] = '+1 day';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'created field';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'tags-management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'ITG_download_taxonomy';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Exports CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 0;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'tid';
  /* Field: Taxonomy term: Feature Tags */
  $handler->display->display_options['fields']['field_tags_display']['id'] = 'field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['table'] = 'field_data_field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['field'] = 'field_tags_display';
  $handler->display->display_options['fields']['field_tags_display']['relationship'] = 'tid';
  /* Field: Taxonomy term: Tag Status */
  $handler->display->display_options['fields']['field_tags_status']['id'] = 'field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['table'] = 'field_data_field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['field'] = 'field_tags_status';
  $handler->display->display_options['fields']['field_tags_status']['relationship'] = 'tid';
  $handler->display->display_options['path'] = 'download-tags';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $export['tags_management'] = $view;

  return $export;
}
