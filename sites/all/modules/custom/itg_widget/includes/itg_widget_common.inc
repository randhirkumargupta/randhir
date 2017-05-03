<?php

/**
 * @file
 * Common file for widgets.
 *
 */

/**
 * Function used to add or delete widgit ids into session for Selected content id should be display on top.
 * 
 */
function itg_widget_setids() {
  $datatoset = array();
  $datatoset = $_SESSION[$_POST['formid']];

  if (is_array($_POST['checkid'])) {
    foreach ($_POST['checkid'] as $ids) {
      if ($_POST['type'] == 'ADD') {
        $datatoset[] = $ids;
      }
      elseif ($_POST['type'] == 'REMOVE') {
        if (($key = array_search($ids, $datatoset)) !== FALSE) {

          unset($datatoset[$key]);
        }
      }
    }
  }
  else {

    if (empty($datatoset)) {
      $datatoset[] = $_POST['checkid'];
    }
    if ($_POST['type'] == 'ADD') {
      array_push($datatoset, $_POST['checkid']);
    }
    elseif ($_POST['type'] == 'REMOVE') {

      if (($key = array_search($_POST['checkid'], $datatoset)) !== FALSE) {
        unset($datatoset[$key]);
      }
    }
  }
  $datatoset = array_unique($datatoset);
  $_SESSION[$_POST['formid']] = $datatoset;
  echo json_encode($_SESSION[$_POST['formid']]);
}

function remove_extra_data() {
//  $widget = array(
////      'widget_anchors_listing',
////      'home_page_feature_widget',
////      'story_widget',
////        'section_wise_content_ordering_list',
////      'section_wise_draggable_content_order',
////      'big_story_format_widget',
//      'dont_miss_content_widget',
//      'dont_miss_content',
//      'section_wise_widget',
////      'we_may_suggest_widget',
////      'section_wise_content_ordering',
////      'widget_anchors_listing',
////      'category_wise_content_list',
////     'photo_carousel_widget',
//  );
//  foreach ($widget as $view_name) {
//    $num_deleted = db_delete('draggableviews_structure')
//            ->condition('view_name', $view_name)
//            ->condition('view_display', 'dont_miss_content')
//            ->execute();
//
//    $num_deleted = db_delete('itg_widget_order')
//            ->condition('widget', $view_name)
//            ->execute();
//  }

  db_query("ALTER TABLE  itg_menu_manager ADD  bk_color VARCHAR( 100 ) NOT NULL DEFAULT  '#cccccc'")->execute();

}

/**
 * Funtion used to delete node combination form itg_widget_order table.
 * 
 * @param string $widget_name
 * @param string $content_type
 * @param int $cat_tid
 * @param int $nid
 */
