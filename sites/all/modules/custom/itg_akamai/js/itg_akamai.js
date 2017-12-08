/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling Akamai Part

jQuery(document).ready(function () {
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-load-my-account',
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
});
// Code ends for handling Akamai part




