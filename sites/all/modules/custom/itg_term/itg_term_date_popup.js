/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {
  Drupal.behaviors.itg_term = {
    attach: function (context, settings) {
      $('#edit-created-min-datepicker-popup-0').one('focus', function() {
        $('#edit-created-min-datepicker-popup-0').datepicker('option', {
          onClose: function(selected) {
            $('#edit-created-max-datepicker-popup-0').one('focus', function() {
              $('#edit-created-max-datepicker-popup-0').datepicker('option', 'minDate', selected);
            });
            $('#edit-created-max-datepicker-popup-0').datepicker('option', 'minDate', selected);
          }
        });
      });
    }
  };
}(jQuery));