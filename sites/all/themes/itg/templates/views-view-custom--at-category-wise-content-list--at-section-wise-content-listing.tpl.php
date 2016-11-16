<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
// aaj_tak_category_wise_content_banner_big
// aaj_tak_category_wise_content_banner_small 
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="catagory-listing">
    <div class="pic">
      <!-- Handle for first large image -->
      <?php
      if ($id == 0 || $id % 5 == 0) {
        $image_style = "aaj_tak_category_wise_content_banner_big";
      }
      else {
        $image_style = "aaj_tak_category_wise_content_banner_small";
      }
      ?>
      <div class="extra-large-image">
        <?php if ($row['uri'] == 'notfound') : ?>
          <?php
          $image = array(
            '#theme' => 'image_style_outside_files',
            '#style_name' => $image_style,
            '#path' => drupal_get_path('theme', 'itg') . "/images/default_for_all.png",
          );
          ?>
        <?php else : ?>
          <?php
          $image = array(
            '#theme' => 'image_style_outside_files',
            '#style_name' => $image_style,
            '#path' => $row['uri'],
          );
          ?>
        <?php endif; ?>
        <?php print render($image); ?>
      </div>
    </div>
    <div class="detail">
      <div class="category-title">
        <h3><?php print $row['title']; ?></h3>
      </div>
      <div class="bottom-category">
        <span class="user-frist-name"><?php print $row['field_first_name']; ?></span>
        <span class="updated-date"><?php print $row['changed'] . t(" IST"); ?></span>
      </div>
    </div>
  </div>
<?php endforeach; ?>