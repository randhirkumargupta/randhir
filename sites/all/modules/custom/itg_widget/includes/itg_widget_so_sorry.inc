<?php

/**
 * function to sent block data for politoons for sosorry page.
 * @return array
 */
function itg_widget_so_sorry_politoons_ordering_data() {
  $block_data = array();

  $query = db_select('draggableviews_structure', 'dvs');
  $query->leftJoin('itg_category_manager', 'icm', 'icm.tid=dvs.entity_id');
  $query->addField('dvs', 'entity_id');
  $query->condition('dvs.view_name', 'so_sorry_politoons');
  $query->condition('dvs.view_display', 'so_sorry_politoons');
  $query->condition('icm.status', 1);
  $query->range(0, 6);
  $query->orderBy('dvs.weight');

  $result = $query->execute()->fetchAll();

  foreach ($result as $taxonomy) {
    $term_data = array();
    $term_data = taxonomy_term_load($taxonomy->entity_id);
    $block_data[] = array(
        'title' => $term_data->name,
        'uri' => $term_data->field_sponser_logo['und'][0]['uri'],
        'term_id' => $term_data->tid,
    );
  }
  return $block_data;
}

function save_so_sorry_widget_data($so_sorry_selected_content) {
  $selected_node = $so_sorry_selected_content['selection'];
  $already_nodes = db_select('itg_widget_order', 'iwo')
                  ->fields('iwo')
                  ->condition('widget', 'so_sorry_widget')
                  ->execute()->fetchAll(PDO::FETCH_ASSOC);
  $new_data_to_insert = array();
  // Check if there is any data in custom table
  if (count($already_nodes)) {

    foreach ($already_nodes as $table_nodes) {
      $new_data_to_insert[$table_nodes['nid']] = $table_nodes;
    }

    foreach ($selected_node as $new_selected_node) {
      $new_data_to_insert[$new_selected_node]['nid'] = $new_selected_node;
    }

    $num = db_delete('itg_widget_order')
            ->condition('widget', 'so_sorry_widget')
            ->execute();

    foreach ($new_data_to_insert as $key => $nodes) {

      $node_weight = $nodes['nid'];
      if ($nodes['weight'] == 0 && isset($nodes['weight'])) {
        $node_weight = 0;
      }
      else if (is_null($nodes['weight']) || $nodes['weight'] == "") {
        $node_weight = $nodes['nid'];
      }
      else {
        $node_weight = $nodes['weight'];
      }

      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nodes['nid'],
                  'widget' => 'so_sorry_widget',
                  'content_type' => " ",
                  'cat_id' => 0,
                  'weight' => $node_weight,
                  'extra' => ($nodes['extra']) ? $nodes['extra'] : "",
              ))->execute();
    }
  }
  else {
    foreach ($selected_node as $nodes) {
      $node_data = node_load($nodes);
      // watchdog('widget', $nodes);
      db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nodes,
                  'widget' => 'so_sorry_widget',
                  'content_type' => $node_data->type,
                  'cat_id' => 0,
                  'weight' => $node_data->nid,
                  'extra' => "",
              ))->execute();
    }
  }
}

?>
