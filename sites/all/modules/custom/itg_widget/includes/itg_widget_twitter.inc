<?php

/**
 * @file
 * IPL Tweets
 */

/*
 * get tweets
 */
function ipl_tweets() {
    global $theme;
  
    if($theme == 'itgadmin')
    {
    drupal_add_js("jQuery(document).ready(function() {
         ! function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0],
        p = /^http:/.test(d.location) ? 'http' : 'https';
    if (!d.getElementById(id)) {
        js = d.createElement(s);
        js.id = id;
        js.src = p + '://platform.twitter.com/widgets.js';
        fjs.parentNode.insertBefore(js, fjs);
    }
}(document, 'script', 'twitter-wjs');
      
    });", array('type' => 'inline', 'scope' => 'footer'));

    return '<a class="twitter-timeline"
  data-widget-id="349125700000829440"
  href="https://twitter.com/IPL"
  width="500"
  height="500" data-chrome="nofooter">IPL TWEETS</a>
 ';
    } else {
        drupal_add_js("jQuery(document).ready(function() {
         ! function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0],
        p = /^http:/.test(d.location) ? 'http' : 'https';
    if (!d.getElementById(id)) {
        js = d.createElement(s);
        js.id = id;
        js.src = p + '://platform.twitter.com/widgets.js';
        fjs.parentNode.insertBefore(js, fjs);
    }
}(document, 'script', 'twitter-wjs');
      
    });", array('type' => 'inline', 'scope' => 'footer'));

    return '<a class="twitter-timeline"
  data-widget-id="349125700000829440"
  href="https://twitter.com/IPL"
  width="500"
  height="500" data-chrome="nofooter">IPL TWEETS</a>';
   // return '<span class="widget-title">IPL TWEETS</span> ';
    }
    
}