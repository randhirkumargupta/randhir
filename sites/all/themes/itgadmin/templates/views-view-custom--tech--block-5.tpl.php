<?php drupal_add_library('flexslider', 'flexslider');
      ?>

<div class="flexslider">
      <ul class="slides"> 
<?php foreach($rows as $index => $row){

   ?>

 <li><?php print $row['field_story_extra_large_image'];?> 
   
      <div class="detail">
        <p class="flex-count"><i class="fa fa-camera"></i> <?php print $row['delta'];?> images</p>
        <p class="flex-caption" title="<?php echo strip_tags($row['title']);?>"><?php print ucfirst($row['title']);?></p>
      </div>
  
 </li>
<?php }; ?>
</ul>
 </div>