function move_node_from_dont_miss_widget($widget_name, $content_type, $cat_tid, $nid) {
  if (!empty($widget_name) && !empty($nid)) {
    $num = db_delete('itg_widget_order')
            ->condition('nid', $nid)
            ->condition('widget', $widget_name)
            ->execute();
    if ($num) {
      drupal_set_message(t("Node has been moved"));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
    else {
      drupal_set_message(t("Node id or widget name not found"));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
  }
}

/**
 * Function to remove term.
 * @param int $tid
 */
function remove_state_term($tid) {
  if ($tid) {
    taxonomy_term_delete($tid);
  }
  drupal_set_message(t("Term Deleted"));
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Funtion used to delete node combination form itg_widget_order table.
 * 
 * @param string $widget_name
 * @param string $content_type
 * @param int $cat_tid
 * @param int $nid
 */
function move_node_from_key_candidate_widget($widget_name, $cat_tid, $state, $nid) {
  if (!empty($widget_name) && !empty($nid)) {
    $num = db_delete('itg_widget_order')
            ->condition('nid', $nid)
            ->condition('cat_id', $cat_tid)
            ->condition('state', $state)
            ->condition('widget', $widget_name)
            ->execute();
    if ($num) {
      drupal_set_message(t("Node has been moved"));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
    else {
      drupal_set_message(t("Node id or widget name not found"));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
  }
}

/**
 * Function used to delete node combination form itg_widget_order table.
 * 
 * @param string $widget_name
 * @param string $content_type
 * @param int $cat_tid
 * @param int $nid
 */
function move_node_from_widget($widget_name, $content_type, $cat_tid, $nid) {
  if (!empty($widget_name) && !empty($cat_tid) && !empty($nid)) {
    $num = db_delete('itg_widget_order')
            ->condition('nid', $nid)
//->condition('content_type', $content_type)
            ->condition('cat_id', $cat_tid)
            ->condition('widget', $widget_name)
            ->execute();
    if ($num) {
      drupal_set_message(t("Node has been moved"));
      drupal_goto($_SERVER['HTTP_REFERER']);
    }
  }
}

/**
 * Function is used to remove extra field value croospond to nid.
 * 
 * @param int $nid
 */
function remove_extra_field_value_for_so_sorry($nid) {
  $extra_field_value = get_so_sorry_extra_for_nid($nid);
  db_update('itg_widget_order')
          ->fields(array('extra' => " "))
          ->condition('nid', $nid)
          ->condition('widget', 'so_sorry_widget')
          ->execute();
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Function is used to add extra field value croospond to nid.
 * 
 * @param int $nid
 * @param string $extra
 */
function add_extra_field_value_for_so_sorry($nid, $extra) {
// Handling only single nid can be either feature or remix;
  $so_sorry_extra_nodes = db_select('itg_widget_order', 'iwo')
                  ->condition('iwo.extra', $extra)
                  ->fields('iwo', array('nid'))
                  ->execute()->fetchAll(PDO::FETCH_ASSOC);

  foreach ($so_sorry_extra_nodes as $key => $nids) {
    db_update('itg_widget_order')
            ->fields(array('extra' => " "))
            ->condition('nid', $nids['nid'])
            ->condition('widget', 'so_sorry_widget')
            ->execute();
  }

  db_update('itg_widget_order')
          ->fields(array('extra' => $extra))
          ->condition('nid', $nid)
          ->condition('widget', 'so_sorry_widget')
          ->execute();

  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Function used for delete node from draggableviews_structure and nodequeue
 * @param int $nid
 * @param int $qid
 * @param string $view_name
 * @param string $page_name
 */
function remove_from_widgets_with_section($nid, $qid, $view_name, $page_name, $section_tid, $type) {
  $draggable_delete = draggable_view_node_delete_section($view_name, $page_name, $nid, $section_tid, $type);
  if ($draggable_delete) {
    nodequeue_subqueue_remove_node($qid, $nid);
    echo "deleted";
  }
  else {
    echo "not-deleted";
  }
}

/**
 * Function used to delete form draggableviews_structure table
 * @param string $view_name
 * @param string $page_name
 * @param int $nid
 * @return int
 */
function draggable_view_node_delete_section($view_name, $page_name, $nid, $section_tid, $type) {
  if (!empty($view_name) && !empty($page_name) && !empty($nid) && !empty($section_tid) && !empty($type)) {
    $args = '{"field_story_category_tid":"' . $section_tid . '","type":"' . $type . '"}';
    $num_deleted = db_delete('draggableviews_structure')
            ->condition('view_name', $view_name)
            ->condition('view_display', $page_name)
            ->condition('entity_id', $nid)
            ->condition('args', $args)
            ->execute();
    return $num_deleted;
  }
}

/**
 * Function used for delete node from draggableviews_structure and nodequeue
 * @param int $nid
 * @param int $qid
 * @param string $view_name
 * @param string $page_name
 */
function remove_from_widgets($nid, $qid, $view_name, $page_name) {
  $draggable_delete = draggable_view_node_delete($view_name, $page_name, $nid);
  nodequeue_subqueue_remove_node($qid, $nid);
  if ($draggable_delete) {
//nodequeue_subqueue_remove_node($qid, $nid);
    print "deleted";
  }
  else {
    print "notdeleted";
  }
  drupal_set_message(t("Node has been moved"));
  drupal_goto($_SERVER['HTTP_REFERER']);
}

/**
 * Function used to delete form draggableviews_structure table
 * @param string $view_name
 * @param string $page_name
 * @param int $nid
 * @return int
 */
function draggable_view_node_delete($view_name, $page_name, $nid) {
  if (!empty($view_name) && !empty($page_name) && !empty($nid)) {
    $num_deleted = db_delete('draggableviews_structure')
            ->condition('view_name', $view_name)
            ->condition('view_display', $page_name)
            ->condition('entity_id', $nid)
            ->execute();
    return $num_deleted;
  }
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 * @param array $form
 * @param array $form_state
 */
function itg_widget_keycandidate_form($form, $form_state) {
  $pre_fix = "";
  $suf_fix = "";
  $op = getsaction_list();

  $form['cat_value'] = array(
      '#type' => 'select',
      '#title' => 'Section <span class="form-required" title="This field is required.">*</span>',
      '#options' => $op,
      '#ajax' => array(
          'callback' => 'ajax_dependent_dropdown_state',
      //'wrapper' => 'view-display-isesue',
      ),
      '#prefix' => $pre_fix,
      '#suffix' => $suf_fix,
  );
  $state_class = "visible";
  $states_neame = array();
  $states_neame = get_all_state($form_state['input']['cat_value']);
//    if (isset($_POST['state_value'])) {
//        $pre_fix = "<div style='display:none'>";
//        $suf_fix = "</div>";
//    }

  $form['state_value'] = array(
      '#type' => 'select',
      '#title' => 'State <span class="form-required" title="This field is required.">*</span>',
      '#multiple' => TRUE,
      '#options' => $states_neame,
      '#prefix' => '<div id="view-display-isesue">',
      '#suffix' => '</div>',
  );




  $form['alt_button'] = array(
      '#type' => 'submit',
      '#value' => t('Apply'),
  );
  $form['#validate'][] = 'itg_widget_keycandidate_validate';
  return $form;
}

/**
 * this function use for get section list
 */
function getsaction_list() {
  $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
  // override taxonomy.
  $tax = itg_widget_get_active_taxonomy($tax);
  $op = array("All" => " - None -");
  foreach ($tax as $key => $val) {
    $op[$val->tid] = $val->name;
  }
  return $op;
}

/**
 * This function use for get state
 */
function get_all_state($cat) {
  $states_neame = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('state_managment');
 
  $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
  $states_neame[] = 'Select';
  foreach ($terms as $values) {
    if ($cat == $values->field_section[LANGUAGE_NONE][0]['tid']) {
      $states_neame[$values->tid] = $values->name;
    }
    if (empty($cat)) {
      $states_neame[$values->tid] = $values->name;
    }
  }
  return $states_neame;
}

/**
 * This mentod will go to keycandidate widget filter url
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_keycandidate_form_submit($form, $form_state) {

  $query = array('state_val' => $form_state['values']['state_value'], 'cat_id' => $form_state['values']['cat_value']);
  drupal_goto('special-key-candidate-widget-contents', array('query' => $query));
}

/**
 * {@inheritdoc}
 */
function itg_widget_form_alter(&$form, &$form_state, $form_id) {
  global $base_url;

  if ($form['#id'] == 'taxonomy-form-term') {
    //drupal_add_css("#edit-field-set-as-featured-cate {display:none !important}" , "inline");
  }
  // Alter form for confirm message during bulk operation.
  $form_id_array_to_alter = array(
      'views_form_section_wise_draggable_content_order_big_story_format',
      'views_form_section_wise_draggable_content_order_dont_miss_content',
      'views_form_section_wise_draggable_content_order_we_may_suggest_widget',
      'views_form_section_wise_draggable_content_order_page',
  );

  if (in_array($form_id, $form_id_array_to_alter)) {
    $form['actions']['submit']['#value'] = t('Confirm');
  }


  foreach (forms_uses_checked_content_id() as $forms) {
//$form['submit']['#validate'][] = 'session_dependent_custom_form_validation';
  }

  $syndication_form = sydication_field_filter_views_form();
  if (in_array($form['#id'], $syndication_form)) {
    $sydication_field_name = 'field_story_syndication_value_1_op';
    $query_url = array("title" => "", "field_recipe_content_type_value" => "All", "field_story_syndication_value_op" => "all", "field_story_syndication_value" => "Yes");
    if ($form['#id'] == 'views-exposed-form-videogallery-management-page-1' || $form['#id'] == 'views-exposed-form-photo-gallery-management-page-1' || $form['#id'] == 'views-exposed-form-strory-menegment-page-1' || $form['#id'] == 'views-exposed-form-recipe-management-page-1' || $form['#id'] == 'views-exposed-form-recipe-management-page-2') {
      $sydication_field_name = 'field_story_syndication_value_op';
      $query_url = array("title" => "", "field_recipe_content_type_value" => "All", "field_story_syndication_value_op" => "all", "field_story_syndication_value" => "Yes");
      drupal_add_css(".form-item-field-story-syndication-value {display:none !important}", "inline");
    }
    if ($form['#id'] == 'views-exposed-form-recipe-management-page') {
      $query_url = array("field_story_syndication_value_1_op" => "all");
      drupal_add_css(".form-item-field-story-syndication-value-1 {display:none !important}", "inline");
    }

    unset($form[$sydication_field_name]['#options']);
    $form[$sydication_field_name]['#options']['all'] = '- Any -';
    $form[$sydication_field_name]['#options']['or'] = 'Yes';
    $form[$sydication_field_name]['#options']['not'] = 'No';

    drupal_add_css('.form-item-field-story-syndication-value-1 , .form-item-field-story-syndication-value {display:none;}', array('type' => 'inline'));
    drupal_add_css('.views-widget-filter-field_story_syndication_value_1 , .views-widget-filter-field_story_syndication_value {display:inline-block !important;}', array('type' => 'inline'));

    $url_chunk = explode("?", $_SERVER['REQUEST_URI']);
    $url_chunk_array = explode('/', $url_chunk[0]);
    $url_without_query_string = end($url_chunk_array);

    $form['reset'] = array(
        '#type' => 'markup',
        '#markup' => l(t("Reset"), $url_without_query_string, array("query" => $query_url)),
    );
  }
  if ($form_id == 'views_form_section_wise_content_ordering_list_page') {
    $type_in_url = $_GET['type'];
    $actual_weight_type = 'All';
    $types = array("story", "videogallery", "photogallery");
    if (in_array($type_in_url, $types)) {
      $actual_weight_type = $type_in_url;
    }

    $views_current_nid = array();
    $view = views_get_current_view();
    $taxonomy_term_data_comma = implode(",", $views_current_nid);
    $itg_widget_order_data = db_select('itg_widget_order', 'iwo')
            ->fields('iwo', array('weight', 'nid'))
            ->condition('cat_id', $_GET['category_tid']);
    foreach ($view->result as $view_result_data) {
      //$views_current_nid[] = $view_result_data->node_itg_widget_order_nid;
      $itg_widget_order_data->condition('nid', $view_result_data->node_itg_widget_order_nid);
    }
    $itg_widget_order_data->condition('content_type', $actual_weight_type)
            ->condition('widget', 'section_wise_widget')
            ->execute()->fetchAll();
//pr($itg_widget_order_data);
//Prepare weight crosspond to nid.
    $select_map_array = array();
    foreach ($itg_widget_order_data as $order_data) {
      $select_map_array[$order_data->nid] = $order_data->weight;
    }

// Prepare weights in array. 
//    $select_map_array_weight = array();
//    foreach ($itg_widget_order_data as $order_data) {
//      $select_map_array_weight[] = $order_data->weight;
//    }
    //pr($form['draggableviews']);
    foreach ($form['draggableviews'] as $key => $weight) {


// echo $key."</br>";
// make options to weight drop down equal to saved weight value.
      //$form['draggableviews'][$key]['weight']['#options'] = drupal_map_assoc($select_map_array_weight);
      $form['draggableviews'][$key]['weight']['#options'] = drupal_map_assoc(array($select_map_array[$form['draggableviews'][$key]['id']['#value']] => $select_map_array[$form['draggableviews'][$key]['id']['#value']]));
//$form['draggableviews'][$key]['weight']['#options'] = array($key => $key);
// make default selected value as saved in database.
      $form['draggableviews'][$key]['weight']['#default_value'] = $select_map_array[$form['draggableviews'][$key]['id']['#value']];
      $form['draggableviews'][$key]['weight']['#validated'] = TRUE;
    }
  }

  drupal_add_css("select.draggableviews-weight {display:none !important}", "inline");
  drupal_add_css("#draggableviews-table-section-wise-content-ordering-list-page .tabledrag-handle {display:none !important}", "inline");

  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'special_auto_review_widget' && ($form_state['view']->current_display == 'special_auto_review_widget_contents' || $form_state['view']->current_display == 'special_auto_review_widget_list')) {

    $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);

    // override taxonomy.
    $tax = itg_widget_get_active_taxonomy($tax);
  }

  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'most_read_widget' && ($form_state['view']->current_display == 'most_read_widget_contents' || $form_state['view']->current_display == 'most_read_widget_list')) {
    $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
    // override taxonomy.
    $tax = itg_widget_get_active_taxonomy($tax);
    $op = array("All" => " - None -");
    foreach ($tax as $key => $val) {
      $op[$val->tid] = $val->name;
    }
    unset($form['category_tid']['#options']);
    $form['category_tid']['#options'] = $op;
  }


  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'special_how_i_made_it' && ($form_state['view']->current_display == 'special_how_made_it_widget_contents' || $form_state['view']->current_display == 'special_how_made_widget_list')) {
    $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
    // override taxonomy.
    $tax = itg_widget_get_active_taxonomy($tax);
    $op = array("All" => " - None -");
    foreach ($tax as $key => $val) {
      $op[$val->tid] = $val->name;
    }
    unset($form['category_tid']['#options']);
    $form['category_tid']['#options'] = $op;
  }


  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'special_how_i_made_it' && ($form_state['view']->current_display == 'special_how_made_it_widget_contents' || $form_state['view']->current_display == 'special_how_made_widget_list')) {

    $tax = taxonomy_get_tree(CATEGORY_MANAGMENT, $parent = 0, $max_depth = 1, $load_entities = FALSE);
    // override taxonomy.
    $tax = itg_widget_get_active_taxonomy($tax);

    $op = array("All" => " - None -");
    foreach ($tax as $key => $val) {
      $op[$val->tid] = $val->name;
    }
    unset($form['category_tid']['#options']);
    $form['category_tid']['#options'] = $op;
  }
// Hiding section filed from basic page (Static page node form)
  if ($form_id == 'page_node_form') {
    //   drupal_add_css("div.form-item-field-page-section-und {display:none}", 'inline');
  }

  if (in_array($form_id, itg_widget_order_reorder_form())) {
    $form['actions']['submit']['#submit'][] = "itg_widget_update_weight_during_order_reorder";
  }
// Assign deafult values in case of checkbox are checked.
  $form = get_sessions_of_ticked_nodes($form);
}

// Exposed filter forms id
function sydication_field_filter_views_form() {
  return array(
      'views-exposed-form-recipe-management-page',
      'views-exposed-form-recipe-management-page-1',
      'views-exposed-form-recipe-management-page-2',
      'views-exposed-form-strory-menegment-page-1',
      'views-exposed-form-photo-gallery-management-page-1',
      'views-exposed-form-videogallery-management-page-1'
  );
}

/**
 * {@inheritdoc}
 */
function session_dependent_custom_form_validation(&$form, &$form_state) {
  if (empty($_SESSION[$form['#form_id']])) {
    form_set_error("Please select at least one item.");
  }
  else {
    return TRUE;
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_views_bulk_operations_form_alter(&$form, &$form_state, $vbo) {
  if ($form['#form_id'] == 'views_form_section_wise_draggable_content_order_big_story_format') {
    if (!isset($_POST['views_bulk_operations'])) {
      drupal_add_js(drupal_get_path('module', 'itg_widget') . '/js/itg_live_tv.js', 'file');
      $big_story_value = itg_big_story_get_extra_value();
      if (in_array('big_story_live_tv_active', $big_story_value)) {
        $yes_live = "checked";
        $no_live = "";
      }
      else {
        $yes_live = "";
        $no_live = "checked";
      }
      // Activate live tv button
      $form['select']['action::itg_widget_categories_wise_node_group']['#suffix'] = '
                <div class="switch-field">
                 <div class="switch-title">' . t('Activate Live TV:') . ' </div>
                 <input type="radio" id="switch_left" name="live_tv_switch_2" value="yes" ' . $yes_live . '/>
                 <label for="switch_left">' . t('Yes') . '</label>
                 <input type="radio" id="switch_right" name="live_tv_switch_2" value="no" ' . $no_live . ' />
                 <label for="switch_right">' . t('No') . '</label>
               </div>';
    }
  }
}

/**
 * Function custom submit for destorying the session for current form id.
 * 
 * @param array $form
 * @param array $form_state
 * @return array
 */
function itg_widget_custom_session_destory($form, &$form_state) {
  $_SESSION[$form['#form_id']] = array();
  unset($_SESSION[$form['#form_id']]);
  return array(
      'form_values' => $form_state['values'],
  );
}

/**
 * Function returns array of all the formid which use checked unchecked
 * Session dependency.
 * 
 * @return array
 */
function forms_uses_checked_content_id() {
  return array(
      'views_form_story_widget_page_1',
      'views_form_widget_anchors_listing_anchors_listing_page',
      'views_form_section_wise_draggable_content_order_dont_miss_content',
      'views_form_home_page_feature_widget_page_1',
      'views_form_section_wise_draggable_content_order_we_may_suggest_widget',
      'views_form_story_widget_most_popular',
      'views_form_section_wise_draggable_content_order_page',
      'views_form_story_widget_trending_videos',
      'views_form_story_widget_top_takes_video',
      'views_form_story_widget_watch_right_now',
      'views_form_photo_carousel_widget_photo_carousel_list',
      'views_form_photo_carousel_widget_video_carousel_list',
      'views_form_so_sorry_so_sorry_videos',
      'views_form_special_auto_review_widget_special_auto_review_widget_contents',
      'views_form_special_how_i_made_it_special_how_made_it_widget_contents',
      'views_form_yearender_top_news_and_top_videos_yearend_left_widget_contents',
      'views_form_most_read_widget_most_read_widget_contents',
      'views_form_key_candidate_special_key_candidate_widget_contents',
  );
}

/**
 * Function is used for get the session values
 * @param array $form
 * @return array
 */
function get_sessions_of_ticked_nodes(&$form) {

  return $form;
}

/**
 * {@inheritdoc}
 */
function itg_widget_theme() {

  $themes = array(
      'section_wise_ordering' => array(
          'template' => 'templates/section-ordering-data',
      ),
      'rhs_section_wise_ordering' => array(
          'template' => 'templates/rhs-section-ordering-data',
      ),
      'top_stories_ordering' => array(
          'template' => 'templates/top-stories-ordering-data',
      ),
      'home_page_feature' => array(
          'template' => 'templates/home-page-feature',
      ),
      'we_may_suggest' => array(
          'template' => 'templates/we-may-suggest',
      ),
      'widget_big_story_format' => array(
          'template' => 'templates/big-story-format',
      ),
      'trending_videos_widget' => array(
          'template' => 'templates/trending-videos-widget',
      ),
      'most_popular_widget' => array(
          'template' => 'templates/most-popular-widget',
      ),
      'featured_photo_carousel' => array(
          'template' => 'templates/featured-photo-carousel',
      ),
      'featured_photo_carousel_rollingslider' => array(
          'template' => 'templates/featured-photo-carousel-rollingslider',
      ),
      'featured_video_carousel' => array(
          'template' => 'templates/featured-video-carousel',
      ),
      'featured_video_carousel_rollingslider' => array(
          'template' => 'templates/featured-video-carousel-rollingslider',
      ),
      'dont_miss_widget' => array(
          'template' => 'templates/dont-miss-widget',
      ),
      'top_takes_videos_widget' => array(
          'template' => 'templates/top-takes-videos-widget',
      ),
      'itg_widget_watch_right_now_videos_widget' => array(
          'template' => 'templates/watch-right-now-videos-widget',
      ),
      'anchor_langing_page_menu' => array(
          'template' => 'templates/anchor-landing-page-menu',
      ),
      'personlization_front_end' => array(
          'template' => 'templates/personlization-front-end',
      ),
      'year_end_top_news' => array(
          'template' => 'templates/year-end-top-news',
      ),
      'how_made_it' => array(
          'template' => 'templates/how-made-it',
      ),
      'year_end_top_videos' => array(
          'template' => 'templates/year-end-top-videos',
      ),
      'auto_reviews' => array(
          'template' => 'templates/auto-reviews',
      ),
      'graph_election' => array(
          'template' => 'templates/itg-widget-graph-election',
      ),
      'itg_widget_politoons' => array(
          'template' => 'templates/itg-widget-politoons',
      ),
      'tech_reviews' => array(
          'template' => 'templates/auto-reviews',
      ),
      'tech_most_read' => array(
          'template' => 'templates/tech-most-read',
      ),
      'live_score_data' => array(
          'template' => 'templates/live-score-data',
      ),
      'podcast_banner' => array(
          'template' => 'templates/podcast-banner',
      ),
  );
  return $themes;
}

/**
 * {@inheritdoc}
 */
function get_required_data_from_entity_id($entity_id) {
  return entity_load('node', array($entity_id));
}

/**
 * {@inheritdoc}
 */
function itg_widget_form_views_exposed_form_alter(&$form, &$form_state, $form_id) {

  if (isset($form['type']) && !empty($form['type'])) {
    foreach ($form['type']['#options'] as $optionkey => $optiondata) {
      if ($optionkey == 'videogallery') {
        $form['type']['#options'][$optionkey] = 'Video';
      }
    }
  }
  switch ($form['#id']) {
     
    case 'views-exposed-form-home-page-feature-widget-page-1':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;

    case 'views-exposed-form-section-wise-draggable-content-order-we-may-suggest-widget':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type'], TRUE, 'story');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-story-widget-most-popular':
    case 'views-exposed-form-story-widget-page-1':
      $form['title']['#attributes']['placeholder'] = t('Story Title');
      $form['title']['#autocomplete_path'] = 'content-title-list/story/autocomplete';
      $form['nid']['#attributes']['placeholder'] = t('Story ID');
      $form['nid']['#autocomplete_path'] = 'content-nid-list/story/autocomplete';
      break;
    case 'views-exposed-form-photo-carousel-widget-photo-carousel-list':
      $form['title']['#attributes']['placeholder'] = t('Photo Gallery Title');
      $form['title']['#autocomplete_path'] = 'content-title-list/photogallery/autocomplete';
      $form['nid']['#attributes']['placeholder'] = t('Photo Gallery ID');
      $form['nid']['#autocomplete_path'] = 'content-nid-list/photogallery/autocomplete';
      break;
    case 'views-exposed-form-photo-carousel-widget-video-carousel-list':
      $form['title']['#attributes']['placeholder'] = t('Video Gallery Title');
      $form['title']['#autocomplete_path'] = 'content-title-list/videogallery/autocomplete';
      $form['nid']['#attributes']['placeholder'] = t('Video Gallery ID');
      $form['nid']['#autocomplete_path'] = 'content-nid-list/videogallery/autocomplete';
      break;
    case 'views-exposed-form-story-widget-trending-videos':
    case 'views-exposed-form-story-widget-top-takes-video':
    case 'views-exposed-form-story-widget-watch-right-now':
      $form['title']['#attributes']['placeholder'] = t('Video Title');
      $form['nid']['#attributes']['placeholder'] = t('Video ID');
      $form['nid']['#autocomplete_path'] = 'content-nid-list/videogallery/autocomplete';
      $form['title']['#autocomplete_path'] = 'content-title-list/videogallery/autocomplete';
      break;
    case 'views-exposed-form-so-sorry-so-sorry-videos':
      $cat_setting = trim(variable_get('so_sorry_category_id_for_widget'));
      if (strlen($cat_setting) <= 0) {
        $setting_link = l(t("Click Here"), "admin/settings/custom-variables");
        drupal_set_message(t("Setting not found for autocomplete"), "error");
      }
      $form['title']['#attributes']['placeholder'] = t('Video Title');
      $form['nid']['#attributes']['placeholder'] = t('Video ID');
      $form['title']['#autocomplete_path'] = 'so-sorry-content-title/autocomplete';
      $form['nid']['#autocomplete_path'] = 'so-sorry-content-nid/autocomplete';
      break;
    case 'views-exposed-form-section-wise-draggable-content-order-big-story-format':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type'], TRUE);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-section-wise-draggable-content-order-dont-miss-content':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-special-auto-review-widget-special-auto-review-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-most-read-widget-most-read-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;

    case 'views-exposed-form-special-how-i-made-it-special-how-made-it-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-feature-content-by-section-widget-feature-content-section-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-poll-widget-poll-widget-format':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets('poll');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-highlights-widget-highlights-widget-conent':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets('breaking_news');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      break;
    case 'views-exposed-form-yearender-top-news-and-top-videos-yearend-left-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $type = isset($_GET['type']) ? $_GET['type'] : "story";
      $form['title']['#autocomplete_path'] = "node-list-for-year-end/title/$type/autocomplete";
      $form['nid']['#autocomplete_path'] = "node-list-for-year-end/nid/$type/autocomplete";
      break;
    case 'views-exposed-form-widget-anchors-listing-anchors-listing-page':
      $form['title']['#attributes']['placeholder'] = t('Anchor name');
      $form['title']['#autocomplete_path'] = 'anchor-list/autocomplete';
      $form['nid']['#attributes']['placeholder'] = t('Anchor ID');
      $form['nid']['#autocomplete_path'] = 'anchor-list-nid/autocomplete';
      break;
    case 'views-exposed-form-section-wise-draggable-content-order-page':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets($_GET['type']);
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      $form['#validate'][] = 'custom_section_wise_validate';
      break;
    case 'views-exposed-form-key-candidate-special-key-candidate-widget-contents':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets('reporter');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      $form['#validate'][] = 'custom_section_wise_validate';
      $states_name = get_all_state($_GET['cat_id']);

      $form['state_val'] = array(
          '#type' => 'select',
          '#multiple' => TRUE,
          '#default_value' => '',
          '#validated' => TRUE,
          '#options' => $states_name,
      );
      $form['state_val']['#prefix'] = '<div class=""style="display:none">';
      $form['state_val']['#suffix'] = '</div>';

      $op = getsaction_list();

      $form['cat_id'] = array(
          '#type' => 'select',
          '#options' => $op,
      );
      $form['cat_id']['#prefix'] = '<div class=""style="display:none">';
      $form['cat_id']['#suffix'] = '</div>';
      break;
    case 'views-exposed-form-key-candidate-special-key-candidate-widget-list':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['title']['#weight'] = 1;
      $form['nid']['#weight'] = 2;
      $form['title']['#weight'] = 1;
      $form['items_per_page']['#weight'] = 5;
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets('reporter');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
      $form['#validate'][] = 'custom_section_wise_validate';
      $form['cat_id']['#prefix'] = '<div class="cat-wraper"style="">';
      $form['cat_id']['#suffix'] = '</div>';
      $form['cat_id']['#title'] = '';
      $form['state']['#prefix'] = '<div class="state-wraper"style="">';
      $form['state']['#suffix'] = '</div>';
      $op = getsaction_list();
      $form['cat1_id']['#type'] = 'select';
      $form['cat1_id']['#options'] = $op;
      $form['cat1_id']['#weight'] = -9999;
      $form['cat1_id']['#default_value'] = $_GET['cat_id'];
      $allstate = get_all_state();
      $form['state1']['#type'] = 'select';
      $form['state1']['#options'] = $allstate;
      $form['state1']['#weight'] = -99994;
      $form['state1']['#default_value'] = $_GET['state'];
      break;
    case 'views-exposed-form-section-wise-content-ordering-list-page':
      if ($_GET['category_tid'] == 0) {
        drupal_add_css(".messages--error {display:none}", "inline");
      }
      // handle expose content type of itg_widget_order table.
      $form['content_type']['#default_value'] = 'all';
      $form['content_type']['#value'] = 'all';
      $form['Canlce'] = array(
          '#type' => 'markup',
          '#markup' => l(t('Reset'), 'section-wise-content-ordering-list', array("attributes" => array("class" => array("button")), "query" => array("category_tid" => 0))),
      );
      drupal_add_css("#edit-content-type-wrapper {display:none}", 'inline');
      $form['#validate'][] = 'custom_section_wise_validate';
      break;
    case 'views-exposed-form-static-pages-page':
      $form['title']['#attributes']['placeholder'] = t('Page Title');
      $form['title']['#autocomplete_path'] = 'content-title-list/page/autocomplete';
      $form['nid']['#attributes']['placeholder'] = t('Page ID');
      $form['nid']['#autocomplete_path'] = 'content-nid-list/page/autocomplete';
      break;
    case 'views-exposed-form-story-widget-trending-videos-widget':
    case 'views-exposed-form-special-auto-review-widget-special-auto-review-widget-list':
    case 'views-exposed-form-section-wise-content-ordering-list-dont-miss-content':
    case 'views-exposed-form-section-wise-content-ordering-list-we-may-suggest-widget':
    case 'views-exposed-form-story-widget-most-popular-widget':
    case 'views-exposed-form-story-widget-page-2':
    case 'views-exposed-form-story-widget-top-takes-video-widget':
    case 'views-exposed-form-story-widget-watch-right-now-widget':
    case 'views-exposed-form-home-page-feature-widget-page-2':
    case 'views-exposed-form-photo-carousel-widget-photo-carousel':
    case 'views-exposed-form-photo-carousel-widget-video-carousel':
    case 'itg-widget-issuewidgetlist-filter-form':
    case 'views-exposed-form-category-of-stroy-base-magazin-widget-issue-magazin-widget-list':
    case 'views-exposed-form-supplement-base-magazin-widget-supplement-base-magazin-widget-list':
    case 'views-exposed-form-yearender-top-news-and-top-videos-yearend-left-widget-list':
    case 'views-exposed-form-most-read-widget-most-read-widget-list':
      $form['items_per_page']['#options'] = array(
        '10' => 10,
        '20' => 20,
        '30' => 30
      );
      break;
  }
  if (isset($form['#info']['filter-shs_term_node_tid_depth']) && !empty($form['#info']['filter-shs_term_node_tid_depth'])) {
    $form['#info']['filter-shs_term_node_tid_depth']['label'] = 'Section';
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_keycandidate_validate($form, &$form_state) {

  if ($form_state['values']['state_value'][0] == '0') {
    form_set_error('state_value', 'State is required');
  }
  if (empty($form_state['values']['state_value'])) {
    form_set_error('state_value', 'State is required');
  }
  if ($form_state['values']['cat_value'] == 'All') {
    form_set_error('cat_value', 'section is required');
  }
}

/**
 * {@inheritdoc}
 */
function custom_section_wise_validate($form, &$form_state) {
  if ($form_state['values']['category_tid'] == 'All' && isset($_GET['category_tid'])) {
    form_set_error('category_tid', 'Category is required');
  }
}

/**
 * Function proivides autocomplete URL to widgets.
 * 
 * @param string $type
 * @param boolean $isCondition
 * @param string $custom_type
 * @return string
 */
function autocomplete_for_widgets($type, $is_condition = FALSE, $custom_type = 'breaking_news') {
  $autocomplete = array();
  if (isset($type) && $type != 'All') {
    $autocomplete['title'] = "content-title-list/$type/autocomplete";
    $autocomplete['nid'] = "content-nid-list/$type/autocomplete";
  }
  else {
// Handle case for big story
    if (!$is_condition) {
      $autocomplete['title'] = "node-list-title/autocomplete";
      $autocomplete['nid'] = "node-list-nid/autocomplete";
    }
    else {
      $autocomplete['title'] = "content-title-list/$custom_type/autocomplete";
      $autocomplete['nid'] = "content-nid-list/$custom_type/autocomplete";
    }
  }
  return $autocomplete;
}

/**
 * Data to yearend widget.
 * 
 * @param string $type
 * @param boolean $isCondition
 * @param string $custom_type
 * @return string
 */
function autocomplete_for_year_end_widgets() {
  $title = arg(4);
  $content_type = arg(2);
  $flag = arg(1);
  if (strlen(trim($title)) > 0) {
    $options = array();
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->leftJoin('taxonomy_index', 'tti', 'tti.nid=n.nid');
    $query->fields('n', array('title', 'nid'));
    $query->condition('tid', variable_get('year_end_for_widget'));
    if ($flag == 'title') {
      $query->condition('n. title', '%' . $title . '%', 'LIKE');
    }
    elseif ($flag == 'nid') {
      $query->condition('n. nid', '%' . $title . '%', 'LIKE');
    }
    $query->condition('n.type', $content_type);
    $query->condition('n.status', 1);
    $query->range(0, 20);
    $result = $query->execute();

    if ($flag == 'title') {
      while ($record = $result->fetchAssoc()) {
        $options[$record['title']] = $record['title'];
      }
    }
    elseif ($flag == 'nid') {
      while ($record = $result->fetchAssoc()) {
        $options[$record['nid']] = $record['nid'];
      }
    }

    drupal_json_output($options);
  }
}

/**
 * Implements hook_views_api().
 *
 * This tells drupal that there is Views integration file named
 * itg_social_media.views.inc.
 *
 * {@inheritdoc}
 */
function itg_widget_views_api() {
  return array(
      'api' => 3,
      'path' => drupal_get_path('module', 'itg_widget') . '/includes/views',
  );
}

/**
 * Implementation of hook_views_query_alter
 * {@inheritdoc}
 */
function itg_widget_views_query_alter(&$view, &$query) {

  global $user;
//  if($view->name = 'programme_content' && $view->current_display == 'block') {
//    //pr($query->where[1]['conditions']);
//  }
  if ($view->name == 'section_wise_draggable_content_order' && $view->current_display == 'big_story_format' && ($_GET['type'] == 'story' || $_GET['type'] == 'photogallery' || $_GET['type'] == 'videogallery')) {

    foreach ($query->table_queue as $queue => $queue_value) {
      if ($queue == 'field_data_field_type') {
        unset($query->table_queue['field_data_field_type']);
      }
    }

    foreach ($query->tables['node'] as $queue2 => $queue_value2) {
      if ($queue2 == 'field_data_field_type') {
        unset($query->tables['node']['field_data_field_type']);
      }
    }

    foreach ($query->where[1]['conditions'] as $conditions_key => $conditions) {
      if ($conditions['field'] == 'field_data_field_type.field_type_value') {
        unset($query->where[1]['conditions'][$conditions_key]);
      }
    }
  }
  if (($view->name == 'programmes' || $view->name == 'live_tv_programs') && ($view->current_display == 'page' || $view->current_display == 'rhs_programmes')) {
    $program_cat_value = variable_get('program_category_id_for_programmes');
    if (strlen($program_cat_value) <= 0) {
// Link should display only adminstrator.
      if (in_array('administrator', $user->roles)) {
        $link = l(t("click here"), 'admin/settings/custom-variables');
      }
      drupal_set_message(t("Program category setting not found :link", array(":link" => $link)), "error");
    }
    $program_where_condition = array(
        'field' => 'taxonomy_term_hierarchy.parent',
        'value' => $program_cat_value,
        'operator' => '=',
    );
    array_push($query->where[1]['conditions'], $program_where_condition);
  }

  if ($view->name == 'programmes' && ($view->current_display == 'page' || $view->current_display == 'rhs_programmes')) {
    $join = new views_join();
    $join->table = 'itg_category_manager';
    $join->field = 'tid';
    $join->left_table = 'taxonomy_term_data';
    $join->left_field = 'tid';
    $join->type = 'LEFT';
    //add the join the the view query
    $view->query->add_relationship('itg_category_manager', $join, 'taxonomy_term_data');
    $view->query->add_field('itg_category_manager', 'status');
    $query->add_where(0, 'itg_category_manager.status', '1', '=');
  }

  if ($view->name == 'anchor_option_view') {
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
  }

  if ($view->name == 'so_sorry_politoons' && $view->current_display = 'so_sorry_politoons') {
    foreach ($query->where[1]['conditions'] as $key => $condtion) {
      if ($condtion['field'] == 'taxonomy_term_data_itg_category_manager__taxonomy_term_hierarchy.parent') {
        $query->where[1]['conditions'][$key]['value'] = variable_get('so_sorry_category_id_for_widget');
      }
    }
  }

  if ($view->name == 'anchor_landing_page') {
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
  }

  if (($view->name == 'widget_anchors_listing' && $view->current_display == 'anchors_listing_page')) {
    $anchor_tid = variable_get('reporter_tid');
    foreach ($query->where[1]['conditions'] as $keys => $conditions) {
      if (is_string($conditions['field']) && $conditions['field'] == 'field_data_field_celebrity_pro_occupation.field_celebrity_pro_occupation_tid') {
        $query->where[1]['conditions'][$keys]['value'] = $anchor_tid;
      }
    }
  }

  if (($view->name == 'widget_anchors_listing' && $view->current_display == 'anchors_listing_widget')) {
    $anchor_tid = variable_get('anchor_id_for_widget');
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
    if (strlen($anchor_tid) <= 0) {
// Link should display only adminstrator.
      if (in_array('administrator', $user->roles)) {
        $link = l(t("click here"), 'admin/settings/custom-variables');
      }
      drupal_set_message(t("Anchor setting not found :link", array(":link" => $link)), "error");
    }
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_videos') {
    foreach ($query->where[1]['conditions'] as $keys => $conditions) {
      if (is_string($conditions['field']) && $conditions['field'] == 'taxonomy_index.tid') {
        $query->where[1]['conditions'][$keys]['value'] = variable_get('so_sorry_category_id_for_widget');
      }
    }
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_videos_widget') {
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_feature') {
    foreach ($query->where[1]['conditions'] as $keys => $condtions) {
      if ($condtions['field'] == 'taxonomy_index.tid') {
        $query->where[1]['conditions'][$keys]['value'] = variable_get('so_sorry_category_id_for_widget');
      }
    }
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_page') {
    // Handling the query if other videos are clicked but those are not feature.
    // But they are in itg_widget_order table as well as widget value is equal to so_sorry_widget
    $arg = arg();
    if (isset($arg[1])) {
      unset($query->where[1]['conditions'][1]);
    }
    foreach ($query->where[1]['conditions'] as $keys => $condtions) {
      if ($condtions['field'] == 'taxonomy_index.tid') {
        $query->where[1]['conditions'][$keys]['value'] = variable_get('so_sorry_category_id_for_widget');
      }
    }
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'the_remix') {
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'most_watched') {
    $arg = arg();
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');

    if (empty($arg[1])) {
      // Logic to skip or add feature video in most viewed list.
      $count_feature = count_sosorry_feature();
      if ($count_feature == 0) {
        $recent_created_nid_for_sorry = get_recent_created_node_for_sosorry();
        $not_in_array_condition = array(
            'field' => 'node.nid',
            'value' => $recent_created_nid_for_sorry,
            'operator' => '!=',
        );
        $query->where[1]['conditions'][] = $not_in_array_condition;
      }
      else {
        $feature_value = get_feature_nid_in_sosorry();
        $not_in_array_condition = array(
            'field' => 'node.nid',
            'value' => $feature_value,
            'operator' => '!=',
        );
        $query->where[1]['conditions'][] = $not_in_array_condition;
      }
    }
  }
  if ($view->name == 'so_sorry' && $view->current_display == 'you_will_love_these') {
    $query->where[1]['conditions'][1]['value'] = variable_get('so_sorry_category_id_for_widget');
    // Skip all nodes which are in most viewed.
    // Not need to handle feature video because its has been already altered.
    // This code must be below the most viewed query alter.
    // Result of most viewed page allways needs to skiped.
    $result = views_get_view_result('so_sorry', 'most_watched');
    //array_push($result, $std_obj);
    foreach ($result as $data) {
      if (isset($data->nid)) {
        $not_in_array_condition = array(
            'field' => 'node.nid',
            'value' => $data->nid,
            'operator' => '!=',
        );
      }
      $query->where[1]['conditions'][] = $not_in_array_condition;
    }

    // handle case if fearute is marked in.
    $feature_value = get_feature_nid_in_sosorry();
    if (!empty($feature_value)) {
      $not_in_array_condition = array(
          'field' => 'node.nid',
          'value' => $feature_value,
          'operator' => '!=',
      );
      $query->where[1]['conditions'][] = $not_in_array_condition;
    }
  }

  if ($view->name == 'yearender_top_news_and_top_videos' && $view->current_display == 'yearend_left_widget_contents') {
    if (!empty($query->where[1]['conditions'])) {
      foreach ($query->where[1]['conditions'] as $key => $condition) {
        if ($query->where[1]['conditions'][$key]['field'] == 'taxonomy_index.tid') {
          $query->where[1]['conditions'][$key]['value'] = variable_get('year_end_for_widget');
        }
      }
    }
  }
  if ($view->name == 'key_candidate' && $view->current_display == 'special_key_candidate_widget_contents') {
    if (!empty($_GET['nid']) && empty($_GET['title'])) {

      $query->where[1]['conditions'][2]['value'] = variable_get('tid_politician');
    } if (empty($_GET['nid']) && !empty($_GET['title'])) {

      $query->where[1]['conditions'][2]['value'] = variable_get('tid_politician');
    }
    elseif (!empty($_GET['nid']) && !empty($_GET['title'])) {
      $query->where[1]['conditions'][3]['value'] = variable_get('tid_politician');
    }
    elseif (empty($_GET['nid']) && empty($_GET['title'])) {
      $query->where[1]['conditions'][1]['value'] = variable_get('tid_politician');
    }
  }
  if ($view->name == 'key_candidate' && $view->current_display == 'special_key_candidate_widget_list') {
    if ($_GET['state'] == 0) {
      if ($query->where[1]['conditions'][3]['field'] == 'itg_widget_order.state') {
        unset($query->where[1]['conditions'][3]);
      }
    }
  }

  if ($view->name == 'yearender' && $view->current_display == 'block_2') {
    $query->where[1]['conditions'][3]['value'] = variable_get('year_end_for_widget');
  }
  if ($view->name == 'yearender' && $view->current_display == 'block_1') {
    $query->where[1]['conditions'][3]['value'] = variable_get('year_end_for_widget');
  }


// Start alter for tech
  if ($view->name == 'tech' && ($view->current_display == 'block_1' || $view->current_display == 'block_5' || $view->current_display == 'block_2' || $view->current_display == 'block_8' || $view->current_display == 'movie_latest')) {
    global $theme;

    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }

      $query->where[1]['conditions'][3]['value'] = $section;
    }
    if ($view->current_display == 'block_5') {
      drupal_add_js('
            jQuery(".flexslider").flexslider({
            animation: "slide",
            prevText: "",
            nextText: "",
          
            });', array('type' => 'inline', 'scope' => 'footer', 'weight' => 15)
      );
    }
  }
  if ($view->name == 'budget' && ($view->current_display == 'budget_election_latest' || $view->current_display == 'budget_top_news' )) {
    global $theme;

    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }

      $query->where[1]['conditions'][3]['value'] = $section;
    }
  }
  //  condition for election most popular
  if ($view->name == 'most_popular' && ($view->current_display == 'elections_most_popular' )) {
    global $theme;

    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }

      $query->where[1]['conditions'][3]['value'] = $section;
    }
  }
  if ($view->name == 'most_popular' && ($view->current_display == 'key_candidate' )) {
    global $theme;

    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }

      $query->where[1]['conditions'][2]['value'] = $section;
    }
  }


  if ($view->name == 'special_entertainment' && ($view->current_display == 'oscar_videos' || $view->current_display == 'oscar_photos')) {
    global $theme;
    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }

      if (empty($section)) {
        $section = $_GET['section_name'];
      }
      $query->where[1]['conditions'][3]['value'] = $section;
    }
  }
  if ($view->name == 'special_entertainment' && ($view->current_display == 'entertainment_oscar_slider')) {
    global $theme;
    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }

      $query->where[1]['conditions'][2]['value'] = $section;
    }
  }

  if ($view->name == 'sport_ipl' && ($view->current_display == 'ipl_video')) {
    global $theme;
    if ($theme != 'seven') {
      if ($theme == FRONT_THEME_NAME) {
        $section = arg(2);
      }
      else {
        $section = $_GET['section'];
      }
      if (empty($section)) {
        $section = $_GET['section_name'];
      }
      // p($section);
      $query->where[1]['conditions'][3]['value'] = $section;
    }
  }


  if ($view->name == 'sport_ipl' && $view->current_display == 'points_tally') {


    $query->where[1]['conditions'][1]['value'] = variable_get('ipl_points_tally_for_widget');
  }
  if ($view->name == 'sport_ipl' && $view->current_display == 'top_performers') {


    $query->where[1]['conditions'][1]['value'] = variable_get('ipl_top_performer_for_widget');
  }

  if ($view->name == 'section_wise_content_ordering_list' && $view->current_display == 'page') {
    $content_value_for_query = "All";
    if (isset($_GET['type'])) {
      $content_value_for_query = $_GET['type'];
      if ($content_value_for_query == 'All') {
        $query->where[1]['conditions'][4]['field'] = 'itg_widget_order.content_type';
        $query->where[1]['conditions'][4]['operator'] = 'LIKE';
      }
    }
    $query->where[1]['conditions'][4]['value'] = $content_value_for_query;
  }
  if ($view->name == 'category_wise_content_list' && ($view->current_display == 'section_wise_content_listing' || $view->current_display == 'grid_view')) {
    $term_id = arg(2);
    if ($term_id) {
      foreach ($query->where[1]['conditions'] as $key => $condition) {
        if ($condition['field'] == 'itg_widget_order.cat_id') {
          $query->where[1]['conditions'][$key]['value'] = $term_id;
        }
      }
    }
  }
  // Adding relationship.
  if (_itg_analytics_relationship_views($view->name, $view->current_display)) {
    $join = new views_join();
    $join->table = 'itg_node_analytics_count_data';
    $join->field = 'nid';
    $join->left_table = 'node';
    $join->left_field = 'nid';
    $join->type = 'LEFT';
    //add the join the the view query
    $view->query->add_relationship('itg_node_analytics_count_data', $join, 'node');
    $view->query->add_field('itg_node_analytics_count_data', 'count');
    $order_by = array();
    $order_by['field'] = 'count';
    $order_by['direction'] = 'DESC';
    array_unshift($query->orderby, $order_by);
  }
}

