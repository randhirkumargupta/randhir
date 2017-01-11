<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$arg = arg(1);
if (is_numeric($arg[1]) && isset($arg[1])) {
  $nid = arg(1);
}
// Logic for default feature video on sosorry page if feature is not selected in widget.
if(function_exists('get_feature_nid_in_sosorry')){
  $nid = get_feature_nid_in_sosorry();
}
if (function_exists('get_recent_created_node_for_sosorry') && empty($nid)) {
  $nid = get_recent_created_node_for_sosorry();
}
if (function_exists('itg_widget_dailymotion_get_videogallery_slider')) {
    itg_widget_dailymotion_get_videogallery_slider($nid);
}
?>

<script>   
   jQuery(document).ready(function() {
        jQuery('.videogallery-slider').slick({
            slidesToShow: 1,
            slidesToScroll: 1,
            arrows: false,
            fade: false,
            asNavFor: '.video-slider-images ul'
        });               
        jQuery('.video-slider-images ul').slick({
            slidesToShow: 7,
            slidesToScroll: 1,
            asNavFor: '.videogallery-slider',
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
    });   
</script>
