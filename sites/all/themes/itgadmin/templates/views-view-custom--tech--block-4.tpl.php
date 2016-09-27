<?php foreach($rows as $index => $row): ?>
	<?php $desc=$row['title'];
    if($row['field_story_kicker_text']!="")
    {
        $desc = $row['field_story_kicker_text'];
    }else if($row['field_story_kicker_text']=="" && $row['body']!=""){
         $desc = $row['body'];
    }?>
         <?php print views_embed_view('tech','block_9', $row['field_common_by_line_reporter_id']); 
        
        ?>
<div><?php echo l(mb_strimwidth(strip_tags($desc), 0, 150, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>

       
<?php endforeach; ?>