<?php
global $base_url, $user;
$uri = base64_encode('http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']);
?>
<div class="header-ads">
  <?php
  $block = block_load('itg_ads', ADS_HEADER);
  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
  print render($render_array);
  ?>
</div>
<div class="itg-logo-container">
  <nav class="navigation">
    <div class="container">
        <?php 
        $menu_manager = !empty($data['menu_manager']) ? $data['menu_manager'] : '';
        print  drupal_render(menu_tree_output($menu_manager));
        
        ?>
    </div>         
  </nav>

</div>

