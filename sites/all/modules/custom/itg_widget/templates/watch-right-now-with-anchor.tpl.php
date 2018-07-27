<div class="watch-right-now-with-anchor">
<div class="watch-right-now-anchor-flex">
  <?php if (!empty($data['wrn_anchors'])) :?>
    <ul class="anchor-list-slide slides">
      <?php 
      $_anchor_count = count( $data['wrn_anchors'] );
      foreach ($data['wrn_anchors'] as $anchor_key => $anchor_video) { 
        $_anchor_url = FRONT_URL . '/' . drupal_get_path_alias("node/" . $anchor_video->nid);
        $_more_link = FRONT_URL . '/anchors-list';
        $_anchor_link = ( $anchor_key !== ($_anchor_count -1) ) ? $_anchor_url : $_more_link;
        ?>
        <li>
          <a  href="<?php print $_anchor_link; ?>" class="pic">     
			<?php print theme('image_style', array('path' => $anchor_video->uri, 'style_name' => 'image170x127', 'alt' => $anchor_video->title, 'title' => $anchor_video->title)); ?>    
            <p><?php print $anchor_video->title;?></p>
          </a>
        </li>
      <?php }?>  
    </ul>
  <?php endif;?>
</div>
<div class="space-15"></div>
<div class="watch-right-now-video">
<span class="widget-title">Watch right now</span>
<?php if (!empty($data['wrn_video'])) : global $base_url; ?>
    <?php $is_fron_page = drupal_is_front_page();
    $data_tb_region_item = '';
    if($is_fron_page){
	  $data_tb_region_item = 'data-tb-region-item';  
    }
    if (empty($is_fron_page)) { ?>
      <h3><span><?php print t("Watch Right Now") ?></span></h3>
    <?php } ?>
    <ul>    
        <?php foreach ($data['wrn_video'] as $video_key => $video_data) { ?>
        <li <?php echo $data_tb_region_item;?> class="watch-right-now-list watch-right-now-<?php echo $video_key ?>">        
    <?php  if (!empty($video_data['esi_file_uri']) && file_exists($video_data['esi_file_uri'])) { ?>
            <a  href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
                <?php //$file_uri = file_create_url($video_data['esi_file_uri']); ?>
              <?php print theme('image', array('path' => $video_data['esi_file_uri'], 'alt' => $video_data['field_story_extra_small_image_alt'], 'title' => $video_data['field_story_extra_small_image_title'])); ?>
            </a>
            <?php
          }
          else {
            ?>
            <a href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $video_data['nid']); ?>" class="pic">
              <img alt="" title="" width='170' height='127'  src='<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg');?>' />
            </a>
          <?php } ?>
            <?php if (!empty($video_data['title'])) : ?>
            <p class="title" title="<?php echo $video_data['title'] ?>">
                <?php 
                if(function_exists('itg_common_get_smiley_title')) {
                  echo l(itg_common_get_smiley_title($video_data['node_obj'], 0, 60), "node/" . $video_data['nid'] , array('html' => TRUE , 'attributes' => array("title" => _widget_title($video_data['title']))));
                } else {
                  echo l(mb_strimwidth($video_data['title'], 0, 70, ".."), "node/" . $video_data['nid'] , array('attributes' => array("title" => $video_data['title'])));
                }
                ?>
            </p>
        <?php endif; ?>
        </li>
    <?php } ?>
    </ul>
  <?php else : ?>
    <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
</div>
</div>
