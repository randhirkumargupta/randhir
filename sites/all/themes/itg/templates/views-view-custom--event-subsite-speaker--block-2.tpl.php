<?php global $base_url; foreach ($rows as $row): ?>
<div class="row speaker-detail-page">  
  <div class="col-md-3">
     <?php 
     if(!empty($row['field_story_extra_large_image'])){
      print $row['field_story_extra_large_image']; 
     }else{
       print "<img width='170' height='170'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/speaker-detail-page.jpg' />";
     }
     ?>
    <h4><?php print $row['title']; ?></h4>
    <p><?php print $row['field_story_new_title']; ?></p>
  </div>
  <div class="col-md-9">
    <h3><?php print $row['title']; ?></h3>
    <div class="body-content"><?php print $row['body']; ?></div>
  </div>
</div>
  
<?php endforeach; ?>
