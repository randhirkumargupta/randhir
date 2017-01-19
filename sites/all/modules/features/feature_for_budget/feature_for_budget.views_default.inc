<?php
/**
 * @file
 * feature_for_budget.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_budget_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'budget';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Budget';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Yearender';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
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

  /* Display: Latest */
  $handler = $view->new_display('block', 'Latest', 'budget_election_latest');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest';
  $handler->display->display_options['display_description'] = 'Latest';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '20';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Field: Small image */
  $handler->display->display_options['fields']['field_story_small_image']['id'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['table'] = 'field_data_field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['field'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_small_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'All';
  $handler->display->display_options['filters']['content_type']['group'] = 1;
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget']['group'] = 1;
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '434';
  $handler->display->display_options['filters']['cat_id']['group'] = 1;

  /* Display: Budget top news */
  $handler = $view->new_display('block', 'Budget top news', 'budget_top_news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Budget top news';
  $handler->display->display_options['display_description'] = 'Budget top news';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = '';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['element_label_colon'] = FALSE;
  /* Field: Content: Medium image */
  $handler->display->display_options['fields']['field_story_medium_image']['id'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['table'] = 'field_data_field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['field'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['empty'] = '<img src="../sites/all/themes/itg/images/default_for_all_top.png" width="370" height="208" class=\'no-result-image\'>';
  $handler->display->display_options['fields']['field_story_medium_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_medium_image']['settings'] = array(
    'image_style' => 'anchors_landing',
    'image_link' => '',
  );
  /* Field: Field: Small image */
  $handler->display->display_options['fields']['field_story_small_image']['id'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['table'] = 'field_data_field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['field'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_small_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'All';
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '434';
  $export['budget'] = $view;

  return $export;
}
