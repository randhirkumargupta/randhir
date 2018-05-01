<?php

/**
 * Function which is used to insert data in helper table for nid.
 * @param int $nid
 */
function __itg_widget_helper_data_insert($nid, $node_data = null) {
  
   // if ($nid && $_REQUEST['op'] !='Apply' && $_REQUEST['op'] !='Save') {
        __itg_widget_helper_data_delete($nid);
        if (empty($node_data)) {
          $node_load_data = node_load($nid, null, TRUE);
        }

        else if ((!empty($node_data)) && ($node_data->status == 1) && (!isset($node_data->original))) {
          $node_load_data = node_load($nid, null, TRUE);
        }
        else {
          $node_load_data = $node_data;
        }

  //$node_load_data = node_load($nid, null, TRUE);

        $node_load_data->status = itg_common_get_node_status_from_tbl($nid);
        
        try {
            db_insert('itg_widget_helper')
              ->fields(array(
                'nid',
                'node_data',
                'node_status',
                'node_type',
                )
              )
              ->values(
                array(
                  'nid' => $nid,
                  'node_data' => serialize($node_load_data),
                  'node_status' => $node_load_data->status,
                  'node_type' => $node_load_data->type,
                )
              )->execute();
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage(), 'error');
        }
    //}
}

function itg_common_get_node_status_from_tbl($nid) {
  if(is_numeric($nid)) {
    return db_select('node' ,'n')->fields('n', array('status'))->condition('n.nid' , $nid)->execute()->fetchField();
  }
}
/**
 * Function used to delete data from helper table for perticulat nid.
 * @param int $nid
 */
function __itg_widget_helper_data_delete($nid) {
  //itg_watchdog("helper_delete" , $nid);
    if ($nid) {
        try {
            db_delete('itg_widget_helper')->condition("nid", $nid)->execute();
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage(), 'error');
        }
    }
}

/**
 * Function gives sosorry feature and remix content data.
 * @param type string
 */
function __get_sosorry_video_nid($type = 'feature') {
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin("node", "n", "n.nid=iwo.nid");
    $query->fields('iwo', array("nid"));
    $query->condition("iwo.widget", "so_sorry_widget");
    $query->condition("n.status", 1);
    $query->condition("iwo.extra", $type);
    return $query->execute()->fetchField();
}

/**
 * Function check nids exists in both widget table of not.
 * @param int $nid
 * @return boolean
 */
function __itg_check_nid_in_widget($nid) {
    $flag = FALSE;
    $i = 0;
    $widget_tbl = db_select("itg_widget_order", "iwo")
        ->fields("iwo", array("nid"))
        ->condition("iwo.nid", $nid)
        ->execute()->rowCount();
    if ($widget_tbl) {
        $i += $widget_tbl;
    }

    $widget_tbl_section = db_select("itg_widget_order_section", "iws")
        ->fields("iws", array("nid"))
        ->condition("iws.nid", $nid)
        ->execute()->rowCount();
    if ($widget_tbl_section) {
        $i += $widget_tbl_section;
    }

    if ($i) {
        $flag = TRUE;
    }
    return $flag;
}

/**
 * Function returns unique data from widget tables.
 * 
 * @return array
 */
function _itg_widget_get_old_data() {
    try {
        $widget_tbl = db_select("itg_widget_order", "iwo")
            ->fields("iwo", array("nid"))
            ->execute()->fetchAllAssoc("nid");

        $widget_tbl_section = db_select("itg_widget_order_section", "iws")
            ->fields("iws", array("nid"))->execute()->fetchAllAssoc("nid");

        $array1 = array_keys($widget_tbl);
        $array2 = array_keys($widget_tbl_section);
        $result = array_unique(array_merge($array1, $array2));
        return $result;
    } catch (Exception $ex) {
        return $ex->getMessage();
    }
}

/**
 * Main function for widget data display.
 * 
 * @param array $result
 * @return array
 */
