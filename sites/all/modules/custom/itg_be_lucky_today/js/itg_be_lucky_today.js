/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @file itg_be_lucky_today.js
 * This is used for be lucky today form validation
 */
jQuery(document).ready(function () {
    jQuery('.itg_be_lucky_today .next').click(function (event) {
        if (jQuery('.itg_be_lucky_today [name="yourname"]').val().length < 1) {
            alert(Drupal.t('Please enter your name'));
            return false;
        }
        return true;
    });

    jQuery('.itg_be_lucky_today .next2').click(function (event) {
        if (!jQuery('.itg_be_lucky_today [name="age"]').is(":checked")) {
            alert(Drupal.t('Please enter your Age'));
            return false;
        }
        return true;
    });
    jQuery('.itg_be_lucky_today .next3').click(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        if (jQuery('.itg_be_lucky_today [name="email"]').val().length < 1) {
            alert(Drupal.t('Please enter your email'));
            return false;
        }
        if (!regex.test(jQuery('.itg_be_lucky_today [name="email"]').val())) {
            alert(Drupal.t('Please enter valid email'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="address"]').val().length < 1) {
            alert(Drupal.t('Please enter your address'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="zip_code"]').val().length < 1) {
            alert(Drupal.t('Please enter your zipcode'));
            return false;
        }
        if (!/^\d{6}$/.test(jQuery('.itg_be_lucky_today [name="zip_code"]').val())) {
            alert(Drupal.t('Please enter valid zipcode'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="mobile"]').val().length < 1) {
            alert(Drupal.t('Please enter your mobile'));
            return false;
        }
        if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today [name="mobile"]').val())) {
            alert(Drupal.t('Please enter valid mobile'));
            return false;
        }
        return true;
    });

    jQuery('.be_lucky_today_submit').click(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().length < 1) {
            alert(Drupal.t('Please fill atleast one row completely'));
            return false;
        }

        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile"]').val().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
        }

        if (jQuery('.itg_be_lucky_today_2 [name="name_2"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_2"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_3"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_3"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_4"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_4"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_5"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_5"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
        }
        return true;
    });

    // Luck meter
    jQuery('.itg_be_lucky_today_2 [type="text"]').blur(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        var luck_meter = 0;

        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email"]').val().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile"]').val().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_2"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_2"]').val().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_3"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_3"]').val().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_4"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_4"]').val().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_5"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_5"]').val().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val())) {
                luck_meter += 20;
            }
        }
        luck_meter = luck_meter + '%';
        jQuery('.luck_meter .black_strip').css('bottom', luck_meter);
    });
    // Luck meter end

});

var insert_magazine = function (response) {
    console.log('response', response);
//    jQuery('#magazine_wrapper').html(response);
}