/**
 * Function which returns flag for add relationship with analytics table.
 * @param string $view_name
 * @param string $view_current_display
 * @return boolean
 */
function _itg_analytics_relationship_views($view_name, $view_current_display) {
  $flag = FALSE;
  if (!empty($view_name) && !empty($view_current_display)) {
    if ($view_name == "story_widget" && ($view_current_display == "most_popular" || $view_current_display == "trending_videos" || $view_current_display == "watch_right_now" || $view_current_display == "top_takes_video")) {
      $flag = TRUE;
    }
    if ($view_name == "so_sorry" && $view_current_display == "most_watched ") {
      $flag = TRUE;
    }
    if ($view_name == "most_read_widget" && $view_current_display == "most_read_widget_contents") {
      $flag = TRUE;
    }
  }
  return $flag;
}

/**
 * Function for returning node queue id by node queue machine name.
 *
 * @param string $form
 */
function get_nodequeue_load_queue_by_name($qname) {
  try {
    $node_queue_object = nodequeue_load_queue_by_name($qname);
    return isset($node_queue_object->qid) ? $node_queue_object->qid : NULL;
  } catch (Exception $e) {
    watchdog('Node Queue Error/Warning', 'There is some error while accessing node queue');
  }
}

/**
 * Callback function for anchor name autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_anchor_autocomplete_name($string) {
  $anchor_id = variable_get('anchor_id_for_widget');
  $itg_query = db_select('node', 'n');
  $itg_query->leftJoin('field_data_field_celebrity_pro_occupation', 'occuptoin', 'occuptoin.entity_id=n.nid');
  $itg_query->condition('occuptoin.field_celebrity_pro_occupation_tid', $anchor_id);
  $itg_query->condition('n.title', '%' . $string . '%', 'LIKE')
          ->fields('n', array('title'));
  $itg_result = $itg_query->execute();
  $result = array();
  foreach ($itg_result as $value) {
    $result[$value->title] = $value->title;
  }
  return drupal_json_output($result);
}

/**
 * Callback function for anchor name autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_anchor_autocomplete_id($string) {
  $anchor_id = variable_get('anchor_id_for_widget');
  $itg_query = db_select('node', 'n');
  $itg_query->leftJoin('field_data_field_celebrity_pro_occupation', 'occuptoin', 'occuptoin.entity_id=n.nid');
  $itg_query->condition('occuptoin.field_celebrity_pro_occupation_tid', $anchor_id);
  $itg_query->condition('n.nid', '%' . $string . '%', 'LIKE')
          ->fields('n', array('nid'));
  $itg_result = $itg_query->execute();
  $result = array();
  foreach ($itg_result as $value) {
    $result[$value->nid] = $value->nid;
  }
  return drupal_json_output($result);
}

/**
 * Hook is used to add unique class to only widgets view wrapper.
 * 
 * Implementation of hook_preprocess_views_view
 * {@inheritdoc}
 */
