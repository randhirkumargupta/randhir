<?php
/**
 * @file : itg-bestcolleges-template.tpl.php
 */
$comment_value = variable_get('COMMENT_CONFIG');
$config_name = $comment_value[0]->config_name;
$arg = arg();
?>
<?php global $base_url;?>

<div class="row">
<div class="col-md-12 col-sm-12 col-xs-12 left-panel arts">
<!-- Slider Start-->
<?php $term = taxonomy_term_load(arg(3));?>
<h2><?php print "INDIA'S BEST ". strtoupper($term->name) ." COLLEGES ".arg(1); ?></h2>
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


<!-- ranking-section start-->
<?php
    $page_data = bestCollegesrank($arg);
    if(isset($page_data['flag-rank']) && (is_array($page_data['previous-rank']) && count($page_data['previous-rank']) > 0) && (is_array($page_data['parameterwise-rank']) && count($page_data['parameterwise-rank']) > 0)){
?>
<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Ranking Section ") ; ?></div>
</div>
<?php
    //$page_data = bestCollegesrank();
    $str_fulldata = "";
    $data_parameterwise_rank = $page_data['parameterwise-rank'];
    $data_previous_rank = $page_data['previous-rank'];


    // parameterwise data string building

    $str_parameterwise_rank = "<div class='wishranking'>
        <div class='midcontitles'>PARAMETER-WISE RANKING <span style='float:right;'></span></div>
        <div class='midmorestories'>
          <ul>
             <li>Reputation: ".$data_parameterwise_rank[0]['reputation']."</li>
             <li>Academic Input: ".$data_parameterwise_rank[0]['academic_input']."</li>
             <li>Student Care: ".$data_parameterwise_rank[0]['studentcare']."</li>
             <li>Infrastructure: ".$data_parameterwise_rank[0]['infrastructure']."</li>
             <li>Placement: ".$data_parameterwise_rank[0]['placement']."</li>
             <li>Perceptual Rank: ".$data_parameterwise_rank[0]['preceptual_rank']."</li>
             <li>Factual Rank: ".$data_parameterwise_rank[0]['factual_rank']."</li>

          </ul>
        <div class='clear'></div>
        </div>
      </div>";

    // yearwisewise data string building

    $str_yearwise_rank= "<div class='prvlink'>
	<div class='prvarrtxt'>PREVIOUS RANKING:</div>
    <div class='prvyrs'>
	 <ul>";

    foreach ($data_previous_rank as $key => $value){
        $year = $value['year'];
        $rank = $value['rank'];
        $str_yearwise_rank .= "<li>".$year." - <span>".$rank."</span></li>";
    }
    $str_yearwise_rank .= "</ul></div></div>";

    $str_fulldata = "<div class='col-sm-12 ranking-section'><div class='ranking-section'>".$str_parameterwise_rank." ".$str_yearwise_rank."</div></div>";
    print $str_fulldata;
    }
?>
<!-- ranking-section end-->

<!-- Related image start-->
<?php
$related_image_value = bestCollegesRelatedImgList();
if(isset($related_image_value['relatedimg_count']) && $related_image_value['relatedimg_count'] > 0){
    unset($related_image_value['relatedimg_count']);
?>

<div class="col-sm-12 col-xs-12 view1 related-img-head">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("MORE IMAGES ") ; ?></div>



</div>
<div class="col-sm-12 related-story-list related-img-body">
    <div class="row">
    <div class="clearfix">
    <?php
     foreach ($related_image_value as $key => $value){
         //$img_ob = file_load($value['field_story_small_image_fid']);

         $file = file_load($value['field_story_large_image_fid']);

         ?>

                <div class="midstoryleft">
                    <a href="<?php print $base_url; ?>/node/<?php print $value['nid']; ?>" target="_blank"><img alt="" title="" src="<?php print file_create_url($file->uri); ?>" width="125" align="left" height="93"></a>
                    <div class="midstorydetail">
                      <div class="midstoryintro"><a href="<?php print $base_url; ?>/node/<?php print $value['nid']; ?>" target="_blank"><?php print $value['title']; ?></a></div></div>
                </div>
    <?php

     }
    ?> </div>
        </div>

</div>

<?php
}
?>

