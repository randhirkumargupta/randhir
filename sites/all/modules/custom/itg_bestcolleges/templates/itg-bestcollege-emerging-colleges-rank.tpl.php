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

 <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

</div>
