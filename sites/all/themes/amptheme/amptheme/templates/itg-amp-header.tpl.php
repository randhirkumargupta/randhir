<?php
global $base_url, $user;
$search_url = FRONT_URL.'/get-amp-search-keyword';
?>

<header role="banner" id="header">
<nav id="navbar">
<amp-accordion disable-session-states>
      <section>
        <h2>
          <span class="show-more"><i class="fa fa-bars"></i></span>
          <span class="show-less"><i class="fa fa-times"></i></span>
        </h2>
        <ul class="header-menu">
            <li class="search-section-amp">
                <form method="GET"
                      class="search-form"
                      action=<?php print $search_url; ?>
                      target="_top">
                    <input type="search"
                           placeholder="Search..."
                           name="search">
                    <input type="submit" name="submitlogin"
                           value="OK"
                           class="ampstart-btn caps">
                    <a href="#" class="search" title="Search"><i class="fa fa-search" aria-hidden="true"></i></a>
                </form>
            </li>

          <?php
          $menu_manager = !empty($data['menu_manager']) ? $data['menu_manager'] : '';
          // Contion to check fucntion isset.
          $load_parent = (null != arg(2)) ? taxonomy_get_parents(arg(2)) : array();
          if (!empty($menu_manager)) {
            $emoji_html = '';
            foreach ($menu_manager as $key => $menu_data) :
              if (function_exists('itg_menu_manager_get_menu')) {
                // Logic to exclude inactive category.
                if (!empty($menu_data['term_load'])) {
                  $category_manager_tid = $menu_data['term_load']->tid;
                  $term_state = itg_category_manager_term_state($category_manager_tid);
                  if ($term_state == 0) {
                    continue;
                  }
                }

                $menu_link_data = itg_menu_manager_get_menu($menu_data, arg(), $load_parent, 'amp');
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
                $color_value = '';
                $icon_path = $menu_link_data['icon_path'];

                if (!empty($icon_path)) {
                  $link_text_icon  = "<span class='menu-icons-amp'><amp-img class='itg-user-icon navimgamp' src='" . file_create_url($icon_path) . "'  /></span>";
                } else {
                  $default_image = $base_url . '/sites/all/themes/itg/images/default_for_all_48_32.jpeg';
                  $link_text_icon  = "<span class='menu-icons-amp'><amp-img class='itg-user-icon navimgamp' src=$default_image alt='' /></span>";
                }
                $link_text = $link_text_icon . $menu_link_data['link_title_for_vertical'];
                if (!empty($sponsored_class)) {
                  $color_value = $menu_data['db_data']['bk_color'];
                }
                preg_match_all('/<img[^>]*>/s', $link_text, $img_tag);
                if (!empty($img_tag[0][0])) {
                  $html = $img_tag[0][0];
                  $html = str_ireplace(
                          ['<img', '<video', '/video>', '<audio', '/audio>'], ['<amp-img', '<amp-video', '/amp-video>', '<amp-audio', '/amp-audio>'], $html
                  );
                  $emoji_html = preg_replace('/<amp-img(.*?)\/?>/', '<amp-img$1></amp-img>', $html);
                  $link_text = $emoji_html;
                } else {
                  $link_text = $link_text;
                }
                ?>
                <li <?php echo $style_tag; ?> class="<?php print $image_class; ?>">
                  <?php print l($link_text, $link_url, array('html' => true, 'attributes' => array('style' => array("background : $color_value"), 'target' => $target, 'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type))));
                  ?>
                </li>
                <?php
              }
            endforeach;
          }
          
          // code for sharing
          $arg = arg();
          if(function_exists('itg_get_node_details')) { 
          $title = itg_get_node_details($arg[1]);
          $share_title = $title[0]['title'];
          $image = file_load($title[0]['field_story_extra_large_image_fid']);
          $share_image = file_create_url($image->uri);
          }
          $actual_link = 'http://' . $_SERVER['HTTP_HOST'] .'/amp'. $_SERVER['REQUEST_URI'];
          $amp_link = str_replace('?amp', '', $actual_link);
          $short_url = shorten_url($amp_link, 'goo.gl');
          $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$amp_link.'&title='.$share_title.'&picture='.$share_image;
          $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($share_title).'&url='.$short_url.'&via=IndiaToday';
          $google_url = 'https://plus.google.com/share?url='.  urlencode($amp_link);
          ?>
        </ul>
      </section>
    </amp-accordion>

<div class="container top-nav">                  
    <div class="main-nav">
       <div class="nav-container-menu">
         <div class="nav-centerall">
         <div class="top-first-menu">
          <?php print drupal_render($data['itg_top_manu_header']); ?>
          </div>
             <!--logo start -->
            <?php $logo_itg = file_create_url(file_default_scheme() . '://../sites/all/themes/amptheme/ampthem/logo.png'); ?>
              <div class="container headeritg-logo">    
              <?php if ($logo_itg): ?>
              <div class="logo">
                  <a href="<?php print $base_url; ?>" title="<?php //print t('Home'); ?>" rel="home" id="logo">
                      <amp-img src="<?php print $logo_itg; ?>" alt="<?php  t('Home'); ?>" height="30" width = "70"></amp-img>
                  </a>
              </div>
              <?php endif; ?>
              </div>
            <!--logo end -->
            <?php print drupal_render($data['itg_top_manu_header_second']); ?>
            </div>
       </div>
    </div>
  </div>
  </nav>
</header>

</header>
<?php if(($title[0]['type'] == 'story') || ($title[0]['type'] == 'breaking_news')) { ?>
<div class="story_ad_block custom-amp-ad">
            <?php
            $block = module_invoke('itg_front_end_common', 'block_view', 'amp_story_ad_block');
            print render($block['content']);
            ?>
</div>
<?php } ?>
