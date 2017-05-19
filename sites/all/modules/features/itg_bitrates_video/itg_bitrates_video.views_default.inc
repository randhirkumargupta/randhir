<?php
/**
 * @file
 * itg_bitrates_video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function itg_bitrates_video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bitrates_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Bitrates videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Bitrates videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Video Id */
  $handler->display->display_options['fields']['field_bitrate_video_id']['id'] = 'field_bitrate_video_id';
  $handler->display->display_options['fields']['field_bitrate_video_id']['table'] = 'field_data_field_bitrate_video_id';
  $handler->display->display_options['fields']['field_bitrate_video_id']['field'] = 'field_bitrate_video_id';
  /* Field: Content: Video Url */
  $handler->display->display_options['fields']['field_video_url']['id'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['table'] = 'field_data_field_video_url';
  $handler->display->display_options['fields']['field_video_url']['field'] = 'field_video_url';
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
    'itg_bitrates_video' => 'itg_bitrates_video',
  );
  /* Filter criterion: Content: Video Id (field_bitrate_video_id) */
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['id'] = 'field_bitrate_video_id_value';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['table'] = 'field_data_field_bitrate_video_id';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['field'] = 'field_bitrate_video_id_value';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['expose']['operator_id'] = 'field_bitrate_video_id_value_op';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['expose']['label'] = 'Video Id';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['expose']['operator'] = 'field_bitrate_video_id_value_op';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['expose']['identifier'] = 'field_bitrate_video_id_value';
  $handler->display->display_options['filters']['field_bitrate_video_id_value']['expose']['remember_roles'] = array(
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'bitrates-videos';
  $export['bitrates_videos'] = $view;

  return $export;
}
