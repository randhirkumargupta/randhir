<?php

/**
 * callback for itg_video_watch_later_refresh().
 */
function itg_video_watch_later_refresh() {
  global $user;
  $arg = arg();
  $watch_html = '';
  $default_html = '';
  if ($user->uid > 0) {
    if (function_exists(itg_get_front_activity_info)) {
     $opt = itg_get_front_activity_info($video_node->nid, $video_node->type, $user->uid, 'read_later', $status = '');
    }
    if (empty($opt['status']) || $opt['status'] == 0) {

      $watch_html.= '<a title = "Save" href="javascript:void(0)" class="user-activity" data-rel="'.$arg[1].'" data-tag="videogallery" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-clock-o"></i><span>Watch Later</span></a>';
    }
    else {

      $watch_html.= '<a title = "Save" href="javascript:" class="def-cur-pointer active"><i class="fa fa-clock-o"></i><span>Watch Later</span></a>';
    }
  }
  else {
    $uri = base64_encode($_SERVER['HTTP_REFERER']);
    $watch_html.= '<a title="Watch later" href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" class="user-icon sso-click"><i class="fa fa-clock-o"></i> <span>Watch Later</span></a>';
  }
  
    $default_html .= '<a class="" title="Submit Video" href="#"><i class="fa fa-share"></i><span>Submit Video</span></a>';
  
  $default_response = array('default_render' => $default_html, 'default_type' => 'normal', 'html_render' => $watch_html, 'type' => 'watch');
  print json_encode($default_response);
}
