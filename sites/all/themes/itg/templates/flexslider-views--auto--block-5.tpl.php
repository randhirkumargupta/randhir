<?php foreach($rows as $index => $row){
//p($items);
   ?>

<div><?php print $row['field_story_extra_large_image'];?></div>
        <div><?php print $row['delta'];?></div>
       <div><?php print ucfirst($row['title']);?></div>
  

<?php };
print theme('flexslider', array('items' => $items, 'settings' => $settings));
?>

