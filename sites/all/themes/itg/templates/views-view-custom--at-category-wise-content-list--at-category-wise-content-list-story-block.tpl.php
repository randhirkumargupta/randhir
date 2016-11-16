<?php
$image_style = "";
if (!empty($title)):
  ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="catagory-listing">
    <div class="extra-large-image">
      <?php
      $image = array(
        '#theme' => 'image_style_outside_files',
        '#style_name' => 'aaj_tak_category_wise_content_story_block',
        '#path' => ($row['uri'] != 'notfound') ? $row['uri'] : drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
      );
      ?>
      <?php print render($image); ?>
    </div>
    <div class="detail"><h3><?php print $row['title']; ?></h3>
      <div class="bottom-category-story">
        <span class="user-frist-name"><?php print $row['field_first_name']; ?></span>
        <span class="updated-date"><?php print $row['changed'] . t(" IST"); ?></span>
      </div>
    </div>
  </div>
<?php endforeach; ?>