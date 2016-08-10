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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Apache Solr: _version_ */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_blog_image */
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
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_extra_large_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['id'] = 'sm_thumb_thumbnail_field_story_extra_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['field'] = 'sm_thumb_thumbnail_field_story_extra_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_extra_large_image']['label'] = '';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_large_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['id'] = 'sm_thumb_thumbnail_field_story_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['field'] = 'sm_thumb_thumbnail_field_story_large_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_large_image']['label'] = '';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_story_small_image */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['id'] = 'sm_thumb_thumbnail_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['field'] = 'sm_thumb_thumbnail_field_story_small_image';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_story_small_image']['label'] = '';
  /* Field: Apache Solr: sm_thumb_thumbnail_field_images */
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_images']['id'] = 'sm_thumb_thumbnail_field_images';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_images']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_images']['field'] = 'sm_thumb_thumbnail_field_images';
  $handler->display->display_options['fields']['sm_thumb_thumbnail_field_images']['label'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
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
    22 => 0,
  );
  /* Filter criterion: Apache Solr: sm_image_title */
  $handler->display->display_options['filters']['sm_image_title']['id'] = 'sm_image_title';
  $handler->display->display_options['filters']['sm_image_title']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_image_title']['field'] = 'sm_image_title';
  $handler->display->display_options['filters']['sm_image_title']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_image_title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_image_title']['expose']['operator_id'] = 'sm_image_title_op';
  $handler->display->display_options['filters']['sm_image_title']['expose']['label'] = 'Caption';
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
  );
  /* Filter criterion: Apache Solr: sm_alttext */
  $handler->display->display_options['filters']['sm_alttext']['id'] = 'sm_alttext';
  $handler->display->display_options['filters']['sm_alttext']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_alttext']['field'] = 'sm_alttext';
  $handler->display->display_options['filters']['sm_alttext']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_alttext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_alttext']['expose']['operator_id'] = 'sm_alttext_op';
  $handler->display->display_options['filters']['sm_alttext']['expose']['label'] = 'Alt Text';
  $handler->display->display_options['filters']['sm_alttext']['expose']['description'] = 'Alt Text';
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
  $handler->display->display_options['path'] = 'searchimage';
  $export['searchimage'] = $view;

  return $export;
}
