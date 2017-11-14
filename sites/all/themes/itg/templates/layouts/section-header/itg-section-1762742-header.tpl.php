<?php

global $base_url;

$theme_path = drupal_get_path('theme', 'itg');

$imag_path = $base_url.'/'.$theme_path.'/templates/layouts/section-header/images/';

$scriptFlag = FALSE;

?>

<div id="section-header-event-1762742" class="india-today-woman-summit clearfix section-header">

    <div class="header-ads header_ltop_container">

        <div class="container">

          <div class="row">

              <div class="col-lg-3 col-md-3 col-sm-4 col-xs-12">

                    <div class="main_logo"> 

                        <a href="index.jsp" title="women Summit"><img src="<?php print $imag_path;?>womenSumitLogo.png" alt="women Summit"></a> 

                   </div>

              </div>

              <div class="col-lg-9 col-md-9 col-sm-8 col-xs-12">

                <div class="topRight">

                    <h1>India Today woman summit & Awards - 2017</h1>

                    <div class="event-detail GoogleAnalyticsET-processed">

                        <span class="event-str-date"><?php echo $data['data']['menu_manager']['event_start_date']; ?></span>

                        <span class="event-vanue-detail-place"><?php echo $data['data']['menu_manager']['event_location']; ?></span>                

				   </div>    

                </div>

              </div>

            </div>

        </div>

    </div>

    

    

    

	<div class="itg-logo-container">

  <nav class="navigation__event">

    <div class="container">

        <?php 

        if($data['is_event']){

			?>

			<div class="row event-menu GoogleAnalyticsET-processed" id="block-menu-menu-event-menu">

				<div class="col-lg-12 col-md-12 col-sm-12 col-sm-12 GoogleAnalyticsET-processed">

          <a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a>

				  <ul class="menu">

            <?php foreach($data['data']['menu_manager']['menu'] as $menu):?>

            <?php print $menu?>

            <?php endforeach;?>

          </ul>  

          <ul class="flashback-menu">

					  <?php foreach($data['data']['menu_manager']['flashback_menu'] as $menu):?>

						<?php print $menu?>

					  <?php endforeach;?>

				  </ul>	  

				</div>

			  </div>

			<?php

		}else if($data['data']['menu_manager']){

			$scriptFlag = TRUE;

			$menu_manager = !empty($data['data']['menu_manager']) ? $data['data']['menu_manager'] : '';

			echo '<a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a>';

			print  drupal_render(menu_tree_output($menu_manager));        

		}

        

        ?>

    </div>         

  </nav>



</div> 

</div>

<div class="add-header">

                

<?php 

 

   $block = block_load('itg_ads', ADS_HEADER);

   $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));

   print render($render_array);

              

  ?>

  </div>

<style>

/*=========Only For This TPL Css Start*/

.page-node-986777 header:after { content: "."; display: block;height: 0; clear: both;visibility: hidden;}

#section-header-event-1762742{ margin-top:-20px;width: 100%; background: #ffd0f6;}

#block-itg-ads-ads-super-banner-top-nav-728x90--2 {text-align: center; padding-top: 10px;margin-bottom: 10px;}

.page-node-986777 header{ clear: both; }

#section-header-event-1762742{ padding:36px 0 0px}

#section-header-event-1762742 .main_logo img{max-width: inherit;}

#section-header-event-1762742 .main_logo{ text-align: left}

#section-header-event-1762742 .topRight h1{ color:#a9218e; text-transform: uppercase; font-size:45px; line-height:46px; margin-top:10px;}

#section-header-event-1762742 .topRight .event-str-date{ color: #000;font-size: 17px;font-weight: bold;}

#section-header-event-1762742 .topRight .event-vanue-detail-place{ color: #000;font-size: 17px;font-weight: bold;}

#section-header-event-1762742 .topRight .event-detail{ margin-top:15px;}

#block-itg-layout-manager-front-end-breadcrumb{ float: left; width:100%}

#section-header-event-1762742 #block-itg-layout-manager-header-block .navigation{ margin-top:0px;}

#section-header-event-1762742 .header-logo{ display: none}

#section-header-event-1762742 .navigation__event{ margin-top:10px; background:#000}

#section-header-event-1762742 .navigation__event .menu{ margin-left:30px;max-width: 100%; list-style:none; margin:0;width: 75%; display: inline-block;}

#section-header-event-1762742 .navigation__event .flashback-menu{ float: right; position: relative; list-style:none; display: block;}

#section-header-event-1762742 .navigation__event .menu li{ position: relative; display: inline-block;  list-style:none;}

