<?php
/**
 * @file
 * feature_for_photo_and_video_related_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_photo_and_video_related_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_photo_video_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Related photo and video content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sambandhit Khabre';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';

  /* Display: Related video */
  $handler = $view->new_display('page', 'Related video', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related video';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['style_options']['class'] = 'photo-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['id'] = 'sm_thumb_video_landing_page_170_x_127_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['field'] = 'sm_thumb_video_landing_page_170_x_127_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['label'] = '';
  $handler->display->display_options['fields']['ds_changed']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = 'true';
  $handler->display->display_options['path'] = 'related-video';

  /* Display: Related photo */
  $handler = $view->new_display('page', 'Related photo', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related photo';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-3';
  $handler->display->display_options['style_options']['class'] = 'photo-list';
  $handler->display->display_options['style_options']['wrapper_class'] = 'row';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['id'] = 'sm_thumb_video_landing_page_170_x_127_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['field'] = 'sm_thumb_video_landing_page_170_x_127_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['label'] = '';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_small_image']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['label'] = '';
  $handler->display->display_options['fields']['ds_changed']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Broken/missing handler */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['value'] = 'true';
  $handler->display->display_options['path'] = 'related-photo';
  $export['related_photo_video_content'] = $view;

  $view = new view();
  $view->name = 'related_story';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Related Story';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sambandhit Khabre';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related Story';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['id'] = 'sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['field'] = 'sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['sm_thumb_video_landing_page_170_x_127_field_story_extra_large_image']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['label']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['hash']['id'] = 'hash';
  $handler->display->display_options['fields']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['hash']['field'] = 'hash';
  $handler->display->display_options['fields']['hash']['label'] = '';
  $handler->display->display_options['fields']['hash']['exclude'] = TRUE;
  $handler->display->display_options['fields']['hash']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Broken/missing handler */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['arguments']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['arguments']['entity_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['entity_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['entity_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['entity_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['entity_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'related-story';
  $export['related_story'] = $view;

  return $export;
}
