<?php
/**
 * @file
 * feature_for_sso_rest_services.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function feature_for_sso_rest_services_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'appapisso';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'appapisso';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
      'application/x-www-form-urlencoded' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'change_password' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'check_user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'edit_profile' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'edit_user_image' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'fblogin' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'forgot_password' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get_login_user_detail' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get_otp' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get_preference' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'log_out' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'login_request' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'otp_verification' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'resend_otp' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'reset_password' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'signup' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'testing' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'twtlogin' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'update_preference' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['appapisso'] = $endpoint;

  return $export;
}
