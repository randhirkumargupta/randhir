<?php

/**
 * Inc file contains the functions for story_Count_report API
 */

/**
 * main function for generate story_video_photo_field_report array
 * @pram datetime $start_date
 * @pram datetime $end_date
 *
 * @return array
 */
function story_video_photo_field_report($start_date, $end_date) {
  global $base_url;
  $data = array();
  $section_list_count = array();
  $vid = 14;
  $section_list = getSectionListByVID($vid);
  //p($section_list); die();
  $section_list_count = nodeCountByDateWise_Report($start_date, $end_date, $section_list);

  $hour = 01;
  $today = strtotime($hour . ':00:00');
  $yesterday = strtotime('-1 day', $today);
  $dayBeforeYesterday = strtotime('-1 day', $yesterday);

  $today_key = date("Y-m-d", $today);
  $yesterday_key = date("Y-m-d", $yesterday);

  $data['overall']['category'] = $section_list_count['between'];
  $data['overall']['total'] = $section_list_count['between'];

  /*date loop start*/
  
  $datediff = $end_date - $start_date;
  $datediff_c = floor($datediff / (60 * 60 * 24));
  $date_l_c = 0;
  while($date_l_c <= $datediff_c){
      
      if($date_l_c == 0){
          $today_key = date("Y-m-d", $start_date); 
          $start_epoc = $start_date;                  
      }
      else{
          $start_epoc = $epoch_to_next = 86400 * $date_l_c;
          $today_key = date("Y-m-d", ($start_date + $epoch_to_next));
      }
      $end_epoc = $start_date + (3600 * 22);  
      $section_list_count_t = nodeCountByToday_Report($start_date, $end_epoc, $section_list);
    
    $data['datewise_data'][$today_key]['category'] = $section_list_count_t['today'];
    $data['datewise_data'][$today_key]['total'] = $section_list_count_t['today'];
    $date_l_c++;
  }
/*date loop end*/

  return $data;
}

/**
 * function for get section list array
 * @pram int $vid
 *
 * @return array $section_list
 */
function getSectionListByVID($vid = 14) {
  $query = db_select('taxonomy_term_data', 'td');
  $query->leftJoin('taxonomy_term_hierarchy', 'th', 'th.tid=td.tid');
  $query->leftJoin('taxonomy_vocabulary', 'tv', 'tv.vid=td.vid');
  $query->condition('th.parent', 0);
  $query->condition('tv.vid', 14);
  $query->fields('td', array('tid', 'name'));
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  return $result;
}

/**
 * function for get section list with node count Report array
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram array $section_list
 *
 * @return array $section_list_count
 */
