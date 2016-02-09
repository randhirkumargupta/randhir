/*
 * @file itg_msi.js
 */

(function($) {
  Drupal.behaviors.itg_msi = {
    attach: function(context) {
      
      //Restrict print issue date to select previous date in magazine form 
      $('#edit-field-print-magazine-issue-date-und-0-value-datepicker-popup-0').datepicker({
        changeYear: true,
        minDate: '0',
        readonly: true
      });
    }
 };
})(jQuery, Drupal, this, this.document);