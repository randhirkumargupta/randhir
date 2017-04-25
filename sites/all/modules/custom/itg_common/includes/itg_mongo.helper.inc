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
    //$select = t('- None -');
    //$data = array('_none' => $select);
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
      $qry = array("nid" => $nid, $type => $val, "created" => date('Y-m-d G:i:s') , "timestamp" => time());
      $result = $people->insert($qry);
      $expire = time() + 86400;
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
      $newdata = array('$set' => array($type => $val, "created" => date('Y-m-d G:i:s') , "timestamp" => time()));
      $people->update(array("nid" => $nid), $newdata);
      $expire = time() + 86400;
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

/**
 * Implements itg_common_mongo_activity_user_count().
 * @param int $uid
 * @param string $collection
 * @param string $event
 * @param int $status
 */
function itg_common_mongo_activity_user_count($uid, $collection, $event = NULL, $status = NULL) {
  if (function_exists('mongodb') && !empty($uid)) {
    $con = mongodb();
    $people = $con->$collection;
    if(empty($event) && empty($status)) {
    $cond = array('uid' => $uid);
    } else {
    $cond = array('uid' => $uid, 'activity' => $event, 'status' => $status);
    }
    $cursor = $people->count($cond);
    return $cursor;
  } else {
    return 0;
  }
  
}

/**
 * Implements itg_common_mongo_activity_user_count_date_wise().
 * @param int $uid
 * @param string $collection
 * @param string $event
 * @param int $status
 */
function itg_common_mongo_activity_user_count_date_wise($uid, $collection, $event = NULL, $status = NULL) {
  if (function_exists('mongodb') && !empty($uid)) {
    if(!empty(variable_get('read_later_days_config'))) {
      $expiry_days = '-'.variable_get('read_later_days_config').' days';
    } else {
      $expiry_days = '-30 days';
    }
    $start_date = strtotime(date('d-m-Y', strtotime($expiry_days)));
    $con = mongodb();
    $people = $con->$collection;
    if(empty($event) && empty($status)) {
    $cond = array('uid' => $uid, 'timestamp' => array('$gte' => $start_date));
    } else {
    $cond = array('uid' => $uid, 'activity' => $event, 'status' => $status, 'timestamp' => array('$gte' => $start_date));
    }
    $cursor = $people->count($cond);
    return $cursor;
  } else {
    return 0;
  }
  
}

/**
 * Implements itg_mongo_delete_ugc_content().
 * @param string $id
 * @param string $collection
 */
function itg_mongo_delete_ugc_content($id, $collection) {
  if (function_exists('mongodb') && !empty($id))
  {
    $del_id = new MongoId($id);
    if(function_exists('itg_ugc_content_details')) {
      $title = itg_ugc_content_details($del_id);
    }
    $con = mongodb();
    $people = $con->$collection;
    $people->remove(array("_id" => $del_id));
    $options = array('query' => array('status' => 'review'));
    drupal_set_message(ucwords($title['title']).t(' Has been deleted sucessfully'));
    drupal_goto('personalization/my-content',$options);
  }
}

/**
 * Helper function to get follow tag.
 * @param int $uid
 */
function itg_personalization_get_followed_tag($uid) {
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->following_personalization;
    $cond = array('uid' => $uid);
    $cursor = $people->find($cond);
    foreach ($cursor as $key => $document) {
      $data[]['tid'] = $document['tid'];
    }
    return $data;
  }
}

/**
 * Helper function to get follow tag status.
 * @param int $uid
 */
function itg_personalization_get_followed_status($tid) {
  $data = '';
  if (function_exists('mongodb')) {
    $con = mongodb();
    $people = $con->following_personalization;
    $cond = array('tid' => $tid);
    $cursor = $people->count($cond);
    return $cursor;
  }
}