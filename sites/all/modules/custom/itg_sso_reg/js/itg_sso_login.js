/*
 * @file itg_sso_login.js
 * Contains all functionality related to login
 */

/*(function ($) {
    Drupal.behaviors.itg_sso_login = {
        attach: function (context, settings) { 
            
            var base_url = Drupal.settings.itg_sso_login.settings.base_url;
            var uid = Drupal.settings.itg_sso_login.settings.uid;
            var check_sso_link = Drupal.settings.itg_sso_login.settings.check_sso_url;
            var check_user_arg = Drupal.settings.itg_sso_login.settings.user_arg;
            var check_change_arg = Drupal.settings.itg_sso_login.settings.change_arg;
            
            if (uid) {                
                if (check_sso_link == 'domain_info' && opener) {
                    opener.location.reload(true);
                }
                if (check_user_arg == 'user') {
                    window.close();
                }
                //if (check_user_arg == 'password-success') {
                    //window.opener.location = 'http://'+check_change_arg+'/personalization/edit-profile/general-settings?pass=success';
                    //window.close();
                //}                
                //if (check_user_arg == 'complete-page') {
                    //window.opener.location = 'http://'+check_change_arg+'/personalization/edit-profile/general-settings?email=success';
                    //window.close();
                //}
            }
            // code for logout 
            jQuery("a#myhref").attr('href', 'javascript:void(0)');
            var logoutsec = Drupal.settings.itg_sso_login.settings.logoutsec;
            //console.log(logoutsec);
            jQuery('body').on('click', '#myhref', function () {
                //Call Ajax
                jQuery.ajax({
                    url: base_url + '/itguserlogout',
                    success: function (data) {
                        jQuery('#iframe-display').html(data);
                        jQuery('#widget-ajex-loader').show();
                        setTimeout(function () {// wait for 5 secs(2)
                            window.location = base_url;
                        }, logoutsec);
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
                        }, logoutsec);
                    }
                });
            });
            
            // change passsword field name
            jQuery("#itg-sso-reg-password-form  label[for='edit-pass-pass1']").text("New password");
        }

    };
})(jQuery, Drupal, this, this.document);*/


// code for akamai block refresh
/*jQuery(document).ready(function () {
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-akamai-load-my-account',
            type: 'post',
            data: '',
            beforeSend: function () {
            },
            success: function (userdata) {
                if (userdata.length != 0) {
                    jQuery('.user-menu').html(userdata);
                }
            },
            error: function (xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    } catch (e) {

    }
});*/
!function(t){Drupal.behaviors.itg_sso_login={attach:function(s,e){var o=Drupal.settings.itg_sso_login.settings.base_url,i=Drupal.settings.itg_sso_login.settings.uid,n=Drupal.settings.itg_sso_login.settings.check_sso_url,r=Drupal.settings.itg_sso_login.settings.user_arg;Drupal.settings.itg_sso_login.settings.change_arg;i&&("domain_info"==n&&opener&&opener.location.reload(!0),"user"==r&&window.close()),jQuery("a#myhref").attr("href","javascript:void(0)");var a=Drupal.settings.itg_sso_login.settings.logoutsec;jQuery("body").on("click","#myhref",function(){jQuery.ajax({url:o+"/itguserlogout",success:function(t){jQuery("#iframe-display").html(t),jQuery("#widget-ajex-loader").show(),setTimeout(function(){window.location=o},a)}})}),jQuery("body").on("click",".close-pass-popup",function(){t(this).parent().parent().hide(),jQuery.ajax({url:o+"/itguserlogout",success:function(t){jQuery("#iframe-display").html(t),jQuery("#widget-ajex-loader").show(),setTimeout(function(){window.location=o},a)}})}),jQuery("#itg-sso-reg-password-form  label[for='edit-pass-pass1']").text("New password")
	if(jQuery("body").hasClass("page-user")) {
		var forget_me = jQuery('.form-item-forget-me-1 [type=checkbox]').is(":checked");
		if (forget_me != undefined && forget_me)  {
			jQuery('.social-share').show();
			jQuery('.sign-border').show();
			jQuery(':input[type="submit"]').prop('disabled', false);
		}else{
			jQuery('.social-share').hide();
			jQuery('.sign-border').hide();
			jQuery(':input[type="submit"]').prop('disabled', true);
		}
		
		jQuery('.form-item-forget-me-1 [type=checkbox]').on('click', function() {
			if (jQuery(this).is(":checked"))  {
				jQuery('.social-share').show();
				jQuery('.sign-border').show();
				jQuery(':input[type="submit"]').prop('disabled', false);
			}else{
				jQuery('.social-share').hide();
				jQuery('.sign-border').hide();
				jQuery(':input[type="submit"]').prop('disabled', true);
			}
		});
	}
	
	}}}(jQuery,Drupal,this,this.document),jQuery(document).ready(function(){try{jQuery.ajax({url:Drupal.settings.itg_widget.settings.base_url+"/itg-akamai-load-my-account",type:"post",data:"",beforeSend:function(){},success:function(t){0!=t.length&&jQuery(".user-menu").html(t)},error:function(t,s,e){console.log(t),console.log("Details: "+s+"\nError:"+e)}})}catch(t){}});
