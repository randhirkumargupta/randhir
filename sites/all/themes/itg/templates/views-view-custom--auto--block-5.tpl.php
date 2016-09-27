<?php foreach($rows as $index => $row){

   ?>

<div class="here"><?php print $row['field_story_extra_large_image'];?></div>
        <div><?php print $row['delta'];?></div>
       <div><?php print ucfirst($row['title']);?></div>
  

<?php }; ?>

