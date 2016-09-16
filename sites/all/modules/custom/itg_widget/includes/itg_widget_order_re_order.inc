<?php

/**
 * @file
 * itg_widget_order_re_order.inc
 *
 * Provide functionality to order reorder page.
 *
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_page_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_we_may_suggest_widget_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_we_may_suggest";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_so_sorry_so_sorry_videos_widget_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_so_sorry";
}



/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_issue_base_magazin_widget_issue_magazin_widget_list_alter(&$form, &$form_state, $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_issue_magazin";
}
/**
 * Function to alter dont miss widget form.
 *
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_dont_miss_content_alter(&$form, &$form_state, $form_id) {
  $draggable_form = $form['draggableviews'];
  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
          "#type" => "textfield",
          "#size" => '',
          // get value which is saved into custom_table.
          '#default_value' => _get_custom_text_value_from_nid($default_value),
          '#attributes' => array("placeholder" => array(t("Please Enter A Label"))),
      );
    }
  }
  // Js added for alter colum name.
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-section-wise-content-ordering-list-dont-miss-content").find("th.tabledrag-hide").html("Label");
          });', array('type' => 'inline', 'scope' => 'footer', 'weight' => 5));

  drupal_add_css('#draggableviews-table-section-wise-content-ordering-list-dont-miss-content .tabledrag-hide {display:block !important;} .draggableviews-weight {display:none}', 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_dont_miss";
}

/**
 * Function for save new order in custom table itg_widget_order for dont miss widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_dont_miss($form, &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'dont_miss_content_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    $result = db_select('itg_widget_order')
                    ->fields('itg_widget_order', array('extra', 'nid', 'content_type'))
                    ->condition('widget', $widget)
                    ->execute()->fetchAll(PDO::FETCH_ASSOC);
    $extra_values = $result;
  }

  // Make draggable array with extra and content type , which is recived above.
  foreach ($extra_values as $key => $value) {
    foreach ($draggable_view_data as $draggable_node_key => $draggable_nodes) {
      if ($draggable_nodes['id'] == $value['nid']) {
        $draggable_view_data[$key]['extra'] = $value['custom_text'];
        $draggable_view_data[$key]['content_type'] = $value['content_type'];
      }
    }
  }

  // Delete all entry of widget dont_miss_content_widget as we have all the array of already inserted data.
  db_delete('itg_widget_order')
          ->condition('widget', 'dont_miss_content_widget')
          ->execute();

  // Now insert again with updated values.
  foreach ($draggable_view_data as $key => $node_data) {
    db_insert('itg_widget_order')
            ->fields(array(
                'nid' => $node_data['id'],
                'widget' => $widget,
                'content_type' => $node_data['content_type'],
                'cat_id' => '0',
                'weight' => $node_data['weight'],
                'extra' => $node_data['custom_text'],
            ))
            ->execute();
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may suggest widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_we_may_suggest($form, &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'we_may_suggest_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    $result = db_select('itg_widget_order')
                    ->fields('itg_widget_order', array('extra', 'nid', 'content_type'))
                    ->condition('widget', $widget)
                    ->execute()->fetchAll(PDO::FETCH_ASSOC);
    $extra_values = $result;
  }
  // Make draggable array with extra and content type , which is recived above.
  foreach ($extra_values as $key => $value) {
    foreach ($draggable_view_data as $draggable_node_key => $draggable_nodes) {
      if ($draggable_nodes['id'] == $value['nid']) {
        $draggable_view_data[$key]['content_type'] = ($value['content_type']) ? $value['content_type'] : "";
      }
    }
  }

  // Delete all entry of widget dont_miss_content_widget as we have all the array of already inserted data.
  db_delete('itg_widget_order')
          ->condition('widget', $widget)
          ->execute();

  // Now insert again with updated values.
  foreach ($draggable_view_data as $key => $node_data) {
    db_insert('itg_widget_order')
            ->fields(array(
                'nid' => $node_data['id'],
                'widget' => $widget,
                'content_type' => ($node_data['content_type']) ? $node_data['content_type'] : "",
                'cat_id' => '0',
                'weight' => $node_data['weight'],
            ))
            ->execute();
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may suggest widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_so_sorry($form, &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'so_sorry_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    $result = db_select('itg_widget_order')
                    ->fields('itg_widget_order', array('extra', 'nid', 'content_type'))
                    ->condition('widget', $widget)
                    ->execute()->fetchAll(PDO::FETCH_ASSOC);
    $extra_values = $result;
  }
  // Make draggable array with extra and content type , which is recived above.
  foreach ($extra_values as $key => $value) {
    foreach ($draggable_view_data as $draggable_node_key => $draggable_nodes) {
      if ($draggable_nodes['id'] == $value['nid']) {
        $draggable_view_data[$key]['content_type'] = ($value['content_type']) ? $value['content_type'] : "";
        $draggable_view_data[$key]['extra'] = ($value['extra']) ? $value['extra'] : "";
      }
    }
  }
  // Delete all entry of widget so_sorry_widget as we have all the array of already inserted data.
  db_delete('itg_widget_order')
          ->condition('widget', $widget)
          ->execute();

  // Now insert again with updated values.
  foreach ($draggable_view_data as $key => $node_data) {
    db_insert('itg_widget_order')
            ->fields(array(
                'nid' => $node_data['id'],
                'widget' => $widget,
                'content_type' => ($node_data['content_type']) ? $node_data['content_type'] : "",
                'cat_id' => '0',
                'weight' => $node_data['weight'],
                'extra' => $node_data['extra'],
            ))
            ->execute();
  }
}


/**
 * Function for save new order in custom table itg_widget_order for we may suggest widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_issue_magazin($form, &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'issue_magazin_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    db_update('itg_widget_order')
                ->fields(array('weight' => $value['weight']))
                 ->condition('widget', 'issue_magazin_widget')
            ->condition('nid', $value['id'])
                ->execute();
  }
 
}



/**
 * {@inheritdoc}
 */
