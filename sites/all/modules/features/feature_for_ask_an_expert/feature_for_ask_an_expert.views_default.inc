<?php
/**
 * @file
 * feature_for_ask_an_expert.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_ask_an_expert_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'ask_an_expert';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ask an expert';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Ask an expert My Queue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_user_name' => 'field_user_name',
    'field_user_email' => 'field_user_email',
    'field_user_message' => 'field_user_message',
    'created' => 'created',
    'edit_node' => 'edit_node',
    'nothing' => 'nothing',
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
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'edit_node' => array(
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
  $handler->display->display_options['fields']['title']['label'] = 'Question';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_user_email']['id'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['fields']['field_user_email']['field'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Reply';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'ask_an_expert' => 'ask_an_expert',
  );

  /* Display: Ask an expert */
  $handler = $view->new_display('page', 'Ask an expert', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    21 => '21',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
    'field_user_name' => 'field_user_name',
    'field_user_email' => 'field_user_email',
    'field_user_message' => 'field_user_message',
    'created' => 'created',
    'view_node' => 'nothing',
    'edit_node' => 'nothing',
    'nothing' => 'nothing',
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
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_message' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
      'separator' => ' |',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['title']['label'] = 'Question';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_user_email']['id'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['fields']['field_user_email']['field'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_user_message']['id'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['fields']['field_user_message']['field'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['exclude'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Reply';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Source term id (field_user_source_term_id) */
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['id'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['field'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_options']['code'] = 'global $user;
if($user->uid != \'1\') {
  $user_uid = user_load($user->uid);
  foreach ($user_uid->field_user_section[\'und\'] as $key => $val) {
    if ($key > 0) {
      $str = \'+\';
    }  
    $tid .= $str.$val[\'tid\'];
  }
  return $tid;
}
else
{
  return \'No Record Found\';
}';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['break_phrase'] = TRUE;
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
    'ask_an_expert' => 'ask_an_expert',
  );
  /* Filter criterion: Content: Description (field_user_message) */
  $handler->display->display_options['filters']['field_user_message_value']['id'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['filters']['field_user_message_value']['field'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['operator'] = 'empty';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Question';
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
    22 => 0,
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
  /* Filter criterion: Content: Email (field_user_email) */
  $handler->display->display_options['filters']['field_user_email_value']['id'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['filters']['field_user_email_value']['field'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_user_email_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_email_value']['expose']['operator_id'] = 'field_user_email_value_op';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['operator'] = 'field_user_email_value_op';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['identifier'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    22 => 0,
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
  $handler->display->display_options['path'] = 'ask-an-expert';

  /* Display: Ask an expert question answer */
  $handler = $view->new_display('page', 'Ask an expert question answer', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ask an expert question answer';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ask-an-expert-question-answer';
  $handler->display->display_options['display_description'] = 'Ask an expert question answer';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Ask the Expert';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Source term id */
  $handler->display->display_options['fields']['field_user_source_term_id']['id'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['field'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_source_term_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_source_term_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'expert-question';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_user_message']['id'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['fields']['field_user_message']['field'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['label'] = '';
  $handler->display->display_options['fields']['field_user_message']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_text'] = 'More[+]';
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_path'] = 'ask-an-expert-question-answer-details/[nid]/[field_user_source_term_id]';
  $handler->display->display_options['fields']['field_user_message']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_user_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_class'] = 'expert-answer';
  $handler->display->display_options['fields']['field_user_message']['element_default_classes'] = FALSE;
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
    'ask_an_expert' => 'ask_an_expert',
  );
  /* Filter criterion: Content: Description (field_user_message) */
  $handler->display->display_options['filters']['field_user_message_value']['id'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['filters']['field_user_message_value']['field'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'ask-an-expert-question-answer';

  /* Display: Ask an expert history */
  $handler = $view->new_display('page', 'Ask an expert history', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ask an expert history';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    21 => '21',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['title']['label'] = 'Question';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['element_label_colon'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_user_email']['id'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['fields']['field_user_email']['field'] = 'field_user_email';
  $handler->display->display_options['fields']['field_user_email']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_user_message']['id'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['fields']['field_user_message']['field'] = 'field_user_message';
  /* Field: Content: Source type */
  $handler->display->display_options['fields']['field_story_source_type']['id'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['field'] = 'field_story_source_type';
  $handler->display->display_options['fields']['field_story_source_type']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Source term id (field_user_source_term_id) */
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['id'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['field'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_options']['code'] = 'global $user;
if($user->uid != \'1\') {
  $user_uid = user_load($user->uid);
  foreach ($user_uid->field_user_section[\'und\'] as $key => $val) {
    if ($key > 0) {
      $str = \'+\';
    }  
    $tid .= $str.$val[\'tid\'];
  }
  return $tid;
}
else
{
  return \'No Record Found\';
}';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Source type (field_story_source_type) */
  $handler->display->display_options['arguments']['field_story_source_type_value']['id'] = 'field_story_source_type_value';
  $handler->display->display_options['arguments']['field_story_source_type_value']['table'] = 'field_data_field_story_source_type';
  $handler->display->display_options['arguments']['field_story_source_type_value']['field'] = 'field_story_source_type_value';
  $handler->display->display_options['arguments']['field_story_source_type_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_source_type_value']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_story_source_type_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_source_type_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_source_type_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_story_source_type_value']['limit'] = '0';
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
    'ask_an_expert' => 'ask_an_expert',
  );
  /* Filter criterion: Content: Description (field_user_message) */
  $handler->display->display_options['filters']['field_user_message_value']['id'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['filters']['field_user_message_value']['field'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Question';
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
    22 => 0,
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
  /* Filter criterion: Content: Email (field_user_email) */
  $handler->display->display_options['filters']['field_user_email_value']['id'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['table'] = 'field_data_field_user_email';
  $handler->display->display_options['filters']['field_user_email_value']['field'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_user_email_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_email_value']['expose']['operator_id'] = 'field_user_email_value_op';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['operator'] = 'field_user_email_value_op';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['identifier'] = 'field_user_email_value';
  $handler->display->display_options['filters']['field_user_email_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    20 => 0,
    6 => 0,
    22 => 0,
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
  $handler->display->display_options['path'] = 'ask-an-expert-history';

  /* Display: Ask an expert question answer details */
  $handler = $view->new_display('page', 'Ask an expert question answer details', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ask an expert question answer details';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ask-an-expert-question-answer ask-an-expert-detailspage';
  $handler->display->display_options['display_description'] = 'Ask an expert question answer details';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Ask the Expert';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Answer is not available for this Question.
';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'expert-question';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Source term id */
  $handler->display->display_options['fields']['field_user_source_term_id']['id'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['field'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_source_term_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_source_term_id']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_user_message']['id'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['fields']['field_user_message']['field'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['label'] = '';
  $handler->display->display_options['fields']['field_user_message']['alter']['max_length'] = '20';
  $handler->display->display_options['fields']['field_user_message']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_text'] = 'More[+]';
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_path'] = 'ask-an-expert-question-answer-details/[field_user_source_term_id]';
  $handler->display->display_options['fields']['field_user_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_class'] = 'expert-answer';
  $handler->display->display_options['fields']['field_user_message']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'ask_an_expert' => 'ask_an_expert',
  );
  /* Filter criterion: Content: Description (field_user_message) */
  $handler->display->display_options['filters']['field_user_message_value']['id'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['filters']['field_user_message_value']['field'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'ask-an-expert-question-answer-details';

  /* Display: Ask an expert question answer */
  $handler = $view->new_display('page', 'Ask an expert question answer', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Ask an expert question answer';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'ask-an-expert-question-answer';
  $handler->display->display_options['display_description'] = 'Ask an expert question answer';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = 'Ask the Expert';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Source term id */
  $handler->display->display_options['fields']['field_user_source_term_id']['id'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['field'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_source_term_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_source_term_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'expert-question';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_user_message']['id'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['fields']['field_user_message']['field'] = 'field_user_message';
  $handler->display->display_options['fields']['field_user_message']['label'] = '';
  $handler->display->display_options['fields']['field_user_message']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_user_message']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_text'] = 'More[+]';
  $handler->display->display_options['fields']['field_user_message']['alter']['more_link_path'] = 'ask-an-expert-question-answer-details/[nid]/[field_user_source_term_id]';
  $handler->display->display_options['fields']['field_user_message']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_user_message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_message']['element_wrapper_class'] = 'expert-answer';
  $handler->display->display_options['fields']['field_user_message']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Source term id (field_user_source_term_id) */
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['id'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['field'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['limit'] = '0';
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
    'ask_an_expert' => 'ask_an_expert',
  );
  /* Filter criterion: Content: Description (field_user_message) */
  $handler->display->display_options['filters']['field_user_message_value']['id'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['table'] = 'field_data_field_user_message';
  $handler->display->display_options['filters']['field_user_message_value']['field'] = 'field_user_message_value';
  $handler->display->display_options['filters']['field_user_message_value']['operator'] = 'not empty';
  $handler->display->display_options['path'] = 'ask-an-expert-question-answer/%';

  /* Display: Latest Question */
  $handler = $view->new_display('block', 'Latest Question', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Question';
  $handler->display->display_options['display_description'] = 'Latest Question';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Source term id */
  $handler->display->display_options['fields']['field_user_source_term_id']['id'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['field'] = 'field_user_source_term_id';
  $handler->display->display_options['fields']['field_user_source_term_id']['label'] = '';
  $handler->display->display_options['fields']['field_user_source_term_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_source_term_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'ask-an-expert-question-answer-details/[nid]/[field_user_source_term_id]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Source term id (field_user_source_term_id) */
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['id'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['table'] = 'field_data_field_user_source_term_id';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['field'] = 'field_user_source_term_id_value';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_source_term_id_value']['limit'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
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
    'ask_an_expert' => 'ask_an_expert',
  );
  $export['ask_an_expert'] = $view;

  $view = new view();
  $view->name = 'user_selection';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User Selection';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Selection';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No User Found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Add User';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::itg_widget_categories_wise_node_group' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Add User',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'Last Name';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: User: Section */
  $handler->display->display_options['fields']['field_user_section']['id'] = 'field_user_section';
  $handler->display->display_options['fields']['field_user_section']['table'] = 'field_data_field_user_section';
  $handler->display->display_options['fields']['field_user_section']['field'] = 'field_user_section';
  $handler->display->display_options['fields']['field_user_section']['type'] = 'hs_taxonomy_term_reference_last_text_only';
  $handler->display->display_options['fields']['field_user_section']['delta_offset'] = '0';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Section (field_user_section) */
  $handler->display->display_options['filters']['field_user_section_tid']['id'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['table'] = 'field_data_field_user_section';
  $handler->display->display_options['filters']['field_user_section_tid']['field'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['value'] = array(
    456 => '456',
  );
  $handler->display->display_options['filters']['field_user_section_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_section_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['operator_id'] = 'field_user_section_tid_op';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['operator'] = 'field_user_section_tid_op';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['identifier'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_section_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_user_section_tid']['hierarchy'] = 1;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['filters']['uid_1']['table'] = 'users';
  $handler->display->display_options['filters']['uid_1']['field'] = 'uid';
  $handler->display->display_options['filters']['uid_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid_1']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid_1']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'user_selection_for_section');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Section (field_user_section) */
  $handler->display->display_options['filters']['field_user_section_tid']['id'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['table'] = 'field_data_field_user_section';
  $handler->display->display_options['filters']['field_user_section_tid']['field'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_user_section_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['operator_id'] = 'field_user_section_tid_op';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['operator'] = 'field_user_section_tid_op';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['identifier'] = 'field_user_section_tid';
  $handler->display->display_options['filters']['field_user_section_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_user_section_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_user_section_tid']['vocabulary'] = 'category_management';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['filters']['uid_1']['table'] = 'users';
  $handler->display->display_options['filters']['uid_1']['field'] = 'uid';
  $handler->display->display_options['filters']['uid_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['uid_1']['value'] = array(
    0 => 0,
  );
  $handler->display->display_options['filters']['uid_1']['group'] = 1;
  $handler->display->display_options['path'] = 'user-selection';
  $export['user_selection'] = $view;

  return $export;
}
