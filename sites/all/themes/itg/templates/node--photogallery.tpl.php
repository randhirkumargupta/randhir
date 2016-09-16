<div style="display:none">
  <?php print render($content); ?>
</div>
<?php
print views_embed_view('photo_list_of_category', 'block_1');
if (function_exists('taboola_view')) {
  taboola_view();
}
?>

<div class="vukkul-comment">

  <div id="vuukle_div"></div>

  <?php
  if (function_exists('vukkul_view')) {
    vukkul_view();
  }
  ?>

</div>