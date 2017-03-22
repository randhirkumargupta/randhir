<div class="emergingCollege-section">
<div class="streamtitle"><?php print t('STREAM: SCIENCE'.$data_key); ?></div>
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
