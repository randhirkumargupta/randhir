<?php

/**
 * Inc file contains the functions
 */

/**
 * main function for generate twtlogin array
 *
 * @return array
 */
function twtlogin($data){
//    echo "twtlogin<pre>";
//    print_r($data);
//    echo "</pre>";
//    exit();
    $token = $data['token'];
    $app_id_social = $data['app_id'];
    $uname_social = $data['uname'];
    $uid_social = $data['uid'];
    $issued_at_social = $data['issued_at'];
    $expires_at_social = $data['expires_at'];
    //check user name is exist in db..
    $password = $data['password'];
    $user_load = user_load_by_name($uname_social);
    if($user_load->uid){
        // user exist, next is step for login
        return userloginTWT($uname_social, $user_load->uid, $password);
    }
    else{
        // user not exist, next is step for signup
        return userSignupTWT($uname_social, $uid_social, $password);
    }
}

/**
 * main function for userloginTWT
 * @pram $uname
 * @return array
 */
function userloginTWT($uname, $uidget, $password){
    global $user;
    $username =  $uname; 
    
    if ($user->uid) {
        // user is already logged in
        return services_error(t('Already logged in as @user.', array('@user' => $user->name)), 406);
    }
    // Check if account is active.
    if (user_is_blocked($username)) {
        return services_error(t('The username %name has not been activated or is blocked.', array('%name' => $username)), 403);
    }
    
    // Emulate drupal native flood control: check for flood condition.
    $flood_state = array();
    if (variable_get('services_flood_control_enabled', TRUE)) {
        $flood_state = _user_resource_flood_control_precheck($username);
    }
    
    // Only authenticate if a flood condition was not detected.
    if (empty($flood_state['flood_control_triggered'])) {
        //echo "andy"; exit();
        $uid = $uidget;
    } else {
        $uid = FALSE;
    }

    // Emulate drupal native flood control: register flood event, and throw error
    // if a flood condition was previously detected
    if (variable_get('services_flood_control_enabled', TRUE)) {
        $flood_state['uid'] = $uid;
        _user_resource_flood_control_postcheck($flood_state);
    }
    
    if ($uid) {
        $user = user_load($uid);        
        if ($user->uid) {
            user_login_finalize();

            $return = new stdClass();
            $return->sessid = session_id();
            $return->session_name = session_name();
            $return->token = drupal_get_token('services');

            $account = clone $user;

            services_remove_user_data($account);

            $return->user = $account;
            //print_r($return);exit();
            return $return;
        }
    }
    watchdog('user', 'Invalid login attempt for %username.', array('%username' => $username));
    return services_error(t('Wrong username or password.'), 401);
}

/**
 * main function for userSignupTWT
 * @pram $uname
 * @return array
 */

function userSignupTWT($uname_social, $uid_social, $password){
    $mail = $uid_social."@twitter.com";
    $username = $uname_social;    
    $first_name = "";
    $last_name = "";
    $mobile = "";
    
    // signup method
    $form_state = array();


    // check user_id is mail or mobile
    $url_info = "aHR0cDovL2l0Z2RyYXBpZC5pbmRpYXRvZGF5b25saW5lLmluL2luZGlhL3N0b3J5L2Rpd2FsaS1zbW9rZS1wb2xsdXRpb24tcGFydGljdWxhdGUtbWF0dGVyLTM0OTQ2Ny0yMDE2LTEwLTMx";
    
    $form_state['values']['mobile'] = "";
    $form_state['values']['url_info'] = $url_info;
    $form_state['values']['mail'] = $mail;
    // prepare array for user
    $edit = array(
        'name' => $username,
        'pass' => $password,
        'mail' => $mail,
        'init' => $mail,
        'status' => 1,
        'access' => REQUEST_TIME,
        'field_first_name' => array(
            LANGUAGE_NONE => array(
                0 => array(
                    'value' => $first_name
                )
            )
        ),
        'field_last_name' => array(
            LANGUAGE_NONE => array(
                0 => array(
                    'value' => $last_name
                )
            )
        ),
        'roles' => array(
            2 => 'authenticated',
            FRONT_USER => 'Front User',
        ),
    );

    if (is_numeric($mobile)) {
        $edit['field_mobile_number'] = array(LANGUAGE_NONE => array(
                0 => array(
                    'value' => $mobile
                )
            )
        );
    }


    try {

        $account = user_save(NULL, $edit);

        if (function_exists('itg_personalization_reddem_referfriend')) {
            itg_personalization_reddem_referfriend($_SESSION['referral_key']);
            unset($_SESSION['referral_key']);
        }
        // Set operation.

        $op = 'register_no_approval_required';
        // Send an email.
        if (empty($form_state['values']['mobile'])) {
            // _user_mail_notify($op, $account);
            if (function_exists('itg_sso_get_mail_content')) {
                if (!empty($form_state['values']['url_info'])) {
                    $url_info = $form_state['values']['url_info'];
                }
                $mail_content = itg_sso_get_mail_content($account, $mail, $url_info);
            }
            itg_user_mapping_activate($account->uid);
        } else {
            $rand_otp = rand(0, 9999);
            if (function_exists('itg_sso_first_time_otp_insert')) {
                itg_sso_first_time_otp_insert($mobile, $mail, $rand_otp, 'register');
                itg_sso_sms_send($rand_otp, $mobile);
            }
            if (!empty($form_state['values']['mail'])) {
                itg_sso_otp_mail_content($rand_otp, $mail);
            }
        }
    } catch (Exception $e) {
        watchdog('error on user save', $e->getMessage());
        drupal_set_message('Error:' . $e->getMessage(), 'error');
        $account = $e;
    }
    //return $account;
    if($account->uid)
        return userloginTWT($uname_social, $account->uid, $password);
    else{
        return $account;
    }
    
}
