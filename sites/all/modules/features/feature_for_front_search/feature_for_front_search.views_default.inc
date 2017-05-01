<?php
/**
 * @file
 * feature_for_front_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_front_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'front_end_global_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Front end global search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Related content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Apache Solr: _version_ */
  $handler->display->display_options['fields']['_version_']['id'] = '_version_';
  $handler->display->display_options['fields']['_version_']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['_version_']['field'] = '_version_';

  /* Display: Front end global search */
  $handler = $view->new_display('page', 'Front end global search', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front end global search';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'front-solr-search-content';
  $handler->display->display_options['display_description'] = 'Front end global search';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'itg-search-list';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Record Found !';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Apache Solr: sm_field_custom_story_small_large_url */
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['id'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['field'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_type'] = '0';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_wrapper_class'] = 'search-pic';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['text'] = '<a href="[url] " target="_blank">[label]</a>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['label']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['label']['element_wrapper_class'] = 'front-label';
  /* Field: Apache Solr: content */
  $handler->display->display_options['fields']['content']['id'] = 'content';
  $handler->display->display_options['fields']['content']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['content']['field'] = 'content';
  $handler->display->display_options['fields']['content']['label'] = '';
  $handler->display->display_options['fields']['content']['exclude'] = TRUE;
  $handler->display->display_options['fields']['content']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['content']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['content']['element_wrapper_class'] = 'front-content';
  /* Field: Apache Solr: ds_changed */
  $handler->display->display_options['fields']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['label'] = '';
  $handler->display->display_options['fields']['ds_changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ds_changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['ds_changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['ds_changed']['custom_date_format'] = 'F j, Y, g:i a';
  $handler->display->display_options['fields']['ds_changed']['second_date_format'] = 'long';
  $handler->display->display_options['fields']['ds_changed']['timezone'] = 'Asia/Kolkata';
  /* Field: Apache Solr: hash */
  $handler->display->display_options['fields']['hash']['id'] = 'hash';
  $handler->display->display_options['fields']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['hash']['field'] = 'hash';
  $handler->display->display_options['fields']['hash']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="search-detail">
<p>[content]</p>
<div class="other-info">Updated : [ds_changed]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Apache Solr: ds_changed */
  $handler->display->display_options['sorts']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['sorts']['ds_changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: Search */
  $handler->display->display_options['filters']['keyword']['id'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['keyword']['field'] = 'keyword';
  $handler->display->display_options['filters']['keyword']['group'] = 1;
  $handler->display->display_options['filters']['keyword']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keyword']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['keyword']['expose']['label'] = 'Search by keywords';
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
  );
  /* Filter criterion: Apache Solr: tm_vid_4_names */
  $handler->display->display_options['filters']['tm_vid_4_names']['id'] = 'tm_vid_4_names';
  $handler->display->display_options['filters']['tm_vid_4_names']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['tm_vid_4_names']['field'] = 'tm_vid_4_names';
  $handler->display->display_options['filters']['tm_vid_4_names']['operator'] = 'word';
  $handler->display->display_options['filters']['tm_vid_4_names']['group'] = 1;
  $handler->display->display_options['filters']['tm_vid_4_names']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tm_vid_4_names']['expose']['operator_id'] = 'tm_vid_4_names_op';
  $handler->display->display_options['filters']['tm_vid_4_names']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['tm_vid_4_names']['expose']['operator'] = 'tm_vid_4_names_op';
  $handler->display->display_options['filters']['tm_vid_4_names']['expose']['identifier'] = 'tm_vid_4_names';
  $handler->display->display_options['filters']['tm_vid_4_names']['expose']['remember_roles'] = array(
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
  );
  /* Filter criterion: Apache Solr: sm_field_itg_common_by_line_name */
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['id'] = 'sm_field_itg_common_by_line_name';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['field'] = 'sm_field_itg_common_by_line_name';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['group'] = 1;
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['expose']['operator_id'] = 'sm_field_itg_common_by_line_name_op';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['expose']['operator'] = 'sm_field_itg_common_by_line_name_op';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['expose']['identifier'] = 'sm_field_itg_common_by_line_name';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_name']['expose']['remember_roles'] = array(
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
  );
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
  );
  /* Filter criterion: Apache Solr: hash */
  $handler->display->display_options['filters']['hash']['id'] = 'hash';
  $handler->display->display_options['filters']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['hash']['field'] = 'hash';
  $handler->display->display_options['filters']['hash']['group'] = 1;
  $handler->display->display_options['filters']['hash']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hash']['expose']['operator_id'] = 'hash_op';
  $handler->display->display_options['filters']['hash']['expose']['label'] = 'Site';
  $handler->display->display_options['filters']['hash']['expose']['operator'] = 'hash_op';
  $handler->display->display_options['filters']['hash']['expose']['identifier'] = 'hash';
  $handler->display->display_options['filters']['hash']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['hash']['expose']['remember_roles'] = array(
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
    10 => 0,
    13 => 0,
    11 => 0,
    16 => 0,
    17 => 0,
    14 => 0,
    12 => 0,
    19 => 0,
    15 => 0,
    18 => 0,
    23 => 0,
  );
  $handler->display->display_options['filters']['hash']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['hash']['group_info']['label'] = 'Property';
  $handler->display->display_options['filters']['hash']['group_info']['identifier'] = 'hash';
  $handler->display->display_options['filters']['hash']['group_info']['group_items'] = array(
    1 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    2 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Apache Solr: label */
  $handler->display->display_options['filters']['label']['id'] = 'label';
  $handler->display->display_options['filters']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['label']['field'] = 'label';
  $handler->display->display_options['path'] = 'topic';
  $export['front_end_global_search'] = $view;

  return $export;
}
