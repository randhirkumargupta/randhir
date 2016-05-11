<?php
/**
 * @file
 * event_backend.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function event_backend_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_first|node|event_backend';
  $msnf->step_name = 'step_first';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_event_short_description',
      2 => 'field_story_url',
      3 => 'field_event_start_date',
      4 => 'field_event_close_date',
      5 => 'field_registration_close_date',
      6 => 'title',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Basic Details',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => '',
        ),
      ),
    ),
  );
  $export['step_first|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_last|node|event_backend';
  $msnf->step_name = 'step_last';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Highlights, Media, Configuration',
    'weight' => '3',
    'children' => array(
      0 => 'field_event_highlights',
      1 => 'field_event_media',
      2 => 'field_config_programme',
      3 => 'field_config_speakers',
      4 => 'field_config_sponsors',
      5 => 'field_config_photo',
      6 => 'field_config_video',
      7 => 'field_config_flashback',
      8 => 'field_config_home',
      9 => 'metatags',
      10 => 'path',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Highlights, Media, Configuration',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_last|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_program_schedule|node|event_backend';
  $msnf->step_name = 'step_program_schedule';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Program Schedule',
    'weight' => '2',
    'children' => array(
      0 => 'field_program_schedule',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Program Schedule',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_program_schedule|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_second|node|event_backend';
  $msnf->step_name = 'step_second';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Registration, Sponsor',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_type',
      1 => 'field_group_registration_fee_5',
      2 => 'field_group_registration_fee_10',
      3 => 'field_individual_registration_fe',
      4 => 'field_no_of_tickets',
      5 => 'field_associate_sponsors',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Registration, Sponsor',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Next',
          'skip' => 'Skip next step',
        ),
      ),
    ),
  );
  $export['step_second|node|event_backend'] = $msnf;

  return $export;
}
