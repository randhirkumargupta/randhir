<?php

/**
 * @file
 * itg_widget_actions_bulk_operation.inc
 *
 * This file provide an extra action bulk operation to add nodes into our custom table.
 *
 */

/**
 * {@inheritdoc}
 */
function itg_widget_action_info() {
  return array(
    'itg_widget_categories_wise_node_group' => array(
      'type' => 'entity' ,
      'label' => t('Add nodes by category wise') ,
      'configurable' => TRUE ,
      'vbo_configurable' => FALSE ,
      'triggers' => array('any') ,
    ) ,
  );
}

/**
 * {@inheritdoc}
 */
function itg_widget_categories_wise_node_group_form($form , &$form_state) {

  $form = array();

  $view_name = $form_state['build_info']['args'][0]->name;
  $current_display = $form_state['build_info']['args'][0]->current_display;
  $widget = _get_widget_name("views_form_" . $view_name . "_page" , $current_display);
  // Confirm message is added for altered form.
  // For nodequeue bulk operation message is added from itg_widget.main.js.
  $form['confirm_message'] = array(
    '#markup' => t("<p class='widget-confirm-message'>Are you sure you want add this content ?</p>") ,
  );

  $form['widget_name'] = array(
    '#type' => 'select' ,
    '#options' => array($widget => "widget") ,
    '#weight' => -1 ,
    '#attributes' => array("style" => array("display:none")) ,
  );

  return $form;
}

/**
 * {@inheritdoc}
 */
function itg_widget_categories_wise_node_group_submit($form , &$form_state) {
  $current_display = $form_state['build_info']['args'][0]->current_display;
  $vals = array();
  // Unique combination using below four.
  $widget_name = $form_state['input']['widget_name'];
  // Get selected nodes ids
  $selected_node_data = $form_state['selection'];
  $get_category_id = -1;
  if ( isset($_GET['category_tid']) && $_GET['category_tid'] == "All" ) {
    $get_category_id = 0;
  }
  elseif ( is_numeric($_GET['category_tid']) ) {
    $get_category_id = $_GET['category_tid'];
  }
  $cat_id = $get_category_id;
  $content_type = isset($_GET['type']) ? $_GET['type'] : NULL;
  if ( $current_display == 'big_story_format' ) {
    // All Code for big sotry.
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_big_story');
    $big_story_data = $form_state;
    save_big_story_widget_data($big_story_data);
  }
  ######################## WIDGET CHANGES ###################
  elseif ( $widget_name == "top_stories_widget" && $current_display == "page_1" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "trending_videos_widget" && $current_display == "trending_videos" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "most_popular_widget" && $current_display == "most_popular" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "top_takes_video_widget" && $current_display == "top_takes_video" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "watch_right_now_widget" && $current_display == "watch_right_now" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "home_page_feature_widget" && $current_display == "page_1" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "photo_carousel_list_widget" && $current_display == "photo_carousel_list" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "video_carousel_list_widget" && $current_display == "video_carousel_list" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "we_may_suggest_widget" && $current_display == "we_may_suggest_widget" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  elseif ( $widget_name == "anchors_listing_widget" && $current_display == "anchors_listing_page" ) {
    itg_widget_save_bulk_operation_widget_data($form_state , $widget_name);
  }
  #################################################################
  elseif ( $current_display == 'dont_miss_content' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_dont_miss');
    $dont_miss_content = $form_state;
    save_dont_miss_widget_data($dont_miss_content);
  }
  elseif ( $current_display == 'special_auto_review_widget_contents' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_special_auto_review');
    save_special_auto_review_widget_data($form_state);
  }
  elseif ( $current_display == 'special_how_made_it_widget_contents' ) {

    if ( empty($_GET['category_tid']) && $_GET['category_tid'] != 'All' ) {
      drupal_set_message(t('Please select Section') , 'error');
      drupal_goto('special-how-made-it-widget-contents');
    }
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_special_how_i_made_it');
    save_special_how_i_made_it_widget_data($form_state);
  }
  elseif ( $current_display == 'yearend_left_widget_contents' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_yearender_left');
    save_yearender_left_widget_data($form_state);
  }
//  elseif ($current_display == 'we_may_suggest_widget') {
//    module_load_include('inc', 'itg_widget', 'includes/we-may-suggest');
//    $we_may_suggest_content = $form_state;
//    save_we_may_suggest_widget_data($we_may_suggest_content);
//  }
  elseif ( $current_display == 'so_sorry_videos' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_so_sorry');
    save_so_sorry_widget_data($form_state);
  }
  elseif ( $current_display == 'poll_widget_format' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_poll');
    save_poll_widget_data($form_state);
  }
  elseif ( $current_display == 'highlights_widget_conent' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_highlights');
    save_highlights_widget_data($form_state);
  }
  elseif ( $current_display == 'issue_base_magazin_widget' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_issue_base_magazin_widget');
    save_issue_magazin_widget_data($form_state);
  }
  elseif ( $current_display == 'most_read_widget_contents' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_most_read');
    save_most_read_widget_data($form_state);
  }
  elseif ( $current_display == 'special_key_candidate_widget_contents' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_key_candidate');
    save_key_candidate_data($form_state);
  }
  elseif ( $current_display == 'feature_content_section_widget_contents' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_feature_content_section');
    save_feature_content_section_widget_data($form_state);
  }
  elseif ( $current_display == 'user_selection_for_section' ) {
    if ( isset($_GET['field_user_section_tid']) && !empty($_GET['field_user_section_tid']) ) {
      module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_section_wise_user');
      save_default_user_for_every_section($form_state);
    }
  }
  elseif ( $current_display == 'issue_category_magazin_widget' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_section_wise_magazine');
    save_primary_category_acccording_issue_magazine($form_state);
  }
  elseif ( $current_display == 'supplement_base_magazin_widget' ) {
    module_load_include('inc' , 'itg_widget' , 'includes/itg_widget_section_wise_magazine');
    save_supplement_acccording_issue_magazine($form_state);
  }
  else {
    // Logic to skip nodes which are already in itg_widget_order table
    $nodes_already = db_select('itg_widget_order' , 'iwo')
            ->condition('iwo.content_type' , $content_type)
            ->condition('iwo.widget' , $widget_name)
            ->condition('iwo.cat_id' , $cat_id)
            ->fields('iwo' , array('nid'))
            ->execute()->fetchAll();
    foreach ($nodes_already as $val) {
      $vals[] = $val->nid;
    }
    // Remove nodes which are already in itg_widget_order table with combination of content type , widget name , cat_id , nid.
    foreach ($selected_node_data as $key => $node_data) {
      if ( in_array($node_data , $vals) ) {
        unset($selected_node_data[$key]);
      }
    }

    if ( count($selected_node_data) ) {
      foreach ($selected_node_data as $node) {
        db_insert('itg_widget_order')
            ->fields(array(
              'nid' => $node ,
              'widget' => $widget_name ,
              'content_type' => ($content_type) ? $content_type : " " ,
              'cat_id' => ($cat_id) ? $cat_id : 0 ,
              'weight' => 0 ,
            ))
            ->execute();
      }
      drupal_set_message(t("Nodes has been saved"));
    }
    else {
      drupal_set_message(t("Selected nodes allready in ordering section"));
    }
  }
  return array(
    'form_values' => $form_state['values'] ,
  );
}
