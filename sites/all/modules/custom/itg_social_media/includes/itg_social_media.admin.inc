<?php
/**
 * Admin setting form for social media settings keys.
 */
function itg_social_media_settings_form() {
  // Facebook app key
  $form['facebook_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App Key'),
    '#attributes' => array('placeholder' => array('Facebook App Key')),
    '#default_value' => variable_get('facebook_app_key'),
  );
  // Facebook app secret
  $form['facebook_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App Secret'),
    '#attributes' => array('placeholder' => array('Facebook App Secret')),
    '#default_value' => variable_get('facebook_app_secret'),
  );
  $form['twitter_app_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter App Key'),
    '#attributes' => array('placeholder' => array('Twitter App Key')),
    '#default_value' => variable_get('twitter_app_key'),
  );
  // Facebook app secret
  $form['twitter_app_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter App Secret'),
    '#attributes' => array('placeholder' => array('Twitter App Secret')),
    '#default_value' => variable_get('twitter_app_secret'),
  );  
  
  return system_settings_form($form);
}

function itg_social_media_login_form() {
  // Facebook pages
  $options = array('_none' => '- Select a value -');
  if (isset($_SESSION['facebook_pages'])) {
    $options = $_SESSION['facebook_pages'];
  }  
  $form['facebook_page_id'] = array(
    '#type' => 'select',
    '#title' => t('Facebook Page'),
    '#options' => $options,
    '#default_value' => '_none',
  );
  $page_id = variable_get('facebook_page_id', '');
  $form['access_token'] = array(
    '#title' => t('Facebook Page Access Token'),
    '#type' => 'textfield',
    '#default_value' => $access_token != '' ? $_SESSION[$page_id] : '', 
  );
  $form['fb_login'] = array(
    '#type' => 'markup',
    '#markup' => '<div>' . l(t('Facebook Login'), itg_social_media_fb_login()) . '</div>',
  );
  $form['twitter_login'] = array(
    '#type' => 'markup',
    '#markup' => '<div>' . l(t('Twitter Login'), itg_social_media_twitter_login()) . '</div>',
  );
  
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return system_settings_form($form);
}

function _facebook_pages_list() {
  global $base_url;
  $fb = itg_social_media_fb_connection();

  try {
    // Returns a `Facebook\FacebookResponse` object
    $response = $fb->get('/me?fields=accounts', variable_get('fb_access_token'));
  }
  catch (Facebook\Exceptions\FacebookResponseException $e) {
    drupal_set_message('Graph returned an error: ' . $e->getMessage(), 'error');    
  }
  catch (Facebook\Exceptions\FacebookSDKException $e) {
    drupal_set_message('Facebook SDK returned an error: ' . $e->getMessage(), 'error');    
  }
  $pages = $response->getGraphPage();
  $accounts = $pages->asArray();
  watchdog('FB Accounts', '<pre>' . print_r($accounts, TRUE) . '</pre>');
  $options = array();
  foreach ($accounts['accounts'] as $account) {
    $options[$account['id']] = $account['name'];
    $token[$account['id']] = $account['access_token'];
  }
  watchdog('FB Accounts foreach', '<pre>' . print_r($options, TRUE) . '</pre>');
  $_SESSION['facebook_pages'] = $options;
  $_SESSION['facebook_token'] = $token;
  drupal_goto($base_url.'/admin/config/administration/social_media_login');
}