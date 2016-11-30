/*
 * @file itg_flag.js
 * Contains all functionality related to Flag Management
 */

(function ($) {
    Drupal.behaviors.itg_flag = {
        attach: function (context, settings) {
            var uid = settings.itg_flag.settings.uid;
            var base_url = settings.itg_flag.settings.base_url;
            
            $('#like_count,#dislike_count').click(function (event) {
                
                var nd_id = jQuery(this).attr('rel');
                var typ = jQuery(this).attr('id');
                var post_data = "&nd_id="+ nd_id + "&typ=" + typ;

                    $.ajax({
                        'url': base_url + '/flag-details-ajax',
                        'data': post_data,
                        'cache': false,
                        'type': 'POST',
                        // dataType: 'json',
                        beforeSend: function () {
                           
                        },
                        'success': function (result)
                        {
                            var obj = jQuery.parseJSON(result);
                             
                            $('#widget-ajex-loader').hide();
                            if (obj.type == 'like_count') {
                            $("#no-of-likes_"+obj.nd_id).html("(" + obj.count + ")");
                        }
                        if (obj.type == 'dislike_count') {
                            $("#no-of-dislikes_"+obj.nd_id).html("(" + obj.count + ")");
                        }
                        if (obj.error == 'error') {
                           
                            $("#voted_"+obj.nd_id).html('You have already voted').show(0).delay(2000).hide(1000);
                        }
                        }
                    });
               
            });
            
            // code for related content hide show
            
           
               $("body").on("click", ".hide_sh", function(e) {
                   console.log('hi');
               var obj = jQuery(this);
                var nd_id = jQuery(this).attr('rel');
                var post_data = "&nd_id="+ nd_id;
                var obj_parent = obj.parent();
                pos_left = obj_parent.offset().left, pos_top = obj_parent.offset().top - $(window).scrollTop(), parent_height = obj_parent.height();
                var parent_clone = obj_parent.clone();
                $("body").addClass("overlay");
                var rc_popup = $(".related-content-popup");
                rc_popup.addClass("popup-open"), 
                rc_popup.html(parent_clone), 
                rc_popup.css({left: pos_left, top: pos_top}),
                $("body").css("overflow", "hidden"), rc_popup.velocity({
                    duration: 300,
                    stagger: 80,
                    left: "500px",
                    top: "20px"
                }),
                
                    $.ajax({
                        'url': base_url + '/related-details-ajax',
                        'data': post_data,
                        'cache': false,
                        'type': 'POST',
                        // dataType: 'json',
                        beforeSend: function () {
                           
                        },
                        'success': function (result)
                        {
//                            obj.next('.nxt').html(result);
                         ///obj.html(result);
                         $('body').find('.related-content-popup').append(result);
                        }
                    });
               
            }); 
            
            // end here
            // jQuery code to close popular videos related content
            $('body').on('click', '.hide-rc', function(){
              $(this).prev().remove();
              $(this).remove();
            });
            
        }

    };
})(jQuery, Drupal, this, this.document);

// script for facebook sharing
(function(d, s, id) {
                        var js, fjs = d.getElementsByTagName(s)[0];
                        if (d.getElementById(id)) return;
                        js = d.createElement(s); js.id = id;
                        js.src = "//connect.facebook.net/en_US/sdk.js#xfbml=1&version=v2.8&appId=265688930492076";
                        fjs.parentNode.insertBefore(js, fjs);
                      }(document, 'script', 'facebook-jssdk'));

function gogogo(linkurl, title, desc, image) {
  FB.ui({
    method: 'feed',
    link: linkurl,
    picture: image,
    name: title,
    //caption: desc,
    description: desc
  });
}
  

//facebook sharing end here

// script for twitter sharing

  function twitter_popup(title, url) {
    tweetlink = "http://twitter.com/share?text="+title+"&url="+url+"&via=indiatoday";
    newwindow=window.open(tweetlink,'indiatoday','height=500,width=550,left=440,top=250');
    if (window.focus) {newwindow.focus()}
    return false;
  }

// twitter sharing end here

// script for google sharing

function googleplusbtn(url, title, img) {
  sharelink = "https://plus.google.com/share?url="+url;
  newwindow=window.open(sharelink,'indiatoday','height=400,width=600,left=440,top=250');
  if (window.focus) {newwindow.focus()}                                                                                                                                
  return false;
}   

// google sharing end here