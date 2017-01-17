<?php
/**
 * @file
 * feature_live_tv_front_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_live_tv_front_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'live_tv_programs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Live tv programs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Live Tv';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  /* Field: Field: Category Icon */
  $handler->display->display_options['fields']['field_sponser_logo']['id'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['table'] = 'field_data_field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['field'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponser_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponser_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponser_logo']['settings'] = array(
    'image_style' => 'widget_very_small',
    'image_link' => 'content',
  );
  /* Field: Taxonomy term: Display Title */
  $handler->display->display_options['fields']['field_cm_display_title']['id'] = 'field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['table'] = 'field_data_field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['field'] = 'field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_display_title']['element_label_colon'] = FALSE;
  /* Field: Field: City */
  $handler->display->display_options['fields']['field_user_city']['id'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['table'] = 'field_data_field_user_city';
  $handler->display->display_options['fields']['field_user_city']['field'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['label'] = '';
  $handler->display->display_options['fields']['field_user_city']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Sort criterion: Taxonomy vocabulary: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'category_management' => 'category_management',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;

  /* Display: Live Tv */
  $handler = $view->new_display('page', 'Live Tv', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Relationship: Taxonomy term: Content using Section */
  $handler->display->display_options['relationships']['reverse_field_story_category_node']['id'] = 'reverse_field_story_category_node';
  $handler->display->display_options['relationships']['reverse_field_story_category_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_story_category_node']['field'] = 'reverse_field_story_category_node';
  $handler->display->display_options['relationships']['reverse_field_story_category_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Display Title */
  $handler->display->display_options['fields']['field_cm_display_title']['id'] = 'field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['table'] = 'field_data_field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['field'] = 'field_cm_display_title';
  $handler->display->display_options['fields']['field_cm_display_title']['label'] = '';
  $handler->display->display_options['fields']['field_cm_display_title']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'category_management' => 'category_management',
  );
  $handler->display->display_options['filters']['machine_name']['group'] = 1;
  $handler->display->display_options['path'] = 'livetv';
  $export['live_tv_programs'] = $view;

  $view = new view();
  $view->name = 'programme_content_live_tv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programme Content live tv';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'customstyle';
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
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'videogallery';

  /* Display: Programmes videos */
  $handler = $view->new_display('block', 'Programmes videos', 'block');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Section wise ordering content: itg_widget_order nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Section wise ordering content: Category */
  $handler->display->display_options['fields']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['fields']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['fields']['cat_id']['field'] = 'cat_id';
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
  $handler->display->display_options['fields']['created']['date_format'] = 'itg_day_date';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '65';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Section wise ordering content: Category */
  $handler->display->display_options['arguments']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['arguments']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['arguments']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['arguments']['cat_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['cat_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['cat_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cat_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cat_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cat_id']['limit'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'videogallery';
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';

  /* Display: latest video live tv page */
  $handler = $view->new_display('block', 'latest video live tv page', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest Video';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Section wise ordering content: itg_widget_order nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = '';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['alter']['text'] = '[field_story_category-tid] ';
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '65';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid_1']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Section wise ordering content: Category */
  $handler->display->display_options['arguments']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['arguments']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['arguments']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['arguments']['cat_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['cat_id']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['cat_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['cat_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['cat_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['cat_id']['limit'] = '0';
  $export['programme_content_live_tv'] = $view;

  return $export;
}
