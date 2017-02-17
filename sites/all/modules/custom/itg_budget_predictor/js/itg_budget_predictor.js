/**
 * @file itg_budget_predictor.js
 * This is used for budget predictor
 */

Drupal.behaviors.itg_budget_predictor = {
    attach: function (context, settings) {
        jQuery(function ()
        {

            var section_id = Drupal.settings.itg_budget_predictor.settings.section_id;
            var user_id = Drupal.settings.itg_budget_predictor.settings.user_id;
            var budget_predictor_cookies_id = Drupal.settings.itg_budget_predictor.settings.budget_predictor_cookies_id;
            var admin_user = Drupal.settings.itg_budget_predictor.settings.admin_user;
            var cookies_name = Drupal.settings.itg_budget_predictor.settings.cookies_name;

            var pre_budget = Drupal.settings.itg_budget_predictor.settings.pre_budget;
            var present_budget = Drupal.settings.itg_budget_predictor.settings.present_budget;

            var cookies_id = jQuery.cookie("COOKIES_IT_" + section_id);
            jQuery.removeCookie("COOKIES_IT_" + section_id);
            if(user_id == 0 && pre_budget != '') {
                var date = new Date();
                var minutes = 30;
                date.setTime(date.getTime() + (minutes * 60 * 1000));
                jQuery.cookie("COOKIES_IT_" + section_id, budget_predictor_cookies_id, { expires: date }); // Sample 3
            } else if(present_budget != ''){
                jQuery.removeCookie("COOKIES_IT_" + section_id);
                var date = new Date();
                var minutes = 30;
                date.setTime(date.getTime() + (minutes * 60 * 1000));
                jQuery.cookie("COOKIES_IT_" + section_id, budget_predictor_cookies_id, { expires: date }); // Sample 3
            }

            if (Drupal.settings.itg_budget_predictor.settings.stopPredictor == 2) {
                var isUpdated;
                jQuery('#ranking-content ul li, #ranking-content-main ul li, .ranking-content ul li').mouseover(function () {
                    var ranking_column_id = jQuery(this).data("id");
                    var str = jQuery(this).attr("id");
                    var entity_id = str.split("_");
                    
                     jQuery("#sortable1, #sortable2, #sortable3, #sortable4").sortable(
                        {
                            connectWith: '.connectedSortable',
                            update: function (event, ui) {
                                isUpdated = true;
                            },
                            stop: function (event, ui) {
                                if (isUpdated == true) {
                                    //Do Something
                                    jQuery.ajax(
                                            {
                                                type: "POST",
                                                url: Drupal.settings.itg_budget_predictor.settings.basePath + '/ajax/budget-ranking/' + section_id,
                                                beforeSend: function() {
                                                                jQuery('#loader-data img').show();
                                                            },
                                                        data:
                                                        {
                                                            sort1: jQuery("#sortable1").sortable('serialize'),
                                                            sort2: jQuery("#sortable2").sortable('serialize'),
                                                            sort3: jQuery("#sortable3").sortable('serialize'),
                                                            sort4: jQuery("#sortable4").sortable('serialize'),
                                                            cookies_id: jQuery.cookie("COOKIES_IT_" + section_id),
                                                            eid: entity_id[1],
                                                            ranking_column_id: ranking_column_id,
                                                        },
                                                success: function (html)
                                                {
                                                    jQuery('.success').fadeIn(500);
                                                    jQuery('#loader-data img').hide();

                                                }
                                            });
                                }
                            }
                        }).disableSelection();
                    
                });

               
            }

        });

    }
};


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

function badget_fb_share(linkurl, title, desc, image) {
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
function badget_twitter_share(title, url) {
    tweetlink = "http://twitter.com/share?text=" + title + "&url=" + url + "&via=indiatoday";
    newwindow = window.open(tweetlink, 'indiatoday', 'height=500,width=550,left=440,top=250');
    if (window.focus) {
        newwindow.focus()
    }
    return false;
}
// twitter sharing end here

// script for google sharing
function badget_google_plus_share(url, title, img) {
    sharelink = "https://plus.google.com/share?url=" + url;
    newwindow = window.open(sharelink, 'indiatoday', 'height=400,width=600,left=440,top=250');
    if (window.focus) {
        newwindow.focus()
    }
    return false;
}

function captureCurrentDiv(section_id)
{
    var cookies_id = jQuery.cookie("COOKIES_IT_" + section_id);
    html2canvas([document.getElementById('main-container-budget')], {
        onrendered: function (canvas)
        {
            var img = canvas.toDataURL()
            jQuery.post("/budget-save/"+section_id, {data: img, cookies_id: cookies_id }, function (file) {
                window.location.reload();
            });
        }
    });
}


function reset_budget(section_id) {
    jQuery.post('/ajax/reset-budget-data/' + section_id, {status: 2}, function (file) {
                window.location.reload();
            });
}
