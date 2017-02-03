<?php

/*
 * Inc file contains the mongo helper functions
 */

/**
 * Helper function to get previous insert record.
 * @param int $nid
 * @param string $ntype
 * @param int $uid
 * @param string $activity
 * @param string $status
 */
function itg_get_front_activity_info($nid, $ntype, $uid, $activity, $status) {
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->front_user_activity;
    if (!empty($status)) {
      $cond = array('nid' => $nid, 'ntype' => $ntype, 'uid' => $uid, 'activity' => $activity, 'status' => $status);
    }
    else {
      $cond = array('nid' => $nid, 'ntype' => $ntype, 'uid' => $uid, 'activity' => $activity);
    }
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $data['nid'] = $document['nid'];
      $data['status'] = $document['status'];
    }
    return $data;
  }
}

/**
 * Helper function to populate the second dropdown.
 * @param string $id
 * @return array $data
 */
function itg_common_tv_time($id = '') {
  $data = '';
  $final_id = date('Y/m/d', strtotime($id));
  if (function_exists('mongodb')) {
    $db = mongodb();
    $people = $db->tv_schedule;
    $date = $final_id;
    $cond = array('program date' => $date);
    $cursor = $people->find($cond);
    // Fetch query for supplements
    $select = t('- None -');
    $data = array('_none' => $select);
    foreach ($cursor as $document) {
      $data[$document['time']] = $document['time'];
    }
    return $data;
  }
}

/**
 * Implements itg_get_follow_story_user
 * @param int $nid
 * @param int $status
 */
function itg_get_follow_story_user($nid, $status) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->front_user_activity;
    $cond = array('nid' => $nid, 'status' => $status);
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $options[] = $document['uid'];
    }
    return $options;
  }
}

/**
 * Get count value by passing nid.
 * @param int $nid
 * @param string $type
 */
function itg_flag_get_count($nid, $type) {
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itg_custom_flag_count;
    $cond = array('nid' => $nid);
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $data[$type] = $document[$type];
    }
    return $data;
  }
}

/**
 * insert value of flag count in db.
 * @param int $nid
 * @param string $type
 * @param string $val
 */
function itg_flag_insert_count($nid, $type, $val) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->itg_custom_flag_count;
      $qry = array("nid" => $nid, $type => $val, "created" => date('Y-m-d G:i:s'));
      $result = $people->insert($qry);
      $expire = time() + 60 * 60 * 24 * 30;
      setcookie("likeDislike" . "_" . $nid, "likeDislike" . "_" . $nid, $expire);
    }
  }
}

/**
 * Implement itg_flag_upd_count
 * @param int $nid
 * @param string $type
 * @param string $val
 */
function itg_flag_upd_count($nid, $type, $val) {
  if (function_exists('mongodb')) {
    $con = mongodb();
    if ($con) {
      $people = $con->itg_custom_flag_count;
      $newdata = array('$set' => array($type => $val, "created" => date('Y-m-d G:i:s')));
      $people->update(array("nid" => $nid), $newdata);
      $expire = time() + 60 * 60 * 24 * 30;
      setcookie("likeDislike" . "_" . $nid, "likeDislike" . "_" . $nid, $expire);
    }
  }
}

/**
 * Get nid value by passing id.
 * @param int $nid
 * @param string $type
 */
function itg_flag_get_nid($nid) {
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->itg_custom_flag_count;
    $cond = array('nid' => $nid);
    $cursor = $people->find($cond);
    foreach ($cursor as $document) {
      $data['nid'] = $document['nid'];
    }
    return $data;
  }
}


/**
 * Get count value by passing nid.
 * @param int $nid
 * @param string $collection
 */
function itg_common_mongo_activity_count($nid, $collection) {
  if (function_exists('mongodb') && !empty($nid)) {
    $con = mongodb();
    $people = $con->$collection;
    $cond = array('nid' => $nid);
    $cursor = $people->count($cond);
    return $cursor;
  } else {
    return 0;
  }
  
}