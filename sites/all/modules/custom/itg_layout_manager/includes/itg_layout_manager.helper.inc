<?php
/**
 * @file
 * Inc file for All common function of layout manager.
 *
 */

/**
 * Get template name by section name
 * @return string
 */
function get_template_name_by_section_name($section_name) {
  $query = db_select('itg_layout_tpl', 'tpl');
  $query->fields('tpl', array('template_name'));  
  $query->condition('section_name', $section_name)
        ->condition('status', 1);
  $query->orderBy('tpl.id', 'DESC')->range(0,1);//LIMIT to 1 records

  return $query->execute()->fetchField();
}

/**
 * Get All itg footer menu 
 * @return array
 */
function get_itg_footer_menu() {  
  $data['publications_footer'] = menu_tree('menu-itg-publications-menu-foote');
  $data['distribution_footer'] = menu_tree('menu-itg-distribution-menu-foote');
  $data['education_footer'] = menu_tree('menu-itg-education-menu-footer');
  $data['events_footer'] = menu_tree('menu-itg-events-menu-footer');
  $data['music_footer'] = menu_tree('menu-itg-music-menu-footer');
  $data['printing_footer'] = menu_tree('menu-itg-printing-menu-footer');
  $data['radio_footer'] = menu_tree('menu-itg-radio-menu-footer');
  $data['shopping_footer'] = menu_tree('menu-itg-shopping-menu-footer');
  $data['syndication_footer'] = menu_tree('menu-itg-syndication-menu-footer');
  $data['television_footer'] = menu_tree('menu-itg-television-menu-footer');
  $data['useful_footer'] = menu_tree('menu-itg-useful-menu-footer');
  $data['welfare_footer'] = menu_tree('menu-itg-welfare-menu-footer');
  $data['footer-top-menu'] = menu_tree('menu-itg-main-menu-footer');
  return $data;
}

/**
 * Get all widgets list for layout setting page
 * @param string $section_name
 * @param string $template_name 
 * @return array
 */
function get_all_widgets_list_by_setting_page($title) {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));  
  $query->condition('type', 'itg_template_widgets');
  $query->condition('title', $title);
  $query->orderBy('n.nid', 'DESC')->range(0,1);//LIMIT to 1 records
  $nid = $query->execute()->fetchField();
  $node = node_load($nid);
  $widget_array = $node->field_itg_widget_name[LANGUAGE_NONE];
  
  return $widget_array;
}

/**
 * check template for section
 * @param string $section_name
 * @param string $template_name 
 * @return int $id
 */
function check_template_of_section($section_name, $template_name) {  
  $query = db_select('itg_layout_tpl', 'tpl');
  $query->fields('tpl', array('id'));  
  $query->condition('section_name', $section_name)
        ->condition('template_name', $template_name, '!=');
  $query->orderBy('tpl.id', 'DESC')->range(0,1);//LIMIT to 1 records
  
  $id = $query->execute()->fetchField();
  
  return $id;
}

/**
 * render itg widget block by widget name 
 * @param string $widget_name 
 * @return array $render_array
 */
function get_itg_widget($widget_name, $widget_info = 'custom', $filter_url = NULL) {

  $widget_info = explode('|', $widget_info);
  
  if (isset($widget_name) && $widget_name == 'section_wise_order') {
    return create_setion_widgets($filter_url, $widget_info[1]);
  }
  else if (isset($widget_name) && $widget_name == 'custom_html_widgets') {
    return get_html_custom_widget($filter_url);    
  }
  else if (isset($widget_name) && $widget_name == 'custom_content_widgets') {
    return itg_custom_widget_ordering_data_from_title($filter_url);    
  }
  else if (isset($widget_name) && $widget_name == 'highlights') {
    return get_highlights_widget($filter_url);    
  }
  else if (isset($widget_name) && $widget_name == 'section_widget2_wise_order') {
    return create_setion_widget2($filter_url);
  }
  else if (isset($widget_name) && ($widget_name == 'photo_list_of_category' || $widget_name == 'video_list_of_category')) {   
    if (isset($widget_name) && ($widget_name == 'photo_list_of_category')) {
      $block = 'block';
    }
    
    if (isset($widget_name) && ($widget_name == 'video_list_of_category')) {
      $block = 'block_1';
    }
    
    return views_embed_view($widget_name, $block, $filter_url);
  }
  else if ($widget_info[0] == 'view') {
    return views_embed_view($widget_name, $widget_info[1], $widget_info[2]);
  }
  elseif (isset($widget_name) && $widget_name == 'recommended_anonymous_user') {
    //itg_front_end_common/recommended_anonymous_user
    $block = block_load('itg_front_end_common', $widget_name);
    $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
    return render($render_array);
  }
  else {
    if($widget_name=='custom_ask_expert_form_block') {
      $block = block_load('itg_ask_expert', $widget_name);
    } else {
        $block = block_load('itg_widget', $widget_name);
    }   
    $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
    
    return render($render_array);
  }
  
}

