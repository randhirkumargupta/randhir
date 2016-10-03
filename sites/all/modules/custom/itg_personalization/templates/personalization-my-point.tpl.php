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
        print l(t('<span>Redeemed Points : <strong>@total_earned</strong></span>', 
            array('@total_earned' => $data['redeemed_points'])), 'order', array('html' => TRUE));
        print l(t('<span>Remaining Points : <strong>@remaining</strong></span>', 
            array('@remaining' => $data['total_earned_so_far'] - $data['redeemed_points'])), 'redeem-points', array('html' => TRUE));
      ?>        
    </div>
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
          <td class="unit-point-item"><?php print $value['activity_name']; ?></td>
          <td class="unit-point-item"><?php print $value['points_per_activity'] ?></td>
          <td class="unit-point-item"><?php print $value['earned_points']; ?></td>
        </tr>
        <?php endforeach; ?>
      </tbody>
        
        
        
        
    </table>
</div>

