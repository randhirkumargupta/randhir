/*
 * Function for dfp tags for video and embed video page.
 */
function get_dfp_tags_script(used_on, external, node_url) {
    var itgdGroupAds = "";
    var referrer = document.referrer;
    itgdAds = "https://pubads.g.doubleclick.net/gampad/ads?sz=640x480|400x300&iu=/1007232/Indiatoday_VOD_Pre_Roll_WEB&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&url=[referrer_url]&description_url=" + node_url + "&correlator=[timestamp]";
    if (used_on == 'embed') {
        itgdAds = "https://pubads.g.doubleclick.net/gampad/ads?sz=400x300|640x480&iu=/1007232/IT_embed_external_web_VOD&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&url=[referrer_url]&description_url=" + node_url + "&correlator=[timestamp]";
        if (referrer.length > 0) {
            itgdGroup = false;
            ItgdDomain = getDomain(referrer);
            if (ItgdDomain == 'aajtak.in' || ItgdDomain == 'indiatoday.in' || ItgdDomain == 'intoday.in' || ItgdDomain == 'indiatodayonline.in' || ItgdDomain == 'dailyo.in' || ItgdDomain == 'ichowk.in' || ItgdDomain == 'mobiletak.in' || ItgdDomain == 'thelallantop.com') {
                itgdGroup = true;
                itgdAds = "https://pubads.g.doubleclick.net/gampad/ads?sz=400x300|640x480&iu=/1007232/IT_embed_internal_web_VOD&impl=s&gdfp_req=1&env=vp&output=vast&unviewed_position_start=1&url=[referrer_url]&description_url=" + node_url + "&correlator=[timestamp]";
            }
        }
    }
    console.log(" Referrer :" + referrer);
    console.log(" Ads :" + itgdAds);
    itgdAds = encodeURI(itgdAds)
    return itgdAds;
}

/*
 * Function for getting domain from url.
 */
function getDomain(url) {
    if (url) {
        var match = /(?:https?:\/\/)?(?:\w+:\/)?[^:?#\/\s]*?([^.\s]+\.(?:[a-z]{2,}|co\.uk|org\.uk|ac\.uk|org\.au|com\.au))(?:[:?#\/]|$)/gi
                .exec(url);
        return match ? match[1] : null;
    } else
        return null;
}