function itg_widget_preprocess_views_view(&$vars) {
  $view_name = $vars['view']->name;
  $widget_views = array(
      'widget_anchors_listing',
      'home_page_feature_widget',
      'story_widget',
      'section_wise_content_ordering_list',
      'section_wise_draggable_content_order',
      'photo_carousel_widget',
      'so_sorry',
      'special_auto_review_widget',
      'special_how_i_made_it',
      'yearender_top_news_and_top_videos',
      'most_read_widget',
      'issue_base_magazin_widget',
      'key_candidate',
  );
  if (in_array($view_name, $widget_views)) {
    $vars['classes_array'][] = 'widgets-view';
    drupal_add_css('td.tabledrag-hide  {display: inline-block !important;}', 'inline');
    drupal_add_css('th.tabledrag-hide  {display: inline-block !important;}', 'inline');
//drupal_add_css('.tabledrag-handle  {display: inline-block !important;}', 'inline');
  }
}

/**
 * Function for theme suggestion.
 * 
 * {@inheritdoc}
 */
function itg_widget_preprocess_node(&$vars) {
  if ($vars['type'] == 'reporter') {
    // Get all terms of vocabulary occupation.
    $itg_occupation = taxonomy_vocabulary_machine_name_load('itg_occupation');
    $itg_occupation_tree = taxonomy_get_tree($itg_occupation->vid);
    foreach ($itg_occupation_tree as $term) {
      $occupation[] = $term->name;
    }

    if (in_array(strtolower('Anchor'), $occupation)) {
      drupal_add_js("jQuery(document).ready(function(){
              jQuery('.read-more , .full-content').click(function(){
              jQuery('.less-content').toggle();
              jQuery('.full-content').toggle();
              });
              })", 'inline'
      );
      $vars['theme_hook_suggestions'][] = 'node__reporter__anchor';
    }
  }
}

