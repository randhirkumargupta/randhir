(function ($) {
    Drupal.behaviors.itg_user_reports = {
        attach: function (context, settings) {
            $("#itg-user-content-visit-report-form #edit-min-date").datepicker({
                maxDate: new Date(),
                minDate: new Date(1970, 01, 01),
                changeMonth: true,
                changeYear: true,
                dateFormat: 'dd-mm-yy',
            })
            $("#itg-user-content-visit-report-form #edit-max-date").datepicker({
                maxDate: new Date(),
                minDate: new Date(1970, 01, 01),
                changeMonth: true,
                changeYear: true,
                dateFormat: 'dd-mm-yy',
            })
        }
    };
}(jQuery));

                