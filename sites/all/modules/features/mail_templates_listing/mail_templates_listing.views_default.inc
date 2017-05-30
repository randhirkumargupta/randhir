<?php
/**
 * @file
 * mail_templates_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function mail_templates_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mail_templates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mail Templates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Mail Templates';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>No Records Found</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Action';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_cms_status']['id'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['table'] = 'field_data_field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['field'] = 'field_cms_status';
  $handler->display->display_options['fields']['field_cms_status']['label'] = '';
  $handler->display->display_options['fields']['field_cms_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cms_status']['element_label_colon'] = FALSE;
  /* Field: Content: New Task Status */
  $handler->display->display_options['fields']['field_new_task_status']['id'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['table'] = 'field_data_field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['field'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['label'] = '';
  $handler->display->display_options['fields']['field_new_task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_task_status']['element_label_colon'] = FALSE;
  /* Field: Content: UGC Comments Status */
  $handler->display->display_options['fields']['field_ugc_comments_status']['id'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['table'] = 'field_data_field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['field'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['label'] = '';
  $handler->display->display_options['fields']['field_ugc_comments_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ugc_comments_status']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_cms_status]
[field_new_task_status]
[field_ugc_comments_status]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_mail_template_category']['id'] = 'field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['table'] = 'field_data_field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['field'] = 'field_mail_template_category';
  $handler->display->display_options['fields']['field_mail_template_category']['label'] = 'Template Category';
  $handler->display->display_options['fields']['field_mail_template_category']['element_label_colon'] = FALSE;
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
    'mail_templates' => 'mail_templates',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
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
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Mail Templates Category */
  $handler->display->display_options['fields']['field_mail_templates_category']['id'] = 'field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['table'] = 'field_data_field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['field'] = 'field_mail_templates_category';
  $handler->display->display_options['fields']['field_mail_templates_category']['label'] = 'Mail Templates';
  $handler->display->display_options['fields']['field_mail_templates_category']['element_label_colon'] = FALSE;
  /* Field: Content: New Task Status */
  $handler->display->display_options['fields']['field_new_task_status']['id'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['table'] = 'field_data_field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['field'] = 'field_new_task_status';
  $handler->display->display_options['fields']['field_new_task_status']['label'] = '';
  $handler->display->display_options['fields']['field_new_task_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_new_task_status']['element_label_colon'] = FALSE;
  /* Field: Content: UGC Comments Status */
  $handler->display->display_options['fields']['field_ugc_comments_status']['id'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['table'] = 'field_data_field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['field'] = 'field_ugc_comments_status';
  $handler->display->display_options['fields']['field_ugc_comments_status']['label'] = '';
  $handler->display->display_options['fields']['field_ugc_comments_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ugc_comments_status']['element_label_colon'] = FALSE;
  /* Field: Content: Ask an Expert Case */
  $handler->display->display_options['fields']['field_ask_an_expert_case']['id'] = 'field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['table'] = 'field_data_field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['field'] = 'field_ask_an_expert_case';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['label'] = '';
  $handler->display->display_options['fields']['field_ask_an_expert_case']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ask_an_expert_case']['element_label_colon'] = FALSE;
  /* Field: Content: Product Expiration Status */
  $handler->display->display_options['fields']['field_product_expiration_status']['id'] = 'field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['table'] = 'field_data_field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['field'] = 'field_product_expiration_status';
  $handler->display->display_options['fields']['field_product_expiration_status']['label'] = '';
  $handler->display->display_options['fields']['field_product_expiration_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_expiration_status']['element_label_colon'] = FALSE;
  /* Field: Content: Blog Status */
  $handler->display->display_options['fields']['field_blog_status']['id'] = 'field_blog_status';
  $handler->display->display_options['fields']['field_blog_status']['table'] = 'field_data_field_blog_status';
  $handler->display->display_options['fields']['field_blog_status']['field'] = 'field_blog_status';
  $handler->display->display_options['fields']['field_blog_status']['label'] = '';
  $handler->display->display_options['fields']['field_blog_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_status']['element_label_colon'] = FALSE;
  /* Field: Content: Photo Gallery Status */
  $handler->display->display_options['fields']['field_photo_gallery_status']['id'] = 'field_photo_gallery_status';
  $handler->display->display_options['fields']['field_photo_gallery_status']['table'] = 'field_data_field_photo_gallery_status';
  $handler->display->display_options['fields']['field_photo_gallery_status']['field'] = 'field_photo_gallery_status';
  $handler->display->display_options['fields']['field_photo_gallery_status']['label'] = '';
  $handler->display->display_options['fields']['field_photo_gallery_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_photo_gallery_status']['element_label_colon'] = FALSE;
  /* Field: Content: Podcast Status */
  $handler->display->display_options['fields']['field_podcast_status']['id'] = 'field_podcast_status';
  $handler->display->display_options['fields']['field_podcast_status']['table'] = 'field_data_field_podcast_status';
  $handler->display->display_options['fields']['field_podcast_status']['field'] = 'field_podcast_status';
  $handler->display->display_options['fields']['field_podcast_status']['label'] = '';
  $handler->display->display_options['fields']['field_podcast_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_podcast_status']['element_label_colon'] = FALSE;
  /* Field: Content: Story Status */
  $handler->display->display_options['fields']['field_story_status']['id'] = 'field_story_status';
  $handler->display->display_options['fields']['field_story_status']['table'] = 'field_data_field_story_status';
  $handler->display->display_options['fields']['field_story_status']['field'] = 'field_story_status';
  $handler->display->display_options['fields']['field_story_status']['label'] = '';
  $handler->display->display_options['fields']['field_story_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_story_status']['element_label_colon'] = FALSE;
  /* Field: Content: Video Status */
  $handler->display->display_options['fields']['field_video_status']['id'] = 'field_video_status';
  $handler->display->display_options['fields']['field_video_status']['table'] = 'field_data_field_video_status';
  $handler->display->display_options['fields']['field_video_status']['field'] = 'field_video_status';
  $handler->display->display_options['fields']['field_video_status']['label'] = '';
  $handler->display->display_options['fields']['field_video_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_status']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_expert']['id'] = 'field_mail_subject_expert';
  $handler->display->display_options['fields']['field_mail_subject_expert']['table'] = 'field_data_field_mail_subject_expert';
  $handler->display->display_options['fields']['field_mail_subject_expert']['field'] = 'field_mail_subject_expert';
  $handler->display->display_options['fields']['field_mail_subject_expert']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_expert']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_expert']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['id'] = 'field_mail_subject_follwo_story';
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['table'] = 'field_data_field_mail_subject_follwo_story';
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['field'] = 'field_mail_subject_follwo_story';
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_follwo_story']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject']['id'] = 'field_mail_subject';
  $handler->display->display_options['fields']['field_mail_subject']['table'] = 'field_data_field_mail_subject';
  $handler->display->display_options['fields']['field_mail_subject']['field'] = 'field_mail_subject';
  $handler->display->display_options['fields']['field_mail_subject']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_loyalty']['id'] = 'field_mail_subject_loyalty';
  $handler->display->display_options['fields']['field_mail_subject_loyalty']['table'] = 'field_data_field_mail_subject_loyalty';
  $handler->display->display_options['fields']['field_mail_subject_loyalty']['field'] = 'field_mail_subject_loyalty';
  $handler->display->display_options['fields']['field_mail_subject_loyalty']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_loyalty']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['id'] = 'field_mail_subject_photo_gallery';
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['table'] = 'field_data_field_mail_subject_photo_gallery';
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['field'] = 'field_mail_subject_photo_gallery';
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_photo_gallery']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['id'] = 'field_mail_subject_sign_up';
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['table'] = 'field_data_field_mail_subject_sign_up';
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['field'] = 'field_mail_subject_sign_up';
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_sign_up']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['id'] = 'field_mail_subject_product_expir';
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['table'] = 'field_data_field_mail_subject_product_expir';
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['field'] = 'field_mail_subject_product_expir';
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_product_expir']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['id'] = 'field_mail_subject_password_chan';
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['table'] = 'field_data_field_mail_subject_password_chan';
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['field'] = 'field_mail_subject_password_chan';
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_password_chan']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_blog']['id'] = 'field_mail_subject_blog';
  $handler->display->display_options['fields']['field_mail_subject_blog']['table'] = 'field_data_field_mail_subject_blog';
  $handler->display->display_options['fields']['field_mail_subject_blog']['field'] = 'field_mail_subject_blog';
  $handler->display->display_options['fields']['field_mail_subject_blog']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_blog']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_blog']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['id'] = 'field_mail_subject_quiz_completi';
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['table'] = 'field_data_field_mail_subject_quiz_completi';
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['field'] = 'field_mail_subject_quiz_completi';
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_quiz_completi']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_print_t']['id'] = 'field_mail_subject_print_t';
  $handler->display->display_options['fields']['field_mail_subject_print_t']['table'] = 'field_data_field_mail_subject_print_t';
  $handler->display->display_options['fields']['field_mail_subject_print_t']['field'] = 'field_mail_subject_print_t';
  $handler->display->display_options['fields']['field_mail_subject_print_t']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_print_t']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_print_t']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_story']['id'] = 'field_mail_subject_story';
  $handler->display->display_options['fields']['field_mail_subject_story']['table'] = 'field_data_field_mail_subject_story';
  $handler->display->display_options['fields']['field_mail_subject_story']['field'] = 'field_mail_subject_story';
  $handler->display->display_options['fields']['field_mail_subject_story']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_story']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_story']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_video']['id'] = 'field_mail_subject_video';
  $handler->display->display_options['fields']['field_mail_subject_video']['table'] = 'field_data_field_mail_subject_video';
  $handler->display->display_options['fields']['field_mail_subject_video']['field'] = 'field_mail_subject_video';
  $handler->display->display_options['fields']['field_mail_subject_video']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_video']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject */
  $handler->display->display_options['fields']['field_mail_subject_podcast']['id'] = 'field_mail_subject_podcast';
  $handler->display->display_options['fields']['field_mail_subject_podcast']['table'] = 'field_data_field_mail_subject_podcast';
  $handler->display->display_options['fields']['field_mail_subject_podcast']['field'] = 'field_mail_subject_podcast';
  $handler->display->display_options['fields']['field_mail_subject_podcast']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_podcast']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_podcast']['element_label_colon'] = FALSE;
  /* Field: Content: Mail Subject Task/Idea */
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['id'] = 'field_mail_subject_task_idea';
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['table'] = 'field_data_field_mail_subject_task_idea';
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['field'] = 'field_mail_subject_task_idea';
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['label'] = '';
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_mail_subject_task_idea']['element_label_colon'] = FALSE;
  /* Field: Mail Templates: Mail Templates */
  $handler->display->display_options['fields']['custom_handler']['id'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['table'] = 'mail_templates';
  $handler->display->display_options['fields']['custom_handler']['field'] = 'custom_handler';
  $handler->display->display_options['fields']['custom_handler']['label'] = '';
  $handler->display->display_options['fields']['custom_handler']['exclude'] = TRUE;
  $handler->display->display_options['fields']['custom_handler']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Subject';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_mail_subject_expert]
[field_mail_subject_follwo_story]
[field_mail_subject]
[field_mail_subject_loyalty]
[field_mail_subject_photo_gallery]
[field_mail_subject_sign_up]
[field_mail_subject_product_expir]
[field_mail_subject_password_chan]
[field_mail_subject_blog]
[field_mail_subject_quiz_completi]
[field_mail_subject_print_t]
[field_mail_subject_story]
[field_mail_subject_video]
[field_mail_subject_podcast]
[field_mail_subject_task_idea]';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Template Status';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_blog_status]
[field_photo_gallery_status]
[field_podcast_status]
[field_story_status]
[field_video_status]
[field_new_task_status]
[field_ugc_comments_status]
[field_ask_an_expert_case]
[field_product_expiration_status]
[custom_handler]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Action';
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
    'mail_templates' => 'mail_templates',
  );
  /* Filter criterion: Content: Mail Templates Category (field_mail_templates_category) */
  $handler->display->display_options['filters']['field_mail_templates_category_value']['id'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['table'] = 'field_data_field_mail_templates_category';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['field'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['operator_id'] = 'field_mail_templates_category_value_op';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['label'] = 'Select Mail Events';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['operator'] = 'field_mail_templates_category_value_op';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['identifier'] = 'field_mail_templates_category_value';
  $handler->display->display_options['filters']['field_mail_templates_category_value']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'mail-templates';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mail Templates';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-left-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['mail_templates'] = $view;

  return $export;
}
