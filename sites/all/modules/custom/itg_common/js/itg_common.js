/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
  Drupal.behaviors.itg_common = {
    attach: function (context) {
      // code for Magazine and Supplement field hide and show
      $('.form-item-roles').hide();
      $('#edit-metatags').hide();
      $('#edit-timezone').hide();
      $('#edit-selected').change(function () {
        $('#edit-roles :checkbox:enabled').prop('checked', false);
        var checkboxId = 'edit-roles-' + $(this).val();
        $('#' + checkboxId).prop("checked", true);
      });
      
      // Change label of the field collection field
      $("#edit-field-numerology-und-0").click(function() {         
        //$("#edit-field-astro-frequency2").hide();        
      });
      $("#edit-field-numerology-und-1").click(function() {
        //$("#edit-field-astro-frequency2").show();        
      });
      
      // Hide date range field from display
      $('#edit-field-field-astro-date-range2').css('display', 'none');
      $('#edit-field-astro-numerology-values').css('display', 'none');
      $('#edit-field-astro-frequency2').css('display', 'none');
      
      // Weekly
      $('#edit-field-astro-frequency2-und-weekly').click(function() {        
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().day(0); // Sun
          var endDay = moment().day(6); // Sat          
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(startDay.format('L'));
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val(endDay.format('L'));
        }
      });
      // Monthly
      $('#edit-field-astro-frequency2-und-monthly').click(function() {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().date(1);
          var lastDay = moment().endOf('month');
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(firstDay.format('L'));
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val(lastDay.format('L'));
        }
      });
      // Yearly
      $('#edit-field-astro-frequency2-und-yearly').click(function() {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().dayOfYear(1).format('L');          
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(firstDay);
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val('12/31/'+moment().year());
        }
      });
      // Show numerology values
      $("#edit-field-numerology-und-1").click(function() {
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
      });
      $("#edit-field-numerology-und-0").click(function() {
        $('#edit-field-astro-numerology-values').css('display', 'none');
        $('#edit-field-astro-frequency2').css('display', 'none');
      });
      var num = $('input[name="field_numerology[und]"]:checked').val();
      if (num == 1) {
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
      }
       
      

    }

  };
})(jQuery, Drupal, this, this.document);