function nodeCountByDateWise_Report($start_date, $end_date, $section_list) {
  $section_list_count = array();
  $between_list_count = array();
  $today_list_count = array();
  $yesterday_list_count = array();
  $video_cont = array();
  $photo_cont = array();
  $story_cont = array();
  $loop_count = 0;
  // loop on section list
  foreach ($section_list as $key => $value) {
    //p($value);die();

    $story_cont = countStory($start_date, $end_date, $value['tid']);
    $video_cont = countVideo($start_date, $end_date, $value['tid']);
    $photo_cont = countPhoto($start_date, $end_date, $value['tid']);
    $sum_between = 0;
    $sum_today = 0;
    $sum_yesteday = 0;
    // p($story_cont);die();
    //$sum = array_sum($story_cont) + array_sum($video_cont) + array_sum($photo_cont);
    $sum_between += $story_cont['total_records_between'] + $story_cont['total_records_between_inhouse'] + $story_cont['total_records_between_agency'];
    $sum_between += $video_cont['total_records_between'] + $video_cont['total_records_between_inhouse'] + $video_cont['total_records_between_agency'];
    $sum_between += $photo_cont['total_records_between'] + $photo_cont['total_records_between_inhouse'] + $photo_cont['total_records_between_agency'];

    $sum_today += $story_cont['total_records_today'] + $story_cont['total_records_today_inhouse'] + $story_cont['total_records_today_agency'];
    $sum_today += $video_cont['total_records_today'] + $video_cont['total_records_today_inhouse'] + $video_cont['total_records_today_agency'];
    $sum_today += $photo_cont['total_records_today'] + $photo_cont['total_records_today_inhouse'] + $photo_cont['total_records_today_agency'];

    $sum_yesteday += $story_cont['total_records_yesterday'] + $story_cont['total_records_yesterday_inhouse'] + $story_cont['total_records_yesterday_agency'];
    $sum_yesteday += $video_cont['total_records_yesterday'] + $video_cont['total_records_yesterday_inhouse'] + $video_cont['total_records_yesterday_agency'];
    $sum_yesteday += $photo_cont['total_records_yesterday'] + $photo_cont['total_records_yesterday_inhouse'] + $photo_cont['total_records_yesterday_agency'];

    $term_name = $value['name'];
    $term_tid = $value['tid'];


    //Inhouce count merging
    if ($story_cont['total_records_between_inhouse'] > 0) {
      $between_list_count[$term_name]['inhouse'] = $story_cont['total_records_between_inhouse'];
    }
    else {
      if ($sum_between > 0) {
        $between_list_count[$term_name]['inhouse'] = 0;
      }
    }
    if ($story_cont['total_records_today_inhouse'] > 0) {
      $today_list_count[$term_name]['inhouse'] = $story_cont['total_records_today_inhouse'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['inhouse'] = 0;
      }
    }
    if ($story_cont['total_records_yesterday_inhouse'] > 0) {
      $yesterday_list_count[$term_name]['inhouse'] = $story_cont['total_records_yesterday_inhouse'];
    }
    else {
      if ($sum_yesteday > 0) {
        $yesterday_list_count[$term_name]['inhouse'] = 0;
      }
    }

    //Agency count merging
    if ($story_cont['total_records_between_agency'] > 0) {
      $between_list_count[$term_name]['agency'] = $story_cont['total_records_between_agency'];
    }
    else {
      if ($sum_between > 0) {
        $between_list_count[$term_name]['agency'] = 0;
      }
    }
    if ($story_cont['total_records_today_agency'] > 0) {
      $today_list_count[$term_name]['agency'] = $story_cont['total_records_today_agency'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['agency'] = 0;
      }
    }
    if ($story_cont['total_records_yesterday_agency'] > 0) {
      $yesterday_list_count[$term_name]['agency'] = $story_cont['total_records_yesterday_agency'];
    }
    else {
      if ($sum_yesteday > 0) {
        $yesterday_list_count[$term_name]['agency'] = 0;
      }
    }
    //video count merging
    if ($video_cont['total_records_between'] > 0) {
      $between_list_count[$term_name]['video'] = $video_cont['total_records_between'];
    }
    else {
      if ($sum_between > 0) {
        $between_list_count[$term_name]['video'] = 0;
      }
    }
    if ($video_cont['total_records_today'] > 0) {
      $today_list_count[$term_name]['video'] = $video_cont['total_records_today'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['video'] = 0;
      }
    }
    if ($video_cont['total_records_yesterday'] > 0) {
      $yesterday_list_count[$term_name]['video'] = $video_cont['total_records_yesterday'];
    }
    else {
      if ($sum_yesteday > 0) {
        $yesterday_list_count[$term_name]['video'] = 0;
      }
    }

    //photo count merging
    if ($photo_cont['total_records_between'] > 0) {
      $between_list_count[$term_name]['photo'] = $photo_cont['total_records_between'];
    }
    else {
      if ($sum_between > 0) {
        $between_list_count[$term_name]['photo'] = 0;
      }
    }
    if ($photo_cont['total_records_today'] > 0) {
      $today_list_count[$term_name]['photo'] = $photo_cont['total_records_today'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['photo'] = 0;
      }
    }
    if ($photo_cont['total_records_yesterday'] > 0) {
      $yesterday_list_count[$term_name]['photo'] = $photo_cont['total_records_yesterday'];
    }
    else {
      if ($sum_yesteday > 0) {
        $yesterday_list_count[$term_name]['photo'] = 0;
      }
    }
  }
  $section_list_count['between'] = $between_list_count;
  $section_list_count['today'] = $today_list_count;
  $section_list_count['yesterday'] = $yesterday_list_count;
  return $section_list_count;
}

