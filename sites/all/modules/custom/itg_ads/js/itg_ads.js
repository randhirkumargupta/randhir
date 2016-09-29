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
                    var opt = $('select[name="field_ads_select_secton_option[und]"]').val();
                    if (opt != '_none'){
                   $('select[name="field_ads_select_secton_option[und]"]').html('<option value="_none">-None-</option>');
                    }
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
            $('#edit-field-ads-section-selection-und').change(function() {
                $('#edit-field-ads-placeholder-und--3').find('option').remove();
            });

            $('select[name="field_ads_select_secton_option[und]"]').change(function() {
                var val = $(this).val();
                if (val == "_none") { // if section select then template variant should be reset
                    $('select[name="field_ads_placeholder[und]"]').html("");
                }
            });
            
//            $('#edit-field-ads-template-selection-und').change(function() {
//                var val = $('#edit-field-ads-template-selection-und').val();
//                alert("hi");
//                if (val == "Home" || val == "Rest") { // if section select then template variant should be reset
//                    alert(val);
//                    //$('select[name="field_ads_select_secton_option[und]"]').html("");
//                }
//            });
            

        }

    };
})(jQuery, Drupal, this, this.document);