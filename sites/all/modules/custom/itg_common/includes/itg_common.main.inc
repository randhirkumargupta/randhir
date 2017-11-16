<?php

/**
 * Implement for lock delete on cancle button
 */
function itg_custom_lock_delete() {
  if (!empty($_GET['nid'])) {
    if (function_exists('content_lock_release')) {
      content_lock_release($_GET['nid'], $user->uid);
    }
  }
  exit;
}

/**
 * Implements itg_custom_dev_node_dpm().
 *   callbck for debugging node load
 */
function itg_custom_dev_node_dpm(){
  $arg = arg();
  if($arg[0] == 'itg-dev-node-dpm' && !empty($arg[1])) {
    $node = node_load($arg[1]);
    p($node);
  }
}

/**
 * Helper function to get photogallery.
 */
function itg_photogallery_embed() {
  if (!empty($_GET['gid'])) {
    $data = node_load($_GET['gid']);
    return theme('itg_photogallery_embed', array('data' => $data));
  }
}

/**
 * Helper function to get videogallery.
 */
function itg_videogallery_embed() {
  $arg = arg(3);
  if (!empty($arg)) {
    $gid = base64_decode($arg);
    if (function_exists('get_video_in_fieldcollection_by_nid')) {
      $videoids = get_video_in_fieldcollection_by_nid($gid);
    }
    return theme('itg_videogallery_embed', array('data' => $videoids));
  }
}

/**
 * Helper function to get videogallery.
 */
function itg_photo_embed() {
  $arg = arg(3);
  if (!empty($arg)) {
    $gid = base64_decode($arg);
    $data = node_load($gid);
    return theme('itg_photo_embed', array('data' => $data));
  }
}

/**
 * callback for funalytics-popup.
 */
function itg_funalytics_popup() {
  echo views_embed_view('front_funalytics_list', 'block_1');
}

/**
 * Implements itg_get_amp_search_result().
 */
function itg_get_amp_search_result() {
  if (isset($_GET['search'])) {
    $name = isset($_GET['search']) ? $_GET['search'] : '';
    $searchurl = FRONT_URL . '/topic/' . $name;
    drupal_goto($searchurl);
  }
}

/**
 * Implements function for get insert private ip
 * @return array
 */
function itg_common_insert_private_ips() {
  global $user;
  module_load_include('inc', 'itg_common', 'includes/itg_common_aws_s3_for_lb');
  if (function_exists('insert_private_ip_in_varnish')) {
    $data_video = insert_private_ip_in_varnish();
  }

}