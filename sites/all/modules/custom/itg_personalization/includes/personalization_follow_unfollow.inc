<?php
/**
 * @file : personalization_follow_unfollow.inc
 */
?>
<?php
/**
 *
 */
function itg_personalization_remove_activity() {
  itg_personalization_send_follow_mail();
}
function itg_personalization_remove_activity_old() {
  global $user;
  $nid = $_POST['nd_id'];
  if (function_exists('mongodb')) {
    $con = mongodb();
    // check connection
    if ($con && !empty($nid)) {
        $people = $con->front_user_activity;
        $people->remove(array("nid" => $nid, "uid" => $user->uid));
        $response = array('success' => 'true');
        print json_encode($response);
    } //close connection

    
  }
}


