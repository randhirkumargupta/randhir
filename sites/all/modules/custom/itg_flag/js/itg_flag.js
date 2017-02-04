/*
 * @file itg_flag.js
 * Contains all functionality related to Flag Management
 */

(function ($) {
    Drupal.behaviors.itg_flag = {
        attach: function (context, settings) {
            var uid = settings.itg_flag.settings.uid;
            var base_url = settings.itg_flag.settings.base_url;


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

        jQuery(document).click(function () {
            jQuery("#sty-dv, #dsty-dv").hide();
        });
        jQuery("#sty-dv, #dsty-dv").click(function (e) {
            e.stopPropagation();
        });

    });

    // emoji and follow story


    // jquery for front user activity
    jQuery('#user-activity, .user-activity').click(function (event) {        
        var nd_id = jQuery(this).attr('rel');
        var dtag = jQuery(this).attr('data-tag');
        var nodeId = jQuery(this).attr('data-nodeid');
        var dstatus = jQuery(this).attr('data-status');
        var data_activity = jQuery(this).attr('data-activity');
        var post_data = "&nd_id=" + nd_id + "&dtag=" + dtag + "&data_activity=" + data_activity + "&dstatus=" + dstatus;
        jQuery(this).closest(".emoji-container").find("a").removeClass("def-cur-pointer").addClass("def-cur-none-pointer");
        if(!jQuery(this).closest(".emoji-container").find("a").hasClass('def-cur-none-pointer')) {
        jQuery.ajax({
            'url': Drupal.settings.baseUrl.baseUrl + '/user-activity-front-end',
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
                    jQuery(".follow-story a").attr({
                        'data-status': 0,
                        title: 'Unfollow story'
                    }).html('Unfollow story');
                }
                if (obj.success == 0) {
                    console.log('update');
                    jQuery(".follow-story a").attr({
                        'data-status': 1,
                        title: 'Follow the Story'
                    }).html('Follow the Story');
                }
                if (obj.error == 'error') {

                }
                if (obj.ok == 'hightlights_emoji_true') {
                    jQuery("."+obj.rel).html("(" + obj.count + ")");
                    jQuery(".hightlights_emoji_msg_" + obj.nd_id).html('Success').show(0).delay(2000).hide(1000);
                }
                if (obj.ok == 'error') {
                    jQuery(".hightlights_emoji_msg_" + obj.nd_id).html('You have already voted').show(0).delay(2000).hide(1000);
                }
                
            }
        });
      } else {
                jQuery(".hightlights_emoji_msg_" +nodeId).html('You have already voted').show(0).delay(2000).hide(1000);
      }

    });

    // end here
});