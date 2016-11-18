<?php
/**
 * @file
 * feature_for_live_tv_front_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_live_tv_front_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'live_tv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'live tv';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Live TV :  Most Popular Video';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_ads_ad_code' => 'field_ads_ad_code',
    'field_ads_header_script' => 'field_ads_header_script',
    'field_story_expert_description' => 'field_story_expert_description',
    'field_mega_review_description' => 'field_mega_review_description',
    'field_recipe_ingredients' => 'field_recipe_ingredients',
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
    'field_ads_ad_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ads_header_script' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_expert_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mega_review_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recipe_ingredients' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Ad Code */
  $handler->display->display_options['fields']['field_ads_ad_code']['id'] = 'field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['table'] = 'field_data_field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['field'] = 'field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['label'] = 'Web';
  $handler->display->display_options['fields']['field_ads_ad_code']['element_label_colon'] = FALSE;
  /* Field: Content: Header script */
  $handler->display->display_options['fields']['field_ads_header_script']['id'] = 'field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['table'] = 'field_data_field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['field'] = 'field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['label'] = 'Web Mobil';
  $handler->display->display_options['fields']['field_ads_header_script']['element_label_colon'] = FALSE;
  /* Field: Field: Content */
  $handler->display->display_options['fields']['field_story_expert_description']['id'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['table'] = 'field_data_field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['field'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['label'] = 'iOS';
  $handler->display->display_options['fields']['field_story_expert_description']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_mega_review_description']['id'] = 'field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['table'] = 'field_data_field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['field'] = 'field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['label'] = 'Android';
  $handler->display->display_options['fields']['field_mega_review_description']['element_label_colon'] = FALSE;
  /* Field: Content: Window */
  $handler->display->display_options['fields']['field_recipe_ingredients']['id'] = 'field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['table'] = 'field_data_field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['field'] = 'field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['element_label_colon'] = FALSE;
  /* Field: Content: device */
  $handler->display->display_options['fields']['field_live_tv_device']['id'] = 'field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['table'] = 'field_data_field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['field'] = 'field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['label'] = 'Device';
  $handler->display->display_options['fields']['field_live_tv_device']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_live_tv_device']['delta_offset'] = '0';
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

  /* Display: Aaj tak live tv */
  $handler = $view->new_display('page', 'Aaj tak live tv', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Ad Code */
  $handler->display->display_options['fields']['field_ads_ad_code']['id'] = 'field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['table'] = 'field_data_field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['field'] = 'field_ads_ad_code';
  $handler->display->display_options['fields']['field_ads_ad_code']['label'] = '';
  $handler->display->display_options['fields']['field_ads_ad_code']['element_label_colon'] = FALSE;
  /* Field: Content: Header script */
  $handler->display->display_options['fields']['field_ads_header_script']['id'] = 'field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['table'] = 'field_data_field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['field'] = 'field_ads_header_script';
  $handler->display->display_options['fields']['field_ads_header_script']['label'] = 'Web Mobil';
  $handler->display->display_options['fields']['field_ads_header_script']['element_label_colon'] = FALSE;
  /* Field: Field: Content */
  $handler->display->display_options['fields']['field_story_expert_description']['id'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['table'] = 'field_data_field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['field'] = 'field_story_expert_description';
  $handler->display->display_options['fields']['field_story_expert_description']['label'] = 'iOS';
  $handler->display->display_options['fields']['field_story_expert_description']['element_label_colon'] = FALSE;
  /* Field: Field: Description */
  $handler->display->display_options['fields']['field_mega_review_description']['id'] = 'field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['table'] = 'field_data_field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['field'] = 'field_mega_review_description';
  $handler->display->display_options['fields']['field_mega_review_description']['label'] = 'Android';
  $handler->display->display_options['fields']['field_mega_review_description']['element_label_colon'] = FALSE;
  /* Field: Content: Window */
  $handler->display->display_options['fields']['field_recipe_ingredients']['id'] = 'field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['table'] = 'field_data_field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['field'] = 'field_recipe_ingredients';
  $handler->display->display_options['fields']['field_recipe_ingredients']['element_label_colon'] = FALSE;
  /* Field: Content: device */
  $handler->display->display_options['fields']['field_live_tv_device']['id'] = 'field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['table'] = 'field_data_field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['field'] = 'field_live_tv_device';
  $handler->display->display_options['fields']['field_live_tv_device']['label'] = 'Device';
  $handler->display->display_options['fields']['field_live_tv_device']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_live_tv_device']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'live_tv_integration' => 'live_tv_integration',
  );
  /* Filter criterion: Content: device (field_live_tv_device) */
  $handler->display->display_options['filters']['field_live_tv_device_value']['id'] = 'field_live_tv_device_value';
  $handler->display->display_options['filters']['field_live_tv_device_value']['table'] = 'field_data_field_live_tv_device';
  $handler->display->display_options['filters']['field_live_tv_device_value']['field'] = 'field_live_tv_device_value';
  $handler->display->display_options['filters']['field_live_tv_device_value']['value'] = array(
    'Web' => 'Web',
  );
  $handler->display->display_options['path'] = 'live-tv';

  /* Display: Live tv */
  $handler = $view->new_display('block', 'Live tv', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'live tv  video in block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_ads_ad_code' => 'field_ads_ad_code',
    'field_ads_header_script' => 'field_ads_header_script',
    'field_story_expert_description' => 'field_story_expert_description',
    'field_mega_review_description' => 'field_mega_review_description',
    'field_recipe_ingredients' => 'field_recipe_ingredients',
    'field_live_tv_device' => 'field_live_tv_device',
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
    'field_ads_ad_code' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ads_header_script' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_expert_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mega_review_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recipe_ingredients' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_live_tv_device' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: device (field_live_tv_device) */
  $handler->display->display_options['arguments']['field_live_tv_device_value']['id'] = 'field_live_tv_device_value';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['table'] = 'field_data_field_live_tv_device';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['field'] = 'field_live_tv_device_value';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_live_tv_device_value']['limit'] = '0';
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
    'live_tv_integration' => 'live_tv_integration',
  );

  /* Display: live tv : Latest Video */
  $handler = $view->new_display('block', 'live tv : Latest Video', 'live_tv_latest_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Live tv: latest video';
  $handler->display->display_options['display_description'] = 'live tv : Latest Video';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
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
  /* Field: Content: primary category */
  $handler->display->display_options['fields']['field_primary_category']['id'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['field'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['label'] = '';
  $handler->display->display_options['fields']['field_primary_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_primary_category']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['empty'] = 'notfound';
  $handler->display->display_options['fields']['field_story_extra_large_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'live_tv_latest_video',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Anchor */
  $handler->display->display_options['fields']['field_video_anchor']['id'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['table'] = 'field_data_field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['field'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['label'] = '';
  $handler->display->display_options['fields']['field_video_anchor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_anchor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'itg_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
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
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'videogallery';
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '425';
  $handler->display->display_options['block_description'] = 'live tv: Jarur Dekhe';

  /* Display: live tv :  Latest Program */
  $handler = $view->new_display('block', 'live tv :  Latest Program', 'live_tv_latest_program');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Live tv: Latest Program';
  $handler->display->display_options['display_description'] = 'live tv : Latest Program';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
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
  /* Field: Content: primary category */
  $handler->display->display_options['fields']['field_primary_category']['id'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['field'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['label'] = '';
  $handler->display->display_options['fields']['field_primary_category']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['empty'] = 'notfound';
  $handler->display->display_options['fields']['field_story_extra_large_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'live_tv_latest_video',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Anchor */
  $handler->display->display_options['fields']['field_video_anchor']['id'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['table'] = 'field_data_field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['field'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['label'] = '';
  $handler->display->display_options['fields']['field_video_anchor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_anchor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'itg_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
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
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'videogallery';
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '639';
  $handler->display->display_options['block_description'] = 'Live tv: Aapke Liye';

  /* Display: Live TV :  Most Popular Video */
  $handler = $view->new_display('block', 'Live TV :  Most Popular Video', 'live_tv_most_popular_video');
  $handler->display->display_options['display_description'] = 'Live TV :  Most Popular Video';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: primary category */
  $handler->display->display_options['fields']['field_primary_category']['id'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['field'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['label'] = '';
  $handler->display->display_options['fields']['field_primary_category']['element_label_colon'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['empty'] = 'notfound';
  $handler->display->display_options['fields']['field_story_extra_large_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'live_tv_latest_video',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Anchor */
  $handler->display->display_options['fields']['field_video_anchor']['id'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['table'] = 'field_data_field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['field'] = 'field_video_anchor';
  $handler->display->display_options['fields']['field_video_anchor']['label'] = '';
  $handler->display->display_options['fields']['field_video_anchor']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_anchor']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'itg_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
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
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videogallery' => 'videogallery',
  );
  $handler->display->display_options['block_description'] = 'Live TV :  Anya Khabre';
  $export['live_tv'] = $view;

  return $export;
}
