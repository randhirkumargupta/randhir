<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
  //p($data);
?>
<div class="trending-videos-flex" id="trending-videos">
  <ul class="trending-videos slides">
    <?php foreach ($data as $entity) {?>
      <li <?php echo $data_tb_region_item;?> class="<?php print $entity['type'] ?> trending-videos-list">
        <?php if (!empty($entity['mi_file_uri']) && file_exists($entity['mi_file_uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/".$entity['nid']); ?>">
            <?php print theme('image', array('path' => $entity['mi_file_uri'], 'alt' => $entity['field_story_medium_image_alt'], 'title' => $entity['field_story_medium_image_title'])); ?>
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
            <img src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');?>" alt="" title="" />
          </a>
        <?php } ?>
        <p title="<?php echo $entity['title']; ?>">
        <?php if (!empty($entity['title'])) : ?>
          <?php echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 120, ".."), "node/" . $entity['nid'] , array("attributes" => array("title" => _widget_title($entity['title'])))) ?>
        <?php endif; ?>
        </p>
        <span class="pic video-icon"><?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
      </li>
    <?php } ?>
  </ul>
</div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
