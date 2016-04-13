<?php
/**
 * @file
 * task_allocation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function task_allocation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'task';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'task';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    20 => '20',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'field_add_task_idea' => 'field_add_task_idea',
    'field_select_team_member' => 'field_select_team_member',
    'field_finish_date_and_time' => 'field_finish_date_and_time',
    'field_status' => 'field_status',
    'view_node' => 'nothing',
    'edit_node' => 'nothing',
    'nothing' => 'nothing',
    'comments_link' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_add_task_idea' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_select_team_member' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_finish_date_and_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_status' => array(
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
    'nothing' => array(
      'align' => '',
      'separator' => '|',
      'empty_column' => 0,
    ),
    'comments_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.no.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_add_task_idea']['id'] = 'field_add_task_idea';
  $handler->display->display_options['fields']['field_add_task_idea']['table'] = 'field_data_field_add_task_idea';
  $handler->display->display_options['fields']['field_add_task_idea']['field'] = 'field_add_task_idea';
  $handler->display->display_options['fields']['field_add_task_idea']['label'] = 'Task Description';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_select_team_member']['id'] = 'field_select_team_member';
  $handler->display->display_options['fields']['field_select_team_member']['table'] = 'field_data_field_select_team_member';
  $handler->display->display_options['fields']['field_select_team_member']['field'] = 'field_select_team_member';
  $handler->display->display_options['fields']['field_select_team_member']['label'] = 'Task assign to';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_finish_date_and_time']['id'] = 'field_finish_date_and_time';
  $handler->display->display_options['fields']['field_finish_date_and_time']['table'] = 'field_data_field_finish_date_and_time';
  $handler->display->display_options['fields']['field_finish_date_and_time']['field'] = 'field_finish_date_and_time';
  $handler->display->display_options['fields']['field_finish_date_and_time']['label'] = 'Last date';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_status']['id'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['table'] = 'field_data_field_status';
  $handler->display->display_options['fields']['field_status']['field'] = 'field_status';
  $handler->display->display_options['fields']['field_status']['label'] = 'Status';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  /* Field: Content: Add comment link */
  $handler->display->display_options['fields']['comments_link']['id'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['table'] = 'node';
  $handler->display->display_options['fields']['comments_link']['field'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['label'] = 'reply';
  $handler->display->display_options['fields']['comments_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comments_link']['alter']['path'] = 'comment/reply/[nid]';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_user_mail']['id'] = 'field_user_mail';
  $handler->display->display_options['fields']['field_user_mail']['table'] = 'field_data_field_user_mail';
  $handler->display->display_options['fields']['field_user_mail']['field'] = 'field_user_mail';
  $handler->display->display_options['fields']['field_user_mail']['label'] = 'user email';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'task_idea_allocation_tracking' => 'task_idea_allocation_tracking',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.no.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Task / idea */
  $handler->display->display_options['fields']['field_task_task_idea']['id'] = 'field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['table'] = 'field_data_field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['field'] = 'field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['label'] = 'Task Description';
  $handler->display->display_options['fields']['field_task_task_idea']['delta_offset'] = '0';
  /* Field: Content: Finish Date and time */
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['id'] = 'field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['table'] = 'field_data_field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['field'] = 'field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['label'] = 'Last date';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Select team member */
  $handler->display->display_options['fields']['field_task_team_member']['id'] = 'field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['table'] = 'field_data_field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['field'] = 'field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['label'] = 'User name';
  $handler->display->display_options['fields']['field_task_team_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status']['id'] = 'field_task_status';
  $handler->display->display_options['fields']['field_task_status']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['fields']['field_task_status']['field'] = 'field_task_status';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  /* Field: Content: Add comment link */
  $handler->display->display_options['fields']['comments_link']['id'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['table'] = 'node';
  $handler->display->display_options['fields']['comments_link']['field'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['label'] = 'reply';
  $handler->display->display_options['fields']['comments_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comments_link']['alter']['path'] = 'comment/reply/[nid]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'task_idea_allocation_tracking' => 'task_idea_allocation_tracking',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['path'] = 'assigned-task-list';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.no.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Task / idea */
  $handler->display->display_options['fields']['field_task_task_idea']['id'] = 'field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['table'] = 'field_data_field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['field'] = 'field_task_task_idea';
  $handler->display->display_options['fields']['field_task_task_idea']['label'] = 'Task Description';
  $handler->display->display_options['fields']['field_task_task_idea']['delta_offset'] = '0';
  /* Field: Content: Finish Date and time */
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['id'] = 'field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['table'] = 'field_data_field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['field'] = 'field_task_finish_date_and_time';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['label'] = 'Last date';
  $handler->display->display_options['fields']['field_task_finish_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Select team member */
  $handler->display->display_options['fields']['field_task_team_member']['id'] = 'field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['table'] = 'field_data_field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['field'] = 'field_task_team_member';
  $handler->display->display_options['fields']['field_task_team_member']['label'] = 'User name';
  $handler->display->display_options['fields']['field_task_team_member']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_task_status']['id'] = 'field_task_status';
  $handler->display->display_options['fields']['field_task_status']['table'] = 'field_data_field_task_status';
  $handler->display->display_options['fields']['field_task_status']['field'] = 'field_task_status';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  /* Field: Content: Add comment link */
  $handler->display->display_options['fields']['comments_link']['id'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['table'] = 'node';
  $handler->display->display_options['fields']['comments_link']['field'] = 'comments_link';
  $handler->display->display_options['fields']['comments_link']['label'] = 'reply';
  $handler->display->display_options['fields']['comments_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['comments_link']['alter']['path'] = 'comment/reply/[nid]';
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
    'task_idea_allocation_tracking' => 'task_idea_allocation_tracking',
  );
  $handler->display->display_options['path'] = 'created-task-list';
  $export['task'] = $view;

  $view = new view();
  $view->name = 'task_user_email';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Task user Email';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Task user Email';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Task user Email entity';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'mail' => 'mail',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['task_user_email'] = $view;

  return $export;
}
