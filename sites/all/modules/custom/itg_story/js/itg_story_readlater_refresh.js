/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling read later block refresh part

jQuery(document).ready(function () {
    var story_nid = Drupal.settings.itg_story.settings.story_nid;
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-read-later-refresh/' + story_nid,
            type: 'post',
            data: '',
            beforeSend: function () {
            },
            success: function (userdata) {
                var obj = jQuery.parseJSON(userdata);

                if (userdata.length != 0) {
                    if (obj.type == 'buzz') {
                        jQuery('.buzz-akamai-refresh-read-later').html(obj.html_render);
                    }
                    if (obj.default_type == 'normal') {
                        jQuery('.not-buzz-case').html(obj.default_render);
                    }
                }
            },
            error: function (xhr, desc, err) {

            }
        });
    } catch (e) {

    }
});
// Code ends for handling photo block refresh part