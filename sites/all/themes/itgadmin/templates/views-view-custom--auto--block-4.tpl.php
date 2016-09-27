<?php foreach($rows as $index => $row){
   
    $desc="";
    if($row['field_story_kicker_text']!="")
    {
        $desc = $row['field_story_kicker_text'];
    }else if($row['field_story_kicker_text']=="" && $row['body']!=""){
         $desc = $row['body'];
    }
  ?>
<div><?php echo $row['title']; ?></div>

<div><?php echo mb_strimwidth(strip_tags($desc), 0, 150, ".."); ?></div>

  

<?php }; ?>

