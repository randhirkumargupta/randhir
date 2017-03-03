<?php
/**
 * @file
 * Admin forms and form settings
 */
/**
 * Admin setting form for social media settings keys.
 * 
 * {@inheritdoc}
 */
function itg_social_media_settings_form() {
  // Facebook wrapper
  $form['fb_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook'),
  );
  // Facebook app key
  $form['fb_wrapper']['facebook_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App Key'),
    '#attributes' => array('placeholder' => array('Facebook App Key')),
    '#default_value' => variable_get('facebook_app_key'),
  );
  // Facebook app secret
  $form['fb_wrapper']['facebook_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App Secret'),
    '#attributes' => array('placeholder' => array('Facebook App Secret')),
    '#default_value' => variable_get('facebook_app_secret'),
  );
  // Twitter wrapper
  $form['fb_twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter'),
  );
  $form['fb_twitter']['twitter_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter App Key'),
    '#attributes' => array('placeholder' => array('Twitter App Key')),
    '#default_value' => variable_get('twitter_app_key'),
  );
  // Facebook app secret
  $form['fb_twitter']['twitter_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter App Secret'),
    '#attributes' => array('placeholder' => array('Twitter App Secret')),
    '#default_value' => variable_get('twitter_app_secret'),
  );  
  
  return system_settings_form($form);
}

/**
 * Page and token setting form.
 * {@inheritdoc}
 */
function itg_social_media_login_form() {
  // Facebook pages
  if (variable_get('is_fb_logged_in', '')) {
    $pages = itg_social_media_fb_paglist();
    $options = $pages[0];
  }
  else {
    $options = array('_none' => '- Select a value -');
  }
    
  $page_id = variable_get('facebook_page_id', '');
  $form['facebook_page_id'] = array(
    '#type' => 'select',
    '#title' => t('Facebook Page'),
    '#options' => $options,
    '#default_value' => $page_id,
  );
  $token = $page_id != '' ? $pages[1] : '';
  if (is_array($token)) {
    $tpart_one = substr($token[$page_id], 0, 128);
    $tpart_two = substr($token[$page_id], 128);
    $form['access_token_one'] = array(
      '#prefix' => '<p>' . $tpart_one . '</p>',
      '#title' => t('Facebook Page Access Token'),
      '#type' => 'textfield',
      '#default_value' => $tpart_one,
    );
    $form['access_token_two'] = array(
      '#prefix' => '<p>' . $tpart_two . '</p>',
      '#title' => t('Facebook Page Access Token'),
      '#type' => 'textfield',      
      '#default_value' => $tpart_two,
    );
  }   
  
  if (variable_get('is_fb_logged_in', '') === 1) {
    $form['fb_logout'] = array(
      '#type' => 'markup',
      '#markup' => '<div>' . l(t('Facebook Logout'), 'facebook/logout') . '</div>',
    );
  }
  else {
    $form['fb_login'] = array(
      '#type' => 'markup',
      '#markup' => '<div>' . l(t('Facebook Login'), itg_social_media_fb_login()) . '</div>',
    );
  }
  
    
  if (variable_get('oauth_token', '') === '') {
    $form['twitter_login'] = array(
      '#type' => 'markup',
      '#markup' => '<div>' . l(t('Twitter Login'), itg_social_media_twitter_login() ) . '</div>',
    );
  }
  else {
    $form['twitter_logout'] = array(
      '#type' => 'markup',
      '#markup' => '<div>' . l(t('Twitter Logout'), 'twitter/logout') . '</div>',
    );
  }
  
    
  return system_settings_form($form);
}

/**
 * Facebook page selection code.
 * @global string $base_url
 */
function _facebook_pages_list() {
  global $base_url;
  variable_set('is_fb_logged_in', 1);
  drupal_goto($base_url . '/admin/config/administration/social_media_login');
}

/**
 * Function to get page list
 * 
 * @return array
 */
function itg_social_media_fb_paglist() {
    $data = array();
  $fb = itg_social_media_fb_connection();  
  try {
    // Returns a `Facebook\FacebookResponse` object
    $response = $fb->get('/me?fields=accounts', variable_get('fb_access_token'));
    
  }
  
  catch (Facebook\Exceptions\FacebookResponseException $e) {
    drupal_set_message(t('Graph returned an error: @emessage', array('@emessage' => $e->getMessage())), 'error');    
  }
  catch (Facebook\Exceptions\FacebookSDKException $e) {
    drupal_set_message(t('Facebook SDK returned an error: @emessage', array('@emessage' => $e->getMessage())), 'error');    
  }
  if(!empty($response)) {
  $pages = $response->getGraphPage();
  $accounts = $pages->asArray();
  watchdog('FB Accounts', '<pre>' . print_r($accounts, TRUE) . '</pre>');
  $options = array();
  foreach ($accounts['accounts'] as $account) {
    $options[$account['id']] = $account['name'];
    $token[$account['id']] = $account['access_token'];
  }
  $data = array($options, $token);
  }
  
  return $data;
}

/**
 * Twitter logout function.
 * @global string $base_url
 */
function itg_social_media_twitter_logout() {
  global $base_url;
  \Codebird\Codebird::setConsumerKey(variable_get('twitter_app_key'), variable_get('twitter_app_secret'));
  $cb = \Codebird\Codebird::getInstance();
  $cb->logout();
  // store the token (which is different from the request token!)    
  variable_set('oauth_token', '');
  variable_set('oauth_token_secret', '');
  drupal_set_message(t('Twitter session has been closed.'), 'status');
  drupal_goto($base_url . '/admin/config/administration/social_media_login');
}

/**
 * facebook logout function.
 * @global string $base_url
 */
function itg_social_media_facebook_logout() {
  global $base_url;
  $fb = itg_social_media_fb_connection();
  $helper = $fb->getRedirectLoginHelper();
  $token = $token = variable_get('access_token_one', '') . variable_get('access_token_two', '');
  $logout = $helper->getLogoutUrl($token, $base_url . '/admin/config/administration/social_media_login');
  variable_set('access_token_one', '');
  variable_set('access_token_two', '');
  variable_set('facebook_page_id', '');
  variable_set('is_fb_logged_in', 0);
  drupal_set_message(t('Facebook session has been closed.'), 'status');
  drupal_goto($logout);
}

/**
 * callback for itg-social-media-promote.
 * @global string $base_url
 */
function itg_social_media_promote() {
  global $user;
  $arg = arg();
  if (is_numeric($arg[1]) && in_array('Social Media', $user->roles)):
    $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
  
    $data_in = itg_social_media_check_node_exist_lock($arg[1]);
    
    if ($data_in[0]->uid == $user->uid || empty($data_in)) {
      itg_social_media_enter_in_lock($arg[1]);      
      $data['promote_form'] = $block['content'];
    } else { 
        $data['promote_form'] = '<div class="promote-lock">'.t("Someone  is already working on this").'</div>';
    } 
  endif;
  
  return theme('social_media_promote', array('data' => $data));
}