<?php
/**
 * @file : itg-bestcolleges-template.tpl.php
 */
$comment_value = variable_get('COMMENT_CONFIG');
$config_name = $comment_value[0]->config_name;
?>
<?php global $base_url;?>
<meta charset="utf-8">
<title>Untitled Document</title>
<meta name="viewport" content="width=device-width, initial-scale=1">

<div class="row">
<div class="col-md-12 col-sm-7 col-xs-12 left-panel arts">
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
                if (array_filter(views_get_view_result('best_college_image_slider', 'block_1'))) {
                    print views_embed_view('best_college_image_slider', 'block_1');
                }

              ?>



            </div>
        </div>
</div>
</div>
</div>

<!-- Right Side -->


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
