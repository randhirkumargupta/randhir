/*
 * @file itg_sso_login.js
 * Contains all functionality related to login
 */

(function ($) {
    Drupal.behaviors.itg_sso_login = {
        attach: function (context, settings) {
            //alert(document.referrer);
            var uid = settings.itg_sso_login.settings.uid;
            var check_sso_link = settings.itg_sso_login.settings.check_sso_url;

            if (uid) {
                //self.opener.location.reload(); 
                if (check_sso_link) {
                    
                        opener.location.reload();
                    
                }
                window.close();
            }


        }

    };
})(jQuery, Drupal, this, this.document);
