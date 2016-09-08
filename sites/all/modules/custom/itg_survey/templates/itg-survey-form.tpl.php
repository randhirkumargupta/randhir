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
$created_date = date('M d, Y', $byline_node->created);
$updated_date = date('h:i', $byline_node->created);

if($form['question_format']['#value'] == 'All questions at a time') {
  $form_class = 'survey-form-wrapper-all';
}
else {
  $form_class = 'survey-form-wrapper-one';
}
?>
<div class="survey-form-main-container">
  <div class="survey-title"><?php echo $node->title; ?></div>
  <div class="survey-description"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
  <div class="survey-byline-name"><?php echo $byline_name; ?></div>
  <div class="survey-byline-twitter-handler"><?php echo $byline_twitter_handler; ?></div>
  <div class="survey-byline-image"><img src="<?php echo $byline_image; ?>" alt="" title=""/></div>
  <div class="survey-byline-date"><?php echo $created_date . ' | UPDATED ' . $updated_date . ' IST | New Delhi'; ?></div>
  
  <!-- Render survey form -->
  <div class="<?php echo $form_class; ?>">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
