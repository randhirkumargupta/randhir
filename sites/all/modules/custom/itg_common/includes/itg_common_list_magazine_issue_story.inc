<?php

/*
 * Inc file contains the helper functions for magazine supplement listing
 * 
 * 
 */

/**
 * Implements itg_get_magazine_story_name().
 * @param string $id
 * @return array $data
 */
function itg_get_magazine_story_name($id = '') {
  $select = t('- None -');
  $data = array('_none' => $select);
  $query = db_select('node' , 'n');
  $query->fields('n' , array('title' , 'nid'));
  $query->condition('n.status' , 1 , '=');
  $query->condition('n.type' , 'magazine' , '=');
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $data[$record['nid']] = $record['title'];
  }
  return $data;
}

/**
 * Implements itg_get_magazine_issue_callback().
 * Helper function to populate the issue dropdown.
 * @param string $mag_id
 * @return array $data
 */
function itg_get_magazine_issue_callback($mag_id = NULL) {
  
  if (isset($mag_id)) {
    $mag_id = $mag_id;
  } else {
    $mag_id = $_POST['magazine'];
  }
  
  try {
  $itg_query = db_select('field_data_field_issue_magazine', 'fe');
  $itg_query->fields('fe', array('entity_id'));
  $itg_query->condition('fe.field_issue_magazine_target_id', $mag_id);
  $itg_query->condition('fe.bundle', 'issue');

  $itg_result = $itg_query->execute()->fetchAll();
  } catch (Exception $e) {
   watchdog('magazine_query', $e->getMessage());
  }

  if (empty($_POST['magazine'])) {
    $select = t('- Select -');
    $data = array('' => $select);
    foreach ($itg_result as $itg_val) {
      $title = itg_common_get_node_title($itg_val->entity_id);
      $dt = date('Y-m-d', strtotime($title));
      $data[$dt] = date('d/m/Y', strtotime($title));
    }
    return $data;
  } else {
    $drop = '<option value="">- Select -</option>';
    foreach ($itg_result as $itg_val) {
      $title = itg_common_get_node_title($itg_val->entity_id);
      $dt = date('Y-m-d', strtotime($title));
      $data[$dt] = date('d/m/Y', strtotime($title));
      $drop .= '<option value="' . $dt . '">' . date('d/m/Y', strtotime($title)) . '</option>';
    }

    echo $drop;
  }
}

/**
 * Implements itg_get_supplement_issue_callback().
 * Helper function to populate the supplement dropdown.
 * @param string $supp_id
 * @return array $data
 */
function itg_get_supplement_issue_callback($supp_id = NULL) {
  if (isset($supp_id)) {
    $supp_id = $supp_id.' 00:00:00';
  } else {
    $supp_id = $_POST['issue'].' 00:00:00';
  }
  try {
  $itg_query = db_select('node', 'n');
  $itg_query->join('field_data_field_issue_supplement', 'sc', 'n.nid = sc.entity_id');
  $itg_query->fields('n', array('nid'));
  $itg_query->fields('sc', array('field_issue_supplement_target_id'));
  $itg_query->condition('n.type', 'issue');
  $itg_query->condition('n.status', 1);
  $itg_query->condition('n.title', $supp_id);
  $itg_query->condition('sc.bundle', 'issue');
  

  $itg_result = $itg_query->execute()->fetchAll();
  } catch (Exception $e) {
   watchdog('issue_query', $e->getMessage());
  }
  
  if (empty($_POST['issue'])) {
    $select = t('- None -');
    $data = array('' => $select);
    foreach ($itg_result as $key => $itg_val) {
      $title = itg_common_get_node_title($itg_val->field_issue_supplement_target_id);
      $dt = date('Y-m-d', strtotime($title));
      $data[$itg_val->field_issue_supplement_target_id] = $title;
    }
    return $data;
  } else {
    $drop = '<option value="">- Select -</option>';
    foreach ($itg_result as $key => $itg_val) {
      $title = itg_common_get_node_title($itg_val->field_issue_supplement_target_id);
      $drop .= '<option value="' . $itg_val->field_issue_supplement_target_id . '">' . $title . '</option>';
    }

    echo $drop;
  }
}
