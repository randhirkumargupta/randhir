(function ($, Drupal, window, document, undefined) {
    Drupal.behaviors.itg_syndication = {
        attach: function (context, settings) {
            var base_url = settings.itg_syndication.settings.base_url;
            //code for magazine callback

            $('#edit-magazine-name', context).change(function (event) {

                var magazine = $("#edit-magazine-name").val();

                var post = "&magazine=" + magazine;

                $.ajax({
                    'url': base_url + '/magazine-check-ajax',
                    'data': post,
                    'type': 'POST',
                    // dataType: 'json',
                    'success': function (data)
                    {

                        $('#edit-issue').html(data);

                    }
                });

            });

            // Place your code here.
            // Common function to reset all values
            function itg_syndication_clear_form(class_name) {
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

            // Disable date field
            $('input[name="field_story_expiry_date[und][0][value][date]"]').keydown(false);

            // Clear hidden fields value
            $('select[name="field_content_sharing_mode[und]"]').on('change', function () {
                switch ($(this).val()) {
                    case '1':
                        itg_syndication_clear_form('group-syndication-ftp');
                        itg_syndication_clear_form('field-name-field-email-address');
                        break;

                    case '2':
                        itg_syndication_clear_form('field-name-field-service-fetch-link');
                        itg_syndication_clear_form('field-name-field-email-address');
                        break;

                    case '3':
                        itg_syndication_clear_form('field-name-field-service-fetch-link');
                        itg_syndication_clear_form('group-syndication-ftp');
                }
            });

            // Change val
            $('select[name="client_title"]').on('change', function () {
                $('input[name="itg_row_selector_client"]').val($(this).val());
            });
            $('select[name="type"]').on('change', function () {
                $('input[name="itg_row_selector_web_property"]').val($(this).val());
            });
            $('select[name="issue"]').on('change', function () {
                $('input[name="itg_row_selector_issue"]').val($(this).val());
            });
        }
    };


})(jQuery, Drupal, this, this.document);
