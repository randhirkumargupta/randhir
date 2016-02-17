<?php
/**
 * @file
 * feature_for_poll.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_poll_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'poll_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Poll Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Poll Listing';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer rules';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Poll Question Text */
  $handler->display->display_options['fields']['field_poll_question_text']['id'] = 'field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['table'] = 'field_data_field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['field'] = 'field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['label'] = '';
  $handler->display->display_options['fields']['field_poll_question_text']['element_label_colon'] = FALSE;
  /* Field: Content: Poll Question Video */
  $handler->display->display_options['fields']['field_poll_question_video']['id'] = 'field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['table'] = 'field_data_field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['field'] = 'field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['label'] = '';
  $handler->display->display_options['fields']['field_poll_question_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_question_video']['click_sort_column'] = 'fid';
  /* Field: Content: Poll Answer */
  $handler->display->display_options['fields']['field_poll_answer']['id'] = 'field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['table'] = 'field_data_field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['field'] = 'field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['label'] = '';
  $handler->display->display_options['fields']['field_poll_answer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_answer']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_poll_answer']['delta_offset'] = '0';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Associate poll (field_associate_poll) */
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['id'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['table'] = 'field_data_field_associate_poll';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['field'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary_options']['items_per_page'] = '25';
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
    'poll' => 'poll',
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
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
  $handler->display->display_options['fields']['title']['label'] = 'Poll Title';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'POSTED BY';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Action';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poll' => 'poll',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
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
    18 => 0,
    6 => 0,
    19 => 0,
    12 => 0,
    10 => 0,
    15 => 0,
    16 => 0,
    13 => 0,
    11 => 0,
    14 => 0,
    17 => 0,
  );
  /* Filter criterion: Content: Poll Question (field_poll_question) */
  $handler->display->display_options['filters']['field_poll_question_value']['id'] = 'field_poll_question_value';
  $handler->display->display_options['filters']['field_poll_question_value']['table'] = 'field_data_field_poll_question';
  $handler->display->display_options['filters']['field_poll_question_value']['field'] = 'field_poll_question_value';
  $handler->display->display_options['filters']['field_poll_question_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_poll_question_value']['expose']['operator_id'] = 'field_poll_question_value_op';
  $handler->display->display_options['filters']['field_poll_question_value']['expose']['operator'] = 'field_poll_question_value_op';
  $handler->display->display_options['filters']['field_poll_question_value']['expose']['identifier'] = 'field_poll_question_value';
  $handler->display->display_options['filters']['field_poll_question_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    18 => 0,
    6 => 0,
    19 => 0,
    12 => 0,
    10 => 0,
    15 => 0,
    16 => 0,
    13 => 0,
    11 => 0,
    14 => 0,
    17 => 0,
  );
  $handler->display->display_options['path'] = 'poll-listing';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['id'] = 'field_associate_poll_target_id';
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['table'] = 'field_data_field_associate_poll';
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['field'] = 'field_associate_poll_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Poll Question Text */
  $handler->display->display_options['fields']['field_poll_question_text']['id'] = 'field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['table'] = 'field_data_field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['field'] = 'field_poll_question_text';
  $handler->display->display_options['fields']['field_poll_question_text']['label'] = '';
  $handler->display->display_options['fields']['field_poll_question_text']['element_label_colon'] = FALSE;
  /* Field: Content: Poll Question Image */
  $handler->display->display_options['fields']['field_poll_question_image']['id'] = 'field_poll_question_image';
  $handler->display->display_options['fields']['field_poll_question_image']['table'] = 'field_data_field_poll_question_image';
  $handler->display->display_options['fields']['field_poll_question_image']['field'] = 'field_poll_question_image';
  $handler->display->display_options['fields']['field_poll_question_image']['label'] = '';
  $handler->display->display_options['fields']['field_poll_question_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_question_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_poll_question_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Poll Question Video */
  $handler->display->display_options['fields']['field_poll_question_video']['id'] = 'field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['table'] = 'field_data_field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['field'] = 'field_poll_question_video';
  $handler->display->display_options['fields']['field_poll_question_video']['label'] = '';
  $handler->display->display_options['fields']['field_poll_question_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_question_video']['click_sort_column'] = 'fid';
  /* Field: Content: Poll Answer */
  $handler->display->display_options['fields']['field_poll_answer']['id'] = 'field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['table'] = 'field_data_field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['field'] = 'field_poll_answer';
  $handler->display->display_options['fields']['field_poll_answer']['label'] = '';
  $handler->display->display_options['fields']['field_poll_answer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_poll_answer']['settings'] = array(
    'edit' => 'Edit',
    'delete' => 'Delete',
    'add' => 'Add',
    'description' => 1,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_poll_answer']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Associate poll (field_associate_poll) */
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['id'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['table'] = 'field_data_field_associate_poll';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['field'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary_options']['items_per_page'] = '25';
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
    'poll' => 'poll',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date -  start date (field_poll_start_date) */
  $handler->display->display_options['filters']['field_poll_start_date_value']['id'] = 'field_poll_start_date_value';
  $handler->display->display_options['filters']['field_poll_start_date_value']['table'] = 'field_data_field_poll_start_date';
  $handler->display->display_options['filters']['field_poll_start_date_value']['field'] = 'field_poll_start_date_value';
  $handler->display->display_options['filters']['field_poll_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_poll_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poll_start_date_value']['expose']['operator_id'] = 'field_poll_start_date_value_op';
  $handler->display->display_options['filters']['field_poll_start_date_value']['expose']['label'] = 'Start Date -  start date (field_poll_start_date)';
  $handler->display->display_options['filters']['field_poll_start_date_value']['expose']['operator'] = 'field_poll_start_date_value_op';
  $handler->display->display_options['filters']['field_poll_start_date_value']['expose']['identifier'] = 'field_poll_start_date_value';
  $handler->display->display_options['filters']['field_poll_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Start Date - end date (field_poll_start_date:value2) */
  $handler->display->display_options['filters']['field_poll_start_date_value2']['id'] = 'field_poll_start_date_value2';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['table'] = 'field_data_field_poll_start_date';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['field'] = 'field_poll_start_date_value2';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['default_date'] = 'now';

  /* Display: Block 2 */
  $handler = $view->new_display('block', 'Block 2', 'block_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['id'] = 'field_associate_poll_target_id';
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['table'] = 'field_data_field_associate_poll';
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['field'] = 'field_associate_poll_target_id';
  $handler->display->display_options['relationships']['field_associate_poll_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Associate poll (field_associate_poll) */
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['id'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['table'] = 'field_data_field_associate_poll';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['field'] = 'field_associate_poll_target_id';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_associate_poll_target_id']['summary_options']['items_per_page'] = '25';
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
    'poll' => 'poll',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Start Date -  start date (field_poll_start_date) */
  $handler->display->display_options['filters']['field_poll_start_date_value']['id'] = 'field_poll_start_date_value';
  $handler->display->display_options['filters']['field_poll_start_date_value']['table'] = 'field_data_field_poll_start_date';
  $handler->display->display_options['filters']['field_poll_start_date_value']['field'] = 'field_poll_start_date_value';
  $handler->display->display_options['filters']['field_poll_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_poll_start_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_poll_start_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Start Date - end date (field_poll_start_date:value2) */
  $handler->display->display_options['filters']['field_poll_start_date_value2']['id'] = 'field_poll_start_date_value2';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['table'] = 'field_data_field_poll_start_date';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['field'] = 'field_poll_start_date_value2';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['operator'] = '>=';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['field_poll_start_date_value2']['default_date'] = 'now';
  $export['poll_listing'] = $view;

  return $export;
}
