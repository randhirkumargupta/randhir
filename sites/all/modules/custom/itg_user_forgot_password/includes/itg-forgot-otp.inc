<?php
/**
 * Implement itg_forgot_otp_callback
 */
function itg_forgot_otp_callback() {
 
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
    if(!empty($email)) {
    $mail_content = itg_forgot_otp_content($rand_otp, $email);
    }
    if(!empty($mobile)) {
    $mail_content = itg_sso_sms_send($rand_otp, $mobile);
    }
  }
}