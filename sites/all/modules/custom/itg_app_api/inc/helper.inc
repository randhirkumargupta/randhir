<?php

/*
 * INC file for Set the Firebase API Configuration & Static variable declaratrion
 * 
 */
/* till middleware implementation */
define('HOME_PAGE_JSON_NEWS_LIST_LIFE_STYLE', 1206567);
/* till middleware implementation */
define('HOME_PAGE_JSON_NEWS_LIST_INDIA', 1206578);
/* till middleware implementation */
define('HOME_PAGE_JSON_NEWS_LIST_WORLD', 1206577);
/* till middleware implementation */
/* till middleware implementation */
define('AUTHOR_TID', 285750);
/* till middleware implementation */
define('BITARATES_BASE_PATH', 'https://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public/dailymotion_bitates_video');
define('HOME_PAGE_JSON_MOVIES', 1206533);
define('HOME_PAGE_JSON_MOVIES_PHOTO', 1208598);
define('HOME_PAGE_JSON_MOVIES_VIDEO', 1207303);
define('HOME_PAGE_JSON_ELECTION', 1206795); // 1768551
/* XML feed Program/story/photo/video list create date range (pass value in days like -90 days) */
$feed_data_limit = '-90 days';
if (!empty(variable_get('itg_feed_data_date_range'))) {
    $feed_data_limit = variable_get('itg_feed_data_date_range');
}
define('FEED_DATA_LIMIT', $feed_data_limit);

/**
 * Common Function to create short url of node
 * @global type $base_url
 *
 * @param int $nid
 *
 * @return string
 */
function get_node_firebase_weburl($nid) {
    if ($nid) {
        global $base_url;
        $firebase_url = "";
        $alias = drupal_get_path_alias('node/' . $nid . '');
        $weburl = FRONT_URL . "/" . $alias;
        return $weburl;
    }
}
