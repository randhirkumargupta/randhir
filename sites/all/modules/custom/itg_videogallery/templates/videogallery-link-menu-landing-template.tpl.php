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

        @media (min-width: 768px){
		#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content{    float: left;  width: 100%; overflow-x: scroll;}
		#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content ul.photo-list li{ width:200px; float:left; padding:0;}
		#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-footer{display:none}
		#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list li:nth-child(4n+1){clear: inherit;}
		#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .other_video_category h3{ float:left}
                #block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list{width:1600px}
	}
	@media (max-width: 767px){
	   #block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-footer{display:block}
	
	}
        
        @media only screen and (max-width: 767px) {
            #block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list li:nth-of-type(1n+5) {display: none;}
        #block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .load-more-video-dec{ text-align:center; }

        #block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .load-more-video-dec a.add-more-video-dec{display: inline-block; vertical-align: top; padding: 10px 20px; font: 14px/18px Roboto; color: #666; background-color: #d1d1d1; border-radius: 5px; margin: 0 10px; text-transform: uppercase;}

        }

</style>
<script>
    Drupal.behaviors.myModuleTest = {
  attach: function (context, settings) {
    jQuery('#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-footer .load-more-video-dec').click(function(){
        console.log('hhhhhhh', jQuery(this).children('a').text().trim(), jQuery(this).children('a').text().trim() == 'Load More');
        if(jQuery(this).children('a').text().trim() == 'Load More'){
            jQuery("#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list li").show();
            jQuery(this).html('<a href="javascript:void(0)" class="add-more-video-dec">Load Less<i class="fa fa-chevron-circle-up" aria-hidden="true"></i></a>');
        }else{
            console.log('less clicked');
            jQuery('#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list li').hide();
            jQuery('#block-itg-videogallery-other-videogallery-from-section .view-display-id-block_4 .view-content .photo-list li:lt(4)').show();
            jQuery(this).html('<a href="javascript:void(0)" class="add-more-video-dec">Load More<i class="fa fa-chevron-circle-down" aria-hidden="true"></i></a>');
        }
        
        
    });
  }
};

</script>


