<?php

//Card Type@MasterCard#CardNumber@5426,0640,004,24979#Expiry  Month/Year@12/2024#CardCode@979#3DSecure@pwd:secret3

global $base_url;

define('ICICI_TXNTYPE', 'sale');
define('ICICI_CURRENCY', 'INR');
define('ICICI_MODE', 'payonly');
define('ICICI_STORENAME', 3344000184);
define('ICICI_SHAREDSECRET', 'asdf1234');
define('ICICI_EN', 'English');
define('ICICI_ACTION_URL', 'https://test.ipg-online.com/connect/gateway/processing');
define('ICICI_FORM_ID', 'frm1');

function itg_payment_icici($db_data) {
  
}

/**
 * Form for order process.
 * @return type
 */
function itg_icici_order_form($form, &$form_state, $args) {
  $form['ORDER_ID'] = array(
    "#type" => "hidden",
    "#title" => t("Order Id"),
    "#value" => rand(),
  );
  $form['TXNDATETIME'] = array(
    "#type" => "hidden",
    "#title" => t("Txn date"),
    "#value" => $txndatetime,
  );
  $form['TXN_AMOUNT'] = array(
    "#type" => "hidden",
    "#title" => t("Final Amount to pay."),
    "#value" => $args['redeemed_payment'],
    "#default_value" => $args['redeemed_payment'],
  );
  $form['EVENT_ID'] = array(
    "#type" => "hidden",
    "#title" => t("event id."),
    "#value" => !empty($args['event_id']) ? $args['event_id'] : NULL,
    "#default_value" => $args['event_id'],
  );
  $form['AMOUNT'] = array(
    "#type" => "hidden",
    "#title" => t("Amount"),
    "#value" => $args['total_payment'],
    "#default_value" => $args['total_payment'],
  );
  $form['REGISTRATION_ID'] = array(
    "#type" => "hidden",
    "#title" => t("Registration id."),
    "#value" => $args['reg_id'],
    "#default_value" => $args['reg_id'],
  );
  $form['COUPON_ID'] = array(
    "#type" => "hidden",
    "#title" => t("Coupon id"),
    "#value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL,
    "#default_value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL,
  );
  $form['SUBMIT'] = array(
    "#type" => "submit",
    "#value" => t("Submit"),
    '#attributes' => array("class" => array("hide")),
  );

  return $form;
}

/**
 * {@inheritdoc}
 */
function itg_icici_order_form_validate($form, &$form_state) {
  $session_value_array = drupal_json_decode($_SESSION['event_registration_payment']['event_key']);
  if ($session_value_array['redeemed_payment'] !== $form_state['values']['TXN_AMOUNT']) {
    $error[] = t("Something wrong happen with order amount");
  }

  if ($session_value_array['event_id'] !== $form_state['values']['EVENT_ID']) {
    $error[] = t("Something wrong happen with event id");
  }
  
  if ($session_value_array['total_payment'] !== $form_state['values']['AMOUNT']) {
    $error[] = t("Something wrong happen with total amount");
  }
  
  if ($session_value_array['reg_id'] !== $form_state['values']['REGISTRATION_ID']) {
    $error[] = t("Something wrong happen with reg_id");
  }
  
  if ($session_value_array['coupon_code'] !== $form_state['values']['COUPON_ID']) {
    $error[] = t("Something wrong happen with coupon code");
  }

  if (!empty($error)) {
    foreach ($error as $messages) {
      drupal_set_message($messages, 'error');
    }
    drupal_goto($_SERVER['HTTP_REFERER']);
  }
}

/**
 * Submit form for paytm checkout page.
 * @global array $user
 * @param array $form
 * @param array $form_state
 * @param array $args
 */
function itg_icici_order_form_submit($form, &$form_state, $args) {
  global $user;
  
  module_load_include('php', 'itg_payment', 'lib/icici/ipg-util');
  
  $responseSuccessURL = $base_url."/itg_payment_success";
  $responseFailURL = $base_url."/itg-payment-response-fail";
  
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

  $db_data['CUST_ID'] = $user->uid;
  $db_data["USER_TYPE"] = ($user->uid) ? "authenticated" : "guest";
  $db_data["REGISTRATION_ID"] = $form_state['values']['REGISTRATION_ID'];
  $db_data["PAYMENT_GATEWAY"] = 'icici';
  $db_data["PAYMENT_GATEWAY_STATUS"] = PAYTM_TRANSACTION_PENDING_STATUS;
  $db_data["TRANSACTION_ID"] = ICICI_TXNTYPE;
  $db_data["ORDER_STATUS"] = PAYTM_ORDER_PAYMENT_PENDING_STATUS;
  $db_data["TRANSACTION_HISTORY"] = serialize(PAYTM_TRANSACTION_HISTORY);
  $db_data["PAYMENT_GATEWAY_HISTORY"] = serialize(PAYMENT_GATEWAY_HISTORY);
  $db_data["TOTAL_AMOUNT"] = floatval($total_amount);
  $db_data["DESCOUNTED_AMOUNT"] = !empty($db_data["COUPON_AMOUNT"]) ? floatval($db_data["COUPON_AMOUNT"]) : 0;
  $db_data["EVENT_ID"] = $form_state['values']['EVENT_ID'];
  $db_data["TXN_AMOUNT"] = floatval($final_amount);

  itg_payment_initial_info_update($db_data);
  
  $CT = floatval($final_amount);
  
  $hash = createHash($CT,"356",$storename,$sharedsecret);  

  $pay_data['timezone'] = array('size' => '', 'val' => 'IST');
  $pay_data['authenticateTransaction'] = array('size' => '', 'val' => 'true');
  $pay_data['txntype'] = array('size' => 50, 'val' => ICICI_TXNTYPE);
  $pay_data['txndatetime'] = array('size' => 50, 'val' => $form_state['values']['TXNDATETIME']);
  $pay_data['hash'] = array('size' => 50, 'val' => $hash);
  $pay_data['currency'] = array('size' => 50, 'val' => ICICI_CURRENCY);
  $pay_data['mode'] = array('size' => 50, 'val' => ICICI_MODE);
  $pay_data['storename'] = array('size' => 50, 'val' => ICICI_STORENAME);
  $pay_data['chargetotal'] = array('size' => 50, 'val' => $CT);
  $pay_data['sharedsecret'] = array('size' => 50, 'val' => ICICI_SHAREDSECRET);
  $pay_data['responseSuccessURL'] = array('size' => '', 'val' => $responseSuccessURL);
  $pay_data['responseFailURL'] = array('size' => '', 'val' => $responseFailURL);
  $pay_data['hash_algorithm'] = array('size' => '', 'val' => 'SHA1');

  theme('itg_payment_merchant_form', array(
      'param_list' => $pay_data,
      'form_id' => '',
      'form_data' => '',
    ));
  //itg_payment_icici($db_data);
  drupal_exit();
}