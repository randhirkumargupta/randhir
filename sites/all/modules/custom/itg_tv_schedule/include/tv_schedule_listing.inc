<?php
module_load_include('module', 'itg_tv_schedule', 'itg_tv_schedule.module');

/*
 * Inc file contains the functions
 */

/**
 * ugc comment details callback
 */
function tv_schedule_listing() {
    //time_zone_conversion();
    if ($_GET['time_zone'] == 'PST'){
        date_default_timezone_set('America/Los_Angeles');
        $date = date("Y-m-d H:i:s");
        $time = new DateTime($date);
        $curent_time = $time->format('H:i'); 
    }elseif ($_GET['time_zone'] == 'GMT') {
        date_default_timezone_set('Africa/Lome');
        $date = date("Y-m-d H:i:s");
        $time = new DateTime($date);
        $curent_time = $time->format('H:i');    
    }else{
        date_default_timezone_set('Asia/Kolkata');
        $date = date("Y-m-d H:i:s");
        $time = new DateTime($date);
        $curent_time = $time->format('H:i');  
    }
    
    
    
    
    $arg = arg();
    $con = new Mongo();
    // Select Database
    $db = $con->csvhandling;
    // Select Collection
    $people = $db->itgcms_demos;
    // Search result  
    if (isset($_GET['title'])) {
        $title = $_GET['title'];
        //if ($title == null){
        // $result = "No Result Found";   
        //}
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
    $counter = 0;
    $keys = 0;
    // iterate cursor to get value of documents
    foreach ($cursor as $document) {
        $s_time = time_zone_conversion($document["time"], $_GET['time_zone']);
        $out[$keys]['time'] = $s_time;       
        $out[$keys]['day'] = $document["day"];
        $out[$keys]['program'] = $document["program"];
        $keys++;
       
        if($curent_time >= $s_time){
          $counter++;
        }
       
    }
    if($counter > 0){
       $count = $counter-1;
    }

    return theme('itg_tv_schedule', array('output' => $out, 'search' => $search, 'total' => $count));
}

?>