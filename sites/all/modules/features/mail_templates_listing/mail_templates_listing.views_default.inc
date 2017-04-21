<?php
/**
 * @file
 * mail_templates_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mail_templates_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mail_templates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mail Templates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mail Templates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Action';
  /* Field: Content: CMS Status */
  $handler->display->display_options['fields']['field_cms_status']['id'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['table'] = 'field_data_field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['field'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['label'] = '';
  $handler->display->display_options['fields']['field_cms_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cms_status']['element_label_colon'] = FALSE;
  /* Field: Content: New Task Status */
  $handler->display->display_options['fields']['field_new_task_status']['id'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['table'] = 'field_data_field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['field'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['label'] = '';
  $handler->display->display_options['fields']['field_new_task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_task_status']['element_label_colon'] = FALSE;
  /* Field: Content: UGC Comments Status */
  $handler->display->display_options['fields']['field_ugc_comments_status']['id'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['table'] = 'field_data_field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['field'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['label'] = '';
  $handler->display->display_options['fields']['field_ugc_comments_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ugc_comments_status']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_cms_status]
[field_new_task_status]
[field_ugc_comments_status]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_mail_template_category']['id'] = 'field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['table'] = 'field_data_field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['field'] = 'field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['label'] = 'Template Category';
  $handler->display->display_options['fields']['field_mail_template_category']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: CMS mail template category (field_cms_mail_template_category) */
  $handler->display->display_options['sorts']['field_cms_mail_template_category_value']['id'] = 'field_cms_mail_template_category_value';
  $handler->display->display_options['sorts']['field_cms_mail_template_category_value']['table'] = 'field_data_field_cms_mail_template_category';
  $handler->display->display_options['sorts']['field_cms_mail_template_category_value']['field'] = 'field_cms_mail_template_category_value';
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
    'mail_templates' => 'mail_templates',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Mail Templates Category */
  $handler->display->display_options['fields']['field_mail_templates_category']['id'] = 'field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['table'] = 'field_data_field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['field'] = 'field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['label'] = 'Mail Templates';
  $handler->display->display_options['fields']['field_mail_templates_category']['element_label_colon'] = FALSE;
  /* Field: Content: CMS Status */
  $handler->display->display_options['fields']['field_cms_status']['id'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['table'] = 'field_data_field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['field'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['label'] = '';
  $handler->display->display_options['fields']['field_cms_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cms_status']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cms_status']['alter']['text'] = '[field_cms_status] ([field_cms_mail_template_category])';
  $handler->display->display_options['fields']['field_cms_status']['element_label_colon'] = FALSE;
  /* Field: Content: New Task Status */
  $handler->display->display_options['fields']['field_new_task_status']['id'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['table'] = 'field_data_field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['field'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['label'] = '';
  $handler->display->display_options['fields']['field_new_task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_task_status']['element_label_colon'] = FALSE;
  /* Field: Content: UGC Comments Status */
  $handler->display->display_options['fields']['field_ugc_comments_status']['id'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['table'] = 'field_data_field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['field'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['label'] = '';
  $handler->display->display_options['fields']['field_ugc_comments_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ugc_comments_status']['element_label_colon'] = FALSE;
  /* Field: Content: Ask an Expert Case */
  $handler->display->display_options['fields']['field_ask_an_expert_case']['id'] = 'field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['table'] = 'field_data_field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['field'] = 'field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['label'] = '';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ask_an_expert_case']['element_label_colon'] = FALSE;
  /* Field: Content: Product Expiration Status */
  $handler->display->display_options['fields']['field_product_expiration_status']['id'] = 'field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['table'] = 'field_data_field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['field'] = 'field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['label'] = '';
  $handler->display->display_options['fields']['field_product_expiration_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_expiration_status']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Template Status';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_cms_status]
[field_new_task_status]
[field_ugc_comments_status]
[field_ask_an_expert_case]
[field_product_expiration_status]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Action';
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
    'mail_templates' => 'mail_templates',
  );
  /* Filter criterion: Content: Mail Templates Category (field_mail_templates_category) */
  $handler->display->display_options['filters']['field_mail_templates_category_value']['id'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['table'] = 'field_data_field_mail_templates_category';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['field'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['operator_id'] = 'field_mail_templates_category_value_op';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['label'] = 'Mail Templates';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['operator'] = 'field_mail_templates_category_value_op';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['identifier'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'mail-templates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mail Templates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-left-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['mail_templates'] = $view;

  return $export;
}
