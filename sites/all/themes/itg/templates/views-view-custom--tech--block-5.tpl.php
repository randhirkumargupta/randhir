<?php foreach($rows as $index => $row){

   ?>
       <div ><?php print $row['field_story_extra_large_image'];?></div>
        <div class="pic"><?php print $row['delta'];?></div>
       <div><?php print ucfirst($row['title']);?></div>
  

<?php }; ?>

