(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_term = {
    attach: function (context, settings) {
      // Place your code here.
      var setting = Drupal.settings.baseUrl;     
      // Ajax callback to check number of node associated with term.
        var tid = $('.tid').text();
        //Call Ajax
        $.ajax({
          url: setting.baseUrl + "/sites/default/files".,
          type: 'post',
          data: {'tid': tid},
          dataType: "JSON",
          success: function (data) {
            $('span.count').html(' : ' + data);
          }
        });
         
    }
  };
})(jQuery, Drupal, this, this.document);
