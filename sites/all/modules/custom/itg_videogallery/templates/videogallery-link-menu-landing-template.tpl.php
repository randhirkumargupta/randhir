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
   print '<div class="other_video_category"><h3><span>Other Video Categories</span></h3><ul class="video_landing_menu">' . $output . '</ul></div>';
?>

<style>
	.other_video_category h3{
		    text-transform: uppercase;
			font-weight: 700;
			color: #bb0a0a;
			position: relative;
	}
	.other_video_category h3 span{
		    padding-top: 0;
			padding-left: 0;
			background: #fff;
			z-index: 1;
			position: relative;
			padding: 45px 20px 10px 0px;
			display: inline-block;
	}
	.other_video_category h3:before{
		    content: '';
			position: absolute;
			left: 0;
			width: 100%;
			bottom: 20px;
			height: 5px;
			margin-top: -2px;
			background: #ddd;
	}
	#block-itg-videogallery-videogallery-link-menu-video ul{
		list-style: none;
		white-space: nowrap;
		display: inline-block;
		width: 100%;
		position: relative;
		border-bottom: 1px solid #d9d9d9;
		overflow: auto;
	}
	#block-itg-videogallery-videogallery-link-menu-video ul li{
	    display: inline-block;
		vertical-align: top;
		border-right: 0;
		text-transform: uppercase;
		padding-right: 30px;
	}
	#block-itg-videogallery-videogallery-link-menu-video ul li a{
		display: block;
		margin: 0;
		padding: 10px 5px 3px;
		border-bottom: 3px solid transparent;
		font-family: Roboto;
		font-weight: 500;
		color: #969696;
	}
	#block-itg-videogallery-videogallery-link-menu-video{
		    margin-top: 22px;
	}
	
#block-itg-videogallery-other-videogallery-from-section .view-content{    float: left;  width: 100%; overflow-x: scroll;}

#block-itg-videogallery-other-videogallery-from-section .view-content ul.photo-list li{ width:200px; float:left}

#block-itg-videogallery-other-videogallery-from-section .view-footer{display:none}
#block-itg-videogallery-other-videogallery-from-section .view-video-list-of-category .view-content .photo-list li:nth-child(4n+1){clear: inherit;}
</style>
<script>
jQuery(document).ready(function(){
  var windowWidth = $(window).width;
  if(windowWidth > 767){
	var videoGallleryLenght = jQuery("#block-itg-videogallery-other-videogallery-from-section .view-content ul.photo-list li").lenght;
	var videoGallleryWidth = jQuery("#block-itg-videogallery-other-videogallery-from-section .view-content ul.photo-list li").width();
	var videoGallleryFullWidth = (videoGallleryWidth ) * videoGallleryLenght;
	jQuery("#block-itg-videogallery-other-videogallery-from-section .view-content ul.photo-list").css('width', videoGallleryFullWidth );
  }
});

</script>
