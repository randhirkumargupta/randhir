<?php

/*
 * Inc file contains the functions
 */
function tv_schedule_listing() {

  //getting value from Url
  if (function_exists('mongodb')) {
    $db = mongodb();
  }

  if (isset($db)) {

    if(isset($_GET['action']) && $_GET['action'] == 'preview'){
      $status = array(0,1);

    }else{
      $status = array(1);
    }

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
    $people = $db->tv_schedule;
    // Search result
    if (isset($search_title)) {
      $search_counter = 0;
      $title = $search_title;
      $regex = new MongoRegex("/$title/i");
      $cond = array('program' => $regex, 'status' => array( '$in' => $status ));
      $cursor_popup = $people->find($cond);
      $result = $cursor_popup->count();
      if ($result > 0) {
        $key = 0;
        foreach ($cursor_popup as $document) {
          $search[$key]['time'] = $document["time"];
          $search[$key]['day'] = $document["day"];
          $search[$key]['program'] = $document["program"];
          $search[$key]['program date'] = $document["program date"];
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
      $cond = array('program date' => $date, 'status' => array( '$in' => $status ));
      $flag = 1;
    }
    else {
      if (isset($arg[1])) {
        $day = $arg[1];
        $date_from_day = date('Y/m/d', strtotime( "$day this week" ));
        $cond = array('program date' => $date_from_day, 'day' => $day, 'status' => array( '$in' => $status ));
      }
      else {
        $cond = array('program date' => $current_day, 'status' => array( '$in' => $status ));
      }
    }

    $all_cursor = $people->find($cond);
    $results = $all_cursor->count();

    $channel_cursor = array();
    $channel_results_count = array();

    $allowed = array('Indiatoday_tvschedule.csv', 'aajtak_tvschedule.csv', 'Dilliaajtak_tvschedule.csv', 'tez_tvschedule.csv');
    foreach( $allowed as $val){
      $cond['filetype'] = $val;
      $channel_cursor[$val] = $people->find($cond);
      $channel_results_count[$val] = $channel_cursor[$val]->count();
    }

    // echo  "<pre>";
    // print_r($channel_results_count);
    // die;



    if ($results > 0 && !empty($channel_cursor)) {
      foreach($channel_cursor as $key => $cursor){


        if($channel_results_count[$key] > 0){
          $counter = 0;
          $keys = 0;
          $time_slider = array();
      // iterate cursor to get value of documents
          foreach ($cursor as $document) {

            $s_time = time_zone_conversion($document['time'], $_GET['time_zone']);
            if ($s_time == $curent_time) {
              $time_slider[$keys]['time'] = '';
            }
            else {
              $time_slider[$keys]['time'] = $s_time;
            }

            $out[$key][$keys]['day'] = $document["day"];
            $out[$key][$keys]['program'] = $document["program"];
            $out[$key][$keys]['program date'] = $document["program date"];
            $out[$key][$keys]['status'] = $document["status"];
            $out[$key][$keys]['type'] = $document["filetype"];

            if (!empty($search_date)) {
              $ass_search_date = $search_date;
            }
            else {
              $ass_search_date = date('Y/m/d');
            }
            // $node_detail = node_load(tv_story_list($ass_search_date, $document['time']));
            // if (!empty($node_detail->nid)) {
            //   $out[$keys]['story_attach'] = l('', 'node/' . $node_detail->nid, array('options' => array('absolute' => TRUE), 'attributes' => array('target' => '_blank', 'class' => array('fa', 'fa-file-text'), 'title' => $node_detail->title)));
            // }
            $keys++;

            //counter required for current time slot display.
            if (($curent_time >= $s_time) && ($current_day == $document["program date"])) {
              $counter++;
            }
          }
        }
      }
    }

    // if ($sel_date == 0 && $search_date != '') {
    //   $no_result = '<div class="no-tv-program">No program details found on this date ' . $search_date . '</div>';
    // }

    if ($counter > 0) {
      $count = $counter - 1;
    }

    return theme('itg_tv_schedule', array('output' => $out, 'search' => $search, 'total' => $count, 'search_count' => $search_count, 'title' => $title, 'no_result' => $no_result, 'time_slider' => $time_slider));
  }
}

/**
 * Custom method for checking program details on particular date.
 *
 * @param string $search_date
 * @return int
 */
function tv_schedule_list($search_date) {
  $db = mongodb();
  if (isset($db)) {
    $people = $db->tv_schedule;
    $date = $search_date;
    $cond = array('program date' => $date, 'status' => 1);
    $cursor = $people->find($cond);
    $results = $cursor->count();
    return $results;
  }
}

/**
 * Custom method for checking story details on particular date.
 *
 * @param string $date
 * @param string $time
 * @return int
 */
function tv_story_list($date, $time) {
  $itg_query = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'story')
      ->condition('status', 1);
  $itg_query->join('field_data_field_poll_start_date', 'frq', 'n.nid = frq.entity_id');
  $itg_query->condition('frq.field_poll_start_date_value', $date);
  $itg_query->join('field_data_field_story_tv_time', 'ast', 'n.nid = ast.entity_id');
  $itg_query->condition('ast.field_story_tv_time_value', $time);
  $itg_result = $itg_query->execute()->fetchField();

  return $itg_result;
}
