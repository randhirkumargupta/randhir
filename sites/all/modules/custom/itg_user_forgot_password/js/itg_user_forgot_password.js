/*
 * @file itg_user_forgot_password.js
 * Contains all functionality related to SSO
 */

(function($) {
    Drupal.behaviors.itg_user_forgot_password = {
        attach: function(context,settings) {
            var base_url = settings.itg_user_forgot_password.settings.base_url;
            var error = settings.itg_user_forgot_password.settings.forgot_error;
            if (error) {
                jQuery.each(error, function (index, item) {
                    if (index == 'ufname') {
                        jQuery('.forgot-error').html(item);
                    }

                });
            }
            // ajax for otp
            var cnt_num = 0;
            $('#itg-user-forgot-password-multistep-form--2 #forgototpclickme', context).click(function (event) {
                cnt_num += 1;
                console.log(cnt_num, 'cnt_num');
                $("div.forgot-otp-resend-limit").remove();
                if(cnt_num < 4){
                    var otp = Math.floor(100000 + Math.random() * 900000)
                        otp = otp.toString().substring(0, 4);
                    var get_param  = $('input[name=ufname]').val();

                    if($.isNumeric(get_param))
                    {
                      var mobile = get_param;
                      var post = "&mobile=" + mobile+ "&otp=" + otp+ "&source=reset";
                    }
                    else
                    {
                        var email = get_param;
                        var post = "&email=" + email+ "&otp=" + otp+ "&source=reset";
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
                }else{
                 $("#fotp #forgot_otp_success").before("<div class='forgot-otp-resend-limit message error'>You have reached max resend OTP limit.</div>");
                }
            });

          $('#edit-pass-pass1').attr('autocomplete','off');
          $('#edit-pass-pass2').attr('autocomplete','off');
        }

    };
})(jQuery, Drupal, this, this.document);
