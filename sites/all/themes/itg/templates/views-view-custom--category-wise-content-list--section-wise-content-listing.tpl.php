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
<?php foreach ($rows as $id => $row) { ?>
  <div class="catagory-listing">
    <div class="pic">
      <?php if ($row['field_story_extra_large_image'] != 'notFound') { ?>
        <?php print $row['field_story_extra_large_image']; ?>
        <?php
      }
      else {
        if ($row['type'] == 'videogallery') {
          $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/default_video.jpg' />";
        }
        else {
          $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />";
        }
      }
      ?>
      <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
    </div>
    <div class="detail"><h3><?php print $row['title']; ?></h3>
        <?php if ($row['type'] == 'story') { ?>
        <p><?php print $row['field_story_kicker_text']; ?></p>
      <?php }
      else if ($row['type'] == 'photogallery') {
        ?>
        <p><?php print $row['field_gallery_kicer']; ?></p>
      <?php }
      else if ($row['type'] == 'photogallery') {
        ?>
        <p><?php print $row['field_story_expert_description']; ?></p>
  <?php } ?>
    </div>
  </div>
<?php } ?>