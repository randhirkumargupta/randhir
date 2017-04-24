<?php

/**
 * @file
 * Provide functionality to order reorder page.
 *
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_key_candidate_special_key_candidate_widget_list_alter(&$form , &$form_state , $form_id) {
  // Js added for alter colum name.
  $draggable_form = $form['draggableviews'];
  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
        "#type" => "textfield" ,
        "#size" => '' ,
        // get value which is saved into custom_table.
        '#default_value' => _get_constituency_value_from_nid($default_value , 'key_candidate') ,
        '#attributes' => array("placeholder" => array(t("Please Enter Constituency"))) ,
      );
    }
  }
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-key-candidate-special-key-candidate-widget-list").find("th.tabledrag-hide").html("Constituency");
          });' , array('type' => 'inline' , 'scope' => 'footer' , 'weight' => 5));

  drupal_add_css('#draggableviews-table-key-candidate-special-key-candidate-widget-list .tabledrag-hide {display:table-cell !important;} .draggableviews-weight {display:none}' , 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_key_candidate";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_so_sorry_so_sorry_videos_widget_alter(&$form , &$form_state , $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_so_sorry";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_special_auto_review_widget_special_auto_review_widget_list_alter(&$form , &$form_state , $form_id) {

  $draggable_form = $form['draggableviews'];
  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
        "#type" => "textfield" ,
        "#size" => '' ,
        // get value which is saved into custom_table.
        '#default_value' => _get_custom_text_value_from_nid($default_value , 'special_auto_review_content') ,
        '#attributes' => array("placeholder" => array(t("Please Enter A Label"))) ,
      );
    }
  }
  // Js added for alter colum name.
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-special-auto-review-widget-special-auto-review-widget-list").find("th.tabledrag-hide").html("Label");
          });' , array('type' => 'inline' , 'scope' => 'footer' , 'weight' => 5));

  drupal_add_css('#draggableviews-table-special-auto-review-widget-special-auto-review-widget-list .tabledrag-hide {display:table-cell !important;} .draggableviews-weight {display:none}' , 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_special_auto_review";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_special_how_i_made_it_special_how_made_widget_list_alter(&$form , &$form_state , $form_id) {

  $draggable_form = $form['draggableviews'];
  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
        "#type" => "textfield" ,
        "#size" => '' ,
        // get value which is saved into custom_table.
        '#default_value' => _get_custom_text_value_from_nid($default_value , 'special_how_made_it_content') ,
        '#attributes' => array("placeholder" => array(t("Please Enter A Label"))) ,
      );
    }
  }
  // Js added for alter colum name.
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-special-how-i-made-it-special-how-made-widget-list").find("th.tabledrag-hide").html("Label");
          });' , array('type' => 'inline' , 'scope' => 'footer' , 'weight' => 5));

  drupal_add_css('#draggableviews-table-special-how-i-made-it-special-how-made-widget-list .tabledrag-hide {display:table-cell !important;} .draggableviews-weight {display:none}' , 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_special_how_i_made_it_review";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_most_read_widget_most_read_widget_list_alter(&$form , &$form_state , $form_id) {

  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_most_read";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_feature_content_by_section_widget_feature_content_section_widget_list_alter(&$form , &$form_state , $form_id) {

  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_feature_content_by_section";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_yearender_top_news_and_top_videos_yearend_left_widget_list_alter(&$form , &$form_state , $form_id) {
  $draggable_form = $form['draggableviews'];

  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
        "#type" => "textfield" ,
        "#size" => '' ,
        // get value which is saved into custom_table.
        '#default_value' => _get_custom_text_value_from_nid($default_value , 'yearender_left_news_video') ,
        '#attributes' => array("placeholder" => array(t("Please Enter A Label"))) ,
      );
    }
  }
  // Js added for alter colum name.
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-yearender-top-news-and-top-videos-yearend-left-widget-list").find("th.tabledrag-hide").html("Label");
          });' , array('type' => 'inline' , 'scope' => 'footer' , 'weight' => 5));

  drupal_add_css('#draggableviews-table-yearender-top-news-and-top-videos-yearend-left-widget-list .tabledrag-hide {display:table-cell !important;} .draggableviews-weight {display:none}' , 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_yearend_left";
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_issue_base_magazin_widget_issue_magazin_widget_list_alter(&$form , &$form_state , $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_issue_magazin";
}

/**
 * Function to alter dont miss widget form.
 *
 * Implements hook_form_FORM_ID_alter().
 *
 * {@inheritdoc}
 */
