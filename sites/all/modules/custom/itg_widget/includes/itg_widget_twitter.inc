<?php

/**
 * @file
 * IPL Tweets
 */

/*
 * get tweets
 */
function ipl_tweets() {

  drupal_add_js(drupal_get_path('module', 'itg_widget') . '/js/itg_widget_ipl.js', array('weight' => 1, 'scope' => 'footer'));
  
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
    return;
}

