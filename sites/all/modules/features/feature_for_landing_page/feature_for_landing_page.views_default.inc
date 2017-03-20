<?php
/**
 * @file
 * feature_for_landing_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_landing_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'anchor_landing_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Anchor Landing Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-firstlast'] = 1;
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['style_options']['custom-class-columncount-prefix'] = 'anchor-list-col';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'anchors_landing',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Occupation (field_celebrity_pro_occupation) */
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['id'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['table'] = 'field_data_field_celebrity_pro_occupation';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['field'] = 'field_celebrity_pro_occupation_tid';
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['value'] = array(
    0 => '399',
  );
  $handler->display->display_options['filters']['field_celebrity_pro_occupation_tid']['vocabulary'] = 'itg_occupation';

  /* Display: Anchor Landing , Anchor Description Block */
  $handler = $view->new_display('block', 'Anchor Landing , Anchor Description Block', 'block');
  $handler->display->display_options['display_description'] = 'Anchor Landing , Anchor Description Block';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'anchors_landing',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $export['anchor_landing_page'] = $view;

  $view = new view();
  $view->name = 'programme_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programme Content';
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'customstyle';
  /* Relationship: Section wise ordering content: itg_widget_order nid Title */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_widget_order';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
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
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'videogallery';

  /* Display: Programmes videos */
  $handler = $view->new_display('block', 'Programmes videos', 'block');
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M, Y';
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
  /* Field: Section wise ordering content: Category */
  $handler->display->display_options['fields']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['fields']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['fields']['cat_id']['field'] = 'cat_id';
  /* Field: Section wise ordering content: weight */
  $handler->display->display_options['fields']['weight']['id'] = 'weight';
  $handler->display->display_options['fields']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['fields']['weight']['field'] = 'weight';
  $handler->display->display_options['fields']['weight']['separator'] = '';
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
  $export['programme_content'] = $view;

  $view = new view();
  $view->name = 'programmes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'programmes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'programmes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
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

  /* Display: Programmes */
  $handler = $view->new_display('page', 'Programmes', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Field: Category Icon */
  $handler->display->display_options['fields']['field_sponser_logo']['id'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['table'] = 'field_data_field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['field'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponser_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponser_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponser_logo']['settings'] = array(
    'image_style' => 'widget_very_small',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Program timing in days */
  $handler->display->display_options['fields']['field_program_timing_in_days']['id'] = 'field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['table'] = 'field_data_field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['field'] = 'field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['label'] = 'Title';
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
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Time Period */
  $handler->display->display_options['fields']['field_time_period']['id'] = 'field_time_period';
  $handler->display->display_options['fields']['field_time_period']['table'] = 'field_data_field_time_period';
  $handler->display->display_options['fields']['field_time_period']['field'] = 'field_time_period';
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
  $handler->display->display_options['path'] = 'programmes';

  /* Display: RHS Program Block */
  $handler = $view->new_display('block', 'RHS Program Block', 'rhs_programmes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
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
  /* Field: Field: Category Icon */
  $handler->display->display_options['fields']['field_sponser_logo']['id'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['table'] = 'field_data_field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['field'] = 'field_sponser_logo';
  $handler->display->display_options['fields']['field_sponser_logo']['label'] = '';
  $handler->display->display_options['fields']['field_sponser_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponser_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_sponser_logo']['settings'] = array(
    'image_style' => 'widget_very_small',
    'image_link' => '',
  );
  /* Field: Taxonomy term: Program timing in days */
  $handler->display->display_options['fields']['field_program_timing_in_days']['id'] = 'field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['table'] = 'field_data_field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['field'] = 'field_program_timing_in_days';
  $handler->display->display_options['fields']['field_program_timing_in_days']['label'] = 'Timing';
  /* Field: Taxonomy term: Time Period */
  $handler->display->display_options['fields']['field_time_period']['id'] = 'field_time_period';
  $handler->display->display_options['fields']['field_time_period']['table'] = 'field_data_field_time_period';
  $handler->display->display_options['fields']['field_time_period']['field'] = 'field_time_period';
  $export['programmes'] = $view;

  return $export;
}
