<?php
/**
 * @file
 * feature_for_personalization.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_personalization_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'personalization_saved_content';
  $view->description = 'My saved content listing.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Personalization - Saved Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Personalization - Saved Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result found!';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Flags: my_saved_content */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'my_saved_content';
  /* Field: Content: Section */
  $handler->display->display_options['fields']['field_story_category']['id'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['table'] = 'field_data_field_story_category';
  $handler->display->display_options['fields']['field_story_category']['field'] = 'field_story_category';
  $handler->display->display_options['fields']['field_story_category']['label'] = '';
  $handler->display->display_options['fields']['field_story_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_story_category']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_story_category']['delta_offset'] = '0';
  /* Field: Content: primary category */
  $handler->display->display_options['fields']['field_primary_category']['id'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['table'] = 'field_data_field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['field'] = 'field_primary_category';
  $handler->display->display_options['fields']['field_primary_category']['label'] = '';
  $handler->display->display_options['fields']['field_primary_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_category']['empty'] = '[field_story_category]';
  $handler->display->display_options['fields']['field_primary_category']['type'] = 'text_plain';
  /* Field: Content: Extra large image */
  $handler->display->display_options['fields']['field_story_extra_large_image']['id'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['table'] = 'field_data_field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['field'] = 'field_story_extra_large_image';
  $handler->display->display_options['fields']['field_story_extra_large_image']['label'] = '';
  $handler->display->display_options['fields']['field_story_extra_large_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_story_extra_large_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_story_extra_large_image']['settings'] = array(
    'image_style' => 'video_landing_page_170_x_127',
    'image_link' => 'content',
  );
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'personalization/my-saved-content';
  $export['personalization_saved_content'] = $view;

  return $export;
}
