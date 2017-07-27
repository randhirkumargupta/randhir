<?php
/**
 * @file
 * feature_for_reporter.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_reporter_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'autocomplete_for_byline';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Autocomplete for byline';
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
    'story' => 'story',
  );

  /* Display: Auto complete for byline */
  $handler = $view->new_display('entityreference', 'Auto complete for byline', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Auto complete for byline';
  $handler->display->display_options['display_description'] = 'Auto complete for byline';
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
  $handler->display->display_options['defaults']['relationships'] = FALSE;
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
  $handler->display->display_options['fields']['field_reporter_email_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reporter_email_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_reporter_email_id']['alter']['text'] = '([field_reporter_email_id])';
  /* Field: Content: Occupation */
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['id'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['field'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['label'] = '';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[title] [field_reporter_email_id] ([field_celebrity_pro_occupation])';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = 'return REPORTER_TID;';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
    'reporter' => 'reporter',
  );
  $export['autocomplete_for_byline'] = $view;

  $view = new view();
  $view->name = 'byline_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Byline list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Byline list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_reporter_email_id' => 'field_reporter_email_id',
    'field_reporter_twitter_handle' => 'field_reporter_twitter_handle',
    'created' => 'created',
    'edit_node' => 'nothing',
    'delete_node' => 'nothing',
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
    'field_reporter_email_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reporter_twitter_handle' => array(
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
  $handler->display->display_options['fields']['counter']['label'] = 'S.NO.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Byline name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Email id */
  $handler->display->display_options['fields']['field_reporter_email_id']['id'] = 'field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['table'] = 'field_data_field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['field'] = 'field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['label'] = 'Byline\'s Email id';
  /* Field: Content: Twitter Handle */
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['id'] = 'field_reporter_twitter_handle';
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['table'] = 'field_data_field_reporter_twitter_handle';
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['field'] = 'field_reporter_twitter_handle';
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['label'] = 'Byline Twitter Handle';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['alter']['text'] = '<span class="delete-link">[delete_node]</span>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
    'field_reporter_email_id' => 'field_reporter_email_id',
    'field_reporter_twitter_handle' => 'field_reporter_twitter_handle',
    'created' => 'created',
    'edit_node' => 'nothing',
    'delete_node' => 'nothing',
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
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reporter_email_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reporter_twitter_handle' => array(
      'sortable' => 1,
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
    'nothing' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No record found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.NO.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Email id */
  $handler->display->display_options['fields']['field_reporter_email_id']['id'] = 'field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['table'] = 'field_data_field_reporter_email_id';
  $handler->display->display_options['fields']['field_reporter_email_id']['field'] = 'field_reporter_email_id';
  /* Field: Content: Twitter Handle */
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['id'] = 'field_reporter_twitter_handle';
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['table'] = 'field_data_field_reporter_twitter_handle';
  $handler->display->display_options['fields']['field_reporter_twitter_handle']['field'] = 'field_reporter_twitter_handle';
  /* Field: Field: Session Title  */
  $handler->display->display_options['fields']['field_story_expert_name']['id'] = 'field_story_expert_name';
  $handler->display->display_options['fields']['field_story_expert_name']['table'] = 'field_data_field_story_expert_name';
  $handler->display->display_options['fields']['field_story_expert_name']['field'] = 'field_story_expert_name';
  /* Field: Content: Occupation */
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['id'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['field'] = 'field_celebrity_pro_occupation';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_celebrity_pro_occupation']['delta_offset'] = '0';
  /* Field: Content: Profile type */
  $handler->display->display_options['fields']['field_reporter_profile_type']['id'] = 'field_reporter_profile_type';
  $handler->display->display_options['fields']['field_reporter_profile_type']['table'] = 'field_data_field_reporter_profile_type';
  $handler->display->display_options['fields']['field_reporter_profile_type']['field'] = 'field_reporter_profile_type';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node]</span>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
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
    'reporter' => 'reporter',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
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
  );
  /* Filter criterion: Content: Email id (field_reporter_email_id) */
  $handler->display->display_options['filters']['field_reporter_email_id_value']['id'] = 'field_reporter_email_id_value';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['table'] = 'field_data_field_reporter_email_id';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['field'] = 'field_reporter_email_id_value';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_reporter_email_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_reporter_email_id_value']['expose']['operator_id'] = 'field_reporter_email_id_value_op';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['expose']['label'] = 'Email id';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['expose']['operator'] = 'field_reporter_email_id_value_op';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['expose']['identifier'] = 'field_reporter_email_id_value';
  $handler->display->display_options['filters']['field_reporter_email_id_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Twitter Handle (field_reporter_twitter_handle) */
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['id'] = 'field_reporter_twitter_handle_value';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['table'] = 'field_data_field_reporter_twitter_handle';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['field'] = 'field_reporter_twitter_handle_value';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['operator'] = 'word';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['group'] = 1;
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['expose']['operator_id'] = 'field_reporter_twitter_handle_value_op';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['expose']['label'] = 'Twitter Handle';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['expose']['operator'] = 'field_reporter_twitter_handle_value_op';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['expose']['identifier'] = 'field_reporter_twitter_handle_value';
  $handler->display->display_options['filters']['field_reporter_twitter_handle_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Occupation (field_celebrity_pro_occupation) */
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['id'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['field'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['expose']['operator_id'] = 'field_celebrity_pro_occupation_tid_op';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['expose']['label'] = 'Occupation';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['expose']['operator'] = 'field_celebrity_pro_occupation_tid_op';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['expose']['identifier'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['vocabulary'] = 'itg_occupation';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'byline-list';
  $export['byline_list'] = $view;

  return $export;
}
