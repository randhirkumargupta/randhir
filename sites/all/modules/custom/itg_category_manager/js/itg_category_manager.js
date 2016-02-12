(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_category_manager = {
    attach: function (context, settings) {
      // Place your code here.
      var setting = Drupal.settings.baseUrl;
      $('#edit-term-state').click(function () {
        var state = $(this).is(':checked');        
      });

    }
  };
})(jQuery, Drupal, this, this.document);
