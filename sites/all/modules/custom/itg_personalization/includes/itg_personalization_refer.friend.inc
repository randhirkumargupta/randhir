<?php

/**
 * @file
 *   Refer a friend form. 
 */

/**
 * Implemetns hook_form().
 *
 * {@inheritdoc}.
 */
function itg_personalization_refer_a_friend_form($form, &$form_state) {
  global $base_url;  
  $form['#tree'] = TRUE;
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'itg_personalization') . '/js/itg_personalization.js',
    drupal_get_path('module', 'itg_astro') . '/js/jquery.validate.min.js',
  );
  drupal_add_js(array('itg_personalization' => array('base_url' => $base_url)), array('type' => 'setting'));
  
  $output = '<div class="social-edit">';
  $output .= '<ul>';
  $output .= '<li>Via Social</li>';
  $output .= '<li><img alt="" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/facebook-edit.png" /></li>';
  $output .= '<li><img alt="" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/edit-twitter.png" /></li>';
  $output .= '<li><img alt="" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/google-plus-edit.png" /></li>';       
  $output .= '<li><img alt="" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/linkedin-edit.png" /></li>';
  $output .= '</ul>';
  $output .= '<div class="more-option"> OR </div>';
  $output .= '<div>';
  
  $form['social_icons'] = array(
    '#type' => 'markup',
    '#markup' => $output,
  );
  $form['friend_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Friend List'),
    // Set up the wrapper so that AJAX will be able to replace the fieldset.
    '#prefix' => '<div id="friend-fieldset-wrapper">',
    '#suffix' => '</div>',
  );

  // Build the fieldset with the proper number of names. We'll use
  // $form_state['num_firend'] to determine the number of collection to build.
  if (empty($form_state['num_friend'])) {
    $form_state['num_friend'] = 1;
  }

  for ($i = 0; $i < $form_state['num_friend']; $i++) {
    $form['friend_fieldset']['name_' . $i] = array(
      '#title' => t('Name'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#maxlength' => 255,
    );

    $form['friend_fieldset']['mail_' . $i] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#required' => TRUE,
      '#maxlength' => 255,
    );
  }
  if ($form_state['num_friend'] <= 4) {
    $form['friend_fieldset']['add_friend'] = array(
      '#name' => 'add_friend',
      '#type' => 'submit',
      '#value' => t('Add more'),
      '#submit' => array('itg_personalization_add_more_add_one'),
      '#ajax' => array(
        'callback' => 'itg_personalization_add_more_callback',
        'wrapper' => 'friend-fieldset-wrapper',
      ),
    );
  }

  if ($form_state['num_friend'] > 1) {
    $form['friend_fieldset']['remove_friend'] = array(
      '#type' => 'submit',
      '#name' => 'remove_friend',
      '#value' => t('Remove'),
      '#submit' => array('itg_personalization_add_more_remove_one'),
      '#ajax' => array(
        'callback' => 'itg_personalization_add_more_callback',
        'wrapper' => 'friend-fieldset-wrapper',
      ),
    );
  }
  $form['total_friend'] = array(
    '#type' => 'value',
    '#value' => $form_state['num_friend'],
  );
  $form['submit'] = array(
    '#name' => 'Save',
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Ajax callback function to add one more group.
 *
 * @param array $form
 * @param array $form_state
 */
function itg_personalization_add_more_add_one($form, &$form_state) {
  $form_state['num_friend'] ++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Ajax submit function for add more field.
 *
 * @param array $form
 * @param array $form_state
 * @return array
 */
function itg_personalization_add_more_callback($form, $form_state) {
  return $form['friend_fieldset'];
}

/**
 * Ajax callback fucntion to remove one group.
 *
 * @param array $form
 * @param array $form_state
 */
function itg_personalization_add_more_remove_one($form, &$form_state) {
  if ($form_state['num_friend'] > 1) {
    $form_state['num_friend'] --;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Implements hook_validate().
 *
 * {@inheritdoc}.
 */
function itg_personalization_refer_a_friend_form_validate($form, &$form_state) {
  $inputs = $form_state['values'];
  for ($i = 0; $i < $inputs['total_friend']; ++$i) {
    $is_user_valid = user_load_by_mail($inputs['mail_' . $i]);
    if ($is_user_valid) {
      form_set_error('mail_' . $i, 'User is already registered.');
    }
  }
}

/**
 * Implements hook_submit().
 *
 * {@inheritdoc}. * 
 */
function itg_personalization_refer_a_friend_form_submit($form, &$form_state) {
  global $user;
  $response = 0;
  $input = $form_state['values']['friend_fieldset'];
  try {
    $itg_query = db_insert('itg_lrp_refer_friend')
        ->fields(array('uid', 'referral_key', 'friend_name', 'mail', 'status', 'created'));
    for ($i = 0; $i < $form_state['values']['total_friend']; ++$i) {
      $presave = array(
        'uid' => $user->uid,
        'referral_key' => uniqid('friend'),
        'friend_name' => check_plain($input['name_' . $i]),
        'mail' => check_plain($input['mail_' . $i]),
        'status' => 0,
        'created' => REQUEST_TIME,
      );
      $itg_query->values($presave);
      $mail_data[] = array(
        'name' => $presave['friend_name'],
        'mail' => $presave['mail'],
        'key' => $presave['referral_key'],
      );
    }
    $itg_query->execute();
    $response = 1;
  }
  catch (Exception $ex) {
    drupal_set_message($ex->getMessage(), 'error');
  }
  // Send mail to users.
  if ($response) {
    for ($i = 0; $i < $form_state['values']['total_friend']; ++$i) {
      $data['link'] = l(t('Click here to register'), FRONT_URL, array('query' => array('referral_key' => $mail_data[$i]['key']), 'attributes' => array('target' => '_blank')));
      $data['name'] = $mail_data[$i]['name'];
      itg_common_get_mail_content($data, $mail_data[$i]['mail']);      
    }
  }
}

/**
 * Implements validation callback for email.
 */
function itg_personalization_validate_by_usermail() {
  $input = check_plain($_POST['usermail']);
  $is_user_valid = user_load_by_mail($input);
  if ($is_user_valid) {
    echo 'false';
  }
  else {
    echo 'true';
  }
}
