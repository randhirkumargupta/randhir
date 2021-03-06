<?php
global $base_url;
drupal_add_css(".logo {display:none !important}", "inline");
drupal_add_css(drupal_get_path('theme', 'itg') . '/css/section-header.css');
?>
<div id="section-header-event-1762631" class="mind-rocks-2017-delhi india-today-mind-rocks-commanheader-2017">
  <div class="header_part cont_tw_iner">
  <div class="w1000 container">
    <div class="header_top ">
      <div class="left_part_logo"> <a href="<?php echo $data['data']['menu_manager']['event_url'];?>" title="Mind Rocks 2017 "> <img src="https://akm-img-a-in.tosshub.com/indiatoday/images/youthsummit/2017/delhi/images/logo.png" alt="Delhi Mind Rocks 2017"> </a></div>
      
      <div class="logo_it_tt ipadLogo"> <a href="https://indiatodaygroup.com/" title="India Today Group" target="_blank"><span class="itgd_logo"><img src="https://akm-img-a-in.tosshub.com/indiatoday/images/youthsummit/images/ITG-logo-main.png" alt="India Today Group"></span></a> </div>
           
      <div class="social_icons_ipad">
        <ul>
          <li> <a href="https://www.facebook.com/MindRocks" title="Mind Rocks 2017" target="_blank"> <span class="fb"></span> <span class="text_socials"></span> </a> </li>
          <li> <a href="https://twitter.com/mindrocks/" title="Mind Rocks 2017" target="_blank"> <span class="tw"></span> <span class="text_socials"></span> </a> </li>
          <li> <a href="https://plus.google.com/103095347742615965425/about" title="Mind Rocks 2017" target="_blank"> <span class="g_plus"></span> <span class="text_socials"></span> </a> </li>         
          
        </ul>
      </div>
      <div class="right_part_ad ipad_top1">
      <?php
        $block = block_load('itg_ads', ADS_HEADER);
        $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
        print render($render_array);
        ?>        
      </div>
      <div class="txt_rgs">
      <div class="tt_date_time">
        <h2> <span class="date_tr">SEPTEMBER 16, 2017</span> <span class="place_tr">Sirifort Auditorium, New Delhi</span> </h2>
      </div>
      
      <div class="eventGuestArea"><img src="https://akm-img-a-in.tosshub.com/indiatoday/images/youthsummit/2017/delhi/images/masthead-delhi.png" alt=""></div>
      <div class="logo_it_tt"> <a href="https://indiatodaygroup.com/" title="India Today Group" target="_blank"><span class="itgd_logo"><img src="https://akm-img-a-in.tosshub.com/indiatoday/images/youthsummit/images/ITG-logo-main.png" alt="India Today Group"></span></a> </div>
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
    <div class="itg-logo-container clearfix">
	<?php
	if ($data['is_event']) {
	  ?>
	  <div class="event-menu conclave-menu2017" style="background:#b92e70">
		<div id="block-menu-menu-event-menu" class="container event-header-menu-container">
			  <div class="row ">
				  <div class="col-md-12 col-sm-12" style="color:#fff">
					  <div class="wrap-mobile-social"> <a class="mobile-nav nochange" href="javascript:void(0)"><i class="fa fa-bars"></i></a><div class="social-share">
             <a href="https://www.facebook.com/MindRocks" title="Mind Rocks 2017" target="_blank"><i class="fa fa-facebook" aria-hidden="true"></i></a>
             <a href="https://twitter.com/mindrocks/" title="Mind Rocks 2017" target="_blank"><i class="fa fa-twitter" aria-hidden="true"></i></a>
             <a href="https://plus.google.com/103095347742615965425/about" title="Mind Rocks 2017" target="_blank"><i class="fa fa-google-plus" aria-hidden="true"></i></a>
            <div class="search-icon-parent"> <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a> <a href="javascript:void(0)" class="search-icon-search" title="" style="display: none;"><i class="fa fa-search"></i></a><div class="globle-search"> <input class="search-text" placeholder="Type here" type="text" value=""></div></div></div></div>
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
</div>

