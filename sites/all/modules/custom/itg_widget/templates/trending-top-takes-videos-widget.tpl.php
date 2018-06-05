<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
  //p($data);
?>
<style type="text/css">
.videoicon.desktophide{ display:none; }
.trending_top_takes_videos{height: 100%; overflow: hidden; padding: 10px 21px; box-sizing: border-box; border: 1px solid #ccc;}
.trending_top_takes_videos ul.trending-videos{border:0; padding-top:0;}
.trending_top_takes_videos ol.flex-control-paging{display:none;}
.trending_top_takes_videos .flex-direction-nav a{opacity:1;}
.trending_top_takes_videos .flex-nav-prev,.trending_top_takes_videos .flex-nav-next{display: inline-block; background-color:rgba(0,0,0,0.5); width: 40px; height: 64px; border-radius: 0px 35px 35px 0; position:absolute;}
.trending_top_takes_videos .flex-nav-prev{left:0px; top:60px;}
.trending_top_takes_videos .flex-nav-next{right:0px; top:60px;border-radius: 35px 0px 0px 35px;}
.trending_top_takes_videos .flex-direction-nav .flex-nav-next .flex-next{padding-left:10px;}
.trending_top_takes_videos .flex-direction-nav{position: absolute;top: 0;width: 100%;}
.trending_top_takes_videos .flex-direction-nav .flex-next{right:0; position:static;line-height: 64px;}
.trending_top_takes_videos .flex-direction-nav .flex-prev{left:0; position:static;line-height: 64px;}
.trending_top_takes_videos .flex-direction-nav a{display:inline;}
.trending_top_takes_videos .flex-direction-nav a:before{color:#fff;}
.trending_top_takes_videos .trending-videos-flex{position:relative;}
#trending-videos .front .trending-videos .trending-videos-list{padding: 0 0 10px;}
#trending-videos ul li{padding:0px; margin-right:0px!important}
.front .trending-videos li span.videoicon i:before{ color:#323232;font-size:20px; }
.front .trending-videos li span.videoicon{color:#323232; font-size:14px; line-height:20px}
@media only screen and (min-width: 320px) and (max-width: 767px) {
.video-icon.mobilehide{ display:none; }
.video-icon.desktophide{ display:inline-block; }
.trending_top_takes_videos .flex-direction-nav a{opacity:0;}
.trending_top_takes_videos .flex-nav-prev,.trending_top_takes_videos .flex-nav-next{display: none;}
.trending_top_takes_videos{ border:0px; }
.trending_top_takes_videos ul.trending-videos li{box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24); -webkit-box-shadow: 0 1px 3px rgba(0,0,0,0.12), 0 1px 2px rgba(0,0,0,0.24);}
#trending-videos ul li{padding:0px; margin-right:15px!important;border-radius: 5px;}
#trending-videos ul li p{ padding:10px;}
.front .trending-videos li span.videoicon i:before {color: #fff; font-size:18px;}
.front .trending-videos li span.videoicon{padding:3px 5px 1px; background:rgba(0,0,0,0.6); color:#fff; font-size:14px; line-height:20px; position: absolute; bottom:0;}
}

</style>
<div class="trending-videos-flex" id="trending-videos">
  <ul class="trending-videos slides">
    <?php foreach ($data as $entity) {?>
      <li <?php echo $data_tb_region_item;?> class="<?php print $entity['type'] ?> trending-videos-list">
        <?php if (!empty($entity['mi_file_uri']) && file_exists($entity['mi_file_uri'])) { ?>            
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/".$entity['nid']); ?>">
            <?php print theme('image', array('path' => $entity['mi_file_uri'], 'alt' => $entity['field_story_medium_image_alt'], 'title' => $entity['field_story_medium_image_title'])); ?>
            <span class="videoicon desktophide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
          </a>
          <?php
        }
        else {
          ?>
          <a class="pic" href="<?php print $base_url . '/' . drupal_get_path_alias("node/" . $entity['nid']); ?>">
            <img src="<?php print file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image370x208.jpg');?>" alt="" title="" />
            <span class="videoicon desktop-hide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
          </a>
        <?php } ?>
        <p title="<?php echo $entity['title']; ?>">
        <?php if (!empty($entity['title'])) : ?>
          <?php echo l(itg_common_get_smiley_title($entity['node_obj'], 0, 120, ".."), "node/" . $entity['nid'] , array("attributes" => array("title" => _widget_title($entity['title'])))) ?>
        <?php endif; ?>
        </p>
        <span class="videoicon mobilehide"><i class="fa fa-play-circle-o" aria-hidden="true"></i> <?php if (!empty($entity['field_video_duration_value'])) { echo $entity['field_video_duration_value']; } ?></span>
      </li>
    <?php } ?>
  </ul>
</div>
<?php else : ?>
  <span class="no-result-found"><?php print t("Content Not Found") ?></span>
<?php endif; ?>