/**
 * Get data from nodequeue, if data doesn't exist in draggable view
 * 
 * @param string $nodequeue_name
 * @return array
 */
function itg_widget_nodes_from_nodequeue($nodequeue_name, $is_dont_expire = FALSE, $min_range, $max_range) {
  $today = date('Y-m-d 00:00:00');
  $nodequeue_id = get_nodequeue_load_queue_by_name($nodequeue_name);
  $nq_query = db_select('nodequeue_nodes', 'nq');
  $nq_query->leftJoin('node', 'n', 'n.nid=nq.nid');
  //join  for field value
  $nq_query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  $nq_query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
  $nq_query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $nq_query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $nq_query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
  $nq_query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
  $nq_query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $nq_query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
  $nq_query->fields('eli_file', array('uri'));
  $nq_query->fields('li_file', array('uri'));
  $nq_query->fields('mi_file', array('uri'));
  $nq_query->fields('si_file', array('uri'));
  $nq_query->fields('esi_file', array('uri'));
  $nq_query->fields('kt', array('field_story_kicker_text_value'));
  $nq_query->fields('vd', array('field_video_duration_value'));
  $nq_query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
  //end
  if (!$is_dont_expire) {
    $nq_query->leftJoin('field_data_field_story_expiry_date', 'fsed', 'fsed.entity_id=n.nid');
    $nq_query->condition('fsed.field_story_expiry_date_value', $today, '>=');
  }
  $nq_query->condition('nq.qid', $nodequeue_id);
  $nq_query->condition('n.status', '1');
  $nq_query->addField('nq', 'nid', 'entity_id');
  $nq_query->orderBy('n.nid', 'DESC');
  $nq_query->range($min_range, $max_range);
  return $nq_query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * Implements function for anchor landing menu
 */
function itg_widget_anchor_landing_menu($nid) {
// Query to get category in which anchor is associated.
  $cat_query = db_select('field_data_field_video_anchor', 'video_anchor');
  $cat_query->leftJoin('field_data_field_story_category', 'cat', 'video_anchor.entity_id = cat.entity_id');
  $cat_query->leftJoin('taxonomy_term_data', 'ttd', 'ttd.tid=cat.field_story_category_tid');
  $cat_query->fields('cat', array('field_story_category_tid'));
  $cat_query->distinct('cat.field_story_category_tid');
  $cat_query->fields('ttd', array('name'));
  $cat_query->condition('video_anchor.field_video_anchor_target_id', $nid, '=');
  $cat_query->condition('cat.bundle', 'videogallery', '=');
  $categories_of_anchor = $cat_query->execute();
  foreach ($categories_of_anchor as $cate) {
    $result[$cate->field_story_category_tid] = $cate->name;
  }
  return $result;
}

/**
 * {@inheritdoc}
 */
function itg_widget_node_view($node, $view_mode, $langcode) {
  if ($node->type == 'reporter' && drupal_is_front_page() == FALSE) {
    $cat_array = itg_widget_anchor_landing_menu(arg(1));
    $first_key = key($cat_array);
// Category view on landing page
    drupal_add_js("jQuery('.anchor-detail-menu .tab-buttons span').click(function(){
var section_id = jQuery(this).attr('value');
jQuery('.anchor-detail-menu .tab-buttons span a').removeClass('active');
jQuery('#edit-field-story-category-tid').val(section_id); 
jQuery('#edit-field-story-category-tid').trigger('change');
jQuery(this).find('a').addClass('active');
});", array('type' => 'inline', 'scope' => 'footer'));
    drupal_add_js("jQuery(document).ready(function(){
jQuery('#edit-field-story-category-tid').val(" . $first_key . "); 
jQuery('#edit-field-story-category-tid').trigger('change');
jQuery('.anchor-detail-menu .tab-buttons span').each(function() {
if(jQuery(this).attr('value') == " . $first_key . "){
jQuery(this).addClass('active');
}
});
});", array('type' => 'inline', 'scope' => 'footer'));
  }
}

/**
 * Comman function for all the widgets for getting the widgets nodeids
 * 
 * @param string $view_name
 * @param string $page
 * @param string $expire_date
 * @param int $range_min
 * @param int $range_max
 * @return array
 */