function itg_widget_form_views_form_section_wise_content_ordering_list_dont_miss_content_alter(&$form , &$form_state , $form_id) {
  $draggable_form = $form['draggableviews'];
  foreach ($draggable_form as $form_key => $from_node) {
    // Escape #tree as draggable view proview 1st option tree
    if (is_integer($form_key)) {
      $default_value = isset($form['draggableviews'][$form_key]['id']['#value']) ? $form['draggableviews'][$form_key]['id']['#value'] : "";
      $form['draggableviews'][$form_key]['custom_text'] = array(
        "#type" => "textfield" ,
        "#size" => '' ,
        // get value which is saved into custom_table.
        '#default_value' => _get_custom_text_value_from_nid($default_value) ,
        '#attributes' => array("placeholder" => array(t("Please Enter A Label"))) ,
      );
    }
  }
  // Js added for alter colum name.
  drupal_add_js('jQuery(document).ready(function() {                  
                 jQuery("#draggableviews-table-section-wise-content-ordering-list-dont-miss-content").find("th.tabledrag-hide").html("Label");
          });' , array('type' => 'inline' , 'scope' => 'footer' , 'weight' => 5));

  drupal_add_css('#draggableviews-table-section-wise-content-ordering-list-dont-miss-content .tabledrag-hide {display:table-cell !important;} .draggableviews-weight {display:none}' , 'inline');
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_dont_miss";
}

/**
 * Function for save new order in custom table itg_widget_order for dont miss widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_dont_miss($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $total_changed_weight = 0;

  foreach ($draggable_view_data as $weight_cal_key => $weight) {
    $total_changed_weight = $weight['weight'] + $total_changed_weight;
  }

  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $value['custom_text'] , ))
          ->condition('widget' , 'dont_miss_content_widget')
          ->condition('nid' , $value['id'])
          ->execute();
    }
    else {
      db_update('itg_widget_order')
          ->fields(array('extra' => $value['custom_text'] , ))
          ->condition('widget' , 'dont_miss_content_widget')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may suggest widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_we_may_suggest($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'we_may_suggest_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    $result = db_select('itg_widget_order')
            ->fields('itg_widget_order' , array('extra' , 'nid' , 'content_type'))
            ->condition('widget' , $widget)
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
      ->condition('widget' , $widget)
      ->execute();

  // Now insert again with updated values.
  foreach ($draggable_view_data as $key => $node_data) {
    db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $node_data['id'] ,
          'widget' => $widget ,
          'content_type' => ($node_data['content_type']) ? $node_data['content_type'] : "" ,
          'cat_id' => '0' ,
          'weight' => $node_data['weight'] ,
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
function update_itg_widget_order_table_data_for_so_sorry($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'so_sorry_widget';
  $extra_values = array();
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    $result = db_select('itg_widget_order')
            ->fields('itg_widget_order' , array('extra' , 'nid' , 'content_type'))
            ->condition('widget' , $widget)
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
      ->condition('widget' , $widget)
      ->execute();

  // Now insert again with updated values.
  foreach ($draggable_view_data as $key => $node_data) {
    db_insert('itg_widget_order')
        ->fields(array(
          'nid' => $node_data['id'] ,
          'widget' => $widget ,
          'content_type' => ($node_data['content_type']) ? $node_data['content_type'] : "" ,
          'cat_id' => '0' ,
          'weight' => $node_data['weight'] ,
          'extra' => $node_data['extra'] ,
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
function update_itg_widget_order_table_data_for_issue_magazin($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'issue_magazin_widget';
  $extra_values = array();
  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight']))
          ->condition('widget' , 'issue_magazin_widget')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may suggest widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_key_candidate($form , &$form_state) {
  // Take draggable view input value after submit the form.

  $draggable_view_data = $form_state['input']['draggableviews'];

  $extra_values = array();
  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }

  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {

    if ($weightcount > 0) {

      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'constituency' => $value['custom_text']))
          ->condition('widget' , 'key_candidate')
          ->condition('id' , $value['id'])
          ->execute();
    }
    else {
      db_update('itg_widget_order')
          ->fields(array('constituency' => $value['custom_text'] , ))
          ->condition('widget' , 'key_candidate')
          ->condition('id' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may special auto review widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_special_auto_review($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $extra_values = array();
  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $value['custom_text'] , ))
          ->condition('widget' , 'special_auto_review_content')
          ->condition('nid' , $value['id'])
          ->execute();
    }
    else {
      db_update('itg_widget_order')
          ->fields(array('extra' => $value['custom_text'] , ))
          ->condition('widget' , 'special_auto_review_content')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may special auto review widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_special_how_i_made_it_review($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $extra_values = array();

  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $value['custom_text'] , ))
          ->condition('widget' , 'special_how_made_it_content')
          ->condition('nid' , $value['id'])
          ->execute();
    }
    else {
      db_update('itg_widget_order')
          ->fields(array('extra' => $value['custom_text'] , ))
          ->condition('widget' , 'special_how_made_it_content')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for Most Read.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_most_read($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $extra_values = array();

  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , ))
          ->condition('widget' , 'most_read_content')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * Function for save new order in custom table itg_widget_order for Most Read.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_feature_content_by_section($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $extra_values = array();

  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    db_update('itg_widget_order')
        ->fields(array('weight' => $value['weight'] , ))
        ->condition('widget' , 'feature_content_by_section')
        ->condition('nid' , $value['id'])
        ->execute();
  }
}

/**
 * Function for save new order in custom table itg_widget_order for we may special auto review widget.
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data_for_yearend_left($form , &$form_state) {
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'yearender_left_news_video';
  $extra_values = array();
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $datacount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $value['custom_text'] , ))
          ->condition('widget' , 'yearender_left_news_video')
          ->condition('nid' , $value['id'])
          ->execute();
    }
    else {
      db_update('itg_widget_order')
          ->fields(array('extra' => $value['custom_text'] , ))
          ->condition('widget' , 'yearender_left_news_video')
          ->condition('nid' , $value['id'])
          ->execute();
    }
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_form_views_form_story_widget_photo_carousel_alter(&$form , &$form_state , $form_id) {
  // TODO: Implement this.
}

/**
 * Function for save new order in custom table itg_widget_order
 *
 * @param array $form
 * @param array $form_state
 */
