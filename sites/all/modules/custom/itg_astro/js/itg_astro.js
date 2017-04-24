/**
 * @file
 * Contains all functionality related to astro module.
 */

(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.itg_astro = {
    attach: function (context, settings) {

      // Hide Zodiac sign name field.
      $('.field-name-field-astro-zodiac-sign-name').css('display', 'none');

      // Code for astro node form to expand sef url and meta fields.
      var uid = Drupal.settings.uid;      

      // Map date with frequency.
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
            var endDay = moment().day(6); // Sat.
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

      // validateJobSearch validation function.
      $("#astro-node-form").validate({
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

            case 'field_astro_date_range[und][0][value2][date]':
              errorPlaceHolder = element.parent().parent();
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
          'field_story_category[und][hierarchical_select][selects][0]': {
            required: true,
            validate_astro_category: true
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
          'field_astro_numerology_values[und][1][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][2][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][3][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][4][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][5][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][6][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][7][field_buzz_description][und][0][value]': {
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
          'field_astro_numerology_values[und][8][field_buzz_description][und][0][value]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][1][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][2][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][3][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][4][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][5][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][6][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][7][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
          'field_astro_numerology_values[und][8][field_astro_select_number][und]': {
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
            },
            dupliNumero: {
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
                  $('.form-item-field-astro-video-thumbnail-und-0 label').html('Video Thumbnail <span class="form-required" title="This field is required."> *</span>');
                }
                return true;
              }
            }
          },
          'field_buzz_description[und][0][value]': {
            required: {
              depends: function () {
                var astroType = $('select[name="field_astro_type[und]"]').find('option:selected').text();
                if (astroType == 'Collective Content') {
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
          'field_buzz_description[und][0][value]': {
            required: 'This field is required.'
          },
          'field_story_category[und][]': {
            required: 'This field is required.'
          },
          'field_astro_video_thumbnail[und][0][fid]': {
            required: 'This field is required.'
          },
          'field_astro_type[und]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][0][field_astro_select_number][und]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][0][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][1][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][2][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][3][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][4][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][5][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][6][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][7][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_numerology_values[und][8][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][0][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][1][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][2][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][3][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][4][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][5][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][6][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][7][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][8][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][9][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][10][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          },
          'field_astro_zodiac[und][11][field_buzz_description][und][0][value]': {
            required: 'This field is required.'
          }
        }
      });
      jQuery.validator.addMethod("validateRange", function (value, element) {
        return validate_date_range(value, element);
      }, "Please enter valid date.");
      jQuery.validator.addMethod("validateSignName", function (value, element) {
        return validate_sign_name_value(value, element);
      }, "This field is required.");
      jQuery.validator.addMethod("validate_astro_category", function (value, element) {
        return validate_astro_category_name(value, element);
      }, "This field is required.");
      jQuery.validator.addMethod("dupliNumero", function (value, element) {
        return dupli_numero_value(value, element);
      }, "This is duplicate value.");

      // Validate date difference.
      function validate_date_range(value, element) {
        var frequency = $('input[name="field_astro_frequency[und]"]:checked').val();
        var startDate = $('input[name="field_astro_date_range[und][0][value][date]"]').val();
        var endDate = $('input[name="field_astro_date_range[und][0][value2][date]"]').val();

        if (moment(startDate) > moment(endDate)) {
          return false;
        }
        if (frequency === 'daily') {
          $('input[name="title"').val(startDate);
        }
        else {
          $('input[name="title"').val(startDate + ' - ' + endDate);
        }

        return true;
      }
      
      // Validate select program field. 
      function validate_astro_category_name(value, element) {
        var selected_term = $('.form-item-field-story-category-und .dropbox').find('.dropbox-selected-item').text();
        if (selected_term !== 'undefined' && selected_term.length > 0) {
          return true;
        }
        else {
          return false;
        }        
      }
      // Validate sign name drop down.
      function validate_sign_name_value(event, element) {        
        if ($(element).val() == '_none') {
          
          return false;
        }
        else {
          return true;
        }
      }

      // Check duplicate numerology field value.
      function dupli_numero_value(value, element) {
        var counter = 0;
        jQuery('.form-field-name-field-astro-numerology-values').find('.form-select').each(function () {
          if ($(this).val() == value) {
            ++counter;
          }
        });
        if (counter >= 2) {
          return false;
        }
        else {
          return true;
        }
      }

      // Common function to reset all values.
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

      // Hide navigation label.
      $('.node-astro-form .story-title-coll').css('display', 'none');
      $('.node-astro-form .story-title-zod').css('display', 'none');
      $('.node-astro-form .story-title-num').css('display', 'none');

      // Reset form if someone change astro type.
      $("select[name='field_astro_type[und]']").on('change', function () {        
        var astroText = $(this).find('option:selected').text();
        switch (astroText) {
          // Collective Content.
          case 'Collective Content':            
            $('.node-astro-form .story-title-zod').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'none');
            $('.node-astro-form .story-title-coll').css('display', 'block');
            break;

            // Numerology.
          case 'Numerology':            
            $('.node-astro-form .story-title-zod').css('display', 'none');
            $('.node-astro-form .story-title-coll').css('display', 'none');
            $('.node-astro-form .story-title-num').css('display', 'block');
            break;

            // Zodiac.
          case 'Zodiac':            
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

      $('input[name="field_astro_date_range[und][0][value][date]"]').keydown(false);
      $('input[name="field_astro_date_range[und][0][value2][date]"]').keydown(false);
      $('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);

    }
  };
})(jQuery, Drupal, this, this.document);
