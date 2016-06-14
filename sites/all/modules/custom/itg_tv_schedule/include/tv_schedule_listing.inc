<?php

/*
 * Inc file contains the functions
 */

/**
 * ugc comment details callback
 */
function tv_schedule_listing() {
    $arg = arg();
    $con = new Mongo();
    // Select Database
    $db = $con->csvhandling;
    // Select Collection
    $people = $db->itgcms_demos;
    // Search result  
    if (isset($_GET['title'])) {
        $title = $_GET['title'];
        $regex = new MongoRegex("/^$title/i");
        $cond = array('program' => $regex);
        $cursor_popup = $people->find($cond);
        $key = 0;
        foreach ($cursor_popup as $document) {
            $search[$key]['time'] = $document["time"];
            $search[$key]['day'] = $document["day"];
            $search[$key]['program'] = $document["program"];
            $key++;
        }
    }
    // Particular day selection and current day selection 
    if (isset($arg[1])) {
        $day = $arg[1];
        $cond = array('day' => $day);
    }
    else {
        $day = strtoupper(date("D"));
        $cond = array('day' => $day);
    }

    $cursor = $people->find($cond);
    $key = 0;
    // iterate cursor to get value of documents
    foreach ($cursor as $document) {
        $out[$key]['time'] = $document["time"];
        $out[$key]['day'] = $document["day"];
        $out[$key]['program'] = $document["program"];
        $key++;
    }

    return theme('itg_tv_schedule', array('output' => $out, 'search' => $search));
}

?>