 <div class="techwatch osscar-video">
     <ul class="">  
<?php foreach($rows as $index => $row){
    $desc=$row['title'];
   
   
    ?>
         <li class="dont-miss-listing">
             <div class="dm-pic"><a href="#" class="pic"><?php print $row['field_story_small_image'];?></a> <span><i class="fa fa-play-circle"></i> <?php echo $row['field_video_duration'];?></span></div>
            
            <div class="dm-detail"><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>       
   </li>


<?php }; ?>
       </ul>
 </div>