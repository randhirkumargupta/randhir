/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Code started  for handling follow story block refresh part

jQuery(document).ready(function () {
    var follow_nid = Drupal.settings.itg_story.settings.follow_nid;
    var followStoryLoginCheck = getCookie('itg_forced_login');
    try {
        if (followStoryLoginCheck != '' && followStoryLoginCheck != 'null') {
            jQuery.ajax({
                url: Drupal.settings.itg_widget.settings.base_url + '/itg-follow-story-refresh/'+ follow_nid,
                type: 'post',
                data: '',
                beforeSend: function () {
                },
                success: function (userdata) {

                    if (userdata.length != 0) {

                        jQuery('.follow-akamai-refresh').html(userdata);

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