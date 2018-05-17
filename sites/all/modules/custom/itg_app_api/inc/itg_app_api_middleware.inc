<?php

/**
 * Inc file contains the functions for Middleware API
 */

/**
 * Function to generate the horizontal menu api data from middleware
 *
 * @return type
 */
function horizontal_menu_middleware_data() {
    // for horizontal menu
    $menu_type_id = '2';
    $menu_data = horizontal_menu_data($menu_type_id);
    $success_status_mess = fetchMasterConfigData('master_config_internal_msg');
    $success_status_message = isset($success_status_mess) ? $success_status_mess : "";

    if ($menu_data['count'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "$success_status_message";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $output_array['data'] = $menu_data['data'];
    return $output_array;
}

/**
 * function to get the menu list
 *
 * @return type
 */
function hamburger_menu_middleware_data() {
    $menu_data = hamburger_menu_data();
    $success_status_mess = fetchMasterConfigData('master_config_internal_msg');
    $success_status_message = isset($success_status_mess) ? $success_status_mess : "";

    if ($menu_data['count'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "$success_status_message";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $output_array['data'] = $menu_data['data'];
    return $output_array;
}

/**
 * Get the hamburger menu data from
 *
 * @param int $menu_type_id horizontal/humburger_menu id
 *
 * @return array $result menu list
 */
function hamburger_menu_data() {
    $menu_list = array();
    $hamburger_menu = array();
    $all_menus = array();
    $top_cat = array();
    $other_cat = array();
    $top_cat_menus = array();

    //$option_list = humberger_menu_cms_list();
    // Top Categories
    $result = hamburger_menu_listing(1);
    $top_cat['menu_label'] = 'Top Categories';
    $order_s = 1;
    $all_menus = menu_list($result, $order_s);
    $top_cat['menu'] = $all_menus['data'];

    // Other Categories
    $order_s = $all_menus['order_l'];
    $other_cat_result = hamburger_menu_listing(2);
    $other_cat['menu_label'] = 'Other Categories';
    $top_cat_menus = menu_list($other_cat_result, $order_s);
    $other_cat['menu'] = $top_cat_menus['data'];

    $hamburger_menu['hamburger_menu'][0] = $top_cat;
    $hamburger_menu['hamburger_menu'][1] = $other_cat;
    $hamburger_menu['data'] = $hamburger_menu;
    $hamburger_menu['count'] = count($hamburger_menu);

    return $hamburger_menu;
}

/**
 * Get the humberger menu api listing
 *
 * @param type $result
 *
 * @return array
 */
function menu_list($result, $order_s = 1) {
    $all_menus = array();
    $total_menu = count($result);
    if ($total_menu > 0) {
        foreach ($result as $data) {
            if ($data['section_id'] == '1206553') {
                $data['title'] = "PROGRAMMES";
            } elseif ($data['section_id'] == '1206552') {
                $data['title'] = "VIDEOS";
            } elseif ($data['section_id'] == '1208521') {
                $data['title'] = "PHOTOS";
            }
            $menu['id'] = isset($data['section_id']) ? $data['section_id'] : "";
            //$menu['order'] = isset($data['order_id']) ? $data['order_id'] : "";
            $menu['order'] = "$order_s";
            $menu['title'] = isset($data['title']) ? strtoupper($data['title']) : "";
            $menu['type'] = isset($data['type']) ? $data['type'] : "";
            $menu['webview_url'] = isset($data['webview_url']) ? $data['webview_url'] : "";
            $menu['icon_url'] = isset($data['icon_url']) ? $data['icon_url'] : "";
            $menu['is_new'] = isset($data['is_new']) ? $data['is_new'] : "";
            $sub_cat = humberger_menu_subcat_list($data['section_id']);
            $sub_cat_total = $sub_cat['total_sub_cat'];
            $menu['has_subcategory'] = "$sub_cat_total";
            $menu['subcategory'] = $sub_cat['data'];
            $all_menus[] = $menu;
            $order_s++;
        }
    }
    $all_menus_data = array();
    $all_menus_data['data'] = $all_menus;
    $all_menus_data['order_l'] = $order_s;
    return $all_menus_data;
}

/**
 * get all the dropdown option of the menu
 *
 * @return type
 */
function humberger_menu_cms_list() {
    $query = db_select('itg_app_menu_master', 'mm');
    $query->fields('mm', array('menu_id', 'menu_name'));
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $query_results;
}

/**
 * Get the horizental menu data from
 *
 * @param int $menu_type_id horizontal/humburger_menu id
 *
 * @return array $result menu list
 */
function horizontal_menu_data($menu_type_id) {
    $menu_list = array();
    $horizontal_menu = array();
    $all_menus = array();
    $menu_data = array();

    $result = middleware_menu_data($menu_type_id);
    $total_menu = count($result);
    $oredr_lc = 1;
    if ($total_menu > 0) {
        foreach ($result as $data) {

            if ($data['section_id'] == '1206553') {
                $data['title'] = "PROGRAMMES";
            } elseif ($data['section_id'] == '1206552') {
                $data['title'] = "VIDEOS";
            } elseif ($data['section_id'] == '1208521') {
                $data['title'] = "PHOTOS";
            }
            $menu_list['id'] = isset($data['section_id']) ? $data['section_id'] : "";
            //$menu_list['order'] = isset($data['order_id']) ? $data['order_id'] : "";
            $menu_list['order'] = "$oredr_lc";
            $menu_list['title'] = isset($data['title']) ? strtoupper($data['title']) : "";
            $menu_list['type'] = isset($data['type']) ? $data['type'] : "";
            $menu_list['webview_url'] = isset($data['webview_url']) ? $data['webview_url'] : "";
            $menu_list['icon_url'] = isset($data['icon_url']) ? $data['icon_url'] : "";
            $menu_list['is_new'] = isset($data['is_new']) ? $data['is_new'] : "";
            $sub_cat = middleware_menu_subcat_list($data['section_id']);
            //if($data['section_id'] == '1206553' || $data['section_id'] == '1208521' || $data['section_id'] == '1206552'){
            if (count($sub_cat['data']) > 1) {
                $sub_cat_total = $sub_cat['total_sub_cat'];
                $menu_list['has_subcategory'] = "$sub_cat_total";
                $menu_list['subcategory'] = $sub_cat['data'];
            } else {
                $subcategory = array();
                $menu_list['has_subcategory'] = "0";
                $menu_list['subcategory'] = $subcategory;
            }

            $all_menus[] = $menu_list;
            $oredr_lc++;
        }
    }

    $horizontal_menu['horizontal_menu'] = $all_menus;
    $menu_data['data'] = $horizontal_menu;
    $menu_data['count'] = $total_menu;
    return $menu_data;
}

/**
 * Common function to get the middleware menu list
 *
 * @param type $menu_type_id
 *
 * @return type array list of menus
 */
function hamburger_menu_listing($menu_label_id) {
    if (!empty($menu_label_id)) {
        $menu_type_id = '1';
        $query = db_select('itg_app_menu_content', 'ham');
        $query->fields('ham');
        $query->condition('ham.menu_type_id', $menu_type_id);
        $query->condition('ham.s_id', 0);
        //$query->condition('ham.has_subcategory','0');
        $query->condition('ham.menu_label_id', $menu_label_id);
        $query->orderBy('order_id', 'ASC');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }
}

/**
 * Common function to get the middleware menu list
 *
 * @param type $menu_type_id
 *
 * @return type array list of menus
 */
function middleware_menu_data($menu_type_id) {
    if (!empty($menu_type_id)) {
        $query = db_select('itg_app_menu_content', 'ham');
        $query->fields('ham');
        $query->condition('ham.menu_type_id', $menu_type_id);
        // only parent menus
        $query->condition('ham.has_subcategory', 0);
        $query->orderBy('order_id', 'ASC');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    }
    return $result;
}

/**
 * Function for getting the subcat for middleware menu manager
 *
 * @param type $cat_id
 *
 * @return type
 */
function middleware_menu_subcat_list($cat_id) {
    $sub_cat = array();
    $sub_cat_list = array();
    $all_sub_cat = array();

    //$secion_id = array(0);
    $query = db_select('itg_app_menu_content', 'cl');
    $query->fields('cl', array('menu_type', 'section_id', 's_title', 'order_id', 'is_new', 's_id'));
    $query->condition('cl.section_id', $cat_id);
    // only parent menus
    $query->condition('cl.has_subcategory', 1);
    //$query->condition('cl.menu_type', 0, '!=');
    $query->condition('cl.s_id', 0, '!=');
    $query->condition('cl.menu_type_id', 2);
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $total_sub_cat = count($result);
    // one static features sub-cat..
    $sub_cat['s_id'] = "0";
    $sub_cat['s_title'] = "FEATURED";
    $sub_cat['s_order'] = "1";
    $sub_cat['s_is_new'] = "0";
    $all_sub_cat[] = $sub_cat;
    if ($total_sub_cat > 0) {
        $lc = 2;
        foreach ($result as $cat_data) {
            $sub_cat['s_id'] = $cat_data['s_id'];
            $sub_cat['s_title'] = strtoupper($cat_data['s_title']);
            $sub_cat['s_order'] = "$lc";
            $sub_cat['s_is_new'] = $cat_data['is_new'];
            $all_sub_cat[] = $sub_cat;
            $lc++;
        }
    }

    $sub_cat_list['total_sub_cat'] = $total_sub_cat + 1;
    $sub_cat_list['data'] = $all_sub_cat;
    return $sub_cat_list;
}

/**
 * Function for getting the subcat for middleware menu manager
 *
 * @param type $cat_id
 *
 * @return type
 */
function humberger_menu_subcat_list($cat_id) {
    $sub_cat = array();
    $sub_cat_list = array();
    $all_sub_cat = array();

    $query = db_select('itg_app_menu_content', 'cl');
    $query->fields('cl', array('menu_type', 'section_id', 's_title', 'order_id', 'is_new'));
    $query->condition('cl.section_id', $cat_id);
    // only parent menus
    $query->condition('cl.has_subcategory', 0);
    $query->condition('cl.menu_type', 0, '!=');
    $query->condition('cl.s_id', 0, '!=');
    $query->condition('cl.menu_type_id', 1);
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    $total_sub_cat = count($result);

    if ($total_sub_cat > 0) {
        foreach ($result as $cat_data) {
            $order_val = $cat_data['order_id'];
            $section_id = $cat_data['section_id'];
            $s_title = $cat_data['s_title'];
            $is_new = $cat_data['is_new'];
            $sub_cat['s_id'] = "$section_id";
            $sub_cat['s_title'] = "$s_title";
            $sub_cat['s_order'] = "$order_val";
            $sub_cat['s_is_new'] = "$is_new";
            $all_sub_cat[] = $sub_cat;
        }
    }

    $sub_cat_list['total_sub_cat'] = $total_sub_cat;
    $sub_cat_list['data'] = $all_sub_cat;
    return $sub_cat_list;
}

/**
 * Get the internal master configuration from the middleware
 *
 * @return type
 */
function master_config_interenal() {
    $config_data = master_config_internal_data();
    $success_status_mess = fetchMasterConfigData('master_config_internal_msg');
    $success_status_message = isset($success_status_mess) ? $success_status_mess : "";

    if ($config_data['count'] > 0) {
        $output_array['status_code'] = "1";
        $output_array['status_message'] = "$success_status_message";
    } else {
        $output_array['status_code'] = "0";
        $output_array['status_message'] = "customised_message";
    }

    $output_array['data'] = $config_data['data'][0];
    return $output_array;
}

/**
 * Get the list of middleware array data
 *
 * @return string
 */
function master_config_internal_data() {
    $config_list = array();
    $data_list = array();
    $ios_data = array();
    $android_data = array();

    $query = db_select('itg_app_master_config_internal', 'imi');
    $query->fields('imi', array('config_val', 'config_key'));
    //$query->condition('imi.config_key', $config_list, 'IN');//
    $result = $query->execute()->fetchAllAssoc('config_key', PDO::FETCH_ASSOC);

    $total_config_data = count($result);
    if ($total_config_data > 0) {

        $config_list['last_updated_datetime'] = isset($result['last_updated_datetime']['config_val']) ? $result['last_updated_datetime']['config_val'] : "";
        $config_list['photo_display_count'] = isset($result['photo_display_count']['config_val']) ? $result['photo_display_count']['config_val'] : "";
        $config_list['photo_pagination_cap'] = isset($result['photo_pagination_cap']['config_val']) ? $result['photo_pagination_cap']['config_val'] : "";

        $config_list['photo_display_count_newslist_cell'] = isset($result['photo_display_count_newslist_cell']['config_val']) ? $result['photo_display_count_newslist_cell']['config_val'] : "";
        $config_list['video_display_count'] = isset($result['video_display_count']['config_val']) ? $result['video_display_count']['config_val'] : "";
        $config_list['video_pagination_cap'] = isset($result['video_pagination_cap']['config_val']) ? $result['video_pagination_cap']['config_val'] : "";
        $config_list['story_display_count'] = isset($result['story_display_count']['config_val']) ? $result['story_display_count']['config_val'] : "";
        $config_list['story_pagination_cap'] = isset($result['story_pagination_cap']['config_val']) ? $result['story_pagination_cap']['config_val'] : "";
        $config_list['news_display_count'] = isset($result['news_display_count']['config_val']) ? $result['news_display_count']['config_val'] : "";
        $config_list['news_pagination_cap'] = isset($result['news_pagination_cap']['config_val']) ? $result['news_pagination_cap']['config_val'] : "";
        $config_list['magazine_display_count'] = isset($result['magazine_display_count']['config_val']) ? $result['magazine_display_count']['config_val'] : "";
        $config_list['magazine_pagination_cap'] = isset($result['magazine_pagination_cap']['config_val']) ? $result['magazine_pagination_cap']['config_val'] : "";
        $config_list['author_display_count'] = isset($result['author_display_count']['config_val']) ? $result['author_display_count']['config_val'] : "";
        $config_list['author_pagination_cap'] = isset($result['author_pagination_cap']['config_val']) ? $result['author_pagination_cap']['config_val'] : "";
        $config_list['author_story_display_count'] = isset($result['author_story_display_count']['config_val']) ? $result['author_story_display_count']['config_val'] : "";
        $config_list['author_story_pagination_cap'] = isset($result['author_story_pagination_cap']['config_val']) ? $result['author_story_pagination_cap']['config_val'] : "";
        $config_list['anchor_display_count'] = isset($result['anchor_display_count']['config_val']) ? $result['anchor_display_count']['config_val'] : "";
        $config_list['anchor_pagination_cap'] = isset($result['anchor_pagination_cap']['config_val']) ? $result['anchor_pagination_cap']['config_val'] : "";
        $config_list['anchor_program_display_count'] = isset($result['anchor_program_display_count']['config_val']) ? $result['anchor_program_display_count']['config_val'] : "";
        $config_list['anchor_program_pagination_cap'] = isset($result['anchor_program_pagination_cap']['config_val']) ? $result['anchor_program_pagination_cap']['config_val'] : "";
        $config_list['closed_poll_display_count'] = isset($result['closed_poll_display_count']['config_val']) ? $result['closed_poll_display_count']['config_val'] : "";
        $config_list['closed_poll_pagination_cap'] = isset($result['closed_poll_pagination_cap']['config_val']) ? $result['closed_poll_pagination_cap']['config_val'] : "";

        $ios_data['live_version'] = isset($result['ios_live_version']['config_val']) ? $result['ios_live_version']['config_val'] : "";
        $ios_data['version_update_datetime'] = isset($result['ios_version_update_datetime']['config_val']) ? $result['ios_version_update_datetime']['config_val'] : "";
        $ios_data['force_update'] = isset($result['ios_force_update']['config_val']) ? $result['ios_force_update']['config_val'] : "";
        $ios_data['update_message_frequency'] = isset($result['ios_update_message_frequency']['config_val']) ? $result['ios_update_message_frequency']['config_val'] : "";

        $android_data['live_version'] = isset($result['android_live_version']['config_val']) ? $result['android_live_version']['config_val'] : "";
        $android_data['beta_version'] = isset($result['android_beta_version']['config_val']) ? $result['android_beta_version']['config_val'] : "";
        $android_data['version_update_datetime'] = isset($result['android_version_update_datetime']['config_val']) ? $result['android_version_update_datetime']['config_val'] : "";
        $android_data['force_update'] = isset($result['android_force_update']['config_val']) ? $result['android_force_update']['config_val'] : "";
        $android_data['update_message_frequency'] = isset($result['android_update_message_frequency']['config_val']) ? $result['android_update_message_frequency']['config_val'] : "";

        $config_list['ios'] = $ios_data;
        $config_list['android'] = $android_data;
        $config_list_data[] = $config_list;
    }

    $data_list['count'] = $total_config_data;
    $data_list['data'] = $config_list_data;
    return $data_list;
}

/**
 * horizontal_menu_listing_top
 */
function horizontal_menu_listing_top() {
    $query = db_select('itg_app_menu_content', 'ham');
    $query->fields('ham');
    $query->condition('ham.menu_type_id', 2);
    // only parent menus
    $query->condition('ham.has_subcategory', 0);
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}

/**
 * hamburger_menu_listing_sub
 */
function hamburger_menu_listing_sub() {
    $query = db_select('itg_app_menu_content', 'cl');
    $query->fields('cl');
    //$query->condition('cl.section_id', $cat_id);
    // only parent menus
    $query->condition('cl.has_subcategory', 1);
    //$query->condition('cl.menu_type', 0, '!=');
    $query->condition('cl.s_id', 0, '!=');
    $query->condition('cl.menu_type_id', 2);
    $query->orderBy('order_id', 'ASC');
    $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
    return $result;
}
/**
 * itg_rapid_get_emoji
 * @param type $post_content
 * @return type
 */
function itg_rapid_get_emoji($post_content) {
    $src = array();
    if ($post_content) {
        preg_match_all('@src="([^"]+)"@', $post_content, $match);
        $src = array_pop($match);
    }
    return $src;
}
