<?php
/**
 * @file
 * INC file for APP API Schemes Services.
 * Contains the resource declarations for the service APIs
 * and other commons functions/hooks. if necessary
 */
/**
 * Function for APP API resource declaration.
 */
function itg_report_api_resource() {
  /**
   * custom resource for ITG Report
   */
  $api = array(
    // testing custom resource declaration.....
    'testing_report' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves testing schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_testing_report',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // story_Count_report custom resource declaration.....
    'story_count_report' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves story_Count_report schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_story_count_report',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // user_list custom resource declaration.....
    'user_list' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves user_list schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_user_list',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // get_story_api custom resource declaration.....
    'get_story_api' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves get_story_api schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_get_story_api',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // story_video_photo_field_report custom resource declaration.....
    'story_video_photo_field_report' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves story_video_photo_field_report schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_story_video_photo_field_report',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // author_report custom resource declaration.....
    'author_report' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves author_report schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_author_report',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // author_report_tvtn custom resource declaration.....
    'author_report_tvtn' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves author_report_tvtn schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_author_report_tvtn',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // auscovery_dashboard_web custom resource declaration.....
    'auscovery_dashboard_web' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves auscovery_dashboard_web schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_auscovery_dashboard_web',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
    // auscovery_dashboard_mob custom resource declaration.....
    'auscovery_dashboard_mob' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves auscovery_dashboard_mob schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_auscovery_dashboard_mob',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
      // get the recent data of Story/Photo/Vieo based on args .....
    'report_api_data_list' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Report API.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_detail',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
      
   // author_report custom resource declaration.....
    'author_report_v1' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves author_report schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_report_api',
            'name' => 'itg_report_api.services',
          ),
          'callback' => 'itg_report_api_author_report_v1',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'token',
              'type' => 'string',
              'description' => 'Function to perform',
              'source' => array('path' => 0),
              'optional' => TRUE,
              'default' => '*',
            ),
          ),
        ),
      ),
    ),
      
   // insert_video custom resource declaration.....
        'insert_video' => array(
            'operations' => array(
                'create' => array(
                    'help' => 'Retrieves insert_video schemes info.',
                    'file' => array(
                        'type' => 'inc',
                        'module' => 'itg_app_api',
                        'name' => 'itg_app_api.services',
                    ),
                    'callback' => 'itg_rapid_api_insert_video',
                    'access callback' => 'user_access',
                    'access arguments' => array('access content'),
                    'access arguments append' => FALSE,
                    'args' => array(
                        array(
                            'name' => 'long_headline',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Long headline',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'short_headline',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Short headline',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'description',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Description',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'city',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'City',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'anchor',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Anchor',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'video_kicker',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Video kicker',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'section_id',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Section id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'cat_id',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Cat id',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'extra_large_img',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Extra Large img: 647*363',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'large_img',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Large img: 613*460',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'medium_img',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Medium img: 483*271',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'small_img',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Small img: 170*96',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'extra_small_img',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Extra small img: 88*50',
                            'type' => 'array',
                        ),
                        array(
                            'name' => 'video_file_name',
                            'optional' => FALSE,
                            'source' => array('data'),
                            'description' => 'Video file name',
                            'type' => 'array',
                        ),
                    ),
                ),
            ),
        ),
    );
  return $api;
}
/**
 * Call back function for testing API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_testing_report($token) {
  // code for check POST method only start
  $str = '{
	  "status_code": "0",
	  "status_message": "Customised Message",
	  "data": {}
  }';
  $jsondata = $str;
  $obj = json_decode($jsondata, TRUE);
  $return_obj = $obj;
  return $return_obj;
}
/**
 * Call back function for story_count_report API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_story_count_report() {
  $start_date = strtotime($_GET['start_date']);
  $end_date = strtotime($_GET['end_date']. " 23:59:00");
  $type = $_GET['type'];
  $status = $_GET['status'];
  $item_per_page = $_GET['item_per_page'];
  $pageno = $_GET['pageno'];
  //valid tid & pageno
  if (!is_numeric($status)) {
    $status = 0;
  }
  if (!is_numeric($item_per_page)) {
    $item_per_page = 0;
  }
  $suffix = $start_date . "_" . $end_date . "_" . $type . "_" . $status . "_" . $item_per_page . "_" . $pageno;
  if ($pageno == "na") {
    $pageno = 0;
  }
  $redis_key = "itg_report_api_story_count_report" . $suffix;
  // echo $redis_key; exit();
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = getStoryCountReport($start_date, $end_date, $type, $status, $item_per_page, $pageno);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for user_list API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_user_list() {
  $user_type = $_GET['user_type'];
  $user_sub_type = $_GET['user_sub_type'];
  if (!is_numeric($item_per_page)) {
    $item_per_page = 0;
  }
  $suffix = $user_type . "_" . $user_sub_type;
  if ($pageno == "na") {
    $pageno = 0;
  }
  $redis_key = "itg_report_api_user_list_" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    //$jsondata = getUserList_Report($user_type, $user_sub_type, $item_per_page, $pageno);
    $jsondata = getUserList_Report($user_type, $user_sub_type);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for get_story_api API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_get_story_api() {
  //p($_GET);die();
  $start_date = $_GET['start_date'];
  $end_date = $_GET['end_date'];
  $user_type = $_GET['user_type'];
  $user_sub_type = $_GET['user_sub_type'];
  $userid = $_GET['userid'];
  $content_type = $_GET['content_type'];
  //valid tid & pageno
  if (!is_numeric($status)) {
    $status = 0;
  }
  if (!is_numeric($item_per_page)) {
    $item_per_page = 0;
  }
  $suffix = $start_date . "_" . $end_date . "_" . $user_type . "_" . $user_sub_type . "_" . $userid . "_" . $content_type;
  if ($pageno == "na") {
    $pageno = 0;
  }
  $redis_key = "itg_report_api_get_story_api" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = getStoryAPI($start_date, $end_date, $user_type, $user_sub_type, $userid, $content_type);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for story_video_photo_field_report API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_story_video_photo_field_report() {
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  if ($_GET['end_date'] != "na") {
    $end_date = strtotime($_GET['end_date']. " 23:59:00");
  }
  else {
    $end_date = $_GET['end_date'];
  }
  $suffix = $start_date . "_" . $end_date;
  $redis_key = "itg_report_api_story_video_photo_field_report" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = story_video_photo_field_report($start_date, $end_date);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for author_report API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_author_report() {
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  $type = 'story';
  if($_GET['type'] == "video"){
      $type = 'videogallery';
  }

  $suffix = $type.'_'.$start_date;
  $redis_key = "itg_report_api_author_report_" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value1'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = author_report($start_date,$type);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
function itg_report_api_author_report_v1() {
  module_load_include('inc', 'itg_report_api', 'inc/itg_report_api_author_report_v1');
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  $suffix = $start_date;
  $redis_key = "itg_report_api_author_report_v1" . $suffix;
  //$result_get = getRedis($redis_key);
  if ($result_get['key_value1'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = author_report_v1($start_date);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    //$result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for author_report_tvtn API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_author_report_tvtn() {
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  $suffix = $start_date;
  $redis_key = "itg_report_api_author_report_tvtn_" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = author_report_tvtn($start_date);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for auscovery_dashboard_web API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_auscovery_dashboard_web() {
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  if ($_GET['end_date'] != "na") {
    $end_date = strtotime($_GET['end_date']. " 23:59:00");
  }
  else {
    $end_date = $_GET['end_date'];
  }
  $suffix = $start_date . "_" . $end_date;
  $redis_key = "itg_report_api_auscovery_dashboard_web" . $suffix;
  $result_get = getRedis($redis_key);

  if ($result_get['key_value1'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = auscovery_dashboard_web($start_date, $end_date);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for auscovery_dashboard_mob API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_auscovery_dashboard_mob() {
  if ($_GET['start_date'] != "na") {
    $start_date = strtotime($_GET['start_date']);
  }
  else {
    $start_date = $_GET['start_date'];
  }
  if ($_GET['end_date'] != "na") {
    $end_date = strtotime($_GET['end_date']. " 23:59:00");
  }
  else {
    $end_date = $_GET['end_date'];
  }
  $suffix = $start_date . "_" . $end_date;
  $redis_key = "itg_report_api_auscovery_dashboard_mob" . $suffix;
  $result_get = getRedis($redis_key);
  if ($result_get['key_value'] != "") {
    $jsondata = $result_get['key_value'];
  }
  else {
    // call function from return data..
    $jsondata = auscovery_dashboard_mob($start_date, $end_date);
    $jsondata = json_encode($jsondata);
    $ttl = DEFAULT_REDIS_EXPIRE_TIME;
    $result_set = setRedis($redis_key, $jsondata, $ttl);
  }
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for story_count_report API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_report_api_detail() {
  $start_date = $_GET['start_date'];
  $end_date = $_GET['end_date'];
  $type = $_GET['type'];
  $status = $_GET['status'];
  $synd = $_GET['synd'];
  $item_per_page = $_GET['item_per_page'];
  $pageno = $_GET['pageno'];
  //valid tid & pageno
  if ($status == 'publish') {
    $status = 1;
  }
  elseif ($status == 'unpublish') {
    $status = 0;
  }
  if($type == 'video'){
    $type = 'videogallery';
  }
  if($type == 'gallery'){
    $type = 'photogallery';
  }
  if (!is_numeric($item_per_page)) {
    $item_per_page = 0;
  }
  $suffix = $start_date . "_" . $end_date . "_" . $type . "_" . $status . "_" . $synd . "_" . $item_per_page."_".$pageno;
  if ($pageno == "na") {
    $pageno = 0;
  }
  $redis_key = "itg_report_api_data_list_report" . $suffix;
  $result_get = getRedis($redis_key);
  //if ($result_get['key_value'] != "") {
    //$jsondata = $result_get['key_value'];
  //}
  //else {
    // call function from return data..
    $jsondata = get_datalist_report($start_date, $end_date, $type, $status, $synd, $item_per_page, $pageno);
    $jsondata = json_encode($jsondata);
    //$ttl = 30; //DEFAULT_REDIS_EXPIRE_TIME;
    //$result_set = setRedis($redis_key, $jsondata, $ttl);
  //}
  $jsondata = json_decode($jsondata, TRUE);
  return $jsondata;
}
/**
 * Call back function for video insert API
 * @pram $_POST in JSON formate
 *
 * @return array - The processed information array.
 */

