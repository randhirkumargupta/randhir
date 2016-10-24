<?php

/*
 * Inc file contains the helper functions
 */

/**
 * Helper function to populate the second dropdown.
 * @param string $id
 * @return array $data
 */
function itg_common_tv_time($id = '') {

  $final_id = date('Y/m/d', strtotime($id));
  if (function_exists('mongodb')) {
    $db = mongodb();
    $people = $db->tv_schedule;
    $date = $final_id;
    $cond = array('program date' => $date);
    $cursor = $people->find($cond);
    // Fetch query for supplements
    $select = t('- None -');
    $data = array('_none' => $select);
    foreach ($cursor as $document) {
      $data[$document['time']] = $document['time'];
    }
    return $data;
  }
}

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
 * @param string $story_node
 */
function itg_story_create_breaking_news($story_node) {
  global $user;

  $node = new stdClass();
  $node->title = $story_node->title;
  $node->type = "breaking_news";

  node_object_prepare($node); //Invokes hook_prepare() and hook_node_prepare().

  $node->language = LANGUAGE_NONE;
  $node->field_content_type[LANGUAGE_NONE][0]['value'] = 'Story';
  $node->field_type[LANGUAGE_NONE][0]['value'] = 'Breaking News';
  $node->field_source[LANGUAGE_NONE][0]['value'] = $story_node->nid;
  $node->field_stroy_city[LANGUAGE_NONE][0]['tid'] = $story_node->field_stroy_city[LANGUAGE_NONE][0]['tid'];
  $node->field_display_on[LANGUAGE_NONE][0]['value'] = 'Section';

  // get selected taxonomy of node
  $story_taxonomy = $story_node->field_story_category[LANGUAGE_NONE];

  foreach ($story_taxonomy as $value1) {
    $story_array[] = $value1['tid'];
  }

  //get all parent category
  $taxonomy_parent = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  foreach ($taxonomy_parent as $key => $value) {
    $taxonomy_parent_array[] = $value->tid;
  }

  // after intersect
  $taxonomy_result = array_intersect($taxonomy_parent_array, $story_array);

  foreach ($taxonomy_result as $key1 => $tax_id) {
    $node->field_section[LANGUAGE_NONE][]['tid'] = $tax_id;
  }

  $node->uid = $user->uid;
  $node->status = 1; //(1 or 0): Published or not
  $node->promote = 0; //(1 or 0): Promoted to front page
  $node->comment = 0; // 0 = Comments disabled, 1 = read only, 2 = read/write

  node_save($node);

}