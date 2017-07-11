<?php
global $base_url, $user;
?>

<header role="banner" id="header">
  <a href="<?php print $base_url; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
    <amp-img src="<?php print $base_url; ?>/sites/all/themes/amptheme/amptheme/logo.png" alt="<?php print t('Home'); ?>" height="58" width = "71"></amp-img>
  </a>
<!--  <a href="#" class="search" title="Search"><i class="fa fa-search" aria-hidden="true"></i></a>-->
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
          if(function_exists('itg_get_node_details')) {
          //$nid = get_nid_form_url($_SERVER['REQUEST_URI']);  
          $title = itg_get_node_details($arg[1]);
          $share_title = $title[0]['title'];
          $image = file_load($title[0]['field_story_extra_large_image_fid']);
          $share_image = file_create_url($image->uri);
          }
          $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
          $short_url = shorten_url($actual_link, 'goo.gl');
          $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$actual_link.'&title='.$share_title.'&picture='.$share_image;
          $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($share_title).'&url='.$short_url.'&via=IndiaToday';
          $google_url = 'https://plus.google.com/share?url='.  urlencode($actual_link);
          ?>
        </ul>
      </section>
    </amp-accordion>
    <div class="nav-right">
<!--      <div class="phone"><i class="fa fa-phone" aria-hidden="true"></i></div>
      <div class="comment"><i class="fa fa-comment" aria-hidden="true"></i></div>-->
      <div class="social-share">
      <amp-accordion disable-session-states>
        <section>
          <h2>
            <span class="show-more"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
            <span class="show-less"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
          </h2>
          <div class="share-link">
            <a href="<?php print $twitter_url; ?>" target="_blank" title="share on twitter"><i class="fa fa-twitter-square" aria-hidden="true"></i></a>
            <a href="<?php print $fb_url; ?>" target="_blank" title="share on facebook"><i class="fa fa-facebook-official" aria-hidden="true"></i></a>
            <a href="<?php print $google_url;?>" target="_blank" title="share on G+"><i class="fa fa-google-plus-square" aria-hidden="true"></i></a>
          </div>
        </section>
      </amp-accordion>
      </div>
    </div>
  </nav>

</header>