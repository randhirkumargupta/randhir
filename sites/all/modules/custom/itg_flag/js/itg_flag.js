/*
 * @file itg_flag.js
 * Contains all functionality related to Flag Management
 */

(function ($) {
    Drupal.behaviors.itg_flag = {
        attach: function (context, settings) {
            var uid = settings.itg_flag.settings.uid;
            var base_url = settings.itg_flag.settings.base_url;
            //alert(base_url);

            // jquery for front user activity
            $('#user-activity').click(function (event) {

                var nd_id = jQuery(this).attr('rel');
                var dtag = jQuery(this).attr('data-tag');
                var dstatus = jQuery(this).attr('data-status');
                var data_activity = jQuery(this).attr('data-activity');
                var post_data = "&nd_id=" + nd_id + "&dtag=" + dtag + "&data_activity=" + data_activity + "&dstatus=" + dstatus;

                $.ajax({
                    'url': base_url + '/user-activity-front-end',
                    'data': post_data,
                    'cache': false,
                    'type': 'POST',
                    // dataType: 'json',
                    beforeSend: function () {

                    },
                    'success': function (result)
                    {
                        var obj = jQuery.parseJSON(result);
                        if (obj.success == 1) {
                            console.log('create');
                            $(".follow-story a").attr({
                                'data-status': 0,
                                title: 'Unfollow story'
                            }).html('Unfollow story');
                        }
                        if (obj.success == 0) {
                            console.log('update');
                            $(".follow-story a").attr({
                                'data-status': 1,
                                title: 'Follow the Story'
                            }).html('Follow the Story');
                        }
                        if (obj.error == 'error') {

                        }
                    }
                });

            });

            // Code for date range on DOB field of edit profile.
            if ($('body').hasClass('page-personalization-edit-profile-general-settings')) {                
                $("#edit-dob-datepicker-popup-0").datepicker({
                    maxDate: '+0d',
                    minDate: new Date(1970, 01, 01),
                    changeMonth: true,
                    changeYear: true,
                    dateFormat: 'yy-mm-dd',
                });
            }

            // end here
        }

    };
})(jQuery, Drupal, this, this.document);

// script for facebook sharing
(function (d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id))
        return;
    js = d.createElement(s);
    js.id = id;
    js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.8&appId=265688930492076";
    fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));

function fbpop(linkurl, title, desc, image, base_url, node_id) {
    FB.ui({
        method: 'feed',
        link: linkurl,
        picture: image,
        name: title,
        //caption: desc,
        description: desc
    }, function (response) {
        if (response.post_id != 'undefined' && response.post_id != '') {
            jQuery.ajax({
                url: base_url + '/earn-loyalty-point/' + node_id + '/share',
                type: 'POST',
                dataType: 'JSON',
            });
        }
    });
}


//facebook sharing end here

// script for twitter sharing

function twitter_popup(title, url) {
    tweetlink = "http://twitter.com/share?text=" + title + "&url=" + url + "&via=indiatoday";
    newwindow = window.open(tweetlink, 'indiatoday', 'height=500,width=550,left=440,top=250');
    if (window.focus) {
        newwindow.focus()
    }
    return false;
}

// twitter sharing end here

// script for google sharing

function googleplusbtn(url, title, img) {
    sharelink = "https://plus.google.com/share?url=" + url;
    newwindow = window.open(sharelink, 'indiatoday', 'height=400,width=600,left=440,top=250');
    if (window.focus) {
        newwindow.focus()
    }
    return false;
}

// google sharing end here


// function for scrolling
function scrollToAnchor(aid) {
    var aTag = jQuery("div[id='" + aid + "']");
    jQuery('html,body').animate({scrollTop: aTag.offset().top}, 'slow');
}

// code for like dislike
jQuery(document).ready(function () {
    jQuery('#like_count,#dislike_count').click(function (event) {
        jQuery('#like_count,#dislike_count').prop('disabled', true);
        var nd_id = jQuery(this).attr('rel');
        var typ = jQuery(this).attr('id');
        var dtag = jQuery(this).attr('data-tag');
        var post_data = "&nd_id=" + nd_id + "&typ=" + typ + "&dtag=" + dtag;

        jQuery.ajax({
            'url': Drupal.settings.baseUrl.baseUrl + '/flag-details-ajax',
            'data': post_data,
            'cache': false,
            'type': 'POST',
            // dataType: 'json',
            beforeSend: function () {

            },
            'success': function (result)
            {
                var obj = jQuery.parseJSON(result);

                jQuery('#widget-ajex-loader').hide();
                if (obj.type == 'like_count') {
                    jQuery("#no-of-likes_" + obj.nd_id).html("(" + obj.count + ")");
                }
                if (obj.chk == 'sty') {
                    jQuery("#sty-dv").show(0);
                }
                if (obj.chk == 'dsty') {
                    jQuery("#dsty-dv").show(0);
                }
                if (obj.type == 'dislike_count') {
                    jQuery("#no-of-dislikes_" + obj.nd_id).html("(" + obj.count + ")");
                }
                if (obj.error == 'error') {

                    jQuery("#voted_" + obj.nd_id).html('You have already voted').show(0).delay(2000).hide(1000);
                }
                jQuery('#like_count,#dislike_count').prop('disabled', false);
            }
        });

    });
});