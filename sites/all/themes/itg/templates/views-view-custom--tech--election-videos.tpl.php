 <div class="techwatch osscar-video">
     <ul class="">  
<?php foreach($rows as $index => $row){
    $desc=$row['title'];
   global $base_url;
    if (!empty($row['field_story_small_image'])) {
                $img = $row['field_story_small_image'];
            }
            else {
                global $base_url;
                $img = "<img src='" . FRONT_URL . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image88x50.jpg" ."' alt='' title='' />";
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
<script>
<?php
$arg = arg();
if ($arg[2] == 'constituency' || $arg[2] == 'constituency-map' || ($arg[0] == 'refresh_election_view_block')) {
?>
jQuery(document).ready(function(){
  var refresh_time = "<?php echo (!empty(get_itg_variable('election_blocks_refreshtime')) ? get_itg_variable('election_blocks_refreshtime') : '60000'); ?>";
  if (refresh_time === undefined){
    refresh_time = 60000;
  }
  <?php
  global $theme;
  if (isset($_GET['category']) && !empty($_GET['category'])) {
    $selction_name = 'category';
  }
  else {
    $selction_name = 'section';
  }
  if (isset($_GET[$selction_name])) {
    $cat_id = $_GET[$selction_name];
  }
  if ($theme == FRONT_THEME_NAME && is_numeric(arg(2)) && arg(0) != 'refresh_election_view_block') {
    $cat_id = arg(2);              
  }
  $jsonUrl = $base_url . '/refresh_election_view_block/tech/election_videos/'.$cat_id;
  ?>
  var jsonUrl = "<?php echo $jsonUrl;?>";
  setTimeout(function(){
       refresh_election_view_blocks(jsonUrl, 'tech', 'election_videos', refresh_time); 
    }, refresh_time);
});
<?php }?>
</script>
