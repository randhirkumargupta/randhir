<div class="emergingCollege-section textwrap">
    <?php
      foreach($data as $data_key => $data_val) {
    ?>
<table style="border-collapse: collapse;" width="100%" align="CENTER" border="1" bordercolor="#c4c4c4" cellpadding="0" cellspacing="0">
    <tr>
    <th><?php print t('RANK'); ?></th>
    <th><?php print t('NAME OF THE COLLEGE'); ?></th>
    <th><?php print t('Zone'); ?></th>
  </tr>
            <?php
              foreach($data_val as $data_val_stream) {
            ?>
            <tr>
    <td data-title="Rank"><?php print $data_val_stream[0]; ?>.</td>
    <td data-title="Name of the college"><?php print $data_val_stream[2]; ?></td>
    <td data-title="Zone"><?php print $data_val_stream[1]; ?></td>
</tr>
                
            <?php
              }
            ?>
        </table>
  <?php
      }
  ?>
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
