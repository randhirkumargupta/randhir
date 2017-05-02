<?php global $base_url;
foreach ($rows as $row): ?>
  <?php

  if (!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image'];
  }
  else {
    $img = "<img width='72' height='72'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image72x72.jpg' alt='' />";
    print l($img, $baseurl . '/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
  <div class="views-field-title" title="<?php echo $row['title'];?>"><?php print $row['title']; ?></div>
    <div class="views-field-field-story-new-title"><?php print $row['field_story_new_title']; ?></div>
<?php endforeach; ?>
