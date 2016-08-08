<?php

/*
 * Inc file contains the functions
 */
function tv_schedule_listing() {

  //getting value from Url
  $arg = arg();
  $search_title = $_GET['title'];
  $search_date = $_GET['date_zone'];
 
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

  // Particular day selection and current day selection
  if (isset($arg[1])) {
    $day = $arg[1];
    $cond = array('day' => $day);
  }
  elseif (isset($search_date)) {
    $date = $search_date;
    $cond = array('program date' => $date);
   }
  else {
    $day = strtoupper(date("D"));
    $cond = array('day' => $day);
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
            if ($curent_time >= $s_time) {
                $counter++;
            }
        }
    }

    if ($counter > 0) {
    $count = $counter - 1;
  }
 
  return theme('itg_tv_schedule', array('output' => $out, 'search' => $search, 'total' => $count, 'search_count' => $search_count, 'title' => $title));
}
