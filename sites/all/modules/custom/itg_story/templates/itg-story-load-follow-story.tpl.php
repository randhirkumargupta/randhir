<?php
global $user;
global $base_url;
$node = $data['node'];
$content = node_view($node, 'full');
// get related content associated with story
$related_content = $content['related_content'];
// condition for buzz
$actual_link = SITE_PROTOCOL . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
//$uri = base64_encode($actual_link);
$uri = base64_encode($_SERVER['HTTP_REFERER']);
$short_url = $_SERVER['HTTP_REFERER']; //shorten_url($_SERVER['HTTP_REFERER'], 'goo.gl');
$fb_title = addslashes($node->title);
$share_desc = '';
$image = '';
$nid = $node->nid;
if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
}

// get total share count
$tot_count = $content['total_share_count'];

// get global comment config   
if (function_exists('itg_story_global_comment_last_record')) {
  $global_comment_last_record = itg_story_global_comment_last_record();
  $config_name = trim($global_comment_last_record[0]->config_name);
}
// get comment count

$get_comment_count = $content['comment_count'];

//get follow story status

$follow_status = $content["follow_status"];

// get posted by info
$node_author = $content["author"];
?>
<ul>
  <!--<?php if ($user->uid > 0): ?>-->
    <!-- <li class="mhide"><a title = "Submit Your Story" class="def-cur-pointer" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i><span><?php print t('Submit Your Story'); ?></span></a></li>
    <li class="mhide"><a title = "Submit Your Story" class="def-cur-pointer story-login-follow" href="javascript:"><i class="fa fa-share"></i><span><?php print t('Submit Your Story'); ?></span></a></li>
  <?php else: ?>
    <li class="mhide"><a title = "Submit Your Story" class="def-cur-pointer akamai-story-submit-holder" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=470&iframe=true&type=<?php print $node->type; ?>"><i class="fa fa-share"></i><span><?php print t('Submit Your Story'); ?></span></a></li>
  <?php endif; ?>-->
  <li class="mhide"><div id="fb-root"></div><a title = "share on facebook" class="def-cur-pointer" onclick='fbpop("<?php print $_SERVER["HTTP_REFERER"]; ?>", "<?php print urlencode($fb_title); ?>", "<?php print urlencode($share_desc); ?>", "<?php print $image; ?>", "<?php print $base_url; ?>", "<?php print $nid; ?>")'><i class="fa fa-facebook"></i></a></li>
  <li class="mhide"><a title = "share on twitter" class="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick='twitter_popup("<?php print urlencode($node->title); ?>", "<?php print urlencode($short_url); ?>")'><i class="fa fa-twitter"></i></a></li>
  <li class="mhide"><a title="share on google+" class="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="#" onclick='return googleplusbtn("<?php print $_SERVER['HTTP_REFERER']; ?>")'><i class="fa fa-google-plus"></i></a></li>
  <?php
  if ($config_name == 'vukkul') {
    ?>
    <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-comments');" title="comment"><i class="fa fa-comment"></i> <span><?php
          if (function_exists(itg_vukkul_comment_count)) {
            print itg_vukkul_comment_count('story_' . $node->nid);
          }
          ?></span></a></li>
  <?php } if ($config_name == 'other') { ?> 
    <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span><?php print $get_comment_count; ?></span></a></li>
  <?php } ?>
  <li class="mhide"><span class="share-count"><?php
      if (!empty($tot_count)) {
        print $tot_count;
      }
      else {
        print 0;
      }
      ?></span><?php print t('SHARES'); ?></li>
  <?php if (!empty($node_author['fname'])) { ?>
    <li class="mhide"><span class="posted-by"><?php print t('Posted by'); ?></span><span class="posted-name"><?php print $node_author['fname'] . ' ' . $node_author['lname']; ?></span></li>
  <?php } ?>   
  <?php if ($user->uid > 0): if (!empty($follow_status['nid']) && $follow_status['status'] == '1'): ?>  
      <li class="mhide follow-story"><a title = "Unfollow Story" href="javascript:" id="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="follow_story" data-status="0" class="def-cur-pointer">Unfollow Story</a></li>
    <?php else: ?>
      <li class="mhide follow-story"><a title = "Follow the Story" href="javascript:" id="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="follow_story" data-status="1" class="def-cur-pointer">Follow the Story</a></li>
    <?php
    endif;
  else:
    ?>
    <li class="mhide">
      <a title="follow story" href="<?php print PARENT_SSO; ?>/saml_login/other/<?php print $uri; ?>"><?php print t('follow story'); ?></a>
    </li>
  <?php endif; ?>

</ul>
