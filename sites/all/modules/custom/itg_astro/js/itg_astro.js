/*
 * @file itg_astro.js
 * Contains all functionality related to astro module.
 */

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_astro = {
    attach: function (context, settings) {

      // Hide Zodiac sign name field      
      $('.field-name-field-astro-zodiac-sign-name').css('display', 'none');

      // Change title and date range on click daily radio button
      $('input[name="field_astro_frequency[und]"]').on('change', function () {
        var frequency = $('input[name="field_astro_frequency[und]"]:checked').val();
        switch (frequency) {
          case 'daily':
            var startDay = moment().format('MMM DD, YYYY');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(startDay);
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(startDay);
            $("#edit-title").val(startDay);
            check_duplicate();

            break;
          case 'weekly':
            var startDay = moment().day(0); // Sun
            var endDay = moment().day(6); // Sat          
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(startDay.format('MMM DD, YYYY'));
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(endDay.format('MMM DD, YYYY'));
            var titleText = startDay.format('MMM DD, YYYY') + " - " + endDay.format('MMM DD, YYYY');
            $("#edit-title").val(titleText);
            check_duplicate();

            break;
          case 'monthly':
            var firstDay = moment().date(1);
            var lastDay = moment().endOf('month');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(firstDay.format('MMM DD, YYYY'));
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(lastDay.format('MMM DD, YYYY'));
            var titleText = firstDay.format('MMM DD, YYYY') + " - " + lastDay.format('MMM DD, YYYY');
            $("#edit-title").val(titleText);
            check_duplicate();

            break;
          case 'yearly':
            var firstDay = moment().dayOfYear(1).format('MMM DD, YYYY');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(firstDay);
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val('Dec 31, ' + moment().year());
            var startYear = moment().dayOfYear(1).format('MMM DD, YYYY');
            var endyear = "Dec 31, " + moment().year();
            $("#edit-title").val(startYear + " - " + endyear);
            check_duplicate();
        }
      });

      // Hide date range field from display      
      $('#edit-field-astro-numerology-values').css('display', 'none');

      // Show numerology values
      $("#edit-field-numerology-und-1").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'block');
      });

      // Hide numerology values
      $("#edit-field-numerology-und-0").click(function () {
        $('#edit-field-astro-numerology-values').css('display', 'none');
      });

      // Edit case if values are available 
      var num = $('input[name="field_numerology[und]"]:checked').val();
      if (num == 1) {
        $('#edit-field-astro-numerology-values').css('display', 'block');
      }

      // Code for astro node form to expand sef url and meta fields.
      var uid = Drupal.settings.uid;
      if (uid != 1) {
        $('#edit-metatags').show();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags-und-advanced').hide();
      }

      //Check duplicacy on title for magazine
      function check_duplicate() {
        $(".form-item-title .error").html('');
        var title = $('#edit-title').val();
        var trimmed_title = $.trim(title);

        //Call Ajax
        $.ajax({
          url: Drupal.settings.uid.base_url + "/check-duplicate-title/" + Drupal.settings.uid.type + '/' + Drupal.settings.uid.nid,
          type: 'post',
          data: {'title': trimmed_title},
          dataType: "JSON",
          success: function (data) {
            if (data == false) {
              $(".form-item-title").append($('<span class="error">Astro for selected frequency is already filled.</span>'));
            }
            else {
              $(".form-item-title .error").html('');
            }
          }
        });
      }     
      
      // validateJobSearch validation function            
      $("#astro-node-form").validate({
        submitHandler: function (form) {
          $('input:submit').attr('disabled', 'disabled');
          form.submit();
        },
        onfocusout: function (element) {
          $(element).valid();
        },
        ignore: '',
        errorElement: 'span',
        errorPlacement: function (error, element) {
          var elementName = element.attr('name');
          var errorPlaceHolder = '';
          switch (elementName) {
            case 'field_astro_zodiac[und][0][field_astro_thumb_icon][und][0][fid]':
              errorPlaceHolder = element.parent().parent().parent();
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {
          'title': {
            remote: {
              url: Drupal.settings.uid.base_url + "/check-duplicate-title/" + Drupal.settings.uid.type + '/' + Drupal.settings.uid.nid,
              type: "post",
              data: {
                title: function () {
                  return jQuery("input[name='title']").val();
                }
              }
            }
          },
          'field_astro_zodiac[und][0][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][1][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][2][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][3][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][4][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][5][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][6][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][7][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][8][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][9][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][10][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_astro_zodiac[und][11][field_buzz_description][und][0][value]': {
            required: true
          },
          'field_story_category[und][]': {
            required: true
          },
          'field_astro_zodiac[und][0][field_zodiac_sign][und]': {
            required: true
          },
          'field_astro_numerology_values[und][0][field_story_source_id][und][0][value]': {
            required: {
              depends: function () {
                var numerology = $('input[name="field_numerology[und]"]:checked').val();
                if (numerology == 1) {
                  return true;
                }
              }
            },
            number: true
          },
          'field_astro_numerology_values[und][0][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var numerology = $('input[name="field_numerology[und]"]:checked').val();
                if (numerology == 1) {
                  return true;
                }
              }
            }
          },
          'field_astro_date_range[und][0][value2][date]': {
            validateRange: true
          }
        },
        messages: {
          'title': {
            remote: 'Astro for selected frequency is already filled.'
          }
        }
      });
      jQuery.validator.addMethod("validateRange", function(value, element) {                    
        return validateDateRange(value, element);
      }, "* Please enter valid date.");
      
      // validate date difference
      function validateDateRange(value, element) {
        var frequency = $('input[name="field_astro_frequency[und]"]:checked').val();
        var startDate = $('input[name="field_astro_date_range[und][0][value][date]"]').val();
        var endDate = $('input[name="field_astro_date_range[und][0][value2][date]"]').val();
        var momenta = moment(startDate, 'MMM DD YYYY');
        var momentb = moment(endDate, 'MMM DD YYYY');
        var days = momentb.diff(momenta, 'days');        
        switch (frequency) {
          case 'daily':            
            if (startDate !== endDate) {
              return false;
              console.log(startDate+' '+endDate);
            }
            else {
              return true;
            }
            break;
          case 'weekly':            
            
            if (days !== 6) {
              return false;
            }
            else {
              return true;
            }
            break;
          case 'monthly':
            if (days == 29 || days == 30) {
              return true;
            }
            else {
              return false;
            }
            break;
          case 'yearly': 
            if (days !== 365) {
              return false;
            }
            else {
              return true;
            }            
        }
      }
      
      // Change title it someone changed date range manually
      $('select[name="field_story_category[und][]"]').on('change', function() {
        var startDate = $('input[name="field_astro_date_range[und][0][value][date]"]').val();
        var endDate = $('input[name="field_astro_date_range[und][0][value2][date]"]').val();
        $('#edit-title').val(startDate+' - '+endDate);
      });

    }
  };
})(jQuery, Drupal, this, this.document);


