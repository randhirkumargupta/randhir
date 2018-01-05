<?php

/**
 * Inc file contains the functions for story_Count_report API
 */

/**
 * main function for generate user list array
 * @pram string $user_type
 * @pram string $user_sub_type
 * @pram int $item_per_page
 * @pram int $pageno
 *
 * @return array userList
 */
function getUserList_Report($user_type, $user_sub_type) {
  global $base_url;
  $list = array();
  $data = array();
  $total_cont = 0;
p($_GET);
  $query = db_select('node', 'n');
  $query->leftJoin('users', 'u', 'u.uid=n.uid');
  $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
  $query->fields('u', array('uid', 'name', 'mail', 'status'));
  
  //filter of content type
  $query->condition('ur.rid', 25, '!=');
  if ($user_type != "na" || $user_type != "") {
    if($user_type == "author"){
        $query->condition('ur.rid', 4, '=');
    }    
  }


  $query->orderBy('u.name', 'DESC');
  $query->groupBy('n.uid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $uid = $resvalue['uid'];
    $name = $resvalue['name'];
    $mail = $resvalue['mail'];
    $status = $resvalue['status'];
    // list data
    $list[$total_cont]['user_id'] = "$uid";
    $list[$total_cont]['name'] = "$name";
    $list[$total_cont]['email'] = "$mail";
    $list[$total_cont]['status'] = "$status";

    $total_cont++;
  }

  $data['results'] = $list;
  $data['total_records'] = "$total_cont";
  return $data;
}

function getUserList_Report_bk($user_type, $user_sub_type, $item_per_page, $pageno) {
  global $base_url;
  $list = array();
  $data = array();
  $total_cont = 1;
  $range_max = $item_per_page;
  //$photolist = array();
  if (!$pageno == 0) {
    $range_min = $pageno * $range_max;
  }
  else {
    $range_min = 0;
  }
  $query = db_select('users', 'u');
  $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
  $query->fields('u', array('uid', 'name', 'mail', 'status'));
  //    if ($user_type != "na") {
  //        $query->condition('n.type', $type);
  //    }
  //    if ($user_sub_type != "na") {
  //        $query->condition('n.type', $type);
  //    }
  //$query->condition('ur.rid', 1, '<>')->condition('ur.rid', 25, '<>')->orderBy('u.name', 'DESC')->groupBy('u.uid')->range($range_min, $range_max);
  $query->condition('ur.rid', 1, '<>')->condition('ur.rid', 25, '<>')->orderBy('u.name', 'DESC')->groupBy('u.uid');
  $result = $query->execute()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $reskey => $resvalue) {
    $uid = $resvalue['uid'];
    $name = $resvalue['name'];
    $mail = $resvalue['mail'];
    $status = $resvalue['status'];
    // list data
    $list[$total_cont]['user_id'] = "$uid";
    $list[$total_cont]['name'] = "$name";
    $list[$total_cont]['email'] = "$mail";
    $list[$total_cont]['status'] = "$status";

    $total_cont++;
  }
  $total_records = totalUser_Report($user_type, $user_sub_type, $item_per_page, $pageno);
  $data['results'] = $list;
  $data['total_records'] = "$total_records";
  return $data;
}

/**
 * main function for get total user records
 * @pram string $user_type
 * @pram string $user_sub_type
 * @pram int $item_per_page
 * @pram int $pageno
 *
 * @return int  $total_records
 */
function totalUser_Report($user_type, $user_sub_type, $item_per_page, $pageno) {
  $query = db_select('users', 'u');
  $query->leftJoin('users_roles', 'ur', 'ur.uid=u.uid');
  $query->fields('u', array('uid'));
  //    if ($user_type != "na") {
  //        $query->condition('n.type', $type);
  //    }
  //    if ($user_sub_type != "na") {
  //        $query->condition('n.type', $type);
  //    }
  $query->condition('ur.rid', 1, '<>')->condition('ur.rid', 25, '<>');
  $result = $query->execute()->fetchAll();
  $total_records = count($result);
  return $total_records;
}

