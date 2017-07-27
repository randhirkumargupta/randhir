<?php
/**
 * @file : itg-survey-form.tpl.php
 */
global $base_url;
$node = $form['node']['#value'];
$from_story = $form['from_story']['#value'];
$byline_node = node_load($node->field_story_reporter[LANGUAGE_NONE][0]['target_id']);

$byline_name = $byline_node->title;
$byline_twitter_handler = $byline_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
$created_date = date('M d, Y', $node->created);
$updated_date = date('h:i', $node->created);

if($form['question_format']['#value'] == 'All questions at a time') {
  $form_class = 'survey-form-wrapper-all';
}
else {
  $form_class = 'survey-form-wrapper-one';
}

// code for sharing
$actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
$uri = base64_encode($actual_link);
$short_url = shorten_url($actual_link, 'goo.gl');
$fb_title = addslashes($node->title);
$share_desc = '';
$image = '';
$nid = $node->nid;
$fb_count = $google_count = $twitter_count = 0;

// get fb count
if(function_exists('itg_facebook_share_count')) {
$fb_count = itg_facebook_share_count($actual_link);
}
// get google count
if(function_exists('itg_google_share_count')) {
$google_count = itg_google_share_count($actual_link);
}
// get twitter count 
if(function_exists('itg_common_mongo_share_count')) {
$twitter_count = itg_common_mongo_share_count($node->nid, 'twitter_share', 'front_user_activity');
}
?>
<div class="survey-form-main-container" style="margin: 10px 0px 10px 0px;">
  <h1 class="survey-title"><?php echo 'Survey: '.$node->title; ?></h1>
  
  <?php if ($from_story != 'yes') { ?>
  <div class="survey-description"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
  <div class="byline">
    <div class="profile-pic">
     <?php
       if (!empty($byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
         $byline_uri = file_create_url($byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
         ?>
       <img src="<?php echo $byline_uri; ?>" alt="" title=""/>
         <?php 
       }
       else {
         $file = 'default_images/user-default.png';
         print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
       }
       ?>
    </div>
    <div class="profile-detail">
      <ul>
        <li class="title"><?php echo $byline_name; ?></li>
          <?php
          $twitter_handle = str_replace('@', '', $byline_twitter_handler);
          if (!empty($twitter_handle)) {
            ?>
          <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script></li>                
          <?php } ?>
      </ul>
      <ul class="date-update">
        <li><?php echo $created_date; ?></li>
        <li>UPDATED <?php echo $updated_date; ?> IST </li>
      </ul>
    </div>
    <div class="social-info">
      <span>
        <a title = "share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook" aria-hidden="true"></i></a>
        <dfn><?php print $fb_count; ?></dfn>
      </span>
      <span>
        <a title = "share on twitter" href="javascript:void(0)" class="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter" aria-hidden="true"></i></a>
        <dfn><?php print $twitter_count; ?></dfn>
      </span>
      <span>
        <a title="share on google+" href="javascript:void(0)" class="user-activity" data-rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus" aria-hidden="true"></i></a>
        <dfn><?php print $google_count;?></dfn>
      </span>
      <!--<span>
        <i class="fa fa-comment" aria-hidden="true"></i>
        <dfn>1522</dfn>
      </span>-->
      
    </div>
  </div>
  <?php } ?>
  <!-- Render survey form -->
  <div class="<?php echo $form_class; ?>">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
