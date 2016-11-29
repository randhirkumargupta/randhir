<div class="vertical-menu-parent"><ul class="vertical-menu">
  <?php
  global $base_url;
  $load_parent = taxonomy_get_parents(arg(2));
  $parent_key_of_third_level = isset(array_keys($load_parent)[0]) ? array_keys($load_parent)[0] : 0;
  foreach ($data as $key => $menu_data) :
    ?>
    <?php
    $title_array = explode("[tid", $menu_data['db_data']['title']);
    $link_url = "";
    $icon = "";
    $target = "_self";
    $link_text = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name : $title_array[0];
    $url_type = $menu_data['db_data']['url_type'];
    $db_target = $menu_data['db_data']['target'];
    $tid = $menu_data['db_data']['tid'];
    $active_cls = $parent_class = "notactive";
    $sponsored_class = ($menu_data['db_data']['extra'] == 'Yes') ? "sponsored-active" : "";
    $uri = isset($menu_data['term_load']->field_sponser_logo['und'][0]['uri']) ? $menu_data['term_load']->field_sponser_logo['und'][0]['uri'] : "";
    if ($uri != "") {
      $icon = theme('image_style', array('style_name' => 'vertical_menu_icons', 'path' => $uri));
    }
    else {
      $icon = "<img width='50' height='150'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
    }
    // if tid is not 0 then its internal url
    if (($tid && $url_type == 'internal')) {
      $link_url = "taxonomy/term/$tid";
      if ($link_url == current_path()) {
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

    if ($tid == $parent_key_of_third_level) {
      $parent_class = "active";
    }
    ?>
    <li><?php print l($icon . $link_text, $link_url, array("html" => true, 'attributes' => array('target' => $target, 'class' => array("second-level-child", "second-level-child-$key", $active_cls, $sponsored_class, $parent_class)))); ?></li>
  <?php
  endforeach;
  ?>
</ul>
    </div>
<!--<div class="vertical-more">    
    <a href="javascript:void(0)">
        <span class="more"><i class="fa fa-chevron-down" aria-hidden="true"></i> More</span>
        <span class="less"><i class="fa fa-chevron-up" aria-hidden="true"></i> Less</span>
    </a>    
</div>-->

