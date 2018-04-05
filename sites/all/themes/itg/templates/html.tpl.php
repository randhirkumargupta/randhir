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
  <?php print $styles; ?>    
  <?php print $scripts; ?>
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
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php if ($skip_link_text && $skip_link_anchor): ?>
    <p id="skip-link">
      <a href="#<?php print $skip_link_anchor; ?>" class="element-invisible element-focusable"><?php print $skip_link_text; ?></a>
    </p>
  <?php endif; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
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
    (function(b,r,a,n,c,h,_,s,d,k){if(!b[n]||!b[n]._q){for(;s<_.length;)c(h,_[s++]);d=r.createElement(a);d.async=1;d.src="https://cdn.branch.io/branch-latest.min.js";k=r.getElementsByTagName(a)[0];k.parentNode.insertBefore(d,k);b[n]=h}})(window,document,"script","branch",function(b,r){b[r]=function(){b._q.push([r,arguments])}},{_q:[],_v:1},"addListener applyCode banner closeBanner creditHistory credits data deepview deepviewCta first getCode init link logout redeem referrals removeListener sendSMS setBranchViewData setIdentity track validateCode".split(" "), 0);branch.init('key_live_cgwzd2EvhB7X2XUsBd2N6joitydwu3OS',{'no_journeys':false} );
    var linkData = {
    data: {
        '$canonical_identifier': "<?php print $content_id; ?>",
        '$data_type': "<?php print $content_type; ?>",
    }
    };
    branch.setBranchViewData(linkData);
	</script>
  <!-- Branch IO code end -->
<!-- Scorecard taboola js -->
<?php if($arg[0] == 'scorecard' && $arg[1] == 'matchcenter'){ ?>
    <script type="text/javascript">
        window._taboola = window._taboola || [];
        _taboola.push({flush: true});
    </script>
<?php } ?>
<!-- End Scorecard taboola js -->
</body>
</html> 
