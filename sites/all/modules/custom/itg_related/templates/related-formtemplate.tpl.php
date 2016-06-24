<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
$type = arg(2);
global $user, $base_url;

?>

<div class="rel-link">
    
    <a class="colorbox-load" href="<?php print $base_url.'/related-content?width=900&height=700&iframe=true&type='.$type; ?>">Add Related content</a>
    <?php
    itg_related_save_search();
    ?>
</div>