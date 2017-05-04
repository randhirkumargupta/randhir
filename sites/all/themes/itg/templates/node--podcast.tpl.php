<?php
global $base_url;
?>
<?php print views_embed_view('podcasts_listing', 'block'); ?>
<?php
$config_name = trim($global_comment_last_record[0]->config_name);
if (!empty($node->field_podcast_configuration['und'])) {
  foreach ($node->field_podcast_configuration['und'] as $value) {
    $config[] = $value['value'];
  }
}
?>
<?php if (function_exists('taboola_view')) : ?>
  <?php taboola_view(); ?>
<?php endif; ?>

<?php if ($config_name == 'vukkul' && in_array('commentbox', $config)) : ?>
  <div class="vukkul-comment">
    <div id="vuukle-emote"></div>
    <div id="vuukle_div"></div>
    <?php if (function_exists('vukkul_view')) : ?>
      <?php vukkul_view(); ?>
    <?php endif; ?>
  </div>
<?php endif; ?>


<?php if ($config_name == 'other' && in_array('commentbox', $config)) : ?>
  <div id="other-comment">
    <?php
    $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
    print render($block['content']);
    ?>
  </div>
<?php endif; ?>