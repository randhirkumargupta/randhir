/**
 * @file
 * A JavaScript file for the story only.
 */

// Code started  for handling Akamai Part for story follow 

jQuery(document).ready(function() {
    var followLoginCheck = getCookie('itg_forced_login');
        
    // This callback is for loading follow story
    try {
        
        if (followLoginCheck != '' && followLoginCheck != 'null') {
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
                }
            });
        }
    } catch (e) {

    }

    jQuery('body').on('click', '.akamai-story-submit-holder', function(e) {
        e.preventDefault();
        jQuery('.akamai-submit-story-col').trigger('click');
    });
    
    // Place ad in Mobile body.
    if (jQuery(window).width() < 768) {
        var ad_div = '';
        if (jQuery(".mobile-body-ad").length > 0) {
            ad_div += "<script>";
            ad_div += "googletag.cmd.push(function() {"
            ad_div += "googletag.defineSlot('/1007232/Indiatoday_Story_300x250_Inarticle', [300, 250], 'div-gpt-ad-1515155454292-0').addService(googletag.pubads());";
            ad_div += "googletag.pubads().enableSingleRequest();"
            ad_div += "googletag.pubads().collapseEmptyDivs();"
            ad_div += "googletag.enableServices();"
            ad_div += "})"
            ad_div += "</script>"
            ad_div += "<div id='div-gpt-ad-1515155454292-0' style='height:250px; width:300px;'></div>";
            ad_div += "<script>";
            ad_div += "googletag.cmd.push(function() { googletag.display('div-gpt-ad-1515155454292-0'); });";
            ad_div += "</script>";
            ad_div += "</div>";
            jQuery(".mobile-body-ad").append(ad_div);
        }
    }
});
