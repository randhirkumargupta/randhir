<?php

/**
 * Inc file contains the functions for homePgae API 
 */

/**
 * main function for generate homePageJson array
 *
 * @return array
 */
function homePageJson_live() {
    global $order;
    $data = array();
    $data_final = array();
    $data_packagelist = array();
    $data_topstories = array();
    $data_news = array();
    $data_magazine = array();
    $order = "1";
    $data_cat_news = array();
    $data_poll = array();
    $data_topstories = array();
    $data_middleware = array();
    $total_count = 0;

    $middleware_packages_config = fetchMasterConfigData_live('packages_config_options');
    if ($middleware_packages_config == 1) {
        $data_middleware = home_page_packages_live();

        $total_count += count($data_middleware);
    }

    $middleware_topstories_config = fetchMasterConfigData_live('top_stories_config_options');
    if ($middleware_topstories_config == 1) { //enable
        $limit = fetchMasterConfigData_live('top_stories_management');
        $data_topstories = topstoriesList('home', $limit);
        $total_count += count($data_topstories);
    }

    $middleware_cat_config = fetchMasterConfigData_live('categories_config_options');
    if ($middleware_cat_config == 1) { //enable
        $data_cat_news = home_page_newslist_cat_live();

        $total_count += count($data_cat_news);
    }

    $middleware_magazine_config = fetchMasterConfigData('magazine_config_options');
    if ($middleware_magazine_config == 1) { //enable
        $data_magazine = homePageJsonMagazine();
        $total_count += count($data_magazine);
    } elseif ($middleware_magazine_config == 2) {
        $data_magazine = homePageJsonMagazine('direct');
        $total_count += count($data_magazine);
    }

    $middleware_polls_config = fetchMasterConfigData_live('polls_config_options');
    if ($middleware_polls_config == 1) { //enable
        $data_poll = homePageJsonPoll();
        $total_count += count($data_poll);
    }

    $success_status_mess = fetchMasterConfigData_live('homePage_display_custom_msg');
    $success_status_message = isset($success_status_mess) ? $success_status_mess : "";

    if ($total_count > 0) {
        $data['status_code'] = "1";
        $data['status_message'] = "$success_status_message";
        $data_final['status_code'] = "1";
        $data_final['status_message'] = "$success_status_message";
    } else {
        $data['status_code'] = "0";
        $data['status_message'] = "";
        $data_final['status_code'] = "0";
        $data_final['status_message'] = "";
    }

    $i = 0;
    $homeapi_order_packages = fetchitg_app_master_config_internal_live('homeapi_order_packages');
    $homeapi_order_topstories = fetchitg_app_master_config_internal_live('homeapi_order_topstories');
    $homeapi_order_categories = fetchitg_app_master_config_internal_live('homeapi_order_categories');
    $homeapi_order_magazines = fetchitg_app_master_config_internal_live('homeapi_order_magazines');
    $homeapi_order_polls = fetchitg_app_master_config_internal_live('homeapi_order_polls');

    if (count($data_middleware) > 0) {
        $data['data'][$homeapi_order_packages] = $data_middleware;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_packages]);
    }

    if (count($data_topstories) > 0) {
        $data['data'][$homeapi_order_topstories] = $data_topstories;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_topstories]);
    }
    if (count($data_cat_news) > 0) {

        $data['data'][$homeapi_order_categories] = $data_cat_news;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_categories]);
    }
    if (count($data_magazine) > 0) {
        $data['data'][$homeapi_order_magazines] = $data_magazine;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_magazines]);
    }
    if (count($data_poll) > 0) {
        $data['data'][$homeapi_order_polls] = $data_poll;
        $i++;
    } else {
        unset($data['data'][$homeapi_order_polls]);
    }
    /* widget calling start */
    $middleware_packages_config = fetchMasterConfigData_live('widget_config_options');
    if ($middleware_packages_config) {
        $query_w = db_select('itg_app_middleware_live', 'iam');
        $query_w->fields('iam');
        $query_w->condition('iam.identifier', 'itg_widget', '=');
        $query_w->condition('iam.status', 1, '=');
        $result_w = $query_w->execute()->fetchAll(PDO::FETCH_ASSOC);

        foreach ($result_w as $reskey => $resvalue) {
            $name = $resvalue['name'];
            $widget = fetch_widget_config_live($name);
            if ($widget['status'] == 1) {
                $widget_data = itg_rv_widget_data($widget);

                $widget_order = fetchitg_app_master_config_internal_live('homeapi_order_widget_' . $name . '');

                $data['data'][$widget_order] = (array) $widget_data;
            }
        }
    }

    $array_key = array_keys($data['data']);

    $active_chunk_c = count($data['data']);
    $data_live = array();
    for ($i = 0; $i < $active_chunk_c; $i++) {
        $min_key = min($array_key);
        if (count($data['data'][$min_key]) > 1 || isset($data['data'][$min_key][0]['id'])) {

            $data_live[$i] = $data['data'][$min_key];
            unset($data['data'][$min_key]);

            foreach ($array_key as $key => $value) {
                if ($value == $min_key) {
                    unset($array_key[$key]);
                }
            }
        }
    }

    $data['data'] = $data_live;

    $lc = 0;
    foreach ($data['data'] as $key => $value) {
        if (count($value[0]) > 0) {
            foreach ($value as $key2 => $value2) {
                $order_v = $lc + 1;
                $value2['order'] = "$order_v";
                $data_final['data'][$lc] = $value2;
                $lc ++;
            }
        } else {
            $order_v = $lc + 1;
            $value['order'] = "$order_v";
            $data_final['data'][$lc] = $value;
            $lc ++;
        }
    }
    if (count($data) == 2) {
        $data['data'] = array();
        $data_final['data'] = array();
    }
    $cube_widget = array();
    
    $widget_detail = array();
    /*$cube_widget['show_widget'] = "1";
    $widget_detail[0]['type'] = "webview";
    $widget_detail[0]['title'] = "Scorecard";
    $widget_detail[0]['type_label'] = "scorecard";
    $widget_detail[0]['width'] = "130";
    $widget_detail[0]['height'] = "119";
    $widget_detail[0]['short_url'] = "https://feeds.intoday.in/xml_it/commentary/cube_ipl98.html";
    $widget_detail[0]['extended_url'] = "https://feeds.intoday.in/xml_it/commentary/scorecard_iplwidget_detail.html";
    $cube_widget['widget_detail'] = $widget_detail;*/
    $cube_widget_config_options = fetchitg_app_master_config_internal_live('cube_widget_config_options');
    $cube_data = "";
    $cube_data = variable_get('cube_widget');
    if ($cube_widget_config_options == 1 && $cube_data !="") {
        $cube_widget_json = variable_get('cube_widget');
        $cube_widget = json_decode($cube_widget_json, TRUE);
        $data_final['cube_widget'] = $cube_widget;
    }
    

    

    return $data_final;
}

