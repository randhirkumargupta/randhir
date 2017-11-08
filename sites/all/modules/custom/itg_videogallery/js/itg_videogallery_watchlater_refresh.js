/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling video watch later block refresh part

jQuery(document).ready(function () {
    var video_nid = Drupal.settings.itg_videogallery.settings.video_nid;
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-video-watch-later-refresh/'+ video_nid,
            type: 'post',
            data: '',
            beforeSend: function () {
            },
            success: function (userdata) {
                if (userdata.length != 0) {
                    jQuery('.akamai-video-replace').html(userdata); 
                }
            },
            error: function (xhr, desc, err) {
                
            }
        });
    } catch (e) {

    }
});
// Code ends for handling photo block refresh part