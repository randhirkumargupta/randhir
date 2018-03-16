<?php

/**
 * @file
 * Helper file for menu manager
 */

/**
 * Function return string matched child element of vocuvolary category_management.
 * @param string $string
 * @return json
 */
function itg_menu_manager_get_child_under_category_management($string) {
  //code add by shravan :: 24 sept 2017
  $match_terms_query = db_select('taxonomy_term_data', 'ttd');
  $match_terms_query->fields('ttd', array('tid', 'name'));
  $match_terms_query->Join('itg_category_manager', 'icm', 'icm.tid = ttd.tid');
  $match_terms_query->condition('icm.status', 1);
  $match_terms_query->condition('ttd.name', '%' . db_like($string) . '%', 'LIKE');
  $match_terms_query->range(0, 20);

  $match_terms = $match_terms_query->execute()->fetchAll();

  foreach ($match_terms as $match_terms_data) {
    $parents = array_reverse(taxonomy_get_parents_all($match_terms_data->tid));
    $top_most_parent = "";
    if (count($parents) > 1) {
      $top_most_parent = $parents[0]->name . " <b> >> </b> ";
    }
    $children[$match_terms_data->name . " [tid: " . $match_terms_data->tid . "]"] = $top_most_parent . $match_terms_data->name . " [tid: " . $match_terms_data->tid . "]";
  }
  return drupal_json_output($children);
}

/**
 * Function create options for itg_menu_manager field.
 * @param string $machine_name
 * @return array
 */
function itg_menu_manager_get_taxonomy_term_options($machine_name) {
  $options = array();

  $options_source = taxonomy_get_tree(CATEGORY_MANAGMENT, 0, 1);
  $options[0] = '-Select-';
  foreach ($options_source as $item) {
    if (itg_category_manager_term_state($item->tid) && module_exists('itg_category_manager') && function_exists('itg_category_manager_term_state')) {
      // Check for active categories
      $key = $item->tid;
      $value = $item->name;
      $options[$key] = $value;
    }
  }

  return $options;
}

/**
 * Function returns matched child of term.
 * @param int $tid
 * @param string $string
 * @return json
 */
function itg_menu_manager_get_child($tid, $string) {
  if (!empty($tid) && $tid) {
    $term = array();
    $children = array();
    // Get all child under the section.
    $all_children = itg_menu_manager_taxonomy_get_children_all($tid, CATEGORY_MANAGMENT);
    foreach ($all_children as $term_data) {
      $term[] = $term_data->tid;
    }
    if (!empty($term)) {
      // Get autocomplete string matched children.
      $match_terms_query = db_select('taxonomy_term_data', 'ttd')
            ->fields('ttd', array('tid', 'name'))
            ->condition('ttd.tid', array($term), 'IN')
            ->condition('ttd.name', '%' . db_like($string) . '%', 'LIKE');

      $match_terms = $match_terms_query->execute()->fetchAll();

      foreach ($match_terms as $match_terms_data) {
        $parents = array_reverse(taxonomy_get_parents_all($match_terms_data->tid));
        $top_most_parent = "";
        if ($match_terms_data->tid != $parent[0]->tid) {
          $top_most_parent = $parents[0]->name . ">>";
        }
        $children[$match_terms_data->name . " [tid: " . $match_terms_data->tid . "]"] = $top_most_parent . $match_terms_data->name . " [tid: " . $match_terms_data->tid . "]";
      }

      return drupal_json_output($children);
    }
  }
}

/**
 * Function to get all child of tid.
 * @param int $tid
 * @param int $vid
 * @param string $key
 * @return array
 */
function itg_menu_manager_taxonomy_get_children_all($tid, $vid = 0, $key = 'tid') {
  $child = taxonomy_get_children($tid, $vid, $key);
  $result = array();
  foreach ($child as $term_key => $data) {
    $result[$term_key] = $data;
    $below = itg_menu_manager_taxonomy_get_children_all($term_key, $vid, $key);
    if (!empty($below)) {
      foreach ($below as $nt => $nd) {
        $result[$nt] = $nd;
      }
    }
  }
  return $result;
}

/**
 * Ajax callback funtion which replace tite field for autocomplete path.
 * @global array $messages
 * @param array $form
 * @param type $form_state
 * @return array
 */
