<?php
/**
 * @file
 * feature_for_video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'anchor_option_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Anchor option view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reporter' => 'reporter',
  );
  /* Filter criterion: Content: Occupation (field_celebrity_pro_occupation) */
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['id'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['field'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['value'] = array(
    0 => '427',
  );
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['vocabulary'] = 'itg_occupation';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Email id */
  $handler->display->display_options['fields']['field_reporter_email_id']['id'] = 'field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['table'] = 'field_data_field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['field'] = 'field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['label'] = '';
  $handler->display->display_options['fields']['field_reporter_email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reporter_email_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_reporter_email_id']['alter']['text'] = '([field_reporter_email_id])';
  $handler->display->display_options['fields']['field_reporter_email_id']['element_label_colon'] = FALSE;
  /* Field: Content: Occupation */
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['id'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['field'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title] [field_reporter_email_id] ([field_celebrity_pro_occupation])';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $export['anchor_option_view'] = $view;

  $view = new view();
  $view->name = 'manage_videogallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Videogallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Videogallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    20 => '20',
    10 => '10',
    9 => '9',
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'nothing' => 'nothing',
    'changed' => 'changed',
    'status' => 'status',
    'view_node' => 'nothing_1',
    'edit_node' => 'nothing_1',
    'delete_node' => 'nothing_1',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'nothing' => array(
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
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Result not found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Video Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Posted By';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node] </span>';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="delete-link">[delete_node] </span>';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Video Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Video Id';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    22 => 0,
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;

  /* Display: Published Content */
  $handler = $view->new_display('page', 'Published Content', 'page');
  $handler->display->display_options['display_description'] = 'Listing of published content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Video Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'custom';
  $handler->display->display_options['fields']['status']['type_custom_true'] = 'Published';
  $handler->display->display_options['fields']['status']['type_custom_false'] = 'Un published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Video formats';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'View Formats';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'video-status/[nid]?width=600';
  $handler->display->display_options['fields']['nothing_2']['alter']['link_class'] = 'colorbox-load';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node] </span>';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="delete-link">[delete_node] </span>';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['path'] = 'manage-videogallery';

  /* Display: Draft Content */
  $handler = $view->new_display('page', 'Draft Content', 'page_1');
  $handler->display->display_options['display_description'] = 'Listing of draft content';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Video Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['type'] = 'custom';
  $handler->display->display_options['fields']['status']['type_custom_true'] = 'Published';
  $handler->display->display_options['fields']['status']['type_custom_false'] = 'Un published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Video formats';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'View Formats';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'video-status/[nid]?width=600';
  $handler->display->display_options['fields']['nothing_2']['alter']['link_class'] = 'colorbox-load';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node] </span>';
  $handler->display->display_options['fields']['view_node']['text'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="delete-link">[delete_node] </span>';
  $handler->display->display_options['fields']['delete_node']['text'] = 'Delete';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Video Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Video Id';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    22 => 0,
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['path'] = 'draft-manage-videogallery';
  $export['manage_videogallery'] = $view;

  $view = new view();
  $view->name = 'video_landing_header';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video landing  header';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
if(module_exists(\'itg_videogallery\')) {
$vid = itg_videogallery_get_videoid($row->fid);
}
?>
<iframe frameborder="0" width="613" height="448"
src="https://www.dailymotion.com/embed/video/<?php print $vid; ?>?autoplay=0&mute=1&ui-start-screen-info"
allowfullscreen></iframe>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Field: iOS */
  $handler->display->display_options['fields']['field_story_expert_description']['id'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['table'] = 'field_data_field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['field'] = 'field_story_expert_description';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );

  /* Display: Video landing  header block */
  $handler = $view->new_display('block', 'Video landing  header block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: File Usage: File */
  $handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
  $handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
  $handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: iOS */
  $handler->display->display_options['fields']['field_story_expert_description']['id'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['table'] = 'field_data_field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['field'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['label'] = '';
  $handler->display->display_options['fields']['field_story_expert_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_expert_description']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['field_story_expert_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_story_expert_description']['element_label_colon'] = FALSE;
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'node_to_file';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'M d, Y,  h:i a';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';

  /* Display: video landing page header scroll */
  $handler = $view->new_display('block', 'video landing page header scroll', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'container';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php
if(isset($_GET[\'category\']) && isset($_GET[\'sid\']) && !isset($_GET[\'pcat\'])){
	$t_name = itg_videogallery_get_term_name($_GET[\'category\']);
	print "<h3>". t("LATEST FROM $t_name") ."</h3>";
}elseif(isset($_GET[\'category\']) && isset($_GET[\'sid\']) && isset($_GET[\'pcat\']) && $_GET[\'pcat\'] != 0){
	$t_name = itg_videogallery_get_term_name($_GET[\'pcat\']);
	print "<h3>". t("LATEST FROM $t_name") ."</h3>";
}
?>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => '',
  );
  /* Field: Content: video_duration */
  $handler->display->display_options['fields']['field_video_duration']['id'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['table'] = 'field_data_field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['field'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '84';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: Category */
  $handler->display->display_options['sorts']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['sorts']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['sorts']['cat_id']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Section (field_story_category) */
  $handler->display->display_options['arguments']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['arguments']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['arguments']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['arguments']['field_story_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_category_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_story_category_tid']['default_argument_options']['code'] = 'if(isset($_GET[\'category\']) && isset($_GET[\'sid\']) && !isset($_GET[\'pcat\'])){
return $_GET[\'category\'];
}if(isset($_GET[\'category\']) && isset($_GET[\'sid\']) && isset($_GET[\'pcat\'])){
return $_GET[\'pcat\'];
}else{
$node = itg_videogallery_get_term(arg(1));
   if(in_array(variable_get(\'ipl_for_widget\'), $node))
   {
return variable_get(\'ipl_for_widget\');
}
}';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $export['video_landing_header'] = $view;

  $view = new view();
  $view->name = 'video_status';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'video status';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'video status';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_upload_video' => 'field_upload_video',
    'fid' => 'fid',
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
    'field_upload_video' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['field_upload_video_fid']['id'] = 'field_upload_video_fid';
  $handler->display->display_options['relationships']['field_upload_video_fid']['table'] = 'field_data_field_upload_video';
  $handler->display->display_options['relationships']['field_upload_video_fid']['field'] = 'field_upload_video_fid';
  $handler->display->display_options['relationships']['field_upload_video_fid']['relationship'] = 'field_videogallery_video_upload_value';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['relationship'] = 'field_upload_video_fid';
  $handler->display->display_options['fields']['filename']['label'] = 'Video Name';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'field_upload_video_fid';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'VIdeo Formats';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$video_id = itg_videogallery_get_videoid($row->fid);
if($video_id != \'\'){
 $api = itg_podcast_dailymotion_api();
 $value = $api->get(
        \'/video/\'.$video_id,
        array(\'fields\' => array(\'available_formats\'))
    );
print implode(\', \', $value[\'available_formats\']);
}else{
print \'Status not found.\';
}
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'video-status';
  $export['video_status'] = $view;

  $view = new view();
  $view->name = 'videogallery_management';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'videogallery management';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Story management';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    8 => '8',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'changed' => 'changed',
    'state' => 'state',
    'status' => 'status',
    'field_story_source_type' => 'field_story_source_type',
    'delete_node' => 'nothing_1',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_source_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<a href="./node/add/story">Create Story</a>
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Posted By';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;

  /* Display: Un Published video */
  $handler = $view->new_display('page', 'Un Published video', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Un Published video';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'changed' => 'changed',
    'state' => 'state',
    'status' => 'status',
    'field_story_source_type' => 'field_story_source_type',
    'edit_node' => 'edit_node',
    'delete_node' => 'nothing_1',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_source_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'videogallery::field_story_archive' => 'videogallery::field_story_archive',
        ),
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Un published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['empty'] = 'Video';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
  );
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'draft' => 'draft',
  );
  $handler->display->display_options['filters']['state_1']['group'] = 1;
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_story_archive_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_source_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator_id'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['identifier'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value_1']['id'] = 'field_story_source_type_value_1';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['value'] = 'migrated';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['group'] = 2;
  /* Filter criterion: Workbench Moderation: From state */
  $handler->display->display_options['filters']['from_state']['id'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['from_state']['field'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['from_state']['group'] = 2;
  $handler->display->display_options['path'] = 'unpublished-video';

  /* Display: Published video */
  $handler = $view->new_display('page', 'Published video', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Publish video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    8 => '8',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'field_story_syndication' => 'field_story_syndication',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'name' => 'name',
    'created' => 'created',
    'changed' => 'changed',
    'field_story_category' => 'field_story_category',
    'field_story_schedule_date_time' => 'field_story_schedule_date_time',
    'field_story_schedule_date_time_1' => 'field_story_schedule_date_time_1',
    'field_story_source_type' => 'field_story_source_type',
    'view_node' => 'nothing_1',
    'nothing_1' => 'nothing_1',
    'story_custom_view_link' => 'story_custom_view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_syndication' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
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
    'field_story_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_schedule_date_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_schedule_date_time_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_source_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'story_custom_view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  /* Field: Content: Syndication */
  $handler->display->display_options['fields']['field_story_syndication']['id'] = 'field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['table'] = 'field_data_field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['field'] = 'field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['empty'] = 'No';
  $handler->display->display_options['fields']['field_story_syndication']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['timezone'] = 'Asia/Kolkata';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time']['id'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_schedule_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['id'] = 'field_story_schedule_date_time_1';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['label'] = 'Status';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['empty'] = 'Video';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  /* Field: Global: Story custom view link */
  $handler->display->display_options['fields']['story_custom_view_link']['id'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['story_custom_view_link']['field'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['label'] = 'View';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
  );
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Syndication (field_story_syndication) */
  $handler->display->display_options['filters']['field_story_syndication_value']['id'] = 'field_story_syndication_value';
  $handler->display->display_options['filters']['field_story_syndication_value']['table'] = 'field_data_field_story_syndication';
  $handler->display->display_options['filters']['field_story_syndication_value']['field'] = 'field_story_syndication_value';
  $handler->display->display_options['filters']['field_story_syndication_value']['value'] = array(
    'Yes' => 'Yes',
  );
  $handler->display->display_options['filters']['field_story_syndication_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_syndication_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['operator_id'] = 'field_story_syndication_value_op';
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['label'] = 'Syndication';
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['operator'] = 'field_story_syndication_value_op';
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['identifier'] = 'field_story_syndication_value';
  $handler->display->display_options['filters']['field_story_syndication_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_story_archive_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_source_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator_id'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['identifier'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value_1']['id'] = 'field_story_source_type_value_1';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['value'] = 'migrated';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator_id'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['label'] = 'Source type (field_story_source_type)';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['identifier'] = 'field_story_source_type_value_1';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['state']['group'] = 2;
  $handler->display->display_options['path'] = 'published-video';

  /* Display: My Un Published video */
  $handler = $view->new_display('page', 'My Un Published video', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Un Published video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    7 => '7',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status']['alter']['text'] = 'Un published';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['empty'] = 'Video';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'podcast ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'draft' => 'draft',
  );
  $handler->display->display_options['filters']['state_1']['group'] = 1;
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_story_archive_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_source_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator_id'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['identifier'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Workbench Moderation: From state */
  $handler->display->display_options['filters']['from_state']['id'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['from_state']['field'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['from_state']['group'] = 2;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value_1']['id'] = 'field_story_source_type_value_1';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['value'] = 'migrated';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator_id'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['identifier'] = 'field_story_source_type_value_1';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'my-unpublished-video';

  /* Display: My Draft Of video */
  $handler = $view->new_display('page', 'My Draft Of video', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Draft video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    20 => '20',
    10 => '10',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'changed' => 'changed',
    'state' => 'state',
    'delete_node' => 'delete_node',
    'nothing_1' => 'nothing_1',
    'story_custom_view_link' => 'story_custom_view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'story_custom_view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  /* Field: Global: Story custom view link */
  $handler->display->display_options['fields']['story_custom_view_link']['id'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['story_custom_view_link']['field'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'draft' => 'draft',
  );
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Workbench Moderation: From state */
  $handler->display->display_options['filters']['from_state']['id'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['from_state']['field'] = 'from_state';
  $handler->display->display_options['filters']['from_state']['operator'] = 'not in';
  $handler->display->display_options['filters']['from_state']['value'] = array(
    'published' => 'published',
  );
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'mydraft-video';

  /* Display: My Published video */
  $handler = $view->new_display('page', 'My Published video', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Published video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    7 => '7',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'field_story_schedule_date_time' => 'field_story_schedule_date_time',
    'changed' => 'changed',
    'field_story_schedule_date_time_1' => 'field_story_schedule_date_time_1',
    'field_story_source_type' => 'field_story_source_type',
    'story_custom_view_link' => 'story_custom_view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_schedule_date_time' => array(
      'sortable' => 0,
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
    'field_story_schedule_date_time_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_source_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'story_custom_view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '

';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time']['id'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_schedule_date_time']['settings'] = array(
    'format_type' => 'itg_date_and_time',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['id'] = 'field_story_schedule_date_time_1';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['label'] = 'Status';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['empty'] = 'Video';
  /* Field: Global: Story custom view link */
  $handler->display->display_options['fields']['story_custom_view_link']['id'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['story_custom_view_link']['field'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
  );
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_story_archive_value']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_source_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator_id'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['label'] = 'Source type';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['operator'] = 'field_story_source_type_value_op';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['identifier'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['state']['group'] = 2;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value_1']['id'] = 'field_story_source_type_value_1';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['value'] = 'migrated';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['group'] = 2;
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator_id'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['label'] = 'Source type (field_story_source_type)';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['operator'] = 'field_story_source_type_value_1_op';
  $handler->display->display_options['filters']['field_story_source_type_value_1']['expose']['identifier'] = 'field_story_source_type_value_1';
  $handler->display->display_options['path'] = 'my-published-video';

  /* Display: My video queue */
  $handler = $view->new_display('page', 'My video queue', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My video queue';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    7 => '7',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'changed' => 'changed',
    'state' => 'state',
    'nothing_1' => 'nothing_1',
    'story_custom_view_link' => 'story_custom_view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'story_custom_view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  /* Field: Global: Story custom view link */
  $handler->display->display_options['fields']['story_custom_view_link']['id'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['story_custom_view_link']['field'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'needs_review' => 'needs_review',
    'needs_modification' => 'needs_modification',
  );
  $handler->display->display_options['filters']['state_1']['expose']['operator_id'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state_1']['expose']['operator'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['identifier'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
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
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'my-queue-video';

  /* Display: In video queue */
  $handler = $view->new_display('page', 'In video queue', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'In Queue Video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    6 => '6',
    8 => '8',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'edit_node' => 'edit_node',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'name' => 'name',
    'changed' => 'changed',
    'state' => 'state',
    'nothing_1' => 'nothing_1',
    'story_custom_view_link' => 'story_custom_view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'name' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'story_custom_view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Title';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['edit_node']['alter']['make_link'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  /* Field: Global: Story custom view link */
  $handler->display->display_options['fields']['story_custom_view_link']['id'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['story_custom_view_link']['field'] = 'story_custom_view_link';
  $handler->display->display_options['fields']['story_custom_view_link']['label'] = 'View';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'needs_review' => 'needs_review',
  );
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'in-queue-video';

  /* Display: Archive video */
  $handler = $view->new_display('page', 'Archive video', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Archive video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    8 => '8',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Status';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Archived';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['value'] = array(
    'Yes' => 'Yes',
  );
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value_1']['id'] = 'field_story_archive_value_1';
  $handler->display->display_options['filters']['field_story_archive_value_1']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value_1']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value_1']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'archive-video';

  /* Display: My video Rejected */
  $handler = $view->new_display('page', 'My video Rejected', 'page_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My video Rejected';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    7 => '7',
    9 => '9',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'nid' => 'nid',
    'uid' => 'uid',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_story_category' => 'field_story_category',
    'nothing' => 'nothing',
    'changed' => 'changed',
    'state' => 'state',
    'edit_node' => 'nothing_1',
    'nothing_1' => 'nothing_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
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
    'nothing' => array(
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = 'Category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '2';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Workbench Moderation: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  $handler->display->display_options['fields']['state']['machine_name'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
    8 => 0,
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
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['value'] = array(
    'rejected' => 'rejected',
  );
  $handler->display->display_options['filters']['state_1']['expose']['operator_id'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state_1']['expose']['operator'] = 'state_1_op';
  $handler->display->display_options['filters']['state_1']['expose']['identifier'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
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
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['path'] = 'my-rejected-video';

  /* Display: UGC Video */
  $handler = $view->new_display('page', 'UGC Video', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage video';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    6 => '6',
    8 => '8',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Draggableviews: Content */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '50';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Syndication */
  $handler->display->display_options['fields']['field_story_syndication']['id'] = 'field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['table'] = 'field_data_field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['field'] = 'field_story_syndication';
  $handler->display->display_options['fields']['field_story_syndication']['empty'] = 'No';
  $handler->display->display_options['fields']['field_story_syndication']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'video ID';
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['label'] = 'Source';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Posted by';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['created']['timezone'] = 'Asia/Kolkata';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time']['id'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_schedule_date_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Schedule date & time */
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['id'] = 'field_story_schedule_date_time_1';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['field'] = 'field_story_schedule_date_time';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['label'] = 'Status';
  $handler->display->display_options['fields']['field_story_schedule_date_time_1']['settings'] = array(
    'format_type' => 'long',
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
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class ="views-action-separator"> | </span> <span class="edit-link">[edit_node]</span>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Actions';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'video ID';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
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
  );
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Workbench Moderation: Current */
  $handler->display->display_options['filters']['is_current']['id'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['is_current']['field'] = 'is_current';
  $handler->display->display_options['filters']['is_current']['value'] = '1';
  $handler->display->display_options['filters']['is_current']['group'] = 1;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['state']['group'] = 1;
  /* Filter criterion: Content: Are you sure you want to Archive? (field_story_archive) */
  $handler->display->display_options['filters']['field_story_archive_value']['id'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['table'] = 'field_data_field_story_archive';
  $handler->display->display_options['filters']['field_story_archive_value']['field'] = 'field_story_archive_value';
  $handler->display->display_options['filters']['field_story_archive_value']['operator'] = 'empty';
  $handler->display->display_options['filters']['field_story_archive_value']['group'] = 1;
  /* Filter criterion: Content: Source type (field_story_source_type) */
  $handler->display->display_options['filters']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['filters']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['filters']['field_story_source_type_value']['value'] = 'UGC';
  $handler->display->display_options['path'] = 'ugc-published-video';
  $export['videogallery_management'] = $view;

  return $export;
}
