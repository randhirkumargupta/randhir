<?php
/**
 * @file
 * features_for_newsletter.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function features_for_newsletter_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_cid'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_cid'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_cid',
    'label' => 'Content ID',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_ctype'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_ctype'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_ctype',
    'label' => 'Content Type',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_external_url'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_external_url'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Exp: http://example.com',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_external_url',
    'label' => 'External URL',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_kicker'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_kicker'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_kicker',
    'label' => 'Kicker',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_thumbnail'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_thumbnail'] = array(
    'bundle' => 'field_newsl_add_news',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_thumbnail',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'imce_filefield_on' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_title'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_title'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_title',
    'label' => 'Title',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_newsl_add_news-field_news_type'.
  $field_instances['field_collection_item-field_newsl_add_news-field_news_type'] = array(
    'bundle' => 'field_newsl_add_news',
    'default_value' => array(
      0 => array(
        'value' => 'internal',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_news_type',
    'label' => 'News Content',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_add_news'.
  $field_instances['node-newsletter-field_newsl_add_news'] = array(
    'bundle' => 'newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_add_news',
    'label' => 'Add News',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'field_collection_fieldset',
      'settings' => array(
        'collapsed' => 0,
        'field_as_label' => '',
        'last_item_collapsed' => 0,
        'new_item_open' => 0,
        'replace_label' => 0,
      ),
      'type' => 'field_collection_fieldset',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_date'.
  $field_instances['node-newsletter-field_newsl_date'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => 'Please select date.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_date',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_day'.
  $field_instances['node-newsletter-field_newsl_day'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 'Monday',
      ),
    ),
    'deleted' => 0,
    'description' => 'Please select day.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_day',
    'label' => 'Day',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_frequency'.
  $field_instances['node-newsletter-field_newsl_frequency'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 'daily',
      ),
    ),
    'deleted' => 0,
    'description' => 'Please choose newsletter frequency.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_frequency',
    'label' => 'Frequency',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_header_headline'.
  $field_instances['node-newsletter-field_newsl_header_headline'] = array(
    'bundle' => 'newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter header headline.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_header_headline',
    'label' => 'Header Headline',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_main_headline'.
  $field_instances['node-newsletter-field_newsl_main_headline'] = array(
    'bundle' => 'newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter main headline.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_main_headline',
    'label' => 'Main Headline',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_newsletter_content'.
  $field_instances['node-newsletter-field_newsl_newsletter_content'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 'top_20_trending',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_newsletter_content',
    'label' => 'Newsletter Content',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_newsletter_type'.
  $field_instances['node-newsletter-field_newsl_newsletter_type'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 'manual',
      ),
    ),
    'deleted' => 0,
    'description' => 'Please choose newsletter type.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_newsletter_type',
    'label' => 'Newsletter Type',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_time'.
  $field_instances['node-newsletter-field_newsl_time'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 12,
      ),
    ),
    'deleted' => 0,
    'description' => 'Please select time in hours.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_time',
    'label' => 'Time',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_time_period'.
  $field_instances['node-newsletter-field_newsl_time_period'] = array(
    'bundle' => 'newsletter',
    'default_value' => array(
      0 => array(
        'value' => 'AM',
      ),
    ),
    'deleted' => 0,
    'description' => 'Please select time period.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_time_period',
    'label' => 'Time Period',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-newsletter-field_newsl_website_name'.
  $field_instances['node-newsletter-field_newsl_website_name'] = array(
    'bundle' => 'newsletter',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select website name.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_newsl_website_name',
    'label' => 'Property (Website Name)',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add News');
  t('Content ID');
  t('Content Type');
  t('Date');
  t('Day');
  t('Exp: http://example.com');
  t('External URL');
  t('Frequency');
  t('Header Headline');
  t('Kicker');
  t('Main Headline');
  t('News Content');
  t('Newsletter Content');
  t('Newsletter Type');
  t('Please choose newsletter frequency.');
  t('Please choose newsletter type.');
  t('Please enter header headline.');
  t('Please enter main headline.');
  t('Please select date.');
  t('Please select day.');
  t('Please select time in hours.');
  t('Please select time period.');
  t('Please select website name.');
  t('Property (Website Name)');
  t('Thumbnail');
  t('Time');
  t('Time Period');
  t('Title');

  return $field_instances;
}