function _get_widget_display_data_as_per_db_result($result = array()) {
    if (!empty($result)) {
            foreach ($result as $widget_data) {
              $webcast_val = '';
              $is_sponsor = FALSE;
              $node_load_data = unserialize($widget_data->node_data);
             
              if($node_load_data->type == 'breaking_news' ) {
                pr($node_load_data);
              } elseif ((isset($node_load_data->field_story_configurations['und'])) && (!empty($node_load_data->field_story_configurations['und']))) {
                foreach ($node_load_data->field_story_configurations['und'] as $id => $id_arr) {
                  if ($id_arr['value'] == 'webcast') {
                    $webcast_val = $node_load_data->field_story_embed_webcast['und'][0]['value'];
                  }
                  if ($id_arr['value'] == 'sponsor') {
                    $is_sponsor = TRUE;
                  }
                }
              }
            $emoji_position1 = isset($node_load_data->field_emoji_position['und'][0]['value']) ? $node_load_data->field_emoji_position['und'][0]['value'] : "";
            $emoji_position2 = isset($node_load_data->field_emoji_position['und'][1]['value']) ? $node_load_data->field_emoji_position['und'][1]['value'] : "";
            $node_smily_data = array('field_story_short_headline_value' => isset($node_load_data->field_story_short_headline['und'][0]['value']) ? $node_load_data->field_story_short_headline['und'][0]['value'] : "",
                'field_emoji_position_value' => array(
                  $emoji_position1,
                  $emoji_position2,
                ),
                'field_emoji_2_value' => isset($node_load_data->field_emoji_2['und'][0]['value']) ? $node_load_data->field_emoji_2['und'][0]['value'] : "",
                'field_emoji_value' => isset($node_load_data->field_emoji['und'][0]['value']) ? $node_load_data->field_emoji['und'][0]['value'] : "",
                'title' => isset($node_load_data->title) ? $node_load_data->title : "",
                'ad_title' => isset($node_load_data->field_story_new_title['und'][0]['value']) ? $node_load_data->field_story_new_title['und'][0]['value'] : "",
                'ad_url' => isset($node_load_data->field_story_redirection_url_titl['und'][0]['value']) ? $node_load_data->field_story_redirection_url_titl['und'][0]['value'] : "",
                'nid' => isset($node_load_data->nid) ? $node_load_data->nid : "",
             );
            $uri = isset($node_load_data->field_story_extra_large_image['und'][0]['uri']) ? $node_load_data->field_story_extra_large_image['und'][0]['uri'] : "";
            $li_file_uri = isset($node_load_data->field_story_large_image['und'][0]['uri']) ? $node_load_data->field_story_large_image['und'][0]['uri'] : "";
            $mi_file_uri = isset($node_load_data->field_story_medium_image['und'][0]['uri']) ? $node_load_data->field_story_medium_image['und'][0]['uri'] : "";
            $esi_file_uri = isset($node_load_data->field_story_extra_small_image['und'][0]['uri']) ? $node_load_data->field_story_extra_small_image['und'][0]['uri'] : "";
            $si_file_uri = isset($node_load_data->field_story_small_image['und'][0]['uri']) ? $node_load_data->field_story_small_image['und'][0]['uri'] : "";
            $widget_image_uri_alt = isset($node_load_data->field_story_extra_small_image['und'][0]['alt']) ? $node_load_data->field_story_extra_small_image['und'][0]['alt'] : "";
            $widget_image_uri_title = isset($node_load_data->field_story_extra_small_image['und'][0]['title']) ? $node_load_data->field_story_extra_small_image['und'][0]['title'] : "";
            $field_story_kicker_text = isset($node_load_data->field_story_kicker_text['und'][0]['value']) ? $node_load_data->field_story_kicker_text['und'][0]['value'] : "";
            $field_story_short_headline_value = isset($node_load_data->field_story_short_headline['und'][0]['value']) ? $node_load_data->field_story_short_headline['und'][0]['value'] : "";
            $field_video_duration_value = isset($node_load_data->field_video_duration_value['und'][0]['value']) ? $node_load_data->field_video_duration_value['und'][0]['value'] : "";
            $field_photo_see_pic_link_value = isset($node_load_data->field_photo_see_pic_link['und'][0]['value']) ? $node_load_data->field_photo_see_pic_link['und'][0]['value'] : "";

            $nid = $node_load_data->nid;
            if ($node_load_data->type == 'story') {
                $title = $field_story_short_headline_value;
            } else {
                $title = $node_load_data->title;
            }
            $created = $node_load_data->created;
            $type = $node_load_data->type;
            $iwo_nid = $node_load_data->nid;
            $uid = $node_load_data->uid;
            $weight = $widget_data->weight;
            $extra = $widget_data->extra;
            $final_widget_array[] = array(
              'uri' => $uri,
              'field_story_extra_small_image_alt' => $widget_image_uri_alt,
              'field_story_extra_small_image_title' => $widget_image_uri_title,
              'field_story_short_headline_value' => !empty($field_story_short_headline_value) ? $field_story_short_headline_value : $title,
              'field_story_kicker_text_value' => $field_story_kicker_text,
              'field_video_duration_value' => $field_video_duration_value,
              'nid' => $nid,
              'title' => $title,
              'created' => $created,
              'type' => $type,
              'uid' => $uid,
              'field_photo_see_pic_link_value' => $field_photo_see_pic_link_value,
              'iwo_nid' => $iwo_nid,
              'extra' => $extra,
              'weight' => $weight,
              'esi_file_uri' => $esi_file_uri,
              'mi_file_uri' => $mi_file_uri,
              'li_file_uri' => $li_file_uri,
              'si_file_uri' => $si_file_uri,
              'field_story_large_image_alt' => isset($node_load_data->field_story_large_image['und'][0]['alt']) ? $node_load_data->field_story_large_image['und'][0]['alt'] : "",
              'field_story_large_image_title' => isset($node_load_data->field_story_large_image['und'][0]['title']) ? $node_load_data->field_story_large_image['und'][0]['title'] : "",
              'field_story_medium_image_alt' => isset($node_load_data->field_story_medium_image['und'][0]['alt']) ? $node_load_data->field_story_medium_image['und'][0]['alt'] : "",
              'field_story_medium_image_title' => isset($node_load_data->field_story_medium_image['und'][0]['title']) ? $node_load_data->field_story_medium_image['und'][0]['title'] : "",
              'field_story_small_image_alt' => isset($node_load_data->field_story_small_image['und'][0]['alt']) ? $node_load_data->field_story_small_image['und'][0]['alt'] : "",
              'field_story_small_image_title' => isset($node_load_data->field_story_small_image['und'][0]['title']) ? $node_load_data->field_story_small_image['und'][0]['title'] : "",
              'field_story_extra_large_image_alt' => isset($node_load_data->field_story_extra_large_image['und'][0]['alt']) ? $node_load_data->field_story_extra_large_image['und'][0]['alt'] : "",
              'field_story_extra_large_image_title' => isset($node_load_data->field_story_extra_large_image['und'][0]['title']) ? $node_load_data->field_story_extra_large_image['und'][0]['title'] : "",
              'node_obj' => $node_smily_data,
              'webcast_val' => $webcast_val,
              'is_spnoser' => $is_sponsor,
            );
        }
    }
    return !empty($final_widget_array) ? $final_widget_array : array();
}

