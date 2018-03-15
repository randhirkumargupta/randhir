<?php

/**
 * callback for itg_follow_story_refresh().
 */
function itg_follow_story_refresh() {
  global $user;
  $arg = arg();
  $uri = base64_encode($_SERVER['HTTP_REFERER']);
  $follow_html = '';
  if ($user->uid > 0) {
    if (function_exists('itg_get_front_activity_info')) {
      $follow_status = itg_get_front_activity_info($arg[1], 'story', $user->uid, 'follow_story', $status = '');
    }
    if (!empty($follow_status['nid']) && $follow_status['status'] == '1') {

      print '<a title = "Unfollow Story" href="javascript:" id="user-activity" data-rel="'.$arg[1].'" data-tag="story" data-activity="follow_story" data-status="0" class="def-cur-pointer">Unfollow Story</a>';
    }
    else {

      print '<a title = "Follow the Story" href="javascript:" id="user-activity" data-rel="'.$arg[1].'" data-tag="story" data-activity="follow_story" data-status="1" class="def-cur-pointer">Follow the Story</a>';
    }
    drupal_exit();
  }
  else {
    print '<a title = "Follow the Story" href="' . PARENT_SSO . '/saml_login/other/' . $uri . '">Follow the Story</a>';
    drupal_exit();
  }
}
