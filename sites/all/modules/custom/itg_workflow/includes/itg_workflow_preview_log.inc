<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function _get_unique_id_for_node_field() {
  $arg = arg();
if (!empty($_SESSION['node_preview_unique'])) {
      $reporter_id = $_SESSION['node_preview_unique'];
    }
    else {
      // format uniqueid time node add
      // format uniqueid time nodeid edit
      // So in future we can track from which opration this entry is made.
      
      $unique = 'preview_' . uniqid() . time() . "_" .$arg[1] . "_" .$arg[2];
      $_SESSION['node_preview_unique'] = $unique;
      $reporter_id = $_SESSION['node_preview_unique'];
    }
    return $reporter_id;
}