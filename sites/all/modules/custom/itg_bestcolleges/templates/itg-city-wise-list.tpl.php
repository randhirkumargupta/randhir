<div class="emergingCollege-section textwrap">
    <?php
      foreach($data as $data_key => $data_val) {
    ?>   
    <div class="streamtitle"><?php print t('CITY '.drupal_strtoupper($data_key)); ?></div>  
        <table style="border-collapse: collapse;" width="100%" align="CENTER" border="1" bordercolor="#c4c4c4" cellpadding="0" cellspacing="0">
    <tr>
    <th><?php print t('Rank'); ?></th>
    <th><?php print t('Name of the college'); ?></th>
  </tr> 
            <?php
              foreach($data_val as $data_val_stream) {
            ?>

            <tr>
    <td data-title="Rank"><?php print $data_val_stream[0]; ?>.</td>
    <td data-title="Name of the college"><?php print $data_val_stream[1]; ?></td>
</tr>

            <?php
              }
            ?>
        </table>
  <?php
      }
  ?>
</div>
