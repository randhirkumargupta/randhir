<?php

/*
 * Inc file contains the helper functions
 */
/**
 * Get breakingnews  id
 * @param int $breaking_id
 * @return int $itg_result
 */
function get_breaking_id($breaking_id) {  
  $query = db_select('field_data_field_source', 'fs');
  $query->fields('fs', array('entity_id'));  
  $query->condition('fs.bundle', 'breaking_news');
  $query->condition('fs.field_source_value', $breaking_id);
  $itg_result = $query->execute()->fetchField();
  
  return $itg_result;
}

/**
 * Implements function for issue exit or not
 * @param string $issue_date
 * @return bool
 */
function itg_story_checked_issue($issue_date) {
  $result = db_select('node', 'node')
    ->fields('node', array('title'))
    ->condition('title', $issue_date, '=')
    ->condition('type', 'issue', '=')
    ->execute()->fetchAssoc();

  if (empty($result['title'])) {
    return FALSE;
  }

  return TRUE;
}


/**
 * Callback for migatred content count
 * 
 */
function itg_get_migrated_like_count($nid) {
  if (!empty($nid)) {
    $query = db_select('itg_custom_flag_count', 'mg');
    $query->fields('mg');
    $query->condition('mg.nid', $nid);
    $query->orderBy('mg.created', 'DESC'); //ORDER BY created
    $result = $query->execute();
    return $record = $result->fetchAll(PDO::FETCH_ASSOC);
  }
}

/**
 * Getting follow story for story pages for akamai purposes
 */
function itg_story_load_follow_story() {
  global $user;
  //if ($user->uid > 0) {
    if (isset($_POST['id']) && !empty($_POST['id'])) {
      $nid = base64_decode($_POST['id']);
      if (isset($nid) && !empty($nid)) {
        $node = node_load($nid);
      }
      if ($node->type == 'story') {
        print theme('itg_story_load_follow_story', array('data' => array('node' => $node)));
        drupal_exit();
      }
    }
  //}
}

/**
 * Implement global_comment_last_record
 */
function itg_story_global_comment_last_record() {
  $query = db_select('itg_global_comment_config', 'ir')
      ->fields('ir', array('config_name', 'created'))
      ->orderBy('id', 'DESC')//ORDER BY created
      ->range(0, 1);
  $result = $query->execute()->fetchAll();
  return $result;
}
