<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="catagory-listing">
    <div class="pic"><?php print $row['field_story_extra_large_image']; ?> </div>
    <div class="detail"><h3><?php print $row['title']; ?></h3>
      <?php if ($row['type'] == 'story') { ?>
        <p><?php print $row['field_story_kicker_text']; ?></p>
      <?php }else if ($row['type'] == 'photogallery') {?>
        <p><?php print $row['field_gallery_kicer']; ?></p>
      <?php }else if ($row['type'] == 'photogallery') { ?>
        <p><?php print $row['field_story_expert_description']; ?></p>
      <?php } ?>
    </div>
  </div>
<?php endforeach; ?>