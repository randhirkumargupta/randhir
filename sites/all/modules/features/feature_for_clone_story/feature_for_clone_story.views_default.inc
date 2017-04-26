<?php
/**
 * @file
 * feature_for_clone_story.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_clone_story_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'story_clone';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'apachesolr__solr';
  $view->human_name = 'story clone';
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

  /* Display: Clone Story */
  $handler = $view->new_display('page', 'Clone Story', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Clone Story';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
    10 => '10',
  );
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '5, 10, 20, 40, 60,80,100';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'entity_id' => 'entity_id',
    'label' => 'label',
    'bundle_name' => 'bundle_name',
    'site' => 'site',
    'ds_created' => 'ds_created',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
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
    'site' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ds_created' => array(
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
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'S. No';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = 'Content id';
  $handler->display->display_options['fields']['entity_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['alter']['text'] = '<span class="seid-[counter]">[entity_id]</span>';
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = 'Title';
  /* Field: Apache Solr: bundle_name */
  $handler->display->display_options['fields']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['fields']['bundle_name']['label'] = 'Content Type';
  /* Field: Apache Solr: site */
  $handler->display->display_options['fields']['site']['id'] = 'site';
  $handler->display->display_options['fields']['site']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['site']['field'] = 'site';
  $handler->display->display_options['fields']['site']['label'] = 'Property';
  /* Field: Apache Solr: ds_created */
  $handler->display->display_options['fields']['ds_created']['id'] = 'ds_created';
  $handler->display->display_options['fields']['ds_created']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_created']['field'] = 'ds_created';
  $handler->display->display_options['fields']['ds_created']['label'] = 'Created date';
  $handler->display->display_options['fields']['ds_created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['ds_created']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['ds_created']['second_date_format'] = 'long';
  /* Field: Apache Solr: ds_changed */
  $handler->display->display_options['fields']['ds_changed']['id'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['ds_changed']['field'] = 'ds_changed';
  $handler->display->display_options['fields']['ds_changed']['label'] = 'Modified on';
  $handler->display->display_options['fields']['ds_changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['ds_changed']['custom_date_format'] = 'd/m/Y';
  $handler->display->display_options['fields']['ds_changed']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Clone';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/add/story?destination=clone-story&clone_id=[entity_id]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Apache Solr: entity_id */
  $handler->display->display_options['sorts']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['sorts']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['sorts']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['sorts']['entity_id']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Apache Solr: entity_id */
  $handler->display->display_options['filters']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['filters']['entity_id']['group'] = 1;
  $handler->display->display_options['filters']['entity_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['entity_id']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['entity_id']['expose']['label'] = 'Content id';
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
  /* Filter criterion: Apache Solr: bundle_name */
  $handler->display->display_options['filters']['bundle_name']['id'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['table'] = 'apachesolr__solr';
  $handler->display->display_options['filters']['bundle_name']['field'] = 'bundle_name';
  $handler->display->display_options['filters']['bundle_name']['group'] = 1;
  $handler->display->display_options['filters']['bundle_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['bundle_name']['expose']['operator_id'] = 'bundle_name_op';
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
    25 => 0,
    26 => 0,
  );
  $handler->display->display_options['path'] = 'clone-story';
  $export['story_clone'] = $view;

  return $export;
}
