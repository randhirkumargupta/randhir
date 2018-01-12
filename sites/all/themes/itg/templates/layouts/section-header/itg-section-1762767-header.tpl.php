<?php
global $base_url;
drupal_add_css(".logo {display:none !important}", "inline");
drupal_add_css(drupal_get_path('theme', 'itg') . '/css/section-header.css');
?>
<div id="section-header-event-1208864" class="india-today-woman-summit">
    <header id="conclave2018-header">
        <div class="container">
            <div class="row">
              <div class="col-sm-12 col-md-12 col-lg-12">
                  <div class="top_head_Sec">
                      <a href="index.php" class="headerHomeLogo"><img src="https://instore-tosshub-com.s3.amazonaws.com/conclave/2018/south-conclave-logo.png" alt="INDIA TODAY CONCLAVE EAST 2017"></a>
                    <div class="top_head_Sechm">
                    <h2 class="titlehm">INDIA TODAY CONCLAVE SOUTH 2018</h2>
                        <h5 class="address-texthm">PARK HYATT, HYDERABAD</h5>
                        <h4 class="address-texthm">JANUARY, 18 &amp; 19 2018</h4>
                        <a href="http://www.indiatodaygroup.com" target="_blank" class="rightIndiaTodayLogo indiatoday-logo-sechm"><img src="https://instore-tosshub-com.s3.amazonaws.com/conclave/2018/rightLogo.png" alt=""></a>
                    </div>
                    </div>
                </div>
            </div>
        </div>
    </header>
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

