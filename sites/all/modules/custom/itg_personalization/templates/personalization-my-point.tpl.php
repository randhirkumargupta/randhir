<?php
global $user;
/* 
 * @file
 *   Personalization - My Preferences data. 
 */
?>
<!-- Outer container for my preference -->
<div class="preference-container">
    <div class="header-point">
      <span>Total Earned so Far : <strong><?php print $data['total_earned_so_far']; ?></strong></span>
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
            <?php
            $activity_array = array('raf' => 'Refer a Friend', 'ugc_contribution' => 'UGC Contribution', 'fb_follow' => 'Facebook Follow');
            if(array_key_exists($value['activity_name'], $activity_array)) {
              $activity_name = $activity_array[$value['activity_name']];
            } else {
             $activity_name  =  ucfirst(str_replace('_', ' ', $value['activity_name']));
            }
            ?>
            <!--<td class="unit-point-item"><?php print ucfirst($value['activity_name']); ?></td>-->
            <td class="unit-point-item"><?php print $activity_name; ?></td>
            <!--<td class="unit-point-item"><?php print ucfirst($value['points_per_activity']); ?></td>-->
            <td class="unit-point-item"><?php print ucfirst($value['points_per_activity']); ?></td>
            <td class="unit-point-item"><?php print ucfirst($value['earned_points']); ?></td>
        </tr>
        <?php endforeach; ?>
        <!--<tr>
            <td class="unit-point-item"></td>
            <td class="unit-point-item"><strong><?php print t('Total Earned Points'); ?></strong></td>
            <td class="unit-point-item"><strong><?php print $data['total_earned_so_far']; ?></strong></td>
        </tr>-->
      </tbody>     
    </table>
  </div>
</div>

