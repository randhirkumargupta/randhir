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
   print '<ul class="photo_landing_menu">' . $output . '</ul>';
?>

<style>
	#block-itg-photogallery-photogallery-link-menu-block ul{
		list-style: none;
		white-space: nowrap;
		display: inline-block;
		width: 100%;
		position: relative;
		border-bottom: 1px solid #d9d9d9;
		overflow: auto;
	}
	#block-itg-photogallery-photogallery-link-menu-block ul li{
	    display: inline-block;
		vertical-align: top;
		border-right: 0;
		text-transform: uppercase;
		padding-right: 30px;
	}
	#block-itg-photogallery-photogallery-link-menu-block ul li a{
		display: block;
		margin: 0;
		padding: 10px 5px 3px;
		border-bottom: 3px solid transparent;
		font-family: Roboto;
		font-weight: 500;
		color: #969696;
	}
	#block-itg-photogallery-photogallery-link-menu-block{
		    margin-top: 22px;
	}
</style>
