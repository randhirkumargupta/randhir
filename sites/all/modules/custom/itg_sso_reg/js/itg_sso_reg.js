/*
 * @file itg_sso_reg.js
 * Contains all functionality related to SSO
 */

(function ($) {
    Drupal.behaviors.itg_sso_reg = {
        attach: function (context, settings) {
            var base_url = settings.itg_sso_reg.settings.base_url;
            var error = settings.itg_sso_reg.settings.custom_error;
            
            if (error) {
                jQuery.each(error, function (index, item) {
                    if (index == 'mobile') {
                        jQuery('.mobile-error').html(item);
                    }
                    if (index == 'mail') {
                        jQuery('.email-error').html(item);
                    }
                    if (index == 'fname') {
                        jQuery('.fname-msg').html(item);
                    }
                    if (index == 'lname') {
                        jQuery('.lname-msg').html(item);
                    }
                    if (index == 'password') {
                        jQuery('.pass-msg').html(item);
                    }
                    if (index == 'forget_me') {
                        jQuery('.forget_me-error').html(item);
                    }
                });
            }
            // ajax for otp
            $('#itg-sso-reg-multistep-form--2 #otpclickme', context).click(function (event) {

                var mobile = $('input[name=step2mobile]').val();
                var email = $('input[name=step2mail]').val();

                var otp = Math.floor(100000 + Math.random() * 900000)
                otp = otp.toString().substring(0, 4);
                var post = "&mobile=" + mobile + "&email=" + email + "&otp=" + otp + "&source=register";

                if (mobile != '') {
                    $("#otpclickme").text("Resend OTP");
                    $.ajax({
                        'url': base_url + '/otpajaxcallback',
                        'data': post,
                        'type': 'POST',
                        beforeSend: function () {
                            $('#ajax-loader').show();
                        },
                        'success': function (data) {
                            $('#ajax-loader').hide();
                            $("#otp_success").html("OTP Sent Successfully").show().delay(2000).hide(1000);
                        }
                    });
                }
            });


            $('input[name=mobile]').keyup(function () {
                this.value = this.value.replace(/[^0-9\.]/g, '');
            });
            
            // validation
            var selected_country = jQuery('select[name="page_country"]').val();
            var flag = 0;
			if (Drupal.settings.countries_json[selected_country] != undefined && Drupal.settings.countries_json[selected_country] == 0)  {
				jQuery('.social-share').show();
				jQuery(':input[type="submit"]').prop('disabled', false);
				jQuery('.country_restriction_msg').hide();
			}else{
				jQuery('.social-share').hide();
				jQuery(':input[type="submit"]').prop('disabled', true);
				jQuery('.country_restriction_msg').show();
			}
			
			jQuery('select[name="page_country"]').on('change', function() {
				var selected_country1 = this.value;
				var flag1 = 0;
				if (Drupal.settings.countries_json[selected_country1] != undefined && Drupal.settings.countries_json[selected_country1] == 0)  {
					jQuery('.social-share').show();
					jQuery(':input[type="submit"]').prop('disabled', false);
					jQuery('.country_restriction_msg').hide();
				}else{
					jQuery('.social-share').hide();
					jQuery(':input[type="submit"]').prop('disabled', true);
					jQuery('.country_restriction_msg').show();
				}
			})
            // validation

        }

    };
})(jQuery, Drupal, this, this.document);

//~ jQuery(document).ready(function(){
	//~ var selected_country = jQuery("#edit-page-country").val();
	//~ var flag = 0;
	//~ if (Drupal.settings.countries_json[selected_country] != undefined && Drupal.settings.countries_json[selected_country] == 0)  {
		//~ jQuery('.social-share').show();
		//~ jQuery(':input[type="submit"]').prop('disabled', false);
		//~ jQuery('.country_restriction_msg').hide();
	//~ }else{
		//~ jQuery('.social-share').hide();
		//~ jQuery(':input[type="submit"]').prop('disabled', true);
		//~ jQuery('.country_restriction_msg').show();
	//~ }
	
	//~ jQuery("#edit-page-country").on('change', function() {
		//~ var selected_country1 = this.value;
		//~ var flag1 = 0;
		//~ if (Drupal.settings.countries_json[selected_country1] != undefined && Drupal.settings.countries_json[selected_country1] == 0)  {
			//~ jQuery('.social-share').show();
			//~ jQuery(':input[type="submit"]').prop('disabled', false);
			//~ jQuery('.country_restriction_msg').hide();
		//~ }else{
			//~ jQuery('.social-share').hide();
			//~ jQuery(':input[type="submit"]').prop('disabled', true);
			//~ jQuery('.country_restriction_msg').show();
		//~ }
	//~ })
//~ });
