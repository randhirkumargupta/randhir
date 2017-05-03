<?php

global $base_url;

module_load_include('php' , 'itg_payment' , 'lib/amex/VPCPaymentConnection');

define('VIRTUAL_PAYMENT_CLIENT_URL' , 'https://vpos.amxvpos.com/vpcpay');
define('VPC_VERSION' , 1);
define('VPC_COMMAND' , 'pay');
define('VPC_RETURN_URL' , $base_url . '/itg-payment-amex-pay-form-page');
define('AMEX_MERCHANT_ACCESS_CODE' , '0EA9FF0B');
define('AMEX_MERCHANT_ID' , 'TEST9820008712');
define('AMXEX_GATEWAY_NAME' , 'amex');
define('AMXEX_TRANSACTION_PENDING_STATUS' , 'pending');
define('AMXEX_TRANSACTION_PENDING_STATUS' , 0);
define('AMXEX_TRANSACTION_PENDING_STATUS' , 0);
define('AMXEX_GATEWAY_HISTORY' , "");
define('AMEX_SUCCESS_STATUS' , 1);
define('AMEX_ORDER_SUCCESS_STATUS' , 1);

/**
 * Response function for amex
 */
function itg_payment_amex_payment_page() {
  $conn = new VPCPaymentConnection();
  // This is secret for encoding the SHA256 hash
  // This secret will vary from merchant to merchant
  $secureSecret = "BD865A6D221FA5D079DDF40E91B7B0CF";
  // Set the Secure Hash Secret used by the VPC connection object
  $conn->setSecureSecret($secureSecret);
  // *******************************************
  // START OF MAIN PROGRAM
  // *******************************************
  // This is the title for display
  $title = $_GET["Title"];
  // Add VPC post data to the Digital Order
  foreach ($_GET as $key => $value) {
    if (($key != "vpc_SecureHash") && ($key != "vpc_SecureHashType") && ((substr($key , 0 , 4) == "vpc_") || (substr($key , 0 , 5) == "user_"))) {
      $conn->addDigitalOrderField($key , $value);
    }
  }
  // Obtain a one-way hash of the Digital Order data and
  // check this against what was received.
  $serverSecureHash = array_key_exists("vpc_SecureHash" , $_GET) ? $_GET["vpc_SecureHash"] : "";
  $secureHash = $conn->hashAllFields();
  if ($secureHash == $serverSecureHash) {
    $errorsExist = false;
  }
  else {
    // HASH not matched
    $errorsExist = true;
  }

  $orderInfo = array_key_exists("vpc_OrderInfo" , $_GET) ? $_GET["vpc_OrderInfo"] : "";
  $receiptNo = array_key_exists("vpc_ReceiptNo" , $_GET) ? $_GET["vpc_ReceiptNo"] : "";
  $txnResponseCode = array_key_exists("vpc_TxnResponseCode" , $_GET) ? $_GET["vpc_TxnResponseCode"] : "";
  $transaction_status = 0;
  $data = array();
  $goto_url = 'itg-payment-amex-payment-fail';
  $data['order_status'] = 0;
  $data['order_id'] = $orderInfo;

  // Process if error does not exists.
  if (!$errorsExist) {
    if ($txnResponseCode == 'C') {
      $transaction_status = 0;
      $data['order_status'] = 0;
      $goto_url = 'itg-payment-amex-payment-cancle';
    }
    elseif ($txnResponseCode == 0) {
      $transaction_status = AMEX_SUCCESS_STATUS;
      $data['order_status'] = AMEX_ORDER_SUCCESS_STATUS;
      $goto_url = 'itg-payment-amex-payment-success';
      update_event_registration_after_success($data['order_id']);
    }
  }
  $data['transaction_id'] = $receiptNo;
  $data['transaction_status'] = $transaction_status;
  $data['transaction_history'] = serialize($_GET);
  itg_payment_response_info_update($data);
  drupal_goto($goto_url);
}

function itg_payment_amex_payment_success() {
  return drupal_set_message("Your payment is complete");
}

function itg_payment_amex_payment_cancle() {
  return drupal_set_message("Your payment is cancle");
}

function itg_payment_amex_payment_fail() {
  return drupal_set_message("Your payment is fail");
}

function itg_payment_amex_order_form_action_response() {
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
