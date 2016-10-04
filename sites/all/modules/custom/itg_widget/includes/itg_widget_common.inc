<?php

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * This function is used to create settings.
 * 
 * {@inheritdoc}
 */
function itg_widgets_custom_variables() {
  $form = array();
  $form['program_category_id_for_programmes'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter Program Category Id'),
      '#default_value' => variable_get('program_category_id_for_programmes'),
      '#required' => TRUE,
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['so_sorry_category_id_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter So Sorry Category Id'),
      '#default_value' => variable_get('so_sorry_category_id_for_widget'),
      '#required' => TRUE,
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['anchor_id_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter Occupation for Anchors'),
      '#default_value' => variable_get('anchor_id_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['year_end_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of year end'),
      '#default_value' => variable_get('year_end_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['auto_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of Auto'),
      '#default_value' => variable_get('auto_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );


  $form['tech_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of tech'),
      '#default_value' => variable_get('tech_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );

  $form['entertainment_oscar_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of Entertainment Oscar Watch'),
      '#default_value' => variable_get('entertainment_oscar_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['entertainment_oscar_news_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of Entertainment Oscar News Watch'),
      '#default_value' => variable_get('entertainment_oscar_news_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['entertainment_oscar_features_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of Entertainment Features Watch'),
      '#default_value' => variable_get('entertainment_oscar_features_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );
  $form['movie_for_widget'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter tid of movie'),
      '#default_value' => variable_get('movie_for_widget'),
      '#size' => 20,
      '#maxlength' => 20,
  );

  return system_settings_form($form);
}

/**
 * Funtion used to add or delete widgit ids into session for Selected content id should be display on top.
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
      else if ($_POST['type'] == 'REMOVE') {
        if (($key = array_search($ids, $datatoset)) !== false) {

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
    else if ($_POST['type'] == 'REMOVE') {

      if (($key = array_search($_POST['checkid'], $datatoset)) !== false) {
        unset($datatoset[$key]);
      }
    }
  }
  $datatoset = array_unique($datatoset);
  $_SESSION[$_POST['formid']] = $datatoset;
}

function remove_extra_data() {
  $widget = array(
//      'widget_anchors_listing',
//      'home_page_feature_widget',
//      'story_widget',
      'section_wise_content_ordering_list',
//      'section_wise_draggable_content_order',
//      'big_story_format_widget',
      'dont_miss_content_widget',
      'dont_miss_content',
//      'section_wise_widget',
//      'we_may_suggest_widget',
//      'section_wise_content_ordering',
//      'widget_anchors_listing',
//      'category_wise_content_list',
//     'photo_carousel_widget',
  );
  foreach ($widget as $view_name) {
    $num_deleted = db_delete('draggableviews_structure')
            ->condition('view_name', $view_name)
            ->condition('view_display', 'dont_miss_content')
            ->execute();

    $num_deleted = db_delete('itg_widget_order')
            ->condition('widget', $view_name)
            ->execute();
  }
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
  $num_updated = db_update('itg_widget_order')
          ->fields(array('extra' => " "))
          ->condition('nid', $nid)
          ->condition('widget', 'so_sorry_widget')
          ->execute();
//drupal_set_message(t("Node has been moved"));
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
 * {@inheritdoc}
 */
function itg_widget_form_alter(&$form, &$form_state, $form_id) {
  global $base_url;
  $setting = array();
  $queue_flag = "";
  $view_name = isset($form_state['view']->name) ? $form_state['view']->name : "";
  $current_display = isset($form_state['view']->current_display) ? $form_state['view']->current_display : "";
  /* Load all nodes queues */
  $queues = nodequeue_load_queues(nodequeue_get_all_qids());
  switch ($view_name) {
    // top story
    case 'story_widget':
      if ($current_display == 'most_popular') {
        //  watchdog("Widget", "Nodequeue bulk operation settings has been found for : Most Popular");
        $queue_flag = 5; // most popular
      }
      elseif ($current_display == 'trending_videos') {
        //  watchdog("Widget", "Nodequeue bulk operation settings has been found for : Trending video");
        $queue_flag = 4; // top story widget qid
      }
      elseif ($current_display == 'top_takes_video') {
        //  watchdog("Widget", "Nodequeue bulk operation settings has been found for : Trending video");
        $queue_flag = $queue_flag = get_nodequeue_load_queue_by_name('top_takes_videos'); // top story widget qid
      }
      elseif ($current_display == 'watch_right_now') {
        //  watchdog("Widget", "Nodequeue bulk operation settings has been found for : Trending video");
        $queue_flag = $queue_flag = get_nodequeue_load_queue_by_name('watch_right_now'); // top story widget qid
      }
      else {
        $queue_flag = 1; // trending_videos widget qid
      }
      break;
    // home page feature
    case 'home_page_feature_widget':
      // watchdog("Widget", "Nodequeue bulk operation settings has been found for : home page feature");
      $queue_flag = 2; // home page feature qid
      break;
    // We may suggest
    case 'we_may_suggest':
      // watchdog("Widget", "Nodequeue bulk operation settings has been found for : we may suggest");
      $queue_flag = 3; // home page feature qid
      break;
    case 'widget_anchors_listing':
      // watchdog("Widget", "Nodequeue bulk operation settings has been found for : we may suggest");
      $queue_flag = $queue_flag = get_nodequeue_load_queue_by_name('widget_anchor'); // anchor widget nodequeue
      break;

    case 'photo_carousel_widget':
      if ($current_display == 'photo_carousel_list') {
        //watchdog("Widget", "Nodequeue bulk operation settings has been found for : Photo Carousel video");
        $queue_flag = get_nodequeue_load_queue_by_name('photo_carousel');
        ; // photo carousel list widget qid
      }
      if ($current_display == 'video_carousel_list') {
        //watchdog("Widget", "Nodequeue bulk operation settings has been found for : Video Carousel video");
        $queue_flag = get_nodequeue_load_queue_by_name('video_carousel'); // video carousel list widget qid
      }

      break;
  }
  if (!empty($queues[$queue_flag])) {
    $setting['name'] = $queues[$queue_flag]->name;
    $setting['qid'] = $queues[$queue_flag]->qid;
    $setting['title'] = $queues[$queue_flag]->title;
    // add js for setting
    drupal_add_js(drupal_get_path('module', 'itg_widget') . '/js/itg_widget.main.js', 'file');
    // pass setting to js for bulk operation
    drupal_add_js(array('itg_widget' => array('data' => $setting)), 'setting');
  }
  // Alter form for confirm message during bulk operation.
  // Below forms are thoese which are not doing action for nodequeue.
  // Nodequeue from are being altered form itg_widget.main.js.
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
    }
    unset($form[$sydication_field_name]['#options']);
    $form[$sydication_field_name]['#options']['all'] = '- Any -';
    $form[$sydication_field_name]['#options']['or'] = 'Yes';
    $form[$sydication_field_name]['#options']['not'] = 'No';

    drupal_add_css('.form-item-field-story-syndication-value-1 , .form-item-field-story-syndication-value {display:none;}', array('type' => 'inline'));
    drupal_add_css('.views-widget-filter-field_story_syndication_value_1 , .views-widget-filter-field_story_syndication_value {display:inline-block !important;}', array('type' => 'inline'));

    $url_chunk = explode("?", $_SERVER['REQUEST_URI']);
    $url_without_query_string = end(explode('/', $url_chunk[0]));

    $form['reset'] = array(
        '#type' => 'markup',
        '#markup' => l("Reset", $url_without_query_string, array("query" => $query_url)),
    );
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
    return true;
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_views_bulk_operations_form_alter(&$form, &$form_state, $vbo) {
  // Form id which will use session value.
  // Session value is set by ajax.
  // Extra funtionality to display nodeid with cross.
  $form_to_used_session_checked = forms_uses_checked_content_id();

  if (in_array($form['#form_id'], $form_to_used_session_checked)) {
    // $form_state['selection'] value is set by bulk operation submit.
    // Only selected nodes are come in $form_state['selection'] array.
    // Here we are forcely changing the array.
    // for big story we are using single selection so skip for big story.
    $form_state['selection'] = $_SESSION[$form['#form_id']];
    $form_state['values']['views_bulk_operations'] = $form_state['selection'];
    $form['actions']['submit']['#submit'][] = "itg_widget_custom_session_destory";
  }

  // Add a node id contianer just below the bulk operation.
  if (isset($form['select']['action::nodequeue_add_action'])) {
    $form['select']['action::nodequeue_add_action']['#suffix'] = '<div class="nodes_id_container"></div>';
  }

  if (isset($form['select']['action::itg_widget_categories_wise_node_group'])) {
    $form['select']['action::itg_widget_categories_wise_node_group']['#suffix'] = '<div class="nodes_id_container"></div>';
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
  );
}

/**
 * Funtion is used for get the session values
 * Which is set for only checkbox on widget search content page.
 * 
 * @param array $form
 * @return array
 */
function get_sessions_of_ticked_nodes(&$form) {
  if (isset($form['views_bulk_operations'])) {
    foreach ($form['views_bulk_operations'] as $key => $form_node_data) {
      if (in_array($form_node_data['#return_value'], $_SESSION[$form['#form_id']])) {
        $form['views_bulk_operations'][$key]['#attributes']['class'][] = 'custom-selected';
        $form['views_bulk_operations'][$key]['#default_value'] = $form_node_data['#return_value'];
      }
    }
    drupal_add_js('jQuery(window).load(function() {
            var sessionids="' . implode($_SESSION[$form['#form_id']], ',') . '";
                if(sessionids!="")
                {
                sessionids=sessionids.split(",");
                }
                jQuery.each(sessionids, function( index, value ) {
                 jQuery(".fieldset-wrapper").append("<span id=spn_"+value+" class=content-ids>"+value+"<a class=removeid cid="+value+" href=javascript:void(0)>X</a></span>");});

            });', array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
    );
  }

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
      'year_end_top_videos' => array(
          'template' => 'templates/year-end-top-videos',
      ),
      'auto_reviews' => array(
          'template' => 'templates/auto-reviews',
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
        $setting_link = l("Click Here", "admin/settings/custom-variables");
        drupal_set_message("Setting not found for autocomplete. Please $setting_link", "error");
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
    case 'views-exposed-form-poll-widget-poll-widget-format':
      $form['title']['#attributes']['placeholder'] = t('Content Title');
      $form['nid']['#attributes']['placeholder'] = t('Content ID');
      $autocomplete_path = autocomplete_for_widgets('poll');
      $form['title']['#autocomplete_path'] = $autocomplete_path['title'];
      $form['nid']['#autocomplete_path'] = $autocomplete_path['nid'];
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
    case 'views-exposed-form-section-wise-content-ordering-list-page':
      $form['#validate'][] = 'custom_section_wise_validate';
      break;
  }

  if (isset($form['#info']['filter-shs_term_node_tid_depth']) && !empty($form['#info']['filter-shs_term_node_tid_depth'])) {
    $form['#info']['filter-shs_term_node_tid_depth']['label'] = 'Section';
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
function autocomplete_for_widgets($type, $isCondition = FALSE, $custom_type = 'breaking_news') {
  $autocomplete = array();
  if (isset($type) && $type != 'All') {
    $autocomplete['title'] = "content-title-list/$type/autocomplete";
    $autocomplete['nid'] = "content-nid-list/$type/autocomplete";
  }
  else {
    // Handle case for big story
    if (!$isCondition) {
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
 * Function used to get widget name
 * 
 * {@inheritdoc}
 */
function _get_widget_name($view_name, $page_name) {
  $widget = "";
  // TODO: Use switch-case

  if (($view_name == 'views_form_section_wise_draggable_content_order_page' || $view_name == 'views_form_section_wise_content_ordering_list_page') && $page_name == 'page') {
    $widget = 'section_wise_widget';
  }
  else if ($page_name == 'we_may_suggest_widget') {
    $widget = 'we_may_suggest_widget';
  }
  else if ($page_name == 'most_popular_widget') {
    $widget = 'we_may_suggest_widget';
  }
  else if ($page_name == 'big_story_format') {
    $widget = 'big_story_format_widget';
  }
  else if ($page_name == 'photo_carousel_list') {
    $widget = 'photo_carousel_list_widget';
  }
  else if ($page_name == 'video_carousel_list') {
    $widget = 'video_carousel_list_widget';
  }
  else if ($page_name == 'dont_miss_content') {
    $widget = 'dont_miss_content_widget';
  }
  return $widget;
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
  if ($view->name == 'section_wise_draggable_content_order' && $view->current_display == 'big_story_format' && $_GET['type'] == 'story') {
    unset($query->table_queue['field_data_field_type']);
    unset($query->tables['node']['field_data_field_type']);
    unset($query->where[1]['conditions'][2]);
  }
  if ($view->name == 'programmes' && ($view->current_display == 'page' || $view->current_display == 'rhs_programmes')) {
    $program_cat_value = variable_get('program_category_id_for_programmes');
    if (strlen($program_cat_value) <= 0) {
      // Link should display only adminstrator.
      if (in_array('administrator', $user->roles)) {
        $link = l("click here", 'admin/settings/custom-variables');
      }
      drupal_set_message("Program category setting not found $link", "error");
    }
    $program_where_condition = array(
        'field' => 'taxonomy_term_hierarchy.parent',
        'value' => $program_cat_value,
        'operator' => '=',
    );
    array_push($query->where[1]['conditions'], $program_where_condition);
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_page') {
    // Handling the query if other videos are clicked but those are not feature.
    // But they are in itg_widget_order table as well as widget value is equal to so_sorry_widget
    $arg = arg();
    if (isset($arg[1])) {
      unset($query->where[1]['conditions'][1]);
    }
  }

  if ($view->name == 'anchor_option_view') {
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
  }

  if ($view->name == 'anchor_landing_page') {
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
  }

  if (($view->name == 'widget_anchors_listing' && $view->current_display == 'anchors_display_page') || ($view->name == 'widget_anchors_listing' && $view->current_display == 'anchors_listing_page')) {
    $anchor_tid = variable_get('anchor_id_for_widget');
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
    if (strlen($anchor_tid) <= 0) {
      // Link should display only adminstrator.
      if (in_array('administrator', $user->roles)) {
        $link = l("click here", 'admin/settings/custom-variables');
      }
      drupal_set_message("Anchor setting not found $link", "error");
    }
  }

  if (($view->name == 'widget_anchors_listing' && $view->current_display == 'anchors_listing_widget')) {
    $anchor_tid = variable_get('anchor_id_for_widget');
    $query->where[1]['conditions'][2]['value'] = variable_get('anchor_id_for_widget');
    if (strlen($anchor_tid) <= 0) {
      // Link should display only adminstrator.
      if (in_array('administrator', $user->roles)) {
        $link = l("click here", 'admin/settings/custom-variables');
      }
      drupal_set_message("Anchor setting not found $link", "error");
    }
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_videos') {
    $query->where[1]['conditions'][1]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_videos_widget') {
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_feature') {
    $query->where[1]['conditions'][2]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'so_sorry_page') {
    $query->where[1]['conditions'][2]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'the_remix') {
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'so_sorry' && $view->current_display == 'most_watched') {
    $query->where[1]['conditions'][3]['value'] = variable_get('so_sorry_category_id_for_widget');
  }
  if ($view->name == 'so_sorry' && $view->current_display == 'you_will_love_these') {
    $query->where[1]['conditions'][1]['value'] = variable_get('so_sorry_category_id_for_widget');
  }

  if ($view->name == 'yearender_top_news_and_top_videos' && $view->current_display == 'yearend_left_widget_contents') {
    $query->where[1]['conditions'][3]['value'] = variable_get('year_end_for_widget');
  }

  if ($view->name == 'yearender' && $view->current_display == 'block_2') {
    $query->where[1]['conditions'][3]['value'] = variable_get('year_end_for_widget');
  }
  if ($view->name == 'yearender' && $view->current_display == 'block_1') {
    $query->where[1]['conditions'][3]['value'] = variable_get('year_end_for_widget');
  }
  if ($view->name == 'auto' && $view->current_display == 'block_2') {
    $query->where[1]['conditions'][2]['value'] = variable_get('auto_for_widget');
  }
  if ($view->name == 'auto' && $view->current_display == 'block_1') {
    $query->where[1]['conditions'][2]['value'] = variable_get('auto_for_widget');
  }

  if ($view->name == 'auto' && $view->current_display == 'block_5') {
    $query->where[1]['conditions'][2]['value'] = variable_get('auto_for_widget');
  }

  // Start alter for tech
  if ($view->name == 'tech' && $view->current_display == 'block_1') {
    $query->where[1]['conditions'][2]['value'] = variable_get('tech_for_widget');
  }
  if ($view->name == 'tech' && $view->current_display == 'block_2') {
    $query->where[1]['conditions'][2]['value'] = variable_get('tech_for_widget');
  }

  if ($view->name == 'tech' && $view->current_display == 'block_5') {
    $query->where[1]['conditions'][2]['value'] = variable_get('tech_for_widget');
  }

  if ($view->name == 'tech' && $view->current_display == 'block_8') {
    $query->where[1]['conditions'][2]['value'] = variable_get('tech_for_widget');
  }
  if ($view->name == 'special_entertainment' && $view->current_display == 'entertainment_oscar_news') {
    $query->where[1]['conditions'][2]['value'] = variable_get('entertainment_oscar_news_for_widget');
  }
  if ($view->name == 'special_entertainment' && $view->current_display == 'entertainment_oscar_features') {
    $query->where[1]['conditions'][2]['value'] = variable_get('entertainment_oscar_features_for_widget');
  }
  if ($view->name == 'special_entertainment' && ($view->current_display == 'oscar_videos' || $view->current_display == 'oscar_photos')) {
    $query->where[1]['conditions'][2]['value'] = variable_get('entertainment_oscar_for_widget');
  }
  if ($view->name == 'special_entertainment' && ($view->current_display == 'entertainment_oscar_slider')) {
    $query->where[1]['conditions'][2]['value'] = variable_get('entertainment_oscar_for_widget');
  }
  if ($view->name == 'special_movie' && ($view->current_display == 'movie_photo_slider' || $view->current_display == 'movie_top_news' || $view->current_display == 'movie_left_top')) {
    $query->where[1]['conditions'][2]['value'] = variable_get('movie_for_widget');
  }
  //pr($query->where[1]); 
}

/**
 * Function for returning node queue id by node queue machine name.
 *
 * @param string $form
 */
function get_nodequeue_load_queue_by_name($qname) {
  try {
    $node_queue_object = nodequeue_load_queue_by_name($qname);
    return isset($node_queue_object->qid) ? $node_queue_object->qid : null;
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
  );
  if (in_array($view_name, $widget_views)) {
    $vars['classes_array'][] = 'widgets-view';
    //drupal_add_css('td.tabledrag-hide {display: block !important;}' , 'inline');
  }
}

/**
 * Function for theme suggestion.
 * 
 * {@inheritdoc}
 */
function itg_widget_preprocess_node(&$vars) {

  // Get all terms of vocabulary occupation.
  $itg_occupation = taxonomy_vocabulary_machine_name_load('itg_occupation');
  $itg_occupation_tree = taxonomy_get_tree($itg_occupation->vid);
  foreach ($itg_occupation_tree as $term) {
    $occupation[] = $term->name;
  }

  if ($vars['type'] == 'reporter' && in_array('Anchor', $occupation)) {

    drupal_add_js(
            "jQuery(document).ready(function(){
              jQuery('.read-more , .full-content').click(function(){
                jQuery('.less-content').toggle();
                jQuery('.full-content').toggle();
              });
            })", 'inline'
    );
    $vars['theme_hook_suggestions'][] = 'node__reporter__anchor';
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
function get_view_nodes_form_custom_table_for_widgets($widget_name, $range_max, $range_min = 0) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->orderBy('iwo.weight', 'ASC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $weight = 0;
  foreach ($result as $data) {
    $weight +=$data['weight'];
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
function get_view_nodes_form_custom_table_for_yearend_widgets($widget_name, $content_type, $range_max, $range_min = 0) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('iwo.content_type', $content_type)
          ->orderBy('iwo.weight', 'ASC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $weight = 0;
  foreach ($result as $data) {
    $weight +=$data['weight'];
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
            ->condition('iwo.content_type', $content_type)
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
function get_view_nodes_form_custom_table_for_spacila_auto_widgets($widget_name, $var_name, $range_max, $range_min = 0) {
  $query = db_select('itg_widget_order', 'iwo');
  $query->leftJoin('node', 'n', 'n.nid=iwo.nid');
  $query->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1)
          ->condition('iwo.cat_id', variable_get($var_name))
          ->orderBy('iwo.weight', 'ASC')
          ->range($range_min, $range_max)
          ->fields('iwo', array('nid', 'extra', 'weight'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  $weight = 0;
  foreach ($result as $data) {
    $weight +=$data['weight'];
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
            ->condition('iwo.cat_id', variable_get($var_name))
            ->orderBy('n.nid', 'DESC')
            ->range($range_min, $range_max)
            ->fields('iwo', array('nid', 'extra', 'weight'));
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
  }
}

/**
 * {@inheritdoc}
 */
function itg_widget_block_view_alter(&$data, $block) {

//  $item = menu_get_item();
//  $arg = arg();
//
//  $page_argument = $item['page_arguments'];
//  if ($block->delta == 'programmes-rhs_programmes') {
//    if ($arg[0] == 'anchors-list' || ($page_argument[0]->field_celebrity_pro_occupation['und'][0]['taxonomy_term']->name == 'Anchor') || ($page_argument[0]->type == 'videogallery' && empty($_GET['sid']))) {
//      return TRUE;
//    }
//    else {
//      $data['content'] = array();
//    }
//  }

  $item = menu_get_item();
  $flag_occupation = array();
  $arg = arg();
  $page_argument = $item['page_arguments'];
  $occupation = $page_argument[0]->field_celebrity_pro_occupation['und'];
  foreach ($occupation as $occupation_taxonomy) {
    $flag_occupation[] = $occupation_taxonomy['taxonomy_term']->name;
  }
  if ($block->delta == 'programmes-rhs_programmes') {
    if ($arg[0] == 'anchors-list' || (in_array('Anchor', $flag_occupation)) || ($page_argument[0]->type == 'videogallery' && empty($_GET['sid']))) {
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
  $nodes_already = db_select('itg_widget_order', 'iwo');
  $nodes_already->Join('node', 'n', 'iwo.nid=n.nid');
  $nodes_already->fields('iwo', array('nid'));
  $nodes_already->condition('iwo.content_type', $content_type)
          ->condition('iwo.widget', $widget_name)
          ->condition('n.status', 1);
  $res = $nodes_already->execute()->fetch();
  return $res->nid;
}

/**
 * This mentod will return a poll widget for against poll nid, used in home page widget 
 * @param type $nid
 */
function itg_poll_home_page_polls_select($nid) {

  $node = node_load($nid);
  $poll_banner_image = '';
  if (isset($node->field_poll_banner[$node->language][0]['uri']) && !empty($node->field_poll_banner[$node->language][0]['uri'])) {
    $poll_banner_image = theme('image_style', array('style_name' => 'home_page_poll_images_style', 'path' => $node->field_poll_banner[$node->language][0]['uri']));
  }
  else {
    $poll_banner_image = '';
  }

  $poll_image_exist_class = '';

  foreach ($node->field_poll_answer['und'] as $row) {
    $item_id[] = $row['value']; // fieldcollection id
  }
  // instant or after complete

  $fieldcollect = entity_load('field_collection_item', $item_id);
  if (is_array($fieldcollect) && count($fieldcollect) > 0) {
    $temp_ent = array_shift(array_slice($fieldcollect, 0, 1));
    $poll_answer_image = isset($temp_ent->field_poll_answer_image[LANGUAGE_NONE]) ? $temp_ent->field_poll_answer_image[LANGUAGE_NONE][0]['fid'] : '';
    if (isset($poll_answer_image) && $poll_answer_image > 0) {
      $poll_image_exist_class = 'poll-option-image';
    }
    else {
      $poll_image_exist_class = '';
    }
  }


  $polls_info['poll_banner_image'] = $poll_banner_image;
  $polls_info['nid'] = $nid;
  $polls_info['title'] = $node->title;
  $polls_info['updated'] = t('Updated: ') . date('M d Y H:i', $node->changed);
  $polls_info['poll_image_exist_class'] = $poll_image_exist_class;

  return theme('itg_poll_homepage_forms', array('data' => $polls_info));
}

/**
 * Implements hook_form().
 * {@inheritdoc}
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidget_filter_form($form, $form_state) {
  $options = array();
  $options[''] = 'Select';
  $query = db_select('node', 'n');
  $query->fields('n', array('title'));
  $query->condition('n.type', array('issue'), '=');
  $query->condition('n.status', 1);
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $options[date('Y-m-d', strtotime($record['title']))] = date('d/m/Y', strtotime($record['title']));
  }

  $form['content_title'] = array(
      '#title' => t('Content Title'),
      '#type' => 'select',
      '#default_value' => $_GET['field_story_issue_date_value']['value']['date'],
      '#options' => $options,
  );
  $form['items_per_page'] = array(
      '#title' => t('Items per page '),
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
 * This mentod will go to issue widget filter url
 * 
 * @param array $form
 * @param array $form_state
 */
function itg_widget_issuewidget_filter_form_submit($form, $form_state) {

  $query = array('field_story_issue_date_value[value][date]' => $form_state['values']['content_title'], 'items_per_page' => $form_state['values']['items_per_page']);
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
  $options = array();
  $options[''] = 'Select';
  $query = db_select('node', 'n');
  $query->fields('n', array('title'));
  $query->condition('n.type', array('issue'), '=');
  $query->condition('n.status', 1);
  $result = $query->execute();
  while ($record = $result->fetchAssoc()) {
    $options[date('Y-m-d', strtotime($record['title']))] = date('d/m/Y', strtotime($record['title']));
  }

  $form['content_title'] = array(
      '#title' => t('Content Title'),
      '#type' => 'select',
      '#default_value' => $_GET['field_story_issue_date_value']['value']['date'],
      '#options' => $options,
  );
  $form['items_per_page'] = array(
      '#title' => t('Items per page '),
      '#type' => 'select',
      '#default_value' => ($_GET['items_per_page']) ? $_GET['items_per_page'] : 20,
      '#options' => array(5 => 5, 10 => 10, 20 => 20, 40 => 40, 60 => 60),
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

  $query = array('field_story_issue_date_value[value][date]' => $form_state['values']['content_title'], 'items_per_page' => $form_state['values']['items_per_page']);
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
  else if (!empty($is_fron_page)) {
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
  $display_block = itg_block_display_condition();

  switch ($delta) {
    case 'watch_right_now_videos_widget':
      if ($arg[0] == 'programmes' || $arg[0] == 'itg-survey' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || ($page_argument[0]->type == 'story') || ($page_argument[0]->type == 'breaking_news') || ($page_argument[0]->type == 'photogallery') || ($page_argument[0]->type == 'survey') || ($page_argument[0]->type == 'videogallery' && isset($_GET['sid'])) || ($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2])) || $display_block == TRUE) {
        return TRUE;
      }
      break;
    case 'top_takes_videos_widget':
      if ($arg[0] == 'programmes' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || ($page_argument[0]->type == 'story') || ($page_argument[0]->type == 'breaking_news') || $display_block == TRUE) {
        return TRUE;
      }
      break;
    case 'we_may_suggest':
      if ($arg[0] == 'programmes' || $arg[0] == 'itg-layout-manager' || $arg[0] == 'insert-layout-setting-ajax' || $arg[0] == 'anchors-list' || $arg[0] == 'itg-survey' || ($page_argument[0]->type == 'story') || ($page_argument[0]->type == 'survey') || ($page_argument[0]->type == 'breaking_news') || ($page_argument[0]->type == 'photogallery') || ($page_argument[0]->type == 'videogallery' && isset($_GET['sid'])) || $display_block == TRUE) {
        return TRUE;
      }
      break;
  }
}

/**
 * Implements hook__node_insert().
 * {@inheritdoc}
 */
function itg_widget_node_insert($node) {
  if ($node->type == 'story' || $node->type == 'videogallery' || $node->type == 'photogallery') {
    $nid = $node->nid;
    $cat_id = $node->field_story_category['und'];
    $order = $node->created;

    foreach ($cat_id as $category) {
      // Insert into table.
      $query = db_insert('itg_widget_order')
              ->fields(array(
                  'nid' => $nid,
                  'widget' => 'section_wise_widget',
                  'content_type' => $node->type,
                  'cat_id' => $category['tid'],
                  'weight' => -1 * abs($node->created),
                  'extra' => "",
              ))
              ->execute();
    }
  }
}

/**
 * Implements hook__node_insert().
 * {@inheritdoc}
 */
function itg_widget_node_update($node) {
  if ($node->type == 'story' || $node->type == 'videogallery' || $node->type == 'photogallery') {
    $nid = $node->nid;
    $cat_id = $node->field_story_category['und'];
    $order = $node->created;
    $updated_categories = array();

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
    $sqlInsert = "DELETE from {itg_widget_order} where widget='section_wise_widget' and nid = '" . $nid . "' and cat_id not in ($strg)";
    db_query($sqlInsert);


    $new_weight_to_be_inserted = array();

    foreach ($updated_categories as $category) {
      $new_weight_to_be_inserted[$category] = -1*$order;
      foreach ($result as $db_values) {
        if ($db_values->cat_id == $category) {
          $new_weight_to_be_inserted[$category] = $db_values->weight;
        }
      }
    }
    

    foreach ($new_weight_to_be_inserted as $category_tid => $weight) {
      $query = db_merge('itg_widget_order')
              ->key(array('nid' => $nid, 'widget' => 'section_wise_widget', 'cat_id' => $category_tid))
              ->fields(array(
                  'nid' => $nid,
                  'widget' => 'section_wise_widget',
                  'content_type' => $node->type,
                  'cat_id' => $category_tid,
                  'weight' => $weight,
                  'extra' => "",
              ))
              ->execute();
    }
  }
}
