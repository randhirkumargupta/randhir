<?php foreach($rows as $index => $row){
    $desc=$row['title'];
    if($row['field_story_kicker_text']!="")
    {
        $desc = $row['field_story_kicker_text'];
    }else if($row['field_story_kicker_text']=="" && $row['body']!=""){
         $desc = $row['body'];
    }else if($row['field_story_expert_description']!=""){
        $desc = $row['field_story_expert_description'];
    }
    $video_class="";
    if(strtolower($row['type'])=='videogallery')
    {
       $video_class='content-video'; 
    }
    ?>
  
       <div class="first-oscar-block <?php echo $video_class;?>"><?php print $row['field_story_extra_large_image'];?></div>
       <div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>
   


<?php }; ?>

