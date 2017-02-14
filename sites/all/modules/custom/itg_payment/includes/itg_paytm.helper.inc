<?php

global $base_url;

define('PAYTM_ENVIRONMENT', 'TEST'); // PROD
define('PAYTM_MERCHANT_KEY', 'vRATqRV01k3O0B#H');
define('PAYTM_MERCHANT_MID', 'Indiaa22153325984376');
define('PAYTM_MERCHANT_WEBSITE', 'india');
define('INDUSTRY_TYPE_ID', 'Retail');
define('CHANNEL_ID', 'WEB');
define('PAYTM_TXN_SUCCESS_STATUS', 1);
define('PAYTM_ORDER_PAYMENT_PENDING_STATUS', 0);
define('PAYTM_TRANSACTION_PENDING_STATUS', 0);
define('PAYTM_TRANSACTION_HISTORY', "");
define('PAYMENT_GATEWAY_HISTORY', "");
define('PAYTM_STARTUP_TRANSACTION_ID', "null");
define('PAYTM_PAYMENT_GATEWAY_NAME', 'paytm');
define('PAYTM_TXN_FAIL_STATUS', 2);
define('PAYTM_ORDER_SUCCESS_STATUS', 1);
define('PAYTM_CALLBACK_URL', $base_url . '/itg_payment_order_form_response_url');

$PAYTM_DOMAIN = "pguat.paytm.com";
if (PAYTM_ENVIRONMENT == 'PROD') {
  $PAYTM_DOMAIN = 'secure.paytm.in';
}

define('PAYTM_REFUND_URL', 'https://' . $PAYTM_DOMAIN . '/oltp/HANDLER_INTERNAL/REFUND');
define('PAYTM_STATUS_QUERY_URL', 'https://' . $PAYTM_DOMAIN . '/oltp/HANDLER_INTERNAL/TXNSTATUS');
define('PAYTM_TXN_URL', 'https://' . $PAYTM_DOMAIN . '/oltp-web/processTransaction');
