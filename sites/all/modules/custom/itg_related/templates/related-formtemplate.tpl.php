<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
$type = arg(2);
?>

<div class="rel-link">
    <a class="colorbox-load" href="http://localhost/itgcms/related-content?width=900&height=700&iframe=true&type=<?php print $type; ?>">Add Related content</a>
    <?php
    itg_related_save_search();
    ?>
</div>