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
  $node_data = menu_get_object();
  $arg = arg();
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
      $nid = isset($menu_item['page_arguments'][0]->nid) ? $menu_item['page_arguments'][0]->nid : "";
      $type = isset($menu_item['page_arguments'][0]->type) ? $menu_item['page_arguments'][0]->type : "";
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
<script type="text/javascript" src="/sites/all/modules/contrib/jquery_update/replace/jquery/1.7/jquery.min.js"></script>
<script type="text/javascript" async="async" src="https://vuukle.com/js/vuukle.js"></script>
<?php if ($nid && $type == 'videogallery') : ?>
<script type="text/javascript" src="/sites/all/modules/custom/itg_videogallery/js/jwplayer.min.js"></script>
<?php endif; ?>
<style>
/* Inline CSS bootstrap */
.container{padding-right:15px;padding-left:15px;margin-right:auto;margin-left:auto}@media (min-width: 769px){.container{max-width:750px}}@media (min-width: 992px){.container{max-width:970px}}@media (min-width: 1200px){.container{max-width:1200px}}.row{margin-right:-15px;margin-left:-15px}.col-xs-1,.col-sm-1,.col-md-1,.col-lg-1,.col-xs-2,.col-sm-2,.col-md-2,.col-lg-2,.col-xs-3,.col-sm-3,.col-md-3,.col-lg-3,.col-xs-4,.col-sm-4,.col-md-4,.col-lg-4,.col-xs-5,.col-sm-5,.col-md-5,.col-lg-5,.col-xs-6,.col-sm-6,.col-md-6,.col-lg-6,.col-xs-7,.col-sm-7,.col-md-7,.col-lg-7,.col-xs-8,.col-sm-8,.col-md-8,.col-lg-8,.col-xs-9,.col-sm-9,.col-md-9,.col-lg-9,.col-xs-10,.col-sm-10,.col-md-10,.col-lg-10,.col-xs-11,.col-sm-11,.col-md-11,.col-lg-11,.col-xs-12,.col-sm-12,.col-md-12,.col-lg-12{position:relative;min-height:1px;padding-right:15px;padding-left:15px}.col-xs-1,.col-xs-2,.col-xs-3,.col-xs-4,.col-xs-5,.col-xs-6,.col-xs-7,.col-xs-8,.col-xs-9,.col-xs-10,.col-xs-11,.col-xs-12{float:left}.col-xs-12{width:100%}.col-xs-11{width:91.66666667%}.col-xs-10{width:83.33333333%}.col-xs-9{width:75%}.col-xs-8{width:66.66666667%}.col-xs-7{width:58.33333333%}.col-xs-6{width:50%}.col-xs-5{width:41.66666667%}.col-xs-4{width:33.33333333%}.col-xs-3{width:25%}.col-xs-2{width:16.66666667%}.col-xs-1{width:8.33333333%}.col-xs-pull-12{right:100%}.col-xs-pull-11{right:91.66666667%}.col-xs-pull-10{right:83.33333333%}.col-xs-pull-9{right:75%}.col-xs-pull-8{right:66.66666667%}.col-xs-pull-7{right:58.33333333%}.col-xs-pull-6{right:50%}.col-xs-pull-5{right:41.66666667%}.col-xs-pull-4{right:33.33333333%}.col-xs-pull-3{right:25%}.col-xs-pull-2{right:16.66666667%}.col-xs-pull-1{right:8.33333333%}.col-xs-pull-0{right:auto}.col-xs-push-12{left:100%}.col-xs-push-11{left:91.66666667%}.col-xs-push-10{left:83.33333333%}.col-xs-push-9{left:75%}.col-xs-push-8{left:66.66666667%}.col-xs-push-7{left:58.33333333%}.col-xs-push-6{left:50%}.col-xs-push-5{left:41.66666667%}.col-xs-push-4{left:33.33333333%}.col-xs-push-3{left:25%}.col-xs-push-2{left:16.66666667%}.col-xs-push-1{left:8.33333333%}.col-xs-push-0{left:auto}.col-xs-offset-12{margin-left:100%}.col-xs-offset-11{margin-left:91.66666667%}.col-xs-offset-10{margin-left:83.33333333%}.col-xs-offset-9{margin-left:75%}.col-xs-offset-8{margin-left:66.66666667%}.col-xs-offset-7{margin-left:58.33333333%}.col-xs-offset-6{margin-left:50%}.col-xs-offset-5{margin-left:41.66666667%}.col-xs-offset-4{margin-left:33.33333333%}.col-xs-offset-3{margin-left:25%}.col-xs-offset-2{margin-left:16.66666667%}.col-xs-offset-1{margin-left:8.33333333%}.col-xs-offset-0{margin-left:0}@media (min-width: 768px){.col-sm-1,.col-sm-2,.col-sm-3,.col-sm-4,.col-sm-5,.col-sm-6,.col-sm-7,.col-sm-8,.col-sm-9,.col-sm-10,.col-sm-11,.col-sm-12{float:left}.col-sm-12{width:100%}.col-sm-11{width:91.66666667%}.col-sm-10{width:83.33333333%}.col-sm-9{width:75%}.col-sm-8{width:66.66666667%}.col-sm-7{width:58.33333333%}.col-sm-6{width:50%}.col-sm-5{width:41.66666667%}.col-sm-4{width:33.33333333%}.col-sm-3{width:25%}.col-sm-2{width:16.66666667%}.col-sm-1{width:8.33333333%}.col-sm-pull-12{right:100%}.col-sm-pull-11{right:91.66666667%}.col-sm-pull-10{right:83.33333333%}.col-sm-pull-9{right:75%}.col-sm-pull-8{right:66.66666667%}.col-sm-pull-7{right:58.33333333%}.col-sm-pull-6{right:50%}.col-sm-pull-5{right:41.66666667%}.col-sm-pull-4{right:33.33333333%}.col-sm-pull-3{right:25%}.col-sm-pull-2{right:16.66666667%}.col-sm-pull-1{right:8.33333333%}.col-sm-pull-0{right:auto}.col-sm-push-12{left:100%}.col-sm-push-11{left:91.66666667%}.col-sm-push-10{left:83.33333333%}.col-sm-push-9{left:75%}.col-sm-push-8{left:66.66666667%}.col-sm-push-7{left:58.33333333%}.col-sm-push-6{left:50%}.col-sm-push-5{left:41.66666667%}.col-sm-push-4{left:33.33333333%}.col-sm-push-3{left:25%}.col-sm-push-2{left:16.66666667%}.col-sm-push-1{left:8.33333333%}.col-sm-push-0{left:auto}.col-sm-offset-12{margin-left:100%}.col-sm-offset-11{margin-left:91.66666667%}.col-sm-offset-10{margin-left:83.33333333%}.col-sm-offset-9{margin-left:75%}.col-sm-offset-8{margin-left:66.66666667%}.col-sm-offset-7{margin-left:58.33333333%}.col-sm-offset-6{margin-left:50%}.col-sm-offset-5{margin-left:41.66666667%}.col-sm-offset-4{margin-left:33.33333333%}.col-sm-offset-3{margin-left:25%}.col-sm-offset-2{margin-left:16.66666667%}.col-sm-offset-1{margin-left:8.33333333%}.col-sm-offset-0{margin-left:0}}@media (min-width: 992px){.col-md-1,.col-md-2,.col-md-3,.col-md-4,.col-md-5,.col-md-6,.col-md-7,.col-md-8,.col-md-9,.col-md-10,.col-md-11,.col-md-12{float:left}.col-md-12{width:100%}.col-md-11{width:91.66666667%}.col-md-10{width:83.33333333%}.col-md-9{width:75%}.col-md-8{width:66.66666667%}.col-md-7{width:58.33333333%}.col-md-6{width:50%}.col-md-5{width:41.66666667%}.col-md-4{width:33.33333333%}.col-md-3{width:25%}.col-md-2{width:16.66666667%}.col-md-1{width:8.33333333%}.col-md-pull-12{right:100%}.col-md-pull-11{right:91.66666667%}.col-md-pull-10{right:83.33333333%}.col-md-pull-9{right:75%}.col-md-pull-8{right:66.66666667%}.col-md-pull-7{right:58.33333333%}.col-md-pull-6{right:50%}.col-md-pull-5{right:41.66666667%}.col-md-pull-4{right:33.33333333%}.col-md-pull-3{right:25%}.col-md-pull-2{right:16.66666667%}.col-md-pull-1{right:8.33333333%}.col-md-pull-0{right:auto}.col-md-push-12{left:100%}.col-md-push-11{left:91.66666667%}.col-md-push-10{left:83.33333333%}.col-md-push-9{left:75%}.col-md-push-8{left:66.66666667%}.col-md-push-7{left:58.33333333%}.col-md-push-6{left:50%}.col-md-push-5{left:41.66666667%}.col-md-push-4{left:33.33333333%}.col-md-push-3{left:25%}.col-md-push-2{left:16.66666667%}.col-md-push-1{left:8.33333333%}.col-md-push-0{left:auto}.col-md-offset-12{margin-left:100%}.col-md-offset-11{margin-left:91.66666667%}.col-md-offset-10{margin-left:83.33333333%}.col-md-offset-9{margin-left:75%}.col-md-offset-8{margin-left:66.66666667%}.col-md-offset-7{margin-left:58.33333333%}.col-md-offset-6{margin-left:50%}.col-md-offset-5{margin-left:41.66666667%}.col-md-offset-4{margin-left:33.33333333%}.col-md-offset-3{margin-left:25%}.col-md-offset-2{margin-left:16.66666667%}.col-md-offset-1{margin-left:8.33333333%}.col-md-offset-0{margin-left:0}}@media (min-width: 1200px){.col-lg-1,.col-lg-2,.col-lg-3,.col-lg-4,.col-lg-5,.col-lg-6,.col-lg-7,.col-lg-8,.col-lg-9,.col-lg-10,.col-lg-11,.col-lg-12{float:left}.col-lg-12{width:100%}.col-lg-11{width:91.66666667%}.col-lg-10{width:83.33333333%}.col-lg-9{width:75%}.col-lg-8{width:66.66666667%}.col-lg-7{width:58.33333333%}.col-lg-6{width:50%}.col-lg-5{width:41.66666667%}.col-lg-4{width:33.33333333%}.col-lg-3{width:25%}.col-lg-2{width:16.66666667%}.col-lg-1{width:8.33333333%}.col-lg-pull-12{right:100%}.col-lg-pull-11{right:91.66666667%}.col-lg-pull-10{right:83.33333333%}.col-lg-pull-9{right:75%}.col-lg-pull-8{right:66.66666667%}.col-lg-pull-7{right:58.33333333%}.col-lg-pull-6{right:50%}.col-lg-pull-5{right:41.66666667%}.col-lg-pull-4{right:33.33333333%}.col-lg-pull-3{right:25%}.col-lg-pull-2{right:16.66666667%}.col-lg-pull-1{right:8.33333333%}.col-lg-pull-0{right:auto}.col-lg-push-12{left:100%}.col-lg-push-11{left:91.66666667%}.col-lg-push-10{left:83.33333333%}.col-lg-push-9{left:75%}.col-lg-push-8{left:66.66666667%}.col-lg-push-7{left:58.33333333%}.col-lg-push-6{left:50%}.col-lg-push-5{left:41.66666667%}.col-lg-push-4{left:33.33333333%}.col-lg-push-3{left:25%}.col-lg-push-2{left:16.66666667%}.col-lg-push-1{left:8.33333333%}.col-lg-push-0{left:auto}.col-lg-offset-12{margin-left:100%}.col-lg-offset-11{margin-left:91.66666667%}.col-lg-offset-10{margin-left:83.33333333%}.col-lg-offset-9{margin-left:75%}.col-lg-offset-8{margin-left:66.66666667%}.col-lg-offset-7{margin-left:58.33333333%}.col-lg-offset-6{margin-left:50%}.col-lg-offset-5{margin-left:41.66666667%}.col-lg-offset-4{margin-left:33.33333333%}.col-lg-offset-3{margin-left:25%}.col-lg-offset-2{margin-left:16.66666667%}.col-lg-offset-1{margin-left:8.33333333%}.col-lg-offset-0{margin-left:0}}
  /* end bootstrap */
  h1,h2,h3,h4 {font-weight: 500; font-family: "OpenSans-Regular";word-wrap: break-word; }
