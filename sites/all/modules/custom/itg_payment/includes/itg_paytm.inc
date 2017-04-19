<?php

define('PAYTM_ENVIRONMENT' , 'TEST'); // PROD
define('PAYTM_MERCHANT_KEY' , 'd8DJIC6KlVT4HekP');
define('PAYTM_MERCHANT_MID' , 'LTDMED81989694148457');
define('PAYTM_MERCHANT_WEBSITE' , 'WEB_STAGING');
define('INDUSTRY_TYPE_ID' , 'Retail');
define('CHANNEL_ID' , 'WEB');
define('PAYTM_TXN_SUCCESS_STATUS' , 1);
define('PAYTM_TRANSACTION_PENDING_STATUS' , 0);
define('PAYTM_TRANSACTION_HISTORY' , "");
define('PAYMENT_GATEWAY_HISTORY' , "");
define('PAYTM_STARTUP_TRANSACTION_ID' , "null");
define('PAYTM_PAYMENT_GATEWAY_NAME' , 'paytm');
define('PAYTM_TXN_FAIL_STATUS' , 2);
define('PAYTM_ORDER_SUCCESS_STATUS' , 1);
define('PAYTM_CALLBACK_URL' , $base_url . '/itg_payment_order_form_response_url');
$PAYTM_DOMAIN = "pguat.paytm.com";

if (PAYTM_ENVIRONMENT == 'PROD') {
  $PAYTM_DOMAIN = 'secure.paytm.in';
}
define('PAYTM_REFUND_URL' , 'https://' . $PAYTM_DOMAIN . '/oltp/HANDLER_INTERNAL/REFUND');
define('PAYTM_STATUS_QUERY_URL' , 'https://' . $PAYTM_DOMAIN . '/oltp/HANDLER_INTERNAL/TXNSTATUS');
define('PAYTM_TXN_URL' , 'https://' . $PAYTM_DOMAIN . '/oltp-web/processTransaction');


/**
 * Form for order process.
 * @return type
 */
function itg_payment_order_form($form , &$form_state , $args) {
  $form['ORDER_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Order Id") ,
    "#value" => "ODR-" . time() . rand(0 , 1000) ,
  );
  $form['CUST_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Customer Id") ,
    "#value" => "CUS-" . time() . rand(0 , 1000) ,
  );
  $form['INDUSTRY_TYPE_ID'] = array(
    "#type" => "hidden" ,
    "#value" => INDUSTRY_TYPE_ID ,
  );
  $form['CHANNEL_ID'] = array(
    "#type" => "hidden" ,
    "#value" => CHANNEL_ID ,
  );

  $form['TXN_AMOUNT'] = array(
    "#type" => "hidden" ,
    "#title" => t("Final Amount to pay.") ,
    "#value" => $args['redeemed_payment'] ,
    "#default_value" => $args['redeemed_payment'] ,
  );

  $form['EVENT_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("event id.") ,
    "#value" => !empty($args['event_id']) ? $args['event_id'] : NULL ,
    "#default_value" => $args['event_id'] ,
  );

  $form['COUPON_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Coupon id") ,
    "#value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL ,
    "#default_value" => !empty($args['coupon_code']) ? $args['coupon_code'] : NULL ,
  );

  $form['AMOUNT'] = array(
    "#type" => "hidden" ,
    "#title" => t("Amount") ,
    "#value" => $args['total_payment'] ,
    "#default_value" => $args['total_payment'] ,
  );

  $form['REGISTRATION_ID'] = array(
    "#type" => "hidden" ,
    "#title" => t("Registration id.") ,
    "#value" => $args['reg_id'] ,
    "#default_value" => $args['reg_id'] ,
  );

  $form['SUBMIT'] = array(
    "#type" => "submit" ,
    "#value" => t("Submit") ,
    '#attributes' => array("class" => array("hide")) ,
  );

  return $form;
}

/**
 * {@inheritdoc}
 */
