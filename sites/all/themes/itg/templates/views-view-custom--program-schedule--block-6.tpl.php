<?php global $base_url; foreach($rows as $row): ?>
  <?php
  if(!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image']; 
  }else{
    $img = "<img width='168' height='168'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/default_speaker.jpg' />";
    print l($img, $row['php'].'/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
  <?php print $row['title']; ?>
  <?php print $row['field_story_new_title']; ?>
<?php endforeach; ?>
