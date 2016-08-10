<?php

/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
//foreach($data as $poll_form){
//    print drupal_render($poll_form);
//}

global $user;
global $base_url;
$nid = $data['list']->nid;
$current_index = isset($_GET['poll_index']) && !empty($_GET['poll_index']) ? $_GET['poll_index'] : 0;
$poll_count = $data['count'];
$pre = '';
$next = '';
if ($current_index < $poll_count && $current_index != 0) {
    $pre = l('Previous', 'itg_active_polls', array('query' => array('poll_index' => $current_index - 1)));
}

if ($current_index < $poll_count && $current_index != $poll_count - 1) {
    $next = l('Next', 'itg_active_polls', array('query' => array('poll_index' => $current_index + 1)));
}

print '<div class="poll-wrapper">';
print '<div class="poll-wrapper-pre-navigator">' . $pre . '</div>';

$isCookies = itg_poll_isCookies($nid);
$poll_uid = itg_poll_getcurrent_userpoll($nid, $user->uid);
if (($isCookies != 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid != $user->uid)) {
    if (isset($nid) && !empty($nid)) {
        print '<div class="poll-replace-id">'.drupal_render(drupal_get_form('itg_poll_form_new', $nid)).'</div>';
    }
} else {
    print '<div class="poll-replace-id">'.itg_poll_get_past_data($nid).'</div>';
}

print '<div class="poll-wrapper-next-navigator">' . $next . '</div>';
print '</div>';
?>