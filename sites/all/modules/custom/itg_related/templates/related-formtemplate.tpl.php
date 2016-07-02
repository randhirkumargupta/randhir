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
    <span class="add-more saved-search-link">Saved Search</span> 
    <a class="colorbox-load add-more add-related-content-link" href="<?php print $base_url.'/related-content?width=900&height=700&iframe=true&type='.$type; ?>">+</a>
</div>
<div class="checked-list-parent">
    <ul class="checked-list">
        
    </ul>
</div>
<div class="my-saved-search">
<?php
itg_related_save_search();
?>
</div>
