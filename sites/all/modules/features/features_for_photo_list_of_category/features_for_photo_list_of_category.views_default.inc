<?php
/**
 * @file
 * features_for_photo_list_of_category.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function features_for_photo_list_of_category_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'photo_list_of_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'photo list of category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'photo list of category';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Extra small image */
  $handler->display->display_options['fields']['field_story_extra_small_image']['id'] = 'field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['table'] = 'field_data_field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['field'] = 'field_story_extra_small_image';
  $handler->display->display_options['fields']['field_story_extra_small_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_small_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_small_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_small_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Gallery Image (field_gallery_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  $handler->display->display_options['fields']['delta']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['delta']['format_plural_singular'] = '1 image';
  $handler->display->display_options['fields']['delta']['format_plural_plural'] = '@count images';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'itg';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Section (field_story_category) */
  $handler->display->display_options['arguments']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['arguments']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['arguments']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['arguments']['field_story_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_category_tid']['summary_options']['items_per_page'] = '25';
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
    'photogallery' => 'photogallery',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['photo_list_of_category'] = $view;

  $view = new view();
  $view->name = 'video_list_of_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video list of category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Result Found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
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
  /* Field: Content: video_duration */
  $handler->display->display_options['fields']['field_video_duration']['id'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['table'] = 'field_data_field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['field'] = 'field_video_duration';
  $handler->display->display_options['fields']['field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'itg';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Field: Short Description */
  $handler->display->display_options['fields']['field_story_expert_name']['id'] = 'field_story_expert_name';
  $handler->display->display_options['fields']['field_story_expert_name']['table'] = 'field_data_field_story_expert_name';
  $handler->display->display_options['fields']['field_story_expert_name']['field'] = 'field_story_expert_name';
  $handler->display->display_options['fields']['field_story_expert_name']['label'] = '';
  $handler->display->display_options['fields']['field_story_expert_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Section wise ordering content: Category */
  $handler->display->display_options['sorts']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['sorts']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['sorts']['cat_id']['order'] = 'DESC';
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
    'videogallery' => 'videogallery',
  );
  /* Filter criterion: Content: Section (field_story_category) */
  $handler->display->display_options['filters']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['filters']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator_id'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['label'] = 'Section (field_story_category)';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['identifier'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_story_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['video_list_of_category'] = $view;

  return $export;
}
