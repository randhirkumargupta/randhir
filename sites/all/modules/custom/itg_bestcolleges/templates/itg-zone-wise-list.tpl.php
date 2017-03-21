<div class="main-bestzonewisecompare">
    <?php
      foreach($data as $data_key => $data_val) {
    ?>
        <div class="bestzonecontainer">
            <div class="bestzone_label">
                <div class="zonecell bestzone_rank"><?php print t('RANK'); ?></div>
                <div class="zonecell bestzone_clgname"><?php print t('NAME OF THE COLLEGE'); ?></div>
                <div class="zonecell bestzone_zone"><?php print t('Zone'); ?></div>
            </div>
            <?php
              foreach($data_val as $data_val_stream) {
            ?>
                <div class="bestzone_value">
                    <div class="zonecell bestzone_rank"><?php print $data_val_stream[0]; ?></div>
                    <div class="zonecell bestzone_clgname"><?php print $data_val_stream[2]; ?></div>
                    <div class="zonecell bestzone_zone"><?php print $data_val_stream[1]; ?></div>
                </div>
            <?php
              }
            ?>
        </div>
  <?php
      }
  ?>
</div>