/**
 * Function gives flag of view which is used in widget popup.
 * 
 * @param array $view
 * @return boolean
 */
function is_widget_views($view) {
    $flag = FALSE;
    $view_name = array(
      'section_wise_draggable_content_order',
      'section_wise_content_ordering_list',
      'story_widget',
      'widget_anchors_listing',
      'photo_carousel_widget',
      'poll_widget',
      'home_page_feature_widget',
      'photo_carousel_widget',
      'so_sorry',
      'special_auto_review_widget',
      'yearender_top_news_and_top_videos',
      'most_read_widget',
      'special_how_i_made_it',
    );
    if (in_array($view->name, $view_name)) {
        $flag = TRUE;
    }
    return $flag;
}

/**
 * Function used to get weight.
 * 
 * @return array
 */
function _get_custom_weight_from_table() {
    $type_in_url = $_GET['type'];
    $actual_weight_type = 'All';
    $types = array("story", "videogallery", "photogallery");
    if (in_array($type_in_url, $types)) {
        $actual_weight_type = $type_in_url;
    }
    $view = views_get_current_view();
    foreach ($view->result as $view_result_data) {
        $required_node[] = $view_result_data->node_itg_widget_order_nid;
    }
    $itg_widget_order_data = db_select('itg_widget_order', 'iwo')
      ->fields('iwo', array('nid', 'weight'))
      ->condition('iwo.cat_id', $_GET['category_tid'])
      ->condition('iwo.nid', $required_node, 'IN');
    $itg_widget_order_data->condition('iwo.content_type', $actual_weight_type)
      ->condition('iwo.widget', 'section_wise_widget');
    $actual_view_data = $itg_widget_order_data->execute()->fetchAllKeyed(0);
    return $actual_view_data;
}

