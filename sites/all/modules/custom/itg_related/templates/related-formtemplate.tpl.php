<?php
/**
 * @file
 * Theme implementation for story form in tab display.
 * 
 */
$type = arg(2);
global $base_url;

?>

<div class="rel-link">
    <span class="add-more saved-search-link"><?php print t('Saved Search'); ?></span> 
    <div class="my-saved-search"><?php print $data; ?></div>
    <a class="colorbox-load add-more add-related-content-link" oncontextmenu="return false;" href="<?php print $base_url.'/related-content?width=1000&height=700&iframe=true&type='.$type; ?>">+</a>
</div>
<div class="checked-list-parent">
    <ul class="checked-list"></ul>
    <div class="save-checklist-ordre"></div>
</div>
