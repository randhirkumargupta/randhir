<div class="emergingCollege-section textwrap">
<?php
      foreach($data as $data_key => $data_val) {
    ?>
<div class="streamtitle"><?php print t('STREAM '.drupal_strtoupper($data_key)); ?></div>
 <table style="border-collapse: collapse;" width="100%" align="CENTER" border="1" bordercolor="#c4c4c4" cellpadding="0" cellspacing="0">
    <tr>
    <th width="50"><?php print t('Rank'); ?></th>
    <th width="180"><?php print t('Name of the college'); ?></th>
    <th><?php print t('Address'); ?></th>
    <th><?php print t('Phone No'); ?></th>
    <th><?php print t('College Website'); ?></th>
    <th><?php print t('Established'); ?></th>
    <th><?php print t('Seats'); ?></th>
    <th><?php print t('2012 Cut-off Percentage'); ?></th>
  </tr>
 <?php
              foreach($data_val as $data_val_stream) {
            ?>
<tr>
    <td data-title="Rank"><?php print $data_val_stream[0]; ?>.</td>
    <td data-title="Name of the college"><?php print $data_val_stream[1]; ?></td>
    <td data-title="Address"><?php print $data_val_stream[2]; ?></td>
    <td data-title="Phone No"><?php print $data_val_stream[3]; ?></td>
    <td data-title="College Website"><?php print $data_val_stream[4]; ?></td>
    <td data-title="Established"><?php print $data_val_stream[5]; ?></td>
    <td data-title="Seats"><?php print $data_val_stream[6]; ?></td>
    <td data-title="2012 Cut-off Percentage"><?php print $data_val_stream[7]; ?></td>
</tr>
<?php } ?>
</table>
<?php
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

