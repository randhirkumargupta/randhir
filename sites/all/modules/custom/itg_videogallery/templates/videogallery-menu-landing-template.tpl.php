<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
if (isset($_GET['sid']) && !empty($_GET['sid'])) {
  $menus = itg_videogallery_ftp_video_post($_GET['sid']);
  foreach ($menus as $menu):
    $output .= '<li value="' . $menu->filter_url . '"><a href="javascript:void(0)" class="NULL">' . $menu->name . '</a></li>';
  endforeach;
}

print '<ul class="video_landing_menu">' . $output . '</ul>';
?>