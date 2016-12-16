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
                $('.form-item-field-constituancy-und-0-value').show();
                $('#edit-field-party-name').show();



            } else {
                $('#edit-field-constituancy-und-0-value').hide();

                $('#edit-field-party-name-und-0-value').hide();
                $('.form-item-field-constituancy-und-0-value').hide();
                $('#edit-field-party-name').hide();


            }
            if (initialhasexist) {
                $('#edit-field-story-category').show();
            } else {
                $('#edit-field-story-category').hide();
            }
            // Hide by default movie name field.
            $('#edit-field-reporter-movie-name').hide();
            var occupationname = $('select[name="field_celebrity_pro_occupation[und][]"').find('option:selected').text();            
            if (~occupationname.indexOf('Celebrity')) {
                $('#edit-field-reporter-movie-name').show();
            }
            $('#edit-field-celebrity-pro-occupation-und').change(function () {
                var celebrityvalue = $('#edit-field-celebrity-pro-occupation-und').val();
                var hasexist = celebrityvalue.indexOf(anchor) != -1;
                var celebrity = $(this).find('option:selected').text();
                var subcelebrity = "Celebrity";
                var initial_poli = celebrityvalue.indexOf(politician) != -1;
                if (hasexist) {
                    $('#edit-field-story-category').show();
                } else
                {
                    $('#edit-field-story-category').hide();
                    $('.dropbox-remove a').trigger('click');
                }
                if (initial_poli)
                {
                    $('#edit-field-constituancy-und-0-value').show();
                    $('#edit-field-party-name-und-0-value').show();
                    $('.form-item-field-constituancy-und-0-value').show();
                    $('#edit-field-party-name').show();
                } else {
                    $('#edit-field-constituancy-und-0-value').hide();
                    $('#edit-field-party-name-und-0-value').hide();
                    $('.form-item-field-constituancy-und-0-value').hide();
                    $('#edit-field-party-name').hide();
                }
                // Show hide logic for career graph field.
                if (~celebrity.indexOf(subcelebrity)) {
                    $('#edit-field-reporter-movie-name').show();
                } else {
                    clear_form_elements('form-field-name-field-reporter-movie-name')
                    $('#edit-field-reporter-movie-name').hide();
                }

            });

            // Common function to reset all values.
            function clear_form_elements(class_name) {
                jQuery("." + class_name).find(':input').each(function () {
                    switch (this.type) {
                        case 'text':
                        case 'textarea':
                            $(this).val('');
                            break;

                        case 'select-one':
                            $(this).val('_none');
                            break;
                    }
                });
            }

            // restrict mouse down on datefield.
            // date-clear form-text hasDatepicker date-popup-init valid
            $('input .hasDatepicker').keypress(function (e) {
                return false
            });

        }

    };
})(jQuery, Drupal, this, this.document);