function get_section_update($form, &$form_state) {
  global $messages;
  unset($messages);
  unset($form_state['input']['title'], $form_state['values']['title']);
  $section = $form_state['values']['sections'];
  // In case of internal category pool search is reaquired but not in external case.
  if ($form_state['values']['url_type'] == 'internal') {
    $form['title']['#autocomplete_path'] = 'itg-menu-manager/get-child/autocomplete/' . $section;
  } else {
    // Unset autocomplete_path if already attached from ajax.
    unset($form['title']['#autocomplete_path']);
  }
  return $form;
}

/**
 * returns drupal path of perticular term.
 *
 * @param array $form
 * @param array $form_state
 * @return string
 */
function get_url_of_current_term($form, &$form_state) {
  //unset($form_state['input']['url'], $form_state['values']['url']);
  $title = $form_state['values']['title'];
  // get values beween squre breaket.
  preg_match_all("/\[([^\]]*)\]/", $title, $matches);
  // get tid
  $term_tid_array = explode("tid:", $matches[1][0]);
  $link = drupal_lookup_path('alias', 'taxonomy/term/' . trim($term_tid_array[1]));
  if (empty($link)) {
    $link = 'taxonomy/term/' . trim($term_tid_array[1]);
  }
  $form['url']['#value'] = !empty($link) ? $link : $form_state['values']['url'];
  return $form;
}

/**
 * Function is callback, which decide section is menadatory or not according to level.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function decide_section($form, &$form_state) {

  $menu_level = $form_state['values']['menu_level'];
  $url_type = $form_state['values']['url_type'];
  $sections = $form_state['values']['sections'];

  // Make section required.
  if ($menu_level == 'third' && $url_type == 'internal') {
    $form['sections']['#required'] = TRUE;
  }

  // In case of external url , not need autocomplete path
  // Hide sections field as not required in case of external url
  if ($url_type == 'external') {
    unset($form['title']['#ajax']);
    unset($form['title']['#autocomplete_path']);
  }

  if ($sections == 0 && $menu_level == 'third' && $url_type == 'internal') {
    $form['title']['#attributes'] = array(
      'disabled' => "disabled",
    );
  }
  return $form;
}

/**
 * Function is callback, which decide title autosuggest.
 *
 * @param array $form
 * @param type $form_state
 * @return array
 */
function add_or_remove_autocomplete($form, $form_state) {

  if ($form_state['values']['url_type'] == 'external') {
    unset($form['title']['#ajax']);
    unset($form['title']['#autocomplete_path']);
  }
  return $form;
}

/**
 * Function to get under vocabulary.
 * @param int $vid
 * @return array
 */
function _get_all_terms_under_vocabulary($vid) {
  if (!empty($vid)) {
    $query = db_select('taxonomy_term_data', 'tdd');
    $query->fields('tdd', array('tid'));
    $query->condition('tdd.vid', $vid);
    return $query->execute()->fetchAll();
  }
  return array();
}

/**
 * function returns array of second level menu
 * @return type
 */
function get_second_level_menu($level = 'second') {
  $query = db_select('itg_menu_manager', 'imm');
  $query->leftJoin('itg_category_manager', 'icm', 'icm.tid=imm.tid');
  $query->fields('imm')->condition('imm.menu_level', $level);
  $db_or = db_or()->condition('icm.status', 1)->condition("imm.url_type", "external");
  $query->orderBy('imm.weight', 'ASC');
  return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
}

/**
 * function returns array of third level menu
 * @return type
 */
