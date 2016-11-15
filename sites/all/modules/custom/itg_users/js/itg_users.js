/*
 * @file itg_users.js
 * Contains all functionality related to users
 */

(function ($) {
  Drupal.behaviors.itg_users = {
    attach: function (context, settings) {
         var uid = settings.itg_users.settings.uid;
            if (uid != 1) {
                // Define role id
                var EXPERT = '21';
                var EDITOR = '6';
                var SECTIONEDITORANCHOR = '20';
                var COPYEDITOR = '5';
                var SITE_ADMIN = '10';
                $('#edit-field-user-section > .form-type-select > label').html('Section<span class="form-required"> *</span>');
                $('.form-item-current-pass .description').hide();
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
                    } else if (value == COPYEDITOR || value == EDITOR || value == SECTIONEDITORANCHOR || value == SITE_ADMIN) {
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
                
                var roleSelected = $('#user-register-form, #user-profile-form').find('select[name="selected"]').val();
                var expertCheck = $('.field-name-field-mark-as-expert').find('.form-checkbox').is(':checked');
                if (roleSelected == EXPERT) {
                  $('#edit-field-user-section > .form-type-select > label').html('Section');
                  $('.user-configurations').show();
                  if(!expertCheck){
                    $('.field-name-field-mark-as-expert').hide();
                  }
                } else if (roleSelected == COPYEDITOR || roleSelected == EDITOR || roleSelected == SECTIONEDITORANCHOR || roleSelected == SITE_ADMIN) {
                  $('.user-configurations').show();
                  if(!expertCheck){
                    $('.field-name-field-user-section').hide();
                  }
                }
                
                $('#user-register-form, #user-profile-form').on('change', 'select[name="selected"]', function () {
                  
                    var value = $(this).val();
                    $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
                    
                    if (value == EXPERT) {
                      
                      $('#edit-field-user-section > .form-type-select > label').html('Section');
                      $('.user-configurations').show().find('.field-name-field-user-section').show().prev().hide();
                      $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
                        
                    } else if (value == COPYEDITOR || value == EDITOR || value == SECTIONEDITORANCHOR || value == SITE_ADMIN) {
                      
                      $('#edit-field-user-section > .form-type-select > label').html('Section<span class="form-required"> *</span>');
                      $('.field-name-field-user-section').find('select').val("_none");
                      $('.user-configurations').show().find('.field-name-field-user-section').hide().prev().show();
                      
                    } else {
                      
                      $('.field-name-field-user-section').find('select').val("_none");
                      $('.field-name-field-mark-as-expert').find('.form-checkbox').attr('checked', false);
                      $('.user-configurations').hide();
                      
                    }
                });
                var mark_as_expert = $('.field-name-field-mark-as-expert').find('.form-checkbox').is(':checked');
                if(mark_as_expert){
                  $('.field-name-field-user-section').show();
                }
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
            
    }
  };
})(jQuery, Drupal, this, this.document);

// code for moderation value change on click of dropdown and save story 
jQuery(document).ready(function() {
    jQuery('#edit-submit').click(function() {                 
        var status_val = jQuery("input[name='status']:checked").val();
        if (status_val == 0) {                   
           var msg = confirm("Are you sure, you want to block user?");
           if (msg == true) {
               return true;
           }
           return false; 
        }                             
    });                  
});