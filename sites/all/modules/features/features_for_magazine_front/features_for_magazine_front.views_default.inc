<?php
/**
 * @file
 * features_for_magazine_front.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function features_for_magazine_front_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'latest_issue_magzine';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest issue magzine';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest issue magzine';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  /* Field: Content: Large Cover Image */
  $handler->display->display_options['fields']['field_issue_large_cover_image']['id'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['table'] = 'field_data_field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['field'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_large_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_issue_title']['id'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['field'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['label'] = '';
  $handler->display->display_options['fields']['field_issue_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_title']['settings'] = array(
    'format_type' => 'itg',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Subscribe Now';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage';
  $handler->display->display_options['fields']['nothing']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Title (field_issue_title) */
  $handler->display->display_options['sorts']['field_issue_title_value']['id'] = 'field_issue_title_value';
  $handler->display->display_options['sorts']['field_issue_title_value']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['sorts']['field_issue_title_value']['field'] = 'field_issue_title_value';
  $handler->display->display_options['sorts']['field_issue_title_value']['order'] = 'DESC';
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
    'issue' => 'issue',
  );
  /* Filter criterion: Content: Title (field_issue_title) */
  $handler->display->display_options['filters']['field_issue_title_value']['id'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['filters']['field_issue_title_value']['field'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_issue_title_value']['default_to_date'] = 'Sunday this week';
  $handler->display->display_options['filters']['field_issue_title_value']['year_range'] = '-3:+0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Large Cover Image */
  $handler->display->display_options['fields']['field_issue_large_cover_image']['id'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['table'] = 'field_data_field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['field'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_large_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['settings'] = array(
    'image_style' => 'magazine_top_issue_172x240',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_issue_title']['id'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['field'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['label'] = '';
  $handler->display->display_options['fields']['field_issue_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_title']['settings'] = array(
    'format_type' => 'itg',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Subscribe Now';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'http://subscriptions.intoday.in/subscriptions/itoday/ite_offer_mailer.jsp?source=ITHomepage';
  $handler->display->display_options['fields']['nothing']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_issue_title_1']['id'] = 'field_issue_title_1';
  $handler->display->display_options['fields']['field_issue_title_1']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['fields']['field_issue_title_1']['field'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title_1']['settings'] = array(
    'format_type' => 'itg_y_m_d',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
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
    'issue' => 'issue',
  );
  /* Filter criterion: Content: Title (field_issue_title) */
  $handler->display->display_options['filters']['field_issue_title_value']['id'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['filters']['field_issue_title_value']['field'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['default_date'] = 'now';
  $handler->display->display_options['filters']['field_issue_title_value']['default_to_date'] = 'Sunday this week';
  $handler->display->display_options['filters']['field_issue_title_value']['year_range'] = '-3:+0';
  /* Filter criterion: Content: Title (field_issue_title) */
  $handler->display->display_options['filters']['field_issue_title_value_1']['id'] = 'field_issue_title_value_1';
  $handler->display->display_options['filters']['field_issue_title_value_1']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['filters']['field_issue_title_value_1']['field'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_issue_title_value_1']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_issue_title_value_1']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'magazine';

  /* Display: Right side issue block */
  $handler = $view->new_display('block', 'Right side issue block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'PREVIOUS EDITIONS';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'issue-magazin-row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_issue_title_1']['id'] = 'field_issue_title_1';
  $handler->display->display_options['fields']['field_issue_title_1']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['fields']['field_issue_title_1']['field'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title_1']['label'] = 'YEAR';
  $handler->display->display_options['fields']['field_issue_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_title_1']['settings'] = array(
    'format_type' => 'itg_d_m_y',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Large Cover Image */
  $handler->display->display_options['fields']['field_issue_large_cover_image']['id'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['table'] = 'field_data_field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['field'] = 'field_issue_large_cover_image';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['label'] = '';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_issue_large_cover_image']['alter']['path'] = 'magazine/[field_issue_title_1]';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_large_cover_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_issue_large_cover_image']['settings'] = array(
    'image_style' => 'magazine_rhs_100x140',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['field_issue_title']['id'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['field'] = 'field_issue_title';
  $handler->display->display_options['fields']['field_issue_title']['label'] = '';
  $handler->display->display_options['fields']['field_issue_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue_title']['settings'] = array(
    'format_type' => 'itg',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Title (field_issue_title) */
  $handler->display->display_options['arguments']['field_issue_title_value']['id'] = 'field_issue_title_value';
  $handler->display->display_options['arguments']['field_issue_title_value']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['arguments']['field_issue_title_value']['field'] = 'field_issue_title_value';
  $handler->display->display_options['arguments']['field_issue_title_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_issue_title_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_issue_title_value']['default_argument_options']['code'] = 'if(!empty(arg(1))) {
$val = strtotime(arg(1));
return date(\'Y\', $val);
}elseif(arg(0) == \'magazine\' && empty(arg(1))){
return date(\'Y\');
}
';
  $handler->display->display_options['arguments']['field_issue_title_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_issue_title_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_issue_title_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_issue_title_value']['year_range'] = '-50:+50';
  $handler->display->display_options['arguments']['field_issue_title_value']['granularity'] = 'year';
  $handler->display->display_options['arguments']['field_issue_title_value']['granularity_reset'] = 0;
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
    'issue' => 'issue',
  );
  /* Filter criterion: Content: Title (field_issue_title) */
  $handler->display->display_options['filters']['field_issue_title_value']['id'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['table'] = 'field_data_field_issue_title';
  $handler->display->display_options['filters']['field_issue_title_value']['field'] = 'field_issue_title_value';
  $handler->display->display_options['filters']['field_issue_title_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_issue_title_value']['default_date'] = 'now';
  $export['latest_issue_magzine'] = $view;

  $view = new view();
  $view->name = 'magazine_top_story';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Magazine top story';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
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
  /* Sort criterion: Section wise ordering content: extra */
  $handler->display->display_options['sorts']['extra']['id'] = 'extra';
  $handler->display->display_options['sorts']['extra']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['extra']['field'] = 'extra';
  /* Contextual filter: Field: DOB (field_story_issue_date) */
  $handler->display->display_options['arguments']['field_story_issue_date_value']['id'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['table'] = 'field_data_field_story_issue_date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['field'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity_reset'] = 0;
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
    'story' => 'story',
  );
  /* Filter criterion: Content: Issue based story (field_story_magazine_story_issue) */
  $handler->display->display_options['filters']['field_story_magazine_story_issue_value']['id'] = 'field_story_magazine_story_issue_value';
  $handler->display->display_options['filters']['field_story_magazine_story_issue_value']['table'] = 'field_data_field_story_magazine_story_issue';
  $handler->display->display_options['filters']['field_story_magazine_story_issue_value']['field'] = 'field_story_magazine_story_issue_value';
  $handler->display->display_options['filters']['field_story_magazine_story_issue_value']['value'] = array(
    'magazine_issue_story' => 'magazine_issue_story',
  );
  /* Filter criterion: Field: DOB (field_story_issue_date) */
  $handler->display->display_options['filters']['field_story_issue_date_value']['id'] = 'field_story_issue_date_value';
  $handler->display->display_options['filters']['field_story_issue_date_value']['table'] = 'field_data_field_story_issue_date';
  $handler->display->display_options['filters']['field_story_issue_date_value']['field'] = 'field_story_issue_date_value';
  $handler->display->display_options['filters']['field_story_issue_date_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_story_issue_date_value']['year_range'] = '-100:+100';
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'issue_magazin_widget';

  /* Display: Magzine bottom story block */
  $handler = $view->new_display('block', 'Magzine bottom story block', 'block');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'magazine_top_three_story_237x133',
    'image_link' => 'content',
  );
  /* Field: Global: Dynamic Clone Link */
  $handler->display->display_options['fields']['dynamic_clone_link']['id'] = 'dynamic_clone_link';
  $handler->display->display_options['fields']['dynamic_clone_link']['table'] = 'views';
  $handler->display->display_options['fields']['dynamic_clone_link']['field'] = 'dynamic_clone_link';
  $handler->display->display_options['fields']['dynamic_clone_link']['label'] = '';
  $handler->display->display_options['fields']['dynamic_clone_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dynamic_clone_link']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '75';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="magazin-post">
[field_story_extra_large_image]
<h3>[dynamic_clone_link]</h3>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: DOB (field_story_issue_date) */
  $handler->display->display_options['arguments']['field_story_issue_date_value']['id'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['table'] = 'field_data_field_story_issue_date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['field'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['year_range'] = '-50:+50';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity_reset'] = 0;

  /* Display: Magzine top story block */
  $handler = $view->new_display('block', 'Magzine top story block', 'block_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'magazine_top_story_483x271',
    'image_link' => 'content',
  );
  /* Field: Global: Dynamic Clone Link */
  $handler->display->display_options['fields']['dynamic_clone_link']['id'] = 'dynamic_clone_link';
  $handler->display->display_options['fields']['dynamic_clone_link']['table'] = 'views';
  $handler->display->display_options['fields']['dynamic_clone_link']['field'] = 'dynamic_clone_link';
  $handler->display->display_options['fields']['dynamic_clone_link']['label'] = '';
  $handler->display->display_options['fields']['dynamic_clone_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['dynamic_clone_link']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="magazin-post">
[field_story_extra_large_image]
<h2>[dynamic_clone_link]</h2>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: DOB (field_story_issue_date) */
  $handler->display->display_options['arguments']['field_story_issue_date_value']['id'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['table'] = 'field_data_field_story_issue_date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['field'] = 'field_story_issue_date_value';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['year_range'] = '-50:+50';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity'] = 'day';
  $handler->display->display_options['arguments']['field_story_issue_date_value']['granularity_reset'] = 0;
  $export['magazine_top_story'] = $view;

  return $export;
}
