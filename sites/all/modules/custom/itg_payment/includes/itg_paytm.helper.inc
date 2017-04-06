<?php

global $base_url;

########################### PAYTM #########################
###################### HELPER CONSTANT#####################
###########################################################
define('PAYTM_ENVIRONMENT' , 'TEST'); // PROD
define('PAYTM_MERCHANT_KEY' , 'd8DJIC6KlVT4HekP');
define('PAYTM_MERCHANT_MID' , 'LTDMED81989694148457');
define('PAYTM_MERCHANT_WEBSITE' , 'WEB_STAGING');
define('INDUSTRY_TYPE_ID' , 'Retail');
define('CHANNEL_ID' , 'WEB');
define('PAYTM_TXN_SUCCESS_STATUS' , 1);
define('PAYTM_ORDER_PAYMENT_PENDING_STATUS' , 0);
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
###########################################################
#################### BILLDESK #############################
################# HELPER CONSTANT##########################
define('BILLDESK_ORDER_PAYMENT_PENDING_STATUS' , 0);
define('BILLDESK_TRANSACTION_PENDING_STATUS' , 0);
define('BILLDESK_TRANSACTION_HISTORY' , "");
define('BILLDESK_GATEWAY_HISTORY' , "");
define('BILLDESK_PAYMENT_GATEWAY_NAME' , 'billdesk');
define('ITG_BILLDESK_SECURITY_KEY' , '5n9wh8T0a3fw');
define('ITG_BILLDESK_CHECKSUM' , '3712345678');
define('ITG_BILLDESK_MERCHANT_ID' , 'INDIATODAY');
define('ITG_BILLDESK_POST_URL' , 'https://pgi.billdesk.com/pgidsk/PGIMerchantPayment');
define('BILLDESK_LABELS' , 'MerchantID|CustomerID|TxnReferenceNo|BankReferenceNo|TxnAmount|' .
    'BankID|BankMerchantID|TxnType|CurrencyName|ItemCode|SecurityType|' .
    'SecurityID|SecurityPassword|TxnDate|AuthStatus|SettlementType|' .
    'ErrorStatus|ErrorDescription|CheckSum');
###########################################################

