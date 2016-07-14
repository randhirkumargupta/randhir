/*
 * @file itg_event_sponsor.js
 * Contains functionality related sponsor form
 */

(function($) {

    Drupal.behaviors.itg_event_sponsor_form = {
        attach: function(context, settings) {
            var uid = settings.itg_event_sponsor.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
                $('#edit-body-und-0-format').hide();
                $('.vertical-tabs-list').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();

            }
        }
    }
})(jQuery);