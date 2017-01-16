<?php
/**
 * @file
 * Default view for podcast laisting page for fornt user.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($rows as $index => $row): ?>
<div class="podcast-container-<?php print $index ?> catagory-listing">
  <div class="podcast-left pic">  
    <div class="podcast-small-image">
      <?php print $row['field_story_extra_large_image']; ?>
    </div>
  </div>
  <div class="podcast-right detail">
    <div class="podcast-title ">
      <?php print $row['title']; ?>
    </div>
    <div class="podcast-kicker">
      <?php print $row['field_podcast_kicker_message']; ?>
    </div>
  </div>
</div>
<?php endforeach; ?>

