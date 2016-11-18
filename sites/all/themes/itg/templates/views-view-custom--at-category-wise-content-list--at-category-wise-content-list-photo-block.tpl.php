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
<?php
$count = 1;

foreach ($rows as $id => $row):
  if ($count % 4 == 1) {
    echo "<div class='wrapper'>";
  }
  ?>
  <div class="catagory-listing-row row-count-<?php print $id; ?>">
    <div class="pic">
      <!-- Handle for first large image -->
      <?php
      if ($id == 0 || $id % 5 == 0) {
        $image_style = "aaj_tak_category_wise_content_photo_block_big";
      }
      else {
        $image_style = "aaj_tak_category_wise_content_photo_small";
      }
      ?>
      <div class="extra-large-image">
        <?php if ($row['field_story_extra_large_image'] == 'notfound') : ?>
          <?php
          $image = array(
            '#theme' => 'image_style_outside_files',
            '#style_name' => $image_style,
            '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
          );
          ?>
          <?php print render($image); ?>
        <?php else : ?>
          <?php print $row['field_story_extra_large_image']; ?>
        <?php endif; ?>
      </div>
    </div>
    <div>
      <?php print $row['delta']; ?>
    </div>
  </div>
  <?php
  if ($count % 4 == 0) {
    echo "</div>";
  }
  $count++;
  ?>
  <?php
endforeach;
if ($count % 4 != 1)
  echo "</div>";
?>