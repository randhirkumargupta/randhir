/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
    Drupal.behaviors.itg_story_front = {
        attach: function (context, settings) {
            // Get query string value.
            function getParameterByName(name, url) {
                if (!url)
                    url = window.location.href;
                name = name.replace(/[\[\]]/g, "\\$&");
                var regex = new RegExp("[?&]" + name + "(=([^&#]*)|&|#|$)"),
                        results = regex.exec(url);
                if (!results)
                    return null;
                if (!results[2])
                    return '';
                return decodeURIComponent(results[2].replace(/\+/g, " "));
            }
            var slickSliderValue = 0;
            var photoStoryValue = getParameterByName('PhotoStory', window.location.href);
            if (photoStoryValue) {
                var slickSliderValue = photoStoryValue;
            }

            $('.multiple-photo-disc').slick({
                infinite: false,
                slidesToShow: 1,
                slidesToScroll: 1,
                prevArrow: '<i class="fa fa-chevron-left" aria-hidden="true"></i>',
                nextArrow: '<i class="fa fa-chevron-right" aria-hidden="true"></i>',
                asNavFor: '.multiple-photo',
                initialSlide: slickSliderValue, // Default slide when query string present in url.
            });
            
            $('.multiple-photo').slick({
                infinite: false,
                slidesToShow: 5,
                slidesToScroll: 1,
                asNavFor: '.multiple-photo-disc',
                focusOnSelect: true,
                centerPadding: '10px',
                responsive: [  
                              {
                                breakpoint: 480,
                                settings: {
                                  slidesToShow: 3                                            
                                }
                              }
                            ]
            });
            
            $('.multiple-photo-disc').on('afterChange', function (event, slick, currentSlide) {
                var hash_text = $(this).find('.slick-current img').parent().attr("data-slick-index");
                var current_url = window.location.href.split('?')[0];
                var photoStoryCuont = Number(hash_text) + 1;
                if (hash_text != 0) {
                    // Change url with query string.
                    window.history.pushState("", "", current_url + "?PhotoStory=" + photoStoryCuont);
                } else {
                    // If frist slide then put pull without query string.
                    window.history.pushState("", "", current_url);
                }
            });
        }
    };

})(jQuery, Drupal, this, this.document);


