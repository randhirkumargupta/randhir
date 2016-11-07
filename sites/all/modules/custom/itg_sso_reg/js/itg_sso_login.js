/*
 * @file itg_sso_login.js
 * Contains all functionality related to login
 */

(function ($) {
    Drupal.behaviors.itg_sso_login = {
        attach: function (context, settings) {
            //alert(document.referrer);
            var base_url = settings.itg_flag.settings.base_url;
            var uid = settings.itg_sso_login.settings.uid;
            var check_sso_link = settings.itg_sso_login.settings.check_sso_url;

            if (uid) {
                //self.opener.location.reload(); 
                if (check_sso_link && opener) {
                    
                        opener.location.reload();
                    
                }
                window.close();
            }
            // code for logout 
            jQuery("a#myhref").attr('href', 'javascript:void(0)');

            jQuery('#myhref').on('click', function() {
                //Call Ajax
                jQuery.ajax({
                    url: base_url+'/itguserlogout',
                    //type: 'post',
                    //mozSystem: true ,
                    //dataType: 'JSON',
                    success: function(data) {
                        $('#widget-ajex-loader').show();
                       // alert('@@@');
                         //location.reload();
                        //window.location = base_url+"/user/logout";
                        //$('span.count').html(' : ' + data);
                         setTimeout(function () {// wait for 5 secs(2)
                              window.location = base_url;
                          }, 15000);
                    }
                });
            });

        }

    };
})(jQuery, Drupal, this, this.document);
