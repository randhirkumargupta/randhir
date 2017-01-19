<div class="oscor-photo">
<div class="row">
<?php 
global $base_url;
foreach($rows as $index => $row){
    $desc=$row['title'];

  ?>
    <div class="col-md-6 ">
     <?php if($row['field_story_medium_image'] != "") {
                print $row['field_story_medium_image'];
            } else {
                print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image370x208.jpg' />";
            }?>
        <div class="title"><h3><?php echo l(mb_strimwidth(strip_tags($desc), 0, 75, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h3></div>
     </div>
   <?php }; ?>
     
</div>

</div>