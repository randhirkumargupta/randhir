<?php
global $base_url;
?>
<?php foreach ($rows as $key => $value) : ?>
  <div class="large-image">
    <?php if (!empty($value['field_story_extra_large_image'])) : ?>
      <a href="<?php print $base_url . '/' . "sosorry/" . $value['nid'] . "" ?>" class="pic">
        <?php print $value['field_story_extra_large_image'] ?>
      </a>
    <?php else : ?>
      <a href="<?php print $base_url . '/' . "sosorry/ " . $value['nid'] . "" ?>" class="pic">
        <img  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
      </a>
    <?php endif; ?>
  </div>
<div>
  <?php print $value['field_video_duration']; ?>
</div>

<div>
  <?php print $value['created']; ?>
</div>

  <div class="title">
    <?php print l($value['title'], $base_url . '/' . "sosorry/" . $value['nid'] . "") ?>
  </div>
<?php endforeach; ?>