/**
 * Function gives respective content type of widget.
 * 
 * @param string $widget_name
 * @return string
 */
function _get_content_type_for_widget($widget_name) {
  $content_type = array('story', 'videogallery', 'photogallery');
  switch ($widget_name) {
    case 'top_stories_widget':
      $content_type = array('story', 'breaking_news', 'mega_review_critic', 'videogallery', 'photogallery');
      break;
    case 'dont_miss_content_widget':
      $content_type = array('story', 'videogallery', 'photogallery', 'breaking_news');
      break;
    case 'we_may_suggest_widget':
      $content_type = array('story', 'videogallery', 'photogallery', 'breaking_news');
      break;
    case 'home_page_feature_widget':
      $content_type = array('story', 'videogallery', 'photogallery', 'breaking_news');
      break;
    case 'most_popular_widget':
      $content_type = array('story', 'breaking_news');
      break;
    case 'big_story_format_widget':
      $content_type = array('story', 'videogallery', 'photogallery', 'breaking_news');
      break;
  }
  return $content_type;
}

/**
 * Form ids of widget popup order reorder form.
 * 
 * @return string
 */
function itg_widget_order_reorder_form() {
    $forms = array(
      'views_form_story_widget_trending_videos_widget', // Trending video widget
      'views_form_story_widget_most_popular_widget', // most popular
      'views_form_story_widget_top_takes_video_widget', // top takes
      'views_form_story_widget_watch_right_now_widget', // watch right now
      'views_form_story_widget_page_2', // top story
      'views_form_home_page_feature_widget_page_2',
      'views_form_photo_carousel_widget_photo_carousel', // photo carousel
      'views_form_photo_carousel_widget_video_carousel',
      'views_form_widget_anchors_listing_anchors_listing_widget',
      'views_form_section_wise_content_ordering_list_we_may_suggest_widget',
      'views_form_section_wise_top_story_widget_order_reorder_page_1'
    );
    return $forms;
}

/**
 * Function gives widget name crossponding to veiw and page name.
 * 
 * @param string $view_name
 * @param string $page_name
 * @return string
 */
