 <div class="osscar-video">
     <ul class="">  
<?php 
global $base_url;
foreach($rows as $index => $row){
    $desc=$row['title'];
   
   
    ?>
         <li class="dont-miss-listing">
             <div class="dm-pic"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}");?>" class="pic"> <?php if($row['field_story_small_image'] != "") {
                print $row['field_story_small_image'];
            } else {
                print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt='' />";
            }?></a> <span><i class="fa fa-play-circle"></i> <?php echo $row['field_video_duration'];?></span></div>
            
            <div class="dm-detail"  title="<?php print $row['title'] ; ?>"><?php 
      if (function_exists('itg_common_get_smiley_title')) {
        echo l(itg_common_get_smiley_title($row['nid'], 0, 90), "node/" . $row['nid'], array("html" => TRUE ));
      }
      else {
       echo l(mb_strimwidth(strip_tags($desc), 0, 100, ".."), "node/" . $row['nid']);
      }
    ?></div>       
   </li>


<?php }; ?>
       </ul>
 </div>