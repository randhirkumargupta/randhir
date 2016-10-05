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
  $view->name = 'product';
  $view->description = 'Product listing page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view product page';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Result Found!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'itg';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_lrp_image']['id'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['table'] = 'field_data_field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['field'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['label'] = '';
  $handler->display->display_options['fields']['field_lrp_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_lrp_image']['settings'] = array(
    'image_style' => 'cart_172x240',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_type'] = '0';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Loyalty Points */
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['id'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['field'] = 'field_lrp_loyalty_points';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['label'] = '';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['text'] = '[field_lrp_loyalty_points] POINTS';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'ADD TO CART';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'cart/add/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn-add-cart';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = '[nid]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'REDEEM POINTS';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'cart/add/[nid]/buy-now';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'btn-redeem-points';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'redeem-point';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="product-wrapper">
<div class="product-pic">[field_lrp_image]<span>[created]</span></div>
<div class="product-title">[title_1]</div>
<div class="product-description">[body]</div>
<div class="redeem-points">[field_lrp_loyalty_points]</div>
<div class="product-actions">[nothing][nothing_1]</div>
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Category (field_lrp_category) */
  $handler->display->display_options['filters']['field_lrp_category_value']['id'] = 'field_lrp_category_value';
  $handler->display->display_options['filters']['field_lrp_category_value']['table'] = 'field_data_field_lrp_category';
  $handler->display->display_options['filters']['field_lrp_category_value']['field'] = 'field_lrp_category_value';
  $handler->display->display_options['filters']['field_lrp_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lrp_category_value']['expose']['operator_id'] = 'field_lrp_category_value_op';
  $handler->display->display_options['filters']['field_lrp_category_value']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_lrp_category_value']['expose']['operator'] = 'field_lrp_category_value_op';
  $handler->display->display_options['filters']['field_lrp_category_value']['expose']['identifier'] = 'field_lrp_category_value';
  $handler->display->display_options['filters']['field_lrp_category_value']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Loyalty Points (field_lrp_loyalty_points) */
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['id'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['field'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['min'] = '0';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['max'] = '500';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['expose']['operator_id'] = 'field_lrp_loyalty_points_value_op';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['expose']['label'] = 'Points';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['expose']['operator'] = 'field_lrp_loyalty_points_value_op';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['expose']['identifier'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'product';
  $export['product'] = $view;

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
  $handler->display->display_options['style_options']['row_class'] = 'col-md-4';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'itg';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_lrp_image']['id'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['table'] = 'field_data_field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['field'] = 'field_lrp_image';
  $handler->display->display_options['fields']['field_lrp_image']['label'] = '';
  $handler->display->display_options['fields']['field_lrp_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_lrp_image']['settings'] = array(
    'image_style' => 'cart_172x240',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['alter']['text'] = '[field_lrp_loyalty_points] POINTS';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'ADD TO CART';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'cart/add/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['rel'] = '[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn-add-cart';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'REDEEM POINTS';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'cart/add/[nid]/buy-now';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'btn-redeem-points';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="product-wrapper">
<div class="product-pic">[field_lrp_image]<span>[created]</span></div>
<div class="product-title">[title]</div>
<div class="product-description">[body]</div>
<div class="redeem-points">[field_lrp_loyalty_points]</div>
<div class="product-actions">[nothing][nothing_1]</div>
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
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
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'product/0-500';

  /* Display: 501 - 1000 Points */
  $handler = $view->new_display('block', '501 - 1000 Points', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '501 - 1000 POINTS';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'product/501-1000';
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Loyalty Points (field_lrp_loyalty_points) */
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['id'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['field'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['min'] = '501';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['max'] = '1000';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['value'] = '500';

  /* Display: 1001 - 10000 Points */
  $handler = $view->new_display('block', '1001 - 10000 Points', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '1001 - 10000 POINTS';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'product/1001-10000';
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Loyalty Points (field_lrp_loyalty_points) */
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['id'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['table'] = 'field_data_field_lrp_loyalty_points';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['field'] = 'field_lrp_loyalty_points_value';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['min'] = '1001';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['max'] = '10000';
  $handler->display->display_options['filters']['field_lrp_loyalty_points_value']['value']['value'] = '500';

  /* Display: Others */
  $handler = $view->new_display('block', 'Others', 'block_4');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  $handler->display->display_options['fields']['field_lrp_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lrp_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_lrp_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_lrp_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_lrp_image']['settings'] = array(
    'image_style' => 'cart_172x240',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['field_lrp_loyalty_points']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'ADD TO CART';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'cart/add/[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['rel'] = '[nid]';
  $handler->display->display_options['fields']['nothing']['alter']['link_class'] = 'btn-add-cart';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'REDEEM POINTS';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'cart/add/[nid]/buy-now';
  $handler->display->display_options['fields']['nothing_1']['alter']['link_class'] = 'btn-redeem-points';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<div class="product-wrapper">
<div class="product-pic">[field_lrp_image]</div>
<div class="product-title">[title]</div>
<div class="redeem-points">[field_lrp_loyalty_points]</div>
<div class="product-actions">[nothing][nothing_1]</div>
</div>';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
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
    'loyalty_and_rewards' => 'loyalty_and_rewards',
  );
  /* Filter criterion: Content: Other Item (field_poll_itg_state) */
  $handler->display->display_options['filters']['field_poll_itg_state_value']['id'] = 'field_poll_itg_state_value';
  $handler->display->display_options['filters']['field_poll_itg_state_value']['table'] = 'field_data_field_poll_itg_state';
  $handler->display->display_options['filters']['field_poll_itg_state_value']['field'] = 'field_poll_itg_state_value';
  $handler->display->display_options['filters']['field_poll_itg_state_value']['value'] = array(
    1 => '1',
  );
  $export['redeem_points'] = $view;

  return $export;
}