function _get_widget_name($view_name, $page_name) {
    $widget = "";
    if (($view_name == 'views_form_section_wise_draggable_content_order_page' || $view_name == 'views_form_section_wise_content_ordering_list_page') && $page_name == 'page') {
        $widget = 'section_wise_widget';
    } elseif ($view_name == "views_form_story_widget_page" && $page_name == "page_1") {
        $widget = 'top_stories_widget';
    } elseif ($view_name == "views_form_story_widget_page" && $page_name == "trending_videos") {
        $widget = 'trending_videos_widget';
    } elseif ($view_name == "views_form_story_widget_page" && $page_name == "most_popular") {
        $widget = 'most_popular_widget';
    } elseif ($view_name == "views_form_story_widget_page" && $page_name == "top_takes_video") {
        $widget = 'top_takes_video_widget';
    } elseif ($view_name == "views_form_story_widget_page" && $page_name == "watch_right_now") {
        $widget = 'watch_right_now_widget';
    } elseif ($view_name == "views_form_widget_anchors_listing_page" && $page_name == "anchors_listing_page") {
        $widget = 'anchors_listing_widget';
    } elseif ($view_name == "views_form_home_page_feature_widget_page" && $page_name == "page_1") {
        $widget = 'home_page_feature_widget';
    } elseif ($view_name == "views_form_photo_carousel_widget_page" && $page_name == "photo_carousel_list") {
        $widget = 'photo_carousel_list_widget';
    } elseif ($view_name == "views_form_photo_carousel_widget_page" && $page_name == "video_carousel_list") {
        $widget = 'video_carousel_list_widget';
    } elseif ($page_name == 'we_may_suggest_widget') {
        $widget = 'we_may_suggest_widget';
    } elseif ($page_name == 'most_popular_widget') {
        $widget = 'we_may_suggest_widget';
    } elseif ($page_name == 'big_story_format') {
        $widget = 'big_story_format_widget';
    } elseif ($page_name == 'photo_carousel_list') {
        $widget = 'photo_carousel_list_widget';
    } elseif ($page_name == 'video_carousel_list') {
        $widget = 'video_carousel_list_widget';
    } elseif ($page_name == 'dont_miss_content') {
        $widget = 'dont_miss_content_widget';
    } elseif ($view_name == "views_form_section_wise_top_story_widget_order_reorder_page" && $page_name == "page") {
        $widget = 'section_manual_order_widget';
    } 
    return $widget;
}

/**
 * Gives widget name from viewname and current display.
 * 
 * @param string $view_name
 * @param string $view_current_display
 * @return string
 */
function itg_widget_get_widget_name_from_views($view_name, $view_current_display) {
    $widget_name = "";
    if ($view_name == 'story_widget' && $view_current_display == 'page_2') {
        $widget_name = "top_stories_widget";
    }
    if ($view_name == 'home_page_feature_widget' && $view_current_display == 'page_2') {
        $widget_name = "home_page_feature_widget";
    }
    if ($view_name == 'photo_carousel_widget' && $view_current_display == 'photo_carousel') {
        $widget_name = "photo_carousel_list_widget";
    }
    if ($view_name == 'photo_carousel_widget' && $view_current_display == 'video_carousel') {
        $widget_name = "video_carousel_list_widget";
    }
    if ($view_name == 'story_widget' && $view_current_display == 'trending_videos_widget') {
        $widget_name = "trending_videos_widget";
    }
    if ($view_name == 'story_widget' && $view_current_display == 'most_popular_widget') {
        $widget_name = "most_popular_widget";
    }
    if ($view_name == 'story_widget' && $view_current_display == 'top_takes_video_widget') {
        $widget_name = "top_takes_video_widget";
    }
    if ($view_name == 'story_widget' && $view_current_display == 'watch_right_now_widget') {
        $widget_name = "watch_right_now_widget";
    }
    if ($view_name == 'widget_anchors_listing' && $view_current_display == 'anchors_listing_widget') {
        $widget_name = "anchors_listing_widget";
    }
    if ($view_name == 'section_wise_content_ordering_list' && $view_current_display == 'we_may_suggest_widget') {
        $widget_name = "we_may_suggest_widget";
    }
    if ($view_name == 'section_wise_top_story_widget_order_reorder' && $view_current_display == 'page_1') {
        $widget_name = "section_manual_order_widget";
    }
    return $widget_name;
}

/**
 * Function to delete nodes from widget and nodequeue.
 * @param int $nid
 */
function itg_widget_handle_unpublished_node($nid, $magazin_widget_condition = TRUE) {
    if ($nid) {
        if (function_exists('__itg_widget_helper_data_delete')) {
            __itg_widget_helper_data_delete($nid);
        }
        // List of all widget.
        // IF number of widget is increses then increse this list.  
        // Delete query for itg_widget_query.
        // Widgets are define above from which node is to be delete.
        try {
            $query = db_delete('itg_widget_order');
            $query->condition('nid', $nid);
            if ($magazin_widget_condition) {
                $query->condition('widget', 'issue_primary_category_magazin_widget', '!=');
            }
            $query->execute();
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage(), 'error');
        }

        try {
            $query = db_delete('itg_widget_order_section');
            $query->condition('nid', $nid);
            $query->execute();
        } catch (Exception $ex) {
            drupal_set_message($ex->getMessage(), 'error');
        }
    }
}

