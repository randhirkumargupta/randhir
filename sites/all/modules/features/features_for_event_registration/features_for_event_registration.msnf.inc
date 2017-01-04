<?php
/**
 * @file
 * features_for_event_registration.msnf.inc
 */

/**
 * Implements hook_msnf_step_info().
 */
function features_for_event_registration_msnf_step_info() {
  $export = array();

  $msnf = new stdClass();
  $msnf->disabled = TRUE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_erf_basic_details|node|event_registration';
  $msnf->step_name = 'step_erf_basic_details';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_registration';
  $msnf->data = array(
    'label' => 'Step 1 - Basic Details:',
    'weight' => '0',
    'children' => array(
      0 => 'field_last_name',
      1 => 'field_erf_gender',
      2 => 'field_erf_mobile',
      3 => 'field_email_address',
      4 => 'field_erf_select_id_type',
      5 => 'field_erf_id_number',
      6 => 'title',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 1 - Basic Details:',
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
  $export['step_erf_basic_details|node|event_registration'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = TRUE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_erf_company_details|node|event_registration';
  $msnf->step_name = 'step_erf_company_details';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_registration';
  $msnf->data = array(
    'label' => 'Step 2 - Company Details:',
    'weight' => '1',
    'children' => array(
      0 => 'field_erf_company_name',
      1 => 'field_erf_designation',
      2 => 'field_erf_mailing_address',
      3 => 'field_erf_postal_code',
      4 => 'field_erf_country',
      5 => 'field_erf_state',
      6 => 'field_erf_city',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 2 - Company Details:',
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
  $export['step_erf_company_details|node|event_registration'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = TRUE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_erf_order_summary|node|event_registration';
  $msnf->step_name = 'step_erf_order_summary';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_registration';
  $msnf->data = array(
    'label' => 'Step 4 - Order Summary:',
    'weight' => '4',
    'children' => array(
      0 => 'field_erf_payment_gateway',
      1 => 'field_erf_total_fee',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 4 - Order Summary:',
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
  $export['step_erf_order_summary|node|event_registration'] = $msnf;

  $msnf = new stdClass();
  $msnf->disabled = TRUE; /* Edit this to true to make a default msnf disabled initially */
  $msnf->api_version = 1;
  $msnf->identifier = 'step_erf_registration_fee|node|event_registration';
  $msnf->step_name = 'step_erf_registration_fee';
  $msnf->entity_type = 'node';
  $msnf->bundle = 'event_registration';
  $msnf->data = array(
    'label' => 'Step 3 - Registration Details:',
    'weight' => '2',
    'children' => array(
      0 => 'field_erf_registration_fee',
      1 => 'field_erf_type',
    ),
    'format_type' => 'default',
    'format_settings' => array(
      'label' => 'Step 3 - Registration Details:',
      'instance_settings' => array(
        'skip_non_required' => 1,
        'hide_if_empty' => 0,
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h2',
        'buttons' => array(
          'previous' => 'Back',
          'next' => 'Proceed to Payment',
          'skip' => '',
        ),
      ),
    ),
  );
  $export['step_erf_registration_fee|node|event_registration'] = $msnf;

  return $export;
}
