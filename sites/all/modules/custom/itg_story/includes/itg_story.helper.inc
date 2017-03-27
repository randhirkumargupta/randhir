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
 * Breaking news create after story create.
 */
function itg_story_create_breaking_news() {
  global $user;
  $title = $_POST['title'];
  $node = new stdClass();
  $node->title = $title;
  $node->type = "breaking_news";

  node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().

  $node->language = LANGUAGE_NONE;
  $node->field_content_type[LANGUAGE_NONE][0]['value'] = 'Story';
  $node->field_type[LANGUAGE_NONE][0]['value'] = 'Breaking News';
  $node->uid = $user->uid;
  $node->status = 1; //(1 or 0): Published or not
  $node->promote = 0; //(1 or 0): Promoted to front page
  $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write
  $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_breaking_content_details'));
  $field_collection_item->setHostEntity('node', $node);
  $field_collection_item->field_breaking_tile[LANGUAGE_NONE][0]['value'] = $title;
  $field_collection_item->field_mark_as_breaking_band[LANGUAGE_NONE][0]['value'] = '1';
  $field_collection_item->save();
  node_save($node);

  $response = array('story_nid' => $node->nid);
  print json_encode($response);
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
