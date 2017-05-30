<?php drupal_add_library('flexslider', 'flexslider');
      libraries_load('flexslider');
      module_load_include('inc', 'itg_widget', 'includes/featured_photo_carousel');

      drupal_add_js('jQuery(window).load(function() {
            jQuery(".flexslider").flexslider({
            animation: "slide",
            prevText: "",
            nextText: "",
            });
            });', array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
      );

      drupal_add_css('.flex-caption {
              width: 96%;
              padding: 2%;
              left: 0;
              bottom: 0;
              background: rgba(0,0,0,.5);
              color: #fff;
              text-shadow: 0 -1px 0 rgba(0,0,0,.3);
              font-size: 14px;
              line-height: 18px;
            }', 'inline');?>

<div class="flexslider">
      <ul class="slides"> 
<?php foreach($rows as $index => $row){

   ?>

 <li><?php print $row['field_story_extra_large_image'];?> 
 
      <div class="detail">
        <p class="flex-count"><i class="fa fa-camera"></i> <?php print $row['delta'];?> <?php print t('Images'); ?></p>
        <p class="flex-caption"><?php print ucfirst($row['title']);?></p>
      </div>
  
 </li>
<?php }; ?>
</ul>
 </div>
