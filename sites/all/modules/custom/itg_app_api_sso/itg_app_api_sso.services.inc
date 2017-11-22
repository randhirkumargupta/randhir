<?php

/**
 * @file
 * INC file for APP API Schemes Services.
 * Contains the resource declarations for the service APIs
 * and other commons functions/hooks. if necessary
 */

module_load_include('inc', 'itg_app_api_sso', 'inc/itg_app_api_sso_fblogin');
module_load_include('inc', 'itg_app_api_sso', 'inc/itg_app_api_sso_twtlogin');
module_load_include('inc', 'itg_app_api_sso', 'inc/itg_app_api_sso_edit_profile');

/**
 * itg_app_api_sso_resource function().
 * @return array
 */
function itg_app_api_sso_resource() {

  /**
   * custom resource SSO based API
   */
  $api = array(
    // login_request custom resource declaration.....
    'login_request' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves storydetail schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_login_request_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user email or mobile',
              'type' => 'array',
            ),
            array(
              'name' => 'password',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user password',
              'type' => 'array',
            ),
            array(
              'name' => 'device_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'device_id ',
              'type' => 'array',
            ),
            array(
              'name' => 'token_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'device_type',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // signup custom resource declaration.....
    'signup' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves storydetail schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_signup_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'first_name',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'First Name',
              'type' => 'array',
            ),
            array(
              'name' => 'last_name',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Last Name',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'User email or mobile number',
              'type' => 'array',
            ),
            array(
              'name' => 'password',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Password',
              'type' => 'array',
            ),
            array(
              'name' => 'confirm_password',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Confirm Password',
              'type' => 'array',
            ),
            array(
              'name' => 'login_type',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => '0=for traditional, 1=socail media',
              'type' => 'array',
            ),
            array(
              'name' => 'email_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Email Id',
              'type' => 'array',
            ),
            array(
              'name' => 'phone_number',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Phone Number',
              'type' => 'array',
            ),
            array(
              'name' => 'location',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Location',
              'type' => 'array',
            ),
            array(
              'name' => 'profile_image',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Profile image',
              'type' => 'array',
            ),
            array(
              'name' => 'gender',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Gender',
              'type' => 'array',
            ),
            array(
              'name' => 'date_of_birth',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Date of birth',
              'type' => 'array',
            ),
            array(
              'name' => 'device_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Device id',
              'type' => 'array',
            ),
            array(
              'name' => 'device_type',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'Device type',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // fblogin custom resource declaration.....
    'fblogin' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves fblogin schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_fblogin_sso',
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
            array(
              'name' => 'app_id',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'application master id',
              'type' => 'string',
            ),
            array(
              'name' => 'uname',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'username (in socail login)',
              'type' => 'string',
            ),
            array(
              'name' => 'uid',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'uid (in socail login)',
              'type' => 'int',
            ),
            array(
              'name' => 'issued_at',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'in timestamp',
              'type' => 'int',
            ),
            array(
              'name' => 'expires_at',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'in timestamp',
              'type' => 'int',
            ),
          ),
        ),
      ),
    ),
    // twtlogin custom resource declaration.....
    'twtlogin' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves twtlogin schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_twtlogin_sso',
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
            array(
              'name' => 'app_id',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'application master id',
              'type' => 'string',
            ),
            array(
              'name' => 'uname',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'username (in socail login)',
              'type' => 'string',
            ),
            array(
              'name' => 'uid',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'uid (in socail login)',
              'type' => 'int',
            ),
            array(
              'name' => 'issued_at',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'in timestamp',
              'type' => 'int',
            ),
            array(
              'name' => 'expires_at',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'in timestamp',
              'type' => 'int',
            ),
          ),
        ),
      ),
    ),
    // forgot_password custom resource declaration.....
    'forgot_password' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves forgot_password schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_forgot_password_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user mobile or email',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // otp_verification custom resource declaration.....
    'otp_verification' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves otp_verification schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_otp_verification_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user mobile or email',
              'type' => 'array',
            ),
            array(
              'name' => 'otp_code',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'otp_code',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // resend_otp custom resource declaration.....
    'resend_otp' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves resend_otp schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_resend_otp_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user mobile or email',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // change_password custom resource declaration.....
    'change_password' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves change_password schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_change_password_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user mobile or email',
              'type' => 'array',
            ),
            array(
              'name' => 'old_pass',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'password',
              'type' => 'array',
            ),
            array(
              'name' => 'new_pass',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'confirm password',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // edit_profile custom resource declaration.....
    'edit_profile' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves edit_profile schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_edit_profile_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'authtoken_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'authtoken_id',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
            array(
              'name' => 'first_name',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'first_name',
              'type' => 'array',
            ),
            array(
              'name' => 'last_name',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'last_name',
              'type' => 'array',
            ),
            array(
              'name' => 'zipcode',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'zipcode',
              'type' => 'array',
            ),
            array(
              'name' => 'address',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'address',
              'type' => 'array',
            ),
            array(
              'name' => 'profile_image',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'profile_image',
              'type' => 'array',
            ),
            array(
              'name' => 'gender',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'gender',
              'type' => 'array',
            ),
            array(
              'name' => 'date_of_birth',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'date_of_birth',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // edit_user_image custom resource declaration.....
    'edit_user_image' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves edit_user_image schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_edit_user_image_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'authtoken_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'authtoken_id',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
            array(
              'name' => 'profile_image',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'profile_image',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // get_login_user_detail custom resource declaration.....
    'get_login_user_detail' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves get_login_user_detail schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_get_login_user_detail_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'authtoken_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'authtoken_id',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // log_out custom resource declaration.....
    'log_out' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves log_out schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services_sso',
          ),
          'callback' => 'itg_rapid_api_log_out_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // get_preference custom resource declaration.....
    'get_preference' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves get_preference schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_get_preference_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'authtoken_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'authtoken_id',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // update_preference custom resource declaration.....
    'update_preference' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves update_preference schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_update_preference_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'authtoken_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'authtoken_id',
              'type' => 'array',
            ),
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user_id',
              'type' => 'array',
            ),
            array(
              'name' => 'preference',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'node_id',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // for static other device end
    // check_user custom resource declaration.....
    'check_user' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves check_user schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_check_user_sso',
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
            array(
              'name' => 'user_id',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'user_id',
              'type' => 'string',
            ),
          ),
        ),
      ),
    ),
    // get_otp custom resource declaration.....
    'get_otp' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves adconfig_tab schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_get_otp_sso',
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
            array(
              'name' => 'user_id',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'user_id',
              'type' => 'string',
            ),
          ),
        ),
      ),
    ),
    // reset_password custom resource declaration.....
    'reset_password' => array(
      'operations' => array(
        'create' => array(
          'help' => 'Retrieves change_password schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_reset_password_sso',
          'access callback' => 'user_access',
          'access arguments' => array('access content'),
          'access arguments append' => FALSE,
          'args' => array(
            array(
              'name' => 'user_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'user mobile or email',
              'type' => 'array',
            ),
            array(
              'name' => 'new_password',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'new password',
              'type' => 'array',
            ),
            array(
              'name' => 'confirm_password',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'confirm password',
              'type' => 'array',
            ),
            array(
              'name' => 'device_id',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'device id',
              'type' => 'array',
            ),
            array(
              'name' => 'device_type',
              'optional' => TRUE,
              'source' => array('data'),
              'description' => 'device type',
              'type' => 'array',
            ),
          ),
        ),
      ),
    ),
    // testing custom resource declaration.....
    'testing' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieves testing schemes info.',
          'file' => array(
            'type' => 'inc',
            'module' => 'itg_app_api_sso',
            'name' => 'itg_app_api_sso.services',
          ),
          'callback' => 'itg_rapid_api_testing_sso',
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
  );

  return $api;
}

