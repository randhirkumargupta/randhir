<?php global $base_url; foreach($rows as $row): ?>
  <?php
  if(!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image']; 
  }else{
    $img = "<img width='168' height='168'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image170x170.jpg' alt='' />";
    print l($img, $row['php'].'/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
    
    <h4  title="<?php print $row['title'] ; ?>"><?php print $row['title']; ?></h4>
    <p><?php print $row['field_story_new_title']; ?></p>
<?php endforeach; ?>
