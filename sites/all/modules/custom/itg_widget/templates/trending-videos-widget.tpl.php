<?php if (!empty($data)) : global $base_url; ?>
<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
<style type="text/css">
.home-trending-video .itg-widget-child.tab-data{border-left: 1px solid #ddd;border-right: 1px solid #ddd;border-bottom: 1px solid #ddd;}
.home-trending-video #trending-videos .trending-videos{border:0px;}
.home-trending-video #trending-videos{ padding:10px; position: relative;}
.home-trending-video #trending-videos ul li{padding:0px; margin-right:0px!important}
.home-trending-video #trending-videos .trending-videos li span.videoicon i:before{ color:#323232;font-size:20px; }
.home-trending-video #trending-videos .trending-videos li span.videoicon{color:#323232; font-size:14px; line-height:20px}
.home-trending-video #trending-videos .trending-videos.slides li p{ padding:5px 0 7px; }
.home-trending-video #trending-videos .trending-videos{overflow-x: hidden;}
.home-trending-video #trending-videos .trending-videos li+li{ border-top:0px;}
.home-trending-video #trending-videos .trending-videos .trending-videos-list .pic{ float: none; margin-right:0px; }
.home-trending-video #trending-videos .trending-videos li a.pic:after{ background:transparent; }
.home-trending-video #trending-videos .trending-videos li span.pic.video-icon{position: relative; height: 24px;display: block;float: none;line-height: 23px; margin-top: 10px;}
.home-trending-video #trending-videos .trending-videos li span.pic.video-icon:after{ font: normal normal normal 14px/1 FontAwesome; content:"\f01d"; font-size: 23px; color:#323232; bottom: 0;left: 0;background: transparent;top: 2px;}
.videoicon.desktophide{ display:none; }

.home-trending-video #trending-videos ul.trending-videos{border:0; padding-top:0;}
.home-trending-video #trending-videos ol.flex-control-paging{display:none;}
.home-trending-video #trending-videos .flex-direction-nav a{opacity:1!important;}
.home-trending-video #trending-videos .flex-nav-prev,.home-trending-video #trending-videos .flex-nav-next{display: inline-block; background-color:rgba(0,0,0,0.5); width: 40px; height: 64px; border-radius: 0px 35px 35px 0; position:absolute;}
.home-trending-video #trending-videos .flex-nav-prev{left:0px; top:80px;}
.home-trending-video #trending-videos .flex-nav-next{right:20px; top:80px;border-radius: 35px 0px 0px 35px;}
.home-trending-video #trending-videos .flex-direction-nav .flex-nav-next .flex-next{padding-left:14px;}
.home-trending-video #trending-videos .flex-direction-nav{position: absolute;top: 0;width: 100%;}
.home-trending-video #trending-videos .flex-direction-nav .flex-next{right:0; position:static;line-height: 64px;}
.home-trending-video #trending-videos .flex-direction-nav .flex-prev{left:0; position:static;line-height: 64px;}
.home-trending-video #trending-videos .flex-direction-nav a{display:inline;}
.home-trending-video #trending-videos .flex-direction-nav a:before{color:#fff;}
.home-trending-video #trending-videos .trending-videos-flex{position:relative;}
.home-trending-video #trending-videos .trending-videos .trending-videos-list{padding:0px;}
.home-trending-video #trending-videos ul li{padding:0px; margin-right:0px!important}
@media only screen and (min-width: 768px) and (max-width: 800px) {.home-trending-video h3.desktop-hide{display:none;}}
@media only screen and (min-width: 320px) and (max-width: 767px) {
 .home-trending-video .tab-buttons{ display: none; }
 .home-trending-video h3{text-transform: uppercase; padding: 0 0 0 10px; margin:0px; color: #000;font-size: 16px;font-weight: 600;margin-bottom:0px; height: auto;font-family: "OpenSans-Bold";}
 .home-trending-video .itg-widget-child.tab-data{ display: block!important }
.home-trending-video .videoicon.mobilehide{ display:none; }
.home-trending-video .videoicon.desktophide{ display:inline-block; }
.home-trending-video #trending-videos .flex-direction-nav a{opacity:0!important;}
.home-trending-video #trending-videos .flex-nav-prev,.home-trending-video #trending-videos .flex-nav-next{display: none;}
.home-trending-video #trending-videos ul.trending-videos li{box-shadow: 0 0px 4px rgba(0,0,0,0.24), 0 0px 4px rgba(0,0,0,0.24); -webkit-box-shadow: 0 0px 4px rgba(0,0,0,0.12), 0 0px 4px rgba(0,0,0,0.24); border:1px solid rgba(0,0,0,0.12);}
.home-trending-video #trending-videos ul li{padding:10px 0px 0; margin-right:15px!important;border-radius: 5px; margin-bottom:2px; margin-top:2px; }
.home-trending-video #trending-videos ul li p{ padding: 15px 10px; font-size: 15px; font-family: "OpenSans-regular"; line-height:20px;}
.home-trending-video #trending-videos .trending-videos li span.videoicon i:before {color: #fff; font-size:18px;}
.home-trending-video #trending-videos .trending-videos li span.videoicon{padding:3px 5px 1px; background:rgba(0,0,0,1); color:#fff; font-size:14px; line-height:20px; position: absolute; bottom:0;}
.home-trending-video #trending-videos .trending-videos.slides li p{padding:7px 10px}
.home-trending-video .itg-widget-child.tab-data{border:0px;}
.home-trending-video #trending-videos{ padding:5px 10px; margin-bottom:15px; }
.home-trending-video #trending-videos .trending-videos .trending-videos-list{min-height:250px;}
.home-trending-video #trending-videos .top_takes_videos_widget h3{ margin-top:20px;}
}

</style>
<h3 class="desktop-hide">Trending Videos</h3>
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