/**
 * Get id of itg_layout_manager
 * @param int $layout_id
 * @param string $block_name 
 * @return int $id
 */
function get_layout_manager_id($layout_id, $block_name) {
  $query = db_select('itg_layout_manager', 'layout');
  $query->fields('layout', array('id'));  
  $query->condition('layout_id', $layout_id)
        ->condition('block_name', $block_name);  
  $id = $query->execute()->fetchField();
  
  return $id;
}

/**
 * Get template name list of layouts directory
 * @param string $tpl_dir 
 * @return array $data
 */
function get_template_name($tpl_dir) {
  
  $dir = getcwd().'/'.drupal_get_path('theme', FRONT_THEME_NAME) . '/templates/layouts/'.$tpl_dir;
  
  $scanned_directory = array_diff(scandir($dir, 1), array('..', '.'));
  
  $data = array("" => "-- Template --");
  
  foreach ($scanned_directory as $key => $val) {
    $tpl = substr($val,0,-8);
    $data[$tpl] = $tpl;    
  }
  
  return $data;
}


/**
 * Get layout details by section_name and template_name for front and admin
 * @param string $section_name
 * @param string $template_name 
 * @return array $data
 */
function get_layout_details_by_block_name($section_name, $template_name, $status,$block_name) {
  
  if ($status == 'admin') {
    //Get last layout setting
    $query = db_select('itg_layout_tpl', 'tpl');
    $query->fields('tpl', array('id', 'status'));  
    $query->condition('section_name', $section_name)
          ->condition('template_name', $template_name)
          ->condition('block_name',$block_name,'IN');
    $query->orderBy('tpl.id', 'DESC')->range(0,1);

    $last_tpl = $query->execute()->fetchField();
  }
  
  //Get layout setting details info
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_manager', array('widget_name', 'block_name', 'block_title', 'widget_info', 'filter_url'));  
  $itg_query->join('itg_layout_manager', 'layout_manager', 'layout_tpl.id = layout_manager.layout_id');  
  $itg_query->condition('layout_tpl.section_name', $section_name);    
  $itg_query->condition('layout_tpl.template_name', $template_name);
  $itg_query->condition('block_name',$block_name,'IN');
  
  //condition for front
  if ($status == 'front') {
    $itg_query->condition('layout_tpl.status', 1);
  } //condition for admin
  elseif ($status == 'admin') {
    $itg_query->condition('layout_tpl.id', $last_tpl);     
  }
  
  $itg_result = $itg_query->execute()->fetchAll();
  
  foreach ($itg_result as $itg_val) {
    $filter_url = $itg_val->filter_url;
    // for widget display name
    if (!empty($itg_val->widget_name)) {
      $widget_info_array = explode('|', $itg_val->widget_info);
      if($widget_info_array[1] !="" &&  $widget_info_array[1] !="undefined") {
        $result['widget_display_name'] = '-'.$widget_info_array[1];  
      } else {
          $result['widget_display_name'] = "";  
      }
    }
    
    $result['widget_name'] = $itg_val->widget_name;
    $result['block_title'] = "";
    if ($status == 'front' && $itg_val->widget_name == 'section_wise_order') { // for section card widgets
      if (!empty($itg_val->block_title)) {
        $result['block_title'] = l($itg_val->block_title, 'taxonomy/term/'.$filter_url);
      }
      $result['more_url'] = l('More[+]', 'taxonomy/term/'.$filter_url);
    }else {
      $result['block_title'] = $itg_val->block_title; //for default widgets
    }
    
    // for photo section and video section
    if ($status == 'front' && ($itg_val->widget_name == 'photo_list_of_category' || $itg_val->widget_name == 'video_list_of_category')) {
      $result['cat_id'] = $filter_url; // category id
      
      if (isset($_GET['category'])) {
        $filter_url = $_GET['category'];
      }
      else {
        // Temp code
       $filter_url =  get_first_category_of_media_widget(arg(2), $template_name, $itg_val->widget_name);
      }
    }
    
    if (isset($itg_val->widget_name)) {
      // get widget block     
      $widget = get_itg_widget($itg_val->widget_name, $itg_val->widget_info, $filter_url);
    } 
    else {
      $widget = '<p>Drag template widgets here !</p>';
    }
    
    $result['widget'] = $widget;
    
    $data[$itg_val->block_name] = $result;
  }
  
  return $data; 
  
}

