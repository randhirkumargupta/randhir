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
  if ($megareview_section_id) {
    $query = db_select('node', 'n')
        ->fields('n', array('nid'));
    $query->condition('type', 'mega_review_critic', '=');
    $result = $query->execute()->fetchAll();
    foreach ($result AS $row) {
      $nid = $row->nid;
      $node = node_load($nid);
      if (empty($node->field_story_category['und'])) {
        $node->field_story_category['und'][0]['tid'] = $megareview_section_id;
        $newpath = itg_common_custompath_insert_load($node);
        $node->path['alias'] = $newpath;
        print "sucessfully associated all megereview node to megaReview section " . $nid . "<br>";
        node_save($node);
        itg_mega_review_ordering_set_of_content($node, $megareview_section_id);
      }
    }
  }
}

/**
 * 
 * @param type $node
 * @param type $megareview_section_id
 */
function itg_mega_review_ordering_set_of_content($node, $megareview_section_id) {
  $nid = $node->nid;
  if (function_exists('__itg_widget_helper_data_insert')) {
    __itg_widget_helper_data_insert($node->nid);
  }
  $single_max_result = get_max_weight_for_node_insert($megareview_section_id, $node->type);
  $max_result = $single_max_result['content_type'];
  $max_result_all = $single_max_result['All'];

  if (isset($megareview_section_id)) {
    $widget_nid = itg_mega_review_check_nid($nid, $megareview_section_id, $node->type);
    if (empty($widget_nid)) {
      $query = db_insert('itg_widget_order_section')
          ->fields(array(
            'nid' => $nid,
            'widget' => 'section_wise_widget',
            'content_type' => $node->type,
            'cat_id' => $megareview_section_id,
            'weight' => ++$max_result,
            'extra' => "",
          ))
          ->execute();
      _delete_old_data_from_section_widget('itg_widget_order_section', $megareview_section_id, $node->type);

      $query = db_insert('itg_widget_order')
          ->fields(array(
            'nid' => $nid,
            'widget' => 'section_wise_widget',
            'content_type' => 'All',
            'cat_id' => $megareview_section_id,
            'weight' => ++$max_result_all,
            'extra' => '',
          ))
          ->execute();
      _delete_old_data_from_section_widget('itg_widget_order', $megareview_section_id, "all");
    }
  }
}

/**
 * function for itg_mega_review_check_nid().
 * @param type $nid
 * @param type $tid
 * @param type $type
 * @return type
 */
function itg_mega_review_check_nid($nid, $tid, $type) {
  $table = 'itg_widget_order_section';
  if (strtolower($type) == 'all') {
    $table = 'itg_widget_order';
  }
  $query = db_select($table, 'iwo')
      ->fields('iwo', array('nid'))
      ->condition('iwo.nid', $nid)
      ->condition('iwo.cat_id', $tid)
      ->condition('iwo.content_type', $type);
   return $query->execute()->fetchField();
}
