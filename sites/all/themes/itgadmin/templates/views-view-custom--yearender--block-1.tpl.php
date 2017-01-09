<?php
global $base_url;
?>
<div class="year-slider">    
    <?php foreach($rows as $index => $row): ?>
    <div><?php print $row['field_story_extra_large_image'];?>
        <h2><?php echo l(mb_strimwidth(strip_tags($row['title']), 0, 105, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></h2>
    </div>
    <?php endforeach; ?>
</div>

<script>
jQuery(document).ready(function () {    
    jQuery('.year-slider').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: false         
    });  
});
</script>
