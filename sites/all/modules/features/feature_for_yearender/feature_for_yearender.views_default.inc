<?php
/**
 * @file
 * feature_for_yearender.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_yearender_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'yearender';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Yearender';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Yearender';
  $handler->display->display_options['css_class'] = 'yearend-gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'photgallery_landing_slider_753x543',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Section wise ordering content: weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'itg_widget_order';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['order'] = 'DESC';
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
    'photogallery' => 'photogallery',
  );

  /* Display: Yearender Top Slider */
  $handler = $view->new_display('block', 'Yearender Top Slider', 'block_1');
  $handler->display->display_options['display_description'] = 'Yearender Top slider';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'customstyle';
  $handler->display->display_options['style_options']['custom-class-columncount'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'photgallery_landing_slider_753x543',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'photogallery';
  $handler->display->display_options['filters']['content_type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget']['group'] = 1;
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '428';

  /* Display: Yearender Latest Galleries */
  $handler = $view->new_display('block', 'Yearender Latest Galleries', 'block_2');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'yearend-gallery';
  $handler->display->display_options['display_description'] = 'Yearender Latest Galleries';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '5';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'col-md-6 col-sm-6 col-xs-12';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Medium image */
  $handler->display->display_options['fields']['field_story_medium_image']['id'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['table'] = 'field_data_field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['field'] = 'field_story_medium_image';
  $handler->display->display_options['fields']['field_story_medium_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_medium_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_medium_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_medium_image']['empty'] = '<img alt="" class="no-result-image" src="../sites/all/themes/itg/images/itg_image370x208.jpg" title="" />';
  $handler->display->display_options['fields']['field_story_medium_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_medium_image']['settings'] = array(
    'image_style' => 'anchors_landing',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Gallery Image (field_gallery_image:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="section-ordering">
                        <div class="pic">  [field_story_medium_image]
<span><i class="fa fa-camera"></i> [delta] images</span>
</div>

                  <h3>[title]</h3>
         
            </div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Section wise ordering content: Content type */
  $handler->display->display_options['filters']['content_type']['id'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['content_type']['field'] = 'content_type';
  $handler->display->display_options['filters']['content_type']['value'] = 'photogallery';
  $handler->display->display_options['filters']['content_type']['group'] = 1;
  /* Filter criterion: Section wise ordering content: Widget */
  $handler->display->display_options['filters']['widget']['id'] = 'widget';
  $handler->display->display_options['filters']['widget']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['widget']['field'] = 'widget';
  $handler->display->display_options['filters']['widget']['value'] = 'section_wise_widget';
  $handler->display->display_options['filters']['widget']['group'] = 1;
  /* Filter criterion: Section wise ordering content: Category */
  $handler->display->display_options['filters']['cat_id']['id'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['table'] = 'itg_widget_order';
  $handler->display->display_options['filters']['cat_id']['field'] = 'cat_id';
  $handler->display->display_options['filters']['cat_id']['value'] = '428';
  $export['yearender'] = $view;

  return $export;
}
