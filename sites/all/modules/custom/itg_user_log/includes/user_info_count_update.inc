<?php

/**
 * 
 * @param type $user_info
 * 
 * 
 * Function to insert into user details collection in mongo db on user login.
 */
function user_data_insert_in_mongodb($user_info) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->usersdetails;
      if (isset($user_info->field_mobile_number['und'][0]['value']) && !empty($user_info->field_mobile_number['und'][0]['value'])) {
        $mobile_no = $user_info->field_mobile_number['und'][0]['value'];
      }
      else {
        $mobile_no = '';
      }

      $created = new MongoDate($user_info->created);
      $access = new MongoDate($user_info->access);
      $qry = array("uuid" => $user_info->uid , "name" => $user_info->name , "email" => $user_info->mail , "mobile" => $mobile_no , "created_date" => $created , "last_access" => $access , "roles" => $user_info->roles , "status" => $user_info->status);

      // find user exist or not
      $users = $people->find(array("uuid" => $user_info->uid))->limit(1);
      $user_exist = FALSE;

      foreach ($users as $user) {
        if (is_array($user) && !empty($user['uuid'])) {
          $user_exist = TRUE;
          break;
        }
      }

      // if not then insert into mongo userdeatils collection
      if (!$user_exist) {
        $people->insert($qry);
      }
      // entry in userlog collection
      itg_user_log_activities_to_mongodb($user_info->uid);
    }
  }
}

/**
 * 
 * Function to insert data into userlog collection .
 */
function itg_user_log_activities_to_mongodb($uid) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->userslog;
      $qry = array("uuid" => $uid , "login_time" => time());
      $people->insert($qry);
    }
  }
}

/**
 * Implements function for active user listing
 */
