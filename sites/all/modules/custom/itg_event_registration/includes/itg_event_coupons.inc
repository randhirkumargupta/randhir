<?php

/**
 * @file: itg_event_registration.inc
 */

/**
 * Callback of check coupon authentication
 * @param array $param
 */
function itg_event_check_coupon_auth($param) {

  // Setting default value for coupons
  $return = array(
      'expired' => 0,
      'is_free_coupon' => 0,
      'discount_type' => 0,
      'discounted_value' => 0,
      'allow_min_cart_amt' => 0,
      'min_cart_amt' => 0,
      'success' => 0,
      'success_message' => 0,
  );


  if (isset($_POST['coupon_code']) && !empty($_POST['coupon_code'])) {
    $coupon_id = get_coupondetail_by_coupon_code($_POST['coupon_code']);
    if (isset($coupon_id) && !empty($coupon_id)) {
      $coupons_data = get_complete_coupon_detail($coupon_id);
      if (isset($coupons_data) && !empty($coupons_data)) {

        // CASE 1 - Checking whether coupon is expired or not

        if ((int) $coupons_data->field_coupon_current_uses[$coupons_data->language][0]['value'] >= (int) $coupons_data->field_coupon_uses_limit[$coupons_data->language][0]['value']) {
          $return['expired'] = 1;
          $return['success'] = 0;
          $return['success_message'] = t('Coupon have been expired now, please try again');
          print $return;  // Returning header by default if coupon expired
          drupal_exit();
        }

        // CASE 2 - Checking Allow Min Cart amount is applicable or not
        if (isset($coupons_data->field_coupon_allow_min_cart_amt[$coupons_data->language][0]['value']) && $coupons_data->field_coupon_allow_min_cart_amt[$coupons_data->language][0]['value'] == 1) {
          $return['allow_min_cart_amt'] = 1;

          // Comparing minimum cart amount 
          $minimum_cart_amount = (int) $coupons_data->field_coupon_minimum_cart_amount[$coupons_data->language][0]['value'];
          if ($minimum_cart_amount > $_POST['total_fee']) {
            $return['success'] = 0;
            $return['min_cart_amt'] = $minimum_cart_amount;
            $return['success_message'] = t('Minimum amount should be greater than or equal to RS. ' . $minimum_cart_amount);
            print json_encode($return);  // Returning header by default if coupon expired
            drupal_exit();
          }
        }


        // CASE 3 - Handling discount on the basis of Coupon type
        $coupon_type = $coupons_data->field_coupon_type[$coupons_data->language][0]['value'];
        $coupon_discount_type = $coupons_data->field_coupon_discount_type[$coupons_data->language][0]['value'];
        $coupon_discounted_value = $coupons_data->field_coupon_discounted_value[$coupons_data->language][0]['value'];
        $total_fee = $_POST['total_fee'];
        switch ($coupon_type) {


          // CASE 4 -  Handling Free Product  
          case 'free_product':
            $return = array(
                'expired' => 0,
                'discounted_value' => 0,
                'total_fee' => $total_fee,
                'success' => 1,
                'success_message' => t('Congratulations! Coupon has been successfully redeemed for Rs. ' . ($total_fee) . ' because you have used free coupon'),
            );
            print json_encode($return);
            drupal_exit();
            break;

          // CASE 5 - Handling Email mobile specific
          case 'email_mobile_login_specific_promocode':
            $c_email = isset($_POST['c_email']) ? trim($_POST['c_email']) : NULL;
            $c_mobile = isset($_POST['c_mobile']) ? trim($_POST['c_mobile']) : NULL;
            $choose_email_mobile = $coupons_data->field_coupon_choose_email_mobile[$coupons_data->language][0]['value'];
            switch ($choose_email_mobile) {
              case 'email':
                $mapped_email = $coupons_data->field_coupon_email[$coupons_data->language][0]['value'];
                if ($mapped_email == $c_email) {
                  $discounted_value = get_discunted_value_for_coupon($coupon_discount_type, $coupon_discounted_value, $total_fee);

                  // Start code for handling if discounted value is greater then the actual amount
                  if ($discounted_value['final_discounted_total_fee'] <= 0) {   // If discounted value is a negetive number then discounted value will be total fee
                    $discounted_value['discounted_value'] = $total_fee;
                    $discounted_value['final_discounted_total_fee'] = 0;
                  }
                  // End code for handling if discounted value is greater then the actual amount


                  $return = array(
                      'expired' => 0,
                      'discounted_value' => $discounted_value['final_discounted_total_fee'],
                      'total_fee' => $total_fee,
                      'success' => 1,
                      'success_message' => t('Congratulations! Coupon has been successfully redeemed for Rs. ' . $discounted_value['discounted_value']),
                  );
                  print json_encode($return);
                  drupal_exit();
                } else {
                  $return['success'] = 0;
                  $return['success_message'] = t('You have entered invalid coupon code, please try again');
                  print json_encode($return);
                  drupal_exit();
                }

                break;
              case 'mobile':
                $mapped_mobile = $coupons_data->field_coupon_email[$coupons_data->language][0]['value'];
                if ($mapped_mobile == $c_mobile) {
                  $discounted_value = get_discunted_value_for_coupon($coupon_discount_type, $coupon_discounted_value, $total_fee);


                  // Start code for handling if discounted value is greater then the actual amount
                  if ($discounted_value['final_discounted_total_fee'] <= 0) {   // If discounted value is a negetive number then discounted value will be total fee
                    $discounted_value['discounted_value'] = $total_fee;
                    $discounted_value['final_discounted_total_fee'] = 0;
                  }
                  // End code for handling if discounted value is greater then the actual amount

                  $return = array(
                      'expired' => 0,
                      'discounted_value' => $discounted_value['final_discounted_total_fee'],
                      'total_fee' => $total_fee,
                      'success' => 1,
                      'success_message' => t('Congratulations! Coupon has been successfully redeemed for Rs. ' . $discounted_value['discounted_value']),
                  );
                  print json_encode($return);
                  drupal_exit();
                } else {
                  $return['success'] = 0;
                  $return['success_message'] = t('You have entered invalid coupon code, please try again');
                  print json_encode($return);
                  drupal_exit();
                }

                break;
            }


            break;

          case 'payment_mode_specific_coupan':
            $payment_mode = strtolower($_POST['payment_mode']);
            $gateway_type = strtolower($coupons_data->field_coupon_gateway_type[$coupons_data->language][0]['value']);
            if ($payment_mode == $gateway_type) {
              $discounted_value = get_discunted_value_for_coupon($coupon_discount_type, $coupon_discounted_value, $total_fee);

              // Start code for handling if discounted value is greater then the actual amount
              if ($discounted_value['final_discounted_total_fee'] <= 0) {   // If discounted value is a negetive number then discounted value will be total fee
                $discounted_value['discounted_value'] = $total_fee;
                $discounted_value['final_discounted_total_fee'] = 0;
              }
              // End code for handling if discounted value is greater then the actual amount


              $return = array(
                  'expired' => 0,
                  'discounted_value' => $discounted_value['final_discounted_total_fee'],
                  'total_fee' => $total_fee,
                  'success' => 1,
                  'success_message' => t('Congratulations! Coupon has been successfully redeemed for Rs. ' . $discounted_value['discounted_value']),
              );
              print json_encode($return);
              drupal_exit();
              break;
            } else {
              $return['success'] = 0;
              $return['success_message'] = t('You have entered invalid coupon code, please try again');
              print json_encode($return);
              drupal_exit();
            }


            break;



          case 'coupan_dc':
          case 'upload_third_party_coupon':

            $discounted_value = get_discunted_value_for_coupon($coupon_discount_type, $coupon_discounted_value, $total_fee);

            // Start code for handling if discounted value is greater then the actual amount
            if ($discounted_value['final_discounted_total_fee'] <= 0) {   // If discounted value is a negetive number then discounted value will be total fee
              $discounted_value['discounted_value'] = $total_fee;
              $discounted_value['final_discounted_total_fee'] = 0;
            }
            // End code for handling if discounted value is greater then the actual amount

            $return = array(
                'expired' => 0,
                'discounted_value' => $discounted_value['final_discounted_total_fee'],
                'total_fee' => $total_fee,
                'success' => 1,
                'success_message' => t('Congratulations! Coupon has been successfully redeemed for Rs. ' . $discounted_value['discounted_value']),
            );
            print json_encode($return);
            drupal_exit();
            break;
        }
      }
    }
    // If coupons is not available in database
    else {
      $return['success'] = 0;
      $return['success_message'] = t('You have entered invalid coupon code, please try again');
      print json_encode($return);
      drupal_exit();
    }
  }
}

