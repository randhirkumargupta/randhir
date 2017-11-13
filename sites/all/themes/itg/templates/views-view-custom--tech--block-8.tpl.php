 <div class="techwatch osscar-video">
     <ul class="">  
<?php foreach($rows as $index => $row){
    $desc=$row['title'];
   
    if (!empty($row['field_story_small_image'])) {
                $img = $row['field_story_small_image'];
            }
            else {
                global $base_url;
                $img = "<img width='170' height='127'  src='" . file_create_url(file_build_uri(drupal_get_path('theme', 'itg') . '/images/itg_image170x127.jpg')) ."' alt='' title='' />";
            }
    ?>
         <li class="dont-miss-listing">
             <div class="dm-pic"><a href="#" class="pic"><?php print $img;?></a> <span><i class="fa fa-play-circle"></i> <?php echo $row['field_video_duration'];?></span></div>
            
             <div class="dm-detail" title="<?php echo strip_tags($desc);?>">
            <?php
              if (function_exists('itg_common_get_smiley_title')) {
                echo l(itg_common_get_smiley_title($row['nid'], 0, 140), "node/" . $row['nid'], array("html" => TRUE));
              }
              else {
                echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 150, ".."), "node/" . $row['nid']);
              }
              ?>
            </div>       
   </li>


<?php }; ?>
       </ul>
 </div>