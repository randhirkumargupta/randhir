<?php
global $base_url, $user;
if (!empty($data['itg_main_manu_header'])) {
  foreach ($data['itg_main_manu_header'] as $key => $val) {
    if (isset($val['#localized_options']['attributes']['title']) && $val['#localized_options']['attributes']['title'] == 1) {
      $data['itg_main_manu_header'][$key]['#attributes']['class'][] = 'sponser-link';
    }
  }
}
?>
<div class="header-ads mhide">
 <!--   <img src="<?php //print base_path()                  ?>sites/all/themes/itg/images/header-ads.png" alt="ads"> -->
 <?php
  if (!empty($data['itg_top']['200*200_header'])) {
    print $data['itg_top']['200*200_header'];
  }
 ?>
</div>                               

<div class="head-live-tv desktop-hide">
  <ul>
      <li> 
        <?php if ($user->uid == 0): ?>
        <a href="<?php print $base_url . '/user/login'; ?>" ><i class="fa fa-user"></i></a>
        <?php else: ?>        
          <a href="javascript:void(0)" class="mobile-user"><i class="fa fa-user"></i></a>        
        <?php $block = module_invoke('system', 'block_view', 'user-menu'); ?>
        <?php print render($block['content']); ?> 
        <?php endif; ?>
    </li>
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
        <?php
        $menu_manager = $data['menu_manager'];
        // Contion to check fucntion isset.
        $load_parent = (null != arg(2)) ? taxonomy_get_parents(arg(2)): array();
        foreach ($menu_manager as $key => $menu_data) :
          ?>
          <?php
           if(function_exists('itg_menu_manager_get_menu')) {
                $menu_link_data = itg_menu_manager_get_menu($menu_data , arg() , $load_parent);
                $image_class = $menu_link_data['image_class'];
                $link_text = $menu_link_data['link_text'];
                $link_url = $menu_link_data['link_url'];
                $target = $menu_link_data['target'];
                $active = $menu_link_data['active'];
                $sponsored_class = $menu_link_data['sponsored_class'];
                $parent_class = $menu_link_data['parent_class'];
                $active_cls = $menu_link_data['active_cls'];
          ?>
        <li class="<?php print $image_class; ?>"><?php print l($link_text, $link_url, array('html' => true, 'attributes' => array('target' => $target, 'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class)))); ?></li>
        <?php 
           }
           endforeach;
        ?>
      </ul>
      <?php //print drupal_render($data['itg_main_manu_header']);    ?>            
    </div>         
  </nav>

  <div class="menu-login mhide">
    <div class="container ">   
      <div class="user-menu">
            <?php
                  
                  $get_user_detail = user_load($user->uid);
        
                  if (!empty($get_user_detail->field_user_picture[LANGUAGE_NONE][0]['uri'])) {
                    $user_pic = theme('image_style', array('style_name' => 'user_header_image_30x30', 'path' => $get_user_detail->field_user_picture[LANGUAGE_NONE][0]['uri']));
                  }
                  else {
                    $file = $base_url . '/sites/all/themes/itg/images/default-user.png';
                    $user_pic = "<img src=$file width='30' height='30' alt='user-image'>";
                  }
                  
            if ($_GET['q'] != 'user') {
            ?>
            <?php if ($_SERVER['HTTP_HOST'] == PARENT_SSO) {
              if ($user->uid == 0) { ?>
                  
                  <a href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, 'http://<?php print PARENT_SSO; ?>/saml_login/other/domain_info', 'indiatoday');" class="user-icon"><i class="fa fa-user"></i></a>
                  <a href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, 'http://<?php print PARENT_SSO; ?>/signup/domain_info', 'indiatoday');" class="register-icon" style="display:none;"><i class="fa fa-user"></i></a>

                  <?php
                }
                else {
                  ?>
                  <a href="<?php print $base_url;?>/personalization/edit-profile/general-settings" class="user-icon"><?php print $user_pic; ?></a>
                  <?php
                }
              }
              else {
                if ($user->uid == 0) {
                  ?>
                  <a onclick="Go (550, 500, 50, 'indiatoday', '', '<?php print PARENT_SSO; ?>', '/saml_login/other')" class="user-icon"><i class="fa fa-user"></i></a>

                  <?php
                }
                else {
                  ?>
                  <a href="<?php print $base_url;?>/personalization/edit-profile/general-settings" class="user-icon"><?php print $user_pic; ?></a>
              <?php
            }
          }
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
