<?php

/**
 * callback for itg_story_readlater_block_refresh().
 */
function itg_story_readlater_block_refresh() {
  global $user;
  $arg = arg();
  $uri = base64_encode($_SERVER['HTTP_REFERER']);
  $buzz_html = '';
  $default_html = '';

  //$buzz_html = '<li class="later">';
  if ($user->uid > 0) {
    if (function_exists(itg_get_front_activity_info)) {
      $opt = itg_get_front_activity_info($arg[1], 'story', $user->uid, 'read_later', $status = '');
    }
    if (empty($opt['status']) || $opt['status'] == 0) {

      $buzz_html .= '<a title = "Read Later" href = "javascript:void(0)" class = "user-activity" data-rel ="' . $arg[1] . '" data-tag = "story" data-activity = "read_later" data-status = "1" class = "def-cur-pointer"><i class = "fa fa-bookmark"></i><span>READ LATER</span></a>';
    }
    else {

      $buzz_html .= '<a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer unflag-action active"><i class="fa fa-bookmark"></i><span>READ LATER</span></a>';
    }
  }
  else {
    $buzz_html .= '<a href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" title="READ LATER"><i class="fa fa-bookmark"></i> <span>' . t('READ LATER') . '</span></a>';
  }
  //$buzz_html.= '</li>';

  //$default_html = '<li class="left-later">';
  if ($user->uid > 0) {
    if (empty($opt['status']) || $opt['status'] == 0) {

      $default_html .= '<span> <a title = "Read Later" href="javascript:void(0)" class="user-activity" data-rel="'.$arg[1].'" data-tag="story" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i>READ LATER</a><span class="flag-throbber">&nbsp;</span></span>';
    }
    else {

      $default_html .= '<span> <a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i>READ LATER</a><span class="flag-throbber">&nbsp;</span></span>';
    }
  }
  else {
    $default_html .= '<a href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" title="READ LATER"><i class="fa fa-bookmark"></i> <span>' . t('READ LATER') . '</span></a>';
  }
  //$default_html.= '</li>';
  $default_response = array('default_render' => $default_html, 'default_type' => 'normal', 'html_render' => $buzz_html, 'type' => 'buzz');
  print json_encode($default_response);
}
