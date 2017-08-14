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
                print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image370x208.jpg' alt='' />";
            }?>
        <div class="title"><h3  title="<?php print strip_tags($row['title']) ; ?>">
          <?php 
            if (function_exists('itg_common_get_smiley_title')) {
              echo l(itg_common_get_smiley_title($row['nid'], 0, 65), "node/" . $row['nid'], array("html" => TRUE ));
            }
            else {
             echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 75, ".."), "node/" . $row['nid']);
            }
          ?>
          </h3></div>
     </div>
   <?php }; ?>
     
</div>

</div>