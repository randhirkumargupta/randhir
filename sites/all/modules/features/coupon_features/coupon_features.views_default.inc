<?php
/**
 * @file
 * coupon_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function coupon_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'manage_coupons';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Coupons';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Coupons';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    24 => '24',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
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
    'created' => 'created',
    'changed' => 'changed',
    'field_ads_start_date' => 'field_ads_start_date',
    'field_ads_end_date' => 'field_ads_end_date',
    'view_node' => 'nothing',
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
    'field_ads_start_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ads_end_date' => array(
      'sortable' => 1,
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
    'nothing' => array(
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
  $handler->display->display_options['empty']['area']['content'] = '<p>No Result found.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
  $handler->display->display_options['fields']['title']['label'] = 'Coupon Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Coupon Type */
  $handler->display->display_options['fields']['field_coupon_type']['id'] = 'field_coupon_type';
  $handler->display->display_options['fields']['field_coupon_type']['table'] = 'field_data_field_coupon_type';
  $handler->display->display_options['fields']['field_coupon_type']['field'] = 'field_coupon_type';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created on';
  $handler->display->display_options['fields']['created']['date_format'] = 'itg_date_with_time';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified on';
  $handler->display->display_options['fields']['changed']['date_format'] = 'itg_date_with_time';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Coupon Discount Type */
  $handler->display->display_options['fields']['field_coupon_discount_type']['id'] = 'field_coupon_discount_type';
  $handler->display->display_options['fields']['field_coupon_discount_type']['table'] = 'field_data_field_coupon_discount_type';
  $handler->display->display_options['fields']['field_coupon_discount_type']['field'] = 'field_coupon_discount_type';
  /* Field: Content: Discounted Value */
  $handler->display->display_options['fields']['field_coupon_discounted_value']['id'] = 'field_coupon_discounted_value';
  $handler->display->display_options['fields']['field_coupon_discounted_value']['table'] = 'field_data_field_coupon_discounted_value';
  $handler->display->display_options['fields']['field_coupon_discounted_value']['field'] = 'field_coupon_discounted_value';
  $handler->display->display_options['fields']['field_coupon_discounted_value']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Coupon uses limit */
  $handler->display->display_options['fields']['field_coupon_uses_limit']['id'] = 'field_coupon_uses_limit';
  $handler->display->display_options['fields']['field_coupon_uses_limit']['table'] = 'field_data_field_coupon_uses_limit';
  $handler->display->display_options['fields']['field_coupon_uses_limit']['field'] = 'field_coupon_uses_limit';
  $handler->display->display_options['fields']['field_coupon_uses_limit']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Used coupons */
  $handler->display->display_options['fields']['field_coupon_current_uses']['id'] = 'field_coupon_current_uses';
  $handler->display->display_options['fields']['field_coupon_current_uses']['table'] = 'field_data_field_coupon_current_uses';
  $handler->display->display_options['fields']['field_coupon_current_uses']['field'] = 'field_coupon_current_uses';
  $handler->display->display_options['fields']['field_coupon_current_uses']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Custom: Coupons rest uses */
  $handler->display->display_options['fields']['custom_handler']['id'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['table'] = 'custom_coupons_rest_uses';
  $handler->display->display_options['fields']['custom_handler']['field'] = 'custom_handler';
  /* Field: Content: Coupon Status */
  $handler->display->display_options['fields']['field_coupon_status']['id'] = 'field_coupon_status';
  $handler->display->display_options['fields']['field_coupon_status']['table'] = 'field_data_field_coupon_status';
  $handler->display->display_options['fields']['field_coupon_status']['field'] = 'field_coupon_status';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class="edit-link">[edit_node] </span>';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
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
    'ads_management' => 'ads_management',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
    'coupon' => 'coupon',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Coupon Title';
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
  /* Filter criterion: Content: Coupon Type (field_coupon_type) */
  $handler->display->display_options['filters']['field_coupon_type_value']['id'] = 'field_coupon_type_value';
  $handler->display->display_options['filters']['field_coupon_type_value']['table'] = 'field_data_field_coupon_type';
  $handler->display->display_options['filters']['field_coupon_type_value']['field'] = 'field_coupon_type_value';
  $handler->display->display_options['filters']['field_coupon_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_coupon_type_value']['expose']['operator_id'] = 'field_coupon_type_value_op';
  $handler->display->display_options['filters']['field_coupon_type_value']['expose']['label'] = 'Coupon Type';
  $handler->display->display_options['filters']['field_coupon_type_value']['expose']['operator'] = 'field_coupon_type_value_op';
  $handler->display->display_options['filters']['field_coupon_type_value']['expose']['identifier'] = 'field_coupon_type_value';
  $handler->display->display_options['filters']['field_coupon_type_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Coupon Status (field_coupon_status) */
  $handler->display->display_options['filters']['field_coupon_status_value']['id'] = 'field_coupon_status_value';
  $handler->display->display_options['filters']['field_coupon_status_value']['table'] = 'field_data_field_coupon_status';
  $handler->display->display_options['filters']['field_coupon_status_value']['field'] = 'field_coupon_status_value';
  $handler->display->display_options['filters']['field_coupon_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_coupon_status_value']['expose']['operator_id'] = 'field_coupon_status_value_op';
  $handler->display->display_options['filters']['field_coupon_status_value']['expose']['label'] = 'Coupon Status';
  $handler->display->display_options['filters']['field_coupon_status_value']['expose']['operator'] = 'field_coupon_status_value_op';
  $handler->display->display_options['filters']['field_coupon_status_value']['expose']['identifier'] = 'field_coupon_status_value';
  $handler->display->display_options['filters']['field_coupon_status_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'manage-coupons';
  $export['manage_coupons'] = $view;

  return $export;
}
