<?php
/**
 * @file
 * features_for_print_team.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function features_for_print_team_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'manage_print_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Manage Print Team';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Manage Print Team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    11 => '11',
    6 => '6',
    20 => '20',
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'changed' => 'changed',
    'created' => 'created',
    'php' => 'php',
    'view_node' => 'nothing',
    'edit_node' => 'nothing',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'changed' => array(
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
    'php' => array(
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
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Idea Headline';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Modified On';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Content: Idea Status */
  $handler->display->display_options['fields']['field_pti_idea_status']['id'] = 'field_pti_idea_status';
  $handler->display->display_options['fields']['field_pti_idea_status']['table'] = 'field_data_field_pti_idea_status';
  $handler->display->display_options['fields']['field_pti_idea_status']['field'] = 'field_pti_idea_status';
  $handler->display->display_options['fields']['field_pti_idea_status']['label'] = 'Status';
  $handler->display->display_options['fields']['field_pti_idea_status']['empty'] = 'In Progress';
  $handler->display->display_options['fields']['field_pti_idea_status']['type'] = 'text_default';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Idea Actions';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php echo itg_print_team_idea_actions($row->nid); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Issue */
  $handler->display->display_options['fields']['field_pti_issue']['id'] = 'field_pti_issue';
  $handler->display->display_options['fields']['field_pti_issue']['table'] = 'field_data_field_pti_issue';
  $handler->display->display_options['fields']['field_pti_issue']['field'] = 'field_pti_issue';
  $handler->display->display_options['fields']['field_pti_issue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_pti_issue']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_pti_issue']['settings'] = array(
    'link' => 0,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Issue';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
if($data->field_field_pti_issue[0][\'raw\'][\'entity\']->title) {
echo date(\'d/m/Y\', strtotime($data->field_field_pti_issue[0][\'raw\'][\'entity\']->title)) ;
} else {
echo \'N/A\';
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Content: Magazine */
  $handler->display->display_options['fields']['field_pti_magazine']['id'] = 'field_pti_magazine';
  $handler->display->display_options['fields']['field_pti_magazine']['table'] = 'field_data_field_pti_magazine';
  $handler->display->display_options['fields']['field_pti_magazine']['field'] = 'field_pti_magazine';
  $handler->display->display_options['fields']['field_pti_magazine']['empty'] = 'NA';
  $handler->display->display_options['fields']['field_pti_magazine']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View Idea';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '<span class="view-link">[view_node]</span>';
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
    'print_team_integration' => 'print_team_integration',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'manage-print-team';
  $export['manage_print_team'] = $view;

  return $export;
}
