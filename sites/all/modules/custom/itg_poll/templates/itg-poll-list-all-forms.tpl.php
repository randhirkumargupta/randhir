<?php
/**
 * @file
 * Theme implementation for poll form for poll landing page
 */
global $user;
global $base_url;
$nid = $data['list']->nid;

$related_stories = '';
$related_stories_class = ' no-related-content';
$no_image_class = '';

// Related node

if (isset($data['related_nodes']) && !empty($data['related_nodes'])) {
  $related_stories = '<div class="related-story relative-active"><span>' . t('RELATED STORY') . '</span><ul class="related-stories">';

  foreach ($data['related_nodes'] as $related_stories_data) {
    $related_stories .= '<li>' . $related_stories_data . '</li>';
  }
  $related_stories .= '</ul></div>';
  $related_stories_class = ' relative-with-img';
}

if (isset($data['poll_image_exist_class']) && !empty($data['poll_image_exist_class'])) {
  $poll_image_exist_class = $data['poll_image_exist_class'];
}




// Banner Image

if (isset($data['poll_banner_image']) && !empty($data['poll_banner_image'])) {
  $poll_banner_image = '<div class="poll-banner-image">' . $data['poll_banner_image'] . '</div>';
}
else {
  $poll_banner_image = '';
  $no_image_class = ' no-poll-image';
}

// Title

$updated = $data['updated'];
$title = '<div class="active-poll-title"><h2>'.t($data['title']).'</h2><div class="updated-msg">'.$updated.' <div class="social-share"><ul><li><a class="share" href="javascript:void(0)"><i class="fa fa-share-alt"></i></a></li><li><a href="#" class="facebook"><i class="fa fa-facebook"></i></a></li><li><a href="#" class="twitter"><i class="fa fa-twitter"></i></a></li><li><a href="#" class="google"></a></li></ul></div></div></div>';

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

print '<div class="poll-wrapper"><h3><span>CURRENT POLL</span></h3>';
//print '<div class="poll-wrapper-pre-navigator">' . $pre . '</div>';

$isCookies = itg_poll_isCookies($nid);
$poll_uid = itg_poll_getcurrent_userpoll($nid, $user->uid);
if (($isCookies != 'yes' && user_is_anonymous()) || (user_is_logged_in() && $poll_uid != $user->uid)) {
  if (isset($nid) && !empty($nid)) {
    print '<div class="poll-data"><div class="'.$related_stories_class. $no_image_class.'">' . $poll_banner_image.$title. '<div class="poll-replace-id '.$poll_image_exist_class.'">' . drupal_render(drupal_get_form('itg_poll_form_new', $nid)) . '</div></div>' . $related_stories.'</div>';
  }
}
else {
  print  '<div class="poll-data"><div class="poll-data'.$related_stories_class. $no_image_class.'">' . $poll_banner_image.$title . '<div class="poll-replace-id '.$poll_image_exist_class.'">' . itg_poll_get_past_data($nid) . '</div></div>' . $related_stories.'</div>';
}

//print '<div class="poll-wrapper-next-navigator">' . $next . '</div>';
print '</div>';

// Printing past polls
?>

<div class="poll-navigation">
    <ul>
       <?php  for($pc=0;$pc<$poll_count;$pc++){ ?> 
        <li><a class="<?php if(isset($_GET['poll_index']) && $_GET['poll_index']!='' && $_GET['poll_index']==$pc) print 'active';  ?>" href="<?php echo $base_url.'/itg_active_polls?poll_index='.$pc ?>"></a></li>
       <?php }  ?>
    
    
    </ul>
</div>

<div class="past-polls">
    <div class="past-poll-label"><h3><span>Past Poll</span></h3></div>
  <?php print views_embed_view('past_polls', 'block'); ?>
</div>