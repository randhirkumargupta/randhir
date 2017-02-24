<div class="main-ready-directory city-directory">
    <?php
      foreach($data as $data_key => $data_val) {
    ?>    
        <div class="ready-directory-container">
            <div class="ready-directory-header">
                <?php print t('CITY '.drupal_strtoupper($data_key)); ?>
            </div>
            <div class="ready-directory-label">
                <div class="directory-cell ready-directory-rank"><?php print t('RANK'); ?></div>
                <div class="directory-cell ready-directory-clgname"><?php print t('NAME OF THE COLLEGE'); ?></div>
            </div>
            <?php
              foreach($data_val as $data_val_stream) {
            ?>
                <div class="ready-directory-value">
                    <div class="directory-cell ready-directory-rank"><?php print $data_val_stream[0]; ?></div>
                    <div class="directory-cell ready-directory-clgname"><?php print $data_val_stream[1]; ?></div>
                </div>
            <?php
              }
            ?>
        </div>
  <?php
      }
  ?>
</div>
