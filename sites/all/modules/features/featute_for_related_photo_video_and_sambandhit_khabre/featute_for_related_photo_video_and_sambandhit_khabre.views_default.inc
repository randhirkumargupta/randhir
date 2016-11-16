<?php
/**
 * @file
 * featute_for_related_photo_video_and_sambandhit_khabre.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function featute_for_related_photo_video_and_sambandhit_khabre_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_photogallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'related photogallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'related videogallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'node';
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

  /* Display: Related photogallery */
  $handler = $view->new_display('page', 'Related photogallery', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Photo By */
  $handler->display->display_options['fields']['field_photo_by']['id'] = 'field_photo_by';
  $handler->display->display_options['fields']['field_photo_by']['table'] = 'field_data_field_photo_by';
  $handler->display->display_options['fields']['field_photo_by']['field'] = 'field_photo_by';
  $handler->display->display_options['fields']['field_photo_by']['label'] = '';
  $handler->display->display_options['fields']['field_photo_by']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_photo_by']['settings'] = array(
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
  $handler->display->display_options['fields']['changed']['timezone'] = 'Asia/Kolkata';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: primary category (field_primary_category) */
  $handler->display->display_options['arguments']['field_primary_category_value']['id'] = 'field_primary_category_value';
  $handler->display->display_options['arguments']['field_primary_category_value']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['arguments']['field_primary_category_value']['field'] = 'field_primary_category_value';
  $handler->display->display_options['arguments']['field_primary_category_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_primary_category_value']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_primary_category_value']['limit'] = '0';
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
    'photogallery' => 'photogallery',
  );
  $handler->display->display_options['path'] = 'related-photogallery';

  /* Display: Related videogallery */
  $handler = $view->new_display('page', 'Related videogallery', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
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
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Field: Byline */
  $handler->display->display_options['fields']['field_story_reporter']['id'] = 'field_story_reporter';
  $handler->display->display_options['fields']['field_story_reporter']['table'] = 'field_data_field_story_reporter';
  $handler->display->display_options['fields']['field_story_reporter']['field'] = 'field_story_reporter';
  $handler->display->display_options['fields']['field_story_reporter']['label'] = '';
  $handler->display->display_options['fields']['field_story_reporter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_reporter']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_story_reporter']['delta_offset'] = '0';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'itg_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['timezone'] = 'Asia/Kolkata';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: primary category (field_primary_category) */
  $handler->display->display_options['arguments']['field_primary_category_value']['id'] = 'field_primary_category_value';
  $handler->display->display_options['arguments']['field_primary_category_value']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['arguments']['field_primary_category_value']['field'] = 'field_primary_category_value';
  $handler->display->display_options['arguments']['field_primary_category_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_primary_category_value']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_primary_category_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_primary_category_value']['limit'] = '0';
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
  $handler->display->display_options['path'] = 'related-videogallery';
  $export['related_photogallery'] = $view;

  $view = new view();
  $view->name = 'sambandhit_khabre';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Sambandhit Khabre';
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
  /* Field: Apache Solr: _version_ */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: hash */
  $handler->display->display_options['fields']['hash']['id'] = 'hash';
  $handler->display->display_options['fields']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['hash']['field'] = 'hash';
  $handler->display->display_options['fields']['hash']['label'] = '';
  $handler->display->display_options['fields']['hash']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Apache Solr: ds_changed */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Apache Solr: entity_id */
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
  $handler->display->display_options['path'] = 'sambandhit-khabre';

  /* Display: Sambandhit Khabre */
  $handler = $view->new_display('block', 'Sambandhit Khabre', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: hash */
  $handler->display->display_options['fields']['hash']['id'] = 'hash';
  $handler->display->display_options['fields']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['hash']['field'] = 'hash';
  $handler->display->display_options['fields']['hash']['label'] = '';
  $handler->display->display_options['fields']['hash']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Apache Solr: ds_changed */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: entity_id */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_id']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['entity_id']['expose']['label'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['expose']['operator'] = 'entity_id_op';
  $handler->display->display_options['filters']['entity_id']['expose']['identifier'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['block_description'] = 'Sambandhit Khabre';
  $export['sambandhit_khabre'] = $view;

  return $export;
}
