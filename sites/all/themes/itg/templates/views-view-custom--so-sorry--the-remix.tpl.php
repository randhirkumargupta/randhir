<?php
global $base_url;
$remix_data = $rows[0];
?>
<?php print t("<h2>THE <span>REMIX</span></h2>"); ?>
<div class="large-image">
  <?php if (!empty($remix_data['field_story_extra_large_image'])) : ?>
    <a href="<?php print $base_url . '/' . "sosorry/" . $remix_data['nid'] . "" ?>" class="pic">
      <?php print $remix_data['field_story_extra_large_image'] ?>
    </a>
  <?php else : ?>
    <a href="<?php print $base_url . '/' . "sosorry/video/" . $remix_data['nid'] . "" ?>" class="pic">
      <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg' alt='' />
    </a>
  <?php endif; ?>
</div>
<div class="title"  title="<?php print strip_tags($remix_data['title']) ; ?>">
  <?php print l(mb_strimwidth($remix_data['title'], 0, 45, ".."), $base_url . '/' . "sosorry/" . $remix_data['nid'] . ""); ?>
</div>