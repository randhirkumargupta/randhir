<?php
/**
 * @file
 * Theme implementation for poll form for poll landing page
 */
global $user;
global $base_url;
$nid = $data['list']->nid;

$related_stories = '';

// Related node

if (isset($data['related_nodes']) && !empty($data['related_nodes'])) {
  $related_stories = '<div>' . t('RELATED STORY') . '</div><ul class="related-stories">';

  foreach ($data['related_nodes'] as $related_stories_data) {
    $related_stories .= '<li>' . $related_stories_data . '</li>';
  }
  $related_stories .= '</ul>';
}

// Banner Image

if (isset($data['poll_banner_image']) && !empty($data['poll_banner_image'])) {
  $poll_banner_image = '<div class="poll-banner-image">' . $data['poll_banner_image'] . '</div>';
}
else {
  $poll_banner_image = '';
}

// Getting current index

$current_index = isset($_GET['poll_index']) && !empty($_GET['poll_index']) ? $_GET['poll_index'] : 0;
$poll_count = $data['count'];
$pre = '';
$next = '';
if ($current_index < $poll_count && $current_index != 0) {
  $pre = l(t('Previous'), 'itg_active_polls', array('query' => array('poll_index' => $current_index - 1)));
}

if ($current_index < $poll_count && $current_index != $poll_count - 1) {
  $next = l(t('Next'), 'itg_active_polls', array('query' => array('poll_index' => $current_index + 1)));
}

print '<div class="poll-wrapper">';
print '<div class="poll-wrapper-pre-navigator">' . $pre . '</div>';

$isCookies = itg_poll_isCookies($nid);
$poll_uid = itg_poll_getcurrent_userpoll($nid, $user->uid);
if (($isCookies != 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid != $user->uid)) {
  if (isset($nid) && !empty($nid)) {
    print $poll_banner_image . '<div class="poll-replace-id">' . drupal_render(drupal_get_form('itg_poll_form_new', $nid)) . '</div>' . $related_stories;
  }
}
else {
  print $poll_banner_image . '<div class="poll-replace-id">' . itg_poll_get_past_data($nid) . '</div>' . $related_stories;
}

print '<div class="poll-wrapper-next-navigator">' . $next . '</div>';
print '</div>';

// Printing past polls
?>
<div class="past-polls">
  <?php print views_embed_view('past_polls', 'block'); ?>
</div>