/**
 * resource callback function
 */

/**
 * Call back function for login_request API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_login_request_sso($token) {

  drupal_session_start();
  $user_id = $username = $_POST['user_id'];
  $password = $password = $_POST['password'];

  if ($user->uid) {
    // user is already logged in
    return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
  }

  // Check if account is active.
  if (user_is_blocked($username)) {
    return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
  }

  $resp = array();
  $user_id = $_POST['user_id'];
  $password = $_POST['password'];
  // login sso user user
  $form_state = array();
  $form_state['values']['name'] = $user_id;
  $form_state['values']['pass'] = $password;
  $form_state['values']['op'] = t('Log in');
  $resp = drupal_form_submit('user_login', $form_state);
  $resp1 = form_get_errors();
  $data = array();
  global $user;
  $data['user'] = $user;
  $data['session'] = $_SESSION;
  if ($user->uid) {
    return $user;
  }
  watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
  return services_error(t('Wrong username or password.'), 401);
}

/**
 * Call back function for signup API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_signup_sso($token) {


  $first_name = $_POST['first_name'];
  $last_name = $_POST['last_name'];
  $user_id = $_POST['user_id'];
  $password = $_POST['password'];
  $login_type = $_POST['login_type'];
  $token_id = $_POST['token_id'];
  $form_state = array();


  // check user_id is mail or mobile
  $url_info = substr(uniqid('', true), -5);
  $mail_flag = 1;
  if (preg_match('/^\d{10}$/', $user_id)) {
    $mail_flag = 0;
    $mobile = $user_id;
    $mail = $first_name . '@' . 'nowhere.com';
  }
  else {
    $mobile = "";
    $mail = $user_id;
  }
  $form_state['values']['mobile'] = $mobile;
  $form_state['values']['url_info'] = $url_info;
  if ($mail_flag) {
    $form_state['values']['mail'] = $mail;
  }
  else {
    $form_state['values']['mail'] = "";
  }
  if ($_POST['email_id'] != "" && filter_var($_POST['email_id'], FILTER_VALIDATE_EMAIL)) {
    $mail = $_POST['email_id'];
  }
  // prepare array for user
  $edit = array(
    'name' => $user_id,
    'pass' => $password,
    'mail' => $mail,
    'init' => $mail,
    'status' => 1,
    'access' => REQUEST_TIME,
    'field_first_name' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $first_name,
        ),
      ),
    ),
    'field_last_name' => array(
      LANGUAGE_NONE => array(
        0 => array(
          'value' => $last_name,
        ),
      ),
    ),
    'roles' => array(
      2 => 'authenticated',
      25 => 'Front User',
    ),
  );

  if (is_numeric($mobile)) {
    $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
        0 => array(
          'value' => $mobile,
        ),
      ),
    );
  }


  try {

    $account = user_save(NULL, $edit);
    updateUsedrProfileAtSignup_rapid_sso($_POST, $action = 1);

    if (function_exists('itg_personalization_reddem_referfriend')) {
      itg_personalization_reddem_referfriend($_SESSION['referral_key']);
      unset($_SESSION['referral_key']);
    }
    // Set operation.

    $op = 'register_no_approval_required';
    // Send an email.
    if (empty($form_state['values']['mobile'])) {
      if (function_exists('itg_sso_get_mail_content')) {
        if (!empty($form_state['values']['url_info'])) {
          $url_info = $form_state['values']['url_info'];
        }
      }
    }
    else {
      $rand_otp = rand(0, 9999);
      if (function_exists('itg_sso_first_time_otp_insert')) {
        itg_sso_first_time_otp_insert($mobile, $mail, $rand_otp, 'register');
      }
    }
  }
  catch (Exception$e) {
    watchdog('error on user save', $e->getMessage());
    drupal_set_message('Error:' . $e->getMessage(), 'error');
    $account = $e;
  }
  return $account;
}

/**
 * Call back function for fblogin API
 * @pram $_GET
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_fblogin_sso($token) {
  return fblogin_sso($_GET);
}

/**
 * Call back function for twtlogin API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_twtlogin_sso($token) {
  return twtlogin_sso($_POST);
}

/**
 * Call back function for forgot_password API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_forgot_password_sso($token) {

  $ufname = $user_id = $_POST['user_id'];
  $msg = "";
  $data = array();


  if (is_numeric($ufname)) {
    $rand_otp = rand(0, 9999);
    if (function_exists(itg_sso_first_time_otp_insert)) {
      itg_sso_first_time_otp_insert($ufname, $email = '', $rand_otp, 'reset');
      itg_sso_sms_send($rand_otp, $ufname);
    }
    //drupal_set_message('Please check your mobile for otp');
    $msg = "Please check your mobile for otp";
    // to do mobile script for sending sms
  }
  else {
    $rand_otp = rand(0, 9999);
    if (function_exists(itg_sso_first_time_otp_insert)) {
      itg_sso_first_time_otp_insert($mobile = '', $ufname, $rand_otp, 'reset');
    }
    if (function_exists(itg_forgot_otp_content)) {
      $mail_content = itg_forgot_otp_content($rand_otp, $ufname);
    }
    //drupal_set_message('Please check your mail for otp');
    $msg = "Please check your mobile for otp";
  }

  $data['status_code'] = "1";
  $data['status_message'] = "Please check your mobile for otp";

  return $data;
}

/**
 * Call back function for otp_verification API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_otp_verification_sso($token) {

  $ufname = $user_id = $_POST['user_id'];
  $uotp = $_POST['otp_code'];
  $msg = "";
  $data = array();

  if (is_numeric($ufname)) {
    $mail = "";
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($ufname);
    }
    if (function_exists(itg_sso_otp_delete)) {
      $resp = itg_sso_otp_check_ser_sso($mail, $ufname, $uotp);
    }
  }
  else {
    $mobile = "";
    if (function_exists(itg_sso_user_email_check)) {
      $get_user_check_email = itg_sso_user_email_check($ufname);
    }
    if (function_exists(itg_sso_otp_delete)) {
      $resp = itg_sso_otp_check_ser_sso($ufname, $mobile, $uotp);
    }
  }



  return $resp;
}

/**
 * Call back function for resend_otp API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_resend_otp_sso($token) {
  $ufname = $user_id = $_POST['user_id'];
  $msg = "";
  $data = array();


  if (is_numeric($ufname)) {
    $rand_otp = rand(0, 9999);
    if (function_exists(itg_sso_first_time_otp_insert)) {
      itg_sso_first_time_otp_insert($ufname, $email = '', $rand_otp, 'reset');
      itg_sso_sms_send($rand_otp, $ufname);
    }
    //drupal_set_message('Please check your mobile for otp');
    $msg = "Please check your mobile for otp";
    // to do mobile script for sending sms
  }
  else {
    $rand_otp = rand(0, 9999);
    if (function_exists(itg_sso_first_time_otp_insert)) {
      itg_sso_first_time_otp_insert($mobile = '', $ufname, $rand_otp, 'reset');
    }
    if (function_exists(itg_forgot_otp_content)) {
      $mail_content = itg_forgot_otp_content($rand_otp, $ufname);
    }
    //drupal_set_message('Please check your mail for otp');
    $msg = "Please check your mobile for otp";
  }

  $data['status_code'] = "1";
  $data['status_message'] = "Please check your mobile for otp";

  return $data;
}

/**
 * Call back function for change_password API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_change_password_sso($token) {
  $uname = $user_id = $_POST['user_id'];
  $pass = $_POST['new_password'];
  $pass2 = $_POST['confirm_password'];
  $msg = "";
  $data = array();
  if (is_numeric($uname)) {
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($uname);
    }
    if (!empty($get_user_check_mobile)) {
      $account = user_load($get_user_check_mobile);
    }
  }
  else {
    if (function_exists(itg_sso_user_email_check)) {
      $get_user_check_email = itg_sso_user_email_check($uname);
    }
    if (!empty($get_user_check_email)) {
      $account = user_load($get_user_check_email);
    }
  }


  $edit = array('pass' => $pass2);

  // Save the account with the new password.
  $flag = user_save($account, $edit);



  return $flag;
}

/**
 * Call back function for edit_profile API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_edit_profile_sso($token) {
  $flag = saveUpdatedProfile_sso($_POST);
  return $flag;
}

/**
 * Call back function for edit_user_image API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_edit_user_image_sso($token) {
  global $user;
  $data = array();
  $user_id = $_POST['user_id'];
  $profile_image = $_POST['profile_image'];
  $user_detail = user_load_by_name($user_id);
  $uid = $user_detail->uid;
  // check mime-type
  $profile_img = base64_decode($profile_image);
  $f = finfo_open();
  $mime_type = finfo_buffer($f, $profile_img, FILEINFO_MIME_TYPE);
  $mime_type_ar = explode("/", $mime_type);
  $mime_type_ext = $mime_type_ar[1];



  $image_name = 'profileimage_' . $uid . "." . $mime_type_ext;
  $profile_img_tmp = '/tmp/profileimage_' . $uid . "." . $mime_type_ext;

  // crate profile img tmp file
  file_put_contents($profile_img_tmp, $profile_img);

  $imagedata = file_get_contents($profile_img_tmp);
  $file_data = file_save_data($imagedata, file_default_scheme() . '://' . $image_name);


  // Update profile pic
  if (!empty($file_data->fid)) {
    $user_detail->field_user_picture['und'][0]['fid'] = $file_data->fid;
  }

  // Save user object.
  $resp = user_save($user_detail);
  if ($resp->uid) {
    $data['status_code'] = "1";
    $data['status_message'] = "";
  }
  else {
    $data['status_code'] = "0";
    $data['status_message'] = "Technical Error.";
  }
  return $data;
}

/**
 * Call back function for get_login_user_detail API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_login_user_detail_sso($token) {
  $data = array();
  $authtoken_id = $_POST['$_POST'];
  $user_id = $_POST['user_id'];
  $account = user_load_by_name($user_id);
  $user_id = $account->uid;
  $first_name = $account->field_first_name['und'][0]['value'];
  $last_name = $account->field_last_name['und'][0]['value'];
  $email_id = $account->mail;
  $phone_number = $account->field_mobile_number['und'][0]['value'];
  $location = "";
  if ($account->field_personalization_city['und'][0]['value']) {
    $location .= $account->field_personalization_city['und'][0]['value'];
  }
  if ($account->field_personalization_state['und'][0]['value']) {
    $location .= ", " . $account->field_personalization_state['und'][0]['value'];
  }
  if ($account->field_user_counrty['und'][0]['value']) {
    $location .= ", " . $account->field_user_counrty['und'][0]['value'];
  }
  if ($account->field_short_description['und'][0]['value']) {
    $location .= ", " . $account->field_short_description['und'][0]['value'];
  }

  $profile_image = $account->field_user_picture['und'][0]['fid'];
  $gender = $account->field_user_gender['und'][0]['value'];
  $date_of_birth = $account->field_story_issue_date['und'][0]['value'];
  $login_type = "na";

  $data['status_code'] = "1";
  $data['status_message'] = "customised_message";

  $data['data']['user_profile_detail']['token_id'] = "$authtoken_id";
  $data['data']['user_profile_detail']['login_type'] = "$login_type";
  $data['data']['user_profile_detail']['user_id'] = "$user_id";
  $data['data']['user_profile_detail']['first_name'] = "$first_name";
  $data['data']['user_profile_detail']['last_name'] = "$last_name";
  $data['data']['user_profile_detail']['email_id'] = "$email_id";
  $data['data']['user_profile_detail']['phone_number'] = "$phone_number";
  $data['data']['user_profile_detail']['location'] = "$location";
  $data['data']['user_profile_detail']['profile_image'] = "$profile_image";
  $data['data']['user_profile_detail']['gender'] = "$gender";
  $data['data']['user_profile_detail']['date_of_birth'] = "$date_of_birth";

  return $data;
}

/**
 * Call back function for log_out API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_log_out_sso($token) {
  global $base_url;
  $data = array();
  $user_id = $_POST['user_id'];
  $user = user_load_by_name($user_id);

  watchdog('user', 'Session closed for %name.', array('%name' => $user->name));

  $original_session_state = drupal_save_session();
  drupal_save_session(TRUE);

  // Destroy the current session.
  module_invoke_all('user_logout', $user);
  session_destroy();

  // Load the anonymous user.
  $user = drupal_anonymous_user();

  drupal_save_session($original_session_state);
  $data['status_code'] = "1";
  $data['status_message'] = "customised_message";

  return $data;
}

/**
 * Call back function for get_preference API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_preference_sso($token) {
  $user_id = $_POST['user_id'];
  $account = user_load_by_name($user_id);

  $user_id = $account->uid;
  $last_access = $account->access;
  $last_access_date = date('Y-m-d h:m:s', $last_access);
  $weight_count_loop = FALSE;
  $tid_array = array();
  $tid_value = array();
  $data = array();
  // As in table itg_widget_order tid is saved in nid colom.
  // So join field_story_category_tid join is applied on nid.
  // get personalization-preferences tid
  $query = db_select('itg_widget_order', 'iwo');
  // Orderby weight or taxonomyterm id.
  $query->fields('iwo', array('weight', 'nid'))->condition('iwo.widget', "personalization_widget")->condition('iwo.extra', $user_id)
      ->orderBy('iwo.weight', 'DESC')->orderBy('iwo.nid', 'DESC')->range(0, 30);
  $result = $query->execute()->fetchAllAssoc('nid');
  $new_array_of_terms = array_keys($result);
  // case handled if perferences is not saved.
  if (count($result) == 0) {
    $weight_count_loop = TRUE;
    $query = db_select('itg_widget_order', 'iwo');
    $query->leftJoin('field_data_field_set_as_featured_cate', 'fc', 'fc.entity_id=iwo.cat_id');
    $query->fields('iwo', array('cat_id'))->condition('iwo.widget', "section_wise_widget")->condition('fc.field_set_as_featured_cate_value', 'Yes')->groupBy('iwo.cat_id')->range(0, 30);
    $result = $query->execute()->fetchAllAssoc('cat_id');
  }
  if ($weight_count_loop) {
    $new_array_of_terms = array();
    // Get only tids.
    $tids_array = array_keys($result);
    foreach ($tids_array as $term_id) {
      $new_array_of_terms[$term_id] = count_node_under_tid($term_id);
    }
    krsort($new_array_of_terms);
  }
  $tid_array = ($weight_count_loop) ? array_keys($new_array_of_terms) : $new_array_of_terms;
  // return data of personalization-preferences value
  $data['status_code'] = "1";
  $data['status_message'] = "customised_message";
  $data['data']['updated_datetime'] = "$last_access_date";
  $data['data']['preference_type'] = "default/implicit/explicit";
  $loop_count = 0;
  //get personalization-preferences value
  foreach ($tid_array as $key => $value) {
    $prefeance = itg_rapid_api_get_personalization_saved_value_sso($value, $user_id);
    $term = taxonomy_term_load($value);
    $term_name = $term->name;
    $data['data']['preference'][$loop_count]['id'] = "$value";
    $data['data']['preference'][$loop_count]['title'] = "$term_name";
    $data['data']['preference'][$loop_count]['is_preffered'] = "$prefeance";
    $loop_count++;
  }

  return $data;
}

/**
 * call back function for get_personalization_saved_value
 *
 * @param int $tid
 *
 * @return array
 */