<!-- Related image end-->



<!-- Slider End-->
<div class="clearfix"></div>
<!-- Grid View-->
<div class="col-sm-12 col-xs-12 view1">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Best of The Best ") . arg(1);; ?></div>

        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
           <a href="#" class="btn btn-default btn-sm grid"><span class="fa fa-th"></span> Grid</a>
            <a href="#" class="btn btn-default btn-sm active_btn list"><span class="fa fa-th-list"></span> List</a>

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
<div class="col-sm-12 col-xs-12 col-md-12">
  <?php
      // get global comment config
      //$config_name = trim($global_comment_last_record[0]->config_name);
      $config_name = 'vukkul';
      if($arg && $arg[0] == "bestcolleges") {
        $term_name = "Bestcolleges " . $arg[1];
        $term_data = taxonomy_get_term_by_name($term_name);
      }
      $tid = array_pop($term_data)->tid;

      $get_val = $tid;
      if (function_exists('itg_flag_get_count')) {
        $like = itg_flag_get_count($get_val, 'like_count');
        $dislike = itg_flag_get_count($get_val, 'dislike_count');
      }

      $like_count_like = $like['like_count'] + $migrated_count[0]['like_count'];
      $dislike_count_like = $dislike['dislike_count'] + $migrated_count[0]['dislike_count'];

      $pid = "voted_" . $get_val;
      $like = "no-of-likes_" . $get_val;
      $dislike = "no-of-dislikes_" . $get_val;
  ?>

    <!--- Like Dis-Like -->
     <div class="agbutton story-like-dislike">
          <div id="name-dv"><?php print t('Do You Like This Bestcolleges'); ?>
            <span id="lky"><button title="Like" id="like_count" rel="<?php print $get_val; ?>" data-tag="sty"><i class="fa fa-thumbs-o-up"></i> <span id="<?php print $like; ?>"><?php print $like_count_like; ?></span> </button>
              <span id="sty-dv" style="display:none">Awesome! </br> Now share the story </br> <a title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a>
                <a title="share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
                <a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>
                <?php
                if ($config_name == 'vukkul') {
                  ?>
                  <a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                <?php } if ($config_name == 'other') { ?>
                  <a onclick ="scrollToAnchor('other-comment');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                <?php } ?>
              </span></span>
            <span id="dlky"> <button title="Dislike" id="dislike_count" rel="<?php print $get_val; ?>" data-tag="dsty"><i class="fa fa-thumbs-o-down"></i> <span id="<?php print $dislike; ?>"><?php print $dislike_count_like; ?></span></button>
              <?php
              if ($config_name == 'vukkul') {
                ?>
                <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><?php print t('comments'); ?></a></span>

              <?php } if ($config_name == 'other') { ?>
                <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><?php print t('comments'); ?></a></span>
              <?php } ?>

            </span>
          </div>
          <p class="error-msg" id="<?php print $pid; ?>"></p>
        </div>

    <!--- End Like Dis-Like -->
</div>
<!-- Grid View End-->

      <?php
        if (function_exists('taboola_view')) {
          //taboola_view();
        }
        ?>

        <?php
        if ($config_name == 'vukkul') {
          if (!empty($node->field_story_comment_question['und'][0]['value'])) {
            $question = 'Q:' . $node->field_story_comment_question['und'][0]['value'];
          }
          ?>
          <div class="c_ques"><?php print $question; ?></div>
          <div class="vukkul-comment">
            <div id="vuukle-emote"></div>
            <div id="vuukle_div"></div>

            <?php
            if (function_exists('vukkul_view')) {
              vukkul_view();
            }
            ?>

          </div>
          <?php
        }
        if ($config_name == 'other' && in_array('comment', $config)) {
          ?>
          <div id="other-comment">
            <?php
            $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
            print render($block['content']);
            ?>
          </div>
        <?php }
        ?>

</div>
