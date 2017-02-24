/*
 * @file itg_common.js
 * Contains all functionality related to common functionality
 */

(function ($) {
  Drupal.behaviors.itg_common_funalytics = {
    attach: function (context, settings) {
      //var fid = settings.itg_common.settings.formid;
      //
       $(".funalytic-popup").attr("href", "javascript:void(0)");
       $('.funalytic-popup').click(function() {
           
            var base_url = settings.itg_funalytics.settings.base_url;
            $.ajax({
                url: base_url + "/funalytics-popup",
                method: 'post',
                data: {},
                success: function(data) {                    
                    $("#funalytics_popup_display").html(data);
                }
            });
      });
  }
 };
})(jQuery, Drupal, this, this.document);