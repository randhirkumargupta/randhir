<h1><?php print $data->title; ?></h1>
<div class="col-md-8">

        <ul class="slickslide">
            <?php foreach ($data->field_gallery_image['und'] as $index => $mega_item) {
                $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
                $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];
                ?>
                <li >
                    <figure class="" img-fid=" <?php print $ans_detail[$mega_item['value']]->field_images['und'][0]['fid'];?>">

                        <img src=<?php print file_create_url($byline_id);?> width="753" height="543"/>
                        <?php //theme('image_style', array('style_name' => 'photgallery_landing_slider_753x543', 'path' => $byline_id)); ?> 
                    </figure>
                </li>
            <?php } ?>
        </ul>
        <div class="slick-thumbs">
            <ul class="slick-thumbs-slider">
                <?php foreach ($data->field_gallery_image['und'] as $index => $mega_item) { $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
                $byline_id = $ans_detail[$mega_item['value']]->field_images['und'][0]['uri'];?>
                    <li >
                       <img src=<?php print file_create_url($byline_id);?> width="88" height="86"/>
                    </li>
                <?php } ?>
            </ul>
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
        focusOnSelect: true,
        responsive: [
            {
              breakpoint: 1024,
              settings: {
                slidesToShow: 7,                  
                slidesToScroll: 1,
                arrows: false
              }
            },
            {
              breakpoint: 600,
              settings: {
                slidesToShow: 4,
                 arrows: false,
                slidesToScroll: 1
              }
            },
            {
              breakpoint: 480,
              settings: {
                slidesToShow: 3,
                 arrows: false,
                slidesToScroll: 1
              }
            }
        ]
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