function draggable_views_nodes_for_widgets($view_name, $page, $expire_date, $range_min = 0, $range_max) {
  if (!empty($view_name) && !empty($page) && !empty($expire_date) && !empty($range_max) && !empty($range_max)) {
    $query = db_select('draggableviews_structure', 'dv_s');
    $query->leftJoin('node', 'n', 'n.nid=dv_s.entity_id');
    if ($expire_date != "NOT") {
      $query->leftJoin('field_data_field_story_expiry_date', 'fsed', 'fsed.entity_id=n.nid');
      $query->fields('fsed', array('field_story_expiry_date_value'));
    }
    //join  for field value
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
    $query->leftJoin('field_data_body', 'dbody', 'dbody.entity_id=n.nid');
    $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->fields('eli_file', array('uri'));
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->fields('si_file', array('uri'));
    $query->fields('esi_file', array('uri'));
    $query->fields('kt', array('field_story_kicker_text_value'));
    $query->fields('vd', array('field_video_duration_value'));
    $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
    //end
    $query->fields('dv_s', array('entity_id'));
    $query->condition('dv_s.view_name', $view_name);
    $query->condition('dv_s.view_display', $page);
    $query->condition('n.status', '1');
    if ($expire_date != "NOT") {
      $query->condition('fsed.field_story_expiry_date_value', $expire_date, '>=');
    }
    $query->orderBy('dv_s.weight', 'ASC');
    $query->groupBy('dv_s.entity_id');
    $query->range($range_min, $range_max);

    return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
}

/**
 * Function returns data for cutom tables widgets.
 * 
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_for_widgets($widget_name, $range_max, $range_min = 0, $order_by = 'DESC') {

  $valid_content_type = _get_content_type_for_widget($widget_name);

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');

  if ($widget_name == 'home_page_feature_widget') {
    $query->leftJoin('field_data_field_story_medium_image', 'mi', 'mi.entity_id=n.nid');
    $query->leftJoin('field_data_field_story_large_image', 'li', 'li.entity_id=n.nid');
  }
  if ($widget_name == 'dont_miss_content_widget') {
    $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  }

  if ($widget_name == 'trending_videos_widget' || $widget_name == 'watch_right_now_widget' || $widget_name == 'we_may_suggest_widget' || $widget_name == 'top_takes_video_widget') {
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
  }

  if ($widget_name == 'featured_photo_carousel' || $widget_name == 'video_carousel_list_widget') {
    $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  }
  //we_may_suggest_widget
  //join  for field value
  //$query->leftJoin('field_data_field_story_extra_large_image' , 'eli' , 'eli.entity_id=n.nid');
  //$query->leftJoin('field_data_field_story_small_image' , 'si' , 'si.entity_id=n.nid');
  //$query->leftJoin('field_data_field_story_extra_small_image' , 'esi' , 'esi.entity_id=n.nid');

  $query->leftJoin('field_data_field_story_kicker_text', 'kt', 'kt.entity_id=n.nid');
  //$query->leftJoin('field_data_body' , 'dbody' , 'dbody.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');

  //$query->leftJoin('file_managed' , 'eli_file' , 'eli_file.fid=eli.field_story_extra_large_image_fid');  
  //$query->leftJoin('file_managed' , 'si_file' , 'si_file.fid=si.field_story_small_image_fid');
  //$query->leftJoin('file_managed' , 'esi_file' , 'esi_file.fid=esi.field_story_extra_small_image_fid');

  if ($widget_name == 'home_page_feature_widget') {
    $query->leftJoin('file_managed', 'li_file', 'li_file.fid=li.field_story_large_image_fid');
    $query->leftJoin('file_managed', 'mi_file', 'mi_file.fid=mi.field_story_medium_image_fid');
    $query->fields('li_file', array('uri'));
    $query->fields('mi_file', array('uri'));
    $query->addField('li', 'field_story_large_image_alt');
    $query->addField('li', 'field_story_large_image_title');
    $query->addField('mi', 'field_story_medium_image_alt');
    $query->addField('mi', 'field_story_medium_image_title');
    $query->addExpression("li_file.uri", 'li_file_uri');
    $query->addExpression("mi_file.uri", 'mi_file_uri');
  }

  if ($widget_name == 'dont_miss_content_widget') {
    $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
    $query->fields('si_file', array('uri'));
    $query->addExpression("si_file.uri", 'si_file_uri');
    $query->fields('si', array('field_story_small_image_alt', 'field_story_small_image_title'));
  }

  if ($widget_name == 'trending_videos_widget' || $widget_name == 'watch_right_now_widget' || $widget_name == 'we_may_suggest_widget' || $widget_name == 'top_takes_video_widget') {
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->fields('esi_file', array('uri'));
    $query->addExpression("esi_file.uri", 'esi_file_uri');
    $query->fields('esi', array('field_story_extra_small_image_alt', 'field_story_extra_small_image_title'));
  }

  if ($widget_name == 'featured_photo_carousel' || $widget_name == 'video_carousel_list_widget') {
    $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
    $query->fields('eli_file', array('uri'));
     $query->fields('eli', array('field_story_extra_large_image_alt', 'field_story_extra_large_image_title'));
    $query->addExpression("eli_file.uri", 'eli_file_uri');
  }

  //$query->fields('eli_file' , array('uri'));  
  //$query->fields('si_file' , array('uri'));
  //$query->fields('esi_file' , array('uri'));

  $query->fields('kt', array('field_story_kicker_text_value'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));

  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('n.type', $valid_content_type)
          ->orderBy('iwo.weight', $order_by)
          ->orderBy('n.nid', 'DESC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * Function returns data for cutom tables widgets.
 * 
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_for_widgets_by_category($widget_name, $category, $range_max, $range_min = 0, $order_by = 'ASC') {
  $valid_content_type = _get_content_type_for_widget($widget_name);
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('iwo.cat_id', $category)
          ->condition('n.type', $valid_content_type)
          ->orderBy('iwo.weight', $order_by)
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

  $weight = 0;
  foreach ($result as $data) {
    $weight += $data['weight'];
  }
  if ($weight > 0) {
    return $result;
  }
  else {
// Query for renctaly careated node if weight is not saved
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
    $query->condition('iwo.widget', $widget_name)
            ->condition('n.status', 1)
            ->condition('iwo.cat_id', $category)
            ->condition('n.type', $valid_content_type)
            ->orderBy('n.nid', 'DESC')
            ->range($range_min, $range_max)
            ->fields('iwo', array('nid', 'extra', 'weight'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
  }
}

/**
 * Function returns data for cutom tables widgets.
 * 
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_for_widgets_special($widget_name, $cat_id, $range_max, $range_min = 0, $order_by = 'ASC') {
  $valid_content_type = _get_content_type_for_widget($widget_name);

  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->Join('taxonomy_index', 'tx', 'n.nid=tx.nid');

  if ($widget_name == 'special_how_made_it_content') {
    $query->leftJoin('field_data_field_story_extra_small_image', 'esi', 'esi.entity_id=n.nid');
    $query->leftJoin('file_managed', 'esi_file', 'esi_file.fid=esi.field_story_extra_small_image_fid');
    $query->fields('esi_file', array('uri'));
    $query->fields('esi', array('field_story_extra_small_image_alt', 'field_story_extra_small_image_title'));
  }

  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));

  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('n.type', $valid_content_type)
          ->condition('tx.tid', $cat_id)
          ->orderBy('iwo.weight', 'ASC')
          ->orderBy('n.nid', 'DESC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * Function returns data for cutom tables widgets.
 *   }

 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_for_yearend_widgets($widget_name, $content_type, $range_max, $range_min = 0) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_extra_large_image', 'eli', 'eli.entity_id=n.nid');
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $query->leftJoin('file_managed', 'eli_file', 'eli_file.fid=eli.field_story_extra_large_image_fid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->fields('si', array('field_story_small_image_alt', 'field_story_small_image_title'));
  $query->fields('eli', array('field_story_extra_large_image_alt', 'field_story_extra_large_image_title'));

  $query->fields('eli_file', array('uri'));
  $query->fields('si_file', array('uri'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
  //end
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('iwo.content_type', $content_type)
          ->orderBy('iwo.weight', 'ASC')
          ->range($range_min, $range_max)
          ->orderBy('n.nid', 'ASC')
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * Function returns data for cutom tables widgets.
 * 
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_for_spacila_auto_widgets($widget_name, $cat_id, $range_max, $range_min = 0) {
  $valid_content_type = _get_content_type_for_widget($widget_name);

  $query = db_select('itg_widget_order', 'iwo'); //
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->Join('taxonomy_index', 'tx', 'n.nid=tx.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_extra_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_extra_small_image_fid');
  $query->fields('si', array('field_story_extra_small_image_alt', 'field_story_extra_small_image_title'));

  $query->fields('si_file', array('uri'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
  //end
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('tx.tid', $cat_id)
          ->condition('n.type', $valid_content_type)
          ->orderBy('iwo.weight', 'ASC')
          ->orderBy('n.nid', 'DESC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * Function returns data for cutom tables widgets.
 * 
 * @param string $widget_name
 * @param int $range_max
 * @param int $range_min
 * @return array
 */
function get_view_nodes_form_custom_table_review_widgets($widget_name, $cat_id, $range_max, $range_min = 0) {
  $valid_content_type = _get_content_type_for_widget($widget_name);

  $query = db_select('itg_widget_order', 'iwo'); //
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->Join('taxonomy_index', 'tx', 'n.nid=tx.nid');
  //join  for field value
  $query->leftJoin('field_data_field_story_small_image', 'si', 'si.entity_id=n.nid');
  $query->leftJoin('field_data_field_video_duration', 'vd', 'vd.entity_id=n.nid');
  $query->leftJoin('file_managed', 'si_file', 'si_file.fid=si.field_story_small_image_fid');
  $query->fields('si', array('field_story_small_image_alt', 'field_story_small_image_title'));
  $query->fields('si_file', array('uri'));
  $query->fields('vd', array('field_video_duration_value'));
  $query->fields('n', array('nid', 'title', 'created', 'type', 'uid'));
  //end
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('tx.tid', $cat_id)
          ->condition('n.type', $valid_content_type)
          ->orderBy('iwo.weight', 'ASC')
          ->orderBy('n.nid', 'DESC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * {@inheritdoc}
 */
function itg_widget_block_view_alter(&$data, $block) {

  $item = menu_get_item();
  $flag_occupation = $story_category = $occupation = array();
  $ipl_category = array();
  $arg = arg();
  $user_link = (!empty($arg[1])) ? drupal_get_path_alias('node/' . $arg[1]) : "";

  $page_argument = $item['page_arguments'];
  if (!empty($page_argument)) {
    $occupation = isset($page_argument[0]->field_celebrity_pro_occupation['und']) ? $page_argument[0]->field_celebrity_pro_occupation['und'] : array();
    $story_category = isset($page_argument[0]->field_story_category['und']) ? $page_argument[0]->field_story_category['und'] : array();
    if (!empty($occupation)) {
      foreach ($occupation as $occupation_taxonomy) {
        $flag_occupation[] = $occupation_taxonomy['taxonomy_term']->name;
      }
    }
    if (!empty($story_category)) {
      foreach ($story_category as $category) {
        $ipl_category[] = $category['tid'];
      }
    }
  }



  if ($block->delta == 'programmes-rhs_programmes') {
    $arraynid = array();
    $arraynid = explode(',', variable_get('ipl_rhs_nids'));
    if (in_array($arg[1], $arraynid) || $user_link == 'ipl-teams' || $user_link == 'ipl-stadiums' || $arg[0] == 'photo-list' || $arg[0] == 'video-list' || in_array(variable_get('ipl_for_widget'), $ipl_category)) {
      $data['content'] = array();
    }
    else {
      if ($arg[0] == 'livetv' || $arg[0] == 'anchors-list' || (in_array('Anchor', $flag_occupation)) || (isset($page_argument[0]->type) && $page_argument[0]->type == 'videogallery' && empty($_GET['sid']))) {
        return TRUE;
      }
      else {
        $data['content'] = array();
      }
    }
  }

  if ($block->delta == 'sport_ipl-top_performers' || $block->delta == 'sport_ipl-points_tally' || $block->delta == 'ipl_tweets' || $block->delta == 'live_score') {
    $arraynid = array();
    $arraynid = explode(',', variable_get('ipl_rhs_nids'));

    if (in_array($arg[1], $arraynid) || $arg[0] == 'photo-list' || $arg[0] == 'video-list' || in_array(variable_get('ipl_for_widget'), $ipl_category)) {
      drupal_add_js('jQuery(document).ready(function() {                  
                        jQuery("body").addClass("section-sport-ipl-bg");

          });', array('type' => 'inline', 'scope' => 'footer'));
      return TRUE;
    }
    else {
      $data['content'] = array();
    }
  }
}

/**
 * Callback function for widget title autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_all_content_title($title) {
  if (strlen(trim($title)) > 0) {
    $options = array();
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->fields('n', array('title'));
    $query->condition('n. title', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
    $query->condition('n.status', 1);
    $query->range(0, 20);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $options[$record['title']] = $record['title'];
    }

    drupal_json_output($options);
  }
}

/**
 * Callback function for widget title autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_so_sorry_content_title($title) {
  if (strlen(trim($title)) > 0) {
    $options = array();
    $so_sorry_cat = variable_get('so_sorry_category_id_for_widget');
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_category', 'cat', 'cat.entity_id=n.nid');
    $query->fields('n', array('title'));
    $query->condition('cat.field_story_category_tid', $so_sorry_cat);
    $query->condition('n. title', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
    $query->condition('n.status', 1);
    $query->range(0, 20);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $options[$record['title']] = $record['title'];
    }

    drupal_json_output($options);
  }
}

/**
 * Callback function for widget title autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_all_content_nid($title) {
  if (strlen(trim($title)) > 0) {
    $options = array();
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'));
    $query->condition('n. nid', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
    $query->condition('n.status', 1);
    $query->range(0, 20);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $options[$record['nid']] = $record['nid'];
    }

    drupal_json_output($options);
  }
}

/**
 * Callback function for widget title autocomplete.
 * 
 * @param string $string keyword for auto suggest.
 * @return json Autocomplete callback for category manager view
 */
function itg_widget_so_sorry_content_nid($title) {
  if (strlen(trim($title)) > 0) {
    $options = array();
    $so_sorry_cat = variable_get('so_sorry_category_id_for_widget');
    $title = strtolower(trim($title));
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_story_category', 'cat', 'cat.entity_id=n.nid');
    $query->fields('n', array('nid'));
    $query->condition('cat.field_story_category_tid', $so_sorry_cat);
    $query->condition('n. nid', '%' . $title . '%', 'LIKE');
    $query->condition('n.type', array('story', 'videogallery', 'photogallery'), 'IN');
    $query->condition('n.status', 1);
    $query->range(0, 20);
    $result = $query->execute();

    while ($record = $result->fetchAssoc()) {
      $options[$record['nid']] = $record['nid'];
    }

    drupal_json_output($options);
  }
}

/*
 * This will return selected poll for widget
 *  @param string $content_type content Type.
 *  @param string $widget_name keyword for auto suggest.
 */

function get_homepage_current_poll_widget($content_type, $widget_name) {
  $ctype = $content_type;
  $cur_date = date('Y-m-d H:i:s');
  $nodes_already = db_select('itg_widget_order', 'iwo');
  $nodes_already->Join('node', 'n', 'iwo.nid=n.nid');
  $nodes_already->leftjoin('field_data_field_"' . $ctype . '"_start_date', 'sd', 'n.nid = sd.entity_id');
  $nodes_already->leftjoin('field_data_field_"' . $ctype . '"_end_date', 'ed', 'n.nid = ed.entity_id');
  $nodes_already->fields('iwo', array('nid'));
  $nodes_already->condition('iwo.content_type', $content_type)
          ->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1);
  $nodes_already->condition('sd.field_"' . $ctype . '"_start_date_value', $cur_date, '<=');
  $nodes_already->condition(db_or()->isNull('ed.field_"' . $ctype . '"_end_date_value')->condition('ed.field_"' . $ctype . '"_end_date_value', $cur_date, '>='));

  $res = $nodes_already->execute()->fetch();
  if (isset($res->nid) && !empty($res->nid)) {
    return $res->nid;
  }
  return;
}

/**
 * This mentod will return a poll widget for against poll nid, used in home page widget 
 * @param type $nid
 */
function itg_poll_home_page_polls_select($nid) {
  if (isset($nid)) {
    $node = node_load($nid);
    $poll_banner_image = '';
    $fieldcollect = array();
    if (isset($node->field_poll_banner) && !empty($node->field_poll_banner)) {
      $poll_banner_image = theme('image_style', array('style_name' => 'home_page_poll_images_style', 'path' => $node->field_poll_banner[$node->language][0]['uri']));
    }
    else {
      $poll_banner_image = '';
    }

    $poll_image_exist_class = '';
    if (isset($node->field_poll_answer['und'])) {
      foreach ($node->field_poll_answer['und'] as $row) {
        $item_id[] = $row['value']; // fieldcollection id
      }
    }
// instant or after complete
    if (!empty($item_id) && isset($item_id)) {
      $fieldcollect = entity_load('field_collection_item', $item_id);
    }
    if (!empty($fieldcollect) && is_array($fieldcollect) && count($fieldcollect) > 0) {
      $fieldcollect_array = array_slice($fieldcollect, 0, 1);
      $temp_ent = array_shift($fieldcollect_array);
      $poll_answer_image = isset($temp_ent->field_poll_answer_image[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_image[LANGUAGE_NONE][0]['fid'] : '';
      if (isset($poll_answer_image) && $poll_answer_image > 0) {
        $poll_image_exist_class = 'poll-option-image';
      }
      else {
        $poll_image_exist_class = '';
      }
    }
    $polls_info['poll_banner_image'] = $poll_banner_image;
    $polls_info['nid'] = isset($nid) ? $nid : "";
    $polls_info['title'] = isset($node->title) ? t(substr(check_plain($node->title), 0, 65)) . '..' : "";
    $polls_info['updated'] = isset($node->changed) ? t('Updated:') . '&nbsp;' . date('M d Y H:i', $node->changed) : "";
    $polls_info['poll_image_exist_class'] = $poll_image_exist_class;
    return theme('itg_poll_homepage_forms', array('data' => $polls_info));
  }
  else {
    return '<span class="no-result-found">' . t("Content Not Found") . '</span>';
  }
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidget_filter_form($form, $form_state) {
  $options_issue = array();
  $options_issue[''] = 'Select';
  $magazine_id = ($form_state['input']['magazine_title'] != "") ? $form_state['input']['magazine_title'] : $_GET['magazine_id'];
  $result = itg_widget_get_issue_data($magazine_id);


  while ($record = $result->fetchAssoc()) {
    $options_issue[date('Y-m-d', strtotime($record['title']))] = date('d/m/Y', strtotime($record['title']));
  }

  $data_magazine = itg_widget_get_magazine_data();

  $options_magazine = array();
  $options_magazine[''] = 'Select';

  while ($record_magazine = $data_magazine->fetchAssoc()) {

    $options_magazine[$record_magazine['nid']] = t($record_magazine['title']);
  }

  $form['magazine_title'] = array(
      '#title' => t('Magazine'),
      '#type' => 'select',
      '#default_value' => $_GET['magazine_id'],
      '#options' => $options_magazine,
      '#ajax' => array(
          'callback' => 'ajax_dependent_dropdown_issue',
      //'wrapper' => 'view-display-isesue',
      ),
  );
  $form['content_title'] = array(
      '#title' => t('Issue Date'),
      '#type' => 'select',
      '#prefix' => '<div id="view-display-isesue">',
      '#suffix' => '</div>',
      '#default_value' => $_GET['field_story_issue_date_value']['value']['date'],
      '#options' => $options_issue,
  );
  $form['items_per_page'] = array(
      '#title' => t('Items per page'),
      '#type' => 'select',
      '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
      '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60),
  );
  $form['alt_button'] = array(
      '#type' => 'submit',
      '#value' => t('Apply'),
  );
  $form['filters']['buttons']['reset'] = array('#type' => 'submit', '#value' => t('Reset'), '#submit' => array('itg_widget_issuewidget_filter_reset'),);
  return $form;
}

/**
 * This function use for get issue data
 * @return array $result
 */
function ajax_dependent_dropdown_issue(&$form, $form_state) {
  return array(
      '#type' => 'ajax',
      '#commands' => array(
          ajax_command_replace("#view-display-isesue", render($form['content_title'])),
      )
  );
}

function ajax_dependent_dropdown_state(&$form, $form_state) {
  return array(
      '#type' => 'ajax',
      '#commands' => array(
          ajax_command_replace("#view-display-isesue", render($form['state_value'])),
      )
  );
}

/**
 * This function use for get issue data
 * @return array $result
 */
function itg_widget_get_issue_data($magazine_id = NULL) {

  $query = db_select('node', 'n');
  $query->fields('n', array('title'));
  $query->condition('n.type', array('issue'), '=');
  $query->Join('field_data_field_issue_magazine', 'mag', 'mag.entity_id=n.nid');
  $query->condition('mag.field_issue_magazine_target_id', $magazine_id, '=');
  $query->condition('n.status', 1);
  $result = $query->execute();
  return $result;
}

/**
 * This function use for get issue data
 * @return array $result
 */
function itg_widget_get_magazine_data() {

  $query = db_select('node', 'n');
  $query->fields('n', array('title', 'nid'));
  $query->condition('n.type', array('magazine'), '=');

  $query->condition('n.status', 1);
  $result = $query->execute();
  return $result;
}

/**
 * This mentod will go to issue widget filter url
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidget_filter_form_submit($form, $form_state) {

  $query = array('field_story_issue_date_value[value][date]' => $form_state['values']['content_title'], 'items_per_page' => $form_state['values']['items_per_page'], 'magazine_id' => $form_state['values']['magazine_title']);
  drupal_goto('issue-base-magazin-widget', array('query' => $query));
}

/**
 * This mentod will go to issue widget list page after rest
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidget_filter_reset($form, $form_state) {

  drupal_goto('issue-base-magazin-widget');
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidgetlist_filter_form($form, $form_state) {
  $options_issue = array();
  $options_issue[''] = 'Select';
  $magazine_id = ($form_state['input']['magazine_title'] != "") ? $form_state['input']['magazine_title'] : $_GET['magazine_id'];
  $result = itg_widget_get_issue_data($magazine_id);


  while ($record = $result->fetchAssoc()) {
    $options_issue[date('Y-m-d', strtotime($record['title']))] = date('d/m/Y', strtotime($record['title']));
  }

  $data_magazine = itg_widget_get_magazine_data();

  $options_magazine = array();
  $options_magazine[''] = 'Select';

  while ($record_magazine = $data_magazine->fetchAssoc()) {

    $options_magazine[$record_magazine['nid']] = t($record_magazine['title']);
  }

  $form['magazine_title'] = array(
      '#title' => t('Magazine'),
      '#type' => 'select',
      '#default_value' => $_GET['magazine_id'],
      '#options' => $options_magazine,
      '#ajax' => array(
          'callback' => 'ajax_dependent_dropdown_issue',
      //'wrapper' => 'view-display-isesue',
      ),
  );
  $form['content_title'] = array(
      '#title' => t('Issue Date'),
      '#type' => 'select',
      '#prefix' => '<div id="view-display-isesue">',
      '#suffix' => '</div>',
      '#default_value' => $_GET['field_story_issue_date_value']['value']['date'],
      '#options' => $options_issue,
  );
  $form['items_per_page'] = array(
      '#title' => t('Items per page'),
      '#type' => 'select',
      '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
      '#options' => array(10 => 10, 20 => 20, 30 => 30),
  );
  $form['alt_button'] = array(
      '#type' => 'submit',
      '#value' => t('Apply'),
  );
  $form['filters']['buttons']['reset'] = array('#type' => 'submit', '#value' => t('Reset'), '#submit' => array('itg_widget_issuewidgetlist_filter_reset'),);




  return $form;
}

/**
 * This mentod will go to added issue widget list filter url
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidgetlist_filter_form_submit($form, $form_state) {

  $query = array('field_story_issue_date_value[value][date]' => $form_state['values']['content_title'], 'items_per_page' => $form_state['values']['items_per_page'], 'magazine_id' => $form_state['values']['magazine_title']);
  drupal_goto('issue-magazin-widget-list', array('query' => $query));
}

/**
 * This mentod will go to added issue widget list page after rest
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidgetlist_filter_reset($form, $form_state) {
  drupal_goto('issue-magazin-widget-list');
}

/**
 * display block on page
 * @return TRUE or FALSE
 */
function itg_block_display_condition() {
  $arg = arg();
  $is_fron_page = drupal_is_front_page();
  if (($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2]))) {
    $tpl_name = get_template_name_by_section_name($arg[2]);
    if (isset($tpl_name)) {
      return TRUE;
    }
  }
  elseif (!empty($is_fron_page)) {
    return TRUE;
  }

  return FALSE;
}

/**
 * display block on page
 * @return TRUE or FALSE
 */
function get_rhs_block_display_condtion($delta = '') {

  $arg = arg();
  $item = menu_get_item();
  $page_argument = $item['page_arguments'];
  $ipl_category = array();
  $we_may_suggest_display_nodes = variable_get('we_may_suggest_block_condition');
  $we_may_suggest_node_array = explode(",", $we_may_suggest_display_nodes);
  $watch_right_now_display_nodes = variable_get('watch_right_now_block_condition');
  $watch_right_now_node_array = explode(",", $watch_right_now_display_nodes);
  $top_takes_display_nodes = variable_get('top_takes_block_condition');
  $top_takes_node_array = explode(",", $top_takes_display_nodes);
  $story_category = (!empty($page_argument[0]->field_story_category['und'])) ? $page_argument[0]->field_story_category['und'] : "";
  if (!empty($story_category)) {
    foreach ($story_category as $category) {
      $ipl_category[] = $category['tid'];
    }
  }
  $display_block = itg_block_display_condition();
  $user_link = (!empty($arg[1])) ? drupal_get_path_alias('node/' . $arg[1]) : "";
  if ($user_link == 'ipl-venue' || $user_link == 'ipl-schedule' || $user_link == 'ipl-teams' || $user_link == 'ipl-stadiums' || $arg[0] == 'photo-list' || $arg[0] == 'video-list' || in_array(variable_get('ipl_for_widget'), $ipl_category)) {
    
  }
  else {

    switch ($delta) {
      
      case 'watch_right_now_videos_widget':
        
       if($arg[0] =='gethomecarddata') {
          return TRUE;
       }
        if ((!empty($arg[1]) && in_array($arg[1], $watch_right_now_node_array)) || $arg[0] == 'blog' || $arg[0] == 'itg_active_polls' || $arg[0] == 'site-map' || $arg[0] == 'blog-listing' || $arg[0] == 'podcasts-listing' || $arg[0] == 'programmes' || $arg[0] == 'topic' || $arg[0] == 'online-archive-story' || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'blog') || $arg[0] == 'itg-survey' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'story') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'podcast') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'mega_review_critic') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'breaking_news') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'photogallery') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'survey') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'videogallery' && isset($_GET['sid'])) || ($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2])) || $display_block == TRUE) {
          return TRUE;
        }
        break;
      case 'top_takes_videos_widget':
        
       if($arg[0] =='gethomecarddata') {
          return TRUE;
       }
        if ((!empty($arg[1]) && in_array($arg[1], $top_takes_node_array)) || $arg[0] == 'blog' || $arg[0] == 'itg_active_polls' || $arg[0] == 'itg-quiz' || $arg[0] == 'programmes' || $arg[0] == 'topic' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'blog') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'story') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'breaking_news') || $display_block == TRUE) {
          return TRUE;
        }
        break;
      case 'we_may_suggest':
       
       if($arg[0] =='gethomecarddata') {
          return TRUE;
       }
        if ((!empty($arg[1]) && in_array($arg[1], $we_may_suggest_node_array)) || $arg[0] == 'blog' || $arg[0] == 'itg_active_polls' || $arg[0] == 'site-map' || $arg[0] == 'itg-quiz' || $arg[0] == 'blog-listing' || $arg[0] == 'podcasts-listing' || $arg[0] == 'topic' || $arg[0] == 'livetv' || $arg[0] == 'online-archive-story' || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'blog') || $arg[0] == 'programmes' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || $arg[0] == 'anchors-list' || $arg[0] == 'itg-survey' || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'story') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'survey') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'breaking_news') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'photogallery') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'podcast') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'mega_review_critic') || (!empty($page_argument[0]->type) && $page_argument[0]->type == 'videogallery' && isset($_GET['sid'])) || $display_block == TRUE) {
          return TRUE;
        }
        break;
    }
  }
}

