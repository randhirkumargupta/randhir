/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling photo block refresh part

jQuery(document).ready(function () {
    var photo_nid = Drupal.settings.itg_photogallery.settings.photo_nid;
    var photoLoginCheck = getCookie('itg_forced_login');
    try {
        if (photoLoginCheck != '' && photoLoginCheck != 'null') {
            jQuery.ajax({
                url: Drupal.settings.itg_widget.settings.base_url + '/itg-photo-block-refresh/'+ photo_nid,
                type: 'post',
                data: '',
                beforeSend: function () {
                },
                success: function (userdata) {
                    var obj = jQuery.parseJSON(userdata);
                    if (userdata.length != 0) {
                        if (obj.type == 'watch') {
                            jQuery('.photo-refresh-top').html(obj.html_render);
                            jQuery('.photo-refresh-bottom').html(obj.html_render);
                        }
                        if (obj.default_type == 'normal') {
                            jQuery('.replace-submit-story').html(obj.default_render);
                        }
                    }
                },
                error: function (xhr, desc, err) {

                }
            });
        }
    } catch (e) {

    }
});
// Code ends for handling photo block refresh part