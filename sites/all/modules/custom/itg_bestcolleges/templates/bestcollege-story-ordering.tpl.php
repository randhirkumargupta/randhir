<div class="watch-right-now-video bestcollege-rhs-video">
<?php 
if (!empty($data)) { 
  global $base_url; 
?>
  
   <h3><span><?php print t("STORY") ?></span></h3><?php // print l('More', 'videos/', array('attributes' => array('class' => 'bestcollege-more-video'))); ?>
    <ul>
        <?php 
        foreach ($data as $video_key => $video_data) { 
        ?>
        <li id="watch-right-now-<?php echo $video_data['nid'] ?>" class="story-right-now-list watch-right-now-<?php echo $video_key; ?>">
        <?php 
          if (!empty($video_data['si_file_uri'])) { 
            $file_uri = file_create_url($video_data['si_file_uri']);
        ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img alt="" title="" src="<?php print $file_uri; ?>" />
            </a>
        <?php
          } else {
        ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img alt="" title="" width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image170x127.jpg' />
            </a>
          <?php 
          
          } 
          if (!empty($video_data['title'])) {  
            echo '<p class="title">' . l(mb_strimwidth($video_data['title'], 0, 140, ".."), "node/" . $video_data['nid']) . '</p>'; 
          } ?>
        </li>
    <?php } ?>
    </ul>
<?php } ?>
</div>





