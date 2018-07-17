<?php

set_time_limit(0);
//ini_set('memory_limit', '-1');
$args = drush_get_arguments(); // Get the arguments.

ordering_update_story_custom();

/**
 * story content ordering
 */
function ordering_update_story_custom() {
  $path = 'sites/default/files/migrate/xml_file/ordering/story_ordering.xml';
  $xml = simplexml_load_file($path, 'SimpleXMLElement');
  foreach ($xml->content_ordering as $xml_data) {
    $nid = '';
    $ordering = '';
    $source_id = '';
    $source_id = (int) $xml_data->content_id;
    $ordering = (int) $xml_data->ordering;
    $nid = get_itg_destination_id('migrate_map_itgstorylist', $source_id);
    custom_ordering_set_of_content($nid, $ordering);
    echo $source_id.'-'.$nid.', ';
  }
}

/**
 * story content ordering
 */
function ordering_update_video_custom() {
  $path = 'sites/default/files/migrate/xml_file/ordering/story_ordering.xml';
  $xml = simplexml_load_file($path, 'SimpleXMLElement');
  foreach ($xml->content_ordering as $xml_data) {
    $nid = '';
    $ordering = '';
    $source_id = '';
    $source_id = (int) $xml_data->content_id;
    $ordering = (int) $xml_data->ordering;
    $nid = get_itg_destination_id('migrate_map_itgstorylist', $source_id);
    custom_ordering_set_of_content($nid, $ordering);
    echo $source_id.'-'.$nid.', ';
  }
}


/**
 * Order set of content
 * @param array $node
 * @return
 */
function custom_ordering_set_of_content($nid, $count) {
  old_section_widget_delete($nid);
  $node = node_load($nid);
  if (isset($node->field_story_category['und'])) {
    $cat_id = $node->field_story_category['und'];
      foreach ($cat_id as $category) {
         $query = db_insert('itg_widget_order_section')
        ->fields(array(
          'nid' => $nid,
          'widget' => 'section_wise_widget',
          'content_type' => $node->type,
          'cat_id' => $category['tid'],
          'weight' => $count,
          'extra' => "",
        ))
        ->execute();
         _delete_old_data_from_section_widget('itg_widget_order_section', $category['tid'], $node->type);
       
       $query = db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $nid,
            'widget' => 'section_wise_widget',
            'content_type' => 'All',
            'cat_id' => $category['tid'],
            'weight' => $count,
            'extra' => '',
        ))
        ->execute();  
       _delete_old_data_from_section_widget('itg_widget_order', $category['tid'], "all");
      }
    }   
} 


function old_section_widget_delete($nid) {
    db_delete('itg_widget_order')
                    ->condition('widget', 'section_wise_widget')
                    ->condition('content_type', 'All')
                    ->condition('nid', $nid)->execute();

    db_delete('itg_widget_order_section')
            ->condition('content_type', $node->type)
            ->condition('widget', 'section_wise_widget')
            ->condition('nid', $nid)->execute();
}
?>