/**
 * function for get tid Video node count value
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram int $tid
 *
 * @return array $total_records
 */
function countVideo($start_date, $end_date, $tid) {
  //video count between $start_date & $end_date

  
  $total_records = array();

  //video count btween
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $start_date, '>=')->condition('n.created', $end_date, '<=')->condition('ti.tid', $tid)->condition('n.type', 'videogallery');
  $result = $query->execute()->fetchAll();
  $total_records_between = count($result);

  //video count today
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $today, '=')->condition('ti.tid', $tid)->condition('n.type', 'videogallery');
  $result = $query->execute()->fetchAll();
  $total_records_today = count($result);

  

  $total_records['total_records_between'] = $total_records_between;
  $total_records['total_records_today'] = $total_records_today;
  $total_records['total_records_yesterday'] = $total_records_yesterday;

  return $total_records;
}

/**
 * function for get tid Photo node count value
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram int $tid
 *
 * @return array $total_records
 */
function countPhoto($start_date, $end_date, $tid) {
  //video count between $start_date & $end_date

  $hour = 01;
  $today = strtotime($hour . ':00:00');
  $yesterday = strtotime('-1 day', $today);
  $dayBeforeYesterday = strtotime('-1 day', $yesterday);
  $total_records = array();

  //photo count between
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $start_date, '>=')->condition('n.created', $end_date, '<=')->condition('ti.tid', $tid)->condition('n.type', 'photogallery');
  $result = $query->execute()->fetchAll();
  $total_records_between = count($result);

  //photo count today
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $today, '=')->condition('ti.tid', $tid)->condition('n.type', 'photogallery');
  $result = $query->execute()->fetchAll();
  $total_records_today = count($result);

  //photo count yesterday
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $yesterday, '=')->condition('ti.tid', $tid)->condition('n.type', 'photogallery');
  $result = $query->execute()->fetchAll();
  $total_records_yesterday = count($result);

  $total_records['total_records_between'] = $total_records_between;
  $total_records['total_records_today'] = $total_records_today;
  $total_records['total_records_yesterday'] = $total_records_yesterday;

  return $total_records;
}

/**
 * function for get tid Story node count value
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram int $tid
 *
 * @return array $total_records
 */
