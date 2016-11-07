<?php
foreach ($data['itg_main_manu_header'] as $key => $val) {
  if ($val['#localized_options']['attributes']['title'] == 1) {
    $data['itg_main_manu_header'][$key]['#attributes']['class'][] = 'sponser-link';
  }
}
?>
<div class="header-ads mhide">
 <!--   <img src="<?php //print base_path()  ?>sites/all/themes/itg/images/header-ads.png" alt="ads"> -->
  <?php print ($data['itg_top']['200*200_header']); ?>
</div>                               

<div class="head-live-tv desktop-hide">
  <ul>
    <li> <a href="javascript:void(0)" ><i class="fa fa-user"></i></a></li>
    <li><a href="javascript:void(0)" class="search-icon" title=""><i class="fa fa-search"></i></a></li>
    <li><a href="javascript:void(0)" class="live-tv" title=""><img src="<?php print base_path() ?>sites/all/themes/itg/images/live-tv-icon.png" alt="Live Tv"></a></li> 
  </ul>
  <div class="globle-search">
    <input class="search-text" placeholder="Type here" type="text" value=""></div>
  <!--      <div class="menu-login desktop-hide">
          <div class="container ">   
              <div class="user-menu">
                  <a href="signup?width=500&height=500&iframe=true" class="user-icon colorbox-load"><i class="fa fa-user"></i></a>
  <?php
  //$block = module_invoke('system', 'block_view', 'user-menu');
  // print render($block['content']);
  ?>
              </div>
          </div>
      </div>-->
</div>
<div class="itg-logo-container">
  <div class="container top-nav">                  
    <div class="social-nav mhide">
      <ul class="social-nav mhide">
        <li><a href="#" title=""><i class="fa fa-facebook"></i></a></li>
        <li><a href="#" title=""><i class="fa fa-twitter"></i></a></li>
        <li><a href="#" title=""><i class="fa fa-google-plus"></i></a></li>
        <li><a href="#" title=""><i class="fa fa-rss"></i></a></li>
        <li><a href="#" title=""><i class="fa fa-mobile"></i></a></li>
        <li><a href="#" title=""><i class="fa fa-volume-up"></i></a></li>
        <li><a href="javascript:void(0)" class="search-icon" title=""><i class="fa fa-search"></i></a></li>                            
      </ul>
      <div class="globle-search">
        <input class="search-text" placeholder="Type here" type="text" value=""></div>
    </div>
    <div class="main-nav">
      <?php print drupal_render($data['itg_top_manu_header']); ?>
    </div>
  </div>
  <nav class="navigation">
    <div class="container">
      <ul class="second-level-menu menu">
        <?php $menu_manager = $data['menu_manager']; 
        foreach ($menu_manager as $key => $menu_data) :  ?>
          <?php  
          $title_array = explode("[tid", $menu_data['db_data']['title']);
          $link_url = "";
          $target = "_self";
          $link_text = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name :  $title_array[0];
          $url_type = $menu_data['db_data']['url_type'];
          $db_target = $menu_data['db_data']['target'];
          $tid = $menu_data['db_data']['tid'];
          $active_cls = "notactive";
          // if tid is not 0 then its internal url
          if ($tid && $url_type == 'internal') {
            $link_url = "taxonomy/term/$tid";
            if($link_url == current_path()) {
              $active_cls = "active";
            }
          }
          else {
            $link_url = $menu_data['db_data']['url'];
          }
          // manage target
          if (trim($db_target) == 'new_window') {
            $target = "_blank";
          }
          ?>
          <li><?php print l($link_text, $link_url, array('attributes' => array('target' => $target, 'class' => array("second-level-child", "second-level-child-$key" , "$active_cls")))); ?></li>
        <?php endforeach; ?>
      </ul>
      <?php //print drupal_render($data['itg_main_manu_header']); ?>            
    </div>         
  </nav>

  <div class="menu-login mhide">
    <div class="container ">   
      <div class="user-menu">
        <?php
        global $user;

        if ($user->uid == 0 || $_GET['q'] != 'user') {
          ?>
          <?php if ($_SERVER['HTTP_HOST'] == 'dev.indiatodayonline.in') { ?>

    <!--<a onclick="window.open('http://itgcms.drupallocal.dev/saml_login/other/domain_info', '_blank', 'location=yes,height=490,width=550,scrollbars=yes,status=yes', 'top=' + tops + ', left=' + left);" class="user-icon"><i class="fa fa-user"></i></a> -->
            <a href="javascript:void(0)" onclick="CenterWindow(550, 500, 50, 'http://dev.indiatodayonline.in/saml_login/other/domain_info', 'indiatoday');" class="user-icon"><i class="fa fa-user"></i></a>
            <a href="javascript:void(0)" onclick="CenterWindow(550, 500, 50, 'http://dev.indiatodayonline.in/signup/domain_info', 'indiatoday');" class="register-icon" style="display:none;"><i class="fa fa-user"></i></a>

          <?php }
          else {
            ?>
            <a onclick="Go(550, 500, 50, 'indiatoday')" class="user-icon"><i class="fa fa-user"></i></a>

          <?php }
        }
        ?>

        <?php
        $block = module_invoke('system', 'block_view', 'user-menu');
        print render($block['content']);
        ?>
      </div>
    </div>
  </div>

</div>
