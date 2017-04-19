<?php

/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
if (isset($_GET['sid']) && !empty($_GET['sid'])) {
  $menus = itg_videogallery_ftp_video_post($_GET['sid'], 'page--section_video', 'video_list_of_category');
  foreach ($menus as $menu):
    $output .= '<li value="' . $menu->filter_url . '"><a href="javascript:void(0)" class="NULL">' . $menu->name . '</a></li>';
  endforeach;
}
if (itg_videogallery_get_categoryparent($_GET['category']) != TRUE && isset($_GET['category']) && isset($_GET['sid'])) {
  print '<ul class="video_landing_menu">' . $output . '</ul>';
}elseif (itg_videogallery_get_categoryparent($_GET['category']) == TRUE && isset($_GET['category']) && isset($_GET['sid'])) {
  print '<ul class="video_landing_menu">' . $output . '</ul>';
}
elseif (itg_videogallery_get_categoryparent($_GET['category']) == TRUE && empty($_GET['sid'])) {
  $term_load = taxonomy_term_load($_GET['category']);
  print '<h3><span>Other Episodes From ' . $term_load->name . '</span></h3>';
}if (empty($_GET['category'])) {
    $node = itg_videogallery_get_term(arg(1));
   if(in_array(variable_get('ipl_for_widget'), $node))
   {
      print '<div class="siderbar-sport"><span class="widget-title">Other Video</span></div>';  
      
   }else {
    
    
  print '<h3><span>Other Video Galleries</span></h3>';
   }
}
?>