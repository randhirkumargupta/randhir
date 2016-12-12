<?php

/* 
 * @file
 *   Mail template for loyalty point expiry notification.
 */
?>

<div>
    <?php print t('Remaining points: ') . $data['remaining_point']; ?>
    <?php print t('Please use your points asap. They will expire in next 24 hours.'); ?>
</div>
