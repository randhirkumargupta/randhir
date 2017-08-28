<?php

/**
 * @file
 * Inc file contains the functions
 */
function itg_akamai_load_my_account() {
  global $base_url;
  global $user;
  $def_file_path = $base_url . '/sites/all/themes/itg/images/default-user.png';
  $def_user_pic = "<img src='" . $def_file_path . "'width='30' height='30' alt='user-image' />";
  if (isset($user->uid) && $user->uid > 0) {
    if (!empty($user->field_user_picture[LANGUAGE_NONE][0]['uri'])) {
      $user_pic = theme('image_style', array('style_name' => 'user_header_image_30x30', 'path' => $user->field_user_picture[LANGUAGE_NONE][0]['uri']));
    }
    print '<a href="' . $base_url . '/personalization/edit-profile/general-settings" class="user-icon">' . $def_user_pic . '</a>';
    print '<ul class="menu">
      <li class="menu__item is-leaf first leaf"><a href="' . $base_url . '/personalization/saved-items" class="menu__link itg-akamai-processed">Personalization</a></li>
      <li class="menu__item is-leaf last leaf" id="myhref"><a href="javascript:void(0)" id="myhref" class="menu__link itg-akamai-processed">Log Out</a></li>
      </ul>';
    drupal_exit();
  }
  else {
    print '<a href="' . $base_url . '/personalization/edit-profile/general-settings" class="user-icon">' . $def_user_pic . '</a>';
  }
}

/**
 * Getting uid by Session ID
 */
function itg_akamai_get_uid_by_sessionid($sid) {
  $query = db_select('sessions', 's');
  $query->fields('s', array('uid'));
  $query->condition('s.sid', $sid, '=');
  $result = $query->execute()->fetchObject();
  if (isset($result->uid) && !empty($result->uid)) {
    return $result->uid;
  }
  return;
}
