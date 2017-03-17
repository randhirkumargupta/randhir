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
      $qry = array("uuid" => $user_info->uid, "name" => $user_info->name, "email" => $user_info->mail, "mobile" => $mobile_no, "created_date" => $created, "last_access" => $access, "roles" => $user_info->roles, "status" => $user_info->status);

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
      $qry = array("uuid" => $uid, "login_time" => time());
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
    array('data' => t('Name')),
    array('data' => t('E-mail')),
    array('data' => t('Mobile Number')),
    array('data' => t('Created Date')),
    array('data' => t('Last Access')),
    array('data' => t('Count')),
    array('data' => t('Status')),
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
          $count = itg_user_log_get_count($row['uuid'], null, new MongoDate(strtotime($first_start_date . " 00:00:00")), new MongoDate(strtotime($first_start_date . " 23:59:59")));
        }
        elseif ($first_start_date && !$first_end_date) {
          $count = itg_user_log_get_count($row['uuid'], null, new MongoDate(strtotime($first_start_date . " 00:00:00")));
        }
        elseif (!$first_start_date && $first_end_date) {
          $count = itg_user_log_get_count($row['uuid'], null, null, new MongoDate(strtotime($first_end_date . " 23:59:59")));
        }
        else {
          $count = itg_user_log_get_count($row['uuid'], $row['created_date']->sec);
        }
        $status = ($row['status']) ? t('Active') : t('Inactive');
        //get the value in table
        $rows[] = array(
          array('data' => $row['name']),
          array('data' => $row['email']),
          array('data' => $row['mobile']),
          array('data' => $row['created_date']->sec ? date('d-m-Y', $row['created_date']->sec) : ''),
          array('data' => $row['last_access']->sec ? date('d-m-Y', $row['last_access']->sec) : ''),
          array('data' => $count),
          array('data' => $status),
        );
      }
    }
  }
  //get the header in table
  $output = render(drupal_get_form('itg_user_log_api_form'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}

/**
 * Implements function for visited user listing
 */
function itg_logged_in_user_visited_node() {
  //print_r($node);
  # configure the table header columns
  $header = array(
    array('data' => t('S No')),
    array('data' => t('N ID')),
    array('data' => t('Title ')),
    array('data' => t('URL')),
    array('data' => t('No of Users Visited')),
  );
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->pagedetails;
      $query = array();
      $limit = 0;
      if (!empty($_GET['items_per_page'])) {
        $limit = $_GET['items_per_page'];
      }
      if (!empty($_GET['title'])) {
        $query['name'] = $_GET['title'];
      }
      if (!empty($_GET['url'])) {
        $query['email'] = $_GET['url'];
      }
      if (is_array($query) && empty($query)) {
        $userData = $people->find()->limit($limit);
      }
      else {
        $userData = $people->find($query)->limit($limit);
      }

      $rows_temp = array();
      $i = 1;
      $count = array();
      foreach ($userData as $row) {

        if (!isset($count[$row['nid']])) {

          $count[$row['nid']] = 0;
          $i++;
        }
        $rows_temp[$row['nid']] = array(
          'nid' => $row['nid'],
          'title' => $row['title'],
          'url' => $row['url'],
          'count' => ++$count[$row['nid']],
        );
      }
      $cou = 1;
      foreach ($rows_temp as $row) {
        $rows[] = array(
          array('data' => $cou),
          array('data' => $row['nid']),
          array('data' => $row['title']),
          array('data' => $row['url']),
          array('data' => $row['count']),
        );
        $cou++;
      }
    }
  }
  //get the header in table
  //$output = render(drupal_get_form('itg_user_log_api_form'));
  $output .= theme('table', array(
    'header' => $header, 'rows' => $rows,
    'attributes' => array('class' => array('views-table')),
    'empty' => t('No results found')));
  $output = render(drupal_get_form('itg_user_log_api_form_visited'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}

function itg_logged_in_user_node_insert_data($node) {
  global $user;
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->pagedetails;
      $qry = array(
        "nid" => $node->nid,
        "title" => $node->title,
        "url" => url(drupal_get_path_alias('node/' . $node->nid), array('absolute' => TRUE)),
        "uid" => ($user->uid) ? $user->uid : 0,
        "email" => ($user->mail) ? $user->mail : "",
        "name" => ($user->name) ? $user->name : "",
        "type" => $node->type,
        "viewtime" => REQUEST_TIME
        );
      $people->insert($qry);
    }
  }
}

