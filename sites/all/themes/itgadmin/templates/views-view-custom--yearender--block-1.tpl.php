<div class="year-slider">
    here i am ========================>
    <?php foreach($rows as $index => $row): ?>
    <div><?php print $row['field_story_extra_large_image'];?>
        <h2><?php print ucfirst($row['title']);?></h2>
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
