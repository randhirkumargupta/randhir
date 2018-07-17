<?php

/**
 * Function used to remove nodeid from widget.
 * @param string $widget
 * @param int $nid
 */
function remove_from_custom_widget($widget , $nid) {
  try {
    db_delete('itg_custom_widgets_data')
        ->condition('nid' , $nid)
        ->condition('widget' , $widget)
        ->execute();
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Function gives widget title json.
 * @param string $widget_title
 */
function itg_custom_widget_name_list($widget_title) {

  $query = db_select('itg_custom_widgets_data' , 'n');
  $query->condition('widget' , $widget_title);
  $query->fields('n' , array('widget'));
  $query->distinct();
  $result = $query->execute();

  while ($record = $result->fetchAssoc()) {
    $options[] = $record['widget'];
  }

  drupal_json_output($options);
}

