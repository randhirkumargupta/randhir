<?php

/**
 * @file: itg_event_registration_price_calculation_ajax.inc
 */

/**
 * Implements function for price calulate according group.
 */
function itg_event_registration_price_calculator_ajax() {
  $ajax_request = explode('-', $_POST['radio_value']);
  $event_nid = $_POST['total_fee'];
  $number =  $_POST['form_open'];
  $node = node_load($event_nid);
  foreach ($node->field_ticket_group_type[LANGUAGE_NONE] as $value) {
    $ticket_types[] = $value['value'];
  }
  $ticket_types = entity_load('field_collection_item', $ticket_types);
  if ($node->field_event_type[LANGUAGE_NONE][0]['value'] == 'paid') {
    if ($node->field_early_bird[LANGUAGE_NONE][0]['value'] != 'early_bird_offer') {
      foreach ($ticket_types as $types) {
        $individual = $types->field_individual_registration_fe[LANGUAGE_NONE][0]['value'];
        $participate = $types->field_participate_type[LANGUAGE_NONE][0]['tid'];
        $terms = taxonomy_term_load($participate);        
        $group_5_cal[$terms->tid] = $types->field_group_registration_fee_5[LANGUAGE_NONE][0]['value'];
        $group_10_cal[$terms->tid] = $types->field_group_registration_fee_10[LANGUAGE_NONE][0]['value'];
        $single_group[$terms->tid] = $individual;
      }
    }
    else {
      foreach ($ticket_types as $types) {
        $participate = $types->field_participate_type[LANGUAGE_NONE][0]['tid'];
        $individual = $types->field_early_bird_individual_regi[LANGUAGE_NONE][0]['value'];
        $terms = taxonomy_term_load($participate);
        $group_5_cal[$terms->tid] = $types->field_early_bird_group_registrat[LANGUAGE_NONE][0]['value'];
        $group_10_cal[$terms->tid] = $types->field_early_bird_group_10_reg[LANGUAGE_NONE][0]['value'];
        $single_group[$terms->tid] = $individual;
      }
    }
  }

  $ticket_type_value = $ajax_request[1];
  $group = '';
  if ($number > 9) {
    $number_10_remain = $number % 10;
    $val = $number - $number_10_remain;
    $group_10 = $val / 10;
    $group_ten_price = $group_10_cal[$ticket_type_value];
    $group_10 = $group_10 * $group_ten_price;
    if (!empty($number_10_remain)) {
      if ($number_10_remain < 9 && $number_10_remain > 4) {
        $number_5_remain = $number_10_remain % 5;
        $val_5 = $number_10_remain - $number_5_remain;
        $group_5 = $val_5 / 5;
        $group_five_price = $group_5_cal[$ticket_type_value];
        $group_5 = $group_5 * $group_five_price;
      }
      else {
        $single_10_price = $single_group[$ticket_type_value];
        $group_single_10 = $number_10_remain * $single_10_price;
      }
      if ($number_5_remain < 5 && !empty($number_5_remain)) {
        $single_price = $single_group[$ticket_type_value];
        $group_single_10 = $number_5_remain * $single_price;
      }
    }
    $group = $group_10 + $group_5 + $group_single_10;
  }
  elseif ($number <= 9 && $number > 4) {
    $number_5_remain = $number % 5;
    $val_5 = $number - $number_5_remain;
    $group_new_5 = $val_5 / 5;
    $group_five_price = $group_5_cal[$ticket_type_value];
    $group_new_5 = $group_new_5 * $group_five_price;
    if (!empty($number_5_remain)) {
      if ($number_5_remain < 5) {
        $single_price = $single_group[$ticket_type_value];
        $group_single_5 = $number_5_remain * $single_price;
      }
    }
    $group = $group_new_5 + $group_single_5;
  }
  elseif ($number < 5) {
    $single_price = $single_group[$ticket_type_value];
    $group = $number * $single_price;
  }
  echo $group;
}