button {outline: none; }
h1 {font-family: Merriweather-Bold;font-size: 40px;line-height: 46px;font-weight: 700; }
h2 {font-family: "Merriweather-Bold";font-size: 29px;line-height: 34px;font-weight: 700; }
h3 {font-family: "OpenSans-Semibold";font-size: 20px;line-height: 24px; }
h4 {font-size: 16px;line-height: 18px; }
h4.heading {color: #09619f;font-weight: 700;font-family: "OpenSans-Regular";text-transform: uppercase;margin-bottom: 15px;border-bottom: 1px solid #ddd;padding-bottom: 10px;font-size: 16px; }
  h4.heading a {color: #09619f; }
.clearfix {
  clear: both; }
a {color: #111;text-decoration: none;}
button,input[type='submit'] {cursor: pointer;}
a:focus,button:focus {outline: 0 none;}
img {vertical-align: top;max-width: 100%;height: auto;}
.list-none, #block-itg-layout-manager-header-block ul, footer ul, .big-news ul, .trending-videos, .view-front-end-global-search .view-content ul, .dont-miss ul, #block-itg-widget-yearende-left-top-news .top-news ul, #block-itg-widget-yearende-left-top-videos .top-video ul, .osscar-video ul, .story-section ul, .may-be-suggest-container ul, .top-takes-video-container ul, .watch-right-now-video ul, .page-snap-post ul, #block-views-anchor-landing-page-block .anchor-right .social-icon ul, .live-block ul, .poll-wrapper ul, .poll-navigation ul, .poll-banner ul, #block-views-video-landing-header-block ul, #block-views-video-landing-header-block-1 ul, .rhs-section-ordering ul, #breadcrumbs ul, .view-archive-story .view-content ul, .program-rhs ul, #block-itg-msi-magazine-calendar ul, #block-views-latest-issue-magzine-block-1 ul, .magazin-lhs-top .magazin-top ul, .magazin-lhs-top .magazin-bottom ul, #block-itg-layout-manager-header-sosorry-block .sosory-footer ul, .sosorry-social ul, .recommended-for-you ul, .tech-layout-page .buying-guides ul, #block-itg-event-backend-program-tab-block ul, #block-views-event-photo-slider-block ul, #block-views-event-associate-video-block ul, #block-views-event-subsite-speaker-block ul, #block-views-past-speaker-event-block ul, #block-views-program-schedule-block-1 ul, #block-menu-menu-event-menu ul, .education-layout-page .how-made-it ul, .sport-home-layout-page .sports-video ul, .movie-layout-page ul, #block-itg-menu-manager-third-level-menu ul, .election-page .key-candidate ul, #block-itg-live-tv-live-tv-video-page ul, #block-menu-menu-about-us-page-menu ul, #block-itg-front-end-common-related-photo-block #related-photo ul, #block-itg-front-end-common-related-photo-block #related-video ul, #block-itg-front-end-common-related-video-block #related-photo ul, #block-itg-front-end-common-related-video-block #related-video ul, .site-map ul, #block-itg-front-end-common-latest-from-aajtak ul, #block-itg-front-end-common-latest-from-pti ul, #block-itg-front-end-common-latest-from-businesstoday ul, .page-state-election .key-candidate ul {list-style-type: none;}
.front-title-hide {display: none;}
.mhide {display: block;}
.desktop-hide {display: none;}
.element-hidden {display: none;}
.element-invisible {position: absolute !important;clip: rect(1px 1px 1px 1px);clip: rect(1px, 1px, 1px, 1px);overflow: hidden;height: 1px;}
.ripple-effect {position: relative;overflow: hidden;}
.widget-title {display: inline-block;vertical-align: top;position: static !important; background: transparent;color: #000;font-size: 16px; padding: 0;    font-weight: 600;
    margin-bottom: 5px; height: auto; font-family: "OpenSans-Bold";}
.widget-title a { color: #111;}
.front .itg-layout-container .ad-widget {border: 1px solid #ddd;height: 280px; padding: 4px 37px;}
.front .itg-top-section .top-rhs-add-child .ad-widget {padding: 4px 15px;height: 283px;}
.itg-listing li { padding: 10px; position: relative;border-bottom: 1px solid #e4e4e4;font-family: "OpenSans-Semibold";}
.itg-listing li a {color: #111;display: inline;border-bottom: none;padding: 0;line-height: 20px;}
/*start header css*/
header {
  margin-bottom: 10px;
  position: relative;
  z-index: 9999; }
#cboxClose {
  background: url(../images/controls.png) no-repeat -25px 0px; }

#block-itg-layout-manager-header-block {
  padding-top: 20px;
  background: #fff;
  position: relative; }
  #block-itg-layout-manager-header-block .header-top {
    height: 163px; }
  #block-itg-layout-manager-header-block a {
    color: #a9a9a9;
    font-family: "OpenSans-Semibold"; }
  #block-itg-layout-manager-header-block .header-logo {
    position: relative; }
  #block-itg-layout-manager-header-block .header-ads {
    text-align: center;
    padding-top: 10px; }
    #block-itg-layout-manager-header-block .header-ads .row {
      margin: 0 auto;
      display: inline-block;
      vertical-align: top; }
  #block-itg-layout-manager-header-block .login-link {
    text-align: right; }
    #block-itg-layout-manager-header-block .login-link a {
      font-weight: 400;
      margin-right: 10px; }
  #block-itg-layout-manager-header-block .logo {
    width: auto;
    top: 15px;
    position: absolute; }
    #block-itg-layout-manager-header-block .logo a {
      display: block;
      overflow: visible; }
    #block-itg-layout-manager-header-block .logo img {
      padding-left: 4px;
      padding-right: 0px;
      vertical-align: top;
      margin-bottom: -2px; }
  #block-itg-layout-manager-header-block .social-nav {
    position: relative;
    float: right; }
    #block-itg-layout-manager-header-block .social-nav a .fa {
      font-size: 23px;
      font-size: 1.4375rem; }
      #block-itg-layout-manager-header-block .social-nav a .fa.fa-mobile {
        font-size: 27px;
        font-size: 1.6875rem; }
    #block-itg-layout-manager-header-block .social-nav .globle-search {
      position: absolute;
      top: -5px;
      right: 40px;
      -webkit-transition: all 0.5s ease-in-out;
      -moz-transition: all 0.5s ease-in-out;
      -ms-transition: all 0.5s ease-in-out;
      -o-transition: all 0.5s ease-in-out;
      transition: all 0.5s ease-in-out;
      width: 0px;
      overflow: hidden; }
      #block-itg-layout-manager-header-block .social-nav .globle-search .search-text {
        width: 100%; }
      #block-itg-layout-manager-header-block .social-nav .globle-search.active {
        width: 225px; }
  #block-itg-layout-manager-header-block .top-nav {
    padding: 0 15px 0 15px;
    margin: 25px auto 5px auto;
    float: none;
    zoom: 1;
    background: transparent; }
    #block-itg-layout-manager-header-block .top-nav:before, #block-itg-layout-manager-header-block .top-nav:after {
      content: "";
      display: block;
      height: 0;
      overflow: hidden; }
    #block-itg-layout-manager-header-block .top-nav:after {
      clear: both; }
    #block-itg-layout-manager-header-block .top-nav ul li a {
      font-weight: 500; }
    #block-itg-layout-manager-header-block .top-nav .main-nav {
      padding-left: 0px;
      line-height: 28px;
      width: 65%;
      margin: 0 auto; }
      #block-itg-layout-manager-header-block .top-nav .main-nav ul.menu {
    float: left;
}
      #block-itg-layout-manager-header-block .top-nav .main-nav li.desktop-hide {
        display: none; }
      #block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) {
        position: relative; }
        #block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before {
          content: '';
          background: url(../images/sprite.png) no-repeat 0 -123px;
          position: absolute;
          top: -11px;
          left: 20px;
          width: 28px;
          height: 19px; }
      #block-itg-layout-manager-header-block .top-nav .main-nav li a {
        padding: 0 35px;
        font-size: 27px;
        font-size: 1.6875rem;
        text-transform: uppercase; }
        #block-itg-layout-manager-header-block .top-nav .main-nav li a.active, #block-itg-layout-manager-header-block .top-nav .main-nav li a:hover {
          color: #ffc106; }
      #block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(2) a {
        padding-left: 0; }
  #block-itg-layout-manager-header-block .navigation {
    zoom: 1;
    margin-top: 0px;
    overflow: visible;
    background: #a00606;
    box-shadow: 0 6px 5px -3px rgba(0, 0, 0, 0.1); height:37px; overflow:hidden;}
    #block-itg-layout-manager-header-block .navigation:before, #block-itg-layout-manager-header-block .navigation:after {
      content: "";
      display: block;
      height: 0;
      overflow: hidden; }
    #block-itg-layout-manager-header-block .navigation:after {
      clear: both; }
    #block-itg-layout-manager-header-block .navigation .container {
      position: relative; }
    #block-itg-layout-manager-header-block .navigation .menu {
      margin-left: 0px;
      margin-right: 50px;
      max-width: 985px; }
      #block-itg-layout-manager-header-block .navigation .menu li {
        float: left; }
        #block-itg-layout-manager-header-block .navigation .menu li a {
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
          line-height: 37px; }
          #block-itg-layout-manager-header-block .navigation .menu li a.sponsored-active {
            background: #ffc106;
            color: #000 !important; }
            #block-itg-layout-manager-header-block .navigation .menu li a.sponsored-active:hover {
              color: #000; }
          #block-itg-layout-manager-header-block .navigation .menu li a.active, #block-itg-layout-manager-header-block .navigation .menu li a:hover {
            color: #ffc106; }
          #block-itg-layout-manager-header-block .navigation .menu li a:after {
            position: absolute;
            content: '';
            height: 100%;
            background: #680101;
            width: 1px;
            right: 0;
            top: 0; }
        #block-itg-layout-manager-header-block .navigation .menu li.has-image a img {
          max-height: 37px;
          width: auto;
          padding: 4px 0; }
      #block-itg-layout-manager-header-block .navigation .menu#newlist li a:after {
        display: none; }
    #block-itg-layout-manager-header-block .navigation ul li.sponser-link a {
      background: #ffc106;
      color: #323232; }
      #block-itg-layout-manager-header-block .navigation ul li.sponser-link a:hover {
        color: #323232; }
    #block-itg-layout-manager-header-block .navigation .all-menu {
      width: 46px;
      cursor: pointer; }
      #block-itg-layout-manager-header-block .navigation .all-menu i {
        font-size: 7px;
        color: #e0e0e0; }
    #block-itg-layout-manager-header-block .navigation ul#newlist {
      padding-left: 0;
      padding-right: 0;
      position: absolute;
      top: 37px;
      z-index: 99999;
      background: #a00606;
      display: none;
      margin-left: 0;
      margin-right: 0;
      right: 0 !important;
      width: 172px; }
      #block-itg-layout-manager-header-block .navigation ul#newlist li {
        float: none;
        border: none;
        border-bottom: 1px solid #000; }
        #block-itg-layout-manager-header-block .navigation ul#newlist li a {
          display: block;
          line-height: normal;
          height: auto;
          padding: 7px 10px;
          white-space: normal;
          word-wrap: break-word; }