/**
 * Get layout details by section_name and template_name for front and admin
 * @param string $section_name
 * @param string $template_name 
 * @return array $data
 */
function get_layout_details($section_name, $template_name, $status) {
 
  if ($status == 'admin') {
    //Get last layout setting
    $query = db_select('itg_layout_tpl', 'tpl');
    $query->fields('tpl', array('id', 'status'));  
    $query->condition('section_name', $section_name)
          ->condition('template_name', $template_name);
    $query->orderBy('tpl.id', 'DESC')->range(0,1);

    $last_tpl = $query->execute()->fetchField();
  }
  
  //Get layout setting details info
  $itg_query = db_select('itg_layout_tpl', 'layout_tpl');
  $itg_query->fields('layout_manager', array('widget_name', 'block_name', 'block_title', 'widget_info', 'filter_url'));  
  $itg_query->join('itg_layout_manager', 'layout_manager', 'layout_tpl.id = layout_manager.layout_id');  
  $itg_query->condition('layout_tpl.section_name', $section_name);    
  $itg_query->condition('layout_tpl.template_name', $template_name);
  
  //condition for front
  if ($status == 'front') {
    $itg_query->condition('layout_tpl.status', 1);
  } //condition for admin
  elseif ($status == 'admin') {
     $itg_query->condition('layout_tpl.id', $last_tpl);     
  }
  
  $itg_result = $itg_query->execute()->fetchAll();
  $data = array();
  foreach ($itg_result as $itg_val) {
   
    $filter_url = $itg_val->filter_url;
    // for widget display name
    if (!empty($itg_val->widget_name)) {
      $widget_info_array = explode('|', $itg_val->widget_info);
      
      if(!empty($widget_info_array[1]) &&  $widget_info_array[1] !="undefined") {
        $result['widget_display_name'] = '-'.$widget_info_array[1];  
      } else{
          $result['widget_display_name'] = "";  
      }
    }
    
    $result['widget_name'] = $itg_val->widget_name;
    $result['block_title'] = "";
    
    if ($status == 'front' && $itg_val->widget_name == 'section_wise_order') { // for section card widgets
      if (!empty($itg_val->block_title)) {
        $result['block_title'] = l($itg_val->block_title, 'taxonomy/term/'.$filter_url);
      }
      $result['more_url'] = l('More[+]', 'taxonomy/term/'.$filter_url);
    }else {
      $result['block_title'] = $itg_val->block_title; //for default widgets
    }
    
    // for photo section and video section
    if ($status == 'front' && ($itg_val->widget_name == 'photo_list_of_category' || $itg_val->widget_name == 'video_list_of_category')) {
      $result['cat_id'] = $filter_url; // category id
      
      if (isset($_GET['category'])) {
        $filter_url = $_GET['category'];
      }
      else {
        // Temp code
       $filter_url =  get_first_category_of_media_widget(arg(2), $template_name, $itg_val->widget_name);
      }
      
      
    }
    
    if (isset($itg_val->widget_name)) {
      // get widget block     
      $widget = get_itg_widget($itg_val->widget_name, $itg_val->widget_info, $filter_url);
    } 
    else {
      $widget = '<p>Drag template widgets here !</p>';
    }
    
    $result['widget'] = $widget;
    
    $data[$itg_val->block_name] = $result;
  }
  
  return $data; 
  
}

