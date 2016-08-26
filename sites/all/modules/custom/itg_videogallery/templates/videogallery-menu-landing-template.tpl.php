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
if (itg_videogallery_get_categoryparent($_GET['category']) == FALSE && isset($_GET['category']) && isset($_GET['sid'])) {
  print '<ul class="video_landing_menu">' . $output . '</ul>';
}
elseif (itg_videogallery_get_categoryparent($_GET['category']) == TRUE && empty($_GET['sid'])) {
  $term_load = taxonomy_term_load($_GET['category']);
  print '<h3>Other Episodes From ' . $term_load->name . '</h3>';
}if (empty($_GET['category'])) {
  print '<h3>Other Video Galleries</h3>';
}
?>