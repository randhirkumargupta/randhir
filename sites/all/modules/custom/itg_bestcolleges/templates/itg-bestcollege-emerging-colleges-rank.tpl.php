<div class="emergingCollege-section">
<div class="streamtitle"><?php print t('STREAM: '.drupal_strtoupper(arg(3))); ?></div>
<table style="border-collapse: collapse;" width="100%" align="CENTER" border="1" bordercolor="#c4c4c4" cellpadding="0" cellspacing="0">
  <tr>
    <th width="50"><?php print t('Rank'); ?></th>
    <th width="180"><?php print t('Name of the college'); ?></th>
    <th><?php print t('Reputation'); ?></th>
    <th><?php print t('Academic Input'); ?></th>
    <th><?php print t('Student Care'); ?></th>
    <th><?php print t('Infra'); ?></th>
    <th><?php print t('Placement'); ?></th>
    <th><?php print t('Perceptual Rank'); ?></th>
    <th><?php print t('Factual Rank'); ?></th>

  </tr>
  <?php foreach($data as $data_key => $data_val) { ?>
  <tr>
    <td data-title="Rank"><?php print $data_val->overall_rank; ?>.</td>
    <td data-title="Name of the college"><?php print $data_val->collegename; ?></td>
    <td data-title="Reputation"><?php print $data_val->reputation; ?></td>
    <td data-title="Academic Input"><?php print $data_val->academic_input; ?></td>
    <td data-title="Student Care"><?php print $data_val->studentcare; ?></td>
    <td data-title="Infra"><?php print $data_val->infrastructure; ?></td>
    <td data-title="Placement"><?php print $data_val->placement; ?></td>
    <td data-title="Perceptual Rank"><?php print $data_val->preceptual_rank; ?></td>
    <td data-title="Factual Rank"><?php print $data_val->factual_rank; ?></td>
  </tr>
  <?php } ?>
</table>
</div>

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
<!-- code for like dislike -->
<div class="col-sm-12 col-xs-12 col-md-12">
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
