<?php

/**
 * @file
 * Theme implementation for poll form for front end page.
 */
global $user;
global $base_url;
$nid = $data['nid'];
$poll_image_exist_class = '';

// Title

$updated = $data['updated'];
$title = '<div class="active-poll-title"><h2>' . t($data['title']) . '</h2><div class="updated-msg">' . $updated . '</div></div>';

// Banner Image
$no_image_class = '';
if (isset($data['poll_banner_image']) && !empty($data['poll_banner_image'])) {
  $poll_banner_image = '<div class="poll-banner-image">' . $data['poll_banner_image'] . '</div>';
}
else {
  $poll_banner_image = '';
  $no_image_class = ' no-poll-image';
}

if (isset($data['poll_image_exist_class']) && !empty($data['poll_image_exist_class'])) {
  $poll_image_exist_class = $data['poll_image_exist_class'];
}

print '<div class="poll-wrapper">';

$isCookies = itg_poll_isCookies($nid);
$poll_uid = itg_poll_getcurrent_userpoll($nid, $user->uid);
if (($isCookies != 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid != $user->uid)) {
  if (isset($nid) && !empty($nid)) {
    $poll_form_home = drupal_get_form('itg_poll_form_home_page', $nid);
    print '<div class="poll-data' . $no_image_class . '">' . $poll_banner_image . $title . '<div class="poll-replace-id ' . $poll_image_exist_class . '">' . drupal_render($poll_form_home) . '</div></div>';
  }
}
else {
  print '<div class="poll-data' . $no_image_class . '">' . $poll_banner_image . $title . '<div class="poll-replace-id ' . $poll_image_exist_class . '">' . itg_poll_get_past_data($nid) . '</div></div>';
}
print '</div>';
?>