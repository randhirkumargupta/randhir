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
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Video Id */
  $handler->display->display_options['fields']['field_bitrate_video_id']['id'] = 'field_bitrate_video_id';
  $handler->display->display_options['fields']['field_bitrate_video_id']['table'] = 'field_data_field_bitrate_video_id';
  $handler->display->display_options['fields']['field_bitrate_video_id']['field'] = 'field_bitrate_video_id';
  /* Field: Content: Resolution */
  $handler->display->display_options['fields']['field_resolution']['id'] = 'field_resolution';
  $handler->display->display_options['fields']['field_resolution']['table'] = 'field_data_field_resolution';
  $handler->display->display_options['fields']['field_resolution']['field'] = 'field_resolution';
  $handler->display->display_options['fields']['field_resolution']['label'] = 'Framesize';
  /* Field: Content: video Bitrate */
  $handler->display->display_options['fields']['field_video_bitrate']['id'] = 'field_video_bitrate';
  $handler->display->display_options['fields']['field_video_bitrate']['table'] = 'field_data_field_video_bitrate';
  $handler->display->display_options['fields']['field_video_bitrate']['field'] = 'field_video_bitrate';
  $handler->display->display_options['fields']['field_video_bitrate']['label'] = 'Bitrate';
  /* Field: Content: Video Duration */
  $handler->display->display_options['fields']['field_bitrate_video_duration']['id'] = 'field_bitrate_video_duration';
  $handler->display->display_options['fields']['field_bitrate_video_duration']['table'] = 'field_data_field_bitrate_video_duration';
  $handler->display->display_options['fields']['field_bitrate_video_duration']['field'] = 'field_bitrate_video_duration';
  $handler->display->display_options['fields']['field_bitrate_video_duration']['label'] = 'Duration';
  /* Field: Content: Bitrate Video Url */
  $handler->display->display_options['fields']['field_video_url']['id'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['table'] = 'field_data_field_video_url';
  $handler->display->display_options['fields']['field_video_url']['field'] = 'field_video_url';
  $handler->display->display_options['fields']['field_video_url']['label'] = 'Video Url ';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'bitrates-videos';
  $export['bitrates_videos'] = $view;

  return $export;
}
