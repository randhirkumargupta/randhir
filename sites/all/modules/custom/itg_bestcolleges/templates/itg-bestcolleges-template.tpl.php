<?php
/**
 * @file : itg-bestcolleges-template.tpl.php
 */
$comment_value = variable_get('COMMENT_CONFIG');
$config_name = $comment_value[0]->config_name;
?>
<?php global $base_url;?>

<div class="row">
<div class="col-md-12 col-sm-12 col-xs-12 left-panel arts">
<!-- Slider Start-->
<?php $term = taxonomy_term_load(arg(3));?>
<h2><?php print "INDIA'S BEST ". $term->name ." COLLEGES ".arg(1); ?></h2>
<div class="slider_outer1">
<div id="myCarousel" class="carousel slide" data-ride="carousel">
    <!-- Indicators -->


    <!-- Wrapper for slides -->
    <div class="carousel-inner" role="listbox">

            <?php
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_2'))) {
                    print views_embed_view('best_college_image_slider', 'block_2');
                }

              ?>

  <div class="clearfix"></div>
    </div>

  </div>
</div>

<!-- Related story start-->
<?php
$related_story_value = bestCollegesRelatedStoryList();
if(isset($related_story_value['relatedstory_count']) && $related_story_value['relatedstory_count'] > 0){
    unset($related_story_value['relatedstory_count']);
// Related story block start here

?>

<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("MORE STORIES ") ; ?></div>



</div>
<div class="col-sm-12 related-story-list">
    <div class="row">
    <div class="clearfix">
    <?php
     foreach ($related_story_value as $key => $value){

         ?>


         <div class="midstoryleft">
           <a href="<?php print $base_url; ?>/node/<?php print $value['nid']; ?>" target="_blank"><img alt="" title="" src="http://media2.intoday.in/indiatoday/images/stories/bc-arts-jun29-1_180_061915094528.jpg" width="125" align="left" height="93"></a>
           <div class="midstorydetail">
               <div class="midstorytitle"><a href="<?php print $base_url; ?>/node/<?php print $value['nid']; ?>" target="_blank"><?php print $value['title']; ?></a>
               </div>
               <div class="midstoryintro"><?php print $value['title']; ?></div>
           </div>
         </div>


    <?php

     }
    ?>
    </div>
        </div>

</div>

<?php
} // Related story block end here
?>
<!-- Related story end-->

<!-- Slider End-->
<div class="clearfix"></div>
<!-- Grid View-->
<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Best of The Best ") . arg(1);; ?></div>

        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
            <a href="#" class="btn btn-default btn-sm list"><span class="fa fa-th-list"></span> List</a>
            <a href="#" class="btn btn-default btn-sm active_btn grid"><span class="fa fa-th"></span> Grid</a>
        </div>
        </div>
</div>

<div>
<div class="clearfix"></div>
<div class="col-sm-12 remove_padd_right">
<div class="row list-group college">
      <div class="clr_chn right_align_bestcollege" >


            <?php
               $url_get = explode('/',$_SERVER['REQUEST_URI']);
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_1', $url_get[2]))) {
                    print views_embed_view('best_college_image_slider', 'block_1', $url_get[2]);
                }
            ?>



            </div>
        </div>
</div>
</div>
</div>

<!-- Right Side -->


<!-- code for like dislike -->

  <?php
      $get_val = '0' . arg(1);
      $get_val = '844705';
      if (function_exists('itg_flag_get_count')) {
        $like = itg_flag_get_count($get_val, 'like_count');
        $dislike = itg_flag_get_count($get_val, 'dislike_count');
      }
      if (!empty($like['like_count'])) {
        $like_count = $like['like_count'];
      }
      if (!empty($dislike['dislike_count'])) {
        $dislike_count = $dislike['dislike_count'];
      }
      $pid = "voted_" . $get_val;
      $like = "no-of-likes_" . $get_val;
      $dislike = "no-of-dislikes_" . $get_val;
  ?>

    <!--- Like Dis-Like -->
    <div class="agbutton story-like-dislike">
        <div id="name-dv">
            <?php print t('Do You Like This Story'); ?>
                <span id="lky">
                    <button title="Like" id="like_count" rel="<?php print $get_val; ?>" data-tag="sty">
                        <i class="fa fa-thumbs-o-up"></i>
                        <span id="<?php print $like; ?>"><?php print $like_count; ?></span>
                    </button>
                </span>
                <span id="dlky">
                    <button title="Dislike" id="dislike_count" rel="<?php print $get_val; ?>" data-tag="dsty">
                        <i class="fa fa-thumbs-o-down"></i>
                        <span id="<?php print $dislike; ?>"><?php print $dislike_count; ?></span>
                    </button>
                </span>
        </div>
    </div>
    <!--- End Like Dis-Like -->
 <!-- code for like dislike -->

<!-- Grid View End-->

    <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

    </div>

</div>
