<?php

function itg_event_render_form_block() {
  $table = '<table class="views-table">';
  $table .= '<tr>
    <th>Speakers</th>
    <th>Speakers Order</th> 
  </tr>';
  $table .= '<tr>';
  $table .= '<td>';
  $table .= drupal_render(drupal_get_form('itg_event_past_speakers'));
  $table .= '</td>';
  $table .= '<td>';
  $table .= views_embed_view('past_speaker_event','order_reorder_widget', $_GET['current_event']);
  $table .= '</td>';
  $table .= '</tr>';
  $table .= '</table>';
  return $table;
}

function itg_event_past_speakers($form, &$form_state) {
  $speakers = array();
  $past_spkr_event_ids = itg_event_backend_event_type_get_event_ids_for_speakers();
  $nodes = explode(",", $past_spkr_event_ids);
  foreach ($nodes as $node_data) {
    if ($node_data) {
      $node_load = node_load($node_data);
      foreach ($node_load->field_program_schedule[LANGUAGE_NONE] as $field_collection) {
        $entity = entity_load('field_collection_item', array($field_collection['value']));
        if (!empty($entity[$field_collection['value']]->field_select_speaker[LANGUAGE_NONE][0]['target_id'])) {
          $speakers[] = $entity[$field_collection['value']]->field_select_speaker[LANGUAGE_NONE][0]['target_id'];
        }
      }
    }
  }
  if (count($speakers)) {

    $form['widget_data'] = array(
      '#tree' => TRUE
    );

    $speakers = array_unique($speakers);

    foreach ($speakers as $key => $value) {
      $form['widget_data'][$key]['speaker_id'] = array(
        '#type' => 'checkboxes',
        '#options' => array($value => ""),
        '#title' => __get_speaker_data($value),
      );
    }

    $form['event_id'] = array(
      '#type' => 'hidden',
      '#value' => $_GET['current_event'],
      '#default_value' => $_GET['current_event'],
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'save',
    );
  }
  return $form;
}

function itg_event_past_speakers_submit($form, &$form_state) {
  $widget_data = $form_state['input']['widget_data'];
  $event_id = $form_state['input']['event_id'];
  $widget_name = 'itg_event_speaker_order_widget';
  // Now insert new entry in itg_widget_order table of combination
  drupal_set_message("Anchors Has Been Added To Widget");
  foreach ($widget_data as $widget) {
    $target_id = array_values($widget['speaker_id']);
    if ($target_id[0] != 0) {
      try {
        watchdog("speaker_widget", $target_id  . $widget_name . $event_id);
        db_merge('itg_widget_order')
            ->key(array(
              'nid' => $target_id[0],
              'widget' => $widget_name,
              'cat_id' => $event_id,
              'content_type' => "All",
            ))
            ->fields(array(
              'weight' => $target_id[0],
              'nid' => $target_id,
              'widget' => $widget_name,
              'cat_id' => $event_id,
              'content_type' => "All",
            ))
            ->execute();
      }
      catch (Exception $ex) {
        echo $ex->getMessage();
      }
    }
  }
}

function __get_speaker_data($id) {
  $query = db_select('node', 'n');
  $query->fields("n", array("title"));
  $query->condition('n.nid', $id);
  return $query->execute()->fetchField();
}
