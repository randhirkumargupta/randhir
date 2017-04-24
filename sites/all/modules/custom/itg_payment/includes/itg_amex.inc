<?php

define('VIRTUAL_PAYMENT_CLIENT_URL' , 'https://vpos.amxvpos.com/vpcpay');
define('VPC_VERSION' , 1);
define('VPC_COMMAND' , 'pay');
define('VPC_RETURN_URL' , $base_url .'/itg-payment-amex-pay-form-page');
define('AMEX_MERCHANT_ACCESS_CODE' , '0EA9FF0B');
define('AMEX_MERCHANT_ID' , 'TEST9820008712');
define('AMXEX_GATEWAY_NAME' , 'amex');
define('AMXEX_TRANSACTION_PENDING_STATUS' , 'pending');
define('AMXEX_TRANSACTION_PENDING_STATUS' , 0);
define('AMXEX_GATEWAY_HISTORY' , "");

function itg_payment_amex_payment_page() {
  pr($_REQUEST);
}


function itg_payment_amex_order_form_action_response() {
  p($_GET);
  $param_list = $_POST;
  $paytm_check_sum = isset($_POST["CHECKSUMHASH"]) ? $_POST["CHECKSUMHASH"] : "";

  $transaction_id = $_POST['TXNID'];
  $transaction_status = 0;
  $data['order_status'] = 0;
  if ($_POST["STATUS"] == "TXN_SUCCESS") {
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
 * Amex payment order form.
 * {@inheritdoc}
 */
function itg_payment_amex_order_form($form , &$form_state , $args) {
  global $base_url;
  $form = array();
  $form['virtualPaymentClientURL'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Virtual payment client url' ,
    '#default_value' => VIRTUAL_PAYMENT_CLIENT_URL ,
  );
  $form['vpc_Version'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Vpc version' ,
    '#default_value' => VPC_VERSION ,
  );
  $form['vpc_Command'] = array(
    '#type' => 'textfield' ,
    '#title' => 'vpc Command' ,
    '#default_value' => VPC_COMMAND ,
  );
  $form['vpc_AccessCode'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Merchant AccessCode:' ,
  );
  $form['vpc_MerchTxnRef'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Merchant Transaction Reference:' ,
  );
  $form['vpc_Merchant'] = array(
    '#type' => 'textfield' ,
    '#title' => 'MerchantID:' ,
  );
  $form['vpc_OrderInfo'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Transaction OrderInfo:' ,
  );
  $form['vpc_Amount'] = array(
    '#type' => 'textfield' ,
    '#title' => 'Purchase Amount:' ,
  );
  $form['vpc_ReturnURL'] = array(
    '#type' => 'textfield' ,
    '#default_value' => VPC_RETURN_URL ,
  );
  $form['vpc_Locale'] = array(
    '#type' => 'select' ,
    '#title' => 'Payment Server Display Language Locale:' ,
    '#options' => array("en" => "en") ,
    '#default_value' => array("en") ,
  );
  $form['vpc_Currency'] = array(
    '#type' => 'select' ,
    '#title' => 'Currency:' ,
    '#options' => array("INR" => "INR") ,
    '#default_value' => array("INR") ,
  );
  $form['SubButL'] = array(
    '#type' => 'submit' ,
    '#value' => 'Pay now' ,
  );
  $form['#action'] = $base_url . '/itg-payment-amex-order-form-action';
  return $form;
}

/**
 * function of AMEX which is responsible for Amex redirection.
 */
function itg_payment_amex_order_form_action() {
  module_load_include('php' , 'itg_payment' , 'lib/amex/VPCPaymentConnection');
  $conn = new VPCPaymentConnection();


// This is secret for encoding the SHA256 hash
// This secret will vary from merchant to merchant

  $secureSecret = "BD865A6D221FA5D079DDF40E91B7B0CF";

// Set the Secure Hash Secret used by the VPC connection object
  $conn->setSecureSecret($secureSecret);


// *******************************************
// START OF MAIN PROGRAM
// *******************************************
// Sort the POST data - it's important to get the ordering right
  ksort($_POST);

// add the start of the vpcURL querystring parameters
  $vpcURL = $_POST["virtualPaymentClientURL"];

// This is the title for display
  $title = $_POST["Title"];


// Remove the Virtual Payment Client URL from the parameter hash as we 
// do not want to send these fields to the Virtual Payment Client.
  unset($_POST["virtualPaymentClientURL"]);
  unset($_POST["SubButL"]);
  unset($_POST["Title"]);

// Add VPC post data to the Digital Order
  foreach ($_POST as $key => $value) {
    if (strlen($value) > 0) {
      $conn->addDigitalOrderField($key , $value);
    }
  }

// Add original order HTML so that another transaction can be attempted.
  $conn->addDigitalOrderField("AgainLink" , $againLink);

// Obtain a one-way hash of the Digital Order data and add this to the Digital Order
  $secureHash = $conn->hashAllFields();
  $conn->addDigitalOrderField("Title" , $title);
  $conn->addDigitalOrderField("vpc_SecureHash" , $secureHash);
  $conn->addDigitalOrderField("vpc_SecureHashType" , "SHA256");

// Obtain the redirection URL and redirect the web browser
  $vpcURL = $conn->getDigitalOrder($vpcURL);
  header("Location: " . $vpcURL);
//echo "<a href=$vpcURL>$vpcURL</a>";
}