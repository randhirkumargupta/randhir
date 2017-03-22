<div class="main-streamwisecompare">
    <?php
      $incr = 0;
      $incr_div = '';
      foreach($data as $data_key => $data_val) {
        if ($incr == 1) {
          $incr_div = 1;
        }
    ?>
        <div class="streamcontainer<?php print $incr_div; ?>">
            <div class="stream_header"><div class="stream_rank"></div><div class="stream_clgname"><?php print t('STREAM '.$data_key); ?></div></div>
            <div class="stream_label"><div class="stream_rank"><?php print t('RANK'); ?></div><div class="stream_clgname"><?php print t('NAME OF THE COLLEGE'); ?></div></div>
            <?php
              foreach($data_val as $data_val_stream) {
            ?>
                <div class="stream_value"><div class="stream_rank"><?php print $data_val_stream['rank']; ?></div><div class="stream_clgname"><?php print $data_val_stream['college_name']; ?></div></div>
            <?php
              }
            ?>
        </div>
  <?php
      $incr++;
      }
  ?>
</div>

<!-- Grid View-->
<div class="col-sm-12 col-xs-12">
<div class="title col-md-6 col-sm-6 col-xs-12"><?php print t("Best of The Best ") . arg(1);; ?></div>

        <div class="right_Section pull-right  col-md-6  col-sm-6 col-xs-12 text-right hidden-xs">
        <strong>view as</strong>
        <div class="btn-group">
            <a href="#" class="btn btn-default btn-sm list"><span class="fa fa-th-list"></span> List</a>
            <a href="#" class="btn btn-default btn-sm active_btn grid"><span class="fa fa-th"></span> Grid</a>
        </div>
        </div>
</div>

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

 <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

</div>

