<?php

/**
 * @file
 *
 * Provides a handler that builds the string for user links we what to use with Linkit core.
 */
class linkit_picker_handler_field_solr_info extends views_handler_field {

  function query() {
    _linkit_picker_set_active_profile();
  }

  function render($values) {
    $value = array(
      'path' => $values->url,
      'title' => $values->label,
    );
    return drupal_json_encode($value);
  }
}