#section-header-event-1762742 .navigation__event .menu li a{ display: block; padding:0 20px;}

#section-header-event-1762742 .navigation__event .menu li a:after{ display: none}

#section-header-event-1762742 .navigation__event .menu li a{ color:#fff; line-height:45px;font-size: 16px; font-weight: normal}

#section-header-event-1762742 .navigation__event .flashback-menu li ul{ display: none; position: absolute; top:42px; left:-215px;  background:#000; z-index: 55555;list-style:none; width:300px; max-width:300px;max-height:100%; overflow:visible;}

#section-header-event-1762742 .navigation__event .flashback-menu li a{ line-height: 45px; font-size: 16px; font-weight: normal;}

#section-header-event-1762742 .navigation__event .flashback-menu li:hover ul{ display: block}

#section-header-event-1762742 .navigation__event .flashback-menu li ul li{ list-style: none; float: left; width:100%; box-sizing: border-box; padding:5px; display: block;border-bottom: 1px solid #ccc;}

.block-itg-ads > div{ width:768px; margin: 0 auto }

/*Humbarger Menu*/

.mobileHumbarger {display: none;cursor: pointer;margin-top:5px;}

.bar1, .bar2, .bar3 { width: 35px; height: 5px; background-color: #fff; margin: 6px 0; transition: 0.4s;}

.change .bar1 { -webkit-transform: rotate(-45deg) translate(-9px, 6px) ; transform: rotate(-45deg) translate(-9px, 6px) ;}

.change .bar2 {opacity: 0;}

.change .bar3 { -webkit-transform: rotate(45deg) translate(-8px, -8px) ;transform: rotate(45deg) translate(-8px, -8px) ;}

#section-header-event-1762742 .mobile-nav{ display: none; }

#section-header-event-1762742 #block-menu-menu-event-menu ul li ul{max-height: 500px; overflow: visible;}

#section-header-event-1762742 .navigation__event .flashback-menu li ul li a{ line-height:22px; font-size:15px; }

@media only screen and (max-width:1024px){

#section-header-event-1762742 .navigation__event{ display: block}

#section-header-event-1762742 .navigation__event .menu{ margin-left:0px;}

#section-header-event-1762742 .navigation__event .menu li{ width: auto;border-bottom: 1px solid #4a4646;}

#section-header-event-1762742 .navigation__event .menu li ul li a{ font-size:14px; line-height:30px; height:30px; padding:0; border-top:0px;}

.block-itg-ads > div{ width:100%; text-align: center; }

}







@media only screen and (max-width:800px){

#section-header-event-1762742 .navigation__event .menu li ul{ right:0; left: inherit;}

#section-header-event-1762742{ padding:10px 0 0}

#section-header-event-1762742 .topRight h1{font-size: 30px;  line-height: 35px; margin-top: 15px;}

	

	

	

}





@media only screen and (max-width:767px){

#section-header-event-1762742{ padding:20px 0 0; }

#section-header-event-1762742 .main_logo {  text-align: center;}

#section-header-event-1762742 .topRight h1 { font-size: 24px; line-height: 30px; margin-top: 5px;}	

#section-header-event-1762742 .topRight .event-str-date,#section-header-event-1762742 .topRight .event-vanue-detail-place{ font-size:14px}

#section-header-event-1762742 .navigation__event .menu{ display: none;}

#section-header-event-1762742 .navigation__event .menu.menuShow{ display: block}

#section-header-event-1762742 .navigation__event .menu li{ float: left; width:100%; box-sizing: border-box}

#section-header-event-1762742 .navigation__event .menu li a{ border-top:0px; padding:0; border-bottom:0px; display: block;}

#section-header-event-1762742 .navigation__event .menu li{ border:0px;}

#section-header-event-1762742 .navigation__event .menu{ position: relative}

#section-header-event-1762742  .mobile-nav{color: #fff;font-size: 26px;height: 40px; line-height: 40px; display: block;}

#section-header-event-1762742 .navigation__event .flashback-menu{ position: absolute; right:15px; top:0px; }

#section-header-event-1762742 .navigation__event .flashback-menu li a{ line-height:37px; }

#section-header-event-1762742 .navigation__event .flashback-menu li ul{ top:40px; left:-173px; }

}



/*=========Only For This TPL Css End*/

</style>

<?php if($scriptFlag):?>

<script>

jQuery('.section-header .navigation__event .mobile-nav').click(function(){

	jQuery('.section-header .navigation__event .menu').toggle();

});

</script>

<?php endif;?>