/**
 * This function use for insert all node in widget table
 *
 */
function insert_all_node_in_widegt_table() {

//  try {
//    // db_query('alter table itg_widget_order add column constituency varchar(200) NULL after extra')->execute();
//    db_query('alter table itg_widget_order add id int NOT NULL AUTO_INCREMENT PRIMARY KEY')->execute();
//  } catch (Exception $ex) {
//    drupal_set_message($ex->getMessage());
//  }
//    $nodes = db_select('node', 'n')
//                    ->fields('n', array('nid'))
//                    ->condition('n.type', array('story', 'photogallery', 'videogallery'), "IN")
//                    ->execute()->fetchAll(PDO::FETCH_ASSOC);
//    foreach ($nodes as $data) {
//        $node = node_load($data['nid']);
//        itg_widget_node_insert($node);
//    }
}

/**
 * Implements hook__node_insert().
 * {@inheritdoc}
 */
function itg_widget_node_insert($node) {
  if ($node->type == 'story' || $node->type == 'videogallery' || $node->type == 'photogallery') {
    if ($node->field_story_source_type['und'][0]['value'] != 'migrated') {
      $nid = $node->nid;
      $cat_id = $node->field_story_category['und'];
      if (isset($node->field_story_category['und'])) {
        $primary_category = $node->field_primary_category['und'][0]['value'];
        foreach ($cat_id as $category) {

          if ($node->field_story_source_type['und'][0]['value'] == 'migrated' && $category['tid'] == $primary_category) {
            continue;
          }
          else {
            $single_max_result = get_max_weight_for_node_insert($category['tid'], $node->type);
            $max_result = $single_max_result['content_type'];
            $max_result_all = $single_max_result['All'];
            $single_insert_query = db_insert('itg_widget_order')->fields(
                    array(
                        'nid',
                        'widget',
                        'content_type',
                        'cat_id',
                        'weight',
                        'extra',
                    )
            );

            $single_insert_query->values(array(
                'nid' => $nid,
                'widget' => 'section_wise_widget',
                'content_type' => $node->type,
                'cat_id' => $category['tid'],
                'weight' => ++$max_result,
                'extra' => '',
                    )
            );

            $single_insert_query->execute();

            $single_insert_query_all = db_insert('itg_widget_order')->fields(
                    array(
                        'nid',
                        'widget',
                        'content_type',
                        'cat_id',
                        'weight',
                        'extra',
                    )
            );

            $single_insert_query_all->values(array(
                'nid' => $nid,
                'widget' => 'section_wise_widget',
                'content_type' => 'All',
                'cat_id' => $category['tid'],
                'weight' => ++$max_result_all,
                'extra' => '',
                    )
            );

            $single_insert_query_all->execute();
          }
        }
      }
    }
  }
}

