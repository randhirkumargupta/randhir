<div class="slider_besrCollage slider_outer">
    <?php foreach($rows as $index => $row): ?>
    <div><?php print $row['field_story_extra_large_image'];?>
        <div class="carousel-caption"><?php echo l(mb_strimwidth(strip_tags($row['title']), 0, 105, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?></div>
    </div>
    <?php endforeach; ?>
</div>

<script>
jQuery(document).ready(function () {
    jQuery('.slider_outer').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: false
    });
});
</script>


