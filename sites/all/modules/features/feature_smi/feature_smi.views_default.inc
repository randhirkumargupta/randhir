<?php
/**
 * @file
 * feature_smi.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_smi_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'browse_content';
  $view->description = 'Social media team can browse content for social media integration.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Browse Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Published Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    10 => '10',
    23 => '23',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_story_category' => 'field_story_category',
    'created' => 'created',
    'nid' => 'nid',
    'nothing' => 'nothing',
    'view_node' => 'view_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No result found!';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'itg';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Search By Post Date';
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
  );
  /* Filter criterion: Content: Section (field_story_category) */
  $handler->display->display_options['filters']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['filters']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_story_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator_id'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['identifier'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recipe' => 'recipe',
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'recipe' => 'recipe',
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  /* Filter criterion: Content: Schedule date &amp; time (field_story_schedule_date_time) */
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['id'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['field'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Content: Content Publish date */
  $handler->display->display_options['fields']['field_itg_content_publish_date']['id'] = 'field_itg_content_publish_date';
  $handler->display->display_options['fields']['field_itg_content_publish_date']['table'] = 'field_data_field_itg_content_publish_date';
  $handler->display->display_options['fields']['field_itg_content_publish_date']['field'] = 'field_itg_content_publish_date';
  $handler->display->display_options['fields']['field_itg_content_publish_date']['label'] = 'Published On';
  $handler->display->display_options['fields']['field_itg_content_publish_date']['settings'] = array(
    'format_type' => 'itg',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'Actions';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
  $handler->display->display_options['fields']['view_node']['text'] = 'Promote';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Content Publish date (field_itg_content_publish_date) */
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['id'] = 'field_itg_content_publish_date_value';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['table'] = 'field_data_field_itg_content_publish_date';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['field'] = 'field_itg_content_publish_date_value';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['expose']['operator_id'] = 'field_itg_content_publish_date_value_op';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['expose']['label'] = 'Filter By Publish Date ';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['expose']['operator'] = 'field_itg_content_publish_date_value_op';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['expose']['identifier'] = 'field_itg_content_publish_date_value';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_itg_content_publish_date_value']['form_type'] = 'date_popup';
  /* Filter criterion: Content: Content Publish date (field_itg_content_publish_date) */
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['id'] = 'field_itg_content_publish_date_value_3';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['table'] = 'field_data_field_itg_content_publish_date';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['field'] = 'field_itg_content_publish_date_value';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['operator'] = '<=';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['group'] = 1;
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['expose']['operator_id'] = 'field_itg_content_publish_date_value_3_op';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['expose']['operator'] = 'field_itg_content_publish_date_value_3_op';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['expose']['identifier'] = 'field_itg_content_publish_date_value_3';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_itg_content_publish_date_value_3']['default_date'] = 'now';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Section (field_story_category) */
  $handler->display->display_options['filters']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['filters']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_story_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_story_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator_id'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['identifier'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Schedule date &amp; time (field_story_schedule_date_time) */
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['id'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['field'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'browse-content';
  $export['browse_content'] = $view;

  $view = new view();
  $view->name = 'social_media_logs';
  $view->description = 'Content logs posted on social media.';
  $view->tag = 'default';
  $view->base_table = 'itg_social_media_logs';
  $view->human_name = 'Social media logs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Social media logs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    10 => '10',
    23 => '23',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'node_title' => 'node_title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'node_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['empty']['area']['content'] = 'No result found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Social Media Logs: relate a node to social media post */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Social Media Logs: Node title */
  $handler->display->display_options['fields']['node_title']['id'] = 'node_title';
  $handler->display->display_options['fields']['node_title']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['node_title']['field'] = 'node_title';
  /* Field: Social Media Logs: Social media */
  $handler->display->display_options['fields']['social_media']['id'] = 'social_media';
  $handler->display->display_options['fields']['social_media']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['social_media']['field'] = 'social_media';
  $handler->display->display_options['fields']['social_media']['label'] = 'Social Media Platform';
  /* Field: Social Media Logs: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = 'Posted By';
  /* Field: Social Media Logs: Created time */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Last Promoted on';
  $handler->display->display_options['fields']['created']['date_format'] = 'itg_date_with_time';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Social Media Logs: Scheduled Time */
  $handler->display->display_options['fields']['scheduled_time']['id'] = 'scheduled_time';
  $handler->display->display_options['fields']['scheduled_time']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['scheduled_time']['field'] = 'scheduled_time';
  $handler->display->display_options['fields']['scheduled_time']['date_format'] = 'itg_date_with_time';
  $handler->display->display_options['fields']['scheduled_time']['second_date_format'] = 'long';
  /* Field: Social Media Logs: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-unpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Social Media Logs: Created time */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'story' => 'story',
    'recipe' => 'recipe',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'empty';
  /* Filter criterion: Social Media Logs: Created time */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = 'between';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Search By Post Date';
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
  );
  /* Filter criterion: Social Media Logs: Node title */
  $handler->display->display_options['filters']['node_title']['id'] = 'node_title';
  $handler->display->display_options['filters']['node_title']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['node_title']['field'] = 'node_title';
  $handler->display->display_options['filters']['node_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['node_title']['expose']['operator_id'] = 'node_title_op';
  $handler->display->display_options['filters']['node_title']['expose']['label'] = 'Node Title';
  $handler->display->display_options['filters']['node_title']['expose']['operator'] = 'node_title_op';
  $handler->display->display_options['filters']['node_title']['expose']['identifier'] = 'node_title';
  $handler->display->display_options['filters']['node_title']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Social Media Logs: Social media */
  $handler->display->display_options['filters']['social_media']['id'] = 'social_media';
  $handler->display->display_options['filters']['social_media']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['social_media']['field'] = 'social_media';
  $handler->display->display_options['filters']['social_media']['exposed'] = TRUE;
  $handler->display->display_options['filters']['social_media']['expose']['operator_id'] = 'social_media_op';
  $handler->display->display_options['filters']['social_media']['expose']['label'] = 'Social media';
  $handler->display->display_options['filters']['social_media']['expose']['operator'] = 'social_media_op';
  $handler->display->display_options['filters']['social_media']['expose']['identifier'] = 'social_media';
  $handler->display->display_options['filters']['social_media']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Social Media Logs: Username */
  $handler->display->display_options['filters']['username']['id'] = 'username';
  $handler->display->display_options['filters']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['username']['field'] = 'username';
  $handler->display->display_options['filters']['username']['exposed'] = TRUE;
  $handler->display->display_options['filters']['username']['expose']['operator_id'] = 'username_op';
  $handler->display->display_options['filters']['username']['expose']['label'] = 'Posted by';
  $handler->display->display_options['filters']['username']['expose']['operator'] = 'username_op';
  $handler->display->display_options['filters']['username']['expose']['identifier'] = 'username';
  $handler->display->display_options['filters']['username']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Social Media Logs: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'social-media-logs/%';
  $export['social_media_logs'] = $view;

  return $export;
}