function itg_rapid_api_get_personalization_saved_value_sso($tid, $uid) {
  if (!empty($tid) && !empty($uid)) {
    $query = db_select('itg_widget_order', 'iwo');
    $query->addField('iwo', 'weight');
    $query->condition('iwo.nid', $tid);
    $query->condition('iwo.extra', $uid);
    return $query->execute()->fetch();
  }
}

/**
 * function for itg_rapid_api_update_preference
 *
 * @param array
 *
 * @return array
 *
 */
function itg_rapid_api_update_preference_sso($token) {
  return $_POST;
}

/**
 * function for itg_rapid_api_update_preference
 *
 * @param int $tid
 *
 * @return array
 */
function update_preference($user_id, $tid) {
  global $user;
  $widget_name = "personalization_widget";

  $nids = array_keys($updates);
  // Delete all the tids from table if they are not in $updates variable
  // unsued tid should be delete
  db_delete('itg_widget_order')->condition('widget', $widget_name)->condition('nid', $nids, "NOT IN")->condition('extra', $user->uid)->execute();
  // Update the weight of tids if exists or insert if dont exists.
  foreach ($updates as $term_id => $weight) {
    db_merge('itg_widget_order')->key(array('nid' => $term_id, 'widget' => $widget_name, 'extra' => $user->uid))->fields(array(
      'nid' => $term_id,
      'widget' => $widget_name,
      'weight' => $weight,
      'extra' => $user->uid,
    ))->execute();
  }
  drupal_set_message(t("My Preferences Has Been Save."));
}

