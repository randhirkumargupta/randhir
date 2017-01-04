/*
 * @file itg_sso_change_email.js
 * Contains all functionality related to SSO
 */

(function($) {
    Drupal.behaviors.itg_sso_reg = {
        attach: function(context,settings) {
            var base_url = settings.itg_sso_reg.settings.base_url;
            // ajax for otp
            $('#itg-sso-user-email-form #forgototpclickme', context).click(function (event) {
                
               var otp = Math.floor(100000 + Math.random() * 900000)
                    otp = otp.toString().substring(0, 4);
                var get_param  = $('input[name=emobile]').val();
                
                if($.isNumeric(get_param))
                {
                  var mobile = get_param;  
                  var post = "&mobile=" + mobile+ "&otp=" + otp+ "&source=change_email_mobile";
                  
                }
                else
                {
                    var email = get_param;
                    var post = "&email=" + email+ "&otp=" + otp+ "&source=change_email_mobile";
                }
               console.log(otp);
               if (get_param != '') {
                    $("#forgototpclickme").text("Resend OTP");
                    
                    $.ajax({
                        'url': base_url + '/forgototp',
                        'data': post,
                        'type': 'POST',
                        beforeSend: function () {
                           
                            $('#ajax-loader').show();
                            

                        },
                        'success': function (data)
                        {

                            $('#ajax-loader').hide();
                            $("#forgot_otp_success").html("OTP Sent Successfully").show().delay(2000).hide(1000);
                        }
                    });
                }
            }); 
          
        }

    };
})(jQuery, Drupal, this, this.document);