function itg_widget_form_views_form_story_widget_photo_carousel_alter(&$form, &$form_state, $form_id) {
  // TODO: Implement this.
}

/**
 * Function for save new order in custom table itg_widget_order
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data($form, &$form_state) {
  // Current display for indentifing the view page (Widget name).
  $current_display = $form_state['build_info']['args'][0]->current_display;
  // Below view_name will use to get widget name.
  $view_name = $form['form_id']['#value'];
  $widget = _get_widget_name($view_name, $current_display);
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  // Content type from url.
  $content_type = $_GET['type'];
  // Category tid from url.
  $cat_id = $_GET['category_tid'];
  // If user dont make changes in draggable view then all the weights remain zero.
  // So check is required here. If al weight are 0 then do not execute query w.r.t. into itg_widget_order table.
  $weight_track_flag = FALSE;
  foreach ($draggable_view_data as $key => $node_data) {
    if ($node_data['weight'] > 0) {
      // Found changes in draggable view content
      $weight_track_flag = TRUE;
    }
  }
  // IF we got there is changes made in draggable view order.
  if ($weight_track_flag) {
    // watchdog("widget", "Change made in order");
    // First delete all the data from itg_widget_order table of combination
    foreach ($draggable_view_data as $key => $node_data) {
      //if (!empty($node_data['id']) && !empty($content_type) && !empty($widget) && !empty($cat_id)) {
      //$node_type = node_load($node_data['id']);  
      $num_deleted = db_delete('itg_widget_order')
              ->condition('nid', $node_data['id'])
              //->condition('content_type', $node_type->type)
              ->condition('widget', $widget)
              ->condition('cat_id', $cat_id)
              ->execute();
      if ($num_deleted) {
        // watchdog("widget", "Delete action has been performed");
      }
      //}
    }

    // Now insert new entry in itg_widget_order table of combination
    foreach ($draggable_view_data as $key => $node_data) {
      if (!empty($node_data['id']) && !empty($content_type) && !empty($widget) && !empty($cat_id)) {
        $is_inserted = db_insert('itg_widget_order')
                ->fields(array(
                    'nid' => $node_data['id'],
                    'widget' => $widget,
                    'content_type' => $content_type,
                    'cat_id' => $cat_id,
                    'weight' => $node_data['weight'],
                ))
                ->execute();
        if ($is_inserted) {
          // watchdog("widget", "Insert action has been performed");
          drupal_set_message(t("Ordering has been saved."));
        }
      }
    }
  }
  // If there is not chnages found in draggable view order then simply give an message.
  else {
    drupal_set_message(t("This ordering is already saved."));
  }
}

/**
 * Funtion to get extra value if already saved used for dont miss widget.
 *
 * @param int $nid
 * @return array
 */
function _get_custom_text_value_from_nid($nid) {
  $result = db_select('itg_widget_order', 'iwo')
                  ->fields('iwo', array('extra'))
                  ->condition('iwo.nid', $nid)
                  ->condition('iwo.widget', 'dont_miss_content_widget')
                  ->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['extra'];
}
