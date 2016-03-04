/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
  Drupal.behaviors.itg_users = {
    attach: function (context) {
        // Define role id
         var EXPERT = '21';
         var EDITOR = '6';
         var SECTIONEDITORANCHOR = '20';
         var COPYEDITOR = '5';
      
      // code for 
      $('.form-item-roles').hide();
      $('#edit-metatags').hide();
      $('#edit-timezone').hide();
      $('#edit-selected').change(function () {
        $('#edit-roles :checkbox:enabled').prop('checked', false);
        var checkboxId = 'edit-roles-' + $(this).val();
        $('#' + checkboxId).prop("checked", true);
      });
      
      
      $('#edit-field-mark-as-expert-und-1').click(function () {
        var EXPERT_ID = 'edit-roles-' + EXPERT;
        var MARK = $(this).is(':checked');
        if (MARK) {
          $('#' + EXPERT_ID).prop("checked", true);
        } else {
           $('#' + EXPERT_ID).prop("checked", false);
        }
       });
       
     
      // jQuery code for user registeration form
      var userSelect = $('select[name="selected"]');
      function userRegisterEdit(v) {
        var value = $(v).val();
        
        var markexpert = $('.field-name-field-mark-as-expert').find('.form-checkbox').is(':checked');
        if (value == EXPERT) {
          $('.field-name-field-user-section').show();
        } else if (value == COPYEDITOR || value == EDITOR || value == SECTIONEDITORANCHOR) {
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
        if (value == EXPERT) {
          $('.field-name-field-user-section').show();
          $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
          $('.field-name-field-mark-as-expert').hide();
        } else if (value == COPYEDITOR || value == EDITOR || value == SECTIONEDITORANCHOR) {
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

    }

  };
})(jQuery, Drupal, this, this.document);