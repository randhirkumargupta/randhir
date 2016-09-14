/*
 * @file itg_ads.js
 * Contains all functionality related to Ads Management
 */

(function($) {
    Drupal.behaviors.itg_ads = {
        attach: function(context) {
            // Module Code start
            //$('.tabledrag-toggle-weight-wrapper').hide();
            $('.vertical-tabs').hide();

            // Disable edit mode of date fields
            $('input[name="field_ads_start_date[und][0][value][date]"]').keydown(false);
            $('input[name="field_ads_end_date[und][0][value][date]"]').keydown(false);
            // Module code end
            $('#edit-field-ads-template-selection-und').change(function() {
                var val = $('#edit-field-ads-template-selection-und').val();

                if (val == "Section") { // if section select then template variant should be reset
                //    $('#edit-field-ads-template-variants-und').val('');
                } else if (val == "Home") { // if home select then content/section selection should be reset
                    $('#edit-field-ads-section-selection-und').val('');
                //    $('#edit-field-ads-content-selection-und').val('');
                } else if (val == "Rest") { // if rest select then content/section selection and template variant should be reset 
                  //  $('#edit-field-ads-template-variants-und').val('');
                    $('#edit-field-ads-section-selection-und').val('');
                  //  $('#edit-field-ads-content-selection-und').val('');

                }

            });


        }

    };
})(jQuery, Drupal, this, this.document);