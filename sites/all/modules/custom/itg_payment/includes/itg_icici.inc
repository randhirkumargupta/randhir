<?php

//Card Type@MasterCard#CardNumber@5426,0640,004,24979#Expiry  Month/Year@12/2024#CardCode@979#3DSecure@pwd:secret3

global $base_url;

define('ICICI_TXNTYPE' , 'sale');
define('ICICI_CURRENCY' , 'INR');
define('ICICI_MODE' , 'payonly');
define('ICICI_STORENAME' , '3344000184'); //3344000184
define('ICICI_SHAREDSECRET' , 'asdf1234');
define('ICICI_EN' , 'English');
define('ICICI_ACTION_URL' , 'https://test.ipg-online.com/connect/gateway/processing');
define('ICICI_FORM_ID' , 'frm1');

date_default_timezone_set('Asia/Kolkata');
$_SESSION['dateTime'] = date('Y:m:d-H:i:s');

function itg_payment_icici($db_data) {
  
}

/**
 * Form for order process.
 * @return type
 */
function itg_icici_order_form($form , &$form_state , $args) {

  $form['ORDER_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Order Id") ,
    "#value" => rand() ,
  );
  $form['TXNDATETIME'] = array(
    "#type" => "hidden" ,
    "#title" => t("Txn date") ,
    "#value" => getDateTime() ,
  );
  $form['TXN_AMOUNT'] = array(
    "#type" => "hidden" ,
    "#title" => t("Final Amount to pay.") ,
    "#value" => $args['redeemed_payment'] ,
    "#default_value" => $args['redeemed_payment'] ,
//    "#default_value" => 1.00 ,
  );
  $form['EVENT_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("event id.") ,
    "#value" => !empty($args['event_id']) ? $args['event_id'] : NULL ,
    "#default_value" => $args['event_id'] ,
//    "#default_value" => 123 ,
  );
  $form['AMOUNT'] = array(
    "#type" => "hidden" ,
    "#title" => t("Amount") ,
    "#value" => $args['total_payment'] ,
    "#default_value" => $args['total_payment'] ,
//    "#default_value" => 1.00 ,
  );
  $form['REGISTRATION_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Registration id.") ,
    "#value" => $args['reg_id'] ,
    "#default_value" => $args['reg_id'] ,
//    "#default_value" => 'abc' ,
  );
  $form['COUPON_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Coupon id") ,
    "#value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL ,
    "#default_value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL ,
//    "#default_value" => 'abb' ,
  );

  $form['SUBMIT'] = array(
    "#type" => "submit" ,
    "#value" => t("Continue..") ,
    '#attributes' => array("class" => array("hide")) ,
  );
  
//  drupal_add_js('myFunction();
//      function myFunction() {
//          document.getElementById("itg-icici-order-form").submit();
//      }','inline');

  
    drupal_add_js('jQuery(document).ready(function () { jQuery("#itg-icici-order-form").submit(); });',
    array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
  );
  return $form;
}

/**
 * {@inheritdoc}
 */
function itg_icici_order_form_validate($form , &$form_state) {
  $session_value_array = drupal_json_decode($_SESSION['event_registration_payment']['event_key']);
  if ($session_value_array['redeemed_payment'] != $form_state['values']['TXN_AMOUNT']) {
    $error[] = t("Something wrong happen with order amount");
  }

  if ($session_value_array['event_id'] != $form_state['values']['EVENT_ID']) {
    $error[] = t("Something wrong happen with event id");
  }

  if ($session_value_array['total_payment'] != $form_state['values']['AMOUNT']) {
    $error[] = t("Something wrong happen with total amount");
  }

  if ($session_value_array['reg_id'] != $form_state['values']['REGISTRATION_ID']) {
    $error[] = t("Something wrong happen with reg_id");
  }

  if (!empty($form_state['values']['COUPON_ID']) && $session_value_array['coupon_code'] != $form_state['values']['COUPON_ID']) {
    $error[] = t("Something wrong happen with coupon code");
  }

  if (!empty($error)) {
    foreach ($error as $messages) {
      drupal_set_message($messages , 'error');
    }
    drupal_goto($_SERVER['HTTP_REFERER']);
  }
}

function getDateTime() { // Here we are returning the current date time that will be further used to generate the salted hashed.
  
  return $_SESSION['dateTime'];
}

function createHash($chargetotal , $Currency , $storeId , $sharedSecret) {
  // Please change the store Id to your individual Store ID
  // NOTE: Please DO NOT hardcode the secret in that script. For example read it from a database.

  $stringToHash = $storeId . getDateTime() . $chargetotal . $Currency . $sharedSecret;

  $ascii = bin2hex($stringToHash);

  return sha1($ascii);
}

/**
 * Submit form for paytm checkout page.
 * @global array $user
 * @param array $form
 * @param array $form_state
 * @param array $args
 */
