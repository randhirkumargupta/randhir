<?php

//ini_set('display_errors', 1);
//error_reporting(E_ALL);

if (!defined('DS')) {
  define('DS', DIRECTORY_SEPARATOR);
}
if (!defined('ROOTPATH_API')) {
  define('ROOTPATH_API', dirname(__DIR__));
}

/*  AKAMAI */
define('AKAMAI_BASE_URI', variable_get('itg_akamai_basepath'));
define('AKAMAI_API_ENDPOINT', variable_get('itg_akamai_api_endpoint'));
define('AKAMAI_CLIENT_TOKEN', variable_get('itg_akamai_client_token'));
define('AKAMAI_CLIENT_SECRET', variable_get('itg_akamai_client_secret'));
define('AKAMAI_ACCESS_TOKEN', variable_get('itg_akamai_access_token'));

module_load_include('phar', 'itg_akamai', 'akamai_api/akamai-open-edgegrid-client');

use Akamai\Open\EdgeGrid\Client;
use Akamai\Open\EdgeGrid\Authentication;

class ItgAkamaiUtility {

  function __construct() {
    
  }

  static function itgAkamaiSetActivityLog($data) {
    if (isset($data) && !empty($data)) {

      try {
        foreach ($data as $fields) {
          $akamai_activity = db_insert('itg_akamai_log')
              ->fields($fields)
              ->execute();
        }
      }
      catch (Exception $e) {
        die($e->getMessage());
      }
    }
  }

  static function itgAkamaiSetDataForLog($request, $response, $uid, $status, $purge_id) {
    $data = array();
    $data['timestamp'] = time();
    if ($status == 201) {
      $data['status'] = 1;
    }
    else {
      $data['status'] = 0;
    }
    $data['purge_id'] = $purge_id;
    $data['uid'] = $uid;
    $data['akamai_request'] = $request;
    $data['akamai_response'] = $response;
    return $data;
  }

  static function itgAkamaiGetDataForLog($urls, $request, $response, $uid, $status, $purge_id) {
    $data = array();
    foreach ($urls as $url) {
      $data[] = array(
        'timestamp' => REQUEST_TIME,
        'status' => $status,
        'purge_id' => $purge_id,
        'uid' => $uid,
        'url' => $url,
        'akamai_request' => $request,
        'akamai_response' => $response,
      );
    }

    return $data;
  }

}
