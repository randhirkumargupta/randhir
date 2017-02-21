<div class="main-bestzonewisecompare">
    <div class="bestzonecontainer">
        <div class="bestzone_label">
                <div class="zonecell bestzone_rank"><?php print t('RANK'); ?></div>
                <div class="zonecell bestzone_clgname"><?php print t('NAME OF THE COLLEGE'); ?></div>
                <div class="zonecell bestzone_zone"><?php print t('CITY'); ?></div>
                <div class="zonecell bestzone_stream"><?php print t('GOVT/PVT'); ?></div>
        </div>
    <?php
      foreach($data as $data_key => $data_val) {
        foreach($data_val as $data_val_stream) {
    ?>
          <div class="bestzone_value">
              <div class="zonecell bestzone_rank"><?php print $data_val_stream[0]; ?></div>
              <div class="zonecell bestzone_clgname"><?php print $data_val_stream[1]; ?></div>
              <div class="zonecell bestzone_zone"><?php print $data_val_stream[2]; ?></div>
              <div class="zonecell bestzone_stream"><?php print $data_val_stream[3]; ?></div>
          </div>
      <?php
        }
      }
  ?>
  </div>
</div>
