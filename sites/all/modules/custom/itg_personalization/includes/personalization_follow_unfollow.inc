<?php
/**
 * @file : personalization_follow_unfollow.inc
 */
?>
<?php
/**
 * Remove own follow activity
 */
function itg_personalization_remove_activity() {
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


