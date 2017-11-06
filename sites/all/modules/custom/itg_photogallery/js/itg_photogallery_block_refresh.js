/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling photo block refresh part

jQuery(document).ready(function () {
    var photo_nid = Drupal.settings.itg_photogallery.settings.photo_nid;
    console.log(photo_nid);
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-photo-block-refresh/'+ photo_nid,
            type: 'post',
            data: '',
            beforeSend: function () {
            },
            success: function (userdata) {
                if (userdata.length != 0) {
                    jQuery('.photo-refresh-top').html(userdata);
                    jQuery('.photo-refresh-bottom').html(userdata);
                }
            },
            error: function (xhr, desc, err) {
                
            }
        });
    } catch (e) {

    }
});
// Code ends for handling photo block refresh part