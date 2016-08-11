<?php

/**
 * @file
 * Theme implementation for poll form for front end page.
 */
global $user;
global $base_url;
$nid = $data['nid'];

// Banner Image

if (isset($data['poll_banner_image']) && !empty($data['poll_banner_image'])) {
  $poll_banner_image = '<div class="poll-banner-image">' . $data['poll_banner_image'] . '</div>';
}
else {
  $poll_banner_image = '';
}

print '<div class="poll-wrapper">';

$isCookies = itg_poll_isCookies($nid);
$poll_uid = itg_poll_getcurrent_userpoll($nid, $user->uid);
if (($isCookies != 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid != $user->uid)) {
  if (isset($nid) && !empty($nid)) {
    print $poll_banner_image . '<div class="poll-replace-id">' . drupal_render(drupal_get_form('itg_poll_form_home_page', $nid)) . '</div>';
  }
}
else {
  print $poll_banner_image . '<div class="poll-replace-id">' . itg_poll_get_past_data($nid) . '</div>';
}
print '</div>';
?>