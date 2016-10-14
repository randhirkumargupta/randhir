<?php drupal_add_library('flexslider', 'flexslider');
      libraries_load('flexslider');
      module_load_include('inc', 'itg_widget', 'includes/featured_photo_carousel');

      drupal_add_js('
            jQuery(".flexslider").flexslider({
            animation: "slide",
            prevText: "",
            nextText: "",
            });
            ', array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
      );

      drupal_add_css('', 'inline');?>

<div class="flexslider">
      <ul class="slides"> 
<?php foreach($rows as $index => $row){

   ?>

 <li><?php print $row['field_story_extra_large_image'];?> 
     
     
     
     
      <div class="detail">
        <p class="flex-count"><i class="fa fa-camera"></i> <?php print $row['delta'];?> images</p>
        <p class="flex-caption"><?php print ucfirst($row['title']);?></p>
      </div>
  
 </li>
<?php }; ?>
</ul>
 </div>
