<?php

/**
 * @file
 * Theme implementation for Video header realted content in tab.
 * 
 */
 
  $menus = itg_videogallery_ftp_video_post(variable_get('tid_photogallery', '1208521'), 'page--section_photo', 'photo_list_of_category');
  foreach ($menus as $menu):
    $output .= '<li value="' . $menu->filter_url . '">'.l($menu->name, FRONT_URL . "/" . drupal_get_path_alias("taxonomy/term/" . $menu->filter_url)).'</li>';
  endforeach;
   print '<div class="other_photogallery_category desktop-hide"><h3><span>Other Photogallery Categories</span></h3><ul class="photo_landing_menu">' . $output . '</ul></div>';
?>
