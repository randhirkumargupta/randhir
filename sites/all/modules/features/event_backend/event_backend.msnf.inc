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
  $msnf->identifier = 'step_configuration|node|event_backend';
  $msnf->step_name = 'step_configuration';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step7-Configuration',
    'weight' => '7',
    'children' => array(
      0 => 'field_associate_event_photo',
      1 => 'field_associate_event_video',
      2 => 'field_config_flashback',
      3 => 'field_config_home',
      4 => 'field_config_photo',
      5 => 'field_config_programme',
      6 => 'field_config_speakers',
      7 => 'field_config_sponsors',
      8 => 'field_config_video',
      9 => 'field_e_associate_highlights',
      10 => 'field_e_content_font_color',
      11 => 'field_e_event_banner',
      12 => 'field_e_heading_bck_color',
      13 => 'field_e_highlighted_font_color',
      14 => 'field_e_menu_bck_color',
      15 => 'field_e_menu_font_color',
      16 => 'field_e_program_title_color',
      17 => 'field_e_tab_color',
      18 => 'field_event_twitter',
      19 => 'field_force_registration_open',
      20 => 'field_story_expert_description',
      21 => 'field_news_title',
      22 => 'field_story_new_title',
      23 => 'field_tab_description',
      24 => 'field_tab_on_off',
      25 => 'field_testsss',
      26 => 'metatags',
      27 => 'path',
      28 => 'additional_settings',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step7-Configuration',
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
  $export['step_configuration|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_first|node|event_backend';
  $msnf->step_name = 'step_first';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step1-Basic Details',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_event_close_date',
      2 => 'field_event_short_description',
      3 => 'field_event_start_date',
      4 => 'field_event_types',
      5 => 'field_registration_close_date',
      6 => 'field_story_expiry_date',
      7 => 'field_story_kicker_text',
      8 => 'field_registration_date_checkbox',
      9 => 'title',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step1-Basic Details',
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
  $msnf->identifier = 'step_highlights|node|event_backend';
  $msnf->step_name = 'step_highlights';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step5-Highlights',
    'weight' => '4',
    'children' => array(
      0 => 'field_event_highlights',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step5-Highlights',
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
  $export['step_highlights|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = TRUE; /* Edit this to true to make a default msnf disabled initially */
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
  $msnf->identifier = 'step_media|node|event_backend';
  $msnf->step_name = 'step_media';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step6-Media',
    'weight' => '6',
    'children' => array(
      0 => 'field_event_media',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step6-Media',
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
  $export['step_media|node|event_backend'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_program_schedule|node|event_backend';
  $msnf->step_name = 'step_program_schedule';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step3-Program Schedule',
    'weight' => '2',
    'children' => array(
      0 => 'field_program_schedule',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step3-Program Schedule',
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
    'label' => 'Step2-Registration Fees',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_type',
      1 => 'field_no_of_tickets',
      2 => 'field_ticket_group_type',
      3 => 'field_early_bird',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step2-Registration Fees',
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

  $msnf = new stdClass();
  $msnf->disabled = FALSE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_sponsor|node|event_backend';
  $msnf->step_name = 'step_sponsor';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_backend';
  $msnf->data = array(
    'label' => 'Step4-Sponsor',
    'weight' => '3',
    'children' => array(
      0 => 'field_associate_sponsors',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step4-Sponsor',
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
  $export['step_sponsor|node|event_backend'] = $msnf;

  return $export;
}
