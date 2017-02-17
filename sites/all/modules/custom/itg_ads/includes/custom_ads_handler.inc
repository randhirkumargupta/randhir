<?php

/**
 * A handler to provide a field that will return ads status whether it is expired or not
  .*
 * @ingroup views_field_handlers
 */
class views_handler_custom_ads_ex_status extends views_handler_field {

  function query() {
    // do nothing -- to override the parent query.
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['alter']['contains']['alter_text'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['alter']['alter_text']);
    unset($form['alter']['text']['#dependency']);
    unset($form['alter']['text']['#process']);
  }

  function render($values) {
    $now = new DateTime();

    if (isset($values->field_field_ads_start_date[0]['raw']['value']) && !empty($values->field_field_ads_start_date[0]['raw']['value'])) {
      $startdate = new DateTime($values->field_field_ads_start_date[0]['raw']['value']);
    }

    if (isset($values->field_field_ads_end_date[0]['raw']['value']) && !empty($values->field_field_ads_end_date[0]['raw']['value'])) {
      $enddate = new DateTime($values->field_field_ads_end_date[0]['raw']['value']);
    }

    if (isset($startdate) && !empty($startdate) && isset($enddate) && !empty($enddate)) {

      if ($startdate <= $now && $now <= $enddate) {
        return 'Active';
      } else {
        return 'Inactive';
      }
    }
    else if (isset($startdate) && !empty($startdate) && !isset($enddate) && empty($enddate)) {
      if ($startdate <= $now) {
        return 'Active';
      } else {
        return 'Forthcoming';
      }
    }
  }

}