function itg_logged_in_user_section_breakup() {
  //print_r($node);
  # configure the table header columns
  $header = array(
    array('data' => t('Title')),
    array('data' => t('Current Week')),
    array('data' => t('Last Week')),
    array('data' => t('Percentage ')),
  );
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->pagedetails;
      $query = array();
      $limit = 0;
      if (!empty($_GET['items_per_page'])) {
        $limit = $_GET['items_per_page'];
      }
      if (!empty($_GET['title'])) {
        $query['name'] = $_GET['title'];
      }

      $first_start_date = FALSE;
      $first_end_date = FALSE;

      if (isset($_GET['From']) && !empty($_GET['From'])) {
        $first_start_date = $_GET['From'];
      }
      if (isset($_GET['To']) && !empty($_GET['To'])) {
        $first_end_date = $_GET['To'];
      }
      if (isset($_GET['lwfrom']) && !empty($_GET['lwfrom'])) {
        $first_start_date = $_GET['lwfrom'];
      }
      if (isset($_GET['lwto']) && !empty($_GET['lwto'])) {
        $first_end_date = $_GET['lwto'];
      }

      $rows = array();
//      foreach ($userData as $row) {
//        if ($first_start_date && $first_end_date) {
//          $count = itg_user_log_api_form_section_breakup_count($row['uuid'], null, new MongoDate(strtotime($c_week_first_date . " 00:00:00")), new MongoDate(strtotime($c_week_first_date . " 23:59:59")));
//        }
//        elseif ($first_start_date && !$first_end_date) {
//          $count = itg_user_log_api_form_section_breakup_count($row['uuid'], null, new MongoDate(strtotime($c_week_first_date. " 00:00:00")));
//        }
//        elseif (!$first_start_date && $first_end_date) {
//          $count = itg_user_log_api_form_section_breakup_count($row['uuid'], null, null, new MongoDate(strtotime($c_week_first_date . " 23:59:59")));
//        }
//        else {
//          $count = itg_user_log_api_form_section_breakup_count($row['uuid'], $row['viewtime']->sec);
//        }
//      }
      if (is_array($query) && empty($query)) {
        $userData = $people->find()->limit($limit);
      }
      else {
        $userData = $people->find($query)->limit($limit);
      }

      $rows_temp = array();
      $count = array();

      if ($userData && count($_GET) > 1) {
        foreach ($userData as $row) {

          if (!isset($count[$row['nid']])) {

            $count[$row['nid']] = 0;
          }
          $rows_temp[$row['nid']] = array(
            'nid' => $row['nid'],
            'title' => $row['title'],
            'url' => $row['url'],
            'count' => ++$count[$row['nid']],
          );
        }
      }
      //p($rows_temp);
      foreach ($rows_temp as $row) {
        $rows[] = array(
          array('data' => $row['title']),
          array('data' => $row['count']),
          array('data' => $row['count']),
        );
      }
    }
  }
  //get the header in table
  //$output = render(drupal_get_form('itg_user_log_api_form'));
  //p($rows);
  $output .= theme('table', array(
    'header' => $header, 'rows' => $rows,
    'attributes' => array('class' => array('views-table')),
    'empty' => t('No results found')));
  $output = render(drupal_get_form('itg_user_log_api_form_section_breakup'));
  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('class' => array('views-table')), 'empty' => t('No results found')));

  # add the pager
  $output .= theme('pager');
  return $output;
}
