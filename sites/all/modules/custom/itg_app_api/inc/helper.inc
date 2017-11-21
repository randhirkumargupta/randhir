<?php

/*
 * INC file for Set the Firebase API Configuration & Static variable declaratrion
 * 
 */

define('HOME_PAGE_JSON_NEWS_LIST_LIFE_STYLE', 1206567); /*till middleware implementation*/
define('HOME_PAGE_JSON_NEWS_LIST_INDIA', 1206578); /*till middleware implementation*/
define('HOME_PAGE_JSON_NEWS_LIST_WORLD', 1206577); /*till middleware implementation*/
define('ANCHOR_TID', 285903); /*till middleware implementation*/
define('BITARATES_BASE_PATH', 'https://itgd-mum-dev-static.s3.ap-south-1.amazonaws.com/s3fs-public/dailymotion_bitates_video'); /*till middleware implementation*/



/**
 * Common Function to create short url of node
 * @global type $base_url
 * @param int $nid
 * @return string
 */
function get_node_firebase_weburl($nid) {
  if ($nid) {
    global $base_url;
    $firebase_url = "";
    $alias = drupal_get_path_alias('node/' . $nid . '');
    $weburl = $base_url . "/" . $alias;
    return $weburl;
  }
}
