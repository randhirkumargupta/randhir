<?php global $base_url;
foreach ($rows as $row): ?>
  <?php

  if (!empty($row['field_story_extra_large_image'])) {
    $img = $row['field_story_extra_large_image'];
  }
  else {
    //$img = "<img width='103' height='103'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/imgpsh_fullsize103x103.png' alt='' title='' />";
    $img = "<img width='103' height='103' src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/imgpsh_fullsize103x103.png') . "' alt='' title='' />";
  }
  if (function_exists('itg_event_get_host_name')) {
    $host_url = itg_event_get_host_name();
    print l($img, $host_url . '/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
    
  <div class="views-field-title" title="<?php echo strip_tags($row['title']);?>"><?php print $row['title']; ?></div>
  <div class="views-field-field-story-new-title"><?php print $row['field_story_new_title']; ?></div>  
<!--  <div class="views-field-field-story-new-title"><?php print $row['field_celebrity_pro_occupation']; ?></div>-->
<?php endforeach; ?>
