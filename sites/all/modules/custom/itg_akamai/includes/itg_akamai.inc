<?php

/**
 * @file
 * Inc file contains the functions
 */
class ItgAkamaiMain {

  function __construct() {
    
  }

  // This method is responsible for section cart ttl and sending header for get ajax header
  static function itgAkamaiSettingTtlForSectionCart($ttl) {
    drupal_add_http_header('Cache-Control', 'public, max-age=' . intval($ttl));
    $formated_expire_date = itg_akamai_set_expiration_date(intval($ttl));
    drupal_add_http_header('Edge-control', 'cache-maxage=' . intval($ttl) . 's');
    drupal_add_http_header('Expires', $formated_expire_date);
  }

  // This method will return the TTL for Akamai section cart
  static function itgAkamaiGettingTTLforAkamaiSectionCart() {
    return variable_get('akamai_timeout_section_card');
  }
  
  // This method is for setting the data for ITG akamai
  static function itgAkamaiDataSetter(){
    
  }
  
  // This method is for setting the data for ITG akamai
  static function itgAkamaiDataGetter(){
    
  }
  
}
