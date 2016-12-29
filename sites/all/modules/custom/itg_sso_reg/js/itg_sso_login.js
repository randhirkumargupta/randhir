/*
 * @file itg_sso_login.js
 * Contains all functionality related to login
 */

(function ($) {
    Drupal.behaviors.itg_sso_login = {
        attach: function (context, settings) { 
            //alert(document.referrer);
            var base_url = Drupal.settings.itg_sso_login.settings.base_url;
            var uid = Drupal.settings.itg_sso_login.settings.uid;
            var check_sso_link = Drupal.settings.itg_sso_login.settings.check_sso_url;
            var check_user_arg = Drupal.settings.itg_sso_login.settings.user_arg;
            var check_change_arg = Drupal.settings.itg_sso_login.settings.change_arg;
            //alert(check_user_arg);
            if (uid) {
                //self.opener.location.reload(); 
                if (check_sso_link == 'domain_info' && opener) {

                    opener.location.reload(true);

                }
                if (check_user_arg == 'user') {
                    window.close();
                }
                if (check_user_arg == 'password-success') {
                    window.opener.location = 'http://'+check_change_arg+'/personalization/edit-profile/general-settings?pass=success';
                    window.close();
                }
                
                if (check_user_arg == 'complete-page') {
                    window.opener.location = 'http://'+check_change_arg+'/personalization/edit-profile/general-settings?email=success';
                    window.close();
                }
            }
            // code for logout 
            jQuery("a#myhref").attr('href', 'javascript:void(0)');

            jQuery('body').on('click', '#myhref', function () {
                //Call Ajax
                jQuery.ajax({
                    url: base_url + '/itguserlogout',
                    success: function (data) {
                        jQuery('#iframe-display').html(data);
                        jQuery('#widget-ajex-loader').show();
                        setTimeout(function () {// wait for 5 secs(2)
                            window.location = base_url;
                        }, 20000);
                    }
                });
            });
            
            
            // code for logout from changepassword, email, mobile number change event
            jQuery('body').on('click', '.close-pass-popup', function () {
                $(this).parent().parent().hide();
                //Call Ajax
                jQuery.ajax({
                    url: base_url + '/itguserlogout',
                    success: function (data) {
                        jQuery('#iframe-display').html(data);
                        jQuery('#widget-ajex-loader').show();
                        setTimeout(function () {// wait for 5 secs(2)
                            window.location = base_url;
                        }, 20000);
                    }
                });
            });
            
            // change passsword field name
            jQuery("#itg-sso-reg-password-form  label[for='edit-pass-pass1']").text("New password");
        }

    };
})(jQuery, Drupal, this, this.document);
