/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {

    Drupal.behaviors.itg_mobile_newservice_form = {
        attach: function(context, settings) {
            // default hide FTP label
            $('.required-fields h3 span').hide();
            $('#edit-field-content-sharing-mode-und input').click(function() {
                var val = $(this).val();
                if (val == 1) { //Fetch web URL (our server)
                    $('#edit-field-email-address-und-0-value').val('');
                    $('#edit-field-ftp-ip-address-und-0-value').val('');
                    $('#edit-field-ftp-username-und-0-value').val('');
                    $('#edit-field-ftp-password-und-0-value').val('');
                    $('.required-fields h3 span').hide();
                } else if (val == 3) { // Via Email 
                    $('#edit-field-service-fetch-link-und-0-value').val('');
                    $('#edit-field-ftp-ip-address-und-0-value').val('');
                    $('#edit-field-ftp-username-und-0-value').val('');
                    $('#edit-field-ftp-password-und-0-value').val('');
                    $('.required-fields h3 span').hide();
                } else if (val == 2) { // Via FTP location 
                    $('#edit-field-email-address-und-0-value').val('');
                    $('#edit-field-service-fetch-link-und-0-value').val('');
                    $('.required-fields h3 span').show();
                }
            });
        }
    }
})(jQuery);
