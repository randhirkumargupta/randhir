<?php

define('PAYTM_ORDER_PAYMENT_PENDING_STATUS' , 0);

/**
 * Function returns json array
 * @param array $array
 * @return array
 */
function itg_payment_encode_data($array) {
  return drupal_json_encode($array);
}

/**
 * Function returns json array
 * @param array $array
 * @return array
 */
function itg_payment_decode_data($array) {
  return drupal_json_decode($array);
}