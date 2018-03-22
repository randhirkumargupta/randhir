<?php
global $base_url, $user;
if (!empty(variable_get('itg_front_url'))) {
  $parse_scheme = parse_url(variable_get('itg_front_url'));
  $scheme = $parse_scheme['scheme'] . "://";
}
if (!empty($data['itg_main_manu_header'])) {
  foreach ($data['itg_main_manu_header'] as $key => $val) {
    if (isset($val['#localized_options']['attributes']['title']) && $val['#localized_options']['attributes']['title'] == 1) {
      $data['itg_main_manu_header'][$key]['#attributes']['class'][] = 'sponser-link';
    }
  }
}
if (isset($user->uid)) {
  $get_user_detail = user_load($user->uid);
}

if (!empty($get_user_detail->field_user_picture[LANGUAGE_NONE][0]['uri'])) {
  $user_pic = theme('image_style', array('style_name' => 'user_header_image_30x30', 'path' => $get_user_detail->field_user_picture[LANGUAGE_NONE][0]['uri']));
}
else {
  $file = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/default-user.png');
  $user_pic = "<img src=$file width='30' height='30' alt='user-image' title='user-image' />";
}
$uri = base64_encode($scheme . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
?>

<div class="itg-logo-container">
    <div class="container top-nav">                  
        <div class="main-nav">
            <div class="nav-container-menu">
                <div class="nav-centerall">
                    <?php print drupal_render($data['itg_top_manu_header']); ?>
                    <!----------logo start -->
                    <?php $logo_itg = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/logo.png'); ?>
                    <div class="container headeritg-logo">
                        <?php if ($logo_itg): ?>
                          <div class="logo">
                              <a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>" rel="home" class="header__logo" id="logo"><img src="<?php print $logo_itg; ?>" alt="<?php print t('Home'); ?>" class="header__logo-image" /></a>
                          </div>
                        <?php endif; ?>
                    </div>
                    <!----------logo end -->
                    <?php print drupal_render($data['itg_top_manu_header_second']); ?>
                </div>
            </div>
        </div>
    </div>
    <nav class="navigation">
        <div class="container">
            <ul class="second-level-menu before-load menu mhide">
                <li class="userlogin-icon-parent-mobile">    
                    <div class="user-menus">
                        <?php
                        if ($_GET['q'] != 'user') {
                          $uri = base64_encode($scheme . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
                          if ($user->uid == 0) {
                            ?>
                            <a href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-user"></i> <?php print t('Login'); ?></a>
                            <?php
                          }
                          else {
                            ?>
                            <a href="<?php print $base_url; ?>/personalization/edit-profile/general-settings" class="user-icon loginicon"><?php print $user_pic; ?></a>  
                            <?php
                          }
                        }
                        ?>

                        <?php
                        $block = module_invoke('system', 'block_view', 'user-menu');
                        print render($block['content']);
                        ?>
                    </div>

                </li>
                

                <?php

                // Contion to check fucntion isset.
                $load_parent = (null != arg(2)) ? itg_common_taxonomy_get_parents(arg(2)) : array();
                $default_image = file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/default_for_all_48_32.jpeg');
              
                $menu_manager = !empty($data['menu_manager']) ? $data['menu_manager'] : '';
               
               
                // Contion to check fucntion isset.
                $load_parent = (null != arg(2)) ? itg_common_taxonomy_get_parents(arg(2)) : array();
                if (!empty($menu_manager)) {
                  foreach ($menu_manager as $key => $menu_data) :
                    if (function_exists('itg_menu_manager_get_menu')) {
                      // Logic to exclude inactive category.
                      $menu_link_data = itg_menu_manager_get_menu($menu_data, arg(), $load_parent);
                     
                      $image_class = $menu_link_data['image_class'];
                      $link_text = $menu_link_data['link_text'];
                      $link_url = $menu_link_data['link_url'];
                      $target = $menu_link_data['target'];
                      $active = $menu_link_data['active'];
                      $sponsored_class = $menu_link_data['sponsored_class'];
                      $parent_class = $menu_link_data['parent_class'];
                      $active_cls = $menu_link_data['active_cls'];
                      $url_type = $menu_link_data['url_type'];
                      $style_tag = '';
                      $color_value = 'transparent';
                      if (!empty($sponsored_class)) {
                        $color_value = $menu_data['db_data']['bk_color'];
                      }
                      if ($menu_link_data['url_type'] == 'url-type-external') {
                        if (strpos($link_url, $_SERVER['HTTP_HOST'])) {
                            $attribute_array = array(
                              'style' => array("background : $color_value"),
                              'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                            );
                          } else {
                            $attribute_array = array(
                              'style' => array("background : $color_value"),
                              'target' => $target,
                              'rel' => 'nofollow',
                              'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                            );
                          }
                        } else {
                          $attribute_array = array(
                            'style' => array("background : $color_value"),
                            'target' => $target,
                            'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                          );
                        }
                   
                      ?>
                     <li <?php echo $style_tag; ?> class="nav-items <?php print $image_class; ?>">
                      <?php print l($link_text, $link_url, array('html' => true, 'attributes' => $attribute_array)); ?> 
                      </li>
                     

                      <?php
                    }
                  endforeach;
                }
               // die();
              ?>
            </ul>
            
            <ul class="second-level-menu before-load menu desktop-hide">
                <li class="userlogin-icon-parent-mobile">    
                    <div class="user-menus">
                        <?php
                        if ($_GET['q'] != 'user') {
                          if ($user->uid == 0) {
                            ?>
                            <a href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-user"></i> <?php print t('Login'); ?></a>
                            <?php
                          }
                          else {
                            ?>
                            <a href="<?php print $base_url; ?>/personalization/edit-profile/general-settings" class="user-icon loginicon"><?php print $user_pic; ?></a>  
                            <?php
                          }
                        }
                        ?>

                        <?php
                        $block = module_invoke('system', 'block_view', 'user-menu');
                        print render($block['content']);
                        ?>
                    </div>

                </li>
                <li class="search-icon-parent-mobile">
                    <div class="globle-search">
                        <input class="search-text" placeholder="Enter search keyword" type="text" value="">
                    </div>
                    <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a>
                </li>

                <?php
                
                if (!empty($menu_manager)) {
                  foreach ($menu_manager as $key => $menu_data) :
                    if (function_exists('itg_menu_manager_get_menu')) {
                      // Logic to exclude inactive category.
                      $menu_link_data = itg_menu_manager_get_menu($menu_data, arg(), $load_parent);
                     
                      $image_class = $menu_link_data['image_class'];
                      $link_text = $menu_link_data['link_text'];
                      $link_url = $menu_link_data['link_url'];
                      $target = $menu_link_data['target'];
                      $active = $menu_link_data['active'];
                      $sponsored_class = $menu_link_data['sponsored_class'];
                      $parent_class = $menu_link_data['parent_class'];
                      $active_cls = $menu_link_data['active_cls'];
                      $url_type = $menu_link_data['url_type'];
                      $style_tag = '';
                      $color_value = 'transparent';
                      if (!empty($sponsored_class)) {
                        $color_value = $menu_data['db_data']['bk_color'];
                      }
                      if ($menu_link_data['url_type'] == 'url-type-external') {
                        if (strpos($link_url, $_SERVER['HTTP_HOST'])) {
                            $attribute_array = array(
                              'style' => array("background : $color_value"),
                              'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                            );
                          } else {
                            $attribute_array = array(
                              'style' => array("background : $color_value"),
                              'target' => $target,
                              'rel' => 'nofollow',
                              'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                            );
                          }
                        } else {
                          $attribute_array = array(
                            'style' => array("background : $color_value"),
                            'target' => $target,
                            'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)
                          );
                        }
                        // For Mobile link
                     $link_title_for_vertical = $menu_link_data['link_text_mobile'];
                     // $link_title_for_vertical = $menu_link_data['link_text_icon'] . $menu_link_data['link_text_mobile'];
                      ?>
                    
                      
                      <li <?php echo $style_tag; ?> class="nav-items desktop-hide <?php print $image_class; ?>">
                      <?php print l($link_title_for_vertical, $link_url, array('html' => true, 'attributes' => $attribute_array)); ?> 
                      </li>

                      <?php
                    }
                  endforeach;
                }
              ?>
            </ul>   

            <div class="menu-login mhide">

                <div class="social-nav mhide">
                    <ul class="social-nav mhide">
                        <li class="share-icon-parent">
                            <a href="javascript:void(0)" class="share-icon-default"><i class="fa fa-share-alt" aria-hidden="true"></i></a>
                            <div class="social-dropdown">
                                <ul>

                                    <li><a rel="nofollow" href="https://www.facebook.com/IndiaToday/" class="user-activity def-cur-pointer" data-rel="1" data-tag="homepage" data-activity="fb_follow" data-status="1" title="Follow us" target="_blank"><i class="fa fa-facebook"></i></a></li>
                                    <li><a rel="nofollow" href="https://twitter.com/indiatoday" class="user-activity def-cur-pointer" data-rel="1" data-tag="homepage" data-activity="twitter_follow" data-status="1" title="Follow us" target="_blank"><i class="fa fa-twitter"></i></a></li>
                                    <li><a rel="nofollow" href="https://plus.google.com/+indiatoday" class="user-activity def-cur-pointer" data-rel="1" data-tag="homepage" data-activity="google_follow" data-status="1" title="Follow us" target="_blank"><i class="fa fa-google-plus"></i></a></li>
                                    <li><a href="<?php echo $base_url . '/rss' ?>" title=""><i class="fa fa-rss"></i></a></li>
                                    <li><a href="#" title=""><i class="fa fa-mobile"></i></a></li>
                                    <li><a href="#" title=""><i class="fa fa-volume-up"></i></a></li>
                                </ul>
                            </div>
                        </li>


                        <li class="search-icon-parent">
                            <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a>
                            <a href="javascript:void(0)" class="search-icon-search" title=""><i class="fa fa-search"></i></a>
                            <div class="globle-search">
                                <input class="search-text" placeholder="Type here" type="text" value="" />
                            </div>
                        </li>   

                        <li>
                            <div class="user-menu">
                                <?php
                                if ($_GET['q'] != 'user') {
                                  $uri = base64_encode($scheme . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
                                  if ($user->uid == 0) {
                                    ?>
                                    <a href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>" class="user-icon sso-click"><i class="fa fa-user"></i></a>
                                    <?php
                                  }
                                  else {
                                    ?>
                                    <a href="<?php print $base_url; ?>/personalization/edit-profile/general-settings" class="user-icon"><?php print $user_pic; ?></a>  
                                    <?php
                                  }
                                }
                                ?>

                                    <?php
                                    $block = module_invoke('system', 'block_view', 'user-menu');
                                    print render($block['content']);
                                    ?>
                            </div>
                        </li>	
                    </ul>          	  
                </div>
            </div>
        </div>
    </nav>
</div>