/**
 * Function returns max weight.
 * @param int $tid
 * @param string $type
 * @return int
 */
function get_max_weight_for_node_insert($tid, $type) {
  $max_query = db_select('itg_widget_order');
  $max_query->addExpression('MAX(weight)', 'weight');
  $max_query->condition('cat_id', $tid);
  $max_query->condition('content_type', array($type, 'All'), 'IN');
  $max_query->condition('widget', 'section_wise_widget');
  $max_query->groupBy('content_type');
  $max_result = $max_query->execute()->fetchAll();
  $all_weight = !empty($max_result[0]->weight) ? $max_result[0]->weight : 1;
  $ct_weight = !empty($max_result[1]->weight) ? $max_result[1]->weight : 1;
  $weight_array = array("All" => $all_weight, "content_type" => $ct_weight);
  return $weight_array;
}

/**
 * Function returns max weight.
 * @param int $tid
 * @param string $type
 * @return int
 */
function get_max_weight($tid, $type) {
  $max_query = db_select('itg_widget_order');
  $max_query->addExpression('MAX(weight)');
  $max_query->condition('cat_id', $tid);
  $max_query->condition('content_type', $type);
  $max_query->condition('widget', 'section_wise_widget');
  $max_result = $max_query->execute()->fetchField();
  return $max_result;
}

/**
 * Function returns max weight of perticular content type.
 * @param string $type
 * @return int
 */
function get_max_weight_for_special($type) {
  $max_query = db_select('itg_widget_order');
  $max_query->addExpression('MAX(weight)');
  $max_query->condition('widget', $type);
  $max_result = $max_query->execute()->fetchField();
  return $max_result;
}

/**
 * Implements hook__node_update().
 * {@inheritdoc}
 */
function itg_widget_node_update($node) {
  if ($node->type == 'story' || $node->type == 'videogallery' || $node->type == 'photogallery') {
    if(itg_workflow_stop_node_update_batch_for_widgets()) {
      return;
    }
    $nid = $node->nid;
    $cat_id = $node->field_story_category['und'];
    $order = $node->created;
    $updated_categories = array();
    $node_type = $node->type;
    $query = db_select('itg_widget_order', 'iwo')
            ->fields('iwo', array('cat_id', 'weight'))
            ->condition('iwo.widget', 'section_wise_widget')
            ->condition('iwo.nid', $nid)
            ->groupBy('iwo.cat_id');

    $result = $query->execute()->fetchAll();

    foreach ($cat_id as $category) {
      $updated_categories[] = $category['tid'];
    }

    // Delete unused category from table.
    $strg = implode(',', $updated_categories);
    db_query("DELETE from {itg_widget_order} where widget= :widget and nid = :nid and cat_id not in (:str)", array(":widget" => 'section_wise_widget', ':nid' => $nid, ':str' => $strg));
    $new_weight_to_be_inserted = array();

    foreach ($updated_categories as $category) {
      //$new_weight_to_be_inserted[$category] = -1 * $order;
      foreach ($result as $db_values) {
        if ($db_values->cat_id == $category) {
          $new_weight_to_be_inserted[$category] = $db_values->weight;
        }
      }
    }


    foreach ($updated_categories as $category_tid => $cat_id) {
      manage_widget_order_during_node_update($nid, $cat_id, $node_type);
      manage_widget_order_during_node_update($nid, $cat_id, "All");
    }
  }

  if ($node->status == 0) {
    itg_widget_handle_unpublished_node($node->nid);
  }
}

function manage_widget_order_during_node_update($nid, $category_tid, $node_type) {
  $max_result = get_max_weight($category_tid, $node_type);
  $check_existing_query = db_select('itg_widget_order', 'iwo')
                  ->fields('iwo', array('nid'))
                  ->condition('iwo.content_type', $node_type)
                  ->condition('iwo.nid', $nid)
                  ->condition('iwo.widget', 'section_wise_widget')
                  ->condition('iwo.cat_id', $category_tid)->execute();

  $db_count = $check_existing_query->rowCount();

  if ($db_count == 0) {
    try {
      $query = db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nid,
                  'widget' => 'section_wise_widget',
                  'content_type' => $node_type,
                  'cat_id' => $category_tid,
                  'weight' => ++$max_result,
                  'extra' => "",
              ))
              ->execute();
    } catch (Exception $ex) {
      drupal_set_message($ex->getMessage());
    }
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_taxonomy_term_insert($term) {
  if ($term->vid == CATEGORY_MANAGMENT) {
    $flag = FALSE;
    foreach ($term->parent as $parents) {
      if ($parents == variable_get('so_sorry_category_id_for_widget')) {
        $flag = TRUE;
        continue;
      }
    }
    if ($flag) {
      $max_weight = get_max_weight_of_politoons();
      db_insert('draggableviews_structure')
              ->fields(array(
                  'entity_id' => $term->tid,
                  'view_name' => 'so_sorry_politoons',
                  'view_display' => 'so_sorry_politoons',
                  'args' => '[]',
                  'parent' => 0,
                  'weight' => ++$max_weight,
              ))
              ->execute();
    }
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_taxonomy_term_delete($term) {
  db_delete('draggableviews_structure')
          ->condition('entity_id', $term->tid)
          ->condition('view_name', 'so_sorry_politoons')
          ->condition('view_display', 'so_sorry_politoons')
          ->execute();
}

/**
 * {@inheritdoc}
 */
function get_max_weight_of_politoons() {
  $max_query = db_select('draggableviews_structure');
  $max_query->addExpression('MAX(weight)');
  $max_query->condition('view_name', 'so_sorry_politoons');
  $max_query->condition('view_display', 'so_sorry_politoons');
  $max_result = $max_query->execute()->fetchField();
  return $max_result;
}

/**
 * Gives extra coloum value so sorry widget.
 * @param int $nid
 * @return string
 */
function get_so_sorry_extra_for_nid($nid) {
  $query = db_select('itg_widget_order', 'iwo')
          ->fields('iwo', array('extra'))
          ->condition('iwo.nid', $nid)
          ->condition('iwo.widget', 'so_sorry_widget');
  return $query->execute()->fetchField();
}

/**
 * Function returns number of feature in so sorry widget.
 * @return int
 */
function count_sosorry_feature() {
  $query = db_select('itg_widget_order', 'iwo')
          ->fields('iwo', array('extra'))
          ->condition('iwo.extra', 'feature')
          ->condition('iwo.widget', 'so_sorry_widget')
          ->countQuery();
  return $query->execute()->fetchField();
}

/**
 * Gives recent upblised video which are in sosorry category.
 * @return int
 */
function get_recent_created_node_for_sosorry() {
  $query = db_select('node', 'n');
  $query->fields('n', array("nid"));
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->condition('n.type', 'videogallery')->condition('ti.tid', variable_get('so_sorry_category_id_for_widget'));
  $query->condition('n.status', 1)->orderBy('n.created', 'DESC');
  return $query->execute()->fetchField();
}

/**
 * Gives count of nid if it is present in sosorry widget.
 * @param int $nid
 * @return int
 */
function check_nid_in_sosorry($nid) {
  $query = db_select('itg_widget_order', 'iwo')
          ->fields('iwo', array('nid'))
          ->condition('iwo.nid', $nid)
          ->condition('iwo.widget', 'so_sorry_widget')
          ->countQuery();
  return $query->execute()->fetchField();
}

/**
 * Gives count of nid if it is present in sosorry widget.
 * @param int $nid
 * @return int
 */
function get_feature_nid_in_sosorry() {
  $query = db_select('itg_widget_order', 'iwo')
          ->fields('iwo', array('nid'))
          ->condition('iwo.extra', 'feature')
          ->condition('iwo.widget', 'so_sorry_widget');
  return $query->execute()->fetchField();
}

/**
 * Returns hash value crossponding to sites. Which is managing from custom varibales.
 * 
 * @param string $site_prefix
 *  site_prefix is like "qa" form qa_1234
 * 
 * @return string
 */
function itg_widget_get_site_hash_from_solr($site_prefix) {
  $solr_variable = variable_get('apache_solr_sites_prefix_values');
  $site_hash = array();
  if (!empty($solr_variable)) {
    $hash_site_string_array = explode(",", $solr_variable);
    foreach ($hash_site_string_array as $value) {
      $prefix_with_values = explode("|", $value);
      $site_hash[strtolower(trim($prefix_with_values[0]))] = trim($prefix_with_values[1]);
    }
    return isset($site_hash[$site_prefix]) ? $site_hash[strtolower($site_prefix)] : $site_hash['dev'];
  }
}

/**
 * Function to get data from solr.
 * @param int $entity_id
 * @param string $hash
 * @return string
 */
function itg_get_link_from_hash_and_entity_solr_search($entity_id, $hash) {
  $solr = apachesolr_get_solr();
  $query = apachesolr_drupal_query("custom", array('q' => "entity_id:$entity_id and hash: $hash"));
  $query->addParam('rows', '1'); // How many rows of result to display default it is 10.
  $query->addParam('qf', 'entity_id'); // Only search in title
  $resp_search = $query->search();
  return isset($resp_search->response->docs[0]) ? $resp_search->response->docs[0] : "";
}

/**
 * Function return only active taxonomy
 * @param array $taxonomy
 * @return array
 */
function itg_widget_get_active_taxonomy($taxonomy = array()) {
  if (function_exists('itg_category_manager_term_state')) {
    foreach ($taxonomy as $key => $term) {

      if (!itg_category_manager_term_state($term->tid)) {
        unset($taxonomy[$key]);
      }
    }
  }
  return $taxonomy;
}
