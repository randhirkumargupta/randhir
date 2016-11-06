/*
 * @file itg_reporter.js
 * Contains all functionality related to Reporter
 */

(function($) {
    Drupal.behaviors.itg_reporter = {
        attach: function(context, settings) {
            var uid = settings.itg_reporter.settings.uid;
            var ntype = settings.itg_reporter.settings.ntype;
            var anchor = settings.itg_reporter.settings.anchor;
            var politician = settings.itg_reporter.settings.politician;

            var intialcelebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
            if (intialcelebrityvalue) {
                var initialhasexist = intialcelebrityvalue.indexOf(anchor) != -1;
            }
            if (intialcelebrityvalue) {
                var initialhasexist_poli = intialcelebrityvalue.indexOf(politician) != -1;
            }
            if (initialhasexist_poli)
            {
                $('#edit-field-constituancy-und-0-value').show();
                $('#edit-field-party-name-und-0-value').show();


            } else {
                $('#edit-field-constituancy-und-0-value').hide();
                $('#edit-field-party-name-und-0-value').hide();


            }
            if (initialhasexist) {
                $('#edit-field-story-category').show();
            }
            else {
                $('#edit-field-story-category').hide();
            }
            $('#edit-field-celebrity-pro-occupation-und').change(function() {
                var celebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
                // alert(celebrityvalue);
                var hasexist = celebrityvalue.indexOf(anchor) != -1;
                var initial_poli = celebrityvalue.indexOf(politician) != -1;
                if (hasexist) {
                    $('#edit-field-story-category').show();

                }
                else
                {
                    $('#edit-field-story-category').hide();
                    $('.dropbox-remove a').trigger('click');
                }

                if (initial_poli)
                {
                    $('#edit-field-constituancy-und-0-value').show();
                    $('#edit-field-party-name-und-0-value').show();


                } else {
                    $('#edit-field-constituancy-und-0-value').hide();
                    $('#edit-field-party-name-und-0-value').hide();


                }

            });


        }

    };
})(jQuery, Drupal, this, this.document);