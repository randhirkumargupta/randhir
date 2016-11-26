/*
 * @file itg_podcast.js
 * Contains all functionality related to podcast
 */

(function($) {
    Drupal.behaviors.itg_podcast = {
        attach: function(context, settings) {
            //var uid = settings.itg_podcast.settings.uid;

        }

    };
})(jQuery, Drupal, this, this.document);


jQuery(document).ready(function() {
    try {
        jQuery('#podcast-node-form #edit-field-story-category').find('label').append('<span class="form-required" title="This field is required.">*</span>');
        jQuery('#podcast-node-form #field-podcast-audio-upload-values').find('label').append('<span class="form-required" title="This field is required.">*</span>');
    }
    catch (e) {
    }
});