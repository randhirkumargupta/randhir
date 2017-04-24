<?php
/**
 * @file
 * features_for_highlights.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function features_for_highlights_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_emoji_condition'.
  $field_instances['field_collection_item-field_highlights-field_emoji_condition'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 0,
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
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_emoji_condition',
    'label' => 'Display',
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
  // 'field_collection_item-field_highlights-field_field_emoji1_title'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji1_title'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 'Oh Nice!',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_field_emoji1_title',
    'label' => 'Emoji title',
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
  // 'field_collection_item-field_highlights-field_field_emoji2_title'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji2_title'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 'Oh No!',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_field_emoji2_title',
    'label' => 'Emoji title',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_field_emoji3_title'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji3_title'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 'Whatever!',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_field_emoji3_title',
    'label' => 'Emoji title',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_field_emoji_highlights_1'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji_highlights_1'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 1,
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
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_field_emoji_highlights_1',
    'label' => 'field_emoji_highlights_1',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_field_emoji_highlights_2'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji_highlights_2'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 1,
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_field_emoji_highlights_2',
    'label' => 'field_emoji_highlights_2',
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

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_field_emoji_highlights_3'.
  $field_instances['field_collection_item-field_highlights-field_field_emoji_highlights_3'] = array(
    'bundle' => 'field_highlights',
    'default_value' => array(
      0 => array(
        'value' => 1,
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
    'field_name' => 'field_field_emoji_highlights_3',
    'label' => 'field_emoji_highlights_3',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_highlights_text'.
  $field_instances['field_collection_item-field_highlights-field_highlights_text'] = array(
    'bundle' => 'field_highlights',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_highlights_text',
    'label' => 'Text',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_highlights-field_highlights_url'.
  $field_instances['field_collection_item-field_highlights-field_highlights_url'] = array(
    'bundle' => 'field_highlights',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Example: http://example.com',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'exclude_cv' => 0,
    'field_name' => 'field_highlights_url',
    'label' => 'URL',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-heighlights-field_highlights'.
  $field_instances['node-heighlights-field_highlights'] = array(
    'bundle' => 'heighlights',
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
        'weight' => 0,
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
    'field_name' => 'field_highlights',
    'label' => 'Highlights',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Display');
  t('Emoji title');
  t('Example: http://example.com');
  t('Highlights');
  t('Text');
  t('URL');
  t('field_emoji_highlights_1');
  t('field_emoji_highlights_2');
  t('field_emoji_highlights_3');

  return $field_instances;
}
