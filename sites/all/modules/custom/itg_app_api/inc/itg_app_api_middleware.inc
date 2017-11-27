<?php

/**
 * Inc file contains the functions for Middleware API
 */


function horizontal_menu_middleware_data() {
    $menu_type_id = '2'; //for horizontal menu
    $menu_data = middleware_menu_data($menu_type_id);
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
 * Get the horizental menu data from 
 * @param int $menu_type_id horizontal/humburger_menu id
 * @return array $result menu list
 */
function middleware_menu_data($menu_type_id){
      $menu_list = array();
      $horizontal_menu = array();
      $all_menus = array();
      $menu_data = array();
      
      $query = db_select('itg_app_menu_content', 'ham');
      $query->fields('ham');
      $query->condition('ham.menu_type_id', $menu_type_id);
      $query->orderBy('order_id','DESC');
      $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
      $total_menu = count($result);
      
      if($total_menu > 0){
        foreach ($result as $data){
          $menu_list['id'] = $data['id'];
          $menu_list['order'] = $data['order_id'];
          $menu_list['title'] = $data['title'];
          $menu_list['type'] = $data['type'];
          $menu_list['webview_url'] = $data['webview_url'];
          $menu_list['icon_url'] = $data['icon_url'];
          $menu_list['is_new'] = $data['is_new'];
          $menu_list['has_subcategory'] = $data['has_subcategory'];
          $menu_list['subcategory'] = array();
          $all_menus[] = $menu_list;
        }
      }
    
    $horizontal_menu['horizontal_menu'] = $all_menus;
    $menu_data['data'] = $horizontal_menu;
    $menu_data['count'] = $total_menu;
    return $menu_data;
}
