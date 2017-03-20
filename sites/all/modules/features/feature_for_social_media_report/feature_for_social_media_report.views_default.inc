<?php
/**
 * @file
 * feature_for_social_media_report.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_social_media_report_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'social_media_report';
  $view->description = 'Social media team can browse content for social media integration.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Social Media Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Social Media Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    10 => '10',
    23 => '23',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '3';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_story_category' => 'field_story_category',
    'created' => 'created',
    'nid' => 'nid',
    'nothing' => 'nothing',
    'view_node' => 'view_node',
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
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_story_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result found!';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Social Media Logs: relate a node to social media post */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
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
  /* Filter criterion: Social Media Logs: Scheduled Time */
  $handler->display->display_options['filters']['scheduled_time']['id'] = 'scheduled_time';
  $handler->display->display_options['filters']['scheduled_time']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['filters']['scheduled_time']['field'] = 'scheduled_time';
  $handler->display->display_options['filters']['scheduled_time']['operator'] = 'between';
  $handler->display->display_options['filters']['scheduled_time']['group'] = 1;
  $handler->display->display_options['filters']['scheduled_time']['exposed'] = TRUE;
  $handler->display->display_options['filters']['scheduled_time']['expose']['operator_id'] = 'scheduled_time_op';
  $handler->display->display_options['filters']['scheduled_time']['expose']['label'] = 'Promoted on';
  $handler->display->display_options['filters']['scheduled_time']['expose']['operator'] = 'scheduled_time_op';
  $handler->display->display_options['filters']['scheduled_time']['expose']['identifier'] = 'scheduled_time';
  $handler->display->display_options['filters']['scheduled_time']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Section (field_story_category) */
  $handler->display->display_options['filters']['field_story_category_tid']['id'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['filters']['field_story_category_tid']['field'] = 'field_story_category_tid';
  $handler->display->display_options['filters']['field_story_category_tid']['value'] = '';
  $handler->display->display_options['filters']['field_story_category_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_story_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['operator_id'] = 'field_story_category_tid_op';
  $handler->display->display_options['filters']['field_story_category_tid']['expose']['label'] = 'Category';
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
  );
  $handler->display->display_options['filters']['field_story_category_tid']['vocabulary'] = 'category_management';
  $handler->display->display_options['filters']['field_story_category_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Content Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'story' => 'story',
    'videogallery' => 'videogallery',
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Schedule date &amp; time (field_story_schedule_date_time) */
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['id'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['table'] = 'field_data_field_story_schedule_date_time';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['field'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['group'] = 1;
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['expose']['operator_id'] = 'field_story_schedule_date_time_value_op';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['expose']['label'] = 'Schedule date &amp; time (field_story_schedule_date_time)';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['expose']['operator'] = 'field_story_schedule_date_time_value_op';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['expose']['identifier'] = 'field_story_schedule_date_time_value';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['granularity'] = 'second';
  $handler->display->display_options['filters']['field_story_schedule_date_time_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'social_media_report');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Content ID';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Social Media Logs: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = 'Promoted By';
  /* Field: Social Media Logs: Count Facebook Promote */
  $handler->display->display_options['fields']['count_fb_promote']['id'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_promote']['field'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['label'] = 'FB Promote';
  /* Field: Social Media Logs: Count Twitter Promote */
  $handler->display->display_options['fields']['count_twitter_promote']['id'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_promote']['field'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['label'] = 'Twitter Promote';
  /* Field: Social Media Logs: Count facebook commnet */
  $handler->display->display_options['fields']['count_fb_comment']['id'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_comment']['field'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['label'] = 'FB Commnet';
  /* Field: Social Media Logs: Count facebook like */
  $handler->display->display_options['fields']['count_fb_like']['id'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_like']['field'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['label'] = 'FB Likes';
  /* Field: Social Media Logs: Count facebook Share */
  $handler->display->display_options['fields']['count_fb_share']['id'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_share']['field'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['label'] = 'FB Share';
  /* Field: Social Media Logs: Count Twitter like */
  $handler->display->display_options['fields']['count_twitter_like']['id'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_like']['field'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['label'] = 'Twitter Likes';
  /* Field: Social Media Logs: Count Twitter retweet */
  $handler->display->display_options['fields']['count_twitter_retweet']['id'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_retweet']['field'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['label'] = 'Twitter Retweet';
  $handler->display->display_options['path'] = 'social-media-report';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Content ID';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Social Media Logs: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = 'Promoted By';
  /* Field: Social Media Logs: Count Facebook Promote */
  $handler->display->display_options['fields']['count_fb_promote']['id'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_promote']['field'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['label'] = 'FB Promote';
  /* Field: Social Media Logs: Count Twitter Promote */
  $handler->display->display_options['fields']['count_twitter_promote']['id'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_promote']['field'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['label'] = 'Twitter Promote';
  /* Field: Social Media Logs: Count facebook commnet */
  $handler->display->display_options['fields']['count_fb_comment']['id'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_comment']['field'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['label'] = 'FB Commnet';
  /* Field: Social Media Logs: Count facebook like */
  $handler->display->display_options['fields']['count_fb_like']['id'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_like']['field'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['label'] = 'FB Likes';
  /* Field: Social Media Logs: Count facebook Share */
  $handler->display->display_options['fields']['count_fb_share']['id'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_share']['field'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['label'] = 'FB Share';
  /* Field: Social Media Logs: Count Twitter like */
  $handler->display->display_options['fields']['count_twitter_like']['id'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_like']['field'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['label'] = 'Twitter Likes';
  /* Field: Social Media Logs: Count Twitter retweet */
  $handler->display->display_options['fields']['count_twitter_retweet']['id'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_retweet']['field'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['label'] = 'Twitter Likes';
  $handler->display->display_options['path'] = 'social-media-report-xls';
  $handler->display->display_options['displays'] = array(
    'social_media_report' => 'social_media_report',
    'default' => 0,
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_doc';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Content ID';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Social Media Logs: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = 'Promoted By';
  /* Field: Social Media Logs: Count Facebook Promote */
  $handler->display->display_options['fields']['count_fb_promote']['id'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_promote']['field'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['label'] = 'FB Promote';
  /* Field: Social Media Logs: Count Twitter Promote */
  $handler->display->display_options['fields']['count_twitter_promote']['id'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_promote']['field'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['label'] = 'Twitter Promote ';
  /* Field: Social Media Logs: Count facebook commnet */
  $handler->display->display_options['fields']['count_fb_comment']['id'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_comment']['field'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['label'] = 'FB Commnet';
  /* Field: Social Media Logs: Count facebook like */
  $handler->display->display_options['fields']['count_fb_like']['id'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_like']['field'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['label'] = 'FB Likes';
  /* Field: Social Media Logs: Count facebook Share */
  $handler->display->display_options['fields']['count_fb_share']['id'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_share']['field'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['label'] = 'FB Share';
  /* Field: Social Media Logs: Count Twitter like */
  $handler->display->display_options['fields']['count_twitter_like']['id'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_like']['field'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['label'] = 'Twitter Likes';
  /* Field: Social Media Logs: Count Twitter retweet */
  $handler->display->display_options['fields']['count_twitter_retweet']['id'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_retweet']['field'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['label'] = 'Twitter Likes';
  $handler->display->display_options['path'] = 'social-media-report-doc';
  $handler->display->display_options['displays'] = array(
    'social_media_report' => 'social_media_report',
    'default' => 0,
  );

  /* Display: PDF */
  $handler = $view->new_display('page', 'PDF', 'social_media_report_pdf');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Social Media Report PDF';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S No.';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Content ID';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'Content Type';
  /* Field: Social Media Logs: Username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = 'Promoted By';
  /* Field: Social Media Logs: Count Facebook Promote */
  $handler->display->display_options['fields']['count_fb_promote']['id'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_promote']['field'] = 'count_fb_promote';
  $handler->display->display_options['fields']['count_fb_promote']['label'] = 'FB Promote';
  /* Field: Social Media Logs: Count Twitter Promote */
  $handler->display->display_options['fields']['count_twitter_promote']['id'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_promote']['field'] = 'count_twitter_promote';
  $handler->display->display_options['fields']['count_twitter_promote']['label'] = 'Twitter Promote';
  /* Field: Social Media Logs: Count facebook commnet */
  $handler->display->display_options['fields']['count_fb_comment']['id'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_comment']['field'] = 'count_fb_comment';
  $handler->display->display_options['fields']['count_fb_comment']['label'] = 'FB Commnet';
  /* Field: Social Media Logs: Count facebook like */
  $handler->display->display_options['fields']['count_fb_like']['id'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_like']['field'] = 'count_fb_like';
  $handler->display->display_options['fields']['count_fb_like']['label'] = 'FB Likes';
  /* Field: Social Media Logs: Count facebook Share */
  $handler->display->display_options['fields']['count_fb_share']['id'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_fb_share']['field'] = 'count_fb_share';
  $handler->display->display_options['fields']['count_fb_share']['label'] = 'FB Share';
  /* Field: Social Media Logs: Count Twitter like */
  $handler->display->display_options['fields']['count_twitter_like']['id'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_like']['field'] = 'count_twitter_like';
  $handler->display->display_options['fields']['count_twitter_like']['label'] = 'Twitter Likes';
  /* Field: Social Media Logs: Count Twitter retweet */
  $handler->display->display_options['fields']['count_twitter_retweet']['id'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['table'] = 'itg_social_media_logs';
  $handler->display->display_options['fields']['count_twitter_retweet']['field'] = 'count_twitter_retweet';
  $handler->display->display_options['fields']['count_twitter_retweet']['label'] = 'Twitter Retweet';
  $handler->display->display_options['path'] = 'social-media-report-pdf';
  $export['social_media_report'] = $view;

  return $export;
}
