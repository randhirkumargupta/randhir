<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * 
 * @param array $updates
 */
function save_itg_widget_personalization_data($updates) {
  $widget_name = "personalization_widget";
  foreach ($updates as $termId => $weight) {
    db_merge('itg_widget_order')
            ->key(array('nid' => $termId, 'widget' => $widget_name))
            ->fields(array(
                'nid' => $termId,
                'widget' => $widget_name,
                'weight' => $weight,
            ))
            ->execute();
  }
  drupal_set_message("My Preferences Has Been Save");
}


function get_personalization_saved_value($tid) {
  $query = db_select('itg_widget_order','iwo');
  $query->addField('iwo','weight');
  $query->condition('iwo.nid',$tid);
  return $query->execute()->fetch();
}