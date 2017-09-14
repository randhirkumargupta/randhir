<?php
/**
 * @file
 * feature_for_tech.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_tech_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'tech';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Tech';
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

  /* Display: Tech leftTop */
  $handler = $view->new_display('block', 'Tech leftTop', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tech leftTop';
  $handler->display->display_options['display_description'] = 'Tech leftTop';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
  /* Field: Content: Kicker */
  $handler->display->display_options['fields']['field_story_kicker_text']['id'] = 'field_story_kicker_text';
  $handler->display->display_options['fields']['field_story_kicker_text']['table'] = 'field_data_field_story_kicker_text';
  $handler->display->display_options['fields']['field_story_kicker_text']['field'] = 'field_story_kicker_text';
  $handler->display->display_options['fields']['field_story_kicker_text']['label'] = '';
  $handler->display->display_options['fields']['field_story_kicker_text']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Field: Short description */
  $handler->display->display_options['fields']['field_story_expert_description']['id'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['table'] = 'field_data_field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['field'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['label'] = '';
  $handler->display->display_options['fields']['field_story_expert_description']['element_label_colon'] = FALSE;
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
  /* Field: Field: Large image */
  $handler->display->display_options['fields']['field_story_large_image']['id'] = 'field_story_large_image';
  $handler->display->display_options['fields']['field_story_large_image']['table'] = 'field_data_field_story_large_image';
  $handler->display->display_options['fields']['field_story_large_image']['field'] = 'field_story_large_image';
  $handler->display->display_options['fields']['field_story_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_large_image']['settings'] = array(
    'image_style' => 'magazine_top_story_483x271',
    'image_link' => '',
  );
  /* Field: Content: Medium image */
  $handler->display->display_options['fields']['field_story_medium_image']['id'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['table'] = 'field_data_field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['field'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_medium_image']['settings'] = array(
    'image_style' => 'magazine_top_three_story_237x133',
    'image_link' => '',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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

  /* Display: Tech photo slider */
  $handler = $view->new_display('block', 'Tech photo slider', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tech gallery';
  $handler->display->display_options['display_description'] = 'Tech photo slider';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Section widget relationship: itg_widget_order_section nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'image_750x363',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Gallery Image (field_gallery_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section widget relationship: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section widget relationship: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'photogallery';
  $handler->display->display_options['filters']['content_type']['group'] = 1;
  /* Filter criterion: Section widget relationship: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget']['group'] = 1;
  /* Filter criterion: Section widget relationship: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '430';

  /* Display: Watch */
  $handler = $view->new_display('block', 'Watch', 'block_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tech Tips';
  $handler->display->display_options['display_description'] = 'Watch';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Section widget relationship: itg_widget_order_section nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: video_duration */
  $handler->display->display_options['fields']['field_video_duration']['id'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['table'] = 'field_data_field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['field'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Field: Small image */
  $handler->display->display_options['fields']['field_story_small_image']['id'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['table'] = 'field_data_field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['field'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_small_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: Section widget relationship: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section widget relationship: Content type */
  $handler->display->display_options['filters']['content_type_1']['id'] = 'content_type_1';
  $handler->display->display_options['filters']['content_type_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['content_type_1']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type_1']['value'] = 'Videogallery';
  $handler->display->display_options['filters']['content_type_1']['group'] = 1;
  /* Filter criterion: Section widget relationship: Widget */
  $handler->display->display_options['filters']['widget_1']['id'] = 'widget_1';
  $handler->display->display_options['filters']['widget_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['widget_1']['field'] = 'widget';
  $handler->display->display_options['filters']['widget_1']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget_1']['group'] = 1;
  /* Filter criterion: Section widget relationship: Category */
  $handler->display->display_options['filters']['cat_id_1']['id'] = 'cat_id_1';
  $handler->display->display_options['filters']['cat_id_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['cat_id_1']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id_1']['value'] = '428';
  $handler->display->display_options['filters']['cat_id_1']['group'] = 1;

  /* Display: byline */
  $handler = $view->new_display('block', 'byline', 'block_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'byline';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Video */
  $handler = $view->new_display('block', 'Video', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Video';
  $handler->display->display_options['display_description'] = 'Video';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Section widget relationship: itg_widget_order_section nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: video_duration */
  $handler->display->display_options['fields']['field_video_duration']['id'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['table'] = 'field_data_field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['field'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Small image */
  $handler->display->display_options['fields']['field_story_small_image']['id'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['table'] = 'field_data_field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['field'] = 'field_story_small_image';
  $handler->display->display_options['fields']['field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_small_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section widget relationship: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section widget relationship: Content type */
  $handler->display->display_options['filters']['content_type_1']['id'] = 'content_type_1';
  $handler->display->display_options['filters']['content_type_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['content_type_1']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type_1']['value'] = 'Videogallery';
  $handler->display->display_options['filters']['content_type_1']['group'] = 1;
  /* Filter criterion: Section widget relationship: Widget */
  $handler->display->display_options['filters']['widget_1']['id'] = 'widget_1';
  $handler->display->display_options['filters']['widget_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['widget_1']['field'] = 'widget';
  $handler->display->display_options['filters']['widget_1']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget_1']['group'] = 1;
  /* Filter criterion: Section widget relationship: Category */
  $handler->display->display_options['filters']['cat_id_1']['id'] = 'cat_id_1';
  $handler->display->display_options['filters']['cat_id_1']['table'] = 'itg_widget_order_section';
  $handler->display->display_options['filters']['cat_id_1']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id_1']['value'] = '443';
  $handler->display->display_options['filters']['cat_id_1']['group'] = 1;

  /* Display: Movie Latest */
  $handler = $view->new_display('block', 'Movie Latest', 'movie_latest');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Movie Latest';
  $handler->display->display_options['display_description'] = 'Movie Latest';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
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
  /* Field: Content: Extra small image */
  $handler->display->display_options['fields']['field_story_extra_small_image']['id'] = 'field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['table'] = 'field_data_field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['field'] = 'field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_small_image']['empty'] = '<img width="88" height="66" class="no-result-image" src="../sites/all/themes/itg/images/dimage_170X127.jpg">';
  $handler->display->display_options['fields']['field_story_extra_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_small_image']['settings'] = array(
    'image_style' => 'widget_very_small',
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
    'image_style' => 'widget_very_small',
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
  $handler->display->display_options['filters']['cat_id']['value'] = '517';
  $handler->display->display_options['filters']['cat_id']['group'] = 1;
  $export['tech'] = $view;

  return $export;
}
