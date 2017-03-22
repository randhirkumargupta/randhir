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

 <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

</div>
