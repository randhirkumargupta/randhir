/*
 * @file showadcontent.js
 */
jQuery(document).ready(function () {
    if (__at__ != 1) {
      setTimeout(openPopup(), 4000);
      console.log('Detected');
    }

});

(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
    m=s.getElementsByTagName(o)
    [0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
    })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
  ga('create', 'UA-795349-17', 'auto');
  ga('set', 'dimension1', 'IndiaToday.in');
  ga('set', 'dimension2', 'India');
  ga('set', 'dimension3', 'India');  
  ga('send', 'pageview');

function openPopup() {
    jQuery(".description").hide();
    jQuery('.view-photo-landing-slider').hide();
    jQuery('.video-landing-header').hide();
    var a = gup('source');
    //console.log(a);
    ga("send", "event", "AdblockPopup", a, "true");
    ga("send", "event", "Adblock", a, "true");
    var post_data = "";
    jQuery.ajax({
        'url': Drupal.settings.baseUrl.baseUrl + '/ads-blocker-details-ajax',
        'data': post_data,
        'cache': false,
        'type': 'POST',
        // dataType: 'json',
        beforeSend: function () {

        },
        'success': function (result)
        {
           jQuery(".ad-blocker").html(result);
           if(jQuery('body').hasClass('node-type-videogallery')){
               jQuery('.node-type-videogallery').find('#content').prepend('<div class"ad-blocker">' + result + '</div>');
           }
            if (navigator.userAgent.indexOf('MSIE') !== -1 || navigator.appVersion.indexOf('Trident/') > 0) {
                jQuery('li#ie').addClass('active');
                jQuery('#tab13').fadeIn();
            } else if (navigator.userAgent.toLowerCase().indexOf("chrome") > -1) {
                jQuery('li#chrome').addClass('active');
                jQuery('body').find("li#chrome").addClass('active');
                jQuery('#tab11').fadeIn();
            } else if (navigator.userAgent.toLowerCase().indexOf("firefox") > -1) {
                jQuery('li#firefox').addClass('active');
                jQuery('#tab12').fadeIn();
            } else {
                jQuery('li#chrome').addClass('active');
                jQuery('#tab11').css('display', 'block');
            }
        }
    });

}

function gup(name) {
    //console.log('called');
    var str = window.location.href;
    var story = str.includes("/story/");
    var gallery = str.includes("/gallery/");
    var video = str.includes("/video/");

    if (story == true)
        return "IT-Story-site";

    if (gallery == true)
        return "IT-Photos-site";

    if (video == true)
        return "IT-Videos-site";
}

jQuery(document).ready(function () {
    jQuery('body').on('click', '.tabs ul li', function () {
        var currIndex = jQuery(this).index() + 1;
        jQuery('.tabs ul li').removeClass('active');
        jQuery(this).addClass('active');
        jQuery('.show_instruction').hide();
        jQuery('#tab1' + currIndex).fadeIn();
    });

    jQuery('body').on('click', 'a',function () {
        jQuery('html, body').animate({
            scrollTop: jQuery('[name="' + jQuery.attr(this, 'href').substr(1) + '"]').offset().top
        }, 1000);
        return false;
    });
    var count_h = 3;
    setInterval(counter_adblock, 1000);
    function counter_adblock() {
        if (count_h == 0) {
            jQuery('.cont_down').removeClass('active_bl');
            jQuery('.cont_to_site').addClass('active_bl');
        } else {
            jQuery('.counter_hh').html(count_h);
        }
        count_h--;
    }
    
});
