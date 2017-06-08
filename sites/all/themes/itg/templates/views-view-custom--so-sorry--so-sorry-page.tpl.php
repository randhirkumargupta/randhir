<?php
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
$nid = $rows[0]['nid'];
$arg = arg(1);
if (is_numeric($arg[1]) && isset($arg[1])) {
  $nid = arg(1);
}
if (function_exists('itg_widget_dailymotion_get_videogallery_slider')) {
  itg_widget_dailymotion_get_videogallery_slider($nid);
}
?>

<script>
  jQuery(document).ready(function () {
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
