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

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'front-solr-search-content';
  $handler->display->display_options['display_description'] = 'Search';
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
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = '';
  $handler->display->display_options['fields']['label_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['label_1']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_custom_story_small_large_url */
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['id'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['field'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['alter']['text'] = '<img src="[sm_field_custom_story_small_large_url]"/>';
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
  /* Field: Apache Solr: sm_common_kicker_text */
  $handler->display->display_options['fields']['sm_common_kicker_text']['id'] = 'sm_common_kicker_text';
  $handler->display->display_options['fields']['sm_common_kicker_text']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_common_kicker_text']['field'] = 'sm_common_kicker_text';
  $handler->display->display_options['fields']['sm_common_kicker_text']['label'] = '';
  $handler->display->display_options['fields']['sm_common_kicker_text']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['sm_common_kicker_text']['alter']['text'] = '[sm_common_kicker_text]';
  $handler->display->display_options['fields']['sm_common_kicker_text']['element_label_colon'] = FALSE;
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
  /* Field: Apache Solr: path_alias */
  $handler->display->display_options['fields']['path_alias']['id'] = 'path_alias';
  $handler->display->display_options['fields']['path_alias']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['path_alias']['field'] = 'path_alias';
  $handler->display->display_options['fields']['path_alias']['label'] = '';
  $handler->display->display_options['fields']['path_alias']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path_alias']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="search-detail">
<div class="other-info">Updated : [ds_changed]</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_setup'] = '<?php
// configuration for social sharing
$node_url = FRONT_URL. \'/\'.$row->path_alias;
$node_title = $row->label;
?>
<div class="social-share">
<ul>
<li><a class="share def-cur-pointer"><i class="fa fa-share-alt"></i></a></li>
<li><a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop(\'<?php print $node_url; ?>\', \'<?php print $node_title; ?>\', \'<?php print $share_desc; ?>\', \'<?php print $src; ?>\')"><i class="fa fa-facebook"></i></a></li>
<li><a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup(\'<?php print urlencode($node_title);?>\', \'<?php print urlencode($node_url); ?>\')"><i class="fa fa-twitter"></i></a></li>
<li><a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn(\'<?php print $node_url; ?>\')"></a></li>
</ul>
</div>';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
// configuration for social sharing
$node_url = FRONT_URL. \'/\'.$row->path_alias;
$node_title = $row->label;
?>
<div class="social-share">
<ul>
<li><a class="share def-cur-pointer"><i class="fa fa-share-alt"></i></a></li>
<li><a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop(\'<?php print $node_url; ?>\', \'<?php print $node_title; ?>\', \'<?php print $share_desc; ?>\', \'<?php print $src; ?>\')"><i class="fa fa-facebook"></i></a></li>
<li><a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup(\'<?php print urlencode($node_title);?>\', \'<?php print urlencode($node_url); ?>\')"><i class="fa fa-twitter"></i></a></li>
<li><a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn(\'<?php print $node_url; ?>\')"></a></li>
</ul>
</div>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  $handler->display->display_options['filters']['tm_vid_14_names']['expose']['label'] = 'Category';
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
    27 => 0,
    28 => 0,
    29 => 0,
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
  $handler->display->display_options['filters']['label']['group'] = 1;
  $handler->display->display_options['path'] = 'advance_search';

  /* Display: Search */
  $handler = $view->new_display('page', 'Search', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'front-solr-search-content';
  $handler->display->display_options['display_description'] = 'Search';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
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
  /* Field: Apache Solr: entity_id */
  $handler->display->display_options['fields']['entity_id']['id'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['entity_id']['field'] = 'entity_id';
  $handler->display->display_options['fields']['entity_id']['label'] = '';
  $handler->display->display_options['fields']['entity_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['entity_id']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
$alias = drupal_get_path_alias(\'node/\'.$row->entity_id);
$node_url = FRONT_URL. \'/\'.$alias;
echo $node_url;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = '';
  $handler->display->display_options['fields']['label_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['label_1']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: sm_field_custom_story_small_large_url */
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['id'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['field'] = 'sm_field_custom_story_small_large_url';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['alter']['text'] = '<a href="[php_1]" title="[label_1]" target="_blank"><img alt="[label_1]" style="width: 170px;" src="[sm_field_custom_story_small_large_url]" title="[label_1]" /></a>';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_type'] = '0';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_wrapper_class'] = 'search-pic';
  $handler->display->display_options['fields']['sm_field_custom_story_small_large_url']['element_default_classes'] = FALSE;
  /* Field: Apache Solr: sm_field_magazine_small_url */
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['id'] = 'sm_field_magazine_small_url';
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['field'] = 'sm_field_magazine_small_url';
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['label'] = '';
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['alter']['text'] = '<a href="[php_1]" title="[label_1]" target="_blank"><img alt="[label_1]" style="width: 170px;"  src="[sm_field_magazine_small_url]" title="[label_1]" /></a>';
  $handler->display->display_options['fields']['sm_field_magazine_small_url']['element_label_colon'] = FALSE;
  /* Field: Apache Solr: label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['label']['alter']['text'] = '<h2 title="[label]"><a href="[php_1]" target="_blank" title="[label]">[label]</a></h2>';
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['label']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['label']['element_wrapper_class'] = 'front-label';
  /* Field: Apache Solr: sm_common_kicker_text */
  $handler->display->display_options['fields']['sm_common_kicker_text']['id'] = 'sm_common_kicker_text';
  $handler->display->display_options['fields']['sm_common_kicker_text']['table'] = 'apachesolr__solr';
  $handler->display->display_options['fields']['sm_common_kicker_text']['field'] = 'sm_common_kicker_text';
  $handler->display->display_options['fields']['sm_common_kicker_text']['label'] = '';
  $handler->display->display_options['fields']['sm_common_kicker_text']['element_label_colon'] = FALSE;
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
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_wrapper_class'] = 'front-search-share';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
// configuration for social sharing
$node_url = FRONT_URL.\'/\'.drupal_get_path_alias(\'node/\'.$row->entity_id);
$node_title = $row->label;
$img_src = $row->sm_field_custom_story_small_large_url[0];
?>
<div class="social-share">
<ul>
<li><a class="share def-cur-pointer"><i class="fa fa-share-alt"></i></a></li>
<li><a title="share on facebook" class= "facebook def-cur-pointer" onclick="fbpop(\'<?php print $node_url; ?>\', \'<?php print urlencode($node_title); ?>\', \'\', \'<?php print $img_src; ?>\')"><i class="fa fa-facebook"></i></a></li>
<li><a title="share on twitter" class= "twitter def-cur-pointer" onclick="twitter_popup(\'<?php print urlencode($node_title);?>\', \'<?php print urlencode($node_url); ?>\')"><i class="fa fa-twitter"></i></a></li>
<li><a title="share on google+" class= "google def-cur-pointer" onclick="return googleplusbtn(\'<?php print $node_url; ?>\')"></a></li>
</ul>
</div>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="front-search-date-share">
<div class="search-detail">
<div class="other-info">Updated : [ds_changed]</div>
</div>
[php]
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
  $handler->display->display_options['path'] = 'topic';
  $export['front_end_global_search'] = $view;

  return $export;
}
