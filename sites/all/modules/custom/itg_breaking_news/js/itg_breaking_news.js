/*
 * @file itg_breaking_news.js
 */

/*
 * @file itg_story.js
 * Contains all functionality related to story
 */

(function ($) {
    Drupal.behaviors.itg_story = {
        attach: function (context, settings) {
            var uid = settings.itg_breaking_news.settings.uid;
            // code to hide body text format filter 
            if (uid != 1) {
            $('#edit-body-und-0-format').hide();
            }
                        
            // code for disbale date field in breaking news      
            $("#edit-field-publish-time-und-0-value-datepicker-popup-0").datepicker({minDate: -1, maxDate: -2}).attr("disabled", 'disabled');

            // default check all checkbox when all is check 
            if ($("#edit-field-mobile-subscribers-und-all").is(':checked')) {
                // code to checked all checkbox when all is checked in mobile subscriber
                $("#edit-field-mobile-subscribers-und-ios").prop("checked", true);
                $("#edit-field-mobile-subscribers-und-android").prop("checked", true);
                $("#edit-field-mobile-subscribers-und-windows").prop("checked", true);

            }

            //code to check unchek checkbox when all checkbox is checked
            $('#edit-field-mobile-subscribers-und-all').click(function () {
                if ($("#edit-field-mobile-subscribers-und-all").is(':checked')) {
                    // code to checked all checkbox when all is checked in mobile subscriber
                    $("#edit-field-mobile-subscribers-und-ios").prop("checked", true);
                    $("#edit-field-mobile-subscribers-und-android").prop("checked", true);
                    $("#edit-field-mobile-subscribers-und-windows").prop("checked", true);

                } else {
                    // unchecked all checkbox      
                    $("#edit-field-mobile-subscribers-und-ios").prop("checked", false);
                    $("#edit-field-mobile-subscribers-und-android").prop("checked", false);
                    $("#edit-field-mobile-subscribers-und-windows").prop("checked", false);

                }

            });

            //code to uncheck all checkbox value when any other checbok is unchecked
            $('#edit-field-mobile-subscribers-und-ios,#edit-field-mobile-subscribers-und-android,#edit-field-mobile-subscribers-und-windows').click(function () {
                $("#edit-field-mobile-subscribers-und-all").prop("checked", false);

            });

        }

    };
})(jQuery, Drupal, this, this.document);
