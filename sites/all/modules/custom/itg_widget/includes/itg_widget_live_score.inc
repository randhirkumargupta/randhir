<?php

/**
 * @file
 * IPL Tweets
 */

/*
 * get tweets
 */
function live_score() {
    $dataxml=  simplexml_load_file("http://cricketlive.intoday.in/data/scores-gadget.xml");
   
    return (array)$dataxml->match;
}