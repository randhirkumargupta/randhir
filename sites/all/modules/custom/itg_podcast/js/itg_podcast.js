/*
 * @file itg_podcast.js
 * Contains all functionality related to podcast
 */

(function($) {
    Drupal.behaviors.itg_podcast = {
        attach: function(context, settings) {
            try {
                jQuery('#podcast-node-form #edit-field-story-category').find('label').html('Category <span class="form-required" title="This field is required.">*</span>');
                jQuery('#podcast-node-form #field-podcast-audio-upload-values').find('label').html('Audio Upload <span class="form-required" title="This field is required.">*</span>');
            }
            catch (e) {
            }
        }

    };
})(jQuery, Drupal, this, this.document);