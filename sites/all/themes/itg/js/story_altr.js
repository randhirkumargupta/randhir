/**
 * @file
 * A JavaScript file for the story only.
 */

// Code started  for handling Akamai Part for story follow 

jQuery(document).ready(function() {

    // This callback is for loading follow story
    try {
        jQuery.ajax({
            url: Drupal.settings.itg_widget.settings.base_url + '/itg-story-load-follow-story',
            type: 'post',
            data: {'id': Drupal.settings.itg_akamai.currentobjectid},
            beforeSend: function() {
                jQuery('.node-type-story .social-list').html('Loading..');
            },
            success: function(userdata) {
                if (userdata.length != 0) {
                    jQuery('.node-type-story .social-list').html(userdata);
                }
            },
            error: function(xhr, desc, err) {
                console.log(xhr);
                console.log("Details: " + desc + "\nError:" + err);
            }
        });
    } catch (e) {

    }

    jQuery('body').on('click', '.akamai-story-submit-holder', function(e) {
        e.preventDefault();
        jQuery('.akamai-submit-story-col').trigger('click');
    });


});