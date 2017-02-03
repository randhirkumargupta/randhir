<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function _get_unique_id_for_node_field($nid) {
  if (empty($nid)) {
    if (!empty($_SESSION['node_preview_unique'])) {
      $reporter_id = $_SESSION['node_preview_unique'];
    }
    else {
      $unique = 'preview_' . uniqid() . time();
      $_SESSION['node_preview_unique'] = $unique;
      $reporter_id = $_SESSION['node_preview_unique'];
    }
    return $reporter_id;
  }
  return FALSE;
}