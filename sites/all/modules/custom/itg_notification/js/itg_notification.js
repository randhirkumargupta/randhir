/*
 * @file itg_notification.js
 */

(function($) {
  Drupal.behaviors.itg_notification = {
    attach: function(context, settings) {

      var uid = settings.itg_notification.settings.uid;
      var nid = settings.itg_notification.settings.nid;

     
      // If user is not drupal admin
      if (uid !== 1) {
        $('.field-edit-link').hide();
        $('#edit-body-und-0-format').hide();
        $('.vertical-tabs-list').hide();
        $('#edit-metatags').show();
      }
      
      $('input[name="field_survey_start_date[und][0][value][date]"]').prop("readonly", true);
      $('#edit-field-cm-display-title-und-0-value').prop("readonly", true);
      
      // Assign story checkbox value (show/hide Content ID)
      if ($("#edit-field-ntf-assign-story-und-1").prop("checked") === true) {
        $('#edit-field-news-cid').show();

      }
      else {
        $('#edit-field-news-cid').hide();
      }
      
      // Assign story checkbox click event (show/hide Content ID)
      $("#edit-field-ntf-assign-story-und-1").on("click", function() {

        if ($(this).prop("checked") === true) {
          $('#edit-field-news-cid').show();
        }
        else {
          $('#edit-field-news-cid').hide();
        }
      });
      
      // Notification message title counter
      $('#edit-title').keyup(function() {
        var len = $(this).val().length;
        $('#notification-text-counter').text('Text Count: '+len);
      });
      
      // jQuery code to select device for Notification
      $('body').on('change', '.form-field-name-field-ntf-select-device .form-checkbox', function () {
        var el_value = $(this).attr('value');
        var el_check = $(this).is(':checked');
        var iOS = $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox[value="iOS"]').is(':checked');
        var Android = $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox[value="Android"]').is(':checked');
        var Windows = $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox[value="Windows"]').is(':checked');
        if (el_value == "all" && el_check == true) {
          $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox').attr('checked', true);
        }
        else if (el_value == "all" && el_check == false) {
          $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox').attr('checked', false);
        }
        else if (el_value != "all" && el_check == false) {
          $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox[value="all"]').attr('checked', false);
        }
        else if (el_value != "all" && iOS == true && Android == true && Windows == true) {
          $(this).parents('.form-field-name-field-ntf-select-device').find('.form-checkbox[value="all"]').attr('checked', true);
        }
      });
      
    }
  };
})(jQuery, Drupal, this, this.document);