/**
 * Display section widgets list
 * @param string $section_name
 * @param string $template_name 
 * @return string 
 */
function display_section_widgets_list($section_name, $template_name, $widget_type) {
  
  global $base_url;  
  
  // select query    
  $itg_query = db_select('itg_section_widgets_list', 'layout_tpl');
  $itg_query->fields('layout_tpl', array('id','category_name', 'category_id'));
  $itg_query->condition('layout_tpl.template_section_name', $section_name);
  $itg_query->condition('layout_tpl.template_name', $template_name);
  $itg_query->condition('layout_tpl.widget_type', $widget_type);
  $itg_query->orderBy('id', 'DESC');
  $itg_result = $itg_query->execute()->fetchAll();
  
  $content = category_widget_list($itg_result, $widget_type);
  
  return $content;
}



/**
 * Display section widgets list
 * @param string $section_name
 * @param string $template_name 
 * @return string 
 */
function category_widget_list($itg_result, $widget_name) {
  
  if ($widget_name == 'section_widget2_wise_order') {
    $content = '<ul id="templates-widget2-section" class="no-bullet pd-10 templates-widgets">';

    foreach ($itg_result as $row) {    
      $content .= '<li id="'.$row->category_name.'" data-widget="'.$widget_name.'#'.$row->category_id.'" data-widget-info="">'
              . '<span>'.$row->category_name.' ('.$row->category_id.')</span>'
              . '<span><a class="layout-section-widget2-delete" href="javascript:void(0)" data-widget="'.$row->id.'">X</a></span>'
              . '</li>';
    }

    $content .= '</ul>';
  }
  else {
    $content = '<ul id="templates-widgets-section" class="no-bullet pd-10 templates-widgets">';
  
    foreach ($itg_result as $row) {    
      $content .= '<li id="'.$row->category_name.'" data-widget="'.$widget_name.'#'.$row->category_id.'" data-widget-info="">'
              . '<span>'.$row->category_name.' ('.$row->category_id.')</span>'
              . '<span><a class="layout-section-delete" href="javascript:void(0)" data-widget="'.$row->id.'">X</a></span>'
              . '</li>';
    }
  
    $content .= '</ul>';
  }
  
  return $content;
  
}



/**
 * Get section widgets id
 * @param $cid
 * @param $section
 * @param $widget_type
 * @return int
 */
function get_section_widgets_id($cid, $section, $widget_type) {
  $query = db_select('itg_section_widgets_list', 'section');
  $query->fields('section', array('id'));  
  $query->condition('category_id', $cid);
  $query->condition('template_section_name', $section);
  $query->condition('widget_type', $widget_type);
  return $query->execute()->fetchField();
}


/**
 * Get current poll widgets list for layout setting page 
 * @return array
 */
function get_widgets_poll_list() {
  $widget_type = '';
  $date = date('Y-m-d H:i:s');
  //echo $date;
  $query = db_select('node', 'n');
  $query->join('field_data_field_poll_start_date', 'start_date', 'start_date.entity_id = n.nid');
  $query->leftJoin('field_data_field_poll_end_date', 'end_date', 'end_date.entity_id = n.nid');
  $query->fields('n', array('title', 'nid'));  
  $query->condition('type', 'poll');
  $query->condition('start_date.field_poll_start_date_value', $date, '<=');
  $query->condition(db_or()->isNull('end_date.field_poll_end_date_value')->condition('end_date.field_poll_end_date_value', $date, '>='));
  
  $itg_result = $query->execute()->fetchAll();
  
  $widget_name = $widget_type;
  
  $content = '<ul id="poll-widgets" class="no-bullet pd-10 templates-widgets">';
  
  foreach ($itg_result as $row) {    
    $content .= '<li id="'.$row->title.'" data-widget="'.$widget_name.'#'.$row->nid.'">'
            . '<span>'.$row->title.'</span>'            
            . '</li>';
  }
  
  $content .= '</ul>';
  
  return $content;
}

