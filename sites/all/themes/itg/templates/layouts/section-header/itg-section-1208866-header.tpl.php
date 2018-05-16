<?php
global $base_url;
drupal_add_css(".logo {display:none !important}", "inline");
drupal_add_css(drupal_get_path('theme', 'itg') . '/css/section-header.css');
?>
<div id="section-header-event-1208866" class="india-today-mind-rocks-guwahati-2017">
    <div class="header_part cont_tw_iner">
  <div class="w1000">
    <div class="header_top ">
      <div class="left_part_logo"> <a href="index.jsp" title="Mind Rocks 2017 "> <img src="https://smedia2.intoday.in/indiatoday/youthsummit/2017/delhi/images/logo.png" alt="Mind Rocks 2017"> </a> </div>
      <div class="logo_it_tt ipadLogo"><span class="itgd_logo"><img src="https://smedia2.intoday.in/indiatoday/images/ITG-logo-main.png" alt="India Today Group"></span></div>
      <div class="eventGuestArea ipadGuest"> <img src="https://smedia2.intoday.in/indiatoday/youthsummit/2017/delhi/images/masthead-delhi.png" alt=""> </div>
      <div class="social_icons_ipad">
        <ul>
          <li> <a href="https://www.facebook.com/MindRocks" title="Mind Rocks 2017" target="_blank"> <span class="fb"></span> <span class="text_socials"></span> </a> </li>
          <li> <a href="https://twitter.com/mindrocks/" title="Mind Rocks 2017" target="_blank"> <span class="tw"></span> <span class="text_socials"></span> </a> </li>
          <li> <a href="https://plus.google.com/103095347742615965425/about" title="Mind Rocks 2017" target="_blank"> <span class="g_plus"></span> <span class="text_socials"></span> </a> </li>
        </ul>
      </div>
      <div class="right_part_ad"><!-- Ad Slot 1 tag: --> 
        <!-- begin ZEDO for channel: IT_Other_YouthSummit, Publisher: India Today, Ad Dimension: Super Banner-728x90 -->
        <div id="zt_209516_1" style="display:show" "=""> 
          <script id="zt_209516_1" language="javascript"> 

if(typeof zmt_mtag !='undefined' && typeof zmt_mtag.zmt_render_placement !='undefined')
{
     zmt_mtag.zmt_render_placement(p209516_1);
}
 </script>
          <div class="clear"></div>
        <iframe id="zd_async_frame_zt_209516_1" name="zd_async_frame_zt_209516_1" scrolling="no" frameborder="0" allowfullscreen="" src="javascript:&quot;<html><body style='background:transparent'></body></html>&quot;" style="width: 728px; height: 90px;"></iframe></div>
        <!-- end ZEDO for channel:  IT_Other_YouthSummit, Publisher: India Today, Ad Dimension: Super Banner-728x90 --> 
        
      </div>
      <div class="txt_rgs">
        <div class="tt_date_time">
          <h2> <span class="date_tr">SEPTEMBER 16, 2017</span> <span class="place_tr">Sirifort Auditorium, New Delhi</span> </h2>
        </div>
        <div class="eventGuestArea"><img src="https://smedia2.intoday.in/indiatoday/youthsummit/2017/delhi/images/masthead-delhi.png" alt=""> </div>
        <div class="logo_it_tt"><span class="itgd_logo"><img src="https://smedia2.intoday.in/indiatoday/images/ITG-logo-main.png" alt="India Today Group"></span></div>
      </div>
      <div class="clearfix"></div>
    </div>
    <div class="social_icons_ipad destop_social">
      <ul>
        <li> <a href="https://www.facebook.com/MindRocks" title="Mind Rocks 2017" target="_blank"> <span class="fb"></span> <span class="text_socials"></span> </a> </li>
        <li> <a href="https://twitter.com/mindrocks/" title="Mind Rocks 2017" target="_blank"> <span class="tw"></span> <span class="text_socials"></span> </a> </li>
        <li> <a href="https://plus.google.com/103095347742615965425/about" title="Mind Rocks 2017" target="_blank"> <span class="g_plus"></span> <span class="text_socials"></span> </a> </li>
      </ul>
    </div>
  </div>
</div>
    <div class="itg-logo-container">
	<?php
	if ($data['is_event']) {
	  ?>
	  <div class="event-menu conclave-menu2017" style="background:#000">
		<div id="block-menu-menu-event-menu" class="container event-header-menu-container">
			  <div class="row ">
				  <div class="col-md-12 col-sm-12" style="color:#fff">
					  <div class="wrap-mobile-social"> <a class="mobile-nav nochange" href="javascript:void(0)"><i class="fa fa-bars"></i></a><div class="social-share"> <a href="#"><i class="fa fa-facebook" aria-hidden="true"></i></a> <a href="#"><i class="fa fa-twitter" aria-hidden="true"></i></a><div class="search-icon-parent"> <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a> <a href="javascript:void(0)" class="search-icon-search" title="" style="display: none;"><i class="fa fa-search"></i></a><div class="globle-search"> <input class="search-text" placeholder="Type here" type="text" value=""></div></div></div></div>
					  <ul class="menu">
						  <?php foreach ($data['data']['menu_manager']['menu'] as $menu): ?>
							<?php print $menu ?>
						  <?php endforeach; ?>
					  </ul>	  
				  </div>       
			  </div>
		  </div>
	  </div>
	  <?php
	}else if ($data['data']['menu_manager']) {
	  $menu_manager = !empty($data['data']['menu_manager']) ? $data['data']['menu_manager'] : '';
	  print drupal_render(menu_tree_output($menu_manager));
	}
	?>
           
    </div>
    <div class="event-add-header">
        <?php
        $block = block_load('itg_ads', ADS_HEADER);
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        print render($render_array);
        ?>
    </div>   
</div>

