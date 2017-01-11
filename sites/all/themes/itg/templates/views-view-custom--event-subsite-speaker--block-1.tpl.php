<?php global $base_url;
foreach ($rows as $row): ?>
  <?php

  if (!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image'];
  }
  else {
    $img = "<img width='72' height='72'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/speaker-rhs.jpg' />";
    print l($img, $baseurl . '/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
  <?php print $row['title']; ?>
  <?php print $row['field_story_new_title']; ?>
<?php endforeach; ?>
