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

/**
 * MegeReview associated to megaReview section
 */
function itg_mega_review_migration() {
  $arg = arg();
  $megareview_section_id = !empty($arg['2']) ? $arg['2'] : '';
  if($megareview_section_id) {
    $query = db_select('node', 'n')
      ->fields('n', array('nid'));
    $query->condition('type', 'mega_review_critic', '=');
    $result = $query->execute()->fetchAll();
    foreach ($result AS $row) {
      $nid = $row->nid;
      $node = node_load($nid);
      if(empty($node->field_story_category['und'][0]['tid'])) {
        $node->field_story_category['und'][0]['tid'] = $megareview_section_id;
        $newpath = itg_common_custompath_insert_load($node);
        $node->path['alias'] = $newpath;
        print "sucessfully associated all megereview node to megaReview section " . $nid . "<br>";
        node_save($node);
      }
    }
  }
}