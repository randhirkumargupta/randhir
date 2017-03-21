<?php
/**
 * @file
 * feature_for_related_content.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_related_content_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'related_content_new';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'Related content';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'itg_row_selector' => 'itg_row_selector',
    'counter' => 'counter',
    'label' => 'label',
    'bundle_name' => 'bundle_name',
    'entity_id' => 'entity_id',
    'url' => 'url',
    'site' => 'site',
    'hash' => 'hash',
    'tm_vid_4_names' => 'tm_vid_4_names',
    'im_vid_4' => 'im_vid_4',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'itg_row_selector' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'bundle_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'site' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'hash' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tm_vid_4_names' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'im_vid_4' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['caption'] = 'Content Listing';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="head-val"><input class="insert-url add-more form-submit" type="button" name="Insert" value="Add Selected Content" /> &nbsp; <input type="text" name="insvalue" id="insvalue" size="40" class="form-text valid">&nbsp; <div id="relatedtit"></div>
</div>
<div id="clickme">Save Search</div>
<div class="search-criteria" style="display:none"><input class="form-text valid" type="text" name="search-title" id="search-title"><input class="insert-save add-more form-submit" id="filter-save" type="button" name="save" value="save" /></div><div class="success" style="display:none">Search saved successfully</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  /* Field: Global: Row Selector */
  $handler->display->display_options['fields']['itg_row_selector']['id'] = 'itg_row_selector';
  $handler->display->display_options['fields']['itg_row_selector']['table'] = 'views';
  $handler->display->display_options['fields']['itg_row_selector']['field'] = 'itg_row_selector';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Apache Solr: url */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Title';
  $handler->display->display_options['fields']['label']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['label']['alter']['target'] = '_blank';
  /* Field: Apache Solr: bundle_name */
  $handler->display->display_options['fields']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['label'] = 'Content Type';
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Nid';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['alter']['text'] = '<span class="seid-[counter]">[entity_id]</span>';
  /* Field: Apache Solr: site */
  $handler->display->display_options['fields']['site']['id'] = 'site';
  $handler->display->display_options['fields']['site']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['site']['field'] = 'site';
  $handler->display->display_options['fields']['site']['label'] = 'Property';
  /* Field: Apache Solr: hash */
  $handler->display->display_options['fields']['hash']['id'] = 'hash';
  $handler->display->display_options['fields']['hash']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['hash']['field'] = 'hash';
  $handler->display->display_options['fields']['hash']['exclude'] = TRUE;
  /* Field: Apache Solr: sm_vid_Category_Management */
  $handler->display->display_options['fields']['sm_vid_Category_Management']['id'] = 'sm_vid_Category_Management';
  $handler->display->display_options['fields']['sm_vid_Category_Management']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_vid_Category_Management']['field'] = 'sm_vid_Category_Management';
  $handler->display->display_options['fields']['sm_vid_Category_Management']['label'] = 'Section';
  /* Field: Apache Solr: im_vid_14 */
  $handler->display->display_options['fields']['im_vid_14']['id'] = 'im_vid_14';
  $handler->display->display_options['fields']['im_vid_14']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['im_vid_14']['field'] = 'im_vid_14';
  $handler->display->display_options['fields']['im_vid_14']['exclude'] = TRUE;
  /* Field: Apache Solr: im_field_story_itg_tags */
  $handler->display->display_options['fields']['im_field_story_itg_tags']['id'] = 'im_field_story_itg_tags';
  $handler->display->display_options['fields']['im_field_story_itg_tags']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['im_field_story_itg_tags']['field'] = 'im_field_story_itg_tags';
  $handler->display->display_options['fields']['im_field_story_itg_tags']['label'] = 'Tags';
  $handler->display->display_options['fields']['im_field_story_itg_tags']['exclude'] = TRUE;
  /* Field: Apache Solr: tm_vid_1_names */
  $handler->display->display_options['fields']['tm_vid_1_names']['id'] = 'tm_vid_1_names';
  $handler->display->display_options['fields']['tm_vid_1_names']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['tm_vid_1_names']['field'] = 'tm_vid_1_names';
  $handler->display->display_options['fields']['tm_vid_1_names']['label'] = 'Tag name';
  $handler->display->display_options['fields']['tm_vid_1_names']['exclude'] = TRUE;
  /* Field: Apache Solr: bs_status */
  $handler->display->display_options['fields']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['fields']['bs_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['fields']['bs_status']['label'] = 'status';
  $handler->display->display_options['fields']['bs_status']['empty'] = 'Unpublished';
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
  /* Filter criterion: Apache Solr: tm_vid_14_names */
  $handler->display->display_options['filters']['tm_vid_14_names']['id'] = 'tm_vid_14_names';
  $handler->display->display_options['filters']['tm_vid_14_names']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['tm_vid_14_names']['field'] = 'tm_vid_14_names';
  $handler->display->display_options['filters']['tm_vid_14_names']['operator'] = 'word';
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
  /* Filter criterion: Apache Solr: sm_field_itg_common_by_line_twit */
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['id'] = 'sm_field_itg_common_by_line_twit';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['field'] = 'sm_field_itg_common_by_line_twit';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['operator'] = 'word';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['group'] = 1;
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['expose']['operator_id'] = 'sm_field_itg_common_by_line_twit_op';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['expose']['label'] = 'Twitter Handle';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['expose']['operator'] = 'sm_field_itg_common_by_line_twit_op';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['expose']['identifier'] = 'sm_field_itg_common_by_line_twit';
  $handler->display->display_options['filters']['sm_field_itg_common_by_line_twit']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bundle */
  $handler->display->display_options['filters']['bundle']['id'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle']['field'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['group'] = 1;
  $handler->display->display_options['filters']['bundle']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle']['expose']['operator_id'] = 'bundle_op';
  $handler->display->display_options['filters']['bundle']['expose']['label'] = 'Content type';
  $handler->display->display_options['filters']['bundle']['expose']['operator'] = 'bundle_op';
  $handler->display->display_options['filters']['bundle']['expose']['identifier'] = 'bundle';
  $handler->display->display_options['filters']['bundle']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Apache Solr: bs_status */
  $handler->display->display_options['filters']['bs_status']['id'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bs_status']['field'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['group'] = 1;
  $handler->display->display_options['filters']['bs_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bs_status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['bs_status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['bs_status']['expose']['operator'] = 'bs_status_op';
  $handler->display->display_options['filters']['bs_status']['expose']['identifier'] = 'bs_status';
  $handler->display->display_options['filters']['bs_status']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'related-content';
  $export['related_content_new'] = $view;

  return $export;
}
