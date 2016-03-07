/*
 * @file itg_astro.js
 * Contains all functionality related to astro module.
 */

(function ($, Drupal, window, document, undefined) {
Drupal.behaviors.itg_astro = {
  attach: function(context, settings) {

    // Hide Zodiac sign name field      
    $('.field-name-field-astro-zodiac-sign-name').css('display', 'none');
    
    // Change title and date range on click daily radio button
      $('#edit-field-astro-frequency-und-daily').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().format('L');          
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay);
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(startDay);          
          $("#edit-title").val(startDay);
        }
      });
      
      // Hide date range field from display      
      $('#edit-field-astro-numerology-values').css('display', 'none');
      $('#edit-field-astro-frequency2').css('display', 'none');
      $("#edit-field-field-astro-date-range2").css('display', 'none');
      
      // Change title and date range on click weekly radio button
      $('#edit-field-astro-frequency-und-weekly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().day(0); // Sun
          var endDay = moment().day(6); // Sat          
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay.format('L'));
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(endDay.format('L'));
          var titleText = startDay.format('MMM Do YYYY') + " - " + endDay.format('MMM Do YYYY');
          $("#edit-title").val(titleText);
        }
      });
      
      // Change title and date range on click Monthly radio button 
      $('#edit-field-astro-frequency-und-monthly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().date(1);
          var lastDay = moment().endOf('month');
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay.format('L'));
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(lastDay.format('L'));
          var titleText = firstDay.format('MMM Do YYYY') + " - " + lastDay.format('MMM Do YYYY');
          $("#edit-title").val(titleText);
        }
      });
      
      // Change title and date range on click Yearly radio button 
      $('#edit-field-astro-frequency-und-yearly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().dayOfYear(1).format('L');
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay);
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val('12/31/' + moment().year());
          var startYear = moment().dayOfYear(1).format('MMM Do YYYY');
          var endyear = "Dec 31st " + moment().year();
          $("#edit-title").val(startYear + " - " + endyear);
        }
      });
      
      // Numerology frequency fields
      $('#edit-field-astro-frequency2-und-weekly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().day(0); // Sun
          var endDay = moment().day(6); // Sat          
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(startDay.format('L'));
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val(endDay.format('L'));
        }
      });
      
      // Monthly
      $('#edit-field-astro-frequency2-und-monthly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().date(1);
          var lastDay = moment().endOf('month');
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(firstDay.format('L'));
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val(lastDay.format('L'));
        }
      });
      
      // Yearly
      $('#edit-field-astro-frequency2-und-yearly').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().dayOfYear(1).format('L');
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(firstDay);
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val('12/31/' + moment().year());
        }
      });
      
      // Daily 
      $("#edit-field-astro-frequency2-und-daily").click(function() {
        var state = $(this).is(':checked');
        if (state) {
          var firstDay = moment().format('L');
          $('#edit-field-field-astro-date-range2-und-0-value-datepicker-popup-0').val(firstDay);
          $('#edit-field-field-astro-date-range2-und-0-value2-datepicker-popup-0').val(firstDay);
        }
      });
      
      // Show numerology values
      $("#edit-field-numerology-und-1").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      });
      
      // Hide numerology values
      $("#edit-field-numerology-und-0").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'none');
        $('#edit-field-astro-frequency2').css('display', 'none');
        $("#edit-field-field-astro-date-range2").css('display', 'none');
      });
      
      // Edit case if values are available 
      var num = $('input[name="field_numerology[und]"]:checked').val();
      if (num == 1) {
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      }
      
      // Code for astro node form to expand sef url and meta fields.
      var uid = Drupal.settings.uid;
      if (uid != 1) {
        $('#edit-field-recipe-description-und-0-format').hide();
        $('#edit-metatags').show();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags-und-advanced').hide();
      }
    

  }
};
})(jQuery, Drupal, this, this.document);


