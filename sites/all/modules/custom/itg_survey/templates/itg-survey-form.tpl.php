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
        <i class="fa fa-facebook" aria-hidden="true"></i>
        <dfn>1522</dfn>
      </span>
      <span>
        <i class="fa fa-twitter" aria-hidden="true"></i>
        <dfn>1522</dfn>
      </span>
      <span>
        <i class="fa fa-google-plus" aria-hidden="true"></i>
        <dfn>1522</dfn>
      </span>
      <span>
        <i class="fa fa-comment" aria-hidden="true"></i>
        <dfn>1522</dfn>
      </span>
      
    </div>
  </div>
  <?php } ?>
  <!-- Render survey form -->
  <div class="<?php echo $form_class; ?>">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
