<?php

/** 
 * @file
 *   Template file for edit profile. 
 */
?>
<?php global $base_url; ?>
<?php print $data['tab']; ?>
<div class="social-edit">
    <ul>
        <li>Via Social</li>
        <li><img alt="" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/facebook-edit.png'; ?>"></li>
        <li><img alt="" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/edit-twitter.png'; ?>"></li>
        <li><img alt="" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/google-plus-edit.png'; ?>"></li>
        <li><img alt="" src="<?php echo $base_url . '/' . drupal_get_path('theme', 'itg') . '/images/linkedin-edit.png'; ?>"></li>
    </ul>
    
    <div class="more-option"> OR </div>
    
</div>

<?php print render($data['form']); ?>

