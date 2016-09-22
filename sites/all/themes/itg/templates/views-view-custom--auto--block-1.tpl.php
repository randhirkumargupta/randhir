<?php foreach($rows as $index => $row){
   if($index==0){?>
       <div class="first-auto-block"><?php print $row['field_story_extra_large_image'];?></div>
       <div><?php print ucfirst($row['title']);?></div>
   <?php }else{
?>
<div><?php print $row['field_story_extra_large_image'];?></div>
<div><?php print ucfirst($row['title']);?></div>
   <?php } ?>

<?php }; ?>

