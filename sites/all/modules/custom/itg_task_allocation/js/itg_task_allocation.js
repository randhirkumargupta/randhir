/*
 * @file itg_mega_reviews_critics.js
 * Contains all functionality related to Mega Reviews & Critics
 */

(function ($) {
  Drupal.behaviors.task_allocation = {
    attach: function (context) {
        //$('.tabledrag-toggle-weight-wrapper').hide();
        $('.vertical-tabs').hide();
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
})(jQuery, Drupal, this, this.document);