<?php
/**
 * @file
 * feature_category_management.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_category_management_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_display_title'.
  $field_instances['taxonomy_term-category_management-field_cm_display_title'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter display title, it will appear on the front end if user has entered.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_display_title',
    'label' => 'Display Title',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_hide_cat_from_home'.
  $field_instances['taxonomy_term-category_management-field_cm_hide_cat_from_home'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you checked this option, category name will not appear on front end navigation.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_hide_cat_from_home',
    'label' => 'Hide Category form home',
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

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_hide_cat_from_search'.
  $field_instances['taxonomy_term-category_management-field_cm_hide_cat_from_search'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you checked this option, then this category would not be able to search in google search.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_hide_cat_from_search',
    'label' => 'Hide Category from search',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_no_follow'.
  $field_instances['taxonomy_term-category_management-field_cm_no_follow'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you checked this option, "No Follow" link will be embedded in category URL. ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_no_follow',
    'label' => 'No Follow',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_redirection_url'.
  $field_instances['taxonomy_term-category_management-field_cm_redirection_url'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please enter the redirection URL (http://example.com). Reader will be redirected to the respective URL by clicking on the category name.
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_redirection_url',
    'label' => 'Redirection URL',
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
  // 'taxonomy_term-category_management-field_cm_select_type'.
  $field_instances['taxonomy_term-category_management-field_cm_select_type'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please select content type, this category will be associated to selected content types. You can associate one category with multiple content types.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_select_type',
    'label' => 'Content Type',
    'required' => 1,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_sponsored_category'.
  $field_instances['taxonomy_term-category_management-field_cm_sponsored_category'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If you checked this option, category will be marked as sponsored and will appear in the category listing page with special flag "Sponsored". ',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_sponsored_category',
    'label' => 'Sponsored Category',
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
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_sponser_logo'.
  $field_instances['taxonomy_term-category_management-field_sponser_logo'] = array(
    'bundle' => 'category_management',
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
        'weight' => 8,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_sponser_logo',
    'label' => 'Category Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => 'category_icon',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 1,
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
            'imce' => 'imce',
            'plupload' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 1,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 1,
          ),
        ),
        'imce_filefield_on' => 0,
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_user_city'.
  $field_instances['taxonomy_term-category_management-field_user_city'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_user_city',
    'label' => ' Program Timing',
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
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Program Timing');
  t('Category Icon');
  t('Content Type');
  t('Display Title');
  t('Hide Category form home');
  t('Hide Category from search');
  t('If you checked this option, "No Follow" link will be embedded in category URL. ');
  t('If you checked this option, category name will not appear on front end navigation.');
  t('If you checked this option, category will be marked as sponsored and will appear in the category listing page with special flag "Sponsored". ');
  t('If you checked this option, then this category would not be able to search in google search.');
  t('No Follow');
  t('Please enter display title, it will appear on the front end if user has entered.');
  t('Please enter the redirection URL (http://example.com). Reader will be redirected to the respective URL by clicking on the category name.
');
  t('Please select content type, this category will be associated to selected content types. You can associate one category with multiple content types.');
  t('Redirection URL');
  t('Sponsored Category');

  return $field_instances;
}
