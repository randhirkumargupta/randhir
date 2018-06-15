<?php if (!empty($data)) : global $base_url; 
$home_top_takes = "home-top-takes";
$is_fron_page = drupal_is_front_page();
$data_tb_region_item = '';
if($is_fron_page){
  $data_tb_region_item = 'data-tb-region-item';  
}
?>
  <div class="top-takes-videos-flex <?php if (!empty($is_fron_page)) { print $home_top_takes; }  ?>" id="trending-videos">
    <?php    
    if (empty($is_fron_page)) {
      ?><h3><span><?php print t("Top Takes") ?></span></h3><?php } ?>
    <ul class="trending-videos slides">  
        <?php foreach ($data as $video_key => $video_data) { ?>
        <li <?php echo $data_tb_region_item;?> class="trending-videos-list top-takes-<?php echo $video_key ?>">
            <?php if (!empty($video_data['mi_file_uri'])) { ?>
            <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">         
              <?php //$extra_large_image_url = image_style_url("widget_very_small", $video_data['mi_file_uri']); ?>
              <?php print theme('image', array('path' => $video_data['mi_file_uri'], 'alt' => $video_data['field_story_medium_image_alt'], 'title' => $video_data['field_story_medium_image_title'])); ?>
              <span class="videoicon desktophide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
            </a>
            <?php
          }
          else {
            ?>
            <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img height="66" width="88" src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');?>" alt="" title="" />
              <span class="videoicon desktophide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
            </a>
          <?php } ?>
            <?php if (!empty($video_data['title'])) : ?>
            <p title="<?php echo $video_data['title']; ?>" class="top-takes-<?php echo $video_data['nid'] ?>">
            <?php 
            if(function_exists('itg_common_get_smiley_title')) {
              echo l(itg_common_get_smiley_title($video_data['node_obj'], 0, 130), "node/" . $video_data['nid'] , array('html' => TRUE , "attributes" => array("title" => _widget_title($video_data['title'])))); 
            }
            else {
              echo l(mb_strimwidth($video_data['title'], 0, 140, ".."), "node/" . $video_data['nid'] , array("attributes" => array("title" => $video_data['title']))); 
            }            
            ?>
            </p>
        <?php endif; ?>
        <span class="videoicon mobilehide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($video_data['field_video_duration_value'])) { echo $video_data['field_video_duration_value']; } ?></span>
        </li>
  <?php } ?>
    </ul>
  </div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
