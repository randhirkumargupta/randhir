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
  // 'taxonomy_term-category_management-field_category_app_description'.
  $field_instances['taxonomy_term-category_management-field_category_app_description'] = array(
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
        'weight' => 20,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_category_app_description',
    'label' => 'App description',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_category_section_flag'.
  $field_instances['taxonomy_term-category_management-field_category_section_flag'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_category_section_flag',
    'label' => 'Section flag',
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
  // 'taxonomy_term-category_management-field_category_section_type'.
  $field_instances['taxonomy_term-category_management-field_category_section_type'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_category_section_type',
    'label' => 'Section type',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_category_banner'.
  $field_instances['taxonomy_term-category_management-field_cm_category_banner'] = array(
    'bundle' => 'category_management',
    'deleted' => 0,
    'description' => 'Image Size (650x45)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_category_banner',
    'label' => 'Category Banner Icon',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => 'category_banner',
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
            'imce' => 0,
            'itg_image_repository' => 'itg_image_repository',
            'itg_image_video' => 0,
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
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_category_color'.
  $field_instances['taxonomy_term-category_management-field_cm_category_color'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'color_field',
        'settings' => array(),
        'type' => 'color_field_default_formatter',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_category_color',
    'label' => 'Category Banner Colour',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'color_field',
      'settings' => array(),
      'type' => 'color_field_spectrum_widget',
      'weight' => 22,
    ),
  );

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
      'weight' => 10,
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
      'weight' => 15,
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
      'weight' => 14,
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
      'weight' => 16,
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_select_template'.
  $field_instances['taxonomy_term-category_management-field_cm_select_template'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_select_template',
    'label' => 'Select template',
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
      'weight' => 21,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_cm_select_template_type'.
  $field_instances['taxonomy_term-category_management-field_cm_select_template_type'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_cm_select_template_type',
    'label' => 'Select template type',
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
      'weight' => 20,
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
      'weight' => 18,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_description'.
  $field_instances['taxonomy_term-category_management-field_description'] = array(
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
        'weight' => 10,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_description',
    'label' => 'Description',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_issue_free'.
  $field_instances['taxonomy_term-category_management-field_issue_free'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_issue_free',
    'label' => 'Issue free',
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
  // 'taxonomy_term-category_management-field_old_content_source_id'.
  $field_instances['taxonomy_term-category_management-field_old_content_source_id'] = array(
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
        'weight' => 22,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_old_content_source_id',
    'label' => 'Source id',
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
      'weight' => 25,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_program_timing_in_days'.
  $field_instances['taxonomy_term-category_management-field_program_timing_in_days'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Ex.(Monday To Friday)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_program_timing_in_days',
    'label' => 'Program timing in days',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
  // 'taxonomy_term-category_management-field_result_format'.
  $field_instances['taxonomy_term-category_management-field_result_format'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_result_format',
    'label' => 'Result format',
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
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_set_as_featured_cate'.
  $field_instances['taxonomy_term-category_management-field_set_as_featured_cate'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_set_as_featured_cate',
    'label' => 'Set As Featured',
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
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_sponser_logo'.
  $field_instances['taxonomy_term-category_management-field_sponser_logo'] = array(
    'bundle' => 'category_management',
    'deleted' => 0,
    'description' => 'Image Size (40x35)',
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
            'imce' => 0,
            'itg_image_repository' => 'itg_image_repository',
            'itg_image_video' => 0,
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_time_period'.
  $field_instances['taxonomy_term-category_management-field_time_period'] = array(
    'bundle' => 'category_management',
    'default_value' => array(
      0 => array(
        'value' => 'am',
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
        'weight' => 17,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_time_period',
    'label' => 'Time Period',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'taxonomy_term-category_management-field_user_city'.
  $field_instances['taxonomy_term-category_management-field_user_city'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '00:00',
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
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
  // 'taxonomy_term-category_management-field_user_name'.
  $field_instances['taxonomy_term-category_management-field_user_name'] = array(
    'bundle' => 'category_management',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '1 Hrs,2Hrs...',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'exclude_cv' => 0,
    'field_name' => 'field_user_name',
    'label' => 'Schedule duration',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
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
      'weight' => 16,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Program Timing');
  t('00:00');
  t('1 Hrs,2Hrs...');
  t('App description');
  t('Category Banner Colour');
  t('Category Banner Icon');
  t('Category Icon');
  t('Content Type');
  t('Description');
  t('Display Title');
  t('Ex.(Monday To Friday)');
  t('Hide Category form home');
  t('Hide Category from search');
  t('If you checked this option, "No Follow" link will be embedded in category URL. ');
  t('If you checked this option, category name will not appear on front end navigation.');
  t('If you checked this option, category will be marked as sponsored and will appear in the category listing page with special flag "Sponsored". ');
  t('If you checked this option, then this category would not be able to search in google search.');
  t('Image Size (40x35)');
  t('Image Size (650x45)');
  t('Issue free');
  t('No Follow');
  t('Please enter display title, it will appear on the front end if user has entered.');
  t('Please enter the redirection URL (http://example.com). Reader will be redirected to the respective URL by clicking on the category name.
');
  t('Please select content type, this category will be associated to selected content types. You can associate one category with multiple content types.');
  t('Program timing in days');
  t('Redirection URL');
  t('Result format');
  t('Schedule duration');
  t('Section flag');
  t('Section type');
  t('Select template');
  t('Select template type');
  t('Set As Featured');
  t('Source id');
  t('Sponsored Category');
  t('Time Period');

  return $field_instances;
}
