<?php
/**
 * @file : itg-survey-form.tpl.php
 */
global $base_url;
$node = $form['node']['#value'];
$byline_node = node_load($node->field_story_reporter[LANGUAGE_NONE][0]['target_id']);

$byline_name = $byline_node->title;
$byline_twitter_handler = $byline_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
$byline_image = $base_url . str_replace('public://', '/sites/default/files/', $byline_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
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
  <div class="survey-description"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
  <div class="byline">
    <div class="profile-pic">
      <img src="<?php echo $byline_image; ?>" alt="" title=""/>
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
  
  <!-- Render survey form -->
  <div class="<?php echo $form_class; ?>">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
