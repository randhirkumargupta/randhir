<?php

/**
 * @file
 * Inc file contains the functions
 */
function itg_akamai_load_my_account() {
  global $base_url;
  global $user;
  if (isset($user->uid) && $user->uid > 0) {
    $user_object = user_load($user->uid);
    if (!empty($user_object->field_user_picture[LANGUAGE_NONE][0]['uri'])) {
      $user_pic = theme('image_style', array('style_name' => 'user_header_image_30x30', 'path' => $user_object->field_user_picture[LANGUAGE_NONE][0]['uri']));
    }
    else {
      $file = $base_url . '/sites/all/themes/itg/images/default-user.png';
      $user_pic = "<img src='" . $file . "'width='30' height='30' alt='user-image' title='user-image' />";
    }
    print '<a href="' . $base_url . '/personalization/edit-profile/general-settings" class="user-icon loginicon">' . $user_pic . '</a>';
    print '<ul class="menu">
      <li class="menu__item is-leaf first leaf"><a href="' . $base_url . '/personalization/saved-items" class="menu__link itg-akamai-processed">Personalization</a></li>
      <li class="menu__item is-leaf last leaf" id="myhref"><a href="javascript:void(0)" id="myhref" class="menu__link itg-akamai-processed">Log Out</a></li>
      </ul>';
    drupal_add_js("jQuery(document).ready(function () {
       jQuery('body').on('click', '#myhref', function () {
                //Call Ajax
                jQuery.ajax({
                    url: '" . $base_url . "/itguserlogout',
                    success: function (data) {
                        jQuery('#iframe-display').html(data);
                        jQuery('#widget-ajex-loader').show();
                        setTimeout(function () {// wait for 5 secs(2)
                            window.location = " . $base_url . ";
                        }, 20000);
                    }
                });
            });
            });", array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
    );
    drupal_exit();
  }
  else {
    $uri = base64_encode($_SERVER['HTTP_REFERER']);
    print '<a href="' . PARENT_SSO . '/saml_login/other/' . $uri . '" class="user-icon sso-click itg-akamai-processed"><i class="fa fa-user"></i></a>';
    drupal_exit();
  }
}