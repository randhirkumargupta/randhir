<div class="main-ready-directory">
    <?php
      foreach($data as $data_key => $data_val) {
    ?>    
        <div class="ready-directory-container">
            <div class="ready-directory-header">
                <?php print t('STREAM '.drupal_strtoupper($data_key)); ?>
            </div>
            <div class="ready-directory-label">
                <div class="directory-cell ready-directory-rank"><?php print t('RANK'); ?></div>
                <div class="directory-cell ready-directory-clgname"><?php print t('NAME OF THE COLLEGE'); ?></div>
                <div class="directory-cell ready-directory-add"><?php print t('Address'); ?></div>
                <div class="directory-cell ready-directory-phn"><?php print t('Phone No'); ?></div>
                <div class="directory-cell ready-directory-web"><?php print t('College Website'); ?></div>
                <div class="directory-cell ready-directory-est"><?php print t('Established'); ?></div>
                <div class="directory-cell ready-directory-seat"><?php print t('Seats'); ?></div>
                <div class="directory-cell ready-directory-cut"><?php print t('2012 Cut-off Percentage'); ?></div>
            </div>
            <?php
              foreach($data_val as $data_val_stream) {
            ?>
                <div class="ready-directory-value">
                    <div class="directory-cell ready-directory-rank"><?php print $data_val_stream[0]; ?></div>
                    <div class="directory-cell ready-directory-clgname"><?php print $data_val_stream[1]; ?></div>
                    <div class="directory-cell ready-directory-add"><?php print $data_val_stream[2]; ?></div>
                    <div class="directory-cell ready-directory-phn"><?php print $data_val_stream[3]; ?></div>
                    <div class="directory-cell ready-directory-web"><?php print $data_val_stream[4]; ?></div>
                    <div class="directory-cell ready-directory-est"><?php print $data_val_stream[5]; ?></div>
                    <div class="directory-cell ready-directory-seat"><?php print $data_val_stream[6]; ?></div>
                    <div class="directory-cell ready-directory-cut"><?php print $data_val_stream[7]; ?></div>
                </div>
            <?php
              }
            ?>
        </div>
  <?php
      }
  ?>
</div>
