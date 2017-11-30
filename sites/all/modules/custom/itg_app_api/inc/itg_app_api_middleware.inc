<?php

/**
 * Inc file contains the functions for Middleware API
 */

/**
 * Function to generate the horizontal menu api data from middleware
 * @return type
 */
function horizontal_menu_middleware_data() {
    $menu_type_id = '2'; //for horizontal menu
    $menu_data = horizontal_menu_data($menu_type_id);
    if ($menu_data['count'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

   $output_array['data'] = $menu_data['data'];
   return $output_array;
}

/**
 * function to get the menu list
 * @return type
 */
function hamburger_menu_middleware_data() {
    $menu_data = hamburger_menu_data();
    if ($menu_data['count'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

   $output_array['data'] = $menu_data['data'];
   return $output_array;
}

/**
 * Get the hamburger menu data from
 * @param int $menu_type_id horizontal/humburger_menu id
 * @return array $result menu list
 */
function hamburger_menu_data() {
  $menu_list = array();
  $hamburger_menu = array();
  $all_menus = array();
  $top_cat = array();
  $other_cat = array();

  $option_list = humberger_menu_cms_list();
     $result = hamburger_menu_listing(1);//Top Categories
     $top_cat['menu_label'] = 'Top Categories';
     $all_menus = menu_list($result);
     $top_cat['menu'] = $all_menus;

     $other_cat_result = hamburger_menu_listing(2);//Other Categories
     $other_cat['menu_label'] = 'Other Categories';
     $top_cat_menus = menu_list($other_cat_result);
     $other_cat['menu'] = $top_cat_menus;

     $hamburger_menu['hamburger_menu'][0] = $top_cat;
     $hamburger_menu['hamburger_menu'][1] = $other_cat;
     $hamburger_menu['data'] = $hamburger_menu;
     $hamburger_menu['count'] = count($hamburger_menu);

  return $hamburger_menu;
}

function menu_list($result){
  $total_menu = count($result);
   if ($total_menu > 0) {
    foreach ($result as $data) {
      $menu['id'] = $data['id'];
      $menu['order'] = $data['order_id'];
      $menu['title'] = $data['title'];
      $menu['type'] = $data['type'];
      $menu['webview_url'] = $data['webview_url'];
      $menu['icon_url'] = $data['icon_url'];
      $menu['is_new'] = $data['is_new'];
      $sub_cat = middleware_menu_subcat_list($data['section_id']);
      $sub_cat_name = $sub_cat['total_sub_cat'];
      $menu['has_subcategory'] = "$sub_cat_name";
      $menu['subcategory'] = $sub_cat['data'];
      $all_menus[] = $menu;
    }
  }
  return $all_menus;
}

/**
 * get all the dropdown option of the menu
 * @return type
 */
function humberger_menu_cms_list(){
    $query = db_select('itg_app_menu_master', 'mm');
    $query->fields('mm', array('menu_id','menu_name'));
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $query_results;
}

/**
 * Get the horizental menu data from
 * @param int $menu_type_id horizontal/humburger_menu id
 * @return array $result menu list
 */
function horizontal_menu_data($menu_type_id) {
  $menu_list = array();
  $horizontal_menu = array();
  $all_menus = array();
  $menu_data = array();

  $result = middleware_menu_data($menu_type_id);
  $total_menu = count($result);

  if ($total_menu > 0) {
    foreach ($result as $data) {
      $menu_list['id'] = $data['id'];
      $menu_list['order'] = $data['order_id'];
      $menu_list['title'] = $data['title'];
      $menu_list['type'] = $data['type'];
      $menu_list['webview_url'] = $data['webview_url'];
      $menu_list['icon_url'] = $data['icon_url'];
      $menu_list['is_new'] = $data['is_new'];
      $sub_cat = middleware_menu_subcat_list($data['section_id']);
      $menu_list['has_subcategory'] = $sub_cat['total_sub_cat'];
      $menu_list['subcategory'] = $sub_cat['data'];
      $all_menus[] = $menu_list;
    }
  }

  $horizontal_menu['horizontal_menu'] = $all_menus;
  $menu_data['data'] = $horizontal_menu;
  $menu_data['count'] = $total_menu;
  return $menu_data;
}

/**
 * Common function to get the middleware menu list
 * @param type $menu_type_id
 * @return type array list of menus
 */
function hamburger_menu_listing($menu_label_id) {
  if (!empty($menu_label_id)) {
    $menu_type_id = '1';
    $query = db_select('itg_app_menu_content', 'ham');
    $query->fields('ham');
    $query->condition('ham.menu_type_id', $menu_type_id);
    $query->condition('ham.s_id', 0);
    $query->condition('ham.menu_label_id', $menu_label_id);
    $query->orderBy('order_id', 'DESC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
  }
}

/**
 * Common function to get the middleware menu list
 * @param type $menu_type_id
 * @return type array list of menus
 */
function middleware_menu_data($menu_type_id) {
  if (!empty($menu_type_id)) {
    $query = db_select('itg_app_menu_content', 'ham');
    $query->fields('ham');
    $query->condition('ham.menu_type_id', $menu_type_id);
    $query->condition('ham.s_id', 0); //only parent menus
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  }
  return $result;
}

/**
 * Function for getting the subcat for middleware menu manager
 * @param type $cat_id
 * @return type
 */
function middleware_menu_subcat_list($cat_id) {
    $sub_cat = array();
    $sub_cat_list = array();
    $all_sub_cat = array();

    //$secion_id = array(0);
    $query = db_select('itg_app_menu_content', 'cl');
    $query->fields('cl',array('menu_type','section_id','s_title','order_id','is_new'));
    $query->condition('cl.section_id', $cat_id);
    $query->condition('cl.has_subcategory', 0); //only parent menus
    $query->condition('cl.menu_type', 0, '!=');
    $query->condition('cl.s_id', 0, '!=');
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $total_sub_cat = count($result);

    if($total_sub_cat > 0){
      foreach ($result as $cat_data){
        $sub_cat['s_id'] = $cat_data['section_id'];
        $sub_cat['s_title'] = $cat_data['s_title'];
        $sub_cat['s_order'] = $cat_data['order_id'];
        $sub_cat['s_is_new'] = $cat_data['is_new'];
        $all_sub_cat[] = $sub_cat;
      }
    }

   $sub_cat_list['total_sub_cat'] = $total_sub_cat;
   $sub_cat_list['data'] = $all_sub_cat;
  return $sub_cat_list;
}
