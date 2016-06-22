<?php

/**
 * Callback function for social media settings form.
 * @global string $base_url
 * @return string
 */
function itg_social_media_fb_login() {
  global $base_url;
  
  // Set api keys to class
  $fb = itg_social_media_fb_connection();
  
  $helper = $fb->getRedirectLoginHelper();
  $permissions = ['manage_pages', 'publish_pages', 'pages_show_list'];
  $loginUrl = $helper->getLoginUrl($base_url . '/itg-social-media-settings-callback', $permissions);  
 
  return $loginUrl;
}

/**
 * Create connection object for facebook.
 * @return stdObject 
 */
function itg_social_media_fb_connection() {
  $fb = new Facebook\Facebook([
    'app_id' => variable_get('facebook_app_key'),
    'app_secret' => variable_get('facebook_app_secret'),
    'default_graph_version' => 'v2.5',
  ]);

  return $fb;
}

/**
 * Create connection object for twitter
 * @global string $base_url
 * @return stdObject 
 */
function itg_social_media_twitter_connection() {
  global $base_url;
  \Codebird\Codebird::setConsumerKey(variable_get('twitter_app_key'), variable_get('twitter_app_secret'));

  $cb = \Codebird\Codebird::getInstance();
  if (variable_get('oauth_token', '') !== '' && variable_get('oauth_token_secret', '') !== '') {
    $cb->setToken(variable_get('oauth_token', ''), variable_get('oauth_token_secret', ''));
  }
  else {
    drupal_set_message(t('Access tokens are not available please login.'), 'error');
    drupal_goto('/browse-content');
  }

  return $cb;
}

/**
 * Callback function for facebook login callback
 * 
 * @global string $base_url
 */
function itg_social_media_settings_callback() {
  global $base_url;
  $fb = itg_social_media_fb_connection();

  $helper = $fb->getRedirectLoginHelper();
  try {
    $accessToken = $helper->getAccessToken();
  }
  catch (Facebook\Exceptions\FacebookResponseException $e) {
    // When Graph returns an error
    drupal_set_message(t('Graph returned an error: ' . $e->getMessage()), 'error');
    drupal_goto('/browse-content');
  }
  catch (Facebook\Exceptions\FacebookSDKException $e) {
    // When validation fails or other local issues
    drupal_set_message(t('Facebook SDK returned an error: ' . $e->getMessage()), 'error');
    drupal_goto('/browse-content');
  }

  if (isset($accessToken)) {
    // Logged in!
    $_SESSION['facebook_access_token'] = (string) $accessToken;
    drupal_set_message(t('Facebook connection has been made successfully'), 'status');
  }
  elseif ($helper->getError()) {
    // The user denied the request
    drupal_set_message(t('User denied the request.'), 'error');
  }
  else {
    drupal_set_message(t('Unable to connect to facebook.'), 'error');
  }

  // The OAuth 2.0 client handler helps us manage access tokens
  $oAuth2Client = $fb->getOAuth2Client();

  // Get the access token metadata from /debug_token
  $tokenMetadata = $oAuth2Client->debugToken($accessToken);
  
  // Validation (these will throw FacebookSDKException's when they fail)
  $tokenMetadata->validateAppId(variable_get('facebook_app_key'));
  
  $tokenMetadata->validateExpiration();

  if (!$accessToken->isLongLived()) {
    // Exchanges a short-lived access token for a long-lived one
    try {
      $accessToken = $oAuth2Client->getLongLivedAccessToken($accessToken);
    }
    catch (Facebook\Exceptions\FacebookSDKException $e) {
      drupal_set_message(t('Error getting long-lived access token' . $helper->getMessage()), 'error');      
    }
  }
  // Long lived access token
  $_SESSION['fb_access_token'] = (string) $accessToken;
  variable_set('fb_access_token', $_SESSION['fb_access_token']);

  drupal_goto($base_url.'/admin/itg-social-media/facebook-pages');
}

/**
 * Twitter login callback function
 * 
 * @global string $base_url
 */
function itg_social_media_twitter_callback() {
  global $base_url;
  \Codebird\Codebird::setConsumerKey(variable_get('twitter_app_key'), variable_get('twitter_app_secret'));

  $cb = \Codebird\Codebird::getInstance();
  if (isset($_GET['oauth_verifier']) && isset($_SESSION['oauth_verify'])) {
    // verify the token
    $cb->setToken($_SESSION['oauth_token'], $_SESSION['oauth_token_secret']);
    unset($_SESSION['oauth_verify']);

    // get the access token
    $reply = $cb->oauth_accessToken([
      'oauth_verifier' => $_GET['oauth_verifier']
    ]);

    // store the token (which is different from the request token!)    
    variable_set('oauth_token', $reply->oauth_token);
    variable_set('oauth_token_secret', $reply->oauth_token_secret);

    // send to same URL, without oauth GET parameters
    drupal_goto($base_url . '/admin/config/administration/social_media_login');
  }
}

/**
 * Twitter login link generator function
 * 
 * @global string $base_url
 * @return string
 */
function itg_social_media_twitter_login() {
  global $base_url;
  unset($_SESSION['oauth_token']);
  \Codebird\Codebird::setConsumerKey(variable_get('twitter_app_key'), variable_get('twitter_app_secret'));

  $cb = \Codebird\Codebird::getInstance();

  if (!isset($_SESSION['oauth_token'])) {
    // get the request token
    $reply = $cb->oauth_requestToken([
      'oauth_callback' => $base_url . '/twitter/oauth'
    ]);

    // store the token
    $cb->setToken($reply->oauth_token, $reply->oauth_token_secret);
    $_SESSION['oauth_token'] = $reply->oauth_token;
    $_SESSION['oauth_token_secret'] = $reply->oauth_token_secret;
    $_SESSION['oauth_verify'] = true;

    // redirect to auth website
    $auth_url = $cb->oauth_authorize();

    return $auth_url;
  }
}

/**
 * Autocomplete callback for social media log node title.
 */
function _smi_title_autocomplete($field, $string) {  
  $itg_query = db_select('itg_social_media_logs', 'itg');
  $itg_query->condition($field, '%' . $string . '%', 'LIKE')
      ->fields('itg', array($field));
  $itg_result = $itg_query->execute();
  $result = array();
  foreach ($itg_result as $value) {
    $result[$value->$field] = $value->$field;
  }
  
  return drupal_json_output($result);
}