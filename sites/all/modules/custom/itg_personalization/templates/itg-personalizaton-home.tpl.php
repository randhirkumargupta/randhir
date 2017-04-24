<?php
global $user;
/* 
 * @file
 *   Template file for personalized content home page.
 */
// get ugc content count based on id
if (function_exists('itg_common_mongo_activity_user_count'))
{
  $submit_ugc_content = itg_common_mongo_activity_user_count($user->uid, 'ugc_details');
  $follow_ugc_content = itg_common_mongo_activity_user_count($user->uid, 'front_user_activity', 'follow_story', '1');
  $read_later_content = itg_common_mongo_activity_user_count_date_wise($user->uid, 'front_user_activity', 'read_later', '1');
  $comment_count = itg_common_mongo_activity_user_count($user->uid, 'itgcms_comment', 'comment', 1);
  $google_share_count = itg_common_mongo_activity_user_count($user->uid, 'front_user_activity', 'google_share', '1');
  $twitter_share_count = itg_common_mongo_activity_user_count($user->uid, 'front_user_activity', 'twitter_share', '1');
  $facebook_share_count = itg_user_fb_share_count($user->uid, 'Content Share');
  $tot_count = $google_share_count + $twitter_share_count + $facebook_share_count;
}
?>
<div class="personalized-wrapper">
  <div class="personalized-user-area">
    <div class="personalized-user">
      <div class="user-pic">
      <?php print $data['profile_pic']; ?>
      </div>
      <div class="user-name">
        <?php print $data['full_name']; ?>
      </div>      
    </div>  
    <div class="personalized-user-info">
      <span>
          <i class="fa fa-share" aria-hidden="true" title="Submit Story"></i>
        <dfn><?php print $submit_ugc_content; ?></dfn>
      </span>
      <span>
        <i class="fa fa-share-alt" aria-hidden="true" title="Share Content"></i>
        <dfn><?php print $tot_count; ?></dfn>
      </span>
      <span>
        <i class="fa fa-comment" aria-hidden="true" title="Comments"></i>
        <dfn><?php print $comment_count; ?></dfn>
      </span>
      <span>
        <i class="fa fa-bookmark" aria-hidden="true" title="Saved Items"></i>
        <dfn><?php print $read_later_content;?></dfn>
      </span>
      <span>
        <i class="fa fa-user" aria-hidden="true" title="Follow Story"></i>
        <dfn><?php print $follow_ugc_content; ?></dfn>
      </span>
    </div>
      <?php if ($data['badge_detail']['earn'] > 0): ?>
      <div class="total-point-wrapper">
        <!-- Total Points -->        
        <div class="total-points">
            <span class="total-point-value">
                <?php print t('TOTAL POINTS'); ?>
                <span><?php print $data['badge_detail']['total']; ?></span>
            </span>
          <?php print render($data['badge_detail']['badge_icon']); ?>
        </div>
        
        <!-- Progress bar logic -->
        <?php
          
        ?>
        <?php //pr($data); ?>
        <div class="pregress-bar">            
            <span class="current-badge"><small><?php print $data['badge_detail']['earn']; ?></small><?php echo t('Current Level'); ?></span>
                <div class="progress-bar-div">
              <span class="pregress-bar-default"></span>
              <span class="pregress-bar-default pregress-bar-active" style="width: <?php print $data['badge_detail']['progress_bar']; ?>%"></span>
            </div>
            
            <?php if ($data['badge_detail']['earn'] != 5): ?>
            <span class="next-badge"><small><?php print $data['badge_detail']['next']; ?></small><?php echo t('Next Level'); ?></span>
            <?php endif; ?>
        </div>
        <?php if ($data['badge_detail']['earn'] != 5): ?>
        <div class="points-to-go">
          <?php print '<span>'.$data['badge_detail']['points_to_go'] . '</span> ' . t('Points to go'); ?>
        </div>
        <?php endif; ?>
      </div>
      <?php endif; ?>
  </div>
 </div> 

