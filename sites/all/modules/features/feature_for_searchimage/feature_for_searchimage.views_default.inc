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
  /* Field: Apache Solr: sm_field_associate_photo_gallery */
  $handler->display->display_options['fields']['sm_field_associate_photo_gallery']['id'] = 'sm_field_associate_photo_gallery';
  $handler->display->display_options['fields']['sm_field_associate_photo_gallery']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_associate_photo_gallery']['field'] = 'sm_field_associate_photo_gallery';
  $handler->display->display_options['fields']['sm_field_associate_photo_gallery']['label'] = '';
  $handler->display->display_options['fields']['sm_field_associate_photo_gallery']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_mega_review_photo_galle */
  $handler->display->display_options['fields']['sm_field_mega_review_photo_galle']['id'] = 'sm_field_mega_review_photo_galle';
  $handler->display->display_options['fields']['sm_field_mega_review_photo_galle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_mega_review_photo_galle']['field'] = 'sm_field_mega_review_photo_galle';
  $handler->display->display_options['fields']['sm_field_mega_review_photo_galle']['label'] = '';
  $handler->display->display_options['fields']['sm_field_mega_review_photo_galle']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['path'] = 'searchimage';
  $export['searchimage'] = $view;

  return $export;
}
