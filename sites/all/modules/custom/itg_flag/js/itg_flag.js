/*
 * @file itg_flag.js
 * Contains all functionality related to Flag Management
 */

/*(function ($) {
    Drupal.behaviors.itg_flag = {
        attach: function (context, settings) {
            var uid = settings.itg_flag.settings.uid;
            var base_url = settings.itg_flag.settings.base_url;
        }

    };
})(jQuery, Drupal, this, this.document);*/

// script for facebook sharing
var app = Drupal.settings.itg_flag.settings.fb_app;
window.fbAsyncInit = function() {
        FB.init({
          appId            : app,
          autoLogAppEvents : true,
          xfbml            : true,
          version          : 'v2.10'
        });
        FB.AppEvents.logPageView();
  };
  
jQuery(window).load( function(){
  (function(d, s, id){
         var js, fjs = d.getElementsByTagName(s)[0];
         if (d.getElementById(id)) {return;}
         js = d.createElement(s); js.id = id;
         js.src = "//connect.facebook.net/en_US/sdk.js";
         fjs.parentNode.insertBefore(js, fjs);
   }(document, 'script', 'facebook-jssdk'));
});

function fbpop(overrideLink, overrideTitle, overrideDescription, overrideImage, base_url, node_id)
{
    if (overrideImage.length === 0) {
        overrideImage = Drupal.settings.itg_flag.settings.default_image;
    } else {
        overrideImage = overrideImage;
    }

    overrideTitle = decodeURIComponent((overrideTitle + '').replace(/\+/g, '%20'));;
    overrideDescription = decodeURIComponent((overrideDescription + '').replace(/\+/g, '%20'));;
    FB.ui({
        method: 'share_open_graph',
        action_type: 'og.shares',
        action_properties: JSON.stringify({
            object: {
                'og:url': overrideLink,
                'og:title': overrideTitle,
                'og:description': overrideDescription,
                'og:image': overrideImage,
            }
        })
    },
    function (response) {
        var front_uid = Drupal.settings.itg_flag.settings.uid;
        jQuery.ajax({
                //url: base_url + '/earn-loyalty-point/' + node_id + '/share',
                url: base_url + '/fb-share-callback/' + node_id + '/' + front_uid,
                type: 'POST',
                dataType: 'JSON',
        });
        if (front_uid > 0) {
            jQuery.ajax({
                //url: base_url + '/earn-loyalty-point/' + node_id + '/share',
                url: base_url + '/itg-global-fb-point/' + node_id + '/facebook_share',
                type: 'POST',
                dataType: 'JSON',
            });
        }
        // Action after response
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
        var nd_id = jQuery(this).attr('data-rel');
        var typ = jQuery(this).attr('id');
        var dtag = jQuery(this).attr('data-tag');
        var datatype = jQuery(this).attr('data-type');
        var post_data = "&nd_id=" + nd_id + "&typ=" + typ + "&dtag=" + dtag + "&datatype=" + datatype;

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
                // console.log(obj.type, obj, obj.type == 'like_count');
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
    jQuery('body').on('click', '#user-activity, .user-activity', function (event) {
   // jQuery('#user-activity, .user-activity').click(function (event) {
        var nd_id = jQuery(this).attr('data-rel');
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
            'success': function (result) {
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
        var nd_id = jQuery(this).attr('data-rel');
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

    // jquery for front follow / unfollow
    jQuery('.follow-activity').click(function (event) {
        var id = jQuery(this).attr('id');
        var ftitle = jQuery(this).attr('data-ftitle');
        var untitle = jQuery(this).attr('data-untitle');
        var nd_id = jQuery(this).attr('data-rel');
        var dtag = jQuery(this).attr('data-tag');
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
                'success': function (result) {
                    var obj = jQuery.parseJSON(result);

                    // case for follow anchor
                    if (obj.success == 1 && obj.activity == data_activity) {
                        jQuery("#" + id).attr({
                            'data-status': 0,
                            title: untitle
                        }).html(untitle);
                    }
                    if (obj.success == 0 && obj.activity == data_activity) {
                        jQuery("#" + id).attr({
                            'data-status': 1,
                            title: ftitle
                        }).html(ftitle);
                    }
                    if (obj.error == 'error') {

                    }

                }
            });
        }
    });
    
    // call back for submit story in case of akamai
    jQuery('body').on('click', '.story-login-follow, .photo-login-akamai, .video-login-akamai', function (event) {
    //jQuery('.story-login-follow').click(function (event) {
        var post_data = "";
            jQuery.ajax({
                'url': Drupal.settings.baseUrl.baseUrl + '/story-login-follow-callback',
                'data': post_data,
                'cache': false,
                'type': 'POST',
                // dataType: 'json',
                beforeSend: function () {

                },
                'success': function (result) {
                    var obj = jQuery.parseJSON(result);
                    if (obj.anony == 'true') {
                      jQuery('.akamai-submit-story-col').trigger('click');  
                    }
                    if (obj.loggedin == 'true') {
                      var uri = Drupal.settings.baseUrl.baseUrl+'/post-ugc-content';
                      window.location.href = uri;
                    }
                }
            });
        
    });

});

// jquery for delete follow / unfollow
jQuery('.delete_class').click(function () {
    var li = jQuery(this).closest('li'),
        del_id = jQuery(this).attr('id');
    var post_data = "&nd_id=" + del_id;
    if(confirm("Are you sure you want to delete this?")){
        jQuery.ajax({
            'url': Drupal.settings.baseUrl.baseUrl + '/user-remove-follow-activity',
            'data': post_data,
            'cache': false,
            'type': 'POST',
            beforeSend: function () {

            },
            'success': function (result) {
                var obj = jQuery.parseJSON(result);
                li.fadeOut(1000, function(){
                    jQuery(this).remove();
                });
                if (obj.error == 'error') {

                }

            }
        });
    }
    else{
        return false;
    }
});

//common function for mobile
function mobilechecks() {
    var check = false;
    (function (a) {
        if (/(android|ipad|playbook|silk|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(a) || /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0, 4)))
            check = true
    })(navigator.userAgent || navigator.vendor || window.opera);
    return check;
}

var is_mobiles = mobilechecks() ? true : false;
if (is_mobiles) {
    jQuery('.follow-author').hide();
    jQuery('.follow-topics').hide();
    jQuery("a.letter").click(function () {
        jQuery("a.letter").removeClass('activetab');
        jQuery(this).addClass('activetab');
        var letter = jQuery(this).attr('id');
        jQuery('.follow-anchor').hide();
        jQuery('.follow-author').hide();
        jQuery('.follow-topics').hide();
        jQuery('.' + letter ).show().addClass('acti');

    });
}


function graphfbpop(overrideLink, overrideTitle, overrideDescription, overrideImage, width, height)
{
    if (overrideImage.length === 0) {
        overrideImage = Drupal.settings.itg_flag.settings.default_image;
    } else {
        overrideImage = overrideImage;
    }
    overrideTitle = decodeURIComponent((overrideTitle + '').replace(/\+/g, '%20'));;
    overrideDescription = decodeURIComponent((overrideDescription + '').replace(/\+/g, '%20'));;
    FB.ui({
        method: 'share_open_graph',
        action_type: 'og.shares',
        action_properties: JSON.stringify({
            object: {
                'og:url': overrideLink,
                'og:title': overrideTitle,
                'og:description': overrideDescription,
                'og:image': overrideImage,
                'og:image:width': width,
                'og:image:height': height
            }
        })
    },
    function (response) {
        console.log('Graph share');
        // Action after response
    });
}