function itg_icici_order_form_submit($form , &$form_state , $args) {
  global $user;
  global $base_url;
  //module_load_include('php', 'itg_payment', 'lib/icici/ipg-util');

  
  //$responseSuccessURL = "http://127.0.0.1/itgcms/itg-payment/icici-payment-success";
  //$responseFailURL = "http://127.0.0.1/itgcms/itg-payment/icici-payment-fail";

   $responseSuccessURL = $base_url."/itg-payment/icici-payment-success";
   $responseFailURL = $base_url."/itg-payment/icici-payment-fail";
  
  $db_data = array();

  // Get required form value.
  $order_id = $form_state['values']['ORDER_ID'];
  $final_amount = $form_state['values']['TXN_AMOUNT'];
  $total_amount = $form_state['values']['AMOUNT'];

  // Create an array having all required parameters for creating checksum.

  $db_data["COUPON_AMOUNT"] = 0;
  $db_data["COUPON_ID"] = "";

  // handel coupon details for database.
  if (!empty($coupon_code)) {
    $db_data["COUPON_ID"] = $form_state['values']['COUPON_ID'];
    $db_data["COUPON_AMOUNT"] = floatval($total_amount - $final_amount);
    $db_data["COUPON_DETAIL"] = itg_payment_get_coupon_details_json($form_state['values']['COUPON_ID']);
  }
  
  $db_data['ORDER_ID'] = $order_id;
  $db_data['CUST_ID'] = $user->uid;
  $db_data["USER_TYPE"] = ($user->uid) ? "authenticated" : "guest";
  $db_data["REGISTRATION_ID"] = $form_state['values']['REGISTRATION_ID'];
  $db_data["PAYMENT_GATEWAY"] = 'icici';
  $db_data["PAYMENT_GATEWAY_STATUS"] = PAYTM_TRANSACTION_PENDING_STATUS;
 // $db_data["TRANSACTION_ID"] = ICICI_TXNTYPE;
  $db_data["ORDER_STATUS"] = PAYTM_ORDER_PAYMENT_PENDING_STATUS;
  $db_data["TRANSACTION_HISTORY"] = serialize(PAYTM_TRANSACTION_HISTORY);
  $db_data["PAYMENT_GATEWAY_HISTORY"] = serialize(PAYMENT_GATEWAY_HISTORY);
  $db_data["TOTAL_AMOUNT"] = floatval($total_amount);
  $db_data["DESCOUNTED_AMOUNT"] = !empty($db_data["COUPON_AMOUNT"]) ? floatval($db_data["COUPON_AMOUNT"]) : 0;
  $db_data["EVENT_ID"] = $form_state['values']['EVENT_ID'];
  $db_data["TXN_AMOUNT"] = floatval($final_amount);

  itg_payment_initial_info_update($db_data);

  $CT = $final_amount;

  $hash = createHash($CT , "356" , '3344000184' , 'asdf1234');

  $pay_data['timezone'] = 'IST';
  $pay_data['authenticateTransaction'] = 'true';
  $pay_data['txntype'] = ICICI_TXNTYPE;
  $pay_data['txndatetime'] = $form_state['values']['TXNDATETIME'];
  $pay_data['hash'] = $hash;
  $pay_data['currency'] = ICICI_CURRENCY;
  $pay_data['mode'] = ICICI_MODE;
  $pay_data['storename'] = ICICI_STORENAME;
  $pay_data['chargetotal'] = $CT;
  $pay_data['sharedsecret'] = ICICI_SHAREDSECRET;
  $pay_data['responseSuccessURL'] = $responseSuccessURL;
  $pay_data['responseFailURL'] = $responseFailURL;
  $pay_data['hash_algorithm'] = 'SHA1';
  $pay_data['order_id'] = $order_id;

  print theme('itg_icici_merchant_form' , array(
    'param_list' => $pay_data ,
    'form_id' => ICICI_FORM_ID ,
    'form_action' => ICICI_ACTION_URL ,
  ));

  drupal_exit();
}

function itg_icici_payment_success_page() {
  
  if (empty($_POST)) {
    return t("'There was a problem with your payment'");
  } else {  
    $data['order_id'] = $_POST['order_id'];
    $data['transaction_id'] = $_POST['endpointTransactionId'];
    $data['transaction_status'] = 1;
    
    if ($_POST['status'] == 'APPROVED') {
      $data['order_status'] = 1;
      // Update order after response.
      update_event_registration_after_success($_POST['order_id']);
    }
      
    $data['transaction_history'] = serialize($_POST);
    
    itg_payment_response_info_update($data);
    //watchdog("icici", '<pre>' . print_r($_POST, TRUE) . '</pre>');
    return drupal_set_message("Your payment is complete");
  }
}

function itg_icici_payment_fail_page() {
  //p($_POST);
  if (empty($_POST)) {
    return t("'There was a problem with your payment'");
  } else {  
    $data['order_id'] = $_POST['order_id'];
    $data['transaction_id'] = $_POST['ipgTransactionId'];
    $data['transaction_status'] = 0;
    $data['order_status'] = 0;
    $data['transaction_history'] = serialize($_POST);
    
    itg_payment_response_info_update($data);
    watchdog("icici_fail", '<pre>' . print_r($_POST, TRUE) . '</pre>');
    return drupal_set_message("Your payment failed");
  }
}
