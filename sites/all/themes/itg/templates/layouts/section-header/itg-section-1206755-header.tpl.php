<?php
global $base_url;
?>
<div id="section-header-event-1206707" class="india-today-woman-summit">
<div class="header-ads header_ltop_container">
  <div class="row">
      <div class="col-lg-3 col-md-3 col-sm-4 col-xs-12">
        <div class="main_logo"> <a href="index.jsp" title="Salaam cricket 2017"><img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/logo.png" alt="Salaam cricket 2017"></a> </div>
      </div>
      <div class="col-lg-9 col-md-9 col-sm-8 col-sm-12">
        <div class="topRight">
          <div class="photosec">
          <img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/meetthe-img.png" alt="">
          
          </div>
          
          <div class="brandLogo">
          	<ul>
            	<li><a href="http://indiatoday.intoday.in" target="_blank"><img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/IT-logo.jpg" alt=""></a></li>
            	<li><a href="http://aajtak.intoday.in" target="_blank"><img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/AT-logo.png" alt=""></a></li>
            </ul>
          </div>
        </div>
      </div>
    </div>
</div>
<div class="itg-logo-container">
  <nav class="navigation">
    <div class="container">
        <?php 
        if($data['is_event']){
			?>
			<div class="row event-menu GoogleAnalyticsET-processed">
				<div class="col-md-8 col-sm-8 GoogleAnalyticsET-processed" style="color:#f7ee23">
				  <ul class="menu">
					  <?php foreach($data['data']['menu_manager']['menu'] as $menu):?>
						<?php print $menu?>
					  <?php endforeach;?>
				 </ul>	  
				</div>
				<div class="col-md-4 col-sm-4 GoogleAnalyticsET-processed">
				  <div class="event-detail GoogleAnalyticsET-processed">
					<span class="event-str-date"><?php echo $data['data']['menu_manager']['event_start_date']; ?></span>
					<span class="event-vanue-detail-place"><?php echo $data['data']['menu_manager']['event_location']; ?></span>                
				  </div>            
				</div>        
			  </div>
			<?php
		}else if($data['data']['menu_manager']){
			$menu_manager = !empty($data['data']['menu_manager']) ? $data['data']['menu_manager'] : '';
			print  drupal_render(menu_tree_output($menu_manager));        
		}
        
        ?>
    </div>         
  </nav>

</div>

<div class="event-add-header">
                
<?php 
 
   $block = block_load('itg_ads', ADS_HEADER);
   $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
   print render($render_array);
						  
  ?>
  </div>   
</div>
<style>
.logo{display:none;}
#block-itg-layout-manager-header-block, .header_ltop_container{
	background: #e7e7e7 url(http://media2.intoday.in/indiatoday/salaamcricket/2017/images/header-bg.jpg) no-repeat 0 0;
    padding: 10px 0 0px;
}
.header_ltop_container .main_logo{
	float: left;
    margin-top: 33px;
	}
.header_ltop_container .topRight{
	margin: 0px 0 0 0;
    padding: 0px;
}
.header_ltop_container .photosec{
	    float: left;
    margin-top: 52px;
}
.header_ltop_container .brandLogo ul{
	    margin: 0px;
    padding: 0px;
    list-style: none;
}
.header_ltop_container .brandLogo ul li{
	    margin: 0px 5px 0 0;
    padding: 0px;
    display: inline-block;
}
.header_ltop_container .brandLogo{
	margin: 94px 0 0 0px;
    padding: 0px;
    float: left;
    text-align: center;
}
.navigation{
	margin-top: 0px!important; 
}
.navigation .menu li a:after{
	background: #000;
}

.navigation .menu li a{
	    color: #e0e0e0;
	text-transform: uppercase;
    font-weight: 500;
    padding: 0 10px;
    border-top: none;
    height: 37px;
    white-space: nowrap;
    position: relative;
    font-size: 14px;
    font-size: 0.875rem;
    line-height: 37px;
}
.navigation .menu li{
	    float: left;
}
.navigation .menu, .navigation .menu li ul{
	list-style-type: none;
}
.navigation .menu{
	margin-right: 50px;
    max-width: 985px;
}

.navigation{    background: #000!important;}
</style>
