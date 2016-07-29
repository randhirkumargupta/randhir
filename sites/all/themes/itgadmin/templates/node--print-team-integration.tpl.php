<?php

//Check for idea approval users 
$idea_review_flag_user = itg_print_team_check_approval_users();
if ($_GET['type'] == 'commentform') {
  print render($content['comment_form']);
  print render($content['comments']);
}  else { 
?>

  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    </div></div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php if (!empty($title) && !$page): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <a href="<?php print $node_url ?>"><?php print $title ?></a>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      
      <div class="field">
        <div class="field-label">Idea Headline:</div>
        <div class="field-items"><?php echo ucwords($node->title); ?></div>
      </div>
      
      <div class="field">
        <div class="field-label">Idea Brief:</div>
        <div class="field-items"><?php echo ucfirst($node->body[LANGUAGE_NONE][0]['value']); ?></div>
      </div>
      
      <?php if($node->field_story_category[LANGUAGE_NONE][0]['taxonomy_term']->name) {?>
      <div class="field">
        <div class="field-label">Section:</div>
        <div class="field-items"><?php echo $node->field_story_category[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
      </div>
      <?php } ?>
      
      <?php if($node->field_pti_idea_status[LANGUAGE_NONE][0]['value']) {?>
      <div class="field">
        <div class="field-label">Status:</div>
        <div class="field-items"><?php echo $node->field_pti_idea_status[LANGUAGE_NONE][0]['value']; ?></div>
      </div>
      <?php } ?>
      
      <?php 
      if($node->field_pti_idea_status[LANGUAGE_NONE][0]['value'] == 'Approved') {
        
      if($node->field_pti_words_limit[LANGUAGE_NONE][0]['value']) { ?>
      <div class="field">
        <div class="field-label">Words Limit:</div>
        <div class="field-items"><?php echo $node->field_pti_words_limit[LANGUAGE_NONE][0]['value'] . ' words'; ?></div>
      </div>
      <?php } ?>
      
      <?php if($node->field_survey_end_date[LANGUAGE_NONE][0]['value']) {?>
      <div class="field">
        <div class="field-label">Timeline:</div>
        <div class="field-items"><?php echo date('d/m/Y', strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'])); ?></div>
      </div>
      <?php } } ?>
      
     <?php
      //Render image and video
      foreach ($node->field_pti_print_media[LANGUAGE_NONE] as $media_arr) {
        $media_detail = entity_load('field_collection_item', array($media_arr['value']));
        $image = image_style_url("thumbnail", $media_detail[$media_arr['value']]->field_pti_upload_image[LANGUAGE_NONE][0]['uri']);
        $video = $media_detail[$media_arr['value']]->field_pti_upload_video[LANGUAGE_NONE][0]['uri'];
      ?>
      
      <div class="field">
        <div class="field-label">Image:</div>
        <div class="field-items"><img src="<?php echo $image; ?>" /></div>
      </div>
      
      <div class="field">
      <div class="field-label">Video:</div>
      <div class="field-items">
        <video width="120" controls="controls">
          <source src="<?php $video; ?>" type="video/mp4"> 
          <object> 
            <embed  src="<?php $video; ?>"> 
          </object> 
        </video>
      </div>
      </div>
      <?php } ?>
      
      <?php if ($idea_review_flag_user) { ?>
        <?php if($node->field_pti_issue[LANGUAGE_NONE][0]['entity']->title) {?>
        <div class="field">
          <div class="field-label">Issue:</div>
          <div class="field-items"><?php echo date('d/m/Y', strtotime($node->field_pti_issue[LANGUAGE_NONE][0]['entity']->title)); ?></div>
        </div>
        <?php } ?>

        <?php if($node->field_pti_magazine[LANGUAGE_NONE][0]['entity']->title) {?>
        <div class="field">
          <div class="field-label">Magazine:</div>
          <div class="field-items"><?php echo $node->field_pti_magazine[LANGUAGE_NONE][0]['entity']->title; ?></div>
        </div>
        <?php } ?>
      <?php } ?>
 </div>   
  <?php endif; ?>
  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
<?php } ?>

