<?php
/**
 * @file
 * features_for_event_registration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function features_for_event_registration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_users_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event Users List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Group Users List';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Registration Found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Registration Fee */
  $handler->display->display_options['fields']['field_erf_registration_fee']['id'] = 'field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['table'] = 'field_data_field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['field'] = 'field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['label'] = 'Registration Details';
  $handler->display->display_options['fields']['field_erf_registration_fee']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_erf_registration_fee']['type'] = 'field_collection_fields';
  $handler->display->display_options['fields']['field_erf_registration_fee']['settings'] = array(
    'view_mode' => 'token',
  );
  $handler->display->display_options['fields']['field_erf_registration_fee']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_erf_registration_fee']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return arg(1);';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'event_registration' => 'event_registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'event-users-list/%';
  $export['event_users_list'] = $view;

  $view = new view();
  $view->name = 'manage_event_registration';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Event Registration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Registered Users List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
    10 => '10',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'nid' => 'nid',
    'field_erf_gender' => 'field_erf_gender',
    'title' => 'title',
    'field_last_name' => 'field_last_name',
    'nothing' => 'nothing',
    'field_erf_mobile' => 'field_erf_mobile',
    'field_erf_designation' => 'field_erf_designation',
    'field_erf_company_name' => 'field_erf_company_name',
    'field_erf_city' => 'field_erf_city',
    'field_erf_country' => 'field_erf_country',
    'nothing_1' => 'nothing_1',
    'created' => 'created',
    'php' => 'php',
    'field_story_source_id' => 'field_story_source_id',
    'php_1' => 'php_1',
    'nothing_3' => 'nothing_3',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
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
    'field_erf_gender' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_last_name' => array(
      'sortable' => 1,
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
    'field_erf_mobile' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_erf_designation' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_erf_company_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_erf_city' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_erf_country' => array(
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
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_source_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_3' => array(
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
  $handler->display->display_options['empty']['area']['content'] = 'No Result Found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S.No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Group Registered Users';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo itg_event_registration_get_registered_user($row->nid); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_erf_gender']['id'] = 'field_erf_gender';
  $handler->display->display_options['fields']['field_erf_gender']['table'] = 'field_data_field_erf_gender';
  $handler->display->display_options['fields']['field_erf_gender']['field'] = 'field_erf_gender';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'First Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_erf_gender] [title] [field_last_name]';
  /* Field: Field collection item: Mobile */
  $handler->display->display_options['fields']['field_erf_mobile']['id'] = 'field_erf_mobile';
  $handler->display->display_options['fields']['field_erf_mobile']['table'] = 'field_data_field_erf_mobile';
  $handler->display->display_options['fields']['field_erf_mobile']['field'] = 'field_erf_mobile';
  $handler->display->display_options['fields']['field_erf_mobile']['label'] = 'Mobile No.';
  /* Field: Content: Via Mail */
  $handler->display->display_options['fields']['field_email_address']['id'] = 'field_email_address';
  $handler->display->display_options['fields']['field_email_address']['table'] = 'field_data_field_email_address';
  $handler->display->display_options['fields']['field_email_address']['field'] = 'field_email_address';
  $handler->display->display_options['fields']['field_email_address']['empty'] = '-';
  /* Field: Field collection item: Company Name */
  $handler->display->display_options['fields']['field_erf_company_name']['id'] = 'field_erf_company_name';
  $handler->display->display_options['fields']['field_erf_company_name']['table'] = 'field_data_field_erf_company_name';
  $handler->display->display_options['fields']['field_erf_company_name']['field'] = 'field_erf_company_name';
  $handler->display->display_options['fields']['field_erf_company_name']['label'] = 'Organization Name';
  /* Field: Field collection item: Designation */
  $handler->display->display_options['fields']['field_erf_designation']['id'] = 'field_erf_designation';
  $handler->display->display_options['fields']['field_erf_designation']['table'] = 'field_data_field_erf_designation';
  $handler->display->display_options['fields']['field_erf_designation']['field'] = 'field_erf_designation';
  /* Field: Field collection item: City */
  $handler->display->display_options['fields']['field_erf_city']['id'] = 'field_erf_city';
  $handler->display->display_options['fields']['field_erf_city']['table'] = 'field_data_field_erf_city';
  $handler->display->display_options['fields']['field_erf_city']['field'] = 'field_erf_city';
  $handler->display->display_options['fields']['field_erf_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_erf_city']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_erf_country']['id'] = 'field_erf_country';
  $handler->display->display_options['fields']['field_erf_country']['table'] = 'field_data_field_erf_country';
  $handler->display->display_options['fields']['field_erf_country']['field'] = 'field_erf_country';
  $handler->display->display_options['fields']['field_erf_country']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Address';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_erf_city] ([field_erf_country])';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Registered Date';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Source id */
  $handler->display->display_options['fields']['field_story_source_id']['id'] = 'field_story_source_id';
  $handler->display->display_options['fields']['field_story_source_id']['table'] = 'field_data_field_story_source_id';
  $handler->display->display_options['fields']['field_story_source_id']['field'] = 'field_story_source_id';
  $handler->display->display_options['fields']['field_story_source_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_source_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Event Name';
  $handler->display->display_options['fields']['php_1']['empty'] = '-';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php echo itg_common_get_node_title($data->_field_data[\'nid\'][\'entity\']->field_story_source_id[\'und\'][0][\'value\']); ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Registration Fee */
  $handler->display->display_options['fields']['field_erf_registration_fee']['id'] = 'field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['table'] = 'field_data_field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['field'] = 'field_erf_registration_fee';
  $handler->display->display_options['fields']['field_erf_registration_fee']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_erf_registration_fee']['type'] = 'field_collection_fieldset_view';
  $handler->display->display_options['fields']['field_erf_registration_fee']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 1,
    'view_mode' => 'full',
    'legend' => '0',
    'collapsible' => 1,
    'collapsed' => 0,
  );
  $handler->display->display_options['fields']['field_erf_registration_fee']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_erf_registration_fee']['multi_type'] = 'ol';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Group Registered Users';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[php]';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'event-users-list/[nid]';
  $handler->display->display_options['fields']['nothing_2']['alter']['link_class'] = 'colorbox-load';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_3']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing_3']['alter']['text'] = 'View Detail';
  $handler->display->display_options['fields']['nothing_3']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_3']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nothing_3']['alter']['link_class'] = 'colorbox-load';
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
    'event_registration' => 'event_registration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'manage-event-registration';
  $export['manage_event_registration'] = $view;

  return $export;
}
