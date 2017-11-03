<?php

/*
 * Implements itg_mega_review_filter_callback().
 * @param string $title
 */
function itg_mega_review_filter_callback($title) {
  
  if (strlen(trim($title)) > 0) {
    $content_type = arg(1);
    $state = trim(arg(2));
    $draft_array = array('movie-review-draft-list');
    if(in_array($state, $draft_array)) {
      $status = 0;
    } else {
      $status = 1;
    }
    
    $options = '';
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->fields('n', array('title'));
    $query->condition('title', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', $content_type, '=');
    $query->condition('n.status', $status);
    $query->range(0, 20);
    $result = $query->execute();
    while ($record = $result->fetchAssoc()) {
      $options[$record['title']] = $record['title'];
    }
    drupal_json_output($options);
  }
}