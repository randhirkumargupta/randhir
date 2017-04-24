<?php

/**
 * @file
 * IPL Tweets
 */

/*
 * get tweets
 */
function ipl_tweets() {

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
     
}

/*
 * get tweets budget
 */
function budget_tweets() {

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
  href="https://twitter.com/indiabudgetlive"
  width="500"
  height="500" data-chrome="nofooter">IPL TWEETS</a>
 ';
     
}


/*
 * get tweets election
 */
function election_tweets() {

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

    return '
<a class="twitter-timeline"
  href="https://twitter.com/TwitterDev"
  data-width="300"
  data-height="300">
Tweets by @TwitterDev
</a> ';
     
}

