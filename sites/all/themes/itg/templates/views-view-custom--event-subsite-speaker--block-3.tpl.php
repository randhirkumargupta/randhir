<?php
global $base_url;
foreach ($rows as $row): ?>

  <div class="image-wrap">  
      <?php
      if (!empty($row['field_sponser_logo'])) {
        print $row['field_sponser_logo'];
      }
      else {
        print "<img src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image237x133.jpg' alt='' />";
      }
      ?>
  </div>

  <h3 title="<?php echo html_entity_decode(strip_tags($row['title'])); ?>"><?php print html_entity_decode(strip_tags($row['title'])); ?></h3>
  <div class="body-content"><?php print $row['body']; ?></div>

<?php endforeach; ?>
