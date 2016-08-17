<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */


if(isset($_GET['sid']) && !empty($_GET['sid'])){
  $menus = itg_videogallery_ftp_video_post($_GET['sid']);
  foreach($menus as $menu):
    $output .= '<li value="'.$menu->filter_url.'">'.$menu->name.'</li>';
  endforeach;
}

print '<ul class="video_landing_menu">'.$output.'</ul>';
?>


<?php
drupal_add_js("jQuery('#block-itg-videogallery-videogallery-menu-video-block ul li').click(function(){
               var section_id = jQuery(this).val();
               jQuery('#edit-field-story-category-tid').val(section_id); 
               jQuery('#edit-field-story-category-tid').trigger('change');
           });", array('type' => 'inline', 'scope' => 'footer'));
drupal_add_js("jQuery(document).ready(function(){
               jQuery('#edit-field-story-category-tid').val(".$_GET['category']."); 
               jQuery('#edit-field-story-category-tid').trigger('change');
           });", array('type' => 'inline', 'scope' => 'footer'));
?>