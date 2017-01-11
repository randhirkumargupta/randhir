<?php if (!empty($data)) : ?>
  <div class="vertical-menu-parent"><ul class="vertical-menu">
      <?php
      global $base_url;
      $load_parent = (null != arg(2)) ? taxonomy_get_parents(arg(2)) : array();
      $parent_key_of_third_level = isset(array_keys($load_parent)[0]) ? array_keys($load_parent)[0] : 0;
      foreach ($data as $key => $menu_data) :
        ?>
        <?php
        $menu_link_data = itg_menu_manager_get_menu($menu_data, arg(), $load_parent);
        $link_text = $menu_link_data['link_title_for_vertical'];
        $link_title_display = $link_text;
        $image_class = $menu_link_data['image_class'];
        $link_url = $menu_link_data['link_url'];
        $target = $menu_link_data['target'];
        $active = $menu_link_data['active'];
        $sponsored_class = $menu_link_data['sponsored_class'];
        $parent_class = $menu_link_data['parent_class'];
        $active_cls = $menu_link_data['active_cls'];
        $display_icon = $menu_link_data['display_icon'];
        $icon = $menu_link_data['icon'];
        $url_type = $menu_link_data['url_type'];
        //Check if icon found empty.
        if(empty($icon)) {
          $image_url = $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all_48_32.jpeg";
          $icon = "<img src='".$image_url."'>";
        }
        if($display_icon == 1) {
          $link_title_display = $icon;
        }
        
        ?>
        <li><?php print l($link_title_display, $link_url, array("html" => true, 'attributes' => array('target' => $target, 'title'=> $menu_link_data['link_title_for_vertical'] , 'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class, $url_type)))); ?></li>
        <?php
      endforeach;
      ?>
    </ul>
  </div>
  <div class="vertical-more">    
    <a class="more" href="javascript:void(0)">
      <span><i class="fa fa-chevron-down" aria-hidden="true"></i></span>
    </a>    
    <a class="less" href="javascript:void(0)" style="display: none">
      <span><i class="fa fa-chevron-up" aria-hidden="true"></i></span>
    </a>    
  </div>
<?php endif; ?>