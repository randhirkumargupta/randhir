<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function itg_menu_manager_custom_variables() {
  $form = array();
  $form['menu_manager_custom_url'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter Urls in which menu custom link will display'),
    '#default_value' => variable_get('menu_manager_custom_url'),
    '#rows' => 10,
    '#cols' => 60,
    '#resizable' => TRUE,
  );
  return system_settings_form($form);
}

/**
 * Callback function autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_menu_manager_autosuggest($tid) {
  if (strlen(trim($tid)) > 0) {
    $options = array();

    $vid = taxonomy_vocabulary_machine_name_load('category_management')->vid;

    $query = db_select('taxonomy_term_data', 'ttd')
        ->fields('ttd', array('tid'))
        ->condition('ttd. tid', '%' . $tid . '%', 'LIKE')
        ->condition('ttd. vid', $vid);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $options[$record['tid']] = $record['tid'];
    }

    drupal_json_output($options);
  }
}

/**
 * Callback function for autosuggest autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_menu_manager_autosuggest_third() {
  $arg = arg();
  $tid = $arg[3];
  $section_id = $arg[1];
  $options = array();

  $vid = taxonomy_vocabulary_machine_name_load('category_management')->vid;

  $query = db_select('taxonomy_term_data', 'ttd');
  $query->leftJoin('taxonomy_term_hierarchy', 'th', 'ttd.tid=th.tid');
  $query->fields('ttd', array('tid'))
      ->condition('ttd. tid', '%' . $tid . '%', 'LIKE')
      ->condition('th. parent', $section_id)
      ->condition('ttd. vid', $vid);
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $options[$record['tid']] = $record['tid'];
  }

  drupal_json_output($options);
}

/**
 * Function is used to delete row in itg_menu_manager.
 * @param int $tid
 * @return type
 */
function remove_from_menu_manager($tid) {

  if (is_numeric($tid)) {
    db_delete('itg_menu_manager')->condition('id', $tid)->execute();
  }
//  else {
//    drupal_set_message("Please enter tid");
//  }
//  if ($_GET['section_id'] && $_GET['section_child']) {
//    $destination = "menu-manager/third";
//    $options = array('query' => array("section_id" => $_GET['section_id'], "section_child" => $_GET['section_child']));
//    drupal_goto($_SERVER['HTTP_REFERER']);
//  }
  drupal_goto($_SERVER['HTTP_REFERER']);
}
