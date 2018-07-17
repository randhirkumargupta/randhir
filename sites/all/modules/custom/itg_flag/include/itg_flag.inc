<?php
/**
 * Implement itg_user_activity_front_highlight().
 */
function itg_user_activity_front_highlight() {
  
  $nd_id = $_POST['nd_id'];
  $emoji_id = explode('-', $nd_id);
  $dtag = $_POST['dtag'];
  $dstatus = $_POST['dstatus'];
  $user_activity = $_POST['data_activity'];
  $activity_date = date('d-m-Y');
  $activity_date_time = date('d-m-Y h:i:s');
  
  
  if (isset($_COOKIE['hightlights_emoji' . "_" . $nd_id])) {
    $response = array('ok' => 'error', 'nd_id' => $emoji_id[0]);
    print json_encode($response);
  }
  else {
    if (function_exists('mongodb')) {
      $con = mongodb();
      if ($con) {
        $people = $con->front_user_activity_highlight;
        if (!empty($nd_id)) {
          $emoji_count = itg_common_mongo_activity_count($nd_id, 'front_user_activity_highlight');
          if (!empty($emoji_count)) {
            $pre_count = $emoji_count + 1;
          }
          else {
            $pre_count = 1;
          }
          $qry = array("nid" => $nd_id, "uid" => $user->uid, "ntype" => $dtag, "activity" => $user_activity, "activity_date" => $activity_date, "activity_date_time" => $activity_date_time, "status" => $dstatus);
          $result = $people->insert($qry);
          $expire = time() + 86400;
          setcookie("hightlights_emoji" . "_" . $nd_id, $expire);
          $response = array('ok' => 'hightlights_emoji_true', 'nd_id' => $emoji_id[0], 'count' => $pre_count, 'rel' => $nd_id);
          print json_encode($response);
        }
      }
    }
  }
}
