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

?>
