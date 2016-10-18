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
$xml = simplexml_load_string($dataxml);
$json = json_encode($xml);
$array = json_decode($json,TRUE);

    return $array;
}