function get_third_level_menu() {
  $arg = arg();
  $node_data = array();
  $section_id = 0;

  // handling for ip pages
  $links_string = variable_get('menu_manager_custom_url');
  $links_array = explode(",", $links_string);
  if (in_array(arg(1), $links_array)) {
    $node_data = node_load(arg(1));
  }

  // for best college
  $url_get = explode('/', $_SERVER['REQUEST_URI']);
  if (isset($url_get[2]) && $url_get[1] == 'bestcolleges') {
    if ($arg[0] == 'taxonomy') {
      $section_id = $arg[2];
    } else {
      $term_name = "Bestcolleges " . $url_get[2];
      $term_data = taxonomy_get_term_by_name($term_name);
      $tid = array_pop($term_data)->tid;
      $section_id = ($tid) ? $tid : '';
    }

    $parents = taxonomy_get_parents_all($section_id);
    if (count($parents) > 1) {
      $section_id = end($parents)->tid;
    }
  }

  // end best collehe
  // condition for itg theme
  if (isset($arg[2])) {
    if ($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2])) {
      $section_id = $arg[2];
      $parents = taxonomy_get_parents_all($section_id);
      if (count($parents) > 1) {
        $section_id = end($parents)->tid;
      }
    }
  }
  if ($arg[0] == 'node' && is_numeric($arg[1])) {
    $data = db_select('field_data_field_primary_category', 'fpc')
                ->fields('fpc', array('field_primary_category_value'))
                ->condition('fpc.entity_id', $arg[1])
                ->execute()->fetchField();
    if (!empty($data)) {
      $parents = taxonomy_get_parents_all($data);
      if (count($parents) > 1) {
        $section_id = end($parents)->tid;
      } else {
        $section_id = $data;
      }
    }
  }
  // condition for itgadmin theme
  else if (isset($_GET['section'])) {
    $section_id = $_GET['section'];
  } else if (isset($node_data->field_page_section['und'][0]['tid']) && $node_data->field_page_section['und'][0]['tid'] == variable_get('ipl_for_widget')) {
    $section_id = variable_get('ipl_for_widget');
  } else if ($arg[0] == 'photo-list' || $arg[0] == 'video-list') {
    $section_id = variable_get('ipl_for_widget');
  } else if ($section_id == "") {
    $node = itg_videogallery_get_term(arg(1));

    if (in_array(variable_get('ipl_for_widget'), $node)) {
      $section_id = variable_get('ipl_for_widget');
    }
  }

  if ($section_id) {
    $query = db_select('itg_menu_manager', 'imm')
          ->fields('imm')
          ->condition('imm.menu_level', 'third')
          ->condition('imm.section_id', $section_id)
          ->orderBy('imm.weight', 'ASC');
    return $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
}

function itg_menu_manager_webform_js_submit(&$form, &$form_state) {
  // define the $sid variable (submission id from webform)
  $sid = $form_state['values']['details']['sid'];
  // if we have a sid then we know the form was properly submitted, otherwise, we'll just return the existing $form array
  if ($sid) {
    // create an array up with the confirmation message, retreived from the webform node
    $confirmation = t("You feedback has been recived. Thank you!");
    drupal_set_message($confirmation);
    $form['submitted']['feedback']['#default_value'] = "";
    $form['submitted']['feedback']['#value'] = "";
    // return the confirmation message
    return $form;
  } else {
    // return the form
    return $form;
  }
}

/**
 * {@inheritdoc}
 */
function itg_menu_manager_custom_submit($form, &$form_state) {
  cache_clear_all('menu_level_data', 'cache', TRUE);
  // Current display for indentifing the view page (Widget name).
  //$current_display = $form_state['build_info']['args'][0]->current_display;
  // Below view_name will use to get widget name.
  // Take draggable view input value after submit the form.
  $draggable_view_data = $form_state['input']['draggableviews'];
  // Category tid from url.
  $menu_level = arg(1);
  if ($menu_level == 'second' || $menu_level == 'vertical') {
    $total_changed_weight = 0;

    foreach ($draggable_view_data as $weight_cal_key => $weight) {
      $total_changed_weight = $weight['weight'] + $total_changed_weight;
    }

    if ($total_changed_weight) {
      // Now insert new entry in itg_widget_order table of combination
      foreach ($draggable_view_data as $key => $menu_data) {
        try {
          db_merge('itg_menu_manager')
                ->key(array(
                  'tid' => $menu_data['id'],
                  'menu_level' => $menu_level,
                ))
                ->fields(array(
                  'weight' => $menu_data['weight'],
                ))
                ->execute();
          //drupal_set_message("Order has been updated");
        } catch (Exception $ex) {
          drupal_set_message($ex->getMessage());
        }
      }
    }
  } else if ($menu_level == 'third') {
    $section_id = $_GET['section_id'];
    $total_changed_weight = 0;

    foreach ($draggable_view_data as $weight_cal_key => $weight) {
      $total_changed_weight = $weight['weight'] + $total_changed_weight;
    }

    if ($total_changed_weight) {
      // Now insert new entry in itg_widget_order table of combination
      foreach ($draggable_view_data as $key => $menu_data) {
        try {
          db_merge('itg_menu_manager')
                ->key(array(
                  'tid' => trim($menu_data['id']),
                ))
                ->fields(array(
                  'weight' => $menu_data['weight'],
                ))
                ->execute();
          drupal_set_message("Order has been updated");
        } catch (Exception $ex) {
          drupal_set_message($ex->getMessage());
        }
      }
    }
  }
}