function countStory($start_date, $end_date, $tid) {
  //video count between $start_date & $end_date

  $hour = 01;
  $today = strtotime($hour . ':00:00');
  $yesterday = strtotime('-1 day', $today);
  $dayBeforeYesterday = strtotime('-1 day', $yesterday);
  $total_records = array();

  //story count between
  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $start_date, '>=')->condition('n.created', $end_date, '<=')->condition('ti.tid', $tid)->condition('n.type', 'story');
  $result = $query->execute()->fetchAll();
  $total_records_between = count($result);

  //story count today
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $today, '=')->condition('ti.tid', $tid)->condition('n.type', 'story');
  $result = $query->execute()->fetchAll();
  $total_records_today = count($result);

  //story count yesterday
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $yesterday, '=')->condition('ti.tid', $tid)->condition('n.type', 'story');
  $result = $query->execute()->fetchAll();
  $total_records_yesterday = count($result);

  /* syndication node count start */


  //story count between
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_story_syndication', 'syn', 'syn.entity_id=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $start_date, '>=')->condition('n.created', $end_date, '<=')->condition('ti.tid', $tid)->condition('n.type', 'story')->condition('syn.field_story_syndication_value', 'yes');
  $result = $query->execute()->fetchAll();
  $syndication_records_between = count($result);

  //story count today
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_story_syndication', 'syn', 'syn.entity_id=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $today, '=')->condition('ti.tid', $tid)->condition('n.type', 'story')->condition('syn.field_story_syndication_value', 'yes');
  $result = $query->execute()->fetchAll();
  $syndication_records_today = count($result);

  //story count yesterday
  $query = "";
  $result = "";

  $query = db_select('node', 'n');
  $query->leftJoin('taxonomy_index', 'ti', 'ti.nid=n.nid');
  $query->leftJoin('field_data_field_story_syndication', 'syn', 'syn.entity_id=n.nid');
  $query->fields('n', array('nid'));
  $query->condition('n.created', $yesterday, '=')->condition('ti.tid', $tid)->condition('n.type', 'story')->condition('syn.field_story_syndication_value', 'yes');
  $result = $query->execute()->fetchAll();
  $syndication_records_yesterday = count($result);

  /* syndication node count end */


  // today count array merging

  $total_records['total_records_between_inhouse'] = $total_records_between - $syndication_records_between;
  $total_records['total_records_today_inhouse'] = $total_records_today - $syndication_records_today;
  $total_records['total_records_yesterday_inhouse'] = $total_records_yesterday - $syndication_records_today;

  $total_records['total_records_between_agency'] = $syndication_records_between;
  $total_records['total_records_today_agency'] = $syndication_records_today;
  $total_records['total_records_yesterday_agency'] = $syndication_records_today;

  return $total_records;
}

/**
 * function for get section list with node count Report array by today
 * @pram datetime $start_date
 * @pram datetime $end_date
 * @pram array $section_list
 *
 * @return array $section_list_count
 */
function nodeCountByToday_Report($start_date, $end_date, $section_list) {
  $section_list_count = array();
  $between_list_count = array();
  $today_list_count = array();
  $yesterday_list_count = array();
  $video_cont = array();
  $photo_cont = array();
  $story_cont = array();
  $loop_count = 0;
  // loop on section list
  foreach ($section_list as $key => $value) {

    $story_cont = countStory($start_date, $end_date, $value['tid']);
    $video_cont = countVideo($start_date, $end_date, $value['tid']);
    $photo_cont = countPhoto($start_date, $end_date, $value['tid']);   
    $sum_today = 0;  

    $sum_today += $story_cont['total_records_today'] + $story_cont['total_records_today_inhouse'] + $story_cont['total_records_today_agency'];
    $sum_today += $video_cont['total_records_today'] + $video_cont['total_records_today_inhouse'] + $video_cont['total_records_today_agency'];
    $sum_today += $photo_cont['total_records_today'] + $photo_cont['total_records_today_inhouse'] + $photo_cont['total_records_today_agency'];    

    $term_name = $value['name'];
    $term_tid = $value['tid'];


    //Inhouce count merging

    if ($story_cont['total_records_today_inhouse'] > 0) {
      $today_list_count[$term_name]['inhouse'] = $story_cont['total_records_today_inhouse'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['inhouse'] = 0;
      }
    }
 

    //Agency count merging
    if ($story_cont['total_records_today_agency'] > 0) {
      $today_list_count[$term_name]['agency'] = $story_cont['total_records_today_agency'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['agency'] = 0;
      }
    }

    //video count merging

    if ($video_cont['total_records_today'] > 0) {
      $today_list_count[$term_name]['video'] = $video_cont['total_records_today'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['video'] = 0;
      }
    }


    //photo count merging

    if ($photo_cont['total_records_today'] > 0) {
      $today_list_count[$term_name]['photo'] = $photo_cont['total_records_today'];
    }
    else {
      if ($sum_today > 0) {
        $today_list_count[$term_name]['photo'] = 0;
      }
    }

  } 
  $section_list_count['today'] = $today_list_count;  
  return $section_list_count;
}