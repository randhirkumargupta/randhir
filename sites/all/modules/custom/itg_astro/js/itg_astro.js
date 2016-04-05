/*
 * @file itg_astro.js
 * Contains all functionality related to astro module.
 */

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_astro = {
    attach: function (context, settings) {

      // Hide Zodiac sign name field      
      $('.field-name-field-astro-zodiac-sign-name').css('display', 'none');

      // Code for astro node form to expand sef url and meta fields.
      var uid = Drupal.settings.uid;
      if (uid != 1) {
        $('#edit-metatags').show();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags-und-advanced').hide();
      }

      // Map date with frequency
      $('input[name="field_astro_frequency[und]"]').on('change', function () {

        var frequency = $('input[name="field_astro_frequency[und]"]:checked').val();
        switch (frequency) {
          case 'daily':
            var startDay = moment().format('MMM DD, YYYY');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(startDay);
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(startDay);
            $("#edit-title").val(startDay);

            break;
          case 'weekly':
            var startDay = moment().day(0); // Sun
            var endDay = moment().day(6); // Sat          
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(startDay.format('MMM DD, YYYY'));
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(endDay.format('MMM DD, YYYY'));
            var titleText = startDay.format('MMM DD, YYYY') + " - " + endDay.format('MMM DD, YYYY');
            $("#edit-title").val(titleText);

            break;
          case 'monthly':
            var firstDay = moment().date(1);
            var lastDay = moment().endOf('month');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(firstDay.format('MMM DD, YYYY'));
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val(lastDay.format('MMM DD, YYYY'));
            var titleText = firstDay.format('MMM DD, YYYY') + " - " + lastDay.format('MMM DD, YYYY');
            $("#edit-title").val(titleText);

            break;
          case 'yearly':
            var firstDay = moment().dayOfYear(1).format('MMM DD, YYYY');
            $('input[name="field_astro_date_range[und][0][value][date]"]').val(firstDay);
            $('input[name="field_astro_date_range[und][0][value2][date]"]').val('Dec 31, ' + moment().year());
            var startYear = moment().dayOfYear(1).format('MMM DD, YYYY');
            var endyear = "Dec 31, " + moment().year();
            $("#edit-title").val(startYear + " - " + endyear);
        }
      });

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
            case 'field_astro_frequency[und]':
              errorPlaceHolder = $('#edit-title').parent();
              break;
            default:
              errorPlaceHolder = element.parent();
          }
          error.appendTo(errorPlaceHolder);
        },
        rules: {
          'field_astro_frequency[und]': {
            required: true
          },
          'field_astro_zodiac[und][0][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][1][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][2][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][3][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][4][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][5][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][6][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][7][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][8][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][9][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][10][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_astro_zodiac[und][11][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Zodiac') {
                  return true;
                }
                else {
                  return false;
                }
              }
            },
            maxlength: 500
          },
          'field_story_category[und][]': {
            required: true,
            validateSignName: true
          },
          'field_astro_numerology_values[und][0][field_buzz_description][und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"').find('option:selected').text();
                if (astroType == 'Numerology') {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          },
          'field_astro_numerology_values[und][0][field_astro_select_number][und]': {
            validateSignName: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"').find('option:selected').text();
                if (astroType == 'Numerology') {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          },
          'field_astro_type[und]': {
            required: true,
            validateSignName: true
          },
          'field_astro_date_range[und][0][value2][date]': {
            required: true,
            date: true,
            validateRange: true,
          },
          'field_astro_video_thumbnail[und][0][fid]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                var video_field = $('input[name="field_astro_video[und][0][fid]"]').val();
                if ($(this).val() == 0 && astroType == 'Collective Content' && video_field != '0') {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_buzz_description[und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').val();
                if (astroType == '314') {
                  return true;
                }
                else {
                  return false;
                }
              }
            }
          },
          'field_astro_date_range[und][0][value][date]': {
            required: true,
            date: true
          }
        },
        messages: {
          'field_astro_frequency[und]': {
            remote: 'Astro for selected frequency is already filled.'
          }
        }
      });
      jQuery.validator.addMethod("validateRange", function (value, element) {
        return validateDateRange(value, element);
      }, "* Please enter valid date.");
      jQuery.validator.addMethod("validateSignName", function (value, element) {
        return validateSignNameValue(value, element);
      }, "* This field is required.");


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
            $('input[name="title"').val(startDate);
            if (startDate !== endDate) {
              return false;
            }
            else {
              return true;
            }
            break;
          case 'weekly':
            $('input[name="title"').val(startDate + ' - ' + endDate);
            if (days !== 6) {
              return false;
            }
            else {
              return true;
            }
            break;
          case 'monthly':
            $('input[name="title"').val(startDate + ' - ' + endDate);
            if (days == 29 || days == 30) {
              return true;
            }
            else {
              return false;
            }
            break;
          case 'yearly':
            $('input[name="title"').val(startDate + ' - ' + endDate);
            if (days !== 365) {
              return false;
            }
            else {
              return true;
            }
        }
      }

      // validate sign name drop down
      function validateSignNameValue(event, element) {
        if ($(element).val() == '_none') {
          return false;
        }
        else {
          return true;
        }
      }

      // Common function to reset all values
      function clear_form_elements(class_name) {
        jQuery("." + class_name).find(':input').each(function () {
          switch (this.type) {
            case 'text':
            case 'textarea':
              $(this).val('');
              break;
            case 'select-one':
              $(this).val('_none');
              break;
          }
        });
      }

      // Hide navigation label
      $('.node-astro-form .story-title-coll').css('display', 'none');
      $('.node-astro-form .story-title-zod').css('display', 'none');
      $('.node-astro-form .story-title-num').css('display', 'none');

      // Reset form if someone change astro type
      $("select[name='field_astro_type[und]']").on('change', function () {
        var astroType = $(this).val();
        var astroText = $(this).find('option:selected').text();
        switch (astroText) {
          // Collective Content
          case 'Collective Content':
            clear_form_elements('field-name-field-astro-zodiac');
            jQuery('.field-name-field-astro-zodiac .button-remove').mousedown();
            clear_form_elements('field-name-field-astro-numerology-values');
            jQuery('.field-name-field-astro-numerology-values .button-remove').each(function () {
              $(this).mousedown();
            });
            $('.node-astro-form .story-title-zod').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'none');
            $('.node-astro-form .story-title-coll').css('display', 'block');
            break;
            // Numerology  
          case 'Numerology':
            clear_form_elements('field-name-field-astro-zodiac');
            jQuery('.field-name-field-astro-zodiac .button-remove').mousedown();
            clear_form_elements('collective-wrapper');
            jQuery('.collective-wrapper .button-remove').mousedown();
            $('.node-astro-form .story-title-zod').css('display', 'none');
            $('.node-astro-form .story-title-coll').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'block');
            break;
            // Zodiac  
          case 'Zodiac':
            clear_form_elements('collective-wrapper');
            jQuery('.collective-wrapper .button-remove').mousedown();
            clear_form_elements('field-name-field-astro-numerology-values');
            jQuery('.field-name-field-astro-numerology-values .button-remove').each(function () {
              $(this).mousedown();
            });
            var sign_name = Drupal.settings.sign;
            var i = 0;
            for (var key in sign_name) {
              $('select[name="field_astro_zodiac[und][' + i + '][field_zodiac_sign][und]"]').val(sign_name[key]);
              ++i;
            }

            $('.node-astro-form .story-title-coll').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'none');
            $('.node-astro-form .story-title-zod').css('display', 'block');
            break;
          case 'Tarrot':
            $('.node-astro-form .story-title-coll').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'none');
            $('.node-astro-form .story-title-zod').css('display', 'none');
            clear_form_elements('collective-wrapper');
            jQuery('.collective-wrapper .button-remove').mousedown();
            clear_form_elements('field-name-field-astro-numerology-values');
            jQuery('.field-name-field-astro-numerology-values .button-remove').each(function () {
              $(this).mousedown();
            });
            clear_form_elements('field-name-field-astro-zodiac');
            jQuery('.field-name-field-astro-zodiac .button-remove').mousedown();
        }
      });

      if ($('select[name="field_astro_type[und]"').find('option:selected').text() == 'Collective Content') {
        $('.node-astro-form .story-title-coll').css('display', 'block');
      }
      if ($('select[name="field_astro_type[und]"').find('option:selected').text() == 'Numerology') {
        $('.node-astro-form .story-title-num').css('display', 'block');
      }
      if ($('select[name="field_astro_type[und]"').find('option:selected').text() == 'Zodiac') {
        $('.node-astro-form .story-title-zod').css('display', 'block');
      }

    }
  };
})(jQuery, Drupal, this, this.document);