/**
 * Function handling link output of menus.
 * @global type $base_url
 * @param type $menu_data
 * @param type $argument
 * @param type $load_parent
 * @param type $amp
 * @return array
 */
function itg_menu_manager_get_menu($menu_data, $argument, $load_parent = array(), $amp = NULL) {
  global $base_url;
  $menu_link_data_array = array();
  $parent_key_of_third_level = !empty($load_parent) ? $load_parent[0] : 0;
  $title_array = explode("[tid", $menu_data['db_data']['title']);
  $link_url = $active = $image_class = "";
  $target = "_self";
  $link_text = $link_title_for_vertical = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name : $title_array[0];
  $url_type = isset($menu_data['db_data']['url_type']) ? $menu_data['db_data']['url_type'] : "";
  $display_icon = isset($menu_data['db_data']['display_icon']) ? $menu_data['db_data']['display_icon'] : "";
  $db_target = isset($menu_data['db_data']['target']) ? $menu_data['db_data']['target'] : "";
  $tid = isset($menu_data['db_data']['tid']) ? $menu_data['db_data']['tid'] : 0;
  $active_cls = $parent_class = "notactive";
  $icon_fid = (int) $menu_data['db_data']['menu_name'];
  $display_icon_attribute = $display_icon;
  $sponser_logo_uri = !empty($menu_data['term_load']->field_sponser_logo['und'][0]['uri']) ? $menu_data['term_load']->field_sponser_logo['und'][0]['uri'] : 0;
 
  $vertical_menu_icon = "";
  $sponser_logo_alt = !empty($menu_data['term_load']->field_sponser_logo['und'][0]['alt']) ? $menu_data['term_load']->field_sponser_logo['und'][0]['alt'] : '';
  $sponser_logo_title = !empty($menu_data['term_load']->field_sponser_logo['und'][0]['title']) ? $menu_data['term_load']->field_sponser_logo['und'][0]['title'] : '';
  // handel case for external menu.
  // display_icon is true and icon_fid is set then show icon other wise title.
  if ($url_type == 'external' && $display_icon && $icon_fid) {
    $int_value = (int) $icon_fid;
    if ($int_value) {
      $icon_object = file_load((int) $icon_fid);
      // Set icon for internal menu used for vertical menu.
      if (!empty($amp)) {
        $link_text = $vertical_menu_icon = "<img width='152' height='85' title='" . $link_title_for_vertical . "'  src='" . file_create_url($icon_object->uri) . "' alt='amp-image' />"; 
      } else {
        //$img_path = image_style_url('menu_manager_icons' , $icon_object->uri);
        $link_text = $link_text_mobile = $vertical_menu_icon =   "<img width='48' height='32' title='" . $link_title_for_vertical . "'  src='" . file_create_url($icon_object->uri) . "' alt='".$link_title_for_vertical."' />";
      }
      if (!empty($icon_object->uri)) {
        $image_class = "has-image";
      }
    }
  }
  // Handle case for default image
  if ($url_type == 'external' && $display_icon && $icon_fid == "notFound") {
    if (!empty($amp)) {
      $link_text = $vertical_menu_icon = "<img width='110' height='37' title='" . $link_title_for_vertical . "' src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all_152_37.png' alt='amp-image' />";
    } else {
      $link_text = $link_text_mobile = $vertical_menu_icon = "<img  title='" . $link_title_for_vertical . "' src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all_110_37.jpeg' alt='' />";
      $image_class = "has-image";
    }
  }

  if ($url_type == 'internal' && $display_icon) {
    if (is_string($sponser_logo_uri) && !empty($sponser_logo_uri)) {
      if (!empty($amp)) {
        $link_text = $vertical_menu_icon = "<img width='152'  height= '85' src='" . file_create_url($sponser_logo_uri) . "' alt='amp-image' />"; 
        $image_class = "has-image";
      } else {
        //$img_path = image_style_url('menu_manager_icons' , $sponser_logo_uri);
        $link_text = $vertical_menu_icon =   "<img width='48' height='32' title='" . $sponser_logo_title . "'  src='" . file_create_url($sponser_logo_uri) . "' alt='".$sponser_logo_alt."' />";
        $link_text_icon = "<span class='menu-icons hidden-desktop'><img width='48' height='32' title='" . $sponser_logo_title . "'  src='" . file_create_url($sponser_logo_uri) . "' alt='".$sponser_logo_alt."' /></span>";
        $image_class = "has-image";
      }
    }
  }

  if (!empty($menu_data['db_data']['menu_level']) && $menu_data['db_data']['menu_level'] == 'second') {
    $temp_data = taxonomy_term_load($tid);
    $link_text_icon_uri = '';
    if (empty($link_text_mobile)) {
      $link_text_mobile = isset($temp_data->name) ? $temp_data->name : $title_array[0];
    }
    
    if (!empty($temp_data->field_sponser_logo['und'][0]['uri']) && file_exists($temp_data->field_sponser_logo['und'][0]['uri'])) {
      $link_text_icon_uri = $temp_data->field_sponser_logo['und'][0]['uri'];
      $img_path_new = file_create_url($link_text_icon_uri);
      $link_text_icon = "<span class='menu-icons hidden-desktop'><img width='48' height='32' title='" . $link_title_for_vertical . "'  src='" . $img_path_new . "' alt='" . $link_title_for_vertical . "' /></span>";
    }
  }

  $sponsored_class = ($menu_data['db_data']['extra'] == 'Yes') ? "sponsored-active" : "";
  // if tid is not 0 then its internal url
  if (($tid && $url_type == 'internal')) {
    $link_url = "taxonomy/term/$tid";
    if ($link_url == current_path()) {
      $active_cls = "active";
    }
  } else {
    $link_url = $menu_data['db_data']['url'];
  }

  // manage target
  if (trim($db_target) == 'new_window') {
    $target = "_blank";
  }

  if ($tid == $parent_key_of_third_level) {
    $parent_class = "active";
  }

  if (!empty($argument[1]) && isset($argument[1])) {
    $arg1 = $argument[1];
    $urlalise = drupal_get_path_alias("node/$arg1");
    $real_path_alise = ($urlalise) ? $urlalise : "node/$arg1";
    if (!empty($link_url)) {
      $link_url_array = explode('/', $link_url);
      $link_url_end = end($link_url_array); //shravan
      if ($link_url_end == $real_path_alise) {
        $active = 'active';
      }
    }
  }

  // Prepare variables
  $menu_link_data_array['image_class'] = $image_class;
  $menu_link_data_array['link_text'] = $link_text;
  $menu_link_data_array['link_url'] = $link_url;
  $menu_link_data_array['target'] = $target;
  $menu_link_data_array['active'] = $active;
  $menu_link_data_array['sponsored_class'] = $sponsored_class;
  $menu_link_data_array['parent_class'] = $parent_class;
  $menu_link_data_array['active_cls'] = $active_cls;
  $menu_link_data_array['icon'] = $vertical_menu_icon;
  $menu_link_data_array['link_title_for_vertical'] = $link_title_for_vertical;
  $menu_link_data_array['url_type'] = "url-type-" . $url_type;
  $menu_link_data_array['display_icon'] = $display_icon_attribute;
  $menu_link_data_array['link_text_icon'] = $link_text_icon;
  $menu_link_data_array['link_text_mobile'] = $link_text_mobile;
  return $menu_link_data_array;
}

/**
 * {@inheritdoc}
 */
function _delete_term_from_menu_manager($tid) {
  try {
    db_delete('itg_menu_manager')
          ->condition('tid', $tid)
          ->execute();
  } catch (Exception $ex) {
    drupal_set_message($ex->getMessage());
  }
}

/**
 * Function which returns count of rows w.r.t menu_manager data.
 *
 * @param string $menu_level
 * @param int $section_id
 * @param string $url_type
 * @param string $term_id
 * @return int
 */
function _get_itg_menu_data($menu_level, $section_id, $url_type, $term_id) {
  $db_query = db_select('itg_menu_manager', 'imm')
        ->fields('imm', array('tid'))
        ->condition('imm.menu_level', $menu_level)
        ->condition('imm.section_id', $section_id)
        ->condition('imm.url_type', $url_type)
        ->condition('imm.tid', $term_id);
  $result = $db_query->execute()->rowCount();
  return $result;
}