/**
 * Getting coupon detail by coupon code
 * @param array $coupon_code
 */
function get_coupondetail_by_coupon_code($coupon_code) {

  $query = db_select('node', 'n');
  $query->join('field_data_field_coupon_status', 'cs', 'n.nid=cs.entity_id');
  $query->condition('n.status', 1);
  $query->condition('n.title', $coupon_code);
  $query->condition('cs.field_coupon_status_value', 'Active');
  $query->fields('n', array('nid'));
  $result = $query->execute()->fetchObject();
  return isset($result->nid) ? $result->nid : NULL;
}

/**
 * Getting coupon detail by coupon id
 * @param int $coupon_id
 */
function get_complete_coupon_detail($coupon_id) {
  if (isset($coupon_id) && !empty($coupon_id)) {
    return node_load($coupon_id);
  }
  return NULL;
}

/**
 * Getting discounted value for coupons
 * @param string $coupon_discount_type
 * @param int $coupon_discounted_value
 */
function get_discunted_value_for_coupon($coupon_discount_type, $coupon_discounted_value, $total_fee) {
  if (!empty($coupon_discount_type) && !empty($coupon_discounted_value) && !empty($total_fee)) {
    $coupon_dis_holder = array();
    switch ($coupon_discount_type) {
      case '% discount':
        $discounted_value = ($total_fee * $coupon_discounted_value) / 100;
        $coupon_dis_holder['discounted_value'] = $discounted_value;
        $coupon_dis_holder['total_fee'] = $total_fee;
        $coupon_dis_holder['final_discounted_total_fee'] = $total_fee - $discounted_value;
        break;
      case 'fix amount discount':
        $discounted_value = $coupon_discounted_value;
        $coupon_dis_holder['discounted_value'] = $discounted_value;
        $coupon_dis_holder['total_fee'] = $total_fee;
        $coupon_dis_holder['final_discounted_total_fee'] = $total_fee - $discounted_value;

        break;
    }
    return $coupon_dis_holder;
  }
}