	<?php

/**
 * @file
 * Theme implementation for Video header realted content in tab.
 * 
 */
 
  $menus = itg_videogallery_ftp_video_post(variable_get('tid_videos', '1206552'), 'page--section_video', 'video_list_of_category');
  foreach ($menus as $menu):
    $output .= '<li value="' . $menu->filter_url . '">'.l($menu->name, FRONT_URL . "/" . drupal_get_path_alias("taxonomy/term/" . $menu->filter_url)).'</li>';
  endforeach;
   print '<div class="other_video_category desktop-hide"><h3><span>Other Video Categories</span></h3><ul class="video_landing_menu">' . $output . '</ul></div>';
?>