function itg_logged_in_user_active_user() {
  # configure the table header columns
  $header = array(
    array('data' => t('Name')) ,
    array('data' => t('E-mail')) ,
    array('data' => t('Mobile Number')) ,
    array('data' => t('Created Date')) ,
    array('data' => t('Last Access')) ,
    array('data' => t('Count')) ,
    array('data' => t('Status')) ,
  );
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->usersdetails;
      $query = array();
      $limit = 0;
      if (!empty($_GET['items_per_page'])) {
        $limit = $_GET['items_per_page'];
      }
      if (!empty($_GET['title'])) {
        $query['name'] = $_GET['title'];
      }
      if (!empty($_GET['email'])) {
        $query['email'] = $_GET['email'];
      }
      if (is_array($query) && empty($query)) {
        $userData = $people->find()->limit($limit);
      }
      else {
        $userData = $people->find($query)->limit($limit);
      }

      $first_start_date = FALSE;
      $first_end_date = FALSE;

      if (isset($_GET['From']) && !empty($_GET['From'])) {
        $first_start_date = $_GET['From'];
      }
      if (isset($_GET['To']) && !empty($_GET['To'])) {
        $first_end_date = $_GET['To'];
      }
      $rows = array();
      foreach ($userData as $row) {
        if ($first_start_date && $first_end_date) {
          $count = itg_user_log_get_count($row['uuid'] , null , new MongoDate(strtotime($first_start_date . " 00:00:00")) , new MongoDate(strtotime($first_start_date . " 23:59:59")));
        }
        elseif ($first_start_date && !$first_end_date) {
          $count = itg_user_log_get_count($row['uuid'] , null , new MongoDate(strtotime($first_start_date . " 00:00:00")));
        }
        elseif (!$first_start_date && $first_end_date) {
          $count = itg_user_log_get_count($row['uuid'] , null , null , new MongoDate(strtotime($first_end_date . " 23:59:59")));
        }
        else {
          $count = itg_user_log_get_count($row['uuid'] , $row['created_date']->sec);
        }
        $status = ($row['status']) ? t('Active') : t('Inactive');
        //get the value in table
        $rows[] = array(
          array('data' => $row['name']) ,
          array('data' => $row['email']) ,
          array('data' => $row['mobile']) ,
          array('data' => $row['created_date']->sec ? date('d-m-Y' , $row['created_date']->sec) : '') ,
          array('data' => $row['last_access']->sec ? date('d-m-Y' , $row['last_access']->sec) : '') ,
          array('data' => $count) ,
          array('data' => $status) ,
        );
      }
    }
  }
  //get the header in table
  $output = render(drupal_get_form('itg_user_log_api_form'));
  $output .= theme('table' , array('header' => $header , 'rows' => $rows , 'attributes' => array('class' => array('views-table')) , 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}

function aasort(&$array , $key) {
  $sorter = array();
  $ret = array();
  reset($array);
  foreach ($array as $ii => $va) {
    $sorter[$ii] = $va[$key];
  }
  asort($sorter);
  foreach ($sorter as $ii => $va) {
    $ret[$ii] = $array[$ii];
  }
  $array = $ret;
}

/**
 * Implements function for visited user listing
 */
function itg_logged_in_user_visited_node() {
  drupal_add_css('#ui-datepicker-div {display:none}' , 'inline');
  $final_array = array();
  //Add pagination class.
  module_load_include('php' , 'itg_reports' , 'includes/pagination');
  $output = render(drupal_get_form('itg_user_content_visit_report_form'));

  $header = array(
    array('data' => t('S. No')) ,
    array('data' => t('Title ')) ,
    array('data' => t('Node Id')) ,
    //array('data' => t('URL')) ,
    array('data' => t('Type')) ,
    array('data' => t('No Of Users Visited')) ,
  );
  if (function_exists('mongodb')) {
    $connection = mongodb();
    if ($connection) {

      $content_visits = $connection->pagedetails;
      $condition = array();

      $condition['roles'] = 'Front User';

      if (!empty($_GET['items_per_page'])) {
        $limit = $_GET['items_per_page'];
      }
      if (!empty($_GET['username'])) {
        $condition['name'] = $_GET['username'];
      }
      if (!empty($_GET['content_type'])) {
        $condition['type'] = $_GET['content_type'];
      }
      if (!empty($_GET['email'])) {
        $condition['email'] = $_GET['email'];
      }
      if (!empty($_GET['min_date']) && !empty($_GET['max_date'])) {
        $condition['viewtime'] = array(
          '$gte' => strtotime('-1 day' , $_GET['min_date']) ,
          '$lte' => strtotime('+1 day' , $_GET['max_date']) ,
        );
      }
      $user_data = $content_visits->find($condition)->sort(array('nid' => 1));
      foreach ($user_data as $info) {
        if (get_front_page_nid() != $info['nid']) {
          array_unshift($array_data[$info['url']] , "");
          unset($array_data[$info['url']][0]);
          $array_data[$info['nid']][] = count($array_data[$info['nid']]);
          $tmp_array = array();
          $tmp_array['url'] = $info['url'];
          $tmp_array['nid'] = $info['nid'];
          $tmp_array['title'] = $info['title'];
          $tmp_array['name'] = $info['type'];
          $tmp_array['count'] = end($array_data[$info['nid']]) + 1;
          $final_array[$info['nid']] = $tmp_array;
          unset($tmp_array);
        }
      }
      # get a list of sort columns and their data to pass to array_multisort
      $sorted_array = array();
      foreach ($final_array as $k => $v) {
        $sorted_array['nid'][$k] = $v['nid'];
        $sorted_array['count'][$k] = $v['count'];
      }
      array_multisort($sorted_array['count'] , SORT_DESC , $sorted_array['nid'] , SORT_DESC , $final_array);
    }
  }
  // Sort final array as count descending mode.
  //$final_array = itg_array_sort($final_array , 'count' , SORT_DESC);
  $pagination = new pagination;
  if (empty($_GET['items_per_page'])) {
    $final_array = array_slice($final_array , 0 , 50);
  }
  // If we have an array with items
  if (count($final_array)) {
    // Parse through the pagination class
    $item_per_page = isset($_GET['item_per_page']) ? $_GET['item_per_page'] : 20;
    $user_details_pages = $pagination->generate($final_array , $item_per_page);
    // Load users report data.
    // If we have items 
    if (count($user_details_pages) != 0) {
      // Get pagination.
      $pageNumbers = $pagination->links();
      $cou = 1;
      foreach ($user_details_pages as $row) {
        $rows[] = array(
          array('data' => $cou) ,
          array('data' => l($row['title'] , 'node/' . $row['nid'] , array("attributes" => array("target" => '_blank')))) ,
          array('data' => $row['nid']) ,
          //array('data' => $row['url']) ,
          array('data' => $row['name']) ,
          array('data' => $row['count']) ,
        );
        $cou++;
      }

      //get the header in table
      //$output = render(drupal_get_form('itg_user_log_api_form'));
      $output .= theme('table' , array(
        'header' => $header , 'rows' => $rows ,
        'attributes' => array('class' => array('views-table')) ,
        'empty' => t('No results found')));
      $output .= theme('pager');
      $output .= '<ul class="custom-pagger">' . $pageNumbers . '</ul>';
      return $output;
    }
  }
  else {
    $rows = array();
    $output .= theme('table' , array(
      'header' => $header , 'rows' => $rows ,
      'attributes' => array('class' => array('views-table')) ,
      'empty' => t('No results found')));
    return $output;
  }
}

function itg_array_sort($array , $on , $order = SORT_ASC) {
  $new_array = array();
  $sortable_array = array();

  if (count($array) > 0) {
    foreach ($array as $k => $v) {
      if (is_array($v)) {
        foreach ($v as $k2 => $v2) {
          if ($k2 == $on) {
            $sortable_array[$k] = $v2;
          }
        }
      }
      else {
        $sortable_array[$k] = $v;
      }
    }

    switch ($order) {
      case SORT_ASC:
        asort($sortable_array);
        break;
      case SORT_DESC:
        arsort($sortable_array);
        break;
    }

    foreach ($sortable_array as $k => $v) {
      $new_array[$k] = $array[$k];
    }
  }

  return $new_array;
}

/**
 * Function which is responsible to insert mongo data.
 * 
 * @global array $user
 * @param array $node
 */
function itg_logged_in_user_node_insert_data($node) {
  global $user;
  $user_roles = $user->roles;
  if (in_array('Front User' , $user_roles)) {
    $user_roles = 'Front User';
  }
  else {
    $user_roles = json_encode($user_roles);
  }
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $section_tids = taxonomy_get_parents_all($node->field_primary_category[LANGUAGE_NONE][0]['value']);
      $section_tids = array_reverse($section_tids);
      $people = $con->pagedetails;
      $qry = array(
        "nid" => $node->nid ,
        "title" => $node->title ,
        "url" => url(drupal_get_path_alias('node/' . $node->nid) , array('absolute' => TRUE)) ,
        "uid" => ($user->uid) ? $user->uid : 0 ,
        "email" => ($user->mail) ? $user->mail : "" ,
        "section" => $section_tids[0]->tid ,
        "name" => ($user->name) ? $user->name : "" ,
        "type" => $node->type ,
        "roles" => $user_roles ,
        "viewtime" => REQUEST_TIME
      );
      $people->insert($qry);
    }
  }
}

