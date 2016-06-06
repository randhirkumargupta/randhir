<?php
/**
 * Callback function for social media settings form.
 * @return string
 */
function itg_social_media_settings() {
  global $base_url;
  // Set api keys to class
  $fb = itg_social_media_fb_connection();
  $helper = $fb->getRedirectLoginHelper();
  $permissions = ['email', 'user_posts', 'user_videos', 'publish_actions', 'user_actions.video'];
  $loginUrl = $helper->getLoginUrl($base_url.'/browse-content', $permissions);

  return l(t('Please login to facebook page'), $loginUrl, array('class' => array('button')));
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