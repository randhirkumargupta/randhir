/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function ($) {

    Drupal.behaviors.itg_mobile_newservice_form = {
        attach: function (context, settings) {
            // default hide add another item for Email address
            jQuery('#edit-field-email-address-und-add-more').hide();
            jQuery('.form-item-field-email-address-und-0-value label').hide();
            jQuery('#edit-field-email-address-und-1-value').hide();
            // default hide FTP label
            jQuery('#itg-group-service-ftp').hide();
            $('.form-item-field-service-fetch-link-und-0-value').hide();
            $('#edit-field-content-sharing-mode-und input').click(function () {
                var val = $(this).val();
                if (val == 1) { //Fetch web URL (our server)
                    $('#edit-field-service-email-address-und-0-value').val('');
                    $('#edit-field-ftp-ip-address-und-0-value').val('');
                    $('#edit-field-ftp-username-und-0-value').val('');
                    $('#edit-field-ftp-password-und-0-value').val('');
                    //$('.form-item-field-service-fetch-link-und-0-value').hide();
                    $('#itg-group-service-ftp').hide();
                } else if (val == 3) { // Via Email 
                    $('#edit-field-service-fetch-link-und-0-value').val('');
                    $('#edit-field-ftp-ip-address-und-0-value').val('');
                    $('#edit-field-ftp-username-und-0-value').val('');
                    $('#edit-field-ftp-password-und-0-value').val('');
                    $('.form-item-field-service-fetch-link-und-0-value').hide();
                    $('#itg-group-service-ftp').hide();
                } else if (val == 2) { // Via FTP location 
                    $('#edit-field-service-email-address-und-0-value').val('');
                    $('#edit-field-service-fetch-link-und-0-value').val('');
                    $('.form-item-field-service-fetch-link-und-0-value').hide();
                    $('#itg-group-service-ftp').show();
                }
            });


            var selectedVal = "";
            var selected = $("#edit-field-content-sharing-mode-und input[type='radio']:checked");
            if (selected.length > 0) {
                selectedVal = selected.val();
                if (selectedVal == 2) {
                    $('#itg-group-service-ftp').show();
                } else if (selectedVal == 3) {
                    $('#edit-field-service-email-address').show();
                }
            }

            //called when key is pressed in textbox
            $("#edit-field-service-content-count-und-0-value").keypress(function (e) {
                //if the letter is not digit then display error and don't type anything
                if (e.which != 8 && e.which != 0 && (e.which < 48 || e.which > 57)) {
                    //display error message
                    return false;
                }
            });

            //called when key is pressed in Field char limit
            $("#edit-field-service-char-limit-und-0-value").keypress(function (e) {
                //if the letter is not digit then display error and don't type anything
                if (e.which != 8 && e.which != 0 && (e.which < 48 || e.which > 57)) {
                    //display error message
                    return false;
                }
            });

            if (Drupal.settings.itg_mobile_newservice.settings.service_form) {
                jQuery('#edit-field-story-expiry-date-und-0-value-datepicker-popup-2').datepicker({
                    minDate: 0,
                    dateFormat: 'dd/mm/yy'
                }).attr('readonly', 'readonly');
            }

        }
    }
})(jQuery);
