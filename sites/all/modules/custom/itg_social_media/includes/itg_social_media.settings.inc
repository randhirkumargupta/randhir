<?php

/**
 * Callback function for social media settings form.
 * @return string
 */
function itg_social_media_settings() {
  global $base_url;
  // Set api keys to class
  $fb = itg_social_media_fb_connection();
  // Try to get user name if logged in
  if (isset($_SESSION['facebook_access_token']) && $_SESSION['facebook_access_token'] != '') {
    try {
      $response = $fb->get('/me?fields=id,name', $_SESSION['facebook_access_token']);
    }
    catch (Facebook\Exceptions\FacebookResponseException $e) {
      drupal_set_message('Graph returned an error: ' . $e->getMessage(), 'error');    
    }
    catch (Facebook\Exceptions\FacebookSDKException $e) {
      drupal_set_message('Facebook SDK returned an error: ' . $e->getMessage(), 'error');      
    }

    $user = $response->getGraphUser();
    if (isset($user) && $user['name'] != '') {      
      return t('Welcome '. $user['name']);
    }
    else {
      $helper = $fb->getRedirectLoginHelper();
      $permissions = ['email', 'user_posts', 'user_videos', 'publish_actions', 'user_actions.video'];
      $loginUrl = $helper->getLoginUrl($base_url . '/browse-content', $permissions);

      return l(t('Please login to facebook page'), $loginUrl, array('class' => array('button')));
    }
  }
  else {
    $helper = $fb->getRedirectLoginHelper();
    $permissions = ['email', 'user_posts', 'user_videos', 'publish_actions', 'user_actions.video'];
    $loginUrl = $helper->getLoginUrl($base_url . '/itg-social-media-settings-callback', $permissions);
    
    return l(t('Please login to facebook page'), $loginUrl, array('class' => array('button')));
  }  
}

/**
 * Create connection object for facebook.
 * @return stdObject 
 */
function itg_social_media_fb_connection() {
  $fb = new Facebook\Facebook([
    'app_id' => FACEBOOK_APP_KEY,
    'app_secret' => FACEBOOK_APP_SECRET,
    'default_graph_version' => 'v2.5',
  ]);

  return $fb;
}

/**
 * Create connection object for twitter
 * @return stdObject 
 */
function itg_social_media_twitter_connection() {
  \Codebird\Codebird::setConsumerKey(TWITTER_API_KEY, TWITTER_API_SECRET);

  $cb = \Codebird\Codebird::getInstance();
  $cb->setToken(TWITTER_ACCESS_TOKEN, TWITTER_ACCESS_TOKEN_SECRET);

  return $cb;
}

/**
 * Callback function for facebook login callback * 
 */
function itg_social_media_settings_callback() {
  $fb = itg_social_media_fb_connection();

  $helper = $fb->getRedirectLoginHelper();
  try {
    $accessToken = $helper->getAccessToken();
  }
  catch (Facebook\Exceptions\FacebookResponseException $e) {
    // When Graph returns an error
    drupal_set_message('Graph returned an error: ' . $e->getMessage(), 'error');
  }
  catch (Facebook\Exceptions\FacebookSDKException $e) {
    // When validation fails or other local issues
    drupal_set_message('Facebook SDK returned an error: ' . $e->getMessage(), 'error');
  }

  if (isset($accessToken)) {
    // Logged in!
    $_SESSION['facebook_access_token'] = (string) $accessToken;
    drupal_set_message('Facebook connection has been made successfully', 'status');
  }
  elseif ($helper->getError()) {
    // The user denied the request
    drupal_set_message('User denied the request.', 'error');
  }
  else {
    drupal_set_message('Unable to connect to facebook.', 'error');
  }
  drupal_goto('/browse-content');
}
