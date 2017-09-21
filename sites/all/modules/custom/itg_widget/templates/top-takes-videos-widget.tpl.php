<?php if (!empty($data)) : global $base_url; 
$home_top_takes = "home-top-takes";
$is_fron_page = drupal_is_front_page();
?>
  <div class="top-takes-video-container <?php if (!empty($is_fron_page)) { print $home_top_takes; }  ?>">
    <?php    
    if (empty($is_fron_page)) {
      ?><h3><span><?php print t("Top Takes") ?></span></h3><?php } ?>
    <ul>  
        <?php foreach ($data as $video_key => $video_data) { ?>
        <li class="top-takes-video top-takes-list top-takes-<?php echo $video_key ?>">
            <?php if (!empty($video_data['esi_file_uri'])) { ?>
            <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">         
              <?php $extra_large_image_url = image_style_url("widget_very_small", $video_data['esi_file_uri']); ?>
                <img title="<?php echo $video_data['field_story_extra_small_image_title'] ?>" src="<?php print $extra_large_image_url; ?>" alt="<?php echo $video_data['field_story_extra_small_image_alt'] ?>" />
            </a>
            <?php
          }
          else {
            ?>
            <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img height="66" width="88" src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/itg_image88x66.jpg" alt="" />
            </a>
          <?php } ?>
            <?php if (!empty($video_data['title'])) : ?>
            <p title="<?php echo $video_data['title']; ?>" class="title top-takes-<?php echo $video_data['nid'] ?>">
            <?php 
            if(function_exists('itg_common_get_smiley_title')) {
              echo l(itg_common_get_smiley_title($video_data['nid'], 0, 130), "node/" . $video_data['nid'] , array('html' => TRUE , "attributes" => array("title" => $video_data['title']))); 
            }
            else {
              echo l(mb_strimwidth($video_data['title'], 0, 140, ".."), "node/" . $video_data['nid'] , array("attributes" => array("title" => $video_data['title']))); 
            }
            
            ?>
            </p>
        <?php endif; ?>
        </li>
  <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>