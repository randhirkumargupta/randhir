<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function itg_latest_issue_article_report() {
  $arg = arg();

  if (!empty($arg[1])) {
    $issue_title = date("Y-m-d 00:00:00", strtotime($arg[1]));
    $query = db_select('node', 'n');
    $query->join('field_data_field_story_issue_date', 'isuue', 'n.nid=isuue.entity_id');
    $query->condition('isuue.field_story_issue_date_value', $issue_title, '=');
    $query->condition('n.status', 1);
    $query->condition('n.type', 'story', '=');
    $query->fields('n', array('nid'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $issue_story_res = array();
    foreach ($result as $issue_story) {
      $issue_story_res[] = array(
        'url' => FRONT_URL . "/" . drupal_get_path_alias('node/' . $issue_story['nid']),
        'nid' => $issue_story['nid']
      );
    }
    echo json_encode($issue_story_res);
    drupal_exit();
  }
  else {
    $query = db_select('node', 'n');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->condition('n.status', 1);
    $query->condition('n.type', 'issue');
    $query->orderBy('n.nid', "DESC");
    $query->range(0, 30);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $latest_issue = array();
    foreach ($result as $value) {
      $latest_issue[] = array(
        'id' => $value['nid'],
        'title' => date("Y-m-d", strtotime($value['title'])),
        'created_date' => date("Y-m-d", $value['created']),
      );
    }
    echo json_encode($latest_issue);
    drupal_exit();
  }
}
