<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
	$data_tb_region_item = 'data-tb-region-item';  
  }
?>
<style type="text/css">
.fifa-wcup .fifa-top-story{background-color: #f0f0f0; display: inline-block; padding-bottom: 20px; width: 100%;}
.fifa-wcup .fifa-top-story img{width: 88px; height: 49px; float: left; margin-right: 5px;}
.fifa-wcup .fifa-top-story h3{font-size: 14px; line-height: 20px; display: block;}
.fifa-wcup .fifa-post{float: left; width: 50%; padding:20px 10px 0; box-sizing:border-box;}
.fifa-wcup h2.widget-title{background: url(https://smedia2.intoday.in/indiatoday/images/hdot.jpg) no-repeat 0 6px; font-size: 20px; line-height: 24px; color: #000; padding-left: 47px;}
</style>
<div class="row">
    <div class="col-md-12">
        <div class="auto-block-1">
            <div class="fifa-top-story">
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
                    ?>
                    <div class="fifa-post fifa-post-first <?php echo $video_class; ?>">
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
            </div>
        </div>    
    </div>
</div>

