<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
<style type="text/css">
.fifa-wcup{background: url(https://smedia2.intoday.in/indiatoday/images/fifa-background-bg.jpg) no-repeat center 277px;}
.fifa-wcup #itg-block-1{background-color: #f0f0f0;}
.fifa-wcup .sport-home-layout-page .itg-layout-615 .droppable{height: auto;}
.fifa-wcup .sport-home-layout-page .itg-layout-615 .auto-block-1{background: none; border:0; }
.fifa-wcup .featured-post{position: relative;}
.fifa-wcup .featured-post h3{position: absolute; bottom: 17px; left: 17px;}
 
.fifa-wcup .movies-featured-post {background-color: #313131;padding: 15px 5px;}
.fifa-wcup .movies-featured-post img{width: 88px;height: 50px;float: left;margin-right: 8px;}
.fifa-wcup .movies-featured-post h3{font-size: 13px;line-height: 16px;color: #fff;display: block;}
.fifa-wcup .movies-featured-post h3 a{color: #fff;}
.fifa-wcup .movies-featured-post:hover{background-color: #a00606;}

.fifa-wcup .headingtext{display: inline-block; width: 100%;}
.fifa-wcup .headingtext .round01{width: 12px; height: 12px; background-color: #a10506; display: inline-block;}
.fifa-wcup .headingtext .round02{width: 10px; height: 10px; background-color: #a10506; display: inline-block; margin: 0 3px;}
.fifa-wcup .headingtext .round03{width: 7px; height: 7px; background-color: #a10506; display: inline-block;}
.fifa-wcup .headingtext h2{font-size: 15px; line-height: 20px; color: #000; text-transform: uppercase;}

</style>
<div class="row">
    <div class="col-md-8">
        <div class="auto-block-1">
            <div class="featured-news">
                <?php
                global $base_url;
                foreach ($data as $index => $row) {
                  $desc = $row['title'];
                  if (function_exists('itg_common_remove_extra_html')) {
                    $desc = itg_common_remove_extra_html($desc);
                  }
                  $video_class = "";
                  if (strtolower($row['type']) == 'videogallery') {
                    $video_class = 'video-icon';
                  }
                  if ($index == 0) {
                    ?>
                    <div class="featured-post featured-post-first <?php echo $video_class; ?>">
                      
                      <h2>Football follows cricket: FIFA proposes mini - World cup every 2 years, just like world</h2>

                        <?php if ($row['uri'] != "") { ?>
                          <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>">
                              <img src="<?php print image_style_url("magazine_top_story_483x271", $row['uri']); ?>" alt="<?php echo $row['field_story_extra_large_image_alt']; ?>" title="<?php echo $row['field_story_extra_large_image_title']; ?>" />
                          </a>
                        <?php
                        }
                        else {
                          print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image483x271.jpg' />";
                        }
                        ?>
                        <h3 <?php echo $data_tb_region_item;?> title="<?php echo strip_tags($desc); ?>">
                            <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($row['node_obj'], 0, 68), "node/" . $row['nid'], array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(strip_tags($desc), 0, 70, ".."), "node/" . $row['nid']);
                            }
                            ?>
                        </h3>           
                    </div>
                  <?php } ?>
            <?php } ?>
            </div>
        </div>    
    </div>
    <!-- -->
    <div class="col-md-4">
        <div class="auto-block-2">
            <div class="movies-featured-news">
              





                <?php
                foreach ($data as $index => $row) {
                  $video_class = "";
                  if (strtolower($row['type']) == 'videogallery') {
                    $video_class = 'video-icon';
                  }
                  if ($index > 0 && $index <= 2) {
                    ?>				
                    <div class="movies-featured-post <?php echo $video_class; ?>">
                        <?php if ($row['mi_file_uri'] != "") { ?>
                          <a  href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>">
                              <img src="<?php print image_style_url("home_page_feature_small", $row['mi_file_uri']); ?>" alt="<?php echo $row['field_story_medium_image_alt']; ?>" title="<?php echo $row['field_story_medium_image_title']; ?>" />
                          </a>
                        <?php
                        }
                        else {
                          print "<img  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/itg_image237x133.jpg' />";
                        }
                        ?>
                        <h3 <?php echo $data_tb_region_item;?> title="<?php echo strip_tags($desc); ?>">
                            <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($row['node_obj'], 0, 80), "node/" . $row['nid'], array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(strip_tags($desc), 0, 85, ".."), "node/" . $row['nid']);
                            }
                            ?>
                        </h3>
                    </div>
                  <?php
                  }
                }
                ?>
            </div>
        </div>
    </div>
    <!-- -->
</div>

