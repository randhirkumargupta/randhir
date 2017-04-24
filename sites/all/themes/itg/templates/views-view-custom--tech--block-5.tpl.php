<?php drupal_add_library('flexslider', 'flexslider');
      libraries_load('flexslider');
      module_load_include('inc', 'itg_widget', 'includes/featured_photo_carousel');


     ?>

<div class="flexslider">
      <ul class="slides"> 
<?php foreach($rows as $index => $row){

   ?>

 <li><?php print $row['field_story_extra_large_image'];?> 
     
     
     
     
      <div class="detail">
        <p class="flex-count"><i class="fa fa-camera"></i> <?php print $row['delta'];?> Images</p>
        <p class="flex-caption"><?php print mb_strimwidth($row['title'], 0, 200, "..");?></p>
      </div>
  
 </li>
<?php }; ?>
</ul>
 </div>
