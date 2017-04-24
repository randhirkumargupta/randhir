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
                    jQuery("#vno-of-likes_" + obj.nd_id).html(obj.count);
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
        if(jQuery(this).attr('data-activity') != 'undefined') {
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
                // case for follow story
                if (obj.success == 1 && obj.activity == 'follow_story') {
                    jQuery(".follow-story a").attr({
                        'data-status': 0,
                        title: 'Unfollow story'
                    }).html('Unfollow story');
                }
                if (obj.success == 0 && obj.activity == 'follow_story') {
                    jQuery(".follow-story a").attr({
                        'data-status': 1,
                        title: 'Follow the Story'
                    }).html('Follow the Story');
                }
                if (obj.error == 'error') {

                }
                // end here
                // case for read later
                    if (obj.success == '1' && obj.activity == 'read_later') {
                        if (obj.type == 'photogallery') {
                            jQuery('.later').html('<a href="javascript:void(0)" title="save" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i></a>');
                        }
                        if (obj.type == 'videogallery') {
                            jQuery('.later').html('<a title = "Save" href="javascript:" class="def-cur-pointer active"><i class="fa fa-clock-o"></i><span>Watch Later</span><span class="video-msg"></span></a>');
                        }
                        if (obj.type == 'story') {
                            jQuery('.later').html('<a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i><span>READ LATER</span></a>');
                            jQuery('.left-later').html('<span> <a title = "Read Later" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i>READ LATER</a><span class="flag-throbber">&nbsp;</span></span>');
                        }
                        jQuery('.stryimg').prepend('<div class="saved-photogallery">Saved</div>');
                        jQuery(".view-photo-landing-slider .slickslide li").append('<div class="saved-photogallery">Saved</div>');
                        jQuery(".video-landing-header .slick-track li").append('<div class="saved-photogallery">Saved</div>');
                        jQuery('.video-msg').html('<div class="saved-video">Saved</div>');
                        setTimeout(function () {
                            jQuery('.saved-photogallery').remove();
                            jQuery('.saved-video').remove();
                        }, 3000);

                    }
                    
                    if (obj.success == '0' && obj.activity == 'read_later') {
                      window.location.reload(true);
                    }
                
            }
        });
      } 
    });
    
     jQuery('.user-activity-highlight').click(function (event) {
        var nd_id = jQuery(this).attr('rel');
        var dtag = jQuery(this).attr('data-tag');
        var nodeId = jQuery(this).attr('data-nodeid');
        var dstatus = jQuery(this).attr('data-status');
        var data_activity = jQuery(this).attr('data-activity');
        var post_data = "&nd_id=" + nd_id + "&dtag=" + dtag + "&data_activity=" + data_activity + "&dstatus=" + dstatus;
        if(!jQuery(this).closest(".emoji-container").find("a").hasClass('def-cur-none-pointer')) {
            jQuery(this).closest(".emoji-container").find("a").removeClass("def-cur-pointer").addClass("def-cur-none-pointer");
            jQuery.ajax({
                'url': Drupal.settings.baseUrl.baseUrl + '/user-activity-front-highlight',
                'data': post_data,
                'cache': false,
                'type': 'POST',
                // dataType: 'json',
                beforeSend: function () {

                },
                'success': function (result)
                {
                    var obj = jQuery.parseJSON(result);
                    if (obj.ok == 'hightlights_emoji_true') {
                        jQuery("."+obj.rel).html("(" + obj.count + ")");
                        jQuery(".hightlights_emoji_msg_" + obj.nd_id).html('Success').show(0).delay(2000).hide(1000);
                    }
                    if (obj.ok == 'error') {
                        jQuery(".hightlights_emoji_msg_" + obj.nd_id).html('You have already voted').show(0).delay(2000).hide(1000);
                    }

                }
            });
        }
       else {
           jQuery(this).closest(".emoji-container").next("p").html('You have already voted').show(0).delay(2000).hide(0);
       }
    });

    // end here
    
    // alert on ugc reject link click
    jQuery(document).ready(function () {
        jQuery(".ugc-reject").click(function () {
            var reject_status = "reject";
            if (reject_status == "reject") {
                var msg = confirm("Are you sure you want to reject this content?");
                if (msg == true) {
                    return true;
                }
                return false;
            }
            return true;
        });
    });
    
    // alert on ugc delete content
    jQuery(document).ready(function () {
        jQuery(".user-con-delete").click(function () {
            var reject_status = "delete";
            if (reject_status == "delete") {
                var msg = confirm("Are you sure you want to Delete this content?");
                if (msg == true) {
                    return true;
                }
                return false;
            }
            return true;
        });
    });
});