/**
 * Implement function for get primary category
 * @param int $nid
 */
function itg_widget_get_primary_cat($nid, $is_rss = FALSE) {
    $query = db_select('field_data_field_primary_category', 'primary_cat');
    $query->fields('primary_cat', array('field_primary_category_value'));
    $query->condition('primary_cat.entity_id', $nid, '=');
    if (!$is_rss) {
        $query->condition('primary_cat.bundle', 'story', '=');
    }
    $result = $query->execute()->fetchField();
    return $result;
}

/**
 * Function gives count of node with perticular widget.
 * 
 * @param int $nid
 * @param string $widget
 * @param int $cat_id (Added: add category filter for widget)
 * @return int
 */
function itg_widget_check_node_in_widget($nid, $widget) {
  $count = 0;
  if (!empty($nid) && !empty($widget)) {
    $query = db_select('itg_widget_order', 'iwo')
        ->fields('iwo', array('nid'))
        ->condition('iwo.nid', $nid)
        ->condition('iwo.widget', $widget);
    if (!empty($cat_id) && is_numeric($cat_id)) {
      $query->condition('cat_id', $cat_id);
    }
    $count = $query->execute()->rowCount();
  }
  return $count;
}

/**
 * This function use for update key candidate election status
 */
function update_keycandidate_status() {
    $status = $_POST['status'];
    $fields_name = $_POST['fname'];
    $fields_name = explode('-', $fields_name);
    db_update('itg_widget_order')
      ->fields(array('extra' => $status,))
      ->condition('widget', 'key_candidate')
      ->condition('nid', $fields_name[1])
      ->condition('cat_id', $fields_name[2])
      ->condition('state', $fields_name[3])
      ->execute();

    exit(1);
}

function itg_content_inactive_videogallery() {
  $current_time = date("Y-m-d H:i:s");
  //set content type
  //$content_type = array('story', 'videogallery'); 
  $content_type = array("videogallery");
  
  $itg_query = db_select('node', 'n');
  $itg_query->leftJoin('field_data_field_story_expiry_date', 'expiry', 'n.nid = expiry.entity_id');
  $itg_query->fields('expiry', array('field_story_expiry_date_value'));
  $itg_query->fields('n', array('nid'));
  $itg_query->condition('n.type', $content_type, 'IN');
  $itg_query->condition('n.status', 1);
  $itg_query->condition('expiry.field_story_expiry_date_value', $current_time, '<');
  $itg_query->isNotNull('expiry.field_story_expiry_date_value');
  $itg_result = $itg_query->execute()->fetchAll();
  //itg_watchdog("nodes_expiry" , $itg_result);
  foreach ($itg_result as $itg_val) {
    $node_data = node_load($itg_val->nid);
    $nodeid[] = $node->nid;
    $node_data->status = 0;
      if(function_exists('itg_videogallery_node_publish_to_unpublish')) {
        itg_videogallery_node_publish_to_unpublish($node->nid);
      }
    node_save($node_data);
    itg_widget_handle_unpublished_node($node->nid);
  }
  //itg_watchdog("nodes_expiry" , $nodeid);
}

/**
 * Function to use insert data into custom table.
 * @param array $form_state
 * @param string $widget_name
 */
function itg_save_section_top_story_widget_data($form_state, $widget_name) {
  $selected_node = $form_state['selection'];
  $category_id = $_GET['category_tid'];
  if (empty($category_id) || $category_id == 0) {
    return;
  }
  if (count($selected_node)) {
    foreach ($selected_node as $node) {
      $is_node_in_widget = itg_widget_check_node_in_widget($node, $widget_name, $category_id);
      if (!$is_node_in_widget) {
        itg_widget_insert_widget_data($node, $widget_name, $category_id);
      }
    }
  }
}
