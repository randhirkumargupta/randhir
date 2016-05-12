/*
 * @file itg_ugc.js
 * Contains all functionality User Generated Content
 */

(function ($) {
  Drupal.behaviors.itg_ugc = {
    attach: function (context, settings) {
             var uid = settings.itg_ugc.settings.uid;
           // code to hide body text format filter 
            if (uid != 1) {
               
                $('.vertical-tabs-list').hide();
                $('#edit-field-user-message-und-0-format').hide();
                $('.vertical-tabs').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();
            }
            
            jQuery('.reject-ugc').click(function() {                 
        var reject_status = 'reject';
        if (reject_status == 'reject') {                   
           var msg = confirm('Are you sure you want to reject this content?');
           if (msg == true) {
               return true;
           }
           return false; 
        }
        return true;                     
    });           
            
      $('#edit-field-ugc-ctype-und').change(function() {
                var contenttypevalue = $('#edit-field-ugc-ctype-und').val();
                // alert(contenttypevalue);
                if (contenttypevalue == 'photogallery' 
                        || contenttypevalue == 'blog' 
                        || contenttypevalue == 'audio'
                        || contenttypevalue == 'video'
                        || contenttypevalue == 'recipe'
                        || contenttypevalue == 'story'
                        || contenttypevalue == '_none') { // Image question
                    $('#edit-title').val('');
                    if (typeof CKEDITOR != "undefined") {
                    CKEDITOR.instances['edit-field-user-message-und-0-value'].setData('');
                }
                else
                {
                    $('#edit-field-user-message-und-0-value').val(''); 
                }
                    $('#edit-field-ugc-upload-photo-und-0-remove-button').mousedown();
                     $('#edit-field-astro-video-und-0-remove-button').mousedown();
                }
               
            }); 
            
            if ($('.form-field-name-field-ugc-ctype .form-select').val() == 'photogallery') {
                
                $('.form-field-name-field-ugc-ctype').siblings('.form-field-name-field-ugc-upload-photo').find('.form-item > label').html('Upload Photo <span class="form-required" title="This field is required.">*</span>');
            }
            $('.form-field-name-field-ugc-ctype').on('change', '.form-select', function () {
                
                var selectedVal = $(this).val();
                if (selectedVal == 'photogallery') {
                    $(this).parent().parent().siblings('.form-field-name-field-ugc-upload-photo').find('.form-item > label').html('Upload Photo <span class="form-required" title="This field is required.">*</span>');
                }
            });
            
            
    }

  };
})(jQuery, Drupal, this, this.document);
