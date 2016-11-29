/**
 * @file
 * A JavaScript file for reports view. 
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.my_custom_behavior = {
        attach: function (context, settings) {
            // Module code start here.
            
            // Disable future date from date popup.
            function itg_report_disable_future_date() {
                $("#edit-date-filter-min-datepicker-popup-0").datepicker({
                    maxDate: new Date(),
                    minDate: new Date(1970, 01, 01),
                    changeMonth: true,
                    changeYear: true,
                    dateFormat: 'yy-mm-dd',
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() + 1);
                        $("#edit-date-filter-max-datepicker-popup-0").datepicker("option", "minDate", dt);
                    }
                });
                $("#edit-date-filter-max-datepicker-popup-0").datepicker({
                    maxDate: new Date(),
                    minDate: new Date(1970, 01, 01),
                    changeMonth: true,
                    changeYear: true,
                    dateFormat: 'yy-mm-dd',
                    onSelect: function (selected) {
                        var dt = new Date(selected);
                        dt.setDate(dt.getDate() - 1);
                        $("#edit-date-filter-min-datepicker-popup-0").datepicker("option", "maxDate", dt);
                    }
                });
            }
            
            // Set moderation filter option based on yes or no.
            $('#edit-moderation').on('change', function () {
                var moderation = $('#edit-moderation').find(":selected").text();
                if (moderation === 'No') {
                    $('select[name="from_state"]').find('option[value="draft"]').attr("selected", true);
                    $("#edit-state option:selected").removeAttr("selected");
                    $("#edit-state option[value='published']").prop("selected", true);
                } else if (moderation === 'Yes') {
                    $('select[name="from_state"]').find('option[value="All"]').attr("selected", true);
                    $("#edit-state option:selected").removeAttr("selected");
                    var values = "needs_review,rejected";
                    $.each(values.split(","), function (i, e) {
                        $("#edit-state option[value='" + e + "']").prop("selected", true);
                    });
                } else {
                    $('select[name="from_state"]').find('option[value="All"]').attr("selected", true);
                    $("#edit-state option:selected").removeAttr("selected");
                }

            });

            // Copy Moderation dropdown under actual moderation field.
            if ($('body').hasClass('page-report-filed-content')) {
                $("#edit-moderation").appendTo("#edit-state-wrapper .views-widget");
                //$('#edit-state').css('display', 'none');
                $('#edit-from-state-wrapper').css('display', 'none');
                $("#edit-state option[value='draft']").remove();
                // Disbale future date.
                itg_report_disable_future_date();
            }            
            
            if ($('body').hasClass('page-comparative-reports')) {
                itg_report_disable_future_date();
            }
            // Module code ends here.
        }
    };
})(jQuery, Drupal, this, this.document);
