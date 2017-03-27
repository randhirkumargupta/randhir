<?php
/**
 * @file
 * feature_for_searchimage.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_searchimage_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'searchimage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'searchimage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'searchimage';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Apache Solr: _version_ */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_blog_image']['id'] = 'sm_thumb_thumbnail_field_blog_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_blog_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_blog_image']['field'] = 'sm_thumb_thumbnail_field_blog_image';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_extra_large_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['id'] = 'sm_thumb_thumbnail_field_story_extra_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['field'] = 'sm_thumb_thumbnail_field_story_extra_large_image';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_large_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['id'] = 'sm_thumb_thumbnail_field_story_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['field'] = 'sm_thumb_thumbnail_field_story_large_image';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_small_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['id'] = 'sm_thumb_thumbnail_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['field'] = 'sm_thumb_thumbnail_field_story_small_image';
  /* Sort criterion: Apache Solr: entity_id */
  $handler->display->display_options['sorts']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['sorts']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['sorts']['entity_id']['order'] = 'DESC';
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Image Found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_original_image_url */
  $handler->display->display_options['fields']['sm_original_image_url']['id'] = 'sm_original_image_url';
  $handler->display->display_options['fields']['sm_original_image_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_original_image_url']['field'] = 'sm_original_image_url';
  $handler->display->display_options['fields']['sm_original_image_url']['label'] = '';
  $handler->display->display_options['fields']['sm_original_image_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: sm_image_title */
  $handler->display->display_options['filters']['sm_image_title']['id'] = 'sm_image_title';
  $handler->display->display_options['filters']['sm_image_title']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_image_title']['field'] = 'sm_image_title';
  $handler->display->display_options['filters']['sm_image_title']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_image_title']['group'] = 1;
  $handler->display->display_options['filters']['sm_image_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_image_title']['expose']['operator_id'] = 'sm_image_title_op';
  $handler->display->display_options['filters']['sm_image_title']['expose']['label'] = 'Caption/Title';
  $handler->display->display_options['filters']['sm_image_title']['expose']['operator'] = 'sm_image_title_op';
  $handler->display->display_options['filters']['sm_image_title']['expose']['identifier'] = 'sm_image_title';
  $handler->display->display_options['filters']['sm_image_title']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: sm_alttext */
  $handler->display->display_options['filters']['sm_alttext']['id'] = 'sm_alttext';
  $handler->display->display_options['filters']['sm_alttext']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_alttext']['field'] = 'sm_alttext';
  $handler->display->display_options['filters']['sm_alttext']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_alttext']['group'] = 1;
  $handler->display->display_options['filters']['sm_alttext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_alttext']['expose']['operator_id'] = 'sm_alttext_op';
  $handler->display->display_options['filters']['sm_alttext']['expose']['label'] = 'Alt Text';
  $handler->display->display_options['filters']['sm_alttext']['expose']['operator'] = 'sm_alttext_op';
  $handler->display->display_options['filters']['sm_alttext']['expose']['identifier'] = 'sm_alttext';
  $handler->display->display_options['filters']['sm_alttext']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: tm_vid_14_names */
  $handler->display->display_options['filters']['tm_vid_14_names']['id'] = 'tm_vid_14_names';
  $handler->display->display_options['filters']['tm_vid_14_names']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['tm_vid_14_names']['field'] = 'tm_vid_14_names';
  $handler->display->display_options['filters']['tm_vid_14_names']['operator'] = 'allwords';
  $handler->display->display_options['filters']['tm_vid_14_names']['group'] = 1;
  $handler->display->display_options['filters']['tm_vid_14_names']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['operator_id'] = 'tm_vid_14_names_op';
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['label'] = 'Section';
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['operator'] = 'tm_vid_14_names_op';
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['identifier'] = 'tm_vid_14_names';
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['operator'] = 'word';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle_name']['expose']['operator'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['identifier'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'searchimage';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'search_unpublish_video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'search unpublish video';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sm_field_video_id' => 'sm_field_video_id',
    'sm_field_video_size' => 'sm_field_video_size',
    'sm_field_video_thumb_url' => 'sm_field_video_thumb_url',
    'sm_field_video_duration' => 'sm_field_video_duration',
    'sm_field_video_used' => 'sm_field_video_used',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sm_field_video_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_size' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_thumb_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Image Found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_field_video_id */
  $handler->display->display_options['fields']['sm_field_video_id']['id'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_id']['field'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_id']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_size */
  $handler->display->display_options['fields']['sm_field_video_size']['id'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_size']['field'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_size']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_thumb_url */
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['id'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['field'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_duration */
  $handler->display->display_options['fields']['sm_field_video_duration']['id'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_duration']['field'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_used */
  $handler->display->display_options['fields']['sm_field_video_used']['id'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_used']['field'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_used']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_property */
  $handler->display->display_options['fields']['sm_field_property']['id'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_property']['field'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['label'] = '';
  $handler->display->display_options['fields']['sm_field_property']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['operator'] = 'word';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle_name']['expose']['operator'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['identifier'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'search-unpublish-video';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Unpublish Video';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sm_field_video_id' => 'sm_field_video_id',
    'sm_field_video_size' => 'sm_field_video_size',
    'sm_field_video_thumb_url' => 'sm_field_video_thumb_url',
    'sm_field_video_duration' => 'sm_field_video_duration',
    'sm_field_video_used' => 'sm_field_video_used',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sm_field_video_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_size' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_thumb_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Image Found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_field_video_id */
  $handler->display->display_options['fields']['sm_field_video_id']['id'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_id']['field'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_id']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_size */
  $handler->display->display_options['fields']['sm_field_video_size']['id'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_size']['field'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_size']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_thumb_url */
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['id'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['field'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_duration */
  $handler->display->display_options['fields']['sm_field_video_duration']['id'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_duration']['field'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_used */
  $handler->display->display_options['fields']['sm_field_video_used']['id'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_used']['field'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_used']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_property */
  $handler->display->display_options['fields']['sm_field_property']['id'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_property']['field'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['label'] = '';
  $handler->display->display_options['fields']['sm_field_property']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['operator'] = 'word';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle_name']['expose']['operator'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['identifier'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'search-unpublish-video-radio';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'search_publish_video');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'search publish video';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sm_field_video_id' => 'sm_field_video_id',
    'sm_field_video_size' => 'sm_field_video_size',
    'sm_field_video_thumb_url' => 'sm_field_video_thumb_url',
    'sm_field_video_duration' => 'sm_field_video_duration',
    'sm_field_video_used' => 'sm_field_video_used',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sm_field_video_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_size' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_thumb_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Image Found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_field_video_id */
  $handler->display->display_options['fields']['sm_field_video_id']['id'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_id']['field'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_id']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_size */
  $handler->display->display_options['fields']['sm_field_video_size']['id'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_size']['field'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_size']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_thumb_url */
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['id'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['field'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_duration */
  $handler->display->display_options['fields']['sm_field_video_duration']['id'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_duration']['field'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_used */
  $handler->display->display_options['fields']['sm_field_video_used']['id'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_used']['field'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_used']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_property */
  $handler->display->display_options['fields']['sm_field_property']['id'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_property']['field'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['label'] = '';
  $handler->display->display_options['fields']['sm_field_property']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['operator'] = 'word';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle_name']['expose']['operator'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['identifier'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'search-publish-video';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'search_publish_video_radio');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search publish Video';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sm_field_video_id' => 'sm_field_video_id',
    'sm_field_video_size' => 'sm_field_video_size',
    'sm_field_video_thumb_url' => 'sm_field_video_thumb_url',
    'sm_field_video_duration' => 'sm_field_video_duration',
    'sm_field_video_used' => 'sm_field_video_used',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sm_field_video_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_size' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_thumb_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_duration' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sm_field_video_used' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Image Found';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_field_video_id */
  $handler->display->display_options['fields']['sm_field_video_id']['id'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_id']['field'] = 'sm_field_video_id';
  $handler->display->display_options['fields']['sm_field_video_id']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_id']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_size */
  $handler->display->display_options['fields']['sm_field_video_size']['id'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_size']['field'] = 'sm_field_video_size';
  $handler->display->display_options['fields']['sm_field_video_size']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_size']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_thumb_url */
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['id'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['field'] = 'sm_field_video_thumb_url';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_thumb_url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_duration */
  $handler->display->display_options['fields']['sm_field_video_duration']['id'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_duration']['field'] = 'sm_field_video_duration';
  $handler->display->display_options['fields']['sm_field_video_duration']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_duration']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_video_used */
  $handler->display->display_options['fields']['sm_field_video_used']['id'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_video_used']['field'] = 'sm_field_video_used';
  $handler->display->display_options['fields']['sm_field_video_used']['label'] = '';
  $handler->display->display_options['fields']['sm_field_video_used']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_property */
  $handler->display->display_options['fields']['sm_field_property']['id'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_property']['field'] = 'sm_field_property';
  $handler->display->display_options['fields']['sm_field_property']['label'] = '';
  $handler->display->display_options['fields']['sm_field_property']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keyword']['expose']['operator'] = 'keyword_op';
  $handler->display->display_options['filters']['keyword']['expose']['identifier'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['operator'] = 'word';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle_name']['expose']['operator'] = 'bundle_name_op';
  $handler->display->display_options['filters']['bundle_name']['expose']['identifier'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'search-publish-video-radio';
  $export['searchimage'] = $view;

  return $export;
}
