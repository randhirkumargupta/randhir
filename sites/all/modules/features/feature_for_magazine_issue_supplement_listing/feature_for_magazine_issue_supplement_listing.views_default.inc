<?php
/**
 * @file
 * feature_for_magazine_issue_supplement_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_magazine_issue_supplement_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'magazine_stories';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Magazine stories';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Magazine stories';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'story' => 'story',
  );
  /* Filter criterion: Content: Select magazine (field_story_select_magazine) */
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['id'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['table'] = 'field_data_field_story_select_magazine';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['field'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['operator_id'] = 'field_story_select_magazine_target_id_op';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['label'] = 'Select magazine';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['operator'] = 'field_story_select_magazine_target_id_op';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['identifier'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['remember_roles'] = array(
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
    27 => 0,
    28 => 0,
    29 => 0,
  );
  /* Filter criterion: Content: Select supplement (field_story_select_supplement) */
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['id'] = 'field_story_select_supplement_target_id';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['table'] = 'field_data_field_story_select_supplement';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['field'] = 'field_story_select_supplement_target_id';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['operator_id'] = 'field_story_select_supplement_target_id_op';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['label'] = 'Select supplement (field_story_select_supplement)';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['operator'] = 'field_story_select_supplement_target_id_op';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['identifier'] = 'field_story_select_supplement_target_id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'nid' => 'nid',
    'name' => 'name',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
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
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Photo Gallery Title: Photo Gallery Title */
  $handler->display->display_options['fields']['custom_handler']['id'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['table'] = 'itg_photogallery';
  $handler->display->display_options['fields']['custom_handler']['field'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['label'] = 'Story Title';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Story Title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Story ID';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['changed']['label'] = 'Modified on';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['timezone'] = 'Asia/Kolkata';
  /* Field: Global: Mega review custom view link */
  $handler->display->display_options['fields']['mega_review_custom_view_link']['id'] = 'mega_review_custom_view_link';
  $handler->display->display_options['fields']['mega_review_custom_view_link']['table'] = 'views';
  $handler->display->display_options['fields']['mega_review_custom_view_link']['field'] = 'mega_review_custom_view_link';
  $handler->display->display_options['fields']['mega_review_custom_view_link']['label'] = 'View';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'story' => 'story',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Select magazine (field_story_select_magazine) */
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['id'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['table'] = 'field_data_field_story_select_magazine';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['field'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['operator_id'] = 'field_story_select_magazine_target_id_op';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['label'] = 'Select magazine';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['operator'] = 'field_story_select_magazine_target_id_op';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['identifier'] = 'field_story_select_magazine_target_id';
  $handler->display->display_options['filters']['field_story_select_magazine_target_id']['expose']['remember_roles'] = array(
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
    27 => 0,
    28 => 0,
    29 => 0,
  );
  /* Filter criterion: Content: Select supplement (field_story_select_supplement) */
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['id'] = 'field_story_select_supplement_target_id';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['table'] = 'field_data_field_story_select_supplement';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['field'] = 'field_story_select_supplement_target_id';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['operator_id'] = 'field_story_select_supplement_target_id_op';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['label'] = 'Select supplement';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['operator'] = 'field_story_select_supplement_target_id_op';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['identifier'] = 'field_story_select_supplement_target_id';
  $handler->display->display_options['filters']['field_story_select_supplement_target_id']['expose']['remember_roles'] = array(
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
    27 => 0,
    28 => 0,
    29 => 0,
  );
  /* Filter criterion: Field: DOB (field_story_issue_date) */
  $handler->display->display_options['filters']['field_story_issue_date_value']['id'] = 'field_story_issue_date_value';
  $handler->display->display_options['filters']['field_story_issue_date_value']['table'] = 'field_data_field_story_issue_date';
  $handler->display->display_options['filters']['field_story_issue_date_value']['field'] = 'field_story_issue_date_value';
  $handler->display->display_options['filters']['field_story_issue_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_issue_date_value']['expose']['operator_id'] = 'field_story_issue_date_value_op';
  $handler->display->display_options['filters']['field_story_issue_date_value']['expose']['label'] = 'Select issue';
  $handler->display->display_options['filters']['field_story_issue_date_value']['expose']['operator'] = 'field_story_issue_date_value_op';
  $handler->display->display_options['filters']['field_story_issue_date_value']['expose']['identifier'] = 'field_story_issue_date_value';
  $handler->display->display_options['filters']['field_story_issue_date_value']['expose']['remember_roles'] = array(
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
    27 => 0,
    28 => 0,
    29 => 0,
  );
  $handler->display->display_options['filters']['field_story_issue_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['path'] = 'magazine-stories';
  $export['magazine_stories'] = $view;

  return $export;
}
