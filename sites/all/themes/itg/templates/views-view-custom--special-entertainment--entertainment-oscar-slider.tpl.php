<?php foreach($rows as $index => $row){
    $desc=$row['title'];
   
    ?>
  
       <div ><?php print $row['field_story_extra_large_image'];?></div>
        <div ><?php print $row['field_story_extra_large_image_1'];?></div>
       
       <div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>
   


<?php }; ?>

