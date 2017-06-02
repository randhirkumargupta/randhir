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
    var str_pattern = /^[a-zA-Z]+$/;
    var address_pattern = /^[-\/a-zA-Z]+$/;
    jQuery('.itg_be_lucky_today .next').click(function (event) {
        if (jQuery('.itg_be_lucky_today [name="yourname"]').val().trim().length < 2) {
            alert(Drupal.t('Please enter your name'));
            return false;
        }
        if (!str_pattern.test(jQuery('.itg_be_lucky_today [name="yourname"]').val())) {
            alert(Drupal.t('Please enter valid name'));
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
    
    jQuery('.itg_be_lucky_today [name="email"]').blur(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        if (jQuery('.itg_be_lucky_today [name="email"]').val().trim().length < 1) {
            alert(Drupal.t('Please enter your email'));
            return false;
        }
        if (!regex.test(jQuery('.itg_be_lucky_today [name="email"]').val())) {
            alert(Drupal.t('Please enter valid email'));
            return false;
        }
    });
    
    jQuery('.itg_be_lucky_today .next3').click(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        if (jQuery('.itg_be_lucky_today [name="email"]').val().trim().length < 1) {
            alert(Drupal.t('Please enter your email'));
            return false;
        }
        if (!regex.test(jQuery('.itg_be_lucky_today [name="email"]').val())) {
            alert(Drupal.t('Please enter valid email'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="address"]').val().trim().length < 1) {
            alert(Drupal.t('Please enter your address'));
            return false;
        }
        if (!address_pattern.test(jQuery('.itg_be_lucky_today [name="address"]').val())) {
            alert(Drupal.t('Please enter valid address'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="zip_code"]').val().trim().length < 1) {
            alert(Drupal.t('Please enter your zipcode'));
            return false;
        }
        if (!/^\d{6}$/.test(jQuery('.itg_be_lucky_today [name="zip_code"]').val())) {
            alert(Drupal.t('Please enter valid zipcode'));
            return false;
        }
        if (jQuery('.itg_be_lucky_today [name="mobile"]').val().trim().length < 1) {
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
        var name = new Array();
        var mobile = new Array();
        var email = new Array();
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().trim().length < 1) {
            alert(Drupal.t('Please fill atleast one row completely'));
            return false;
        }

        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().trim().length >= 1) {
            if (!str_pattern.test(jQuery('.itg_be_lucky_today_2 [name="name"]').val())) {
                alert(Drupal.t('Please enter valid name'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="email"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            name.push(jQuery('.itg_be_lucky_today_2 [name="name"]').val());
            email.push(jQuery('.itg_be_lucky_today_2 [name="email"]').val());
            mobile.push(jQuery('.itg_be_lucky_today_2 [name="mobile"]').val());
        }

        if (jQuery('.itg_be_lucky_today_2 [name="name_2"]').val().trim().length >= 1) {
            if (!str_pattern.test(jQuery('.itg_be_lucky_today_2 [name="name_2"]').val())) {
                alert(Drupal.t('Please enter valid name'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="email_2"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="name_2"]').val(), name) !== -1){
                alert(Drupal.t('Please enter different Name'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val(), email) !== -1){
                alert(Drupal.t('Please enter different Email'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val(), mobile) !== -1){
                alert(Drupal.t('Please enter different Mobile'));
                return false;
            }
            
            name.push(jQuery('.itg_be_lucky_today_2 [name="name_2"]').val());
            email.push(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val());
            mobile.push(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val());
            
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_3"]').val().trim().length >= 1) {
            if (!str_pattern.test(jQuery('.itg_be_lucky_today_2 [name="name_3"]').val())) {
                alert(Drupal.t('Please enter valid name'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="email_3"]').val().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="name_3"]').val(), name) !== -1){
                alert(Drupal.t('Please enter different Name'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val(), email) !== -1){
                alert(Drupal.t('Please enter different Email'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val(), mobile) !== -1){
                alert(Drupal.t('Please enter different Mobile'));
                return false;
            }
            
            name.push(jQuery('.itg_be_lucky_today_2 [name="name_3"]').val());
            email.push(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val());
            mobile.push(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val());
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_4"]').val().trim().length >= 1) {
            if (!str_pattern.test(jQuery('.itg_be_lucky_today_2 [name="name_4"]').val())) {
                alert(Drupal.t('Please enter valid name'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="email_4"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="name_4"]').val(), name) !== -1){
                alert(Drupal.t('Please enter different Name'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val(), email) !== -1){
                alert(Drupal.t('Please enter different Email'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val(), mobile) !== -1){
                alert(Drupal.t('Please enter different Mobile'));
                return false;
            }
            
            name.push(jQuery('.itg_be_lucky_today_2 [name="name_4"]').val());
            email.push(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val());
            mobile.push(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val());
            
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_5"]').val().trim().length >= 1) {
            if (!str_pattern.test(jQuery('.itg_be_lucky_today_2 [name="name_5"]').val())) {
                alert(Drupal.t('Please enter valid name'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="email_5"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (!regex.test(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val())) {
                alert(Drupal.t('Please enter valid email'));
                return false;
            }
            if (jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val().trim().length < 1) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            if (!/^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val())) {
                alert(Drupal.t('Please enter valid mobile'));
                return false;
            }
            
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="name_5"]').val(), name) !== -1){
                alert(Drupal.t('Please enter different Name'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val(), email) !== -1){
                alert(Drupal.t('Please enter different Email'));
                return false;
            }
            if(jQuery.inArray(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val(), mobile) !== -1){
                alert(Drupal.t('Please enter different Mobile'));
                return false;
            }
            
            name.push(jQuery('.itg_be_lucky_today_2 [name="name_5"]').val());
            email.push(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val());
            mobile.push(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val());
        }
        return true;
    });

    // Luck meter
    jQuery('.itg_be_lucky_today_2 [type="text"]').blur(function (event) {
        var regex = /^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/;
        var luck_meter = 0;

        if (jQuery('.itg_be_lucky_today_2 [name="name"]').val().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email"]').val().trim().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile"]').val().trim().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_2"]').val().trim().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_2"]').val().trim().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_2"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val().trim().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_2"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_3"]').val().trim().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_3"]').val().trim().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_3"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val().trim().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_3"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_4"]').val().trim().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_4"]').val().trim().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_4"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val().trim().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_4"]').val())) {
                luck_meter += 20;
            }
        }
        if (jQuery('.itg_be_lucky_today_2 [name="name_5"]').val().trim().length >= 1) {
            if (jQuery('.itg_be_lucky_today_2 [name="email_5"]').val().trim().length >= 1 && regex.test(jQuery('.itg_be_lucky_today_2 [name="email_5"]').val()) && jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val().trim().length >= 1 && /^\d{10}$/.test(jQuery('.itg_be_lucky_today_2 [name="mobile_5"]').val())) {
                luck_meter += 20;
            }
        }
        luck_meter = luck_meter + '%';
        jQuery('.luck_meter .black_strip').css('bottom', luck_meter);
    });
    // Luck meter end
    
    jQuery(".page-be-lucky-today").on('keydown', '#number_check', function(event){
        if (!/[0-9]/g.test(event.key) && event.key != "Delete" && event.key != "Backspace" && event.key != "ArrowLeft" && event.key != "ArrowRight") {
            event.preventDefault();            
            return false
        }
    });

});

var insert_magazine = function (response) {
    console.log('response', response);
//    jQuery('#magazine_wrapper').html(response);
}

function fbs_click()
{
    u = "bit.ly/Social_sharing";
    t = "test title";
    window.open('http://www.facebook.com/sharer.php?u=' + encodeURIComponent(u) + '&t=' + encodeURIComponent(t), 'sharer', 'toolbar=0,status=0,width=626,height=436');
    console.log('http://www.facebook.com/sharer.php?u=' + encodeURIComponent(u) + '&t=' + encodeURIComponent(t));
    return false;
}
