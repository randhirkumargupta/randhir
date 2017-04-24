<?php

/**
 * @file
 * IPL Tweets
 */
/*
 * get tweets
 */
function live_score() {
    $urllivescore = variable_get('live_score_url');
    try {
           $dataxml = simplexml_load_file($urllivescore);
    } catch (Exception $ex) {
        drupal_set_message($ex->getMessage());
    }
    if (!empty($dataxml)) {
        return (array) $dataxml->match;
    }
}
