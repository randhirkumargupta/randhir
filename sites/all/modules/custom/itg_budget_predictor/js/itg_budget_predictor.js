/**
 * @file itg_widget.main.js
 * This is used for widgets setting
 */

Drupal.behaviors.itg_budget_predictor = {
    attach: function (context, settings) {
        //alert('hi = ' +Drupal.settings.itg_budget_predictor.settings.basePath);
        jQuery(function ()
        {
            var isUpdated;
            var year = Drupal.settings.itg_budget_predictor.settings.year;
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
                                    url: Drupal.settings.itg_budget_predictor.settings.basePath + '/ajax/budget-ranking/' + year,
                                    data:
                                            {
                                                sort1: jQuery("#sortable1").sortable('serialize'),
                                                sort2: jQuery("#sortable2").sortable('serialize'),
                                                sort3: jQuery("#sortable3").sortable('serialize')
                                            },
                                    success: function (html)
                                    {
                                        jQuery('.success').fadeIn(500);
                                    }
                                });
                    }
                }
            }).disableSelection();
        });

    }
};


// script for facebook sharing
(function(d, s, id) {
                        var js, fjs = d.getElementsByTagName(s)[0];
                        if (d.getElementById(id)) return;
                        js = d.createElement(s); js.id = id;
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
    tweetlink = "http://twitter.com/share?text="+title+"&url="+url+"&via=indiatoday";
    newwindow=window.open(tweetlink,'indiatoday','height=500,width=550,left=440,top=250');
    if (window.focus) {newwindow.focus()}
    return false;
  }
// twitter sharing end here

// script for google sharing
function badget_google_plus_share(url, title, img) {
  sharelink = "https://plus.google.com/share?url="+url;
  newwindow=window.open(sharelink,'indiatoday','height=400,width=600,left=440,top=250');
  if (window.focus) {newwindow.focus()}                                                                                                                                
  return false;
}   

function captureCurrentDiv()
{
        html2canvas([document.getElementById('main-container-budget')], {   
                onrendered: function(canvas)  
                {
                        var img = canvas.toDataURL()
                        jQuery.post("/budget-save", {data: img}, function (file) {
                            window.location.reload();
                        });   
                }
        });
}