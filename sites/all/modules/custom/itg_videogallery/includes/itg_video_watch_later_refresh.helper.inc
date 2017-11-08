<?php

/**
 * callback for itg_video_watch_later_refresh().
 */
function itg_video_watch_later_refresh() {
  global $user;
  $arg = arg();
  if ($user->uid > 0) {
    if (function_exists(itg_get_front_activity_info)) {
                                  $opt = itg_get_front_activity_info($video_node->nid, $video_node->type, $user->uid, 'read_later', $status = '');
    }
    if (empty($opt['status']) || $opt['status'] == 0) {

      print '<a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="'.$arg[1].'" data-tag="videogallery" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-clock-o"></i><span>Watch Later</span></a>';
    }
    else {

      print '<a title = "Save" href="javascript:" class="def-cur-pointer active"><i class="fa fa-clock-o"></i><span>Watch Later</span></a>';
    }
    drupal_exit();
  }
  else {
    $uri = base64_encode($_SERVER['HTTP_REFERER']);
    print '<a title="Watch later" href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" class="user-icon sso-click"><i class="fa fa-clock-o"></i> <span>Watch Later</span></a>';
    drupal_exit();
  }
}
