<?php

/*
 * Inc file contains the functions
 */
function tv_schedule_listing() {

    //getting value from Url
    $flag = 0;
    $arg = arg();
    $search_title = $_GET['title'];
    $search_date = $_GET['date_zone'];
    //calling custom method
    $sel_date = tv_schedule_list($search_date);

    if ($_GET['time_zone'] == 'PST') {
        date_default_timezone_set('America/Los_Angeles');
    }
    elseif ($_GET['time_zone'] == 'GMT') {
        date_default_timezone_set('Africa/Lome');
    }
    else {
        date_default_timezone_set('Asia/Kolkata');
    }
    $date = date("Y-m-d H:i:s");
    $time = new DateTime($date);
    $curent_time = $time->format('H:i');
    $current_day = $time->format('Y/m/d');

    $db = mongodb();
    $people = $db->tv_schedule;
    // Search result
    if (isset($search_title)) {
        $search_counter = 0;
        $title = $search_title;
        $regex = new MongoRegex("/$title/i");
        $cond = array('program' => $regex);
        $cursor_popup = $people->find($cond);
        $result = $cursor_popup->count();
        if ($result > 0) {
            $key = 0;
            foreach ($cursor_popup as $document) {
                $search[$key]['time'] = $document["time"];
                $search[$key]['day'] = $document["day"];
                $search[$key]['program'] = $document["program"];
                $key++;
                $search_counter++;
            }
            $search_count = $search_counter;
        }
        else {
            $search_count = 0;
        }
    }

    if ($sel_date > 0) {
        $date = $search_date;
        $cond = array('program date' => $date);
        $flag = 1;
    }
    else {
        if (isset($arg[1])) {
            $day = $arg[1];
            $cond = array('day' => $day);
        }
        else {
            $day = strtoupper(date("D"));
            $cond = array('day' => $day);
        }
    }

    $cursor = $people->find($cond);
    $results = $cursor->count();

    $counter = 0;
    $keys = 0;
    if ($results > 0) {
        // iterate cursor to get value of documents
        foreach ($cursor as $document) {
            $s_time = time_zone_conversion($document['time'], $_GET['time_zone']);
            if ($s_time == $curent_time) {
                $out[$keys]['time'] = '';
            }
            else {
                $out[$keys]['time'] = $s_time;
            }
            //$out[$keys]['time'] = $document["time"];
            $out[$keys]['day'] = $document["day"];
            $out[$keys]['program'] = $document["program"];
            $keys++;

            //counter required for current time slot display.
            if ($curent_time >= $s_time && $current_day == $document["program date"]) {
                $counter++;
            }
        }
    }

    if ($sel_date == 0 && $search_date != '') {
        $no_result = 'No program details found on this date ' . $search_date;
    }



    if ($counter > 0) {
        $count = $counter - 1;
    }

    return theme('itg_tv_schedule', array('output' => $out, 'search' => $search, 'total' => $count, 'search_count' => $search_count, 'title' => $title, 'no_result' => $no_result));
}

/**
 * Custom method for checking program details on particular date.
 *
 * @param string $search_date
 * @return int
 */
function tv_schedule_list($search_date) {
    $db = mongodb();
    $people = $db->tv_schedule;
    $date = $search_date;
    $cond = array('program date' => $date);
    $cursor = $people->find($cond);
    $results = $cursor->count();
    return $results;
}
