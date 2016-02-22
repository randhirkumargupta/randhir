<?php
/**
 * @file
 * feature_category_management.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_category_management_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'category_manager_dev';
  $view->description = 'Category listing page';
  $view->tag = 'default';
  $view->base_table = 'itg_category_manager';
  $view->human_name = 'Category Manager';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Category Manager';
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
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['pager_position'] = 'bottom';
  $handler->display->display_options['pager']['options']['skip_empty_pages'] = 0;
  $handler->display->display_options['style_plugin'] = 'tree';
  $handler->display->display_options['style_options']['main_field'] = 'tid';
  $handler->display->display_options['style_options']['parent_field'] = 'tid_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<a href="./admin/structure/taxonomy/category_management/add">+ Add Category</a>';
  $handler->display->display_options['header']['area_1']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="itg-section">Section</div>
      <div class="itg-category">Category</div>
      <div class="itg-sub-category">Sub Category</div>
      <div class="itg-sub-sub-category">Sub Sub Category</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Category Manager: ITG */
  $handler->display->display_options['relationships']['tid']['id'] = 'tid';
  $handler->display->display_options['relationships']['tid']['table'] = 'itg_category_manager';
  $handler->display->display_options['relationships']['tid']['field'] = 'tid';
  $handler->display->display_options['relationships']['tid']['label'] = 'Taxonomy';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'tid';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_class'] = 'term-name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  /* Field: Category Manager: created field */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'itg_category_manager';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['element_type'] = 'div';
  $handler->display->display_options['fields']['created']['element_class'] = 'created-date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Category Manager: changed field */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'itg_category_manager';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_type'] = 'div';
  $handler->display->display_options['fields']['changed']['element_class'] = 'changed-date';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd-m-Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Category Manager: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'itg_category_manager';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_class'] = 'term-status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'active-inactive';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'Term ID without relation';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  /* Field: Taxonomy term: Term edit link */
  $handler->display->display_options['fields']['edit_term']['id'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['edit_term']['field'] = 'edit_term';
  $handler->display->display_options['fields']['edit_term']['relationship'] = 'tid';
  $handler->display->display_options['fields']['edit_term']['label'] = '';
  $handler->display->display_options['fields']['edit_term']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_term']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['edit_term']['text'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="category-manager-details">
<div class="cmd-heading"><i class="fa fa-minus-square-o"></i><i class="fa fa-plus-square-o"></i> [name]</div>
<div class="cmd-detail">
<span>[created]</span>
<span>[changed]</span>
<span>[status]</span>
[edit_term]
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Category Manager: created field */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'itg_category_manager';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Field: Publish Time (field_publish_time) */
  $handler->display->display_options['arguments']['field_publish_time_value']['id'] = 'field_publish_time_value';
  $handler->display->display_options['arguments']['field_publish_time_value']['table'] = 'field_data_field_publish_time';
  $handler->display->display_options['arguments']['field_publish_time_value']['field'] = 'field_publish_time_value';
  $handler->display->display_options['arguments']['field_publish_time_value']['relationship'] = 'tid';
  $handler->display->display_options['arguments']['field_publish_time_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_publish_time_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_publish_time_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_publish_time_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_publish_time_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_publish_time_value']['year_range'] = '2015:2030';
  $handler->display->display_options['arguments']['field_publish_time_value']['granularity_reset'] = 0;
  $handler->display->display_options['arguments']['field_publish_time_value']['use_fromto'] = 'no';
  /* Filter criterion: Taxonomy term: Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'tid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'keyword';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['relationship'] = 'tid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    4 => '4',
  );
  /* Filter criterion: Taxonomy term: Content Type (field_cm_select_type) */
  $handler->display->display_options['filters']['field_cm_select_type_value']['id'] = 'field_cm_select_type_value';
  $handler->display->display_options['filters']['field_cm_select_type_value']['table'] = 'field_data_field_cm_select_type';
  $handler->display->display_options['filters']['field_cm_select_type_value']['field'] = 'field_cm_select_type_value';
  $handler->display->display_options['filters']['field_cm_select_type_value']['relationship'] = 'tid';
  $handler->display->display_options['filters']['field_cm_select_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cm_select_type_value']['expose']['operator_id'] = 'field_cm_select_type_value_op';
  $handler->display->display_options['filters']['field_cm_select_type_value']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['field_cm_select_type_value']['expose']['operator'] = 'field_cm_select_type_value_op';
  $handler->display->display_options['filters']['field_cm_select_type_value']['expose']['identifier'] = 'field_cm_select_type_value';
  $handler->display->display_options['filters']['field_cm_select_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );
  /* Filter criterion: Category Manager: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'itg_category_manager';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'in';
  $handler->display->display_options['filters']['status']['value'] = array();
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    5 => 0,
    8 => 0,
    20 => 0,
    6 => 0,
    10 => 0,
    19 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    15 => 0,
    18 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'category-manager';
  $export['category_manager_dev'] = $view;

  return $export;
}