#block-itg-layout-manager-header-block ul{ list-style:none; }
#block-itg-layout-manager-header-block .top-nav ul li{display: inline-block;}
body.front #block-itg-layout-manager-header-block .top-nav .main-nav li a.active {color: #a9a9a9;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(2) a {padding-left: 0;}
#block-itg-layout-manager-header-block .top-nav .main-nav li:nth-child(3) a:before {
    width: 8px;
    height: 8px;
    border-radius: 100%;
    background: #c00;
    display: inline-block;
    position: relative;
    top: -5px;
    left: -5px;
    box-shadow: 0 0 0 rgba(214, 2, 12, 0.8);
    border-radius: 50%;
    background: #c00;
    animation: pulse 1.7s infinite;
    content: "";
}
#block-itg-layout-manager-header-block .top-nav .main-nav .headeritg-logo {
    float: left;
    width: 185px;
    text-align: center;
    height: 40px;
}
#block-itg-layout-manager-header-block .logo {
    width: auto;
    top: 15px;
    position: absolute;
}
#block-itg-layout-manager-header-block .logo a {
    display: block;
    overflow: visible;
}
#block-itg-layout-manager-header-block .logo img {
    padding-left: 4px;
    padding-right: 0px;
    vertical-align: top;
    margin-bottom: -2px;
}
#block-itg-layout-manager-header-block .second-level-menu.menu:before, #block-itg-layout-manager-header-block .second-level-menu.menu:after {
    content: "";
    display: block;
    height: 0;
    overflow: hidden;
}
#block-itg-layout-manager-header-block .navigation .menu { margin-right: 0px;}
#block-itg-layout-manager-header-block .second-level-menu.menu {zoom: 1;}
#block-itg-layout-manager-header-block .menu-login {
    position: absolute;
    right: 0px;
    top: 0px;
}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li {
    display: inline-block;
}
#block-itg-layout-manager-header-block .social-nav .share-icon-parent {
    position: relative;
}
#block-itg-layout-manager-header-block .menu-login .social-nav ul li a {
    padding: 0 10px;
    line-height: 32px;
    color: #fff;
}
#block-itg-layout-manager-header-block .social-nav .social-dropdown {
    display: none;
    position: absolute;
    top: -5px;
    right: 40px;
    -webkit-transition: all 0.5s ease-in-out;
    -moz-transition: all 0.5s ease-in-out;
    -ms-transition: all 0.5s ease-in-out;
    -o-transition: all 0.5s ease-in-out;
    transition: all 0.5s ease-in-out;
    width: 0px;
    background: #f0f0f0;
    height: 37px;
}
/*End header css*/
/*Start CSS Top Story Home Page*/
.front .itg-top-section .top-rhs-add .home-trending-video {margin-top: 30px;}
.tab-buttons {
  zoom: 1;
  background: #e4e4e4;
  border-radius: 10px 10px 0 0; }
  .tab-buttons:before, .tab-buttons:after {
    content: "";
    display: block;
    height: 0;
    overflow: hidden; }
  .tab-buttons:after {
    clear: both; }
  .tab-buttons span {
    font-weight: 500;
    font-family: "OpenSans-Regular";
    background: #e4e4e4;
    text-transform: uppercase;
    height: 36px;
    line-height: 36px;
    text-align: center;
    border-radius: 10px 10px 0 0;
    border-top: 3px solid transparent;
    color: #818181;
    width: 50%;
    display: block;
    float: left;
    cursor: pointer;
    white-space: nowrap;
    overflow: hidden;
    text-overflow: ellipsis;
    padding: 0 5px; }
    .tab-buttons span.active {
      background: #fff;
      color: #a00606;
      border-left: 1px solid #e4e4e4;
      border-right: 1px solid #e4e4e4;
      border-top: 3px solid #a00606; }

.itg-listing {
  list-style: none;
  border: 1px solid #dddddd; }
  .itg-listing li {
    padding: 15px;
    position: relative;
    border-bottom: 1px solid #e4e4e4;
    font-family: "OpenSans-Semibold"; }
    .itg-listing li a {
      color: #111;
      padding: 15px 15px 15px 20px;
      display: block;
      border-bottom: 1px solid #e4e4e4;
      line-height: 20px; }
      .itg-listing li a:hover {
        background: #f8f8f8; }
      .itg-listing li a:first-letter {
        text-transform: capitalize; }
    .itg-listing li:last-child a {
      border-bottom: none; }
    .itg-listing li:before {
      position: absolute;
      top: 22px;
      left: 9px;
      content: '';
      border-radius: 50%;
      background: #959595;
      height: 5px;
      width: 5px; }
    .itg-listing li a {
      display: inline;
      border-bottom: none;
      padding: 0; }
    .itg-listing li:before {
      display: none; }
    .itg-listing li:hover {
      background: #f8f8f8; }
      /* End tab */
/* score card section */
#block-itg-widget-score-card-iframe-widget{ overflow: hidden; }
#itg-scorecard-container{background: #222834;padding: 0;height: 60px; overflow: hidden;}
#itg-scorecard-container .scorecard-stripcontent{padding: 0px;position: relative;height: 60px;}
#itg-scorecard-container .scorecard-stripcontent ul li{list-style: none; display: inline-block; border-left: 1px solid #4f4f4f; padding: 0 4px;}
#itg-scorecard-container .scorecard-stripcontent ul li:nth-child(1){border-left:0px;}
#itg-scorecard-container .scorecard-stripcontent ul li:nth-child(3){border-right:0px}
#itg-scorecard-container .scorecard-stripcontent ul{position: absolute;top:-1px;}
#itg-scorecard-container .scorecard-stripcontent ul li a{color: #fff; font-family: "OpenSans-Regular";font-weight:normal; font-size: 14px; }
#itg-scorecard-container .scorecard-stripcontent ul li:nth-child(1) a{white-space: nowrap;overflow: hidden;text-overflow: ellipsis;width: 242px;display: inline-block;line-height: 20px; position: relative;top: 4px;}
#itg-scorecard-container .scorecard-stripcontent ul{position: absolute;top: 50%;transform: translateY(-50%);}

</style>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <p id="skip-link">
      <a href="#<?php print $skip_link_anchor; ?>" class="element-invisible element-focusable"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>  
  <?php print $styles; ?>    
  <?php print $scripts; ?>
  <?php print $page_bottom; ?>
    <script>
      jQuery(document).ready(function () {
        jQuery(".tab-buttons span , .video_landing_menu a , .slick-arrow, .slick-slide, .pager a").on('click' , function() {
            comscoreBeacon();
        });
      });
    </script>
    <!-- Branch IO code -->
    <script type="text/javascript">
    (function(b,r,a,n,c,h,_,s,d,k){if(!b[n]||!b[n]._q){for(;s<_.length;)c(h,_[s++]);d=r.createElement(a);d.async=1;d.src="https://cdn.branch.io/branch-latest.min.js";k=r.getElementsByTagName(a)[0];k.parentNode.insertBefore(d,k);b[n]=h}})(window,document,"script","branch",function(b,r){b[r]=function(){b._q.push([r,arguments])}},{_q:[],_v:1},"addListener applyCode banner closeBanner creditHistory credits data deepview deepviewCta first getCode init link logout redeem referrals removeListener sendSMS setBranchViewData setIdentity track validateCode".split(" "), 0);branch.init('key_live_djuJxtD2ZARYUWRnZZp9WnegBtjqJrld',{'no_journeys':false} );
    var linkData = {
    data: {
        '$canonical_identifier': "<?php print $content_id; ?>",
        '$data_type': "<?php print $content_type; ?>",
    }
    };
    branch.setBranchViewData(linkData);
	</script>
  <!-- Branch IO code end -->
</body>
</html> 
