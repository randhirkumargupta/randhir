<?php

/* 
 * @file
 *   Personalization - My Preferences data. 
 */
?>
<!-- Outer container for my preference -->
<div class="preference-container">
    <div class="header-point">
      <span>Total Earned so For : <strong><?php print $data['total_earned_so_far']; ?></strong></span>
      <?php 
        print '<span>' . l(t('Redeemed Points : <strong>@redeemed</strong></span>', 
            array('@redeemed' => $data['redeemed_points'])), 'order', array('html' => TRUE)) . '</span>';
        print '<span>' . l(t('Remaining Points : <strong>@remaining</strong>', 
            array('@remaining' => $data['remaining_point'])), 'product', array('html' => TRUE)) . '</span>';
      ?>        
    </div>
  <div class="overflow-x-auto">
    <table class="unit-description">
      <thead>
        <tr>
          <th class="unit-point-header">Activities</th>
          <th class="unit-point-header">Points per Activity</th>
          <th class="unit-point-header">Earned Point</th>
        </tr>
      </thead>
      <tbody>
        <?php foreach ($data['unit_description'] as $value): ?>
        <tr>
            <td class="unit-point-item"><?php print ucfirst($value['activity_name']); ?></td>
            <td class="unit-point-item"><?php print ucfirst($value['points_per_activity']); ?></td>
            <td class="unit-point-item"><?php print ucfirst($value['earned_points']); ?></td>
        </tr>
        <?php endforeach; ?>
        <tr>
            <td class="unit-point-item"></td>
            <td class="unit-point-item"><strong><?php print t('Total Earned Points'); ?></strong></td>
            <td class="unit-point-item"><strong><?php print $data['total_earned_so_far']; ?></strong></td>
        </tr>
      </tbody>     
    </table>
  </div>
</div>

