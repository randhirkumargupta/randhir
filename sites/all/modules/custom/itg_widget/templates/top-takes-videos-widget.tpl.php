<?php if (!empty($data)) : global $base_url; 
$home_top_takes = "home-top-takes";
$is_fron_page = drupal_is_front_page();
$data_tb_region_item = '';
if($is_fron_page){
  $data_tb_region_item = 'data-tb-region-item';  
}
?>
<style type="text/css">
.front .trending_top_takes_videos .trending-videos{overflow-x: hidden;}
.front .trending_top_takes_videos .trending-videos .trending-videos-list{padding: 0 10px 10px;}
.front .trending_top_takes_videos .trending-videos li+li{ border-top:0px;}
.trending_top_takes_videos .trending-videos .trending-videos-list .pic{ float: none; margin-right:0px; }
.front .trending_top_takes_videos .trending-videos li a.pic:after{ background:transparent; }
.front .trending_top_takes_videos .trending-videos li span.pic.video-icon{position: relative; height: 24px;display: block;float: none;line-height: 23px; margin-top: 10px;}
.front .trending_top_takes_videos .trending-videos li span.pic.video-icon:after{ font: normal normal normal 14px/1 FontAwesome; content:"\f01d"; font-size: 23px; color:#323232; bottom: 0;left: 0;background: transparent;top: 2px;}
.videoicon.desktophide{ display:none; }
.trending_top_takes_videos{height: 100%; overflow: hidden; padding: 10px 21px; box-sizing: border-box; border: 1px solid #ccc;}
.trending_top_takes_videos ul.trending-videos{border:0; padding-top:0;}
.trending_top_takes_videos ol.flex-control-paging{display:none;}
.trending_top_takes_videos .flex-direction-nav a{opacity:1!important;}
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
.front #trending-videos .trending-videos .trending-videos-list{padding: 0 0 10px;}
#trending-videos ul li{padding:0px; margin-right:0px!important}
.front #trending-videos .trending-videos li span.videoicon i:before{ color:#323232;font-size:20px; }
.front #trending-videos .trending-videos li span.videoicon{color:#323232; font-size:14px; line-height:20px}
.front #trending-videos .trending-videos.slides li p{ padding-bottom: 7px; }
@media only screen and (min-width: 320px) and (max-width: 767px) {
.videoicon.mobilehide{ display:none; }
.videoicon.desktophide{ display:inline-block; }
.trending_top_takes_videos .flex-direction-nav a{opacity:0!important;}
.trending_top_takes_videos .flex-nav-prev,.trending_top_takes_videos .flex-nav-next{display: none;}
.trending_top_takes_videos{ border:0px;padding: 10px 15px; }
.trending_top_takes_videos ul.trending-videos li{box-shadow: 0 0px 4px rgba(0,0,0,0.24), 0 0px 4px rgba(0,0,0,0.24); -webkit-box-shadow: 0 0px 4px rgba(0,0,0,0.12), 0 0px 4px rgba(0,0,0,0.24); border:1px solid rgba(0,0,0,0.12);}
#trending-videos ul li{padding:10px 0px 0; margin-right:15px!important;border-radius: 5px; margin-bottom:2px; margin-top:2px; }
#trending-videos ul li p{ padding: 15px 10px; font-size: 15px; font-family: "OpenSans-regular"; line-height:20px;}
.front .trending-videos li span.videoicon i:before {color: #fff; font-size:18px;}
.front .trending-videos li span.videoicon{padding:3px 5px 1px; background:rgba(0,0,0,0.6); color:#fff; font-size:14px; line-height:20px; position: absolute; bottom:0;}
}

</style>
  <div class="top-takes-videos-flex <?php if (!empty($is_fron_page)) { print $home_top_takes; }  ?>" id="trending-videos">
    <?php    
    if (empty($is_fron_page)) {
      ?><h3><span><?php print t("Top Takes") ?></span></h3><?php } ?>
    <ul class="top-takes-videos slides">  
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
