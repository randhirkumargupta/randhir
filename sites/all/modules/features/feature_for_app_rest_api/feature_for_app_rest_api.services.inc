<?php
/**
 * @file
 * feature_for_app_rest_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function feature_for_app_rest_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'appapi';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'appapi';
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
    'ad_config_json' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'adconfig_android' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'adconfig_ipad' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'adconfig_iphone' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'adconfig_tab' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'anchor_detail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'anchor_follow_list' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'anchor_list' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'anchor_programm_list' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'author_detail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'author_follow_list' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'author_list' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'author_report' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'author_story_list' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'authtoken_verification' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'bookmark_delete' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'bookmark_get' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'bookmark_set' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'cast_polls' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'change_password' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'comment' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'countAll' => array(
          'enabled' => '1',
        ),
        'countNew' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'config_update_status' => array(
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
    'file' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
        'retrieve' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'create_raw' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'follow_anchor' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'follow_author' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'follow_topic' => array(
      'operations' => array(
        'create' => array(
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
    'get_preference' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get_story_api' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get_the_user_follow_status' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'hamburger_menu' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'home' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'horizontal_menu' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'livetv_aajtak' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'livetv_channellist' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'livetv_delhiaajtak' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'livetv_indiatoday' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'livetv_tej' => array(
      'operations' => array(
        'retrieve' => array(
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
    'magazine_coverstories' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'magazine_edition' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'magazine_editionlist' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'master_config' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'newslist' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'newswrap' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'node' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'relationships' => array(
        'files' => array(
          'enabled' => '1',
        ),
        'comments' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'attach_file' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'otherapps_android' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'otherapps_ios' => array(
      'operations' => array(
        'retrieve' => array(
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
    'photodetail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'photolist' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'photostorydetail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'poll_detail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'polls_close' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'polls_open' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'program_category_list' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'programlist' => array(
      'operations' => array(
        'retrieve' => array(
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
    'server_error_master' => array(
      'operations' => array(
        'retrieve' => array(
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
    'storydetail' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
        ),
        'get_variable' => array(
          'enabled' => '1',
        ),
        'set_variable' => array(
          'enabled' => '1',
        ),
        'del_variable' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'taxonomy_term' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'selectNodes' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'taxonomy_vocabulary' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'retrieveByMachineName' => array(
          'enabled' => '1',
        ),
        'getTree' => array(
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
    'update_preference' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
        'create' => array(
          'enabled' => '1',
        ),
        'update' => array(
          'enabled' => '1',
        ),
        'delete' => array(
          'enabled' => '1',
        ),
        'index' => array(
          'enabled' => '1',
        ),
      ),
      'actions' => array(
        'login' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'logout' => array(
          'enabled' => '1',
          'settings' => array(
            'services' => array(
              'resource_api_version' => '1.0',
            ),
          ),
        ),
        'token' => array(
          'enabled' => '1',
        ),
        'request_new_password' => array(
          'enabled' => '1',
        ),
        'user_pass_reset' => array(
          'enabled' => '1',
        ),
        'register' => array(
          'enabled' => '1',
        ),
      ),
      'targeted_actions' => array(
        'cancel' => array(
          'enabled' => '1',
        ),
        'password_reset' => array(
          'enabled' => '1',
        ),
        'resend_welcome_email' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user_follow_topic_list' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'user_list' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'videolist' => array(
      'operations' => array(
        'retrieve' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['appapi'] = $endpoint;

  return $export;
}
