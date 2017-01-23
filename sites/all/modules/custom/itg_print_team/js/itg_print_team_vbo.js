/**
 * @file
 * A JavaScript file for the theme.
 */
(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_print_vbo = {
        attach: function (context, settings) {
            // module code start here.    
            $('#views-form-manage-print-team-page-1 .form-checkbox').change(function () {
                if ($(this).is(":checked")) {
                    var magazine = $(this).parent().siblings().text();                    
                    if (magazine.length > 0) {
                        console.log(magazine);
                        $('select[name="pti_magazine"] option:contains("- Select Magazine -")').attr('selected', 'selected');
                        $('select[name="pti_magazine"] option:contains("' + magazine + '")').attr('selected', 'selected');
                        $('select[name="pti_magazine"]').trigger("change");
                    }
                    else {
                        $('select[name="pti_magazine"] option:contains("- Select Magazine -")').attr('selected', 'selected');
                        $('select[name="pti_magazine"]').trigger("change");
                    }
                }
            });


            $('.itg-associate').on('click', function (event) {
                event.preventDefault();
                $('#edit-submit--2').trigger('click');
            });
            $('.itg-rating').on('click', function (event) {
                event.preventDefault();
                $('#edit-submit-rating').trigger('click');
            });
            // Module code ends here.
        }
    };


})(jQuery, Drupal, this, this.document);
