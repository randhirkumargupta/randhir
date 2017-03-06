<?php
/**
 * Get Duplicate Email
 * @param string $email
 */
function itg_sso_user_email_check($email) {
  
  $sso_user_check_email = db_select('users', 'u')->fields('u', array('uid'));
  $sso_user_check_email->condition('u.mail', $email, '=');
  $result = $sso_user_check_email->execute()->fetchfield();
  return $result;
  
}

/**
 * Get Duplicate mobile.
 * @param int $mobile
 */
function itg_sso_user_mobile_check($mobile) {
  
  $sso_user_check_mobile = db_select('users', 'u')->fields('u', array('uid'));
  $sso_user_check_mobile->condition('u.name', $mobile, '=');
  $result = $sso_user_check_mobile->execute()->fetchfield();
  return $result;
  
}

/**
 * Get otp value by mobile or email.
 * @param int $mobile
 * @param string $email
 * @param string $source
 */
function itg_sso_reg_get_otp($mobile, $mail, $source) {
  $otp_check = db_select('itg_sso_reg_otp_info', 'otv')->fields('otv', array('otp'));
  $otp_check->condition('source',$source ,'=');
  if(!empty($mobile) && empty($email)) {
  $otp_check->condition('otv.mobile', $mobile, '=');
  }
  if(!empty($email) && empty($mobile)) {
    $otp_check->condition('otv.email', $email, '=');
  }
  if(!empty($email) && !empty($mobile)) {
    $otp_check->condition('otv.mobile', $mobile, '=');
    $otp_check->condition('otv.email', $email, '=');
  }

  $otp_check->orderBy('id', 'DESC');//ORDER BY created
  $otp_check ->range(0,1);  
  $result = $otp_check->execute()->fetchfield();
  return $result;
}

/**
 * Implement itg_sso_otp_callback
 */
function itg_sso_reg_otp_callback() {

  $mobile = $_POST['mobile'];
  $email = $_POST['email'];
  $rand_otp = $_POST['otp'];
  $source = $_POST['source'];
  $otp_exist = itg_sso_otp_check($mobile, $email, $source);

  if ($otp_exist) {
    $otp = db_update('itg_sso_reg_otp_info');
    $otp->expression('otp_count', 'otp_count + 1');// Table name no longer needs {}
    $otp->condition('id', $otp_exist, '=');
    $otp ->fields(array(
      'otp' => $rand_otp,
      'created' => date('Y-m-d G:i:s'),
    ));
    
    $otp->execute();
    
    if (!empty($mobile)) {
      $mail_content = itg_sso_sms_send($rand_otp, $mobile);
    }
    if (!empty($mobile) && !empty($email)) {
      $mail_content = itg_sso_otp_mail_content($rand_otp, $email);
    }
    //$mail_content = itg_sso_get_mail_content($otp, $email);
  }
}

/**
 * Implements itg_sso_otp_check
 * @param int $otpmobile
 * @param string $email
 * @param string $source
 */
function itg_sso_otp_check($otpmobile, $email, $source) {
  
  $otpmobile = trim($otpmobile);
  $get_sso_otp = db_select('itg_sso_reg_otp_info', 'otv')->fields('otv', array('id'));
  $get_sso_otp->condition('otv.source',$source ,'=');
  
  if(!empty($otpmobile) && empty($email)) {
  $get_sso_otp->condition('otv.mobile', $otpmobile, '=');
  }
  if(!empty($email) && empty($otpmobile)) {
  $get_sso_otp->condition('otv.email', $email, '=');
  }
  if(!empty($email) && !empty($otpmobile)) {
    $get_sso_otp->condition('otv.mobile', $otpmobile, '=');
    $get_sso_otp->condition('otv.email', $email, '=');
  }
  $get_sso_otp->orderBy('id', 'DESC');//ORDER BY created
  $get_sso_otp ->range(0,1);  
  $result = $get_sso_otp->execute()->fetchfield();
  return $result;
}

/**
 * Implements itg_sso_otp_delete
 * @param int $mobile
 * @param string $email
 * @param string $source
 */
function itg_sso_otp_delete($mail, $mobile, $source) {

  $otp_delete = db_delete('itg_sso_reg_otp_info');
  $otp_delete->condition('source', $source, '=');
  if (!empty($mobile) && empty($email)) {
    $otp_delete->condition('mobile', $mobile, '=');
  }
  if (!empty($email) && empty($mobile)) {
    $otp_delete->condition('email', $email, '=');
  }
  if (!empty($email) && !empty($mobile)) {
    $otp_delete->condition('mobile', $mobile, '=');
    $otp_delete->condition('email', $email, '=');
  }
  $otp_delete->execute();
}

/**
 * Implements itg_user_mapping_activate
 * @param int $uid
 */
function itg_user_mapping_activate($uid) {
  $active = db_insert('itg_user_activate_info') // Table name no longer needs {}
              ->fields(array(
                'uid' => $uid,
                'status' => 0,
                'created' => date('Y-m-d G:i:s'),
                'updated' => date('Y-m-d G:i:s'),
              ))
              ->execute();
}

/**
 * Implements itg_sso_user_activate_callback
 */
function itg_sso_user_activate_callback() {
  $user_id = base64_decode(arg(1));
  $redirect_url = 'http://'.$_SERVER['HTTP_HOST'].'?active=true';
  if (isset($user_id)) {
    $user_updated = db_update('itg_user_activate_info') // Table name no longer needs {}
        ->fields(array(
          'status' => 1,
          'updated' => date('Y-m-d G:i:s'),
        ))
        ->condition('uid', $user_id, '=')
        ->execute();
    
    print '<div class="activate-message">Your Account Activated Sucessfully!</div>';
    drupal_goto($redirect_url);
  }
}


/**
 * Implements itg_sso_first_time_otp_insert
 * @param int $uid
 * @param string $email
 * @param int $rand_otp
 * @param string $rand_otp
 */
function itg_sso_first_time_otp_insert($mobile, $mail, $rand_otp, $source) {
  $otp = db_insert('itg_sso_reg_otp_info') // Table name no longer needs {}
              ->fields(array(
                'mobile' => $mobile,
                'email' => $mail,
                'source' => $source,
                'otp' => $rand_otp,
                'otp_count' => 1,
                'created' => date('Y-m-d G:i:s'),
              ))
              ->execute();
}

/**
 * Implements itg_sso_sms_send
 * @param int $otp
 * @param int $mobile
 */

function itg_sso_sms_send($otp, $mobile) {

  $runfile = "http://bulkpush.mytoday.com/BulkSms/SingleMsgApi?feedid=361347&username=9811668984&password=tpwaw&senderid=INDTDY&Text=Your%20otp%20is%20".$otp."&To=".$mobile;
  $ch = curl_init();
  curl_setopt($ch, CURLOPT_URL, $runfile);
  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($ch, CURLOPT_URL, $runfile);
  $content = curl_exec($ch);
  curl_close($ch);
  
}
