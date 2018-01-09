/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling video watch later block refresh part

jQuery(document).ready(function () {
    var video_nid = Drupal.settings.itg_videogallery.settings.video_nid;
    var watchLoginCheck = getCookie('itg_forced_login');
    try {
        if (watchLoginCheck != '' && watchLoginCheck != 'null') {
            jQuery.ajax({
                url: Drupal.settings.itg_widget.settings.base_url + '/itg-video-watch-later-refresh/'+ video_nid,
                type: 'post',
                data: '',
                beforeSend: function () {
                },
                success: function (userdata) {
                    var obj = jQuery.parseJSON(userdata);
                    if (userdata.length != 0) {
                        if (obj.type == 'watch') {
                            jQuery('.akamai-video-replace').html(obj.html_render);
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