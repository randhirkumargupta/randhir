<?php
global $base_url, $user;
?>

<header role="banner" id="header">
  <a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
    <amp-img src="<?php print $base_url; ?>/sites/all/themes/amptheme/amptheme/logo.png" alt="<?php print t('Home'); ?>" height="58" width = "71"></amp-img>
  </a>
  <nav id="navbar">
    <amp-accordion disable-session-states>
      <section>
        <h2>
          <span class="show-more"><i class="fa fa-bars"></i></span>
          <span class="show-less"><i class="fa fa-times"></i></span>
        </h2>
        <ul class="header-menu">
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
          if(function_exists('itg_common_get_node_title')) {
          $title = itg_common_get_node_title($arg[1]);
          }
          $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
          $short_url = shorten_url($actual_link, 'goo.gl');
          ?>
        </ul>
      </section>
    </amp-accordion>
    <div class="nav-right">
      <div class="phone"><i class="fa fa-phone" aria-hidden="true"></i></div>
      <div class="comment"><i class="fa fa-comment" aria-hidden="true"></i></div>
      <div class="share"><i class="fa fa-share-alt" aria-hidden="true"></i></div>
      <amp-social-share type="twitter" width="25" height="25" aria-label="share on twitter"
      data-param-text="<?php print $title; ?>"
      data-param-url="<?php print $short_url; ?>">
      </amp-social-share>
      <amp-social-share type="facebook" width="25" height="25" aria-label="share on facebook"
      data-param-app_id="254325784911610" data-param-quote="<?php print $title; ?>"
      data-param-url="<?php print $actual_link; ?>"></amp-social-share>
      <amp-social-share type="gplus" width="25" height="25" aria-label="share on google+"
      data-param-url="<?php print $actual_link; ?>">
      </amp-social-share>
    </div>
  </nav>

</header>