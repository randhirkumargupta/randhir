<?php
/**
 * @file
 * features_for_loyalty_and_rewards.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function features_for_loyalty_and_rewards_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'lrp_manage_items';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Items';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    24 => '24',
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_lrp_product_count' => 'field_lrp_product_count',
    'field_lrp_actual_price' => 'field_lrp_actual_price',
    'field_lrp_discounted_price' => 'field_lrp_discounted_price',
    'field_lrp_loyalty_points' => 'field_lrp_loyalty_points',
    'field_story_expiry_date' => 'field_story_expiry_date',
    'created' => 'created',
    'changed' => 'changed',
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
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lrp_product_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lrp_actual_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lrp_discounted_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lrp_loyalty_points' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_expiry_date' => array(
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Product Title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Product Count */
  $handler->display->display_options['fields']['field_lrp_product_count']['id'] = 'field_lrp_product_count';
  $handler->display->display_options['fields']['field_lrp_product_count']['table'] = 'field_data_field_lrp_product_count';
  $handler->display->display_options['fields']['field_lrp_product_count']['field'] = 'field_lrp_product_count';
  $handler->display->display_options['fields']['field_lrp_product_count']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Actual Price */
  $handler->display->display_options['fields']['field_lrp_actual_price']['id'] = 'field_lrp_actual_price';
  $handler->display->display_options['fields']['field_lrp_actual_price']['table'] = 'field_data_field_lrp_actual_price';
  $handler->display->display_options['fields']['field_lrp_actual_price']['field'] = 'field_lrp_actual_price';
  $handler->display->display_options['fields']['field_lrp_actual_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Discounted Price */
  $handler->display->display_options['fields']['field_lrp_discounted_price']['id'] = 'field_lrp_discounted_price';
  $handler->display->display_options['fields']['field_lrp_discounted_price']['table'] = 'field_data_field_lrp_discounted_price';
  $handler->display->display_options['fields']['field_lrp_discounted_price']['field'] = 'field_lrp_discounted_price';
  $handler->display->display_options['fields']['field_lrp_discounted_price']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_lrp_discounted_price']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Loyalty Points */
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['id'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['field'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Field: Expiry Date */
  $handler->display->display_options['fields']['field_story_expiry_date']['id'] = 'field_story_expiry_date';
  $handler->display->display_options['fields']['field_story_expiry_date']['table'] = 'field_data_field_story_expiry_date';
  $handler->display->display_options['fields']['field_story_expiry_date']['field'] = 'field_story_expiry_date';
  $handler->display->display_options['fields']['field_story_expiry_date']['label'] = 'Product Expiry Date';
  $handler->display->display_options['fields']['field_story_expiry_date']['empty'] = '-';
  $handler->display->display_options['fields']['field_story_expiry_date']['settings'] = array(
    'format_type' => 'custom_date_d_m_y_',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom_date_d_m_y_';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom_date_d_m_y_';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Completed(Sold out) */
  $handler->display->display_options['fields']['field_lrp_completed']['id'] = 'field_lrp_completed';
  $handler->display->display_options['fields']['field_lrp_completed']['table'] = 'field_data_field_lrp_completed';
  $handler->display->display_options['fields']['field_lrp_completed']['field'] = 'field_lrp_completed';
  $handler->display->display_options['fields']['field_lrp_completed']['label'] = 'Status';
  $handler->display->display_options['fields']['field_lrp_completed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_completed']['alter']['text'] = 'Sold out';
  $handler->display->display_options['fields']['field_lrp_completed']['empty'] = 'In Stock';
  $handler->display->display_options['fields']['field_lrp_completed']['delta_offset'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span> ';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<span class ="views-action-separator"> | </span> <span class="edit-link">[edit_node]</span>';
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Product Title';
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
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'lrp-manage-items';
  $export['lrp_manage_items'] = $view;

  $view = new view();
  $view->name = 'redeem_points';
  $view->description = 'Product listing page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Redeem points';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Redeem points';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'VIEW ALL';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_lrp_image']['id'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['table'] = 'field_data_field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['field'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['label'] = '';
  $handler->display->display_options['fields']['field_lrp_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_lrp_image']['settings'] = array(
    'image_style' => 'magazine_rhs_100x140',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Loyalty Points */
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['id'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['field'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['label'] = '';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['text'] = '[field_lrp_loyalty_points] POINTS';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'ADD TO CART';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'cart/add/[nid]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = '[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'REDEEM POINTS';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'cart/add/[nid]/buy-now';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'redeem-point';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Loyalty Points (field_lrp_loyalty_points) */
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['id'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['field'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['value'] = '500';

  /* Display: 0 - 500 Points */
  $handler = $view->new_display('block', '0 - 500 Points', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '0 -500 POINTS';
  $handler->display->display_options['link_url'] = 'hfhfhfhgfgf';
  $export['redeem_points'] = $view;

  return $export;
}
