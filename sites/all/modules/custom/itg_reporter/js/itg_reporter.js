/*
 * @file itg_reporter.js
 * Contains all functionality related to Reporter
 */

(function ($) {
    Drupal.behaviors.itg_reporter = {
        attach: function (context, settings) {
            var uid = settings.itg_reporter.settings.uid;
            var ntype = settings.itg_reporter.settings.ntype;

            // code to hide body text format filter 
            if (uid != 1 && ntype) {
                $('.vertical-tabs-list').hide();
                $('#edit-field-user-message-und-0-format').hide();
                $('.vertical-tabs').hide();
                $('#edit-metatags').show();
                $('#edit-metatags-und-advanced').hide();

            }
        }

    };
})(jQuery, Drupal, this, this.document);