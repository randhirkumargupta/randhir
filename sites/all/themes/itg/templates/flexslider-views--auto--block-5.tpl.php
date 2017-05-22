<?php foreach($rows as $index => $row){
   ?>

<div><?php print $row['field_story_extra_large_image'];?></div>
        <div><?php print $row['delta'];?></div>
        <div title="<?php echo strip_tags($row['title']);?> "><?php print ucfirst($row['title']);?></div>
  

<?php };
print theme('flexslider', array('items' => $items, 'settings' => $settings));
?>