function update_itg_widget_order_table_data($form , &$form_state) {

  // Current display for indentifing the view page (Widget name).
  $current_display = $form_state['build_info']['args'][0]->current_display;
  // Below view_name will use to get widget name.
  $view_name = $form['form_id']['#value'];
  $widget = _get_widget_name($view_name , $current_display);
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  // Category tid from url.
  $cat_id = $_GET['category_tid'];
  $type_in_url = $_GET['type'];
  $actual_weight_type = 'All';
  $types = array("story" , "videogallery" , "photogallery");
  if (in_array($type_in_url , $types)) {
    $actual_weight_type = $type_in_url;
  }

  // Now insert new entry in itg_widget_order table of combination
  foreach ($draggable_view_data as $key => $node_data) {
    try {
      db_merge('itg_widget_order')
          ->key(array(
            'nid' => $node_data['id'] ,
            'widget' => $widget ,
            'cat_id' => $cat_id ,
            'content_type' => $actual_weight_type ,
          ))
          ->fields(array(
            'weight' => (int) $node_data['weight'] ,
            'nid' => $node_data['id'] ,
            'widget' => $widget ,
            'cat_id' => $cat_id ,
            'content_type' => $actual_weight_type ,
          ))
          ->execute();
    }
    catch (Exception $ex) {
      drupal_set_message($ex->getMessage());
    }
  }
}

/**
 * Funtion to get extra value if already saved used for dont miss widget.
 *
 * @param int $nid
 * @return array
 */
function _get_custom_text_value_from_nid($nid , $widget = 'dont_miss_content_widget') {
  $result = db_select('itg_widget_order' , 'iwo')
          ->fields('iwo' , array('extra'))
          ->condition('iwo.nid' , $nid)
          ->condition('iwo.widget' , $widget)
          ->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['extra'];
}

/**
 * Funtion to get extra value if already saved used for dont miss widget.
 *
 * @param int $nid
 * @return array
 */
function _get_constituency_value_from_nid($nid , $widget = 'key_candidate') {
  $result = db_select('itg_widget_order' , 'iwo')
          ->fields('iwo' , array('constituency'))
          ->condition('iwo.id' , $nid)
          ->condition('iwo.widget' , $widget)
          ->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result[0]['constituency'];
}

function itg_widget_form_views_form_category_of_stroy_base_magazin_widget_issue_magazin_widget_list_alter(&$form , &$form_state , $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_issue_magazin_primary_cat";
}

function itg_widget_form_views_form_supplement_base_magazin_widget_supplement_base_magazin_widget_list_alter(&$form , &$form_state , $form_id) {
  $form['actions']['submit']['#submit'][] = "update_itg_widget_order_table_data_for_issue_magazin_supplement";
}

function update_itg_widget_order_table_data_for_issue_magazin_primary_cat(&$form , &$form_state , $form_id) {
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'issue_primary_category_magazin_widget';
  $extra_values = array();
  $issue_date = $_GET['field_story_issue_date_value']['value']['date'];
  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $weightcount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      $primary_cat = itg_widget_get_primary_cat($value['id']);
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $issue_date , ))
          ->condition('widget' , 'issue_primary_category_magazin_widget')
          ->condition('nid' , $value['id'])
          ->condition('extra' , $issue_date)
          ->condition('cat_id' , $primary_cat)
          ->execute();
    }
  }
}

function update_itg_widget_order_table_data_for_issue_magazin_supplement(&$form , &$form_state , $form_id) {
  $draggable_view_data = $form_state['input']['draggableviews'];
  $widget = 'issue_supplement_magazin_widget';
  $extra_values = array();
  $issue_date = $_GET['field_story_issue_date_value']['value']['date'];
  $weightcount = 0;
  foreach ($draggable_view_data as $key => $value) {
    $weightcount = $weightcount + $value['weight'];
  }
  // Get extra , nid , content type from custom_table because it will further use to insert again.
  foreach ($draggable_view_data as $key => $value) {
    if ($weightcount > 0) {
      $primary_cat = itg_widget_get_primary_cat($value['id']);
      db_update('itg_widget_order')
          ->fields(array('weight' => $value['weight'] , 'extra' => $issue_date , ))
          ->condition('widget' , 'issue_supplement_magazin_widget')
          ->condition('nid' , $value['id'])
          ->condition('extra' , $issue_date)
          ->execute();
    }
  }
}