/**
 * Get itg setion cards
 * @param $section_id
 * @return array
 */
function create_setion_widgets($section_id, $widget_style = NULL) {
  module_load_include('inc', 'itg_widget', 'includes/section-wise-order-from-custom-table');
  // value is hardcoded need to be change for dyanamic functionality
  $info['section'] = $section_id; // tid of section
  $info['content_type'] = ''; // content type machine name
  // view name which is stored in draggableviews_structure table
  $info['view_name'] = 'views_form_section_wise_content_ordering_list_page';
  $block['subject'] = t('Section wise ordering from custom table');
  
  $data = itg_widget_section_wise_ordering_from_custom_table($info, $widget_style);
  
  return theme("section_wise_ordering", array("data" => $data, "widget_style" => $widget_style));
}

/**
 * Get itg setion widgets
 * @param $section_id
 * @return array
 */
function create_setion_widget2($section_id) {
  module_load_include('inc', 'itg_widget', 'includes/section-wise-order-from-custom-table');
  // value is hardcoded need to be change for dyanamic functionality
  $info['section'] = $section_id; // tid of section
  $info['content_type'] = ''; // content type machine name
  // view name which is stored in draggableviews_structure table
  $info['view_name'] = 'views_form_section_wise_content_ordering_list_page';
  //$block['subject'] = t('Section wise ordering from custom table');
  $data = itg_widget_section_wise_ordering_for_rhs_from_custom_table($info);
  
  return theme("rhs_section_wise_ordering", array("data" => $data));
}

/**
 * Get get_first_category_of_media_widget
 * @param $section
 * @param $template
 * @param $widget_name
 * @return array
 */
function get_first_category_of_media_widget($section, $template, $widget_name) {
  $query = db_select('itg_layout_tpl', 'ilt');
  $query->condition('ilt.status', 1, '=');
  $query->condition('ilt.template_name', $template, '=');
  $query->condition('ilt.section_name', $section, '=');
  $query->join('itg_layout_manager', 'ilm', 'ilt.id = ilm.layout_id' );
  $query->condition('ilm.widget_name', $widget_name, '=');
  $query->fields('ilm', array('filter_url', 'block_name'));

  $result = $query->execute();
  foreach($result as $key => $val) {        
    $cat_array[$val->block_name] = $val->filter_url;
  }

  ksort($cat_array);
  foreach($cat_array as $first) break;
  return $filter_url = $first;
}

function get_default_section_tpl(){
    $query = db_select('itg_layout_tpl', 'tpl');
    $query->fields('tpl', array('section_name', 'template_name'));  
    $query->condition('status', 1);
          //->condition('default', 1);
    $last_tpl = $query->execute()->fetchAll();
    p($last_tpl);
}

/**
 * Get tid of section tpl
 * @return int
 */
function get_tid_of_section_tpl($tid) {
  $query = db_select('itg_layout_tpl', 'tpl');
  $query->fields('tpl', array('section_name'));  
  $query->condition('section_name', $tid)
        ->condition('status', 1);
  $query->orderBy('tpl.id', 'DESC')->range(0,1);//LIMIT to 1 records

  return $query->execute()->fetchField();
}

/**
 * Get ads page name
 * @return $page_name
 */
function get_ads_page_name() {
	$arg = arg();
	$is_fron_page = drupal_is_front_page();      
	if (!empty($is_fron_page)) {          
		$page_name = 'Home';
	} 
	else if (($arg[0] == 'taxonomy' && $arg[1] == 'term' && is_numeric($arg[2]))) {
		$ads_tid = get_tid_of_section_tpl($arg[2]);	
		if (!empty($ads_tid)) {
			$page_name = $ads_tid;
		}
		else {
			$page_name = 'Rest';
		}
	}
	else {
	 $page_name = 'Rest';   
	}
	
	return $page_name;
}

/**
 * Get all html_custom widgets list for layout setting page
 * @return array
 */
