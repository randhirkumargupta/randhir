(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_category_manager = {
    attach: function (context, settings) {
      // Place your code here.
      var setting = Drupal.settings.baseUrl;
      $('#edit-term-state').click(function () {
        var state = $(this).is(':checked');
      });
      $('#show-content-count').on('click', function () {
        var tid = $('.tid').text();
        //Call Ajax
        $.ajax({
          url: setting.baseUrl + "/content-associated",
          type: 'post',
          data: {'tid': tid},
          dataType: "JSON",
          success: function (data) {
            $('span.count').html(' : ' + data);
          }
        });
      });
    }
  };
})(jQuery, Drupal, this, this.document);