/**
 * Call back function for check_user API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_check_user_sso($token) {
  $uname = $_GET['user_id'];

  $account = user_load_by_name($uname);
  return $account;
}

/**
 * Implements itg_sso_otp_check_ser_sso
 *
 * @param int $mobile
 * @param string $email
 * @param string $opt
 */
function itg_sso_otp_check_ser_sso($mail, $mobile, $opt) {
  //echo $mail; echo "<br>"; echo $mobile;
  $otp_check = db_select('itg_sso_reg_otp_info', 'opti');
  $otp_check->fields('opti', array('mobile', 'email', 'otp'));

  if (!empty($mobile) && empty($mail)) {
    $otp_check->condition('opti.mobile', $mobile, '=');
    $otp_check->condition('opti.otp', $opt, '=');
  }
  if (!empty($mail) && empty($mobile)) {
    $otp_check->condition('opti.email', $mail, '=');
    $otp_check->condition('opti.otp', $opt, '=');
  }

  $res = $otp_check->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $res;
}

/**
 * Call back function for get_otp API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_get_otp_sso($token) {
  //$_GET['user_id'] = 'sandy765@mailinator.com';
  $uname = $_GET['user_id'];

  $otp_check = db_select('itg_sso_reg_otp_info', 'opti');
  $otp_check->fields('opti', array('otp', 'created'));
  if (is_numeric($uname)) {
    $otp_check->condition('opti.mobile', $uname, '=');
  }
  else {
    $otp_check->condition('opti.email', $uname, '=');
  }
  // ORDER BY created
  $otp_check->orderBy('id', 'DESC');
  $otp_check->range(0, 1);

  $res = $otp_check->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $res;
}

/**
 * Call back function for reset_password API
 * @pram $_POST
 *
 * @return array - The processed information array.
 */
function itg_rapid_api_reset_password_sso($token) {
  $uname = $user_id = $_POST['user_id'];
  $pass = $_POST['new_password'];
  $pass2 = $_POST['confirm_password'];
  $msg = "";
  $data = array();
  if (is_numeric($uname)) {
    if (function_exists(itg_sso_user_mobile_check)) {
      $get_user_check_mobile = itg_sso_user_mobile_check($uname);
    }
    if (!empty($get_user_check_mobile)) {
      $account = user_load($get_user_check_mobile);
    }
  }
  else {
    if (function_exists(itg_sso_user_email_check)) {
      $get_user_check_email = itg_sso_user_email_check($uname);
    }
    if (!empty($get_user_check_email)) {
      $account = user_load($get_user_check_email);
    }
  }


  $edit = array('pass' => $pass2);

  // Save the account with the new password.
  $flag = user_save($account, $edit);
  return $flag;
}

/**
 * itg_rapid_api_testing_sso function().
 * @param type $token
 * @return type
 */
function itg_rapid_api_testing_sso($token) {
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
