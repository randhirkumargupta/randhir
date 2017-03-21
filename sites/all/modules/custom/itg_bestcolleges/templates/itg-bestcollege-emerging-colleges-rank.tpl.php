<table>

  <tr><td colspan="9"><?php print t('STREAM Art'.$data_key); ?></td></tr>
  <tr>
    <th><?php print t('RANK'); ?></th>
    <th><?php print t('NAME OF THE COLLEGE'); ?></th>
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
    <td><?php print $data_val->overall_rank; ?></td>
    <td><?php print $data_val->collegename; ?></td>
    <td><?php print $data_val->reputation; ?></td>
    <td><?php print $data_val->academic_input; ?></td>
    <td><?php print $data_val->studentcare; ?></td>
    <td><?php print $data_val->infrastructure; ?></td>
    <td><?php print $data_val->placement; ?></td>
    <td><?php print $data_val->preceptual_rank; ?></td>
    <td><?php print $data_val->factual_rank; ?></td>
  </tr>
  <?php } ?>
</table>

