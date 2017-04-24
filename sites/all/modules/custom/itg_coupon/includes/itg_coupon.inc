<?php

/**
 * Implements third_party_coupon_form
 * @param array $form
 * @param array $form_state
 */
function third_party_coupon_form($form, &$form_state) {
  global $base_url;
  $form['coupon_holder'] = array(
      '#type' => 'fieldset',
      '#description' => t("Upload third party coupon"),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );

  $form['coupon_holder']['file_upload'] = array(
      '#type' => 'file',
      '#title' => t('CSV File'),
      '#size' => 40,
      '#description' => t('Select the CSV file to import third party coupons'));

  $form['coupon_holder']['submit_button'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Implements hook_form_validate
 * @param array $form
 * @param array $form_state
 */
function third_party_coupon_form_validate($form, &$form_state) {
  // attempt to save the uploaded file
  $validators = array('file_validate_extensions' => array('csv'));

  $file = file_save_upload('file_upload', $validators);

  if (!$file) {
    form_set_error('file_upload', t('A file must be uploaded or selected.'));
  } else if ($file->filemime != 'text/csv') {
    form_set_error('file_upload', t('The file must be of CSV type only.'));
  } else {
    // set files to form_state, to process when form is submitted
    $form_state['values']['file_upload'] = $file;
  }
}

/**
 * Implements hook_form_submit
 * @param array $form
 * @param array $form_state
 */
function third_party_coupon_form_submit($form, &$form_state) {

  global $base_url;
  global $user;

  $line_max = THIRD_PARTY_COUPONS_LINE_MAX;
  $filepath = $form_state['values']['file_upload']->uri;
  $handle = fopen($filepath, "r");
  $send_counter = 0;

  $data = array();
  $label = array();

  while ($row = fgetcsv($handle, $line_max, ',')) {

    if ($send_counter == 0) {
      $label = $row;
    } else {
      $data[] = $row;
    }
    $send_counter++;
  }

  $number_of_chunk = $send_counter - 1;
  // Create operations array.
  $operations = array();

  foreach ($data as $key => $csvdata) {
    $first_string = trim($csvdata[0]);
    // This function will contain code for coupons creation.
    if (!empty($first_string) && isset($first_string)) {
      $operations[] = array('op_third_party_coupons', array($csvdata));
    }
  }

  // Start Batch of node creation.
  $batch = array(
      'title' => t('Creating the third party coupons finally....please wait....!'),
      'operations' => $operations,
      'finished' => 'op_third_party_coupons_finished',
      'init_message' => t('Coupons csv checking started...please wait....!'),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('third party coupons creation process has encountered an error.'),
      'file' => drupal_get_path('module', 'itg_coupon') . '/includes/itg_coupon.inc',
  );

  // Set the batch operation.
  batch_set($batch);
  batch_process('manage-coupons'); // The path to redirect to when done.
}

/**
 * Implements op_third_party_coupons
 * @param array $csvdata
 * @param array $context
 */
function op_third_party_coupons($csvdata, &$context) {
  global $user;
  if (isset($csvdata) && !empty($csvdata)) {
    $itg_coupon_check_coupon = itg_coupon_check_coupon($csvdata[0]);
    if (isset($itg_coupon_check_coupon) && !empty($itg_coupon_check_coupon)) {
      drupal_set_message(t('OOPS! Coupon "' . $csvdata[0] . '" is already exist, please try with another name or click ' . l('here', 'node/' . $itg_coupon_check_coupon . '/edit') . ' to edit existing'), 'error');
    } else {
      $node = new stdClass();
      $node->type = 'coupon';
      $node->language = LANGUAGE_NONE;
      node_object_prepare($node);

      $node->title = isset($csvdata[0]) ? $csvdata[0] : "";

      $node->field_coupon_type[LANGUAGE_NONE][0]['value'] = 'upload_third_party_coupon';
      $node->field_coupon_discount_type[LANGUAGE_NONE][0]['value'] = isset($csvdata[1]) ? $csvdata[1] : "";
      $node->field_coupon_discounted_value[LANGUAGE_NONE][0]['value'] = isset($csvdata[2]) ? $csvdata[2] : "";

      if (isset($csvdata[3]) && !empty($csvdata[3]) && $csvdata[3] == 1) {
        $node->field_coupon_allow_min_cart_amt[LANGUAGE_NONE][0]['value'] = isset($csvdata[3]) ? $csvdata[3] : "";
        $node->field_coupon_minimum_cart_amount[LANGUAGE_NONE][0]['value'] = isset($csvdata[4]) ? $csvdata[4] : "";
      }

      $node->field_coupon_third_party_coupon[LANGUAGE_NONE][0]['value'] = isset($csvdata[5]) ? $csvdata[5] : "";
      $node->field_coupon_uses_limit[LANGUAGE_NONE][0]['value'] = isset($csvdata[6]) ? (int) $csvdata[6] : "";
      $node->field_coupon_status[LANGUAGE_NONE][0]['value'] = 'Active';
      $node->status = 1;
      $node->uid = $user->uid;
      try {
        node_save($node);
        drupal_set_message(t('Coupon created successfully for "' . $csvdata[0] . '"'));
      } catch (Exception $e) {
        drupal_set_message(t("Unable to save coupon for " . $csvdata[0]));
      }
    }
  }
}

/**
 * Implements op_third_party_coupons_finished
 * @param string $success 
 * @param array $results 
 * @param array $operations 
 */
function op_third_party_coupons_finished($success, $results, $operations) {

  if ($success) {
    drupal_set_message(t('Third party coupons created successfully.'));
  } else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    drupal_set_message(t('An error occurred while processing @operation with arguments : @args', array('@operation' => $error_operation[0], '@args' => print_r($error_operation[0], TRUE))));
  }
}

/**
 * Implements third_party_coupon_form
 * @param array $form
 * @param array $form_state
 */
function coupons_apply_form($form, &$form_state) {
  global $base_url;
  $form['coupon_holder'] = array(
      '#type' => 'fieldset',
      '#description' => t("Coupons Apply form"),
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
  );

  $form['coupon_holder']['total_amount'] = array(
      '#type' => 'textfield',
      '#title' => t('total Amount'),
  );
    
      $form['coupon_holder']['gateway_type'] = array(
      '#type' => 'radios',
      '#title' => t('Gateway Type'),
      '#options' => array('Amex','Paytm','ICICI','BillDEsk'),
  );
  
       $form['coupon_holder']['coupon_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Coupons code'),
      '#description' => t('Please enter valid coupon code')
  );
  

  $form['coupon_holder']['submit_button'] = array(
      '#type' => 'submit',
      '#value' => t('Apply'),
      '#attributes' => array('class' => array('use-ajax-submit')),

      );

  return $form;
}