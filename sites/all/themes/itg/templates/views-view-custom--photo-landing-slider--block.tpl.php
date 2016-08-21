<div class="row">
    <h2><?php print $row['title']; ?></h2>
    <div class="col-md-8">
        <ul class="slickslide">
            <?php foreach ($rows as $index => $row): ?>
                <li>
                    <figure>
                        <?php print $row['field_images']; ?>
                        <figcaption><?php print $row['field_photo_by']; ?></figcaption>
                    </figure>
                </li>
            <?php endforeach; ?>
        </ul>
        <div class="slick-thumbs" style="display: none">
            <ul>
                <?php foreach ($rows as $index => $row): ?>
                    <li>
                        <?php print $row['field_images_1']; ?>
                    </li>
                <?php endforeach; ?>
            </ul>
        </div>
    </div>
    <div class="col-md-4 other-details-main">
        <ul class="counterslide">
            <?php foreach ($rows as $index => $row): ?>
                <li>

                    <div class="other-details">
                        <div class="counter">
                            <i class="fa fa-camera" aria-hidden="true"></i>
                            <?php print $row['counter']; ?>
                        </div>
                        <div class="caption"><?php print $row['field_image_caption']; ?></div>
                    </div>
                </li>
            <?php endforeach; ?>
        </ul>
        
        <div class="social-icon">
            <ul>
                <li><a href="#"><i class="fa fa-facebook"></i></a></li>
                <li><a href="#"><i class="fa fa-google-plus"></i></a></li>
                <li><a href="#"><i class="fa fa-twitter"></i></a></li>
                <li><a href="#"><i class="fa fa-comment"></i></a></li>
                <li><a href="#"><i class="fa fa-link"></i></a></li>
                <li><a href="#"><i class="fa fa-share"></i></a></li>
                <li><a href="#"><i class="fa fa-bookmark"></i></a></li>
            </ul>
            
            
            
        </div>
        
        
    </div>
</div>


<script>
jQuery(document).ready(function (e) {
    jQuery('.slickslide').slick({
        dots: true,
        infinite: true,        
        fade: false,
        slide: 'li',
        cssEase: 'linear',
        centerMode: true,
        slidesToShow: 1,
        variableWidth: true,
        autoplay: true,
        autoplaySpeed: 4000,
        responsive: [{
            breakpoint: 800,
            settings: {
                arrows: false,
                centerMode: false,
                centerPadding: '40px',
                variableWidth: false,
                slidesToShow: 1,
                dots: true
            },
            breakpoint: 1200,
            settings: {
                arrows: false,
                centerMode: false,
                centerPadding: '40px',
                variableWidth: false,
                slidesToShow: 1,
                dots: true

            }
        }],
        customPaging: function (slider, i) {
            return '<button class="tab">' + jQuery('.slick-thumbs li:nth-child(' + (i + 1) + ')').html() + '</button>';
        }
    });
    
    jQuery('.counterslide').slick({
        dots: false,
        fade: true,
        asNavFor:'.slickslide'
    });

    //$('.slick-thumbs').html('');
    //$('.slick-dots').appendTo('.slick-thumbs');
});

</script>








    
  



