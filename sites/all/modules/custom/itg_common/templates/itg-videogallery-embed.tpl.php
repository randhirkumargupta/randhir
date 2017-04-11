<?php if(function_exists('itg_common_get_node_title') && !empty($_GET['gid'])) {
  $title = itg_common_get_node_title($_GET['gid']);
  $videoids = $data;
 } ?>
<h1><?php print $title; ?></h1>
<div class="itg-embed-photo-wrapper">
<?php
    if (!empty($videoids)) {
        $hide_player = "";
        $newimageds = '<div class="itg-embed-photo-thumb"><ul class="itg-embed-photo-thumb-slider">';
        ?>
        <div class="itg-embed-photo"><ul class="itg-embed-photo-slider">
        <?php foreach ($videoids as $keys => $video_value) {
            if ($keys != 0) {
                $hide_player = 'hide-player';
            }
            
            ?> <?php
              if (module_exists('itg_videogallery')) {
                  $vid = itg_videogallery_get_videoid($row['fid']);
              }
              if ($video_value->solr_video_thumb != "") {
                  $newimageds.= '<li><img data-tag="video_' . $video_value->solr_video_id . '" src="' . $video_value->solr_video_thumb . '" height="66" width="88" alt=""></li>';
              }
              else {
                  $newimageds.= '<li><img data-tag="video_' . $video_value->solr_video_id . '" src="' . $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/itg_image88x66.jpg" height="66" width="88" alt=""></li>';
              }
              $ads_flag = 0;
              if ($video_value->field_include_ads_value == 'yes') {
                  $ads_flag = 1;
              }
              ?>
            <li><div class="<?php echo $hide_player; ?>" id="video_<?php echo $video_value->solr_video_id; ?>"><div class="iframe-video"><iframe frameborder="0" scrolling="no" src="https://www.dailymotion.com/embed/video/<?php print $video_value->video_id; ?>?autoplay=0&ui-logo=1&mute=1&endscreen-enable=<?php echo $ads_flag; ?>&ui-start-screen-info" allowfullscreen></iframe></div></div>  
              
            <?php
            echo '<div class="embed-desc" id="video_dec_' . $video_value->solr_video_id . '" >'.  ucfirst($video_value->field_videogallery_description_value).'</div></li>';
        }
        ?>
        </ul>
        </div>
        <?php $newimageds.='</ul></div>';
    }
    ?>
  
<?php
                    if (!empty($videoids) && count($videoids) > 1) {
                        print $newimageds;
                    }
                    ?>


</div>


<style>
  .page-videogallery-embed{background-color: #171717;}
  h1{font-size: 32px; margin: 25px 0; color: #fff; text-align: center;}
  .itg-embed-photo-wrapper{padding: 10px; background-color: #000; max-width: 773px; margin: 0 auto;}
  .itg-embed-photo-thumb{margin-top: 10px;}
  .itg-embed-photo-thumb .slick-slide{outline: none;}
  .itg-embed-photo-thumb img{width: 88px; max-width: 100%; height: 66px; border: 1px solid #000; outline: none;}
  .itg-embed-photo-thumb .slick-current img{border-color: #fff;}
  .embed-desc{color: #fff; padding: 5px 0 0;}
  .itg-embed-photo-slider .slick-next, .itg-embed-photo-slider .slick-prev {
    cursor: pointer;
    width: 50px;
    height: 100px;
    background-color: rgba(255, 255, 255, 0.3);
    font-size: 0;
    position: absolute;
    top: 0;
    bottom: 0;
    margin: auto 0;
    z-index: 9;
    border: none;
  }
  .itg-embed-photo-slider .slick-next{
    border-radius: 90px 0px 0px 90px;
    right: 0;
  }
  .itg-embed-photo-slider .slick-prev {
    border-radius: 0 90px 90px 0;
    left: 0;
  }
  .itg-embed-photo-slider .slick-prev:hover, .itg-embed-photo-slider .slick-next:hover {background-color: rgba(255, 255, 255, 0.6);}
  .itg-embed-photo-slider .slick-next:before, .itg-embed-photo-slider .slick-prev:before {
    font: normal normal normal 32px/100px FontAwesome;
    position: absolute;
    top: 0;
    color: #666;
  }
  .itg-embed-photo-slider .slick-next:before{
    content: '\f054';
    right: 5px;
  }
  .itg-embed-photo-slider .slick-prev:before {
    content: '\f053';
    left: 5px;
  }
  .itg-embed-photo-thumb-slider{
    padding: 0 40px;
  }
  .itg-embed-photo-thumb-slider .slick-next, .itg-embed-photo-thumb-slider .slick-prev {
    cursor: pointer;
    width: 40px;
    height: 66px;
    font-size: 0;
    position: absolute;
    top: 0;
    z-index: 9;
    border: none;
    background-color: #000;
  }
  .itg-embed-photo-thumb-slider .slick-next{left: 0;}
  .itg-embed-photo-thumb-slider .slick-prev{right: 0;}
  .itg-embed-photo-thumb-slider .slick-next:before, .itg-embed-photo-thumb-slider .slick-prev:before {
    font: normal normal normal 32px/66px FontAwesome;
    position: absolute;
    top: 0;
    color: #fff;
  }
  .itg-embed-photo-thumb-slider .slick-next:before{content: '\f053'; left: 10px;}
  .itg-embed-photo-thumb-slider .slick-prev:before{content: '\f054'; right: 10px;}
</style>
<script>
  jQuery(document).ready(function (e) {
    jQuery('.itg-embed-photo-slider').slick({
      slidesToShow: 1,
      slidesToScroll: 1,
      adaptiveHeight: true,
      arrows: true,
      fade: false,
      asNavFor: '.itg-embed-photo-thumb-slider'
    });
    jQuery('.itg-embed-photo-thumb-slider').slick({
      slidesToShow: 7,
      slidesToScroll: 1,
      asNavFor: '.itg-embed-photo-slider',
      dots: false,
      centerMode: false,
      arrows: true,
      focusOnSelect: true,
      responsive: [
        {
          breakpoint: 1024,
          settings: {
            slidesToShow: 7,
            slidesToScroll: 1,
            arrows: false
          }
        },
        {
          breakpoint: 600,
          settings: {
            slidesToShow: 4,
            arrows: false,
            slidesToScroll: 1
          }
        },
        {
          breakpoint: 480,
          settings: {
            slidesToShow: 3,
            arrows: false,
            slidesToScroll: 1
          }
        }
      ]
    });
  });
</script>