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
            var startDay = moment().format('MMM Do YYYY');
            $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay);
            $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(startDay);
            $("#edit-title").val(startDay);
            var is_valid = validateAstroNodeForm('title');
            if (is_valid == false) {
              return false;
            }
            break;
          case 'weekly':
            var startDay = moment().day(0); // Sun
            var endDay = moment().day(6); // Sat          
            $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(startDay.format('MMM Do YYYY'));
            $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(endDay.format('MMM Do YYYY'));
            var titleText = startDay.format('MMM Do YYYY') + " - " + endDay.format('MMM Do YYYY');
            $("#edit-title").val(titleText);
            var is_valid = validateAstroNodeForm('title');
            if (is_valid == false) {
              return false;
            }
            break;
          case 'monthly':
            var firstDay = moment().date(1);
            var lastDay = moment().endOf('month');
            $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay.format('MMM Do YYYY'));
            $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val(lastDay.format('MMM Do YYYY'));
            var titleText = firstDay.format('MMM Do YYYY') + " - " + lastDay.format('MMM Do YYYY');
            $("#edit-title").val(titleText);
            var is_valid = validateAstroNodeForm('title');
            if (is_valid == false) {
              return false;
            }
            break;
          case 'yearly':
            var firstDay = moment().dayOfYear(1).format('MMM Do YYYY');
            $('#edit-field-astro-date-range-und-0-value-datepicker-popup-0').val(firstDay);
            $('#edit-field-astro-date-range-und-0-value2-datepicker-popup-0').val('Dec 31st ' + moment().year());
            var startYear = moment().dayOfYear(1).format('MMM Do YYYY');
            var endyear = "Dec 31st " + moment().year();
            $("#edit-title").val(startYear + " - " + endyear);
            var is_valid = validateAstroNodeForm('title');
            if (is_valid == false) {
              return false;
            }
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
        $('#edit-field-recipe-description-und-0-format').hide();
        $('#edit-metatags').show();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags-und-advanced').hide();
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
          'field_astro_zodiac[und][0][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][1][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][2][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][3][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][4][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][5][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][6][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][7][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][8][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][9][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][10][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
          },
          'field_astro_zodiac[und][11][field_astro_thumb_icon][und][0][fid]': {
            required: {
              depends: function () {
                if ($(this).val() == 0) {
                  $(this).removeAttr('value');
                }
                return true;
              }
            }
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
          }
        },
        messages: {
          'title': {
            remote: 'Astro for selected frequency is already filled.'
          }
        }
      });


    }
  };
})(jQuery, Drupal, this, this.document);


