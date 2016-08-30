<?php
/**
 * @file
 * features_for_notification.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function features_for_notification_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_android_details|node|notification|form';
  $field_group->group_name = 'group_android_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'notification';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Android Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_survey_question',
      1 => 'field_ntf_android_vibration',
      2 => 'field_news_thumbnail',
      3 => 'field_newst_banner',
      4 => 'field_ntf_android_sound',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Android Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'android-details',
        'classes' => 'group-android-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_android_details|node|notification|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notification_details|node|notification|form';
  $field_group->group_name = 'group_notification_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'notification';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Details',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_cm_redirection_url',
      2 => 'field_ntf_select_device',
      3 => 'field_ntf_assign_story',
      4 => 'field_news_cid',
      5 => 'field_ntf_schedule',
      6 => 'title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Notification Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'notification-details',
        'classes' => 'group-notification-details field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_notification_details|node|notification|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Android Details');
  t('Notification Details');

  return $field_groups;
}
