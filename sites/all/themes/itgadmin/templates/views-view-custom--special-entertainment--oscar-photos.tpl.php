<div class="oscor-photo">
<div class="row">
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
   
  ?>
    <div class="col-md-6">
    <?php print $row['field_story_extra_large_image'];?>
        <div class="title"><h3><?php echo l(mb_strimwidth(strip_tags($desc), 0, 100, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h3></div>
     </div>
   <?php }; ?>
     
</div>

</div>