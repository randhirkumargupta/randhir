/*
 * @file itg_front_end_common.js
 * Contains all functionality related to Ads Management
 */

(function($) {
    Drupal.behaviors.itg_ads = {
        attach: function(context) {
         
        }
        
        

    };
})(jQuery, Drupal, this, this.document);

jQuery(document).ready(function () {
  var input_range = jQuery('#slider-range').val();
  jQuery("#slider-range").ionRangeSlider({
    min: 0,
    max: 1439,
    from: 0,
    step: 1,
    onStart: function () {
      setTimeout(function () {
        jQuery('.irs-slider.single').text("00:00 AM");
      }, 0);
    },
    onChange: timeline
  });

  function timeline(data) {
    var num = data.from;
    var hs = Math.floor(num / 60);
    var ms = num - (hs * 60);
    if (hs.length == 1) {
      hs = '0' + hs;
    }
    if (ms.length == 1) {
      ms = '0' + ms;
    }
    if (ms == 0)
      ms = '00';
    if (hs >= 12) {
      if (hs == 12) {
        hs = hs;
        ms = ms + " PM";
      } else {
        hs = hs;
        ms = ms + " PM";
      }
    } else {
      hs = hs;
      ms = ms + " AM";
    }
    if (hs == 0) {
      hs = '00';
      ms = ms;
    }
    jQuery('.irs-slider.single').text(hs + ":" + ms);
    jQuery('.breaking-section').each(function () {
      var breakingDate = jQuery(this).find('.breaking-date').text();
      var text_array = breakingDate.split(" ");
      var timeVal = text_array[0].split(":");
      var hs_to_num = parseInt(timeVal[0] * 60);
      var ms_to_num = parseInt(timeVal[1]);
      var totla_num = hs_to_num + ms_to_num;
      if (num > totla_num) {
        jQuery(this).hide();
      } else {
        jQuery(this).show();
      }
    });
  }
});