function itg_payment_order_form_validate($form , &$form_state) {
  $session_value_array = drupal_json_decode($_SESSION['event_registration_payment']['event_key']);
  if ($session_value_array['redeemed_payment'] !== $form_state['values']['TXN_AMOUNT']) {
    $error[] = t("Something wrong happen with order amount");
  }

  if ($session_value_array['event_id'] !== $form_state['values']['EVENT_ID']) {
    $error[] = t("Something wrong happen with event id");
  }

  if (!empty($error)) {
    foreach ($error as $messages) {
      drupal_set_message($messages , 'error');
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
function itg_payment_order_form_submit($form , &$form_state , $args) {
  global $user;

  $db_data = array();
  module_load_include('php' , 'itg_payment' , 'lib/encdec_paytm');
  // Get required form value.
  $order_id = $form_state['values']['ORDER_ID'];
  $customer_id = $form_state['values']['CUST_ID'];
  $industry_type = $form_state['values']['INDUSTRY_TYPE_ID'];
  $channel_id = $form_state['values']['CHANNEL_ID'];
  $final_amount = $form_state['values']['TXN_AMOUNT'];
  $event_id = $form_state['values']['EVENT_ID'];
  $registration_id = $form_state['values']['REGISTRATION_ID'];
  $coupon_code = $form_state['values']['COUPON_ID'];
  $total_amount = $form_state['values']['AMOUNT'];
  $user_id = $user->uid;
  // Create an array having all required parameters for creating checksum.
  // Array prepare for paytm.
  $param_list["MID"] = PAYTM_MERCHANT_MID;
  $param_list["ORDER_ID"] = $db_data["ORDER_ID"] = $order_id;
  $param_list["CUST_ID"] = $customer_id;
  $param_list["INDUSTRY_TYPE_ID"] = $industry_type;
  $param_list["CHANNEL_ID"] = $channel_id;
  $param_list["WEBSITE"] = PAYTM_MERCHANT_WEBSITE;
  $param_list["CALLBACK_URL"] = PAYTM_CALLBACK_URL;
  $param_list["TXN_AMOUNT"] = floatval($final_amount);
  $db_data["COUPON_AMOUNT"] = 0;
  $db_data["COUPON_ID"] = "";
  // handel coupon details for database.
  if (!empty($coupon_code)) {
    $db_data["COUPON_ID"] = $coupon_code;
    $db_data["COUPON_AMOUNT"] = floatval($total_amount - $final_amount);
    $db_data["COUPON_DETAIL"] = itg_payment_get_coupon_details_json($coupon_code);
  }

  $db_data['CUST_ID'] = $user_id;
  $db_data["USER_TYPE"] = ($user->uid) ? "authenticated" : "guest";
  $db_data["REGISTRATION_ID"] = $registration_id;
  $db_data["PAYMENT_GATEWAY"] = PAYTM_PAYMENT_GATEWAY_NAME;
  $db_data["PAYMENT_GATEWAY_STATUS"] = PAYTM_TRANSACTION_PENDING_STATUS;
  $db_data["TRANSACTION_ID"] = PAYTM_STARTUP_TRANSACTION_ID;
  $db_data["ORDER_STATUS"] = PAYTM_ORDER_PAYMENT_PENDING_STATUS;
  $db_data["TRANSACTION_HISTORY"] = serialize(PAYTM_TRANSACTION_HISTORY);
  $db_data["PAYMENT_GATEWAY_HISTORY"] = serialize(PAYMENT_GATEWAY_HISTORY);
  $db_data["TOTAL_AMOUNT"] = floatval($total_amount);
  $db_data["DESCOUNTED_AMOUNT"] = !empty($db_data["COUPON_AMOUNT"]) ? floatval($db_data["COUPON_AMOUNT"]) : 0;
  $db_data["EVENT_ID"] = $event_id;
  $db_data["TXN_AMOUNT"] = floatval($final_amount);

  itg_payment_initial_info_update($db_data);

  $merchant_checkout_form = drupal_get_form('itg_payment_merchant_form');

  $check_sum = getChecksumFromArray($param_list , PAYTM_MERCHANT_KEY);
  echo theme('itg_payment_merchant_form' , array(
    'param_list' => $param_list ,
    'check_sum' => $check_sum ,
    'form_data' => $merchant_checkout_form ,
  ));
  drupal_exit();
}

/**
 * Function which is called after response from paytm.
 */
function itg_payment_order_form_response_url() {
  // Prepare data.
  $data = array();
  $param_list = array();
  module_load_include('php' , 'itg_payment' , 'lib/encdec_paytm');
  $paytm_check_sum = "";
  $is_valid_checksum = "FALSE";

  $param_list = $_POST;
  $paytm_check_sum = isset($_POST["CHECKSUMHASH"]) ? $_POST["CHECKSUMHASH"] : "";

  $transaction_id = $_POST['TXNID'];
  $transaction_status = 0;
  $data['order_status'] = 0;
  if ($_POST["STATUS"] == "TXN_SUCCESS") {
    //update_event_registration_after_success
    update_event_registration_after_success($_POST['ORDERID']);
    
    $transaction_status = PAYTM_TXN_SUCCESS_STATUS;
    $data['order_status'] = PAYTM_ORDER_SUCCESS_STATUS;
  }

  $data['order_id'] = $_POST['ORDERID'];
  $data['transaction_id'] = $_POST['TXNID'];
  $data['transaction_status'] = $transaction_status;
  $data['transaction_history'] = serialize($_POST);

  // Update order after response.
  itg_payment_response_info_update($data);
  drupal_goto('itg_payment_success');
}


/**
 * {@inheritdoc}
 */
function itg_payment_merchant_form() {
  $form = array();
  $form['markup'] = array(
    '#markup' => t("Merchant Check Out Page") ,
  );
  return $form;
}