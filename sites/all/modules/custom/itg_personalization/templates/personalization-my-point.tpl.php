<?php

/* 
 * @file
 *   Personalization - My Preferences data. 
 */
?>
<!-- Outer container for my preference -->
<div class="preference-container">
    <div class="header-point">
        <span>Total Earned so For : <?php print $data['total_earned_so_far']; ?></span> |
        <span>Redeemed Points : <?php print $data['redeemed_points']; ?></span> |
        <span>Remaining Points : <?php print $data['total_earned_so_far'] - $data['redeemed_points']; ?></span>
    </div>
    <div class="unit-description">
        <div class="unit-point-header">Activities</div>
        <div class="unit-point-header">Points per Activity</div>
        <div class="unit-point-header">Earned Point</div>
        <?php foreach ($data['unit_description'] as $value): ?>
        <div class="unit-point-item"><?php print $value['activity_name']; ?></div>
        <div class="unit-point-item"><?php print $value['points_per_activity'] ?></div>
        <div class="unit-point-item"><?php print $value['earned_points']; ?></div>
        <?php endforeach; ?>
    </div>
</div>

