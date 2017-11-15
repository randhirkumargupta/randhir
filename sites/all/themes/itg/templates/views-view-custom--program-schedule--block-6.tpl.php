<?php global $base_url; foreach($rows as $row): ?>
  <?php
  if(!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image']; 
  }else{
    //$img = "<img width='168' height='168' src='" . file_create_url(file_build_uri(drupal_get_path('theme', 'itg') . '/images/itg_image170x170.jpg')) . "' alt='' title='' />";
    $img = "<img width='168' height='168' src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/itg_image170x170.jpg') . "' alt='' title='' />";
    print l($img, $row['php'].'/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
    
    <h4  title="<?php print strip_tags($row['title']) ; ?>"><?php print html_entity_decode(strip_tags($row['title'])); ?></h4>
    <p><?php print $row['field_story_new_title']; ?></p>
<!--    <p><?php print $row['field_celebrity_pro_occupation']; ?></p>-->
<?php endforeach; ?>
