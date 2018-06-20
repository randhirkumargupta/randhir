<?php
/**
 * @file
 * Returns the HTML for the basic html structure of a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728208
 */
?><!DOCTYPE html>
<!--[if IEMobile 7]><html class="iem7" <?php print $html_attributes; ?>><![endif]-->
<!--[if lte IE 6]><html class="lt-ie9 lt-ie8 lt-ie7" <?php print $html_attributes; ?>><![endif]-->
<!--[if (IE 7)&(!IEMobile)]><html class="lt-ie9 lt-ie8" <?php print $html_attributes; ?>><![endif]-->
<!--[if IE 8]><html class="lt-ie9" <?php print $html_attributes; ?>><![endif]-->
<!--[if (gte IE 9)|(gt IEMobile 7)]><!--><html <?php print $html_attributes . $rdf_namespaces; ?> ><!--<![endif]-->

<head>
  <meta charset="utf-8" />
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, minimum-scale=1, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <?php print $head; ?>  
  <!--<link href='https://fonts.googleapis.com/css?family=Roboto+Slab' rel='stylesheet' type='text/css'>-->
  <!--<link href='https://fonts.googleapis.com/css?family=Roboto:300,400,500,700' rel='stylesheet' type='text/css'>-->
  <script type="text/javascript">
    if (window.location.hash && window.location.hash == '#_=_') {
        window.location.hash = '';
        history.pushState('', document.title, window.location.pathname); // nice and clean
        e.preventDefault(); // no page reload
    }
  </script>
  <!--[if IEMobile]><meta http-equiv="cleartype" content="on"><![endif]-->
  <?php
    $arg = arg();
    $front_page = drupal_is_front_page();
    global $base_url;
    $nid = isset($menu_item['page_arguments'][0]->nid) ? $menu_item['page_arguments'][0]->nid : "";
    $type = isset($menu_item['page_arguments'][0]->type) ? $menu_item['page_arguments'][0]->type : "";
    if((!$front_page) && ($type != 'story')){
      print $styles; 
      print $scripts; 
    }
  ?>
  <?php if ($add_html5_shim and !$add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/html5.js"></script>
    <![endif]-->
  <?php elseif ($add_html5_shim and $add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/html5-respond.js"></script>
    <![endif]-->
  <?php elseif ($add_respond_js): ?>
    <!--[if lt IE 9]>
    <script src="<?php print $base_path . $path_to_zen; ?>/js/respond.js"></script>
    <![endif]-->
  <?php endif;
  ?>
<script>
      (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function()
      { (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
      m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
      })(window,document,'script','https://www.google-analytics.com/analytics.js','ga');
      <?php 
      //if($node_data->type != 'videogallery' && ($arg[0] != 'video' || $arg[2] != 'embed')) { 
      if($arg[0] != 'video' && $arg[2] != 'embed') {
      ?>
      ga('create', 'UA-795349-17', 'auto');
    <?php } ?>
      <?php
      $bylines = NULL;
      if($nid && $type == 'story') {
          if(function_exists('_get_byline_from_nid_for_kindle')) {
            $bylines = implode(",", _get_byline_from_nid_for_kindle($nid));
          }
          }
      ?>
      <?php if(!empty($bylines)) :?>
      ga('set', 'dimension1', '<?php echo $bylines ?>');
      <?php endif; ?>
        <?php 
        //if($node_data->type != 'videogallery' && ($arg[0] != 'video' || $arg[2] != 'embed')) { 
        if(($arg[0] != 'video' && $arg[2] != 'embed')) {
		?>
      ga('send', 'pageview');
      <?php } ?>
    </script>
    <!-- Default comscore -->
    <script type='text/javascript'>
      var _comscore = _comscore || [];
      _comscore.push(
      { c1: "2", c2: "8549097" }
      );
      (function()
      { var s = document.createElement("script"), el = document.getElementsByTagName("script")[0]; s.src = (document.location.protocol == "https:" ? "https://sb" : "http://b") + ".scorecardresearch.com/beacon.js"; el.parentNode.insertBefore(s, el); }
      )();
    </script>
    <noscript>
      <img alt="" src="http://b.scorecardresearch.com/p?c1=2&ac2=8549097&cv=2.0&cj=1">
    </noscript>
        <!-- Comscore function which is called on ajax -->
    <script>
      function comscoreBeacon() {
            var url = "<?php echo FRONT_URL ?>/api/xml/pv.xml?q="+(new Date).getTime();
            var xmlhttp;
            if (window.XMLHttpRequest) {
                // code for IE7+, Firefox, Chrome, Opera, Safari
                xmlhttp = new XMLHttpRequest();
            } else {
                // code for IE6, IE5
                xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
            }
            xmlhttp.open("GET", url, true);
            xmlhttp.send();
            (new Image).src = "https://sb.scorecardresearch.com/b?c1\x3d2\x26c2\x3d8549097\x26c8\x3d" + encodeURIComponent(document.title) + "\x26c7\x3d" + encodeURIComponent(document.location.href) + "\x26c9\x3d" + encodeURIComponent(document.referrer) + "\x26rn\x3d" + ("" + (new Date).getTime())
        }
    </script>
    <?php if(!drupal_is_front_page()):?>
   <script type='text/javascript'>var _sf_startpt=(new Date()).getTime()</script>  
    <?php endif;?>
    <?php 
      $content_id = '';
      $content_type = '';
      if ($type == 'story' || $type == 'photogallery' || $type == 'videogallery') {
        $content_id = $nid;
        $content_type = $type;
      }
    ?>
    <!-- Quora Pixel Code (JS Helper) -->
    <script>
        !function(q,e,v,n,t,s){if(q.qp) return; n=q.qp=function(){n.qp?n.qp.apply(n,arguments):n.queue.push(arguments);}; n.queue=[];t=document.createElement(e);t.async=!0;t.src=v; s=document.getElementsByTagName(e)[0]; s.parentNode.insertBefore(t,s);}(window, 'script', 'https://a.quora.com/qevents.js');
        qp('init', 'a50e46d4d6b444a7ab8308928a6df8f0');
        qp('track', 'ViewContent');
    </script>
    <noscript><img height="1" width="1" style="display:none" src="https://q.quora.com/_/ad/a50e46d4d6b444a7ab8308928a6df8f0/pixel?tag=ViewContent&noscript=1"/></noscript>    
    <!-- End of Quora Pixel Code -->
<?php if(($front_page) || ($type == 'story')){ 
	$sprite_path = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/sprite.png');
	$control_path = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/controls.png');
	$akamai_path = file_create_url(file_default_scheme() . '://../');
	?>
<style>
/*! CSS Used from: Embedded */
*{box-sizing:border-box;}
@font-face{font-family:'OpenSans-Regular';src:url(<?php print $akamai_path.'/sites/all/themes/itg/fonts/OpenSans-Regular.eot';?>);src:local("/"),url(/sites/all/themes/itg/fonts/OpenSans-Regular.woff) format("woff"),url(/sites/all/themes/itg/fonts/OpenSans-Regular.ttf) format("truetype"),url(/sites/all/themes/itg/fonts/OpenSans-Regular.svg) format("svg");font-weight:400;font-style:normal;font-display:swap;}
@font-face{font-family:'Merriweather-Bold';src:local("/"),url(<?php print $akamai_path.'/sites/all/themes/itg/fonts/merriweather-latin-700.woff';?>) format("woff"),url(/sites/all/themes/itg/fonts/Merriweather-Bold.ttf) format("truetype"),url(/sites/all/themes/itg/fonts/merriweather-latin-700.woff2) format("woff2");font-weight:400;font-style:normal;font-display:swap;}
@font-face{font-family:'OpenSans-Semibold';src:url(/sites/all/themes/itg/fonts/OpenSans-Semibold.eot);src:local("/"),url(/sites/all/themes/itg/fonts/OpenSans-Semibold.woff) format("woff"),url(/sites/all/themes/itg/fonts/OpenSans-Semibold.ttf) format("truetype"),url(/sites/all/themes/itg/fonts/OpenSans-Semibold.svg) format("svg");font-weight:400;font-style:normal;font-display:swap;}
@font-face{font-family:'OpenSans-Bold';src:url(/sites/all/themes/itg/fonts/OpenSans-Bold.eot);src:local("/"),url(/sites/all/themes/itg/fonts/OpenSans-Bold.woff) format("woff"),url(/sites/all/themes/itg/fonts/OpenSans-Bold.ttf) format("truetype"),url(/sites/all/themes/itg/fonts/OpenSans-Bold.svg) format("svg");font-weight:400;font-style:normal;font-display:swap;}
@font-face{font-family:'flexslider-icon';src:url(/sites/all/libraries/flexslider/fonts/flexslider-icon.eot);src:url(/sites/all/libraries/flexslider/fonts/flexslider-icon.eot#iefix) format('embedded-opentype'),url(/sites/all/libraries/flexslider/fonts/flexslider-icon.woff) format('woff'),url(/sites/all/libraries/flexslider/fonts/flexslider-icon.ttf) format('truetype'),url(/sites/all/libraries/flexslider/fonts/flexslider-icon.svg#flexslider-icon) format('svg');font-weight:400;font-style:normal;font-display:swap;}
@font-face{font-family:'FontAwesome';src:url(/sites/all/themes/itg/fonts/fontawesome-webfont.eot?v=4.5.0);src:url(/sites/all/themes/itg/fonts/fontawesome-webfont.eot#iefix&v=4.5.0) format("embedded-opentype"),url(/sites/all/themes/itg/fonts/fontawesome-webfont.woff2?v=4.5.0) format("woff2"),url(/sites/all/themes/itg/fonts/fontawesome-webfont.woff?v=4.5.0) format("woff"),url(/sites/all/themes/itg/fonts/fontawesome-webfont.ttf?v=4.5.0) format("truetype"),url(/sites/all/themes/itg/fonts/fontawesome-webfont.svg?v=4.5.0#fontawesomeregular) format("svg");font-weight:400;font-style:normal;font-display:swap;}
.element-invisible {position: absolute!important; clip: rect(1px 1px 1px 1px); clip: rect(1px,1px,1px,1px); overflow: hidden;   height: 1px;}
.container{padding-right:15px;padding-left:15px;margin-right:auto;margin-left:auto;}
@media (min-width: 769px){
.container{max-width:750px;}
}
@media (min-width: 992px){
.container{max-width:970px;}
}
@media (min-width: 1200px){
.container{max-width:1200px;}
}
.row{margin-right:-15px;margin-left:-15px;}
.col-lg-3,.col-sm-4,.col-md-4,.col-lg-4,.col-sm-5,.col-md-5,.col-lg-5,.col-sm-6,.col-sm-7,.col-md-7,.col-sm-8,.col-md-8,.col-lg-8,.col-xs-12,.col-sm-12,.col-md-12,.col-lg-12{position:relative;min-height:1px;padding-right:15px;padding-left:15px;}
.col-xs-12{float:left;}
.col-xs-12{width:100%;}
@media (min-width: 768px){
.col-sm-4,.col-sm-5,.col-sm-6,.col-sm-7,.col-sm-8,.col-sm-12{float:left;}
.col-sm-12{width:100%;}
.col-sm-8{width:66.66666667%;}
.col-sm-7{width:58.33333333%;}
.col-sm-6{width:50%;}
.col-sm-5{width:41.66666667%;}
.col-sm-4{width:33.33333333%;}
}
@media (min-width: 992px){
.col-md-4,.col-md-5,.col-md-7,.col-md-8,.col-md-12{float:left;}
.col-md-12{width:100%;}
.col-md-8{width:66.66666667%;}
.col-md-7{width:58.33333333%;}
.col-md-5{width:41.66666667%;}
.col-md-4{width:33.33333333%;}
}
@media (min-width: 1200px){
.col-lg-3,.col-lg-4,.col-lg-5,.col-lg-8,.col-lg-12{float:left;}
.col-lg-12{width:100%;}
.col-lg-8{width:66.66666667%;}
.col-lg-5{width:41.66666667%;}
.col-lg-4{width:33.33333333%;}
.col-lg-3{width:25%;}
}
h1,h2,h3,h4{font-weight:500;font-family:OpenSans-Regular;word-wrap:break-word;}
h1,h2{font-weight:700;}
h1{font-family:Merriweather-Bold;font-size:40px;line-height:46px;}
h2{font-family:Merriweather-Bold;font-size:29px;line-height:34px;}
h3{font-family:OpenSans-Semibold;font-size:20px;line-height:24px;}
h4{font-size:16px;}
h4{line-height:18px;}
a{text-decoration:none;}
img{max-width:100%;}
a{color:#111;}
.def-cur-pointer{cursor:pointer;}
a:focus{outline:0;}
img{vertical-align:top;height:auto;}
*{margin:0;}
.mt-50{margin-top:20px;}
*{padding:0;}
#block-itg-layout-manager-header-block .top-nav ul li a{padding-left:10px;padding-right:10px;}
.hide,.comment-mobile.desktop-hide{display:none;}
#block-itg-layout-manager-header-block .navigation .menu li a,#block-itg-layout-manager-header-block .top-nav ul li,#page{display:inline-block;}
#page{vertical-align:top;}
#page{width:100%;}
.top-takes-video-container ul li.top-takes-video .pic,.trending-videos li .pic,.video-icon,.watch-right-now-video ul li.watch-right-now-list .pic{position:relative;}
.mhide{display:block;}
.desktop-hide{display:none;}
#main{min-height:500px;}
.row{zoom:1;}
.row:before,.row:after{content:"";display:block;height:0;overflow:hidden;}
.row:after{clear:both;}
#block-itg-layout-manager-header-block ul,footer ul,.trending-videos,.dont-miss ul,.top-takes-video-container ul,.watch-right-now-video ul,#block-itg-front-end-common-latest-from-aajtak ul,#block-itg-front-end-common-latest-from-pti ul,#block-itg-front-end-common-latest-from-businesstoday ul{list-style-type:none;}
.front-title-hide,.widget-help-text{display:none;}
*{padding:0;}
*{margin:0;}
.ripple-effect{position:relative;overflow:hidden;}
.widget-title{display:inline-block;vertical-align:top;position:static!important;background:0 0;color:#000;font-size:16px;padding:0;font-weight:600;margin-bottom:5px;height:auto;font-family:OpenSans-Bold;}
.widget-title a{color:#111;}
.front .itg-layout-container .ad-widget{border:1px solid #ddd;height:280px;padding:4px 37px;}
.front .itg-top-section .top-rhs-add-child .ad-widget{padding:4px 15px;height:283px;}
.itg-listing li{padding:10px;position:relative;border-bottom:1px solid #e4e4e4;font-family:OpenSans-Semibold;}
.itg-listing li a{color:#111;display:inline;border-bottom:none;padding:0;line-height:20px;}
.adtext{font-size:11px;color:#5f5f5f;line-height:16px;text-align:center;text-transform:uppercase;}
.mhide{display:block;}
.desktop-hide{display:none;}
.row{zoom:1;}
.row:after,.row:before{content:"";display:block;height:0;overflow:hidden;}
.row:after{clear:both;}
p{word-wrap:break-word;}
#main{min-height:500px;}
#block-itg-ads-ads-super-banner-top-nav-728x90{text-align:center;padding-top:4px;margin-bottom:10px;}
#block-itg-layout-manager-header-block .navigation:after,#block-itg-layout-manager-header-block .second-level-menu.menu:after,#block-itg-layout-manager-header-block .top-nav:after{clear:both;}
header{margin-bottom:10px;position:relative;z-index:9999;}
#block-itg-layout-manager-header-block{padding-top:20px;background:#fff;position:relative;}
#block-itg-layout-manager-header-block a{color:#a9a9a9;font-family:OpenSans-Semibold;}
#block-itg-layout-manager-header-block .social-nav{position:relative;float:right;}
#block-itg-layout-manager-header-block .social-nav a .fa{font-size:23px;font-size:1.4375rem;}
#block-itg-layout-manager-header-block .social-nav a .fa.fa-mobile{font-size:27px;font-size:1.6875rem;}
#block-itg-layout-manager-header-block .social-nav .globle-search{position:absolute;top:-5px;right:40px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;overflow:hidden;}
#block-itg-layout-manager-header-block .navigation .container,#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3){position:relative;}
#block-itg-layout-manager-header-block .social-nav .globle-search .search-text{width:100%;}
#block-itg-layout-manager-header-block .top-nav{padding:0 15px;margin:25px auto 5px;float:none;zoom:1;background:0 0;}
#block-itg-layout-manager-header-block .navigation .menu li,#block-itg-layout-manager-header-block .top-nav .main-nav ul.menu{float:left;}
#block-itg-layout-manager-header-block .top-nav:after,#block-itg-layout-manager-header-block .top-nav:before{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .top-nav ul li a{font-weight:500;}
#block-itg-layout-manager-header-block .top-nav .main-nav{padding-left:0;line-height:28px;width:65%;margin:0 auto;}
#block-itg-layout-manager-header-block .top-nav .main-nav li.desktop-hide{display:none;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{padding:0 35px;font-size:27px;font-size:1.6875rem;text-transform:uppercase;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a.active,#block-itg-layout-manager-header-block .top-nav .main-nav li a:hover{color:#ffc106;}
#block-itg-layout-manager-header-block .navigation{zoom:1;margin-top:0;background:#a00606;box-shadow:0 6px 5px -3px rgba(0,0,0,.1);height:37px;overflow:hidden;}
#block-itg-layout-manager-header-block .navigation:after,#block-itg-layout-manager-header-block .navigation:before{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .navigation .menu{margin-left:0;max-width:985px;margin-right:0;}
#block-itg-layout-manager-header-block .navigation .menu li a{color:#e0e0e0;text-transform:uppercase;font-weight:500;padding:0 10px;border-top:none;height:37px;white-space:nowrap;position:relative;font-size:14px;font-size:.875rem;line-height:37px;}
#block-itg-layout-manager-header-block .navigation .menu li a:hover{color:#ffc106;}
#block-itg-layout-manager-header-block .navigation .menu li a:after{position:absolute;content:'';height:100%;background:#680101;width:1px;right:0;top:0;}
#block-itg-layout-manager-header-block .navigation .menu#newlist li a:after{display:none;}
#block-itg-layout-manager-header-block .navigation .all-menu{width:46px;cursor:pointer;}
#block-itg-layout-manager-header-block .navigation .all-menu i{font-size:7px;color:#e0e0e0;}
#block-itg-layout-manager-header-block .navigation ul#newlist{padding-left:0;padding-right:0;position:absolute;top:37px;z-index:99999;background:#a00606;display:none;margin-left:0;margin-right:0;right:0!important;width:172px;}
#block-itg-layout-manager-header-block .navigation ul#newlist li{float:none;border:none;border-bottom:1px solid #000;}
#block-itg-layout-manager-header-block .navigation ul#newlist li a{display:block;line-height:normal;height:auto;padding:7px 10px;white-space:normal;word-wrap:break-word;}
#block-itg-layout-manager-header-block ul{list-style:none;}
#block-itg-layout-manager-header-block .top-nav ul li{display:inline-block;}
body.front #block-itg-layout-manager-header-block .top-nav .main-nav li a.active{color:#a9a9a9;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(2) a{padding-left:0;}
/* #block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{width:8px;height:8px;display:inline-block;position:relative;top:-5px;left:-5px;box-shadow:0 0 0 rgba(214,2,12,.8);border-radius:50%;background:#c00;animation:pulse 1.7s infinite;content:"";} */
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{width:8px;height:8px;display:inline-block;position:relative;top:-5px;left:-5px;background:url(https://smedia2.intoday.in/indiatoday/livedot.gif) no-repeat 0 0;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{float:left;width:185px;text-align:center;height:40px;}
#block-itg-layout-manager-header-block .logo{width:auto;top:15px;position:absolute;}
#block-itg-layout-manager-header-block .logo a{display:block;overflow:visible;}
#block-itg-layout-manager-header-block .logo img{padding-left:4px;padding-right:0;vertical-align:top;margin-bottom:-2px;}
#block-itg-layout-manager-header-block .second-level-menu.menu:after,#block-itg-layout-manager-header-block .second-level-menu.menu:before{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .second-level-menu.menu{zoom:1;}
#block-itg-layout-manager-header-block .menu-login{position:absolute;right:0;top:0;}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li{display:inline-block;}
#block-itg-layout-manager-header-block .social-nav .share-icon-parent{position:relative;}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li a{padding:0 10px;line-height:32px;color:#fff;}
#block-itg-layout-manager-header-block .social-nav .social-dropdown{display:none;position:absolute;top:-5px;right:40px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;background:#f0f0f0;height:37px;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo+.menu li.menu__item.is-leaf a{padding-right:0;padding-left:35px;}
.morediv a,.section-ordering a.pic-no-icon{display:block;}
.section-ordering h3{padding:10px 0;font-size:20px;font-size:1.25rem;}
.section-ordering p{font-size:14px;font-size:.875rem;line-height:18px;position:relative;border-top:1px solid #ddd;padding:12px 0 12px 12px;}
.morediv{text-align:right;text-transform:uppercase;font-size:11px;color:#5794e0;}
.morediv a{color:#5794e0;font-weight:700;position:relative;font-family:OpenSans-Bold;}
.widget-wrapper.top_stories_ordering{border:1px solid #ddd;}
.widget-wrapper{height:100%;overflow:hidden;}
.poll-wrapper .poll-banner-image{float:left;margin-right:20px;max-width:170px}.poll-wrapper .poll-data{border:1px solid #ddd;padding:18px;position:relative;display:inline-block;vertical-align:top;width:calc(100% - 5px)}.poll-wrapper .updated-msg{font-size:12px;font-size:.75rem;color:#8a8a8a;font-family:OpenSans-Regular}.poll-wrapper .poll-data .poll-replace-id{width:100%;display:inline-block;vertical-align:top;margin-top:20px}.poll-wrapper .poll-replace-id .form-item-pole-answer{padding:0 0 5px}.poll-wrapper .poll-replace-id label{color:#33363b;font-family:OpenSans-Regular;font-size:14px;text-transform:capitalize}.home_page_poll_widget_block .poll-data{max-width:370px;padding:0;margin:0;border:none;border-bottom:1px solid #ddd}.home_page_poll_widget_block .poll-data .poll-banner-image{max-width:100%;max-height:208px;height:208px;width:100%;margin:0}.home_page_poll_widget_block .poll-wrapper .poll-data .poll-replace-id{padding:10px 0 0;max-height:inherit;overflow-y:auto;margin-top:0}.home_page_poll_widget_block .poll-data .poll-banner-image img{width:100%;height:208px}.home_page_poll_widget_block .poll-data .active-poll-title{background-color:#000;float:left;width:100%;height:auto;overflow:hidden}.home_page_poll_widget_block .poll-data .active-poll-title h2{color:#fff;font-size:16px;line-height:22px;margin:0;padding:5px 10px}.home_page_poll_widget_block .poll-data .active-poll-title .updated-msg{display:none}.home_page_poll_widget_block .poll-data form{text-align:left;padding-bottom:20px}.home_page_poll_widget_block .poll-data form .form-radios{text-align:center}.home_page_poll_widget_block .poll-data form .form-radios .form-item{display:inline-block;vertical-align:top;margin-bottom:5px;padding:0 10px}.home_page_poll_widget_block .poll-data form .form-radios .form-item .form-radio{float:left;margin:3px 2px 0 0}.home_page_poll_widget_block .poll-data form label{display:inline-block;vertical-align:top;padding:0;text-transform:uppercase;font-family:OpenSans-Semibold}.home_page_poll_widget_block .poll-data .poll-replace-id .form-submit{width:95px;height:32px;background-color:#e3e3e3;border:none;font-weight:500;font-family:OpenSans-Semibold;color:#5f5f5f;margin:15px auto 0;display:inherit;font-size:14px;line-height:34px;padding:0;text-transform:uppercase;cursor:pointer}#block-itg-layout-manager-header-block .social-nav .globle-search.active {width: 225px;}#block-itg-layout-manager-header-block .social-nav .social-dropdown.active {display: block;width: 260px;}
.region-breaking-news{display:inline-block;vertical-align:top;width:100%}.breakingnew-home{margin-bottom:10px;font-family:"OpenSans-Regular";zoom:1;position:relative}.breakingnew-home:before,.breakingnew-home:after{content:"";display:block;height:0;overflow:hidden}.breakingnew-home:after{clear:both}.breakingnew-home .title{text-transform:uppercase;background:#000;color:#fff;height:33px;line-height:35px;padding:0 10px;min-width:100px;font-size:18px;font-weight:600;float:left;position:relative;z-index:9;text-align:center;max-width:350px;white-space:nowrap;text-overflow:ellipsis;overflow:hidden;min-width:100px}.breakingnew-home .new-detail{zoom:1;background:#ffc106;height:33px;line-height:33px;padding-right:215px}.breakingnew-home .new-detail:before,.breakingnew-home .new-detail:after{content:"";display:block;height:0;overflow:hidden}.breakingnew-home .new-detail:after{clear:both}.breakingnew-home .new-detail .marquee-container{height:33px;position:relative;overflow:hidden}.breakingnew-home .new-detail .marquee-container .marquee-child{height:33px;line-height:33px;background:transparent}.breakingnew-home .new-detail .marquee-container .marquee-child a *{font-size:20px;color:#000;font-size:18px;line-height:34px}.breakingnew-home .new-detail .marquee-container .field-content{cursor:pointer;display:inline-block;vertical-align:top;padding-right:20px}.breakingnew-home .new-detail .marquee-container br{display:none}.breakingnew-home .new-detail .ltv-and-ss{position:absolute;right:0;top:0}.breakingnew-home .new-detail .social-share{float:right;padding-top:6px}.breakingnew-home .new-detail .social-share ul{list-style-type:none}.breakingnew-home .new-detail .social-share ul li{display:inline-block;vertical-align:top;padding-right:8px}.breakingnew-home .new-detail .social-share ul li a,.breakingnew-home .new-detail .social-share ul li span{background:#000;width:20px;height:20px;border-radius:100%;display:block;color:#fff;text-align:center;line-height:23px;font-size:15px}@media screen and (min-width:768px){.breakingnew-home .new-detail .social-share ul li a,.breakingnew-home .new-detail .social-share ul li span{width:23px;height:23px;line-height:25px}}.breakingnew-home .new-detail .social-share ul li a.share,.breakingnew-home .new-detail .social-share ul li span.share{color:#d0d0d0}.breakingnew-home .new-detail .social-share ul li a.share,.breakingnew-home .new-detail .social-share ul li a.google,.breakingnew-home .new-detail .social-share ul li span.share,.breakingnew-home .new-detail .social-share ul li span.google{background:transparent}.breakingnew-home .new-detail .social-share ul li a.facebook,.breakingnew-home .new-detail .social-share ul li span.facebook{background:#0b4887}.breakingnew-home .new-detail .social-share ul li a.twitter,.breakingnew-home .new-detail .social-share ul li span.twitter{background:#05a3d2}.breakingnew-home .new-detail .social-share ul li a.google,.breakingnew-home .new-detail .social-share ul li span.google{background:url(/sites/all/themes/itg/images/google-icon.jpg) no-repeat center center}.breakingnew-home .new-detail .social-share ul li{padding-right:4px}.breakingnew-home .new-detail .social-share ul li .fa-share-alt{color:#684e00}.breakingnew-home .new-detail .live-tv-link{float:right}.breakingnew-home .new-detail .live-tv-link a{color:#fff;font-size:14px;padding:7px;background:#ffc106}.breakingnew-home .new-detail .live-tv-link a img{padding-top:5px}
.big-news{position:relative;color:#fff;padding:10px;background:#000;margin-bottom:20px;font-family:"OpenSans-Regular"}.big-news .big-story-col-1,.big-news .big-story-col-2{padding:0 15px}.big-news .big-story-col-1{position:relative}.big-news .big-story-col-1 .story-tag{position:absolute;margin:0 0 0 15px}.big-news .big-story-col-1 .loading-popup{top:50%;left:50%;position:absolute;margin-left:-15px;margin-top:-15px;display:none}
.big-news .big-story-col-1 iframe .jwplayer{position:inherit}.big-news .big-story-col-1 i{position:absolute;right:30px;bottom:10px;font-size:26px}.big-news h1{position:relative;margin-bottom:10px}.big-news h1:after{content:'';width:14px;height:14px;background:#f40000;border-radius:100%;display:none}.big-news h1 a i{color:#f40000;font-size:.4em;padding-bottom:7px;display:inline-block;vertical-align:bottom;-webkit-animation-name:blinker;-webkit-animation-iteration-count:infinite;-webkit-animation-timing-function:cubic-bezier(1,0,0,1);-webkit-animation-duration:1s}.big-news a{color:#fff}.big-news p{color:#adacac;font-size:16px;font-size:1rem;line-height:20px;margin-bottom:15px}.big-news .share-new{margin-bottom:15px}.big-news .share-new ul li{display:inline-block;vertical-align:top}.big-news .share-new ul li:first-child a{padding-left:0}.big-news .share-new ul li a{padding:0 10px;border-right:1px solid #606060;font-size:16px;font-size:1rem;line-height:15px;display:inline-block;vertical-align:top;cursor:pointer}.big-news .share-new ul li:last-child a{border-right:none}.big-news .big-story-detail{max-height:106px;overflow:auto}.big-news .big-story-detail li{position:relative;padding-left:15px;margin-bottom:15px}.big-news .big-story-detail li:before{position:absolute;top:5px;left:0;content:'';border-radius:50%;background:#fff;height:6px;width:6px}.big-news .big-story-detail li a{font-size:16px;font-size:1rem;font-weight:500}.big-news .big-story-detail li a:hover{color:#adacac}.big-news .story-tag{position:relative;top:0;left:0;background:#a00606;height:26px;line-height:26px;padding:0 7px;text-transform:uppercase;color:#fff;font-family:"OpenSans-Regular";z-index:1;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;max-width:100%;margin:10px 0 0 10px}.big-news .story-tag a{color:#fff}.big-news .smilies-title,.featured-post .smilies-title{display:inline-block !important}
.big-news .big-story-col-1 { position: relative;}.big-news .big-story-col-1, .big-news .big-story-col-2 {padding: 0 15px;}
.iframe-video iframe { position: absolute; top: 0; left: 0; width: 100%; height: 100%; overflow: auto;}.iframe-video { position: relative; padding-bottom: 56.2%; height: 0; -webkit-overflow-scrolling: touch;}#block-itg-widget-big-story-format .iframe-video {padding-bottom: 66.5%;}
@media only screen and (max-width: 1024px){.big-news .big-story-col-1, .big-news .big-story-col-2 {width: 50%; float: left;}}
@media only screen and (min-width: 769px){.big-news .big-story-col-1 {width: 56.4%;}.big-news .big-story-col-2 { width: 43.6%;padding-left: 0;}.big-news .big-story-col-1, .big-news .big-story-col-2 {float: left;padding: 0 15px;}}
@media only screen and (max-width: 680px){.big-news .big-story-col-1, .big-news .big-story-col-2 {width: 100%;float: none;} .big-news .big-story-col-2 {padding-top: 15px;}}
@media only screen and (max-width:768px){.home_page_poll_widget_block .poll-data form .form-radios .form-item{display:block;text-align: left;}.home_page_poll_widget_block .poll-data form .form-radios .form-item .form-radio{margin: 3px 6px 0 0;}}
@media only screen and (max-width: 768px){
#block-itg-layout-manager-header-block .top-nav{padding:0;width:100%;background:#fff;margin-top:7px;text-align:right;line-height:28px;margin-bottom:0;box-shadow:0 6px 5px -3px rgba(0,0,0,0.1);}
#block-itg-layout-manager-header-block .top-nav .main-nav{padding-left:0;float:none;width:100%;line-height:20px;}
#block-itg-layout-manager-header-block .main-nav .desktop-hide{width:35px;height:20px;position:relative;float:left;padding-left:10px;}
.mobile-nav .bar1,.mobile-nav .bar2,.mobile-nav .bar3{width:20px;height:2px;background-color:#5e5e5e;margin:4px 0;transition:.4s;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu{width:calc(100% - 55px);margin:0 auto;overflow:hidden;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu .nav-centerall{margin:0 auto;width:390px;}
#block-itg-layout-manager-header-block .top-nav ul{list-style-type:none;}
#block-itg-layout-manager-header-block .top-nav ul li{display:inline-block;vertical-align:top;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{font-size:15px;padding:0 8px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{top:-1px;left:-5px;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{width:125px;margin-left:0;}
#block-itg-layout-manager-header-block .logo{width:100px;position:absolute;top:15px;}
#block-itg-layout-manager-header-block .logo img{max-width:100%;padding-left:0;background:transparent;}
#block-itg-layout-manager-header-block .navigation{width:85%;border-right:1px solid #ccc;background:#f9f9f9;box-shadow:0 3px 3px #ccc;height:calc(76vh - 70px);position:absolute;z-index:9999990;overflow-x:hidden;display:none;margin-top:0;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo+.menu li.menu__item.is-leaf a{padding-left:8px;}
.breakingnew-home{text-align:center;background:#ffc106;margin:-5px -15px 10px;padding:0}.breakingnew-home .title{float:left;font-size:12px;line-height:23px;height:23px;padding:0 5px;display:inline-block;margin-bottom:0}.breakingnew-home .new-detail{height:inherit;line-height:23px;font-size:16px;padding:0;width:100%;float:none}.breakingnew-home .new-detail .marquee-container{width:calc(100% - 130px);height:23px;float:left;line-height:23px;margin-left:5px}.breakingnew-home .new-detail .marquee-container .marquee-child{height:23px;line-height:23px}.breakingnew-home .new-detail .social-share{display:none}.breakingnew-home .new-detail .live-tv-link .live-tv-icon{display:none}.breakingnew-home .new-detail .marquee-container .marquee-child a * {    line-height: 23px;font-size: 14px;}.breakingnew-home .new-detail .live-tv-link a { padding: 0 7px;}
}
@media only screen and (max-width: 767px){
header#header{padding-top:60px;}
#block-itg-layout-manager-header-block{position:fixed;width:100%;top:0;z-index:99995;}
#block-itg-layout-manager-header-block .navigation{width:85%;border-right:1px solid #ccc;background:#f9f9f9;box-shadow:0 3px 3px #ccc;height:calc(100vh - 60px);}
#block-itg-ads-ads-super-banner-top-nav-728x90{background:#f2f2f2;padding-bottom:10px;border:1px solid #e2e2e2;min-height:280px;}
}
@media only screen and (max-width:420px){
#block-itg-layout-manager-header-block{padding-top:10px;background:#fff;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu .nav-centerall{margin:0 auto;width:295px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{font-size:13px;font-weight:400;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{width:65px;padding:0 5px;margin-left:0;}
#block-itg-layout-manager-header-block .logo{width:55px;position:absolute;top:15px;}
}
footer,footer .footer-bottom h4,footer a{font-family:OpenSans-Regular;}
footer{margin-top:20px;background:#000;}
footer a{color:#a6a6a6;}
footer .footer-top .container{zoom:1;position:relative;}
footer .footer-top .container:after,footer .footer-top .container:before{content:"";display:block;height:0;overflow:hidden;}
footer .footer-top .container:after{clear:both;}
footer .footer-top a{color:#fff;}
footer .footer-top .footer-top-link{float:left;white-space:nowrap;overflow-x:auto;margin-right:50px;}
footer .footer-top .footer-social-link{font-size:24px;font-size:1.5rem;vertical-align:middle;float:right;padding-right:50px;}
footer .footer-top .footer-social-link .globle-search{position:absolute;top:3px;right:45px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;overflow:hidden;height:30px;}
footer .footer-top .footer-social-link .globle-search .search-text{width:100%;}
footer .footer-top .footer-social-link .fa{font-size:24px;font-size:1.5rem;vertical-align:middle;}
footer .footer-top ul li{display:inline-block;vertical-align:top;}
footer .footer-top ul li:nth-child(1) a{padding-left:0;}
footer .footer-top ul li a{color:#fff;padding:0 15px;height:37px;line-height:37px;border-right:1px solid #111;font-size:16px;display:block;text-transform:uppercase;}
footer .footer-top .footer-expand-icon{position:absolute;top:0;right:15px;width:50px;text-align:center;height:37px;cursor:pointer;background:url(/sites/all/themes/itg/images/sprite.png) 10px 10px no-repeat #000;}
footer .footer-mid{background:#111;padding:4px 0 10px;text-align:center;}
footer .footer-bottom{padding:20px 0;}
footer .footer-bottom a{font-size:12px;}
footer .footer-bottom a:hover{color:#ffc106;}
footer .footer-bottom h4{font-weight:500;color:#fff;text-transform:uppercase;margin-bottom:5px;font-size:14px;font-size:.875rem;}
footer .footer-bottom ul li{padding:2px 0;}
footer .footer-bottom .cell{padding:0 15px;float:left;width:200px;margin-bottom:0;}
footer .footer-bottom .cell ul{margin-bottom:20px;}
footer .footer-bottom .cell ul:last-child{margin-bottom:0;}
footer .footer-copyright{color:#a6a6a6;padding:10px 0;text-align:center;font-size:12px;font-size:.75rem;border-top:1px solid #111;}
.tab-buttons,.tab-buttons span{background:#e4e4e4;border-radius:10px 10px 0 0;}
.front .itg-top-section .top-rhs-add .home-trending-video{margin-top:30px;}
.tab-buttons{zoom:1;}
.tab-buttons:after,.tab-buttons:before{content:"";display:block;height:0;overflow:hidden;}
.tab-buttons:after{clear:both;}
.tab-buttons span{font-weight:500;font-family:OpenSans-Regular;text-transform:uppercase;height:36px;line-height:36px;text-align:center;border-top:3px solid transparent;color:#818181;width:50%;display:block;float:left;cursor:pointer;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;padding:0 5px;}
.tab-buttons span.active{background:#fff;color:#a00606;border-left:1px solid #e4e4e4;border-right:1px solid #e4e4e4;border-top:3px solid #a00606;}
.itg-listing{list-style:none;border:1px solid #ddd;}
.itg-listing li{padding:15px;position:relative;border-bottom:1px solid #e4e4e4;font-family:OpenSans-Semibold;}
.itg-listing li a,.itg-listing li:last-child a{border-bottom:none;}
.itg-listing li a{color:#111;line-height:20px;display:inline;padding:0;}
.itg-listing li a:hover{background:#f8f8f8;}
.itg-listing li a:first-letter{text-transform:capitalize;}
.itg-listing li:before{position:absolute;top:22px;left:9px;content:'';border-radius:50%;background:#959595;height:5px;width:5px;display:none;}
.itg-listing li:hover{background:#f8f8f8;}
.featured-news .featured-post{float:left;width:50%;padding:5px;}
.featured-news .featured-post.featured-post-first{float:none;width:100%;margin-bottom:10px;}
.front .itg-top-section .home-top-story .droppable{height:620px;}
.trending-videos .trending-videos-list .pic{float:left;margin-right:10px;}
/*! CSS Used from: Embedded */
*{margin:0;padding:0;}
.top-autobanner{width:100%;padding:10px 0;text-align:center;}
.top-autobanner .mobile-banner{display:none;}
@media screen and (max-width: 767px){
.top-autobanner .mobile-banner{display:block;}
}
/*! CSS Used from: Embedded */
.block-itg-ads iframe{max-width:inherit!important;}
/*! CSS Used from: https://akm-img-a-in.tosshub.com/advagg_css/css__YrgNoqYWOh7Gx_Cgj7gre3EXzK4uvFWK5REdO1lsmZs__7A8UiwtD0wHzDTfvlO6MlKMCiJHzYB19g_oAAaV8bfI__Mh6lcz2SSWurJ9gYhmBP20dJEYie_L2KE7OY4NIu0rg.css?F21Ie6exrqw77eeBLW7gjBxXwpbeA4nD */
.slides,.slides>li,.flex-control-nav,.flex-direction-nav{margin:0;padding:0;list-style:none;}
.flexslider{margin:0;padding:0;}
.flexslider .slides>li{display:none;-webkit-backface-visibility:hidden;}
.flexslider .slides img{width:100%;display:block;}
.flexslider .slides:after{content:"\0020";display:block;clear:both;visibility:hidden;line-height:0;height:0;}
.flexslider{margin:0;background:#fff;border:4px solid #fff;position:relative;zoom:1;-webkit-border-radius:4px;-moz-border-radius:4px;border-radius:4px;-webkit-box-shadow:'' 0 1px 4px rgba(0,0,0,0.2);-moz-box-shadow:'' 0 1px 4px rgba(0,0,0,0.2);-o-box-shadow:'' 0 1px 4px rgba(0,0,0,0.2);box-shadow:'' 0 1px 4px rgba(0,0,0,0.2);}
.flexslider .slides{zoom:1;}
.flexslider .slides img{height:auto;-moz-user-select:none;}
.flex-viewport{max-height:2000px;-webkit-transition:all 1s ease;-moz-transition:all 1s ease;-ms-transition:all 1s ease;-o-transition:all 1s ease;transition:all 1s ease;}
.flex-direction-nav{*height:0;}
.flex-direction-nav a{text-decoration:none;display:block;width:40px;height:40px;margin:-20px 0 0;position:absolute;top:50%;z-index:10;overflow:hidden;opacity:0;cursor:pointer;color:rgba(0,0,0,0.8);text-shadow:1px 1px 0 rgba(255,255,255,0.3);-webkit-transition:all .3s ease-in-out;-moz-transition:all .3s ease-in-out;-ms-transition:all .3s ease-in-out;-o-transition:all .3s ease-in-out;transition:all .3s ease-in-out;}
.flex-direction-nav a:before{font-family:"flexslider-icon";font-size:40px;display:inline-block;content:'\f001';color:rgba(0,0,0,0.8);text-shadow:1px 1px 0 rgba(255,255,255,0.3);}
.flex-direction-nav a.flex-next:before{content:'\f002';}
.flex-direction-nav .flex-prev{left:-50px;}
.flex-direction-nav .flex-next{right:-50px;text-align:right;}
.flexslider:hover .flex-direction-nav .flex-prev{opacity:.7;left:10px;}
.flexslider:hover .flex-direction-nav .flex-prev:hover{opacity:1;}
.flexslider:hover .flex-direction-nav .flex-next{opacity:.7;right:10px;}
.flexslider:hover .flex-direction-nav .flex-next:hover{opacity:1;}
.flex-control-nav{width:100%;position:absolute;bottom:-40px;text-align:center;}
.flex-control-nav li{margin:0 6px;display:inline-block;zoom:1;*display:inline;}
.flex-control-paging li a{width:11px;height:11px;display:block;background:#666;background:rgba(0,0,0,0.5);cursor:pointer;text-indent:-9999px;-webkit-box-shadow:inset 0 0 3px rgba(0,0,0,0.3);-moz-box-shadow:inset 0 0 3px rgba(0,0,0,0.3);-o-box-shadow:inset 0 0 3px rgba(0,0,0,0.3);box-shadow:inset 0 0 3px rgba(0,0,0,0.3);-webkit-border-radius:20px;-moz-border-radius:20px;border-radius:20px;}
.flex-control-paging li a:hover{background:#333;background:rgba(0,0,0,0.7);}
.flex-control-paging li a.flex-active{background:#000;background:rgba(0,0,0,0.9);cursor:default;}
@media screen and (max-width:860px){
.flex-direction-nav .flex-prev{opacity:1;left:10px;}
.flex-direction-nav .flex-next{opacity:1;right:10px;}
}
.flexslider .flex-direction-nav a{display:none;}
.flexslider:hover .flex-direction-nav a{display:block;}
@media only screen and (min-width:768px) and (max-width:1024px) {#block-itg-widget-featured-photo-carousel .flex-direction-nav{margin-right: 37px;position: absolute;top: 50%;right: 0;}}
/*! CSS Used from: https://akm-img-a-in.tosshub.com/advagg_css/css__NJyel756rLEgMrcX0avSp1tmtzPDRjgWuLuKOt4HjKU__AZpiH0s0Isf5wf_-jqvbmw7M2t5BcOc3apqK9IQlVCQ__Mh6lcz2SSWurJ9gYhmBP20dJEYie_L2KE7OY4NIu0rg.css?CHAqni8ppjXfj5Tx9GeqOydV9JoUNp34 */
.container{padding-right:15px;padding-left:15px;margin-right:auto;margin-left:auto;}
@media (min-width:769px){
.container{max-width:750px;}
}
@media (min-width:992px){
.container{max-width:970px;}
}
@media (min-width:1200px){
.container{max-width:1200px;}
}
.row{margin-right:-15px;margin-left:-15px;}
.col-lg-3,.col-sm-4,.col-md-4,.col-lg-4,.col-sm-5,.col-md-5,.col-lg-5,.col-sm-6,.col-sm-7,.col-md-7,.col-sm-8,.col-md-8,.col-lg-8,.col-xs-12,.col-sm-12,.col-md-12,.col-lg-12{position:relative;min-height:1px;padding-right:15px;padding-left:15px;}
.col-xs-12{float:left;}
.col-xs-12{width:100%;}
@media (min-width:768px){
.col-sm-4,.col-sm-5,.col-sm-6,.col-sm-7,.col-sm-8,.col-sm-12{float:left;}
.col-sm-12{width:100%;}
.col-sm-8{width:66.66666667%;}
.col-sm-7{width:58.33333333%;}
.col-sm-6{width:50%;}
.col-sm-5{width:41.66666667%;}
.col-sm-4{width:33.33333333%;}
}
@media (min-width:992px){
.col-md-4,.col-md-5,.col-md-7,.col-md-8,.col-md-12{float:left;}
.col-md-12{width:100%;}
.col-md-8{width:66.66666667%;}
.col-md-7{width:58.33333333%;}
.col-md-5{width:41.66666667%;}
.col-md-4{width:33.33333333%;}
}
@media (min-width:1200px){
.col-lg-3,.col-lg-4,.col-lg-5,.col-lg-8,.col-lg-12{float:left;}
.col-lg-12{width:100%;}
.col-lg-8{width:66.66666667%;}
.col-lg-5{width:41.66666667%;}
.col-lg-4{width:33.33333333%;}
.col-lg-3{width:25%;}
}
.fa{display:inline-block;font:normal normal normal 14px/1 FontAwesome;font-size:inherit;text-rendering:auto;-webkit-font-smoothing:antialiased;-moz-osx-font-smoothing:grayscale;}
.fa-search:before{content:"\f002";}
.fa-user:before{content:"\f007";}
.fa-volume-up:before{content:"\f028";}
.fa-camera:before{content:"\f030";}
.fa-chevron-right:before{content:"\f054";}
.fa-twitter:before{content:"\f099";}
.fa-facebook:before{content:"\f09a";}
.fa-rss:before{content:"\f09e";}
.fa-google-plus:before{content:"\f0d5";}
.fa-mobile:before{content:"\f10b";}
.fa-circle:before{content:"\f111";}
.fa-share-alt:before{content:"\f1e0";}
.fa-play-circle-o:before {content: "\f01d";}
.slick-slider{position:relative;display:block;box-sizing:border-box;-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;-webkit-touch-callout:none;-khtml-user-select:none;-ms-touch-action:pan-y;touch-action:pan-y;-webkit-tap-highlight-color:transparent;}
.slick-list{position:relative;display:block;overflow:hidden;margin:0;padding:0;}
.slick-list:focus{outline:none;}
.slick-slider .slick-track,.slick-slider .slick-list{-webkit-transform:translate3d(0,0,0);-moz-transform:translate3d(0,0,0);-ms-transform:translate3d(0,0,0);-o-transform:translate3d(0,0,0);transform:translate3d(0,0,0);}
.slick-track{position:relative;top:0;left:0;display:block;}
.slick-track:before,.slick-track:after{display:table;content:'';}
.slick-track:after{clear:both;}
.slick-slide{display:none;float:left;height:100%;min-height:1px;}
.slick-initialized .slick-slide{display:block;}
.mCustomScrollbar{-ms-touch-action:pinch-zoom;touch-action:pinch-zoom;}
.mCustomScrollBox{position:relative;overflow:hidden;height:100%;max-width:100%;outline:0;direction:ltr;}
.mCSB_container{overflow:hidden;width:auto;height:auto;}
.mCSB_inside>.mCSB_container{margin-right:30px;}
.mCSB_scrollTools{position:absolute;width:16px;height:auto;left:auto;top:0;right:0;bottom:0;opacity:.75;filter:"alpha(opacity=75)";-ms-filter:"alpha(opacity=75)";}
.mCSB_scrollTools .mCSB_draggerContainer{position:absolute;top:0;left:0;bottom:0;right:0;height:auto;}
.mCSB_scrollTools .mCSB_draggerRail{width:2px;height:100%;margin:0 auto;-webkit-border-radius:16px;-moz-border-radius:16px;border-radius:16px;}
.mCSB_scrollTools .mCSB_dragger{cursor:pointer;width:100%;height:30px;z-index:1;}
.mCSB_scrollTools .mCSB_dragger .mCSB_dragger_bar{position:relative;width:4px;height:100%;margin:0 auto;-webkit-border-radius:16px;-moz-border-radius:16px;border-radius:16px;text-align:center;}
.mCSB_scrollTools,.mCSB_scrollTools .mCSB_dragger .mCSB_dragger_bar{-webkit-transition:opacity .2s ease-in-out,background-color .2s ease-in-out;-moz-transition:opacity .2s ease-in-out,background-color .2s ease-in-out;-o-transition:opacity .2s ease-in-out,background-color .2s ease-in-out;transition:opacity .2s ease-in-out,background-color .2s ease-in-out;}
.mCustomScrollBox:hover>.mCSB_scrollTools{opacity:1;filter:"alpha(opacity=100)";-ms-filter:"alpha(opacity=100)";}
.mCSB_scrollTools .mCSB_draggerRail{background-color:#000;background-color:rgba(0,0,0,.4);filter:"alpha(opacity=40)";-ms-filter:"alpha(opacity=40)";}
.mCSB_scrollTools .mCSB_dragger .mCSB_dragger_bar{background-color:#fff;background-color:rgba(255,255,255,.75);filter:"alpha(opacity=75)";-ms-filter:"alpha(opacity=75)";}
.mCSB_scrollTools .mCSB_dragger:hover .mCSB_dragger_bar{background-color:#fff;background-color:rgba(255,255,255,.85);filter:"alpha(opacity=85)";-ms-filter:"alpha(opacity=85)";}
.mCSB_scrollTools .mCSB_dragger:active .mCSB_dragger_bar{background-color:#fff;background-color:rgba(255,255,255,.9);filter:"alpha(opacity=90)";-ms-filter:"alpha(opacity=90)";}
*{box-sizing:border-box;}
main{display:block;}
h1,h2,h3,h4{font-weight:500;font-family:"OpenSans-Regular";word-wrap:break-word;}
h1{font-family:Merriweather-Bold;font-size:40px;line-height:46px;font-weight:700;}
h2{font-family:"Merriweather-Bold";font-size:29px;line-height:34px;font-weight:700;}
h3{font-family:"OpenSans-Semibold";font-size:20px;line-height:24px;}
h4{font-size:16px;line-height:18px;}
#block-itg-layout-manager-header-block ul,footer ul,.trending-videos,.dont-miss ul,.top-takes-video-container ul,.watch-right-now-video ul,#block-itg-front-end-common-latest-from-aajtak ul,#block-itg-front-end-common-latest-from-pti ul,#block-itg-front-end-common-latest-from-businesstoday ul{list-style-type:none;}
a{color:#111;text-decoration:none;}
a:focus{outline:0 none;}
img{vertical-align:top;max-width:100%;height:auto;}
.def-cur-pointer{cursor:pointer;}
*{margin:0;}
.mt-50{margin-top:20px;}
*{padding:0;}
#block-itg-layout-manager-header-block .top-nav ul li a{padding-left:10px;padding-right:10px;}
.hide{display:none;}
#page,#block-itg-layout-manager-header-block .top-nav ul li,#block-itg-layout-manager-header-block .navigation .menu li a{display:inline-block;}
#page{vertical-align:top;}
#page{width:100%;}
.video-icon,.trending-videos li .pic,.top-takes-video-container ul li.top-takes-video .pic,.watch-right-now-video ul li.watch-right-now-list .pic{position:relative;}
.mhide{display:block;}
.desktop-hide{display:none;}
#block-itg-front-end-common-latest-from-aajtak ul li a.pic,#block-itg-front-end-common-latest-from-businesstoday ul li a.pic{overflow:hidden;display:block;}
#block-itg-front-end-common-latest-from-aajtak ul li a.pic img,#block-itg-front-end-common-latest-from-businesstoday ul li a.pic img{transition:all 500ms ease 0s;}
#block-itg-front-end-common-latest-from-aajtak ul li a.pic img:hover,#block-itg-front-end-common-latest-from-businesstoday ul li a.pic img:hover{transform:scale(1.2);}
.widget-title{position:relative;top:0;left:0;background:#a00606;height:22px;line-height:22px;padding:0 7px;text-transform:uppercase;color:#fff;font-family:"OpenSans-Regular";z-index:1;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;max-width:100%;}
.widget-title a{color:#fff;}
input[type="text"]{border:1px solid #ddd;height:32px;line-height:30px;padding:5px;color:#333;}
.row{zoom:1;}
.row:before,.row:after{content:"";display:block;height:0;overflow:hidden;}
.row:after{clear:both;}
p{word-wrap:break-word;}
#main{min-height:500px;}
header{margin-bottom:10px;position:relative;z-index:9999;}
#block-itg-layout-manager-header-block{padding-top:20px;background:#fff;position:relative;}
#block-itg-layout-manager-header-block a{color:#a9a9a9;font-family:"OpenSans-Semibold";}
#block-itg-layout-manager-header-block .logo{width:auto;top:15px;position:absolute;}
#block-itg-layout-manager-header-block .logo a{display:block;overflow:visible;}
#block-itg-layout-manager-header-block .logo img{padding-left:4px;padding-right:0;vertical-align:top;margin-bottom:-2px;}
#block-itg-layout-manager-header-block .social-nav{position:relative;float:right;}
#block-itg-layout-manager-header-block .social-nav a .fa{font-size:23px;font-size:1.4375rem;}
#block-itg-layout-manager-header-block .social-nav a .fa.fa-mobile{font-size:27px;font-size:1.6875rem;}
#block-itg-layout-manager-header-block .social-nav .globle-search{position:absolute;top:-5px;right:40px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;overflow:hidden;}
#block-itg-layout-manager-header-block .social-nav .globle-search .search-text{width:100%;}
#block-itg-layout-manager-header-block .top-nav{padding:0 15px;margin:25px auto 5px auto;float:none;zoom:1;background:transparent;}
#block-itg-layout-manager-header-block .top-nav:before,#block-itg-layout-manager-header-block .top-nav:after{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .top-nav:after{clear:both;}
#block-itg-layout-manager-header-block .top-nav ul li a{font-weight:500;}
#block-itg-layout-manager-header-block .top-nav .main-nav{padding-left:0;line-height:28px;width:65%;margin:0 auto;}
#block-itg-layout-manager-header-block .top-nav .main-nav li.desktop-hide{display:none;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3){position:relative;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{content:'';background:url(/sites/all/themes/itg/images/sprite.png) no-repeat 0 -123px;position:absolute;top:-11px;left:20px;width:28px;height:19px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{padding:0 35px;font-size:27px;font-size:1.6875rem;text-transform:uppercase;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a.active,#block-itg-layout-manager-header-block .top-nav .main-nav li a:hover{color:#ffc106;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(2) a{padding-left:0;}
#block-itg-layout-manager-header-block .navigation:before,#block-itg-layout-manager-header-block .navigation:after{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .navigation:after{clear:both;}
#block-itg-layout-manager-header-block .navigation .container{position:relative;}
#block-itg-layout-manager-header-block .navigation .menu{margin-left:0;margin-right:50px;max-width:985px;}
#block-itg-layout-manager-header-block .navigation .menu li{float:left;}
#block-itg-layout-manager-header-block .navigation .menu li a{color:#e0e0e0;text-transform:uppercase;font-weight:500;padding:0 10px;border-top:none;height:37px;white-space:nowrap;position:relative;font-size:14px;font-size:.875rem;line-height:37px;}
#block-itg-layout-manager-header-block .navigation .menu li a:hover{color:#ffc106;}
#block-itg-layout-manager-header-block .navigation .menu li a:after{position:absolute;content:'';height:100%;background:#680101;width:1px;right:0;top:0;}
#block-itg-layout-manager-header-block .navigation .menu#newlist li a:after{display:none;}
#block-itg-layout-manager-header-block .navigation .all-menu{width:46px;cursor:pointer;}
#block-itg-layout-manager-header-block .navigation .all-menu i{font-size:7px;color:#e0e0e0;}
#block-itg-layout-manager-header-block .navigation ul#newlist{padding-left:0;padding-right:0;position:absolute;top:37px;z-index:99999;background:#a00606;display:none;margin-left:0;margin-right:0;right:0!important;width:172px;}
#block-itg-layout-manager-header-block .navigation ul#newlist li{float:none;border:none;border-bottom:1px solid #000;}
#block-itg-layout-manager-header-block .navigation ul#newlist li a{display:block;line-height:normal;height:auto;padding:7px 10px;white-space:normal;word-wrap:break-word;}
#page-title{font-size:26px;font-weight:500;line-height:35px;}
footer{margin-top:20px;background:#000;font-family:"OpenSans-Regular";}
footer a{color:#a6a6a6;font-family:"OpenSans-Regular";}
footer .footer-top .container{zoom:1;position:relative;}
footer .footer-top .container:before,footer .footer-top .container:after{content:"";display:block;height:0;overflow:hidden;}
footer .footer-top .container:after{clear:both;}
footer .footer-top a{color:#fff;}
footer .footer-top .footer-top-link{float:left;white-space:nowrap;overflow-x:auto;margin-right:50px;}
footer .footer-top .footer-social-link{font-size:24px;font-size:1.5rem;vertical-align:middle;float:right;padding-right:50px;}
footer .footer-top .footer-social-link .globle-search{position:absolute;top:3px;right:45px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;overflow:hidden;height:30px;}
footer .footer-top .footer-social-link .globle-search .search-text{width:100%;}
footer .footer-top .footer-social-link .fa{font-size:24px;font-size:1.5rem;vertical-align:middle;}
footer .footer-top ul li{display:inline-block;vertical-align:top;}
footer .footer-top ul li:nth-child(1) a{padding-left:0;}
footer .footer-top ul li a{color:#fff;padding:0 15px;height:37px;line-height:37px;border-right:1px solid #111;font-size:16px;display:block;text-transform:uppercase;}
footer .footer-top .footer-expand-icon{position:absolute;top:0;right:15px;width:50px;text-align:center;height:37px;cursor:pointer;background:#000 url(/sites/all/themes/itg/images/sprite.png) no-repeat 10px 10px;}
footer .footer-mid{background:#111;padding:4px 0 10px;text-align:center;}
footer .footer-bottom{padding:20px 0;}
footer .footer-bottom a{font-size:12px;}
footer .footer-bottom a:hover{color:#ffc106;}
footer .footer-bottom h4{font-weight:500;font-family:"OpenSans-Regular";color:#fff;text-transform:uppercase;margin-bottom:5px;font-size:14px;font-size:.875rem;}
footer .footer-bottom ul li{padding:2px 0;}
footer .footer-bottom .cell{padding:0 15px;float:left;width:200px;margin-bottom:0;}
footer .footer-bottom .cell ul{margin-bottom:20px;}
footer .footer-bottom .cell ul:last-child{margin-bottom:0;}
footer .footer-copyright{color:#a6a6a6;padding:10px 0;text-align:center;font-size:12px;font-size:.75rem;border-top:1px solid #111;}
.itg-front .itg-widget{position:relative;}
.itg-layout-container .itg-h450-section .droppable{height:450px;}
.itg-layout-container .itg-h321-section .droppable{height:321px;}
.itg-common-section .droppable{min-height:420px;}
.itg-top-section{position:relative;}
.tab-buttons{zoom:1;background:#e4e4e4;border-radius:10px 10px 0 0;}
.tab-buttons:before,.tab-buttons:after{content:"";display:block;height:0;overflow:hidden;}
.tab-buttons:after{clear:both;}
.tab-buttons span{font-weight:500;font-family:"OpenSans-Regular";background:#e4e4e4;text-transform:uppercase;height:36px;line-height:36px;text-align:center;border-radius:10px 10px 0 0;border-top:3px solid transparent;color:#818181;width:50%;display:block;float:left;cursor:pointer;white-space:nowrap;overflow:hidden;text-overflow:ellipsis;padding:0 5px;}
.tab-buttons span.active{background:#fff;color:#a00606;border-left:1px solid #e4e4e4;border-right:1px solid #e4e4e4;border-top:3px solid #a00606;}
.itg-listing{list-style:none;border:1px solid #ddd;}
.itg-listing li{padding:15px;position:relative;border-bottom:1px solid #e4e4e4;font-family:"OpenSans-Semibold";}
.itg-listing li a{color:#111;padding:15px 15px 15px 20px;display:block;border-bottom:1px solid #e4e4e4;line-height:20px;}
.itg-listing li a:hover{background:#f8f8f8;}
.itg-listing li a:first-letter{text-transform:capitalize;}
.itg-listing li:last-child a{border-bottom:none;}
.itg-listing li:before{position:absolute;top:22px;left:9px;content:'';border-radius:50%;background:#959595;height:5px;width:5px;}
.itg-listing li a{display:inline;border-bottom:none;padding:0;}
.itg-listing li:before{display:none;}
.itg-listing li:hover{background:#f8f8f8;}
.featured-news{zoom:1;padding-bottom:10px;margin:0 -5px;}
.featured-news:before,.featured-news:after{content:"";display:block;height:0;overflow:hidden;}
.featured-news:after{clear:both;}
.featured-news .featured-post{float:left;width:50%;padding:5px;}
.featured-news .featured-post a{display:block;}
.featured-news .featured-post a:hover{color:#193984;}
.featured-news .featured-post img{width:100%;}
.featured-news .featured-post.featured-post-first{float:none;width:100%;margin-bottom:10px;}
.section_wise_order .widget-title{position:absolute;}
.section-ordering a:not(.video-icon){display:inline-block;}
.section-ordering a.pic-no-icon{display:block;}
.section-ordering h3{padding:10px 0;font-size:20px;font-size:1.25rem;}
.section-ordering p{font-size:15px;font-size:.9375rem;line-height:20px;position:relative;border-top:1px solid #ddd;padding:12px 0 12px 12px;}
.section-ordering p:before{position:absolute;top:18px;left:0;content:'';border-radius:100%;background:#a00606;height:5px;width:5px;}
.section-ordering img{width:100%;max-height:208px;}
.video-icon,.trending-videos li .pic{display:inline-block;vertical-align:top;}
.video-icon:after,.trending-videos li .pic:after{background:url(/sites/all/themes/itg/images/sprite.png) no-repeat 0 -87px;content:"";width:18px;height:18px;position:absolute;left:5px;bottom:5px;}
.trending-videos{border:1px solid #ddd;padding-top:10px;}
.trending-videos .trending-videos-list{overflow:hidden;padding:10px;}
.trending-videos .trending-videos-list .pic{float:left;margin-right:10px;}
.trending-videos li+li{border-top:1px solid #aaa9a9;}
.top-takes-video-container.home-top-takes ul{padding-top:10px;border:1px solid #ddd;}
.top-takes-video-container.home-top-takes .top-takes-list{padding:10px;border:0;}
.dont_miss .widget-title{position:relative;display:inline-block;vertical-align:top;margin-bottom:5px;}
.dont-miss ul{zoom:1;}
.dont-miss ul:before,.dont-miss ul:after{content:"";display:block;height:0;overflow:hidden;}
.dont-miss ul:after{clear:both;}
.dont-miss ul .dont-miss-listing{overflow:hidden;padding:10px;}
.dont-miss ul .dont-miss-listing .dm-pic{float:left;margin-right:15px;}
.dont-miss ul .dont-miss-listing .dm-detail{display:block;overflow:hidden;word-wrap:break-word;font-size:15px;font-size:.9375rem;line-height:20px;color:#111;font-family:"OpenSans-Semibold";}
.dont-miss ul .dont-miss-listing{float:left;width:50%;padding:0 10px 25px 0;border:none;}
.dont-miss ul .dont-miss-listing .dm-pic{width:170px;}
.dont-miss ul .dont-miss-listing .dm-pic a{display:block;}
.dont-miss ul .dont-miss-listing .dm-detail p{font-size:15px;font-size:.9375rem;line-height:20px;color:#111;font-family:"OpenSans-Semibold";}
.dont-miss ul .dont-miss-listing:nth-child(2n+1){clear:left;}
.dont-miss ul .dont-miss-listing:nth-child(3),.dont-miss ul .dont-miss-listing:nth-child(4){padding-bottom:0;}
.watch-video-home .widget-title{position:relative;margin-bottom:5px;}
.home-shows .trending-videos{border:none;padding-top:0;}
.home-shows .trending-videos .trending-videos-list{overflow:hidden;padding:10px 0;}
.home-shows .trending-videos .trending-videos-list:first-child{padding-top:0;}
.top-takes-video-container ul .top-takes-video{overflow:hidden;padding:10px;}
.top-takes-video-container ul .top-takes-video .pic{float:right;margin-left:10px;}
.top-takes-video-container ul .top-takes-video .title{display:block;overflow:hidden;word-wrap:break-word;font-size:15px;font-size:.9375rem;line-height:20px;color:#111;font-family:"OpenSans-Semibold";}
.top-takes-video-container ul li.top-takes-video{padding:10px 0;}
.top-takes-video-container ul li.top-takes-video .pic:after{background:url(/sites/all/themes/itg/images/video-icon-small.png) no-repeat;content:"";width:18px;height:18px;position:absolute;right:5px;bottom:5px;}
.top-takes-video-container ul li+li{border-top:1px solid #ddd;}
.top-takes-video-container ul li:last-child{border-bottom:1px solid #ddd;}
.watch_right_now_videos_widget .widget-title{position:relative;}
.watch-right-now-video ul .watch-right-now-list{overflow:hidden;padding:10px;}
.watch-right-now-video ul .watch-right-now-list .pic{float:right;margin-left:5px;}
.watch-right-now-video ul .watch-right-now-list .title{display:block;overflow:hidden;word-wrap:break-word;font-size:15px;font-size:.9375rem;line-height:20px;color:#111;font-family:"OpenSans-Semibold";}
.watch-right-now-video ul li.watch-right-now-list{padding:10px 0;}
.watch-right-now-video ul li.watch-right-now-list .pic{width:88px;}
.watch-right-now-video ul li.watch-right-now-list .pic:after{background:url(/sites/all/themes/itg/images/video-icon-small.png) no-repeat;content:"";width:18px;height:18px;position:absolute;right:5px;bottom:5px;}
.watch-right-now-video ul li.watch-right-now-list+li{border-top:1px solid #ddd;}
.watch-right-now-video ul li.watch-right-now-list:last-child{border-bottom:1px solid #ddd;}
.sidebar-second .top-takes-video-container ul li,.sidebar-second .watch-right-now-video ul li{padding:10px 0;}
.featured_photo_carousel .widget-title{position:absolute;top:10px;left:10px;}
.featured_photo_carousel .data-holder{max-width:750px;background-color:#fff;overflow:hidden;}
.featured_photo_carousel .flexslider{border:none;margin:0;max-width:650px;width:100%;}
.featured_photo_carousel .flexslider .flex-caption{width:96%;padding:2%;left:0;bottom:0;background:rgba(0,0,0,0.5);color:#fff;text-shadow:0 -1px 0 rgba(0,0,0,0.3);font-size:14px;line-height:18px;}
.featured_photo_carousel .flexslider .flex-viewport{overflow:visible!important;}
.featured_photo_carousel .flexslider .slides li{position:relative;border-right:1px solid #fff;}
.featured_photo_carousel .flexslider .slides li .detail{width:100%;font-family:"OpenSans-Regular";}
.featured_photo_carousel .flexslider .slides li .detail .flex-caption{padding:5px;background:#000;color:#fff;font-size:13px;font-size:.8125rem;font-weight:500;line-height:18px;width:auto;max-height:45px;min-height:45px;overflow:hidden;}
.featured_photo_carousel .flexslider .slides li .detail .flex-caption a{color:#fff;}
.featured_photo_carousel .flexslider .slides li .detail .flex-caption a:hover{color:#f1f1f1;}
.featured_photo_carousel .flexslider .slides li .detail .flex-count{position:absolute;bottom:49px;left:0;display:inline-block;vertical-align:top;background:#000;opacity:.5;color:#fff;font-size:12px;font-size:.75rem;line-height:23px;margin-bottom:0;padding:0 10px;height:23px;}
.featured_photo_carousel .flexslider .flex-count{display:inline-block;vertical-align:top;background:#000;opacity:.6;color:#fff;font-size:12px;font-size:.75rem;margin-bottom:10px;}
.featured_photo_carousel .flexslider .flex-count i{margin-right:5px;}
.featured_photo_carousel .flexslider .flex-direction-nav a{display:block;opacity:1;}
.featured_photo_carousel .flexslider .flex-direction-nav a:before{font:normal normal normal 14px/1 FontAwesome;font-size:30px;display:inline-block;color:#fff;background:#67aaef;z-index:1;width:40px;height:40px;line-height:40px;text-align:center;}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-prev{left:auto;right:0;border-right:1px solid #1a3c8d;width:41px;}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-prev:before{content:'\f104';}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-next{right:-40px;}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-next:before{content:'\f105';}
.itg-layout-container ul li:hover a{color:#193984;}
[id*="block-itg-widget-featured-photo-carousel"] .flexslider .slides img{max-height:340px;}
#block-itg-layout-manager-header-block .second-level-menu.menu{zoom:1;}
#block-itg-layout-manager-header-block .second-level-menu.menu:before,#block-itg-layout-manager-header-block .second-level-menu.menu:after{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .second-level-menu.menu:after{clear:both;}
#block-itg-layout-manager-header-block .menu-login .user-menu{position:relative;z-index:99999;}
#block-itg-layout-manager-header-block .menu-login .user-menu a{cursor:pointer;}
#block-itg-layout-manager-header-block .menu-login .user-menu a.user-icon{background:transparent;color:#fff;text-align:center;font-size:28px;}
.pic-no-icon:after{display:none;}
.front #content{display:inline-block;vertical-align:top;width:100%;}
#block-itg-front-end-common-latest-from-aajtak ul,#block-itg-front-end-common-latest-from-pti ul,#block-itg-front-end-common-latest-from-businesstoday ul{border:1px solid #ddd;min-height:381px;}
#block-itg-front-end-common-latest-from-aajtak ul .third-party-list,#block-itg-front-end-common-latest-from-pti ul .third-party-list,#block-itg-front-end-common-latest-from-businesstoday ul .third-party-list{overflow:hidden;padding:10px;}
#block-itg-front-end-common-latest-from-aajtak ul .third-party-list .pic,#block-itg-front-end-common-latest-from-businesstoday ul .third-party-list .pic{float:left;margin-right:10px;}
#block-itg-front-end-common-latest-from-aajtak ul .third-party-list .title{display:block;overflow:hidden;word-wrap:break-word;font-size:15px;font-size:.9375rem;line-height:20px;color:#111;font-family:"OpenSans-Semibold";}
#block-itg-front-end-common-latest-from-aajtak ul li a.pic,#block-itg-front-end-common-latest-from-businesstoday ul li a.pic{width:88px;height:66px;}
#block-itg-front-end-common-latest-from-aajtak ul li+li,#block-itg-front-end-common-latest-from-pti ul li+li,#block-itg-front-end-common-latest-from-businesstoday ul li+li{border-top:1px solid #ddd;}
.search-icon-parent{position:relative;}
.search-icon-parent .search-icon-search{display:none;}
.widget-help-text{display:none;}
.top-n-most-popular-stories .widget-wrapper .data-holder{height:calc(100% - 22px);}
.top-n-most-popular-stories .widget-wrapper .data-holder .mCSB_inside>.mCSB_container{margin-right:0;}
.top-n-most-popular-stories .widget-wrapper .data-holder .mCSB_scrollTools{width:3px;}
.widget-wrapper.featured_photo_carousel .data-holder{height:calc(100% - 27px);}
.top_stories_ordering .widget-title{padding:5px 7px 1px;}
.data-holder .itg-listing li{padding:10px;}
.itg-sponsor-title{position:absolute;font-size:9px;padding:4px 5px 5px 18px;color:#447b9a;}
.data-holder .section-ordering p a{padding:5px 0;}
.data-holder .section-ordering p:before{top:25px;}
.adtext{font-size:11px;color:#5f5f5f;line-height:16px;text-align:center;text-transform:uppercase;}
#block-itg-layout-manager-header-block .navigation .menu li.userlogin-icon-parent-mobile{display:none;}
#block-itg-layout-manager-header-block .top-nav .main-nav ul.menu li.desktop-hide{display:none;}
#block-itg-ads-ads-super-banner-top-nav-728x90{text-align:center;padding-top:4px;margin-bottom:10px;}
#block-itg-layout-manager-header-block .top-nav .main-nav ul.menu{float:left;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{width:24px;height:24px;display:inline-block;top:2px;left:12px;background:url(https://smedia2.intoday.in/indiatoday/livedot.gif) no-repeat 0 0;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile{display:none;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{float:left;width:185px;text-align:center;height:40px;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo+.menu li.menu__item.is-leaf a{padding-right:0;padding-left:35px;}
#block-itg-layout-manager-header-block .social-nav .social-dropdown{display:none;position:absolute;top:-5px;right:40px;-webkit-transition:all .5s ease-in-out;-moz-transition:all .5s ease-in-out;-ms-transition:all .5s ease-in-out;-o-transition:all .5s ease-in-out;transition:all .5s ease-in-out;width:0;background:#f0f0f0;height:37px;}
#block-itg-layout-manager-header-block .navigation .menu{margin-right:0;}
#block-itg-layout-manager-header-block .menu-login{position:absolute;right:0;top:0;}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li{display:inline-block;}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li a{padding:0 10px;line-height:32px;color:#fff;}
#block-itg-layout-manager-header-block .social-nav .globle-search .search-text{height:37px;border:0;}
#block-itg-layout-manager-header-block .social-nav .share-icon-parent{position:relative;}
#block-itg-layout-manager-header-block .social-nav .social-dropdown ul li a{line-height:45px;color:#333;}
#block-itg-layout-manager-header-block .social-nav li:hover .social-dropdown ul li:hover .fa,#block-itg-layout-manager-header-block .social-nav li:hover .social-dropdown ul li .fa{color:#333;}
.front .ad-widget .sidebar-ad .block-itg-ads{margin:0 auto 0;}
.section-ordering p,.trending-videos .trending-videos-list,.watch-right-now-video ul li{font-family:"OpenSans-Semibold";}
.itg-top-section .home-top-story .data-holder .itg-listing li{padding:10px;font-family:"OpenSans-Semibold";}
#block-itg-front-end-common-latest-from-aajtak ul .third-party-list,#block-itg-front-end-common-latest-from-pti ul .third-party-list,#block-itg-front-end-common-latest-from-businesstoday ul .third-party-list{font-family:"OpenSans-Semibold";}
#page{height:100%;}
input[type="text"]{transition:all 300ms;}
input[type="text"]:focus{border-color:#026bc5;}
input[type="text"]{-webkit-appearance:none;appearance:none;}
.itg-h450-section .widget-wrapper{height:100%;padding:10px;background-color:#f3f3f3;}
.itg-h321-section .dont_miss{height:100%;padding:5px 20px 8px;background-color:#f3f3f3;}
.widget-wrapper{height:100%;overflow:hidden;}
.widget-wrapper .data-holder{height:100%;}
.widget-wrapper .data-holder .block-itg-widget{height:100%;}
.widget-wrapper .data-holder .block-itg-widget>div,.widget-wrapper .data-holder .block-itg-widget>ul{height:100%;}
.widget-wrapper.top_stories_ordering{border:1px solid #ddd;}
.widget-wrapper.top_stories_ordering .data-holder .block-itg-widget{height:calc(100% - 22px);overflow:hidden;}
.widget-wrapper.top_stories_ordering .data-holder .block-itg-widget .itg-listing{border:none;height:auto;}
.widget-title{display:inline-block;vertical-align:top;position:static!important;background:transparent;color:#000;font-size:16px;padding:0;font-weight:600;margin-bottom:5px;height:auto;font-family:"OpenSans-Bold";}
.widget-title a{color:#111;}
.featured-news .featured-post h2{margin-top:5px;}
.featured-news .featured-post h3{overflow:hidden;margin-top:5px;line-height:22px;font-size:18px;}
.itg-layout-container .ad-widget{border:1px solid #ddd;height:321px;padding:25px 37px;}
.itg-layout-container .ad-widget .sidebar-ad{height:100%;}
.ripple-effect{position:relative;overflow:hidden;}
.data-holder a:hover{color:#193984;}
footer .footer-top ul li a:hover{color:#ffc106;}
.rippleEffect { animation: rippleDrop .8s linear;}
.ripple {width: 0; height: 0; border-radius: 50%; background: rgba(255,255,255,0.4); transform: scale(0); position: absolute;
    opacity: 1; z-index: 9999;} @keyframes rippleDrop{100%{transform:scale(2);opacity:0}}
@media all and (min-width:1025px){
.featured-news .featured-post>a,.dm-pic a,.top-takes-list a,.trending-videos-list .pic a,.trending-videos-list>a.pic,.watch-right-now-list>a{overflow:hidden;display:block;}
.featured-news .featured-post>a img,.dm-pic a img,.top-takes-list a img,.trending-videos-list .pic a img,.trending-videos-list>a.pic img,.watch-right-now-list>a img{transition:all 500ms ease 0s;}
.featured-news .featured-post>a img:hover,.dm-pic a img:hover,.top-takes-list a img:hover,.trending-videos-list .pic a img:hover,.trending-videos-list>a.pic img:hover,.watch-right-now-list>a img:hover{transform:scale(1.2);}
.social-nav li .fa{transition:all 300ms;}
.social-nav li:hover .fa{color:#ffc106;}
}
#widget-ajex-loader{background:rgba(0,0,0,0.5);position:fixed;left:0;top:0;height:100%;width:100%;z-index:99999;}
#widget-ajex-loader img{bottom:0;left:0;margin:auto;position:absolute;right:0;top:0;}
.block-itg-ads iframe{max-width:100%;overflow:hidden;}
@media all and (max-width:767px){
.featured_photo_carousel .flexslider{max-width:100%;}
.featured_photo_carousel .flexslider .slides li{border-right:none;}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-prev{left:0;right:auto;border-right:none;width:40px;}
.featured_photo_carousel .flexslider .flex-direction-nav a.flex-next{right:0;}
}
@media all and (max-width:767px){
.featured-news .featured-post h3{max-height:none;}
}
@media only screen and (max-width:1024px){
h1{font-size:26px;line-height:32px;font-weight:700;}
h2{font-size:22px;line-height:26px;font-weight:700;}
h3{font-size:16px;line-height:24px;}
h4{font-size:12px;line-height:18px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{padding:0 15px;font-size:20px;font-size:1.25rem;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{top:-6px;left:0;}
#block-itg-layout-manager-header-block .top-nav .headeritg-logo{margin-left:10px;}
#block-itg-layout-manager-header-block .navigation .menu{margin-left:0;margin-right:50px;padding-left:0;max-width:790px;}
#block-itg-layout-manager-header-block .navigation .menu li a{padding:0 8px;}
.itg-layout-container .itg-h450-section .droppable{height:auto;}
.itg-layout-container .ad-widget{height:300px;padding:10px 0;width:322px;margin:0 auto;}
.itg-h321-section .dont_miss{padding:5px 10px 8px;}
.dont-miss ul .dont-miss-listing .dm-pic{width:140px;}
footer .footer-top .footer-top-link{float:none;}
footer .footer-top .footer-social-link{width:280px;position:relative;margin:0 auto;float:none;padding-right:0;padding-bottom:10px;}
footer .footer-top .footer-social-link .globle-search{right:50px;}
footer .footer-top div.footer-expand-icon{display:none;}
footer .footer-top .footer-expand-icon{top:auto;right:auto;position:absolute;}
.widget-wrapper{max-height:100%;height:auto;}
}
@media only screen and (max-width:768px){
.block-itg-ads{overflow:hidden;}
header{margin-bottom:15px;}
.mhide{display:none;}
.desktop-hide{display:block;}
#block-itg-layout-manager-header-block .logo{width:100px;position:absolute;top:15px;}
#block-itg-layout-manager-header-block .logo img{max-width:100%;padding-left:0;background:transparent;}
#block-itg-layout-manager-header-block .top-nav{padding:0;width:100%;background:#fff;margin-top:7px;text-align:right;line-height:28px;margin-bottom:0;box-shadow:0 6px 5px -3px rgba(0,0,0,0.1);}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{padding:0 8px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li.desktop-hide{display:inline-block;}
#block-itg-layout-manager-header-block .top-nav ul{list-style-type:none;}
#block-itg-layout-manager-header-block .top-nav ul li{display:inline-block;vertical-align:top;}
#block-itg-layout-manager-header-block .top-nav ul li a{text-decoration:none;text-transform:uppercase;font-size:15px;font-weight:500;padding-right:10px;}
#block-itg-layout-manager-header-block .top-nav .main-nav{padding-left:0;float:none;width:100%;line-height:20px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{font-size:15px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before{top: 4px;left: -4px; width: 13px; height: 13px;  background-size: 100%;}
#block-itg-layout-manager-header-block .navigation{background:#a00606;display:none;margin-top:0;}
#block-itg-layout-manager-header-block .navigation .container{position:relative;}
#block-itg-layout-manager-header-block .navigation .menu{zoom:1;margin:0;padding-left:0;padding-right:0;}
#block-itg-layout-manager-header-block .navigation .menu:before,#block-itg-layout-manager-header-block .navigation .menu:after{content:"";display:block;height:0;overflow:hidden;}
#block-itg-layout-manager-header-block .navigation .menu:after{clear:both;}
#block-itg-layout-manager-header-block .navigation .menu li{width:100%;}
#block-itg-layout-manager-header-block .navigation .menu li a{border-top:1px solid #900505;border-right:none;display:block;height:30px;line-height:30px;padding:0 15px;}
#block-itg-layout-manager-header-block .navigation .menu li a:hover{color:#ffc106;}
#block-itg-layout-manager-header-block .navigation .menu li a:after{display:none;}
#block-itg-layout-manager-header-block .navigation .menu li.all-menu a{border-right:none;}
#block-itg-layout-manager-header-block .navigation .menu li.all-menu a i{font-size:22px;font-size:1.375rem;color:#131212;vertical-align:middle;}
#block-itg-layout-manager-header-block .navigation ul#newlist{position:absolute;right:0;z-index:99;background:#a00606;display:none;}
footer .footer-top .footer-top-link{float:none;}
.itg-layout-container .itg-h450-section .droppable,.itg-layout-container .itg-h321-section .droppable,.itg-common-section .droppable{height:auto;min-height:auto;}
.itg-top-section .featured-news{padding-bottom:0;}
.dont-miss ul .dont-miss-listing .dm-pic{width:124px;}
}
@media only screen and (max-width:768px){
.sidebar-second .top-takes-video-container ul li,.sidebar-second .watch-right-now-video ul li{padding:10px 24px 10px 0;}
}
@media only screen and (max-width:768px){
#block-itg-ads-ads-super-banner-top-nav-728x90{margin-bottom:20px;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile{display:block;padding:5px 0 5px 15px;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile .globle-search{font-family:'Open Sans',sans-serif;width:85%;float:left;margin-right:10px;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile .globle-search input{width:100%;padding:5px 10px;border:1px solid #ccc;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile a{border-top:0;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu{width:350px;margin:0 auto;}
#block-itg-layout-manager-header-block .main-nav .desktop-hide{position:absolute;width:38px;height:38px;}
}
@media only screen and (max-width:767px){
.dont-miss ul .dont-miss-listing{width:100%;padding:0 0 20px;}
.dont-miss ul .dont-miss-listing .dm-pic{width:124px;}
.dont-miss ul .dont-miss-listing:nth-child(3){padding-bottom:20px;}
.dont-miss ul .dont-miss-listing .dm-detail{overflow:initial;}
.featured_photo_carousel .flexslider .flex-direction-nav a:before{width:30px;height:30px;line-height:30px;font-size:20px;}
}
@media only screen and (max-width:680px){
.itg-h450-section .col-md-8 .widget-wrapper{height:100%;padding:0;background-color:#f3f3f3;}
.featured_photo_carousel .widget-title{top:0;left:0;}
.itg-h321-section .dont_miss{padding:5px 10px 5px;}
div.footer-expand-icon{display:block;}
footer .footer-top div.footer-expand-icon{display:block;position:absolute;top:0;right:15px;}
footer .footer-top .footer-social-link{display:none;}
}
@media only screen and (min-width:769px){
.featured-news{padding:5px;border:1px solid #ddd;margin:0;}
.featured-news .featured-post{padding:5px;}
.section-ordering h3{font-size:20px;font-size:1.25rem;}
.featured_photo_carousel .flexslider .flex-direction-nav{display:block;}
.featured_photo_carousel .flexslider .slides li .detail .flex-caption{font-size:18px;font-size:1.125rem;font-weight:500;line-height:24px;padding:10px;min-height:68px;max-height:auto;overflow:initial;}
.featured_photo_carousel .flexslider .slides li .detail .flex-count{position:absolute;bottom:78px;left:0;}
}
@media only screen and (min-width:769px){
.sidebar-second .top-takes-video-container ul li,.sidebar-second .watch-right-now-video ul li{padding:10px 24px 10px 30px;}
}
@media only screen and (min-width:768px) and (max-width:1200px){
.widget-wrapper.top_stories_ordering .data-holder .block-itg-widget{overflow:scroll;max-height:663px;}
}
@media (max-width:767px){
.itg-layout-container .ad-widget{width:322px;}
}
@media only screen and (max-width:768px){
#block-itg-layout-manager-header-block .navigation .menu li.userlogin-icon-parent-mobile{display:block;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu{width:calc(100% - 55px);margin:0 auto;overflow:hidden;}
#block-itg-layout-manager-header-block .main-nav .desktop-hide{width:35px;height:20px;position:relative;float:left;padding-left:10px;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu .nav-centerall{margin:0 auto;width:390px;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{width:125px;margin-left:0;}
#block-itg-layout-manager-header-block .navigation{width:85%;border-right:1px solid #ccc;background:#f9f9f9;box-shadow:0 3px 3px #ccc;height:calc(76vh - 70px);position:absolute;z-index:9999990;overflow-x:hidden;}
#block-itg-layout-manager-header-block .navigation .container{height:100%;overflow-x:hidden;overflow-y:scroll;}
#block-itg-layout-manager-header-block .navigation .second-level-menu.menu li{border-top:1px solid #ccc;}
#block-itg-layout-manager-header-block .navigation .second-level-menu.menu li a{border-top:0;color:#666;font-size:14px;font-weight:300;height:37px;line-height:37px;}
#block-itg-layout-manager-header-block .navigation .container{padding:0;}
#block-itg-layout-manager-header-block .navigation .container .user-menus .fa.fa-user{background:red;border-radius:100%;padding:5px 0;color:#fff;width:25px;height:25px;text-align:center;margin-right:6px;}
#block-itg-layout-manager-header-block .navigation .container .user-menus{padding-top:5px;}
#block-itg-layout-manager-header-block .navigation .menu li.search-icon-parent-mobile a{float:left;text-align:center;padding:0;width:20px;}
.mobile-nav .bar1,.mobile-nav .bar2,.mobile-nav .bar3{width:20px;height:2px;background-color:#5e5e5e;margin:4px 0;transition:.4s;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo+.menu li.menu__item.is-leaf a{padding-left:8px;}
}
@media only screen and (max-width:767px){
#block-itg-layout-manager-header-block .navigation{width:85%;border-right:1px solid #ccc;background:#f9f9f9;box-shadow:0 3px 3px #ccc;height:calc(100vh - 60px);}
}
@media only screen and (max-width:420px){
#block-itg-layout-manager-header-block{padding-top:10px;background:#fff;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{font-size:13px;font-weight:400;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{width:65px;padding:0 5px;margin-left:0;}
#block-itg-layout-manager-header-block .main-nav .nav-container-menu .nav-centerall{margin:0 auto;width:295px;}
#block-itg-layout-manager-header-block .logo{width:55px;position:absolute;top:15px;}
}
@media only screen and (max-width:320px){
#block-itg-layout-manager-header-block .main-nav .nav-container-menu .nav-centerall{width:300px;}
#block-itg-layout-manager-header-block .top-nav .main-nav li a{padding:0 5px;}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo{width:50px;height:35px;}
#block-itg-layout-manager-header-block .logo{width:45px;}
}
@media (min-width:768px) and (max-width:1024px) and (orientation:landscape){
#block-itg-layout-manager-header-block .navigation{display:block!important;}
}
.morediv{text-align:right;text-transform:uppercase;font-size:11px;color:#111;font-weight:700;color:#5794e0;font-family:OpenSans-Bold;}
.morediv a{color:#5794e0;font-weight:700;position:relative;display:block;}
.front .itg-top-section .home-top-story .data-holder .itg-listing li.itg-top-story-ad:before{display:none;}
.front .itg-top-section .home-top-story .data-holder .itg-listing li.itg-top-story-ad{padding:0 10px;}
.front .itg-top-section .top-rhs-add .home-trending-video{margin-top:30px;}
.front .itg-top-section .top-rhs-add-child .ad-widget{padding:4px 15px;height:283px;}
.front .itg-top-section .top-rhs-add-child .ad-widget .sidebar-ad{background:#fff;margin:0;}
.front .itg-top-section .home-top-story .data-holder .itg-listing li{padding:10px;}
.front .itg-top-section .home-top-story .itg-sponsor-title{left:0;padding:0;position:relative;display:block;font-weight:700;letter-spacing:1px;}
.front #block-itg-widget-home-page-feature .featured-news .featured-post h2 a,.front #block-itg-widget-home-page-feature .featured-news .featured-post h3 a{display:inline;}
.front .itg-top-section .home-top-story .droppable{height:620px;}
@media only screen and (max-width:1024px){
.itg-layout-container .itg-h321-section .droppable{height:300px;}
#block-itg-layout-manager-header-block .menu-login{right:15px;}
}
@media screen and (min-width:991px) and (max-width:1024px){
.front .itg-top-section .top-rhs-add{margin-top:40px;}
.front .itg-top-section .top-rhs-add .home-trending-video{margin-top:0;}
.front .itg-top-section .home-top-story .droppable{height:620px;}
.front .itg-top-section .top-rhs-add-child .ad-widget{width:333px;margin:0 auto;}
#block-itg-front-end-common-latest-from-aajtak ul,#block-itg-front-end-common-latest-from-pti ul,#block-itg-front-end-common-latest-from-businesstoday ul{overflow-y:auto;max-height:350px;}
.front .mt-50{margin-top:20px;}
}
@media screen and (min-width:768px) and (max-width:991px){
.front .itg-top-section .home-top-story .droppable{height:515px;}
.front .itg-top-section .top-rhs-add{margin-top:40px;}
.front .itg-top-section .top-rhs-add .home-trending-video{margin-top:0;}
#block-itg-front-end-common-latest-from-aajtak ul,#block-itg-front-end-common-latest-from-pti ul,#block-itg-front-end-common-latest-from-businesstoday ul{overflow-y:auto;max-height:350px;}
.front .mt-50{margin-top:20px;}
.itg-layout-container .itg-h321-section .droppable{height:auto;}
}
.ad-widget .sidebar-ad .block-itg-ads{width:300px;margin:0 auto 0;}
body.front #block-itg-layout-manager-header-block .top-nav .main-nav li a.active{color:#a9a9a9;}
.front .watch-right-now-video ul li{padding:13px 0;}
.front .top-takes-video-container ul .top-takes-video .title{font-family:"OpenSans-Semibold";}
#block-itg-front-end-common-latest-from-aajtak ul .third-party-list .title{font-weight:600;letter-spacing:.8px;}
@media screen and (max-width:767px){
.front .widget-wrapper.top_stories_ordering{border:0;}
.front .itg-top-section .home-top-story .data-holder .itg-listing li{padding:15px 10px 10px 25px;}
.front .itg-listing li:before{display:block;}
.featured-news .featured-post a{font-weight:700;}
.front .itg-top-section .top-rhs-add-child .ad-widget{padding:0;margin-top:20px;}
footer .footer-top .footer-social-link{display:none;opacity:0;}
.front .itg-top-section .home-top-story .droppable{height:auto;}
.itg-layout-container .itg-h321-section .droppable{height:auto;}
}
@media screen and (max-width:767px){
.top-n-most-popular-stories{margin-top:15px;}
.top_stories_ordering .widget-title{padding:5px 7px 1px 0;}
}
#block-itg-widget-home-page-feature .featured-news .featured-post a{display:inline;}
.front #block-itg-widget-home-page-feature .featured-news .featured-post a{display:block;overflow:hidden;}
.front-title-hide{display:none;}
@media only screen and (max-width:768px){
.front .itg-top-section .top-rhs-add-child .ad-widget{padding:10px 10px;height:290px;}
.front .itg-layout-container .itg-h321-section .ad-widget{height:315px;padding:30px 0;width:322px;margin:0 auto;background:#f3f3f3;}
.front .itg-layout-container .itg-h321-section .ad-widget .sidebar-ad{background:#f3f3f3;height:100%;}
.itg-h321-section .dont-miss ul li{width:100%;}
.itg-h321-section .dont-miss ul li:nth-child(4),.itg-h450-section .watch-right-now-video ul li:nth-child(4),.itg-h450-section .watch-right-now-video ul li:nth-child(5){display:none;}
}
@media only screen and (max-width:767px){
#block-itg-layout-manager-header-block{position:fixed;width:100%;top:0;z-index:99995;}
header#header{padding-top:65px;}
}
#block-itg-ads-ads-page-pusher-1x1{position:relative;overflow:hidden;}
.live-webcast-coverage iframe{width:100%;}
@media only screen and (max-width:767px){
.front .itg-top-section .top-rhs-add-child .ad-widget{padding:0;height:auto;background:#f3f3f3;}
.front .itg-layout-container .itg-h321-section .ad-widget{height:auto;padding:0;width:300px;margin:0 auto;background:#f3f3f3;}
.front .itg-layout-container .itg-h321-section .ad-widget .sidebar-ad{background:#f3f3f3;height:100%;}
.itg-h321-section .dont-miss ul li:nth-child(4),.itg-h450-section .watch-right-now-video ul li:nth-child(4),.itg-h450-section .watch-right-now-video ul li:nth-child(5){display:block;}
.front .trending-videos .trending-videos-list:nth-child(5){display:block;}
.front .mt-50{margin-top:20px;}
.front .itg-top-section .top-rhs-add .home-trending-video{padding:0;}
}
.front .itg-layout-container .itg-h321-section .droppable{height:280px;}
.front .trending-videos .trending-videos-list{overflow:hidden;padding:14px 10px;}
.front .itg-layout-container .ad-widget{border:1px solid #ddd;height:280px;padding:4px 37px;}
footer .footer-top .footer-top-link{font-size:22px;color:#fff;overflow:hidden;line-height:35px;float:left;}
@media only screen and (max-width:1024px){
.front .itg-layout-container .itg-h321-section .droppable{height:280px;}
.front .itg-layout-container .ad-widget{padding:4px 10px;}
.itg-h450-section .watch-right-now-video ul li:nth-child(5){display:none;}
}
@media only screen and (max-width:768px){
.front .itg-layout-container .itg-h321-section .droppable{height:auto;}
.front .itg-layout-container .itg-h321-section .ad-widget{height:300px;padding:24px 0;width:322px;margin:0 auto;background:#f3f3f3;}
footer .footer-top .footer-top-link{font-size:19px;line-height:44px;}
}
@media only screen and (max-width:767px){
.front .itg-layout-container .itg-h321-section .ad-widget{height:282px;padding:4px 0 10px;}
#block-itg-ads-ads-super-banner-top-nav-728x90{background:#f2f2f2;padding-bottom:10px;border:1px solid #e2e2e2;min-height:280px;}
.front .itg-top-section .top-rhs-add-child .ad-widget .sidebar-ad{padding-bottom:10px;}
}
@media only screen and (max-width:320px){
.itg-layout-container .ad-widget{width:300px;padding:0;height:250px;border:0;}
.front .itg-top-section .top-rhs-add-child .ad-widget{margin:15px -30px 0;width:320px;padding:4px 10px;}
.front .itg-layout-container .itg-h321-section .ad-widget{margin:0 -17px;}
}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li.livetv-icon-parent a svg{position:relative;top:3px;}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li.livetv-icon-parent a:hover svg #hovesvg{fill:#ffc106;}
@media only screen and (max-width:767px){
.featured-news .featured-post.featured-post-first{margin-bottom:0;}
}


</style>
<?php } ?>
<?php if($front_page) : 
$js_path = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/js/lazysizes.min.js'); 
$jquery_js_path = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/js/1.9/jquery.min.js'); 
?>
<script type="text/javascript" src="<?php print $jquery_js_path; ?>"></script>
<script type="text/javascript" async src="<?php print $js_path; ?>"></script>
<?php endif; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <p id="skip-link">
      <a href="#<?php print $skip_link_anchor; ?>" class="element-invisible element-focusable"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php 
	if($front_page || $type == 'story'){
	  print $scripts;
	}
	if ($front_page) {
	 $ipl_triangle_status = itg_ipl_triangle_status();
	 if($ipl_triangle_status['score_triangle'] == 1){
	   echo $ipl_triangle_status['score_code_cube_app'];
	 }
	}
  
  if (!empty(FRONT_URL) && $base_url == FRONT_URL && $arg[0] != 'video' && $arg[2] != 'embed' && (!drupal_is_front_page()) && get_itg_variable('itg_election_home_chunk')) {
    $ipl_triangle_status = itg_ipl_triangle_status();
    if ($ipl_triangle_status['score_triangle'] == 1) {
      echo $ipl_triangle_status['score_code_cube_app'];
    }   
	}
  ?>
  <?php print $page_bottom; ?>
  <!-- Branch IO code end -->
<!-- Scorecard taboola js -->
<?php if($arg[0] == 'scorecard' && $arg[1] == 'matchcenter'){ ?>
    <script type="text/javascript">
        window._taboola = window._taboola || [];
        _taboola.push({flush: true});
    </script>
<?php } ?>
<!-- End Scorecard taboola js --> 
<?php 
	if($front_page || $type == 'story'){
	  print $styles;
	}
?>
<!--
<script type="text/javascript">"serviceWorker" in navigator && window.addEventListener("load", function() {navigator.serviceWorker.register("/service-worker.js").then(function(e) { console.log("Service worker registered."), e.onupdatefound = function() {var n = e.installing; n.onstatechange = function() { switch (n.state) {case "installed": navigator.serviceWorker.controller ? (console.log("New or updated content is available."), window.location.reload()) : console.log("Content is now available offline!"); break; case "redundant": console.error("The installing service worker became redundant.") } } } }).catch(function(e) {console.error("Error during service worker registration:", e) }) }); console.log("%cStop!","font-size:48px; font-weight: bold; color: red;");console.log("\n%cThe JavaScript console is intended for developers. If someone told you to copy-paste something here to enable special features, it is a scam and will expose your personal information.","font-size:24px;");</script><script type="text/javascript">function loadScript(e, t) {if (navigator.onLine) {var n = document.createElement("script"); n.type = "text/javascript", n.async = !0, n.readyState ? n.onreadystatechange = function() {"loaded" != n.readyState && "complete" != n.readyState || (n.onreadystatechange = null, t && "function" == typeof t && t()) } : n.onload = function() {t && "function" == typeof t && t() }, n.src = e, (document.getElementsByTagName("head")[0] || document.getElementsByTagName("body")[0]).appendChild(n) } else {var a = new Request(e); caches.match(a).then(function(n) {if (n) {var a = document.createElement("script"); a.type = "text/javascript", a.async = !0, a.readyState ? a.onreadystatechange = function() {"loaded" != a.readyState && "complete" != a.readyState || (a.onreadystatechange = null, t && "function" == typeof t && t()) } : a.onload = function() {t && "function" == typeof t && t() }, a.src = e, (document.getElementsByTagName("head")[0] || document.getElementsByTagName("body")[0]).appendChild(a) } }) } } </script>
<script type="text/javascript" src="https://akm-img-a-in.tosshub.com/sites/common/js/gdpr/gdpr_check.js" data-name="cookies-policy" data-id="gdprconsentpolicy"></script>
-->
<style type="text/css">#block-itg-layout-manager-header-block .navigation{overflow:visible;}</style>
</body>
</html> 
