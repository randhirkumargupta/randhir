<?php

/**
 * Function to return custom content widget array.
 * 
 * @param string $title
 * @return array
 */
function itg_custom_widget_ordering_data_from_title($title) {
  if ( !empty($title) ) {

    $query = db_select('itg_custom_widgets_data' , 'icw');
    $query->leftJoin('node' , 'n' , 'n.nid=icw.nid');
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image' , 'eli' , 'eli.entity_id=n.nid');
    $query->leftJoin('file_managed' , 'eli_file' , 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('field_data_field_story_kicker_text' , 'kt' , 'kt.entity_id=n.nid');
    $query->fields('eli_file' , array('uri'));
    $query->fields('kt' , array('field_story_kicker_text_value'));
    $query->fields('n' , array('nid' , 'title' , 'created' , 'type' , 'uid'));
    //end
    $query->fields('icw' , array('nid' , 'weight'))
        ->condition('icw.widget' , $title)
        ->condition('n.status' , '1')
        ->orderBy('icw.weight' , 'ASC')
        ->orderBy('n.nid' , 'DESC')
        ->groupBy('icw.nid')
        ->range(0 , 3);
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $entity_data = array();
    foreach ($result as $entity_data_node) {
      $entity_data[] = $entity_data_node;
    }

    return theme("itg_custom_widget_ordering_data" , array("data" => $entity_data));
  }
  return array();
}

/**
 * Function used to return widget specific minimum weight
 * @param string $custom_widget_name
 * @return int
 */
function itg_custom_widget_get_min_weight($custom_widget_name) {
  $min_query = db_select('itg_custom_widgets_data');
  $min_query->addExpression('MIN(weight)');
  $min_query->condition('widget' , $custom_widget_name);
  $min_query = $min_query->execute()->fetchField();
  return isset($min_query) ? $min_query : 1;
}

/**
 * {@inheritdoc}
 */
function itg_custom_widget_update_order_reorder_data($form , &$form_state) {
  $arg = arg();
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];

  // Now insert new entry in itg_widget_order table of combination
  foreach ($draggable_view_data as $key => $node_data) {
    try {
      db_merge('itg_custom_widgets_data')
          ->key(array(
            'nid' => $node_data['id'] ,
            'widget' => $arg[1] ,
          ))
          ->fields(array(
            'weight' => $node_data['weight'] ,
            'nid' => $node_data['id'] ,
            'widget' => $arg[1] ,
          ))
          ->execute();
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage());
    }
  }
}


