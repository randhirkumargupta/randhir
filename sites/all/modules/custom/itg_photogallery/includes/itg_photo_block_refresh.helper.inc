<?php

/**
 * callback for itg_photo_block_refresh().
 */
function itg_photo_block_refresh() {
  global $user;
  $arg = arg();
  $photo_watch_html = '';
  $default_html = '';
  if ($user->uid > 0) {
    if (function_exists(itg_get_front_activity_info)) {
      $opt = itg_get_front_activity_info($arg[1], 'photogallery', $user->uid, 'read_later', $status = '');
    }
    if (empty($opt['status']) || $opt['status'] == 0) {

      $photo_watch_html.= '<li class="later" title = "Saved"><a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="' . $arg[1] . '" data-tag="photogallery" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i></a></li>';
    }
    else {

      $photo_watch_html.= '<li title = "Saved"><a title = "Save" href="javascript:" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a></li>';
    }
  }
  else {
    $uri = base64_encode($_SERVER['HTTP_REFERER']);
    $photo_watch_html.= '<li><a href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" class="user-icon sso-click"><i class="fa fa-bookmark"></i> <span></span> </a></li>';
  }
  
  $default_html .= '<a class="" title="post content" href="#"><i class="fa fa-share"></i></a>';
  
  $default_response = array('default_render' => $default_html, 'default_type' => 'normal', 'html_render' => $photo_watch_html, 'type' => 'watch');
  print json_encode($default_response);
}
