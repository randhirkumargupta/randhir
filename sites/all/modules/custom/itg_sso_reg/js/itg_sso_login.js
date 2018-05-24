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
