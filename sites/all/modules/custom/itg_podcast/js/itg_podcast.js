/*
 * @file itg_podcast.js
 * Contains all functionality related to podcast
 */

(function($) {
    Drupal.behaviors.itg_podcast = {
        attach: function(context, settings) {
            try {
                jQuery('#podcast-node-form #edit-field-story-category').find('label').html('Category <span class="form-required" title="This field is required.">*</span>');
                jQuery('#podcast-node-form #field-podcast-audio-upload-values').find('th label').html('Audio Upload <span class="form-required" title="This field is required.">*</span>');
            }
            catch (e) {
            }
            
             jQuery('.plupload_start').on('click', function() {
                $('#podcast-node-form').ajaxComplete(function(event, request, settings) {  
                    if (jQuery('input[name="files[field_podcast_audio_upload_und_0_field_podcast_upload_audio_file_und_0]"]').val() == 0) {
                        jQuery('.field-multiple-table tbody tr:first .cancel').mousedown();
                        jQuery( this ).off( event );                      
                    }

                });
            });
        }

    };
})(jQuery, Drupal, this, this.document);