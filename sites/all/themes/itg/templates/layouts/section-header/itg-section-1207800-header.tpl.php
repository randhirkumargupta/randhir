<?php
global $base_url, $user;
$uri = base64_encode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
?>
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
            	<li><a href="http://aajtak.intoday.in" target="_blank"><img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/AT-logo.png" alt=""></a></li>
            	<li><a href="http://indiatoday.intoday.in" target="_blank"><img src="http://media2.intoday.in/indiatoday/salaamcricket/2017/images/IT-logo.jpg" alt=""></a></li>
            	
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
        $menu_manager = !empty($data['menu_manager']) ? $data['menu_manager'] : '';
        print  drupal_render(menu_tree_output($menu_manager));
        
        ?>
    </div>         
  </nav>

</div>

<style>
.logo{display:none;}
#block-itg-layout-manager-header-block{
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
    #block-itg-layout-manager-header-block .navigation{
		     margin-top: 0px; 
}
#block-itg-layout-manager-header-block .navigation{
	background:#000;
}

#block-itg-layout-manager-header-block .navigation .menu li a:after{
	background: #000;
}


</style>

