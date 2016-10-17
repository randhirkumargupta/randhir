<ul class="third-level-menu">
  <?php foreach ($data as $key => $menu_data) : ?>
    <?php
    $link_url = "";
    $target = "_self";
    $link_text = isset($menu_data['term_load']->name) ? $menu_data['term_load']->name : $menu_data['db_data']['title'];
    $url_type = $menu_data['db_data']['url_type'];
    $db_target = $menu_data['db_data']['target'];
    $tid = $menu_data['db_data']['tid'];
    // if tid is not 0 then its internal url
    if ($tid && $url_type == 'internal') {
      $link_url = "taxonomy/term/$tid";
    }
    else {
      $link_url = $menu_data['db_data']['url'];
    }
    // manage target
    if (trim($db_target) == 'new_window') {
      $target = "__blank";
    }
    ?>
    <li><?php print l($link_text, $link_url, array('attributes' => array('target' => $target, 'class' => array("third-level-child", "third-level-child-$key")))); ?></li>
  <?php endforeach; ?>
</ul>