/**
 * 
 * @return type
 */
//function itg_logged_in_user_section_breakup() {
//  //print_r($node);
//  # configure the table header columns
//  $header = array(
//    array('data' => t('Title')) ,
//    array('data' => t('Current Week')) ,
//    array('data' => t('Last Week')) ,
//    array('data' => t('Percentage ')) ,
//  );
//  if (function_exists('mongodb')) {
//    $con = mongodb();
//    if ($con) {
//      $people = $con->pagedetails;
//      $query = array();
//      $limit = 0;
//      if (!empty($_GET['items_per_page'])) {
//        $limit = $_GET['items_per_page'];
//      }
//      if (!empty($_GET['title'])) {
//        $query['name'] = $_GET['title'];
//      }
//
//      $first_start_date = FALSE;
//      $first_end_date = FALSE;
//
//      if (isset($_GET['From']) && !empty($_GET['From'])) {
//        $first_start_date = $_GET['From'];
//      }
//      if (isset($_GET['To']) && !empty($_GET['To'])) {
//        $first_end_date = $_GET['To'];
//      }
//      if (isset($_GET['lwfrom']) && !empty($_GET['lwfrom'])) {
//        $first_start_date = $_GET['lwfrom'];
//      }
//      if (isset($_GET['lwto']) && !empty($_GET['lwto'])) {
//        $first_end_date = $_GET['lwto'];
//      }
//
//      $rows = array();
//
//      if (is_array($query) && empty($query)) {
//        $userData = $people->find()->limit($limit);
//      }
//      else {
//        $userData = $people->find($query)->limit($limit);
//      }
//
//      $rows_temp = array();
//      $count = array();
//
//      if ($userData && count($_GET) > 1) {
//        foreach ($userData as $row) {
//
//          if (!isset($count[$row['nid']])) {
//
//            $count[$row['nid']] = 0;
//          }
//          $rows_temp[$row['nid']] = array(
//            'nid' => $row['nid'] ,
//            'title' => $row['title'] ,
//            'url' => $row['url'] ,
//            'count' => ++$count[$row['nid']] ,
//          );
//        }
//      }
//      //p($rows_temp);
//      foreach ($rows_temp as $row) {
//        $rows[] = array(
//          array('data' => $row['title']) ,
//          array('data' => $row['count']) ,
//          array('data' => $row['count']) ,
//        );
//      }
//    }
//  }
//  //get the header in table
//  //$output = render(drupal_get_form('itg_user_log_api_form'));
//  //p($rows);
//  $output .= theme('table' , array(
//    'header' => $header , 'rows' => $rows ,
//    'attributes' => array('class' => array('views-table')) ,
//    'empty' => t('No results found')));
//  $output = render(drupal_get_form('itg_user_log_api_form_section_breakup'));
//  $output .= theme('table' , array('header' => $header , 'rows' => $rows , 'attributes' => array('class' => array('views-table')) , 'empty' => t('No results found')));
//
//  # add the pager
//  $output .= theme('pager');
//  return $output;
//}
