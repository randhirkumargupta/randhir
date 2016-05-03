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
            
      $('#edit-field-ugc-content-type-und').change(function() {
                var contenttypevalue = $('#edit-field-ugc-content-type-und').val();
                // alert(contenttypevalue);
                if (contenttypevalue == 'photogallery' 
                        || contenttypevalue == 'blog' 
                        || contenttypevalue == 'audio'
                        || contenttypevalue == 'video'
                        || contenttypevalue == 'recipe'
                        || contenttypevalue == 'story'
                        || contenttypevalue == '_none') { // Image question
                    $('#edit-title').val('');
                    CKEDITOR.instances['edit-field-user-message-und-0-value'].setData('');
                    $('#edit-field-ugc-upload-photo-und-0-remove-button').mousedown();
                     $('#edit-field-astro-video-und-0-remove-button').mousedown();
                }
               
            }); 
    }

  };
})(jQuery, Drupal, this, this.document);
