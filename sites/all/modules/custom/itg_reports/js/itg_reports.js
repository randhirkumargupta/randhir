/**
 * @file
 * A JavaScript file for reports view. 
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.my_custom_behavior = {
        attach: function (context, settings) {
            // Module code start here.
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
                $('#edit-state').css('display', 'none');
                $('#edit-from-state-wrapper').css('display', 'none');
            }
            // Module code ends here.
        }
    };
})(jQuery, Drupal, this, this.document);
