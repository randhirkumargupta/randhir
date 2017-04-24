(function ($) {
  Drupal.behaviors.CkeditorTimestamp = {
    attach: function (context, settings) {
      CKEDITOR.timestamp = Drupal.settings.itg_ckeditor_cache.timestamp;
    }
  };
}) (jQuery);