<?php
/**
 * Callback function for social media settings form.
 */
function itg_social_media_settings() {
  // Set api keys to class
  $fb = itg_social_media_fb_connection();
  $helper = $fb->getRedirectLoginHelper();
  $permissions = ['email', 'user_posts', 'user_videos', 'publish_actions', 'user_actions.video'];
  $loginUrl = $helper->getLoginUrl('http://social.indiatodayonline.in/dev/browse-content', $permissions);

  return l(t('Please login to facebook page'), $loginUrl, array('class' => array('button')));
}

/**
 * Create connection object for facebook.
 */
function itg_social_media_fb_connection() {
  $fb = new Facebook\Facebook([
    'app_id' => FACEBOOK_APP_KEY,
    'app_secret' => FACEBOOK_APP_SECRET,
    'default_graph_version' => 'v2.5',
  ]);
  
  return $fb;
}