/**
 * Get Package category listing from the middleware
 * @return type
 */
function home_page_newslist_cat_live() {
    $query = db_select('itg_app_middleware_live', 'am');
    $query->innerJoin('itg_app_master_info_internal_live', 'mci', 'mci.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'categories_options');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mci.info_type', 'categories', '=');
    $query->condition('mci.info_key', 'order', '=');
    $query->orderBy('mci.info_value', 'ASC');
    $query->groupBy('am.ids');
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $cat_news_list = array();
    foreach ($query_results as $tid) {
        $cat_news_list[] = homePageCatNewslist($tid['ids']);
    }

    return $cat_news_list;
}

function home_page_packages_live() {
    $query = db_select('itg_app_middleware_live', 'am');
    $query->leftJoin('itg_app_master_info_internal_live', 'mci', 'mci.org_id=am.ids');
    $query->fields('am', array('ids'));
    $query->condition('am.identifier', 'itg_package');
    $query->condition('am.ids', '0', '!=');
    $query->condition('mci.info_type', 'packages', '=');
    $query->orderBy('mci.info_value', 'ASC');
    $query_results = $query->execute()->fetchAll(PDO::FETCH_ASSOC);

    $list_arr = array();
    foreach ($query_results as $tid) {

        $list_arr[] = homePageJsonPackagelist($tid['ids']);
    }

    return $list_arr;
}

function fetchitg_app_master_config_internal_live($key) {
    $value = "";
    if ($key) {
        $query = db_select('itg_app_master_config_internal_live', 'mci');
        $query->fields('mci');
        $query->condition('mci.config_key', $key, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $value = $result[0]['config_val'];
    }
    return $value;
}

function fetch_widget_config_live($name) {
    $data = array();
    if ($name) {
        $query = db_select('itg_app_middleware_live', 'iam');
        $query->fields('iam');
        $query->condition('iam.identifier', 'itg_widget', '=');
        $query->condition('iam.name', $name, '=');
        $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
        $data = $result[0];
    }
    return $data;
}

function fetchMasterConfigData_live($key) {
    $key_val = "";
    if ($key) {
        $query = db_select('itg_app_master_config_internal', 'imi');
        $query->fields('imi', array('config_val'));
        $query->condition('imi.config_key', $key, '=');
        $results = $query->execute()->fetchAll();
        $key_val = $results[0]->config_val;
    }
    return $key_val;
}
