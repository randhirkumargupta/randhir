<?php
$image_style = "";
if (!empty($title)):
  ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="catagory-listing">
    <div class="extra-large-image">
      <?php if ($row['field_story_extra_large_image'] == 'notfound') : ?>
        <?php
        $image = array(
          '#theme' => 'image_style_outside_files',
          '#style_name' => 'live_tv_latest_video',
          '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
        );
        print render($image);
        ?>
      <?php else : ?>
        <?php print $row['field_story_extra_large_image'] ?>
      <?php endif; ?>
    </div>
    <div class="detail"><h3><?php print $row['title']; ?></h3>
      <div class="bottom-category-story">
        <span class="user-frist-name"><?php print $row['field_first_name']; ?></span>
        <span class="updated-date"><?php print $row['changed'] . t(" IST"); ?></span>
      </div>
    </div>
  </div>
<?php endforeach; ?>