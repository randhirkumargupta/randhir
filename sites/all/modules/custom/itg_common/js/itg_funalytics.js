/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function($) {
  Drupal.behaviors.itg_common_funalytics = {
    attach: function(context, settings) {

      $(".funalytic-popup").attr("href", "javascript:void(0)");
      $('.funalytic-popup').click(function() {

        var base_url = settings.itg_funalytics.settings.base_url;
        var loader_html = '<div id="funalytics-ajex-loader"><img class="widget-loader" src="sites/all/themes/itg/images/loader.svg" alt="Loading..." title="" /></div>';
        $("#funalytics_popup_display").html(loader_html);
        var goto = $(this).attr('data-nid');

        $.ajax({
          url: base_url + "/funalytics-popup",
          method: 'post',
          data: {},
          success: function(data) {
            $("#funalytics_popup_display").html(data);
            jQuery('.funalytics-slider').slick({
              initialSlide: goto,
              slidesToShow: 1,
              slidesToScroll: 1,
              infinite: false,
              prevArrow: "<button class = 'slick-prev'><i class = 'fa fa-angle-left'></i></button>",
              nextArrow: "<button class = 'slick-next'><i class = 'fa fa-angle-right'></i></button>"
            });
            //jQuery('.funalytics-slider').slick('slickGoTo', goto);

          }
        });
      });

      $("#funalytics_popup_display").on('click', '.close-popup', function() {
        $(this).closest("#funalytics_popup_display").html('');
      });
    }
  };
})(jQuery, Drupal, this, this.document);