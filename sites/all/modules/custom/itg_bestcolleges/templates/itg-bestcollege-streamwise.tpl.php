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
