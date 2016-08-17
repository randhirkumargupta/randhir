<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function get_anchor_landing_page_data($anchor_id) {
  $anchor_data = array();
  $anchor_data['node_load'] = node_load($anchor_id);
  return $anchor_data;
}