function itg_rapid_api_insert_video() {
    $HTTP_RAW_POST_DATA;
    $params = (array) json_decode(file_get_contents('php://input'), TRUE);
    p($params);
    $long_headline = $params['long_headline'];
    $short_headline = $params['short_headline'];
    $description = $params['description'];
    $city = $params['city'];
    $anchor = $params['anchor'];
    $video_kicker = $params['video_kicker'];
    $section_id = $params['section_id'];
    $cat_id = $params['cat_id'];
    $extra_large_img = $params['extra_large_img'];
    $large_img = $params['large_img'];
    $medium_img = $params['medium_img'];
    $small_img = $params['small_img'];
    $extra_small_img = $params['extra_small_img'];
    $video_file_name = $params['video_file_name'];
    //prepare node object
    $node = array(
        'uid' => 970,
        'name' => 'siteadmin',
        'type' => 'videogallery',
        'language' => LANGUAGE_NONE,
        'title' => $long_headline,
        'status' => 0,
        'promote' => 0,
        'sticky' => 0,
        'created' => (int) REQUEST_TIME,
        'revision' => 0,
        'comment' => '0',
        'path' => array(
            'alias' => '',
            'pid' => null,
            'source' => null,
            'language' => LANGUAGE_NONE,
            'pathauto' => 1,
        ),
        'nid' => null,
        'vid' => null,
        'changed' => '',
        'log' => '',
        'date' => '',
        'submit' => 'Save',
        'preview' => 'Preview',
        'private' => 0,
        'op' => 'Save',
        'body' => array(LANGUAGE_NONE => array(
                array(
                    'value' => $description,
                    'summary' => $description,
                    'format' => 'full_html',
                ),
            )),
        ///
        'field_primary_category' => array(LANGUAGE_NONE => array(
                array(
                    'value' => $section_id,
                    'safe_value' => $section_id,
                ),
            )),
        'field_story_category' => array(LANGUAGE_NONE => array(
                array(
                    'value' => $cat_id,
                ),
            )),
        'field_story_expert_description' => array(LANGUAGE_NONE => array(
                array(
                    'value' => $video_kicker,
                ),
            )),
        /* 'field_story_extra_large_image' => array(LANGUAGE_NONE => array(
          array(
          'fid' => $description,
          'uid' => $description,
          'filename' => $description,
          'uri' => $description,
          'filemime' => $description,
          'filesize' => $description,
          'status' => $description,
          'timestamp' => $description,
          'uuid' => $description,
          'rdf_mapping' => array(),
          'alt' => $description,
          'title' => $description,
          'width' => $description,
          'height' => $description,
          ),
          )), */
        'field_story_short_headline' => array(LANGUAGE_NONE => array(
                array(
                    'value' => $short_headline,
                ),
            )),
        'field_story_source_type' => array(LANGUAGE_NONE => array(
                array(
                    'value' => 'videogallery',
                    'safe_value' => 'videogallery',
                ),
            )),
        'field_stroy_city' => array(LANGUAGE_NONE => array(
                array(
                    'tid' => $city,
                ),
            )),
        'field_video_anchor' => array(LANGUAGE_NONE => array(
                array(
                    'target_id' => $anchor,
                ),
            )),
        ///
        'validated' => true,
    );

    try {
        node_save((object) $node);
        $success = TRUE;
    } catch (Exception $e) {
        // Do your error handling here.
        $success = FALSE;
    }

    $data = array();
    $data['status_code'] = "0";
    $data['status_message'] = "custom_msg";
    if ($success) {
        $data['status_code'] = "1";
        $data['status_message'] = "";
    }

    return $data;
}