function get_html_custom_widget_list() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));  
  $query->condition('type', 'custom_html_widgets');        
  $itg_result = $query->execute()->fetchAll();
  
  $rows = array();
  
  foreach ($itg_result as $row) {
    $widget[$row->nid] = $row->title;
  }
  
  return $widget;
}


/**
 * Get html_custom widgets for layout
 * @return theme
 */
function get_html_custom_widget($nid) {
  $node = node_load($nid); 
  $html_code = $node->body[LANGUAGE_NONE][0]['value'];  
  return theme("html_custom_widget", array("data" => $html_code));  
}

/**
 * Get highlights widgets for layout
 * @return theme
 */
function get_highlights_widget($nid) {  
    global $theme , $base_url;
    $highlights_node = node_load($nid);
    
    $output = '';
    $text = '';
    $output .= '<div class="wrap-listing">';
    foreach ($highlights_node->field_highlights[LANGUAGE_NONE] as $highlights_arr) {
      $highlights_detail = entity_load('field_collection_item', array($highlights_arr['value']));
      
      
      if(!empty($highlights_detail[$highlights_arr['value']]->field_highlights_url[LANGUAGE_NONE][0]['value'])) {
        $highlight_title = l($highlights_detail[$highlights_arr['value']]->field_highlights_text[LANGUAGE_NONE][0]['value'], $highlights_detail[$highlights_arr['value']]->field_highlights_url[LANGUAGE_NONE][0]['value'], array('attributes' => array('target' => '_blank')));
      }
      
      else {
          $highlight_title = $highlights_detail[$highlights_arr['value']]->field_highlights_text[LANGUAGE_NONE][0]['value'];
      }
      
      $like_dislike = '';
      
      $associate_emoji = $highlights_detail[$highlights_arr['value']]->field_emoji_condition['und'][0]['value'];
      
      //If none is deifne then not show any emoji or thumb.
      
      if($associate_emoji != "none") {
        
        //Show only like displike.
        
        if($associate_emoji == 0) {
          if (function_exists('itg_event_backend_highlights_like_dislike')) {
            if ($theme != 'itgadmin') {
              $like_dislike = itg_event_backend_highlights_like_dislike($highlights_arr['value']);
            }
          }
        }


        $emoji_reaction = '<span class="emoji-container">';
        $anchor_pointer_class = "def-cur-pointer";
        // Handel No case start.
        // IF associate emoji is No then dont show otherwise display on front end.

        if($associate_emoji == 1) {
          // Possible cookie for same line emoji on hightlight.
          $cookie_array = array(
            'hightlights_emoji_'.$highlights_arr['value'].'-field_field_emoji_highlights_1',
            'hightlights_emoji_'.$highlights_arr['value'].'-field_field_emoji_highlights_2',
            'hightlights_emoji_'.$highlights_arr['value'].'-field_field_emoji_highlights_3',
          );
          // Make emoji disable if cookie cookie is Set.
          if(isset($_COOKIE[$cookie_array[0]]) || isset($_COOKIE[$cookie_array[1]]) || isset($_COOKIE[$cookie_array[2]])) {
            $anchor_pointer_class = "def-cur-none-pointer";
          }
          // First emoji logic.
          if (!empty($highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_1[LANGUAGE_NONE][0]['value']) && $highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_1[LANGUAGE_NONE][0]['value'] == 1) {
            $emoji1_src = $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/highlights_icons/Good.png";
            $emoji1_title = $highlights_detail[$highlights_arr['value']]->field_field_emoji1_title[LANGUAGE_NONE][0]['value'];
            $field_class = $highlights_arr['value'].'-field_field_emoji_highlights_1';
            // Count user click from mongodb.
            if(function_exists('itg_common_mongo_activity_count')) {
              $emoji_count = itg_common_mongo_activity_count($field_class, 'front_user_activity_highlight');
            }
            $emoji_image = "<img src='".$emoji1_src."' title= '".$emoji1_title."' alt='' /> ";
            $count_message = ' <span class="'.$field_class.'">('.$emoji_count.')</span> ';
            // Prepare reaction link.
            $emoji_reaction .= l($emoji_image , 'javascript:void(0)' , array("external" => TRUE , "html" => TRUE , "attributes" => array("title" => $emoji1_title , "rel" => $field_class , "data-tag" => "All" , "data-status" => 1 , "data-activity" => "hightlights_emoji" , "data-click" => "nice" , "data-nodeid" => $highlights_arr['value'] , "class" => array($anchor_pointer_class ,  "user-activity-highlight"))));
            $emoji_reaction .= $count_message;
          }

          if (!empty($highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_2[LANGUAGE_NONE][0]['value']) && $highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_2[LANGUAGE_NONE][0]['value'] == 1) {
            $emoji2_src = $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/highlights_icons/Bad.png";
            $emoji2_title = $highlights_detail[$highlights_arr['value']]->field_field_emoji2_title[LANGUAGE_NONE][0]['value'];
            $field_class = $highlights_arr['value'].'-field_field_emoji_highlights_2';
            if(function_exists('itg_common_mongo_activity_count')) {
              $emoji_count = itg_common_mongo_activity_count($field_class, 'front_user_activity_highlight');
            }
            $emoji_image = "<img src='".$emoji2_src."' title= '".$emoji2_title."' alt='' /> ";
            $emoji_reaction .= l($emoji_image , 'javascript:void(0)' , array("external" => TRUE , "html" => TRUE , "attributes" => array("title" => $emoji1_title , "rel" => $field_class , "data-tag" => "All" , "data-status" => 1 , "data-activity" => "hightlights_emoji" , "data-click" => "no", "data-nodeid" => $highlights_arr['value'], "class" => array($anchor_pointer_class ,  "user-activity-highlight"))));
            $count_message = ' <span class="'.$field_class.'">('.$emoji_count.')</span> ';
            $emoji_reaction .= $count_message;
          }

          if (!empty($highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_3[LANGUAGE_NONE][0]['value']) && $highlights_detail[$highlights_arr['value']]->field_field_emoji_highlights_3[LANGUAGE_NONE][0]['value'] == 1) {
            $emoji3_src = $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/highlights_icons/WGMF.png";
            $emoji3_title = $highlights_detail[$highlights_arr['value']]->field_field_emoji3_title[LANGUAGE_NONE][0]['value'];
            $field_class = $highlights_arr['value'].'-field_field_emoji_highlights_3';
            if(function_exists('itg_common_mongo_activity_count')) {
              $emoji_count = itg_common_mongo_activity_count($field_class, 'front_user_activity_highlight');
            }
            $emoji_image = "<img src='".$emoji3_src."' title= '".$emoji3_title."' alt='' />";
            $emoji_reaction .= l($emoji_image , 'javascript:void(0)' , array("external" => TRUE , "html" => TRUE , "attributes" => array("title" => $emoji1_title , "rel" => $field_class , "data-tag" => "All" , "data-status" => 1 , "data-activity" => "hightlights_emoji", "data-click" => "whatever" ,"data-nodeid" => $highlights_arr['value'], "class" => array($anchor_pointer_class ,  "user-activity-highlight"))));
            $count_message = ' <span class="'.$field_class.'">('.$emoji_count.')</span>';
            $emoji_reaction .= $count_message;
          }
          // Add span for for vote messsage.
          $emoji_reaction .= '</span><p class="hightlights_emoji_msg_'.$highlights_arr['value'].'"></p>';
        }
      }
      // Handel No case END.
      // Prepare link dislike and emoji.
      $text .= '<div class="h-list">' . $highlight_title . $like_dislike . $emoji_reaction . '</div>';      

    }

    $output .= $text. '</div>';
  
  
  return theme("itg_highlights_widget", array("data" => $output));  
}

/**
 * Get all html_custom widgets list for layout setting page
 * @return array
 */
function get_highlights_widget_list() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));  
  $query->condition('type', 'heighlights');        
  $itg_result = $query->execute()->fetchAll();
  
  $rows = array();
  
  foreach ($itg_result as $row) {
    $widget[$row->nid] = $row->title;
  }
  
  return $widget;
}