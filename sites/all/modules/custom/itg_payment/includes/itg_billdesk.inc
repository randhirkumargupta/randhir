<?php
define('BILLDESK_ORDER_PAYMENT_PENDING_STATUS' , 0);
define('BILLDESK_TRANSACTION_PENDING_STATUS' , 0);
define('BILLDESK_TRANSACTION_HISTORY' , "");
define('BILLDESK_GATEWAY_HISTORY' , "");
define('BILLDESK_PAYMENT_GATEWAY_NAME' , 'billdesk');
define('ITG_BILLDESK_SECURITY_KEY' , '5n9wh8T0a3fw');
define('ITG_BILLDESK_CHECKSUM' , '3712345678');
define('ITG_BILLDESK_MERCHANT_ID' , 'INDIATODAY');
define('ITG_BILLDESK_POST_URL' , 'https://pgi.billdesk.com/pgidsk/PGIMerchantPayment');
define('ITG_BILLDESK_SUCCESS_URL' , 'itg-payment/billdesk-payment-success');

define('BILLDESK_LABELS' , 'MerchantID|CustomerID|TxnReferenceNo|BankReferenceNo|TxnAmount|' .
    'BankID|BankMerchantID|TxnType|CurrencyName|ItemCode|SecurityType|' .
    'SecurityID|SecurityPassword|TxnDate|AuthStatus|SettlementType|' .
    'ErrorStatus|ErrorDescription|CheckSum');


function itg_billdesk_payment_success_page() {
  
  if (empty($_POST)) {
    return t("'There was a problem with your payment'");
  }
   //watchdog("BillDesk post", '<pre>' . print_r($_POST, TRUE) . '</pre>');
  if (isset($_POST['msg']) && $_POST['msg'] != '') {
    
    $values = explode('|' , $_POST['msg']);
    
    $data['order_id'] = $values[1];
    $data['transaction_id'] = $values[1];
    $data['transaction_status'] = 1;
    
    watchdog("BillDesk update", '<pre>' . print_r($values, TRUE) . '</pre>');    
    
    //if (end($values) == $_SESSION['billdesk_checksum']) {
      // Payment Failed transactions for BillDesk.
      if (($values['24'] == 'Canceled By User') || ($values[14] == '0399') || ($values[14] == 'NA') || ($values[14] == '0002') || ($values[14] == '0001')) {
        if ($values[14] == '0399') {
          $data['order_status'] = 0;
          $cancelled = 'Invalid Authentication at Bank';
        }
        if ($values[14] == 'NA') {
          $data['order_status'] = 0;
          $cancelled = 'Invalid Input in the Request Message ';
        }
        if ($values[14] == '0002') {
          $data['order_status'] = 0;
          $cancelled = 'BillDesk is waiting for Response from Bank';
        }
        if ($values[14] == '0001') {
          $data['order_status'] = 0;
          $cancelled = 'Error at BillDesk ';
        }
        drupal_set_message(t('Transaction denied due to @error' , array('@error' => $cancelled)) , 'error');
        drupal_goto('<front>');
      }
      // Payment Success transactions for BillDesk.
      elseif (($values['24'] == 'Completed successfully.') || ($values['24'] == 'PGS10001-Success') || ($values[14] == '0300')) {
        $data['order_status'] = 1;
        
        // Update order after response.
        update_event_registration_after_success($values[1]);
        
      }
      $data['transaction_history'] = serialize($values);
    //}
    
    itg_payment_response_info_update($data);
    return drupal_set_message("Your payment is complete");
  }
}

/**
 * Ask for Billdesk redirect form.
 */
function itg_payment_billdesk_order_form($form , &$form_state , $args) {
  global $base_url;
  global $user;
  $amount = number_format($args['redeemed_payment'] , 2 , '.' , '');//final payment value
  $event_id = $args['event_id'];
  $reg_id = $args['reg_id'];
  // Build the data array that will be translated into hidden form values.
  $merchant_id = ITG_BILLDESK_MERCHANT_ID;
  $checksumkey = ITG_BILLDESK_CHECKSUM;
  $security_id = ITG_BILLDESK_SECURITY_KEY;
  $bdposturl = ITG_BILLDESK_POST_URL;
  $order_id = "ODR-" . time() . rand(0 , 1000);
  $value = $merchant_id . '|' . $order_id . '|NA|' . $amount . '|NA|NA|NA|INR|NA|R|indiatoday|NA|NA|F|NA|NA|' . $reg_id . '|' . $event_id . '|NA|NA|NA|' . $base_url. '/'. ITG_BILLDESK_SUCCESS_URL;
  // Generate Checksum.
  $common_string = $security_id;

  $string_new = $value . "|" . $common_string;
  $checksum = crc32($string_new);
  $_SESSION['billdesk_checksum'] = $checksum;
  $datawithchecksumvalue = $value . "|" . $checksum;
  $msg = $datawithchecksumvalue;

  $form['msg'] = array(
    '#type' => 'hidden' ,
    '#value' => $msg ,
  );

  $form['#action'] = $bdposturl;

  $form['submit'] = array(
    "#type" => 'submit' ,
    "#value" => 'Continue Payment' ,
  );
  $db_data = array();
  $db_data['ORDER_ID'] = $order_id;
  $db_data['TOTAL_AMOUNT'] = $args['total_payment'];

  $db_data["COUPON_AMOUNT"] = 0;
  $db_data["COUPON_ID"] = "";
  $coupon_code = !empty($args['coupon_code']) ? $args['coupon_code'] : NULL;
  $total_amount = $args['total_payment'];
  $final_amount = $args['redeemed_payment'];
  $registration_id = $args['reg_id'];
  // handel coupon details for database.
  if (!empty($coupon_code)) {
    $db_data["COUPON_ID"] = $coupon_code;
    $db_data["COUPON_AMOUNT"] = floatval($total_amount - $final_amount);
    $db_data["COUPON_DETAIL"] = itg_payment_get_coupon_details_json($coupon_code);
  }

  $db_data['CUST_ID'] = "CUS-" . time() . rand(0 , 1000);
  $db_data["USER_TYPE"] = ($user->uid) ? "authenticated" : "guest";
  $db_data["REGISTRATION_ID"] = $registration_id;
  $db_data["PAYMENT_GATEWAY"] = BILLDESK_PAYMENT_GATEWAY_NAME;
  $db_data["PAYMENT_GATEWAY_STATUS"] = BILLDESK_TRANSACTION_PENDING_STATUS;
  $db_data["TRANSACTION_ID"] = BILLDESK_TRANSACTION_PENDING_STATUS;
  $db_data["ORDER_STATUS"] = BILLDESK_ORDER_PAYMENT_PENDING_STATUS;
  $db_data["TRANSACTION_HISTORY"] = serialize(BILLDESK_GATEWAY_HISTORY);
  $db_data["PAYMENT_GATEWAY_HISTORY"] = serialize(BILLDESK_GATEWAY_HISTORY);
  $db_data["TOTAL_AMOUNT"] = floatval($total_amount);
  $db_data["DESCOUNTED_AMOUNT"] = !empty($db_data["COUPON_AMOUNT"]) ? floatval($db_data["COUPON_AMOUNT"]) : 0;
  $db_data["EVENT_ID"] = $event_id;
  $db_data["TXN_AMOUNT"] = floatval($final_amount);
  itg_payment_initial_info_update($db_data);
  return $form;
}