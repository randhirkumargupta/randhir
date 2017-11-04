<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
if (isset($_GET['sid']) && !empty($_GET['sid'])) {
  if (module_exists('itg_videogallery')) {
    $menus = itg_videogallery_ftp_video_post($_GET['sid'], 'page--section_photo', 'photo_list_of_category');
    foreach ($menus as $menu):
      $ga_data = "ga('send', 'event', 'Photo_" . trim(str_replace(" ", "", $menu->name)) . "Thumb', 'click','1', 1, {'nonInteraction': 1});return true;";
      $output .= '<li value="' . $menu->filter_url . '"><a href="javascript:void(0)" class="NULL" onclick="'.$ga_data.'">' . $menu->name . '</a></li>';
    endforeach;    
  }
  print '<ul class="photo_landing_menu">' . $output . '</ul>';
} else {
    $node = itg_videogallery_get_term(arg(1));
    if(in_array(variable_get('ipl_for_widget'), $node)) {
       print '<div class="siderbar-sport"><span class="widget-title">Other Gallery</span></div>'; 

    }
}
?>