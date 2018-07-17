<?php

/**
 * Implements itg_live_tv_details
 */
function itg_live_tv_details() {
  $n_id = $_POST['company'];
  $device = $_POST['device'];
  // check if value is exist
  if (!empty($n_id) && !empty($device)) {
    $exist_val = itg_live_tv_company($device);
    $errors = array_filter($exist_val);

    if (!empty($errors)) {
      foreach ($exist_val as $val) {
        $node = node_load($val);
        foreach ($node->field_live_tv_device[LANGUAGE_NONE] as $key => $value) {
          if ($value['value'] == $device) {
            unset($node->field_live_tv_device[LANGUAGE_NONE][$key]);
            field_attach_presave('node', $node);
            field_attach_update('node', $node);
            // Clear the static loading cache.
            entity_get_controller('node')->resetCache(array($node->nid));
            itg_live_tv_insert($n_id, $device);
          }
        }
      }
    }
    else {
      itg_live_tv_insert($n_id, $device);
    }
  }
}