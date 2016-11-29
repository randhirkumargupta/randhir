
<div class="row">
    <div class="col-md-8">
        <ul class="slickslide">
            <?php foreach ($rows as $index => $row): ?>
                <li >
                    <figure class="imgtags" img-fid=" <?php print $row['fid'];?>">
                        <?php print $row['field_images']; ?>                    
                    </figure>
                </li>
            <?php endforeach; ?>
        </ul>
<!--        <div class="slick-thumbs">
            <ul class="slick-thumbs-slider">
                <?php foreach ($rows as $index => $row): ?>
                    <li >
                        <?php print $row['field_images_1']; ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>-->        
    </div>
    
</div>


<script>
jQuery(document).ready(function (e) {    
    jQuery('.slickslide').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: false,
        asNavFor: '.slick-thumbs-slider, .counterslide, .photo-by-slider'
    });
    jQuery('.slick-thumbs-slider').slick({
        slidesToShow: 7,
        slidesToScroll: 1,
        asNavFor: '.slickslide, .counterslide, .photo-by-slider',
        dots: false,
        centerMode: false,
        arrows: true,
        variableWidth: true,
        focusOnSelect: true
    });
        
    jQuery('.counterslide').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: true,
        asNavFor: '.slick-thumbs-slider, .slickslide, .photo-by-slider'
    });
    jQuery('.photo-by-slider').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: false,
        fade: true,
        asNavFor: '.slick-thumbs-slider, .slickslide, .counterslide'
    });
});

</script>








    
  



