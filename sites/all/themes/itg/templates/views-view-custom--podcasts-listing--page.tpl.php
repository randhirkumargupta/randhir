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
      <?php print $row['field_story_extra_large_image']; ?>    
      <span><i class="fa fa-volume-up" aria-hidden="true"></i> 09:10</span>
  </div>
  <div class="podcast-right detail">    
      <h3><?php print $row['title']; ?></h3>
      <p><?php print $row['field_podcast_kicker_message']; ?></p>      
    </div>    
  </div>
<?php endforeach; ?>

