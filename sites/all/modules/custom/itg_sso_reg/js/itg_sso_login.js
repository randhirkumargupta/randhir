! function(t) {
    Drupal.behaviors.itg_sso_login = {
        attach: function(s, e) {
            
           //get Cookie for sso login
           function getCookie(cname) {
                var name = cname + "=";
                var ca = document.cookie.split(';');
                for(var i = 0; i < ca.length; i++) {
                    var c = ca[i];
                    while (c.charAt(0) == ' ') {
                        c = c.substring(1);
                    }
                    if (c.indexOf(name) == 0) {
                        return c.substring(name.length, c.length);
                    }
                }
                return "";
            }
            var ssoLoginCheck = getCookie('itg_forced_login');
            console.log(ssoLoginCheck);
            //end code get Cookie for sso login
            
            var o = Drupal.settings.itg_sso_login.settings.base_url,
                i = Drupal.settings.itg_sso_login.settings.uid,
                n = Drupal.settings.itg_sso_login.settings.check_sso_url,
                r = Drupal.settings.itg_sso_login.settings.user_arg,
                sso_url = Drupal.settings.itg_sso_login.settings.sso_url,
                front_url = Drupal.settings.itg_sso_login.settings.front_url,
                change_pass_redirection = sso_url + '/saml_login/other/' + front_url;
            Drupal.settings.itg_sso_login.settings.change_arg;
            i && ("domain_info" == n && opener && opener.location.reload(!0), "user" == r && window.close()), jQuery("a#myhref").attr("href", "javascript:void(0)");
            var a = Drupal.settings.itg_sso_login.settings.logoutsec;
            jQuery("body").on("click", "#myhref", function() {
                jQuery.ajax({
                    url: o + "/itguserlogout",
                    success: function(t) {
                        jQuery("#iframe-display").html(t), jQuery("#widget-ajex-loader").show(), setTimeout(function() {
                            window.location = o
                        }, a)
                    }
                })
            }), jQuery("body").on("click", ".close-pass-popup", function() {
                t(this).parent().parent().hide(), jQuery.ajax({
                    url: o + "/itguserlogout",
                    success: function(t) {
                        jQuery("#iframe-display").html(t), jQuery("#widget-ajex-loader").show(), setTimeout(function() {
                            window.location = change_pass_redirection
                        }, a)
                    }
                })
            }), jQuery("#itg-sso-reg-password-form  label[for='edit-pass-pass1']").text("New password")
            if (ssoLoginCheck != '' && ssoLoginCheck != 'null') {
                //alert(ssoLoginCheck);
                jQuery.ajax({
                    url: Drupal.settings.itg_widget.settings.base_url + "/itg-load-my-account",
                    type: "post",
                    data: "",
                    beforeSend: function() {},
                    success: function(t) {
                        0 != t.length && jQuery(".user-menu").html(t)
                    },
                    error: function(t, s, e) {
                        console.log(t), console.log("Details: " + s + "\nError:" + e)
                    }
                });
            }
            
        }
    }
}(jQuery, Drupal, this, this.document);

/*jQuery(document).ready(function() {
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + "/itg-load-my-account",
            type: "post",
            data: "",
            beforeSend: function() {},
            success: function(t) {
                0 != t.length && jQuery(".user-menu").html(t)
            },
            error: function(t, s, e) {
                console.log(t), console.log("Details: " + s + "\nError:" + e)
            }
        })
    } catch (t) {}
});*/
