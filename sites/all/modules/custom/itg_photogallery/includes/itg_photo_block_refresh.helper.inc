<?php

/**
 * callback for itg_photo_block_refresh().
 */
function itg_photo_block_refresh() {
  global $user;
  $arg = arg();
  if ($user->uid > 0) {
    if (function_exists(itg_get_front_activity_info)) {
      $opt = itg_get_front_activity_info($arg[1], 'photogallery', $user->uid, 'read_later', $status = '');
    }
    if (empty($opt['status']) || $opt['status'] == 0) {

      print '<li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="' . $arg[1] . '" data-tag="photogallery" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>';
    }
    else {

      print '<li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>';
    }
    drupal_exit();
  }
  else {
    $uri = base64_encode($_SERVER['HTTP_REFERER']);
    print '<li><a href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>';
    drupal_exit();
  }
}
