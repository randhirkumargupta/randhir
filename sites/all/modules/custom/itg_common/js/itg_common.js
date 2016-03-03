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
      $('#edit-title').val(moment().format('L'));
      // Hide date range field from display      
      $('#edit-field-astro-numerology-values').css('display', 'none');
      $('#edit-field-astro-frequency2').css('display', 'none');
      $("#edit-field-field-astro-date-range2").css('display', 'none');
      
      // Daily 
      $('#edit-field-astro-frequency-und-daily').click(function () {
        var state = $(this).is(':checked');
        if (state) {
          var startDay = moment().format('L'); // Sun
          var endDay = moment().format('L'); // Sat          
          $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay);
          $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(endDay);
          $('#edit-title').val(startDay);
        }
      });
      // Weekly
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
      // Show numerology values
      $("#edit-field-numerology-und-1").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      });
      $("#edit-field-numerology-und-0").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'none');
        $('#edit-field-astro-frequency2').css('display', 'none');
        $("#edit-field-field-astro-date-range2").css('display', 'none');
      });
      var num = $('input[name="field_numerology[und]"]:checked').val();
      if (num == 1) {
        $("#edit-field-field-astro-date-range2").css('display', 'block');
        $('#edit-field-astro-numerology-values').css('display', 'block');
        $('#edit-field-astro-frequency2').css('display', 'block');
        $('#edit-field-astro-frequency2 label:first').html('Select Frequency<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-story-source-id label:first").html('Enter Number<span class="form-required" title="This field is required."> *</span>');
        $("#edit-field-astro-numerology-values-und-0-field-buzz-description label:first").html('Enter Text<span class="form-required" title="This field is required."> *</span>');
      }

      // jQuery code for user registeration form
      var userSelect = $('select[name="selected"]');
      function userRegisterEdit(v) {
        var value = $(v).val();
        var markexpert = $('.field-name-field-mark-as-expert').find('.form-checkbox').is(':checked');
        if (value == "21") {
          $('.field-name-field-user-section').show();
        } else if (value == "5" || value == "6" || value == "20") {
          $('.field-name-field-mark-as-expert').show();
          if (markexpert == true) {
            $('.field-name-field-user-section').show();
          }
          else {
            $('.field-name-field-user-section').hide();
          }
        }
      }
      userRegisterEdit(userSelect);

      $('#user-register-form, #user-profile-form').on('change', 'select[name="selected"]', function () {
        var value = $(this).val();
        $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
        if (value == "21") {
          $('.field-name-field-user-section').show();
          $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
          $('.field-name-field-mark-as-expert').hide();
        } else if (value == "5" || value == "6" || value == "20") {
          $('.field-name-field-user-section').hide();
          $('.field-name-field-user-section').find('select').val("_none");
          $('.field-name-field-mark-as-expert').show();
        } else {
          $('.field-name-field-user-section').find('select').val("_none");
          $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
          $('.field-name-field-user-section').hide();
          $('.field-name-field-mark-as-expert').hide();
        }
      });

      $('.field-name-field-mark-as-expert').on('change', '.form-checkbox', function () {
        var check = $(this).is(':checked');
        if (check == true) {
          $('.field-name-field-user-section').show();
        }
        else {
          $('.field-name-field-user-section').hide();
          $('.field-name-field-user-section').find('select').val("_none");
        }
      });
      
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