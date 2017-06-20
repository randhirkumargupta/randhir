<?php

/**
 * Function to display form with dragaable view
 * @return html
 */
function itg_event_render_form_block() {
  drupal_add_js(drupal_get_path('module', 'itg_event_registration') . '/js/itg-event-speaker-order.js', array('type' => 'file', 'scope' => 'footer'));
  $table = '<table class="views-table">';
  $table .= '<tr>
    <th>Past Speakers List</th>
    <th>Speakers Order</th> 
  </tr>';
  $table .= '<tr>';
  $table .= '<td>';
  $table .= drupal_render(drupal_get_form('itg_event_past_speakers'));
  $table .= '</td>';
  $table .= '<td>';
  $table .= views_embed_view('past_speaker_event', 'order_reorder_widget', $_GET['current_event']);
  $table .= '</td>';
  $table .= '</tr>';
  $table .= '</table>';
  return $table;
}

/**
 *  {@inheritdocs}
 */
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
      '#tree' => TRUE,
      '#prefix' => '<div class="wrapper-widget">',
      '#suffix' => '</div>'
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
      '#value' => 'Add To Widget',
    );
  }
  return $form;
}

/**
 * {@inhertidocs}
 */
function itg_event_past_speakers_submit($form, &$form_state) {
  $widget_data = $form_state['input']['widget_data'];
  $event_id = $form_state['input']['event_id'];
  $widget_name = 'itg_event_speaker_order_widget';
  // Now insert new entry in itg_widget_order table of combination
  drupal_set_message("Anchors Has Been Added To Widget");
  foreach ($widget_data as $widget) {
    $target_id = array_values($widget['speaker_id']);
    // Logic to skip current speaker if already added.
    $row_count = __skip_already_added_speaker($target_id[0], $event_id);
    if ($row_count) {
      continue;
    }

    $max_weight = __max_weight_for_speker($event_id);
    if ($target_id[0] != 0) {
      try {
        db_merge('itg_widget_order')
            ->key(array(
              'nid' => $target_id[0],
              'widget' => $widget_name,
              'cat_id' => $event_id,
              'content_type' => "All",
            ))
            ->fields(array(
              'weight' => --$max_weight,
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
  // Start code for sending purge request of event home page for Akamai
  if (isset($_GET['current_event']) && !empty($_GET['current_event'])) {
    $url = drupal_get_path_alias('node/' . $_GET['current_event']);
    if (function_exists('itg_akamai_clear_url')) {
      itg_akamai_clear_url($url, array());
    }
  }
  // End code for sending purge request of event home page for Akamai
}

/**
 * function to get max value of event weight.
 */
function __max_weight_for_speker($event_id) {
  $max_query_all = db_select('itg_widget_order');
  $max_query_all->addExpression('MIN(weight)', 'weight');
  $max_query_all->condition('cat_id', $event_id);
  $max_query_all->condition('widget', 'itg_event_speaker_order_widget');
  $max_result = $max_query_all->execute()->fetchField();
  if ($max_result == null || empty($max_result)) {
    return 0;
  }
  else {
    return $max_result;
  }
}

/**
 * Function which gives count for event + speaker combination.
 * 
 * @param int $speaker_id
 * @param int $event_id
 * @return int
 */
function __skip_already_added_speaker($speaker_id, $event_id) {
  $count_query = db_select('itg_widget_order', 'iwo');
  $count_query->fields('iwo', array("nid"));
  $count_query->condition('iwo.cat_id', $event_id);
  $count_query->condition('iwo.nid', $speaker_id);
  $count_query->condition('iwo.widget', 'itg_event_speaker_order_widget');
  return $count_query->execute()->rowCount();
}

/**
 * Function gives speaker data.
 * 
 * @param int $id
 * @return string
 */
function __get_speaker_data($id) {
  $query = db_select('node', 'n');
  $query->fields("n", array("title"));
  $query->condition('n.nid', $id);
  return $query->execute()->fetchField();
}

/**
 * Implement Hook_FORM_FORM_ID_ALTER.
 */
function itg_event_registration_form_views_form_past_speaker_event_order_reorder_widget_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#submit'][] = "past_speaker_event_order_reorder_submit";
}

/**
 * Custom submit handler function.
 */
function past_speaker_event_order_reorder_submit($form, &$form_state) {
  $draggable_view_data = $form_state['input']['draggableviews'];
  $added_weight = 0;
  foreach ($draggable_view_data as $key => $value) {
    $added_weight += $value['weight'];
  }
  
  if ($added_weight) {
    foreach ($draggable_view_data as $key => $value) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'],))
          ->condition('widget', 'itg_event_speaker_order_widget')
          ->condition('nid', $value['id'])
          ->condition('cat_id', $_GET['current_event'])
          ->execute();
    }
  }

  // Start code for sending purge request of event home page for Akamai
  if (isset($_GET['current_event']) && !empty($_GET['current_event'])) {
    $url = drupal_get_path_alias('node/' . $_GET['current_event']);
    if (function_exists('itg_akamai_clear_url')) {
      itg_akamai_clear_url($url, array());
    }
  }
  // End code for sending purge request of event home page for Akamai
}
