/*
 * @file itg_reporter.js
 * Contains all functionality related to Reporter
 */

(function ($) {
    Drupal.behaviors.itg_reporter = {
        attach: function (context, settings) {
            var uid = settings.itg_reporter.settings.uid;
            var ntype = settings.itg_reporter.settings.ntype;
            var anchor = settings.itg_reporter.settings.anchor;

            var intialcelebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
            if (intialcelebrityvalue) {
                var initialhasexist = intialcelebrityvalue.indexOf(anchor) != -1;
            }
            if (initialhasexist) {
                $('#edit-field-story-category').show();
            }
            else {
                $('#edit-field-story-category').hide();                
            }
            $('#edit-field-celebrity-pro-occupation-und').change(function () {
                var celebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
                // alert(celebrityvalue);
                var hasexist = celebrityvalue.indexOf(anchor) != -1;
                if (hasexist) {
                    $('#edit-field-story-category').show();

                }
                else
                {
                    $('#edit-field-story-category').hide();
                    $('.dropbox-remove a').trigger('click');
                }

            });


        }

    };
})(jQuery, Drupal, this, this.document);