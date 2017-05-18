<?php
 global $base_url;
?>
<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='<?php print $hook ?>-links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>

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
          <div class="field-label"><?php print t('Survey Title:');  ?></div>
          <div class="field-items"><?php echo $title; ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Survey Instruction:');  ?></div>
          <div class="field-items"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Survey Questions Format:');  ?></div>
          <div class="field-items"><?php echo $node->field_survey_questions_format[LANGUAGE_NONE][0]['value']; ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Publish:');  ?></div>
          <div class="field-items"><?php echo $node->status ? 'Yes' : 'No'; ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Survey Question Display:');  ?></div>
          <div class="field-items"><?php echo ucwords($node->field_survey_question_display[LANGUAGE_NONE][0]['value']); ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Category:');  ?></div>
          <div class="field-items"><?php echo $node->field_survey_category[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('Start Date:');  ?></div>
          <div class="field-items"><?php echo date('Y/m/d', strtotime($node->field_survey_start_date[LANGUAGE_NONE][0]['value'])); ?></div>
        </div>
        <div class="field">
          <div class="field-label"><?php print t('End Date:');  ?></div>
          <div class="field-items"><?php echo date('Y/m/d', strtotime($node->field_survey_end_date[LANGUAGE_NONE][0]['value'])); ?></div>
        </div>
      
      <?php
      if (isset($node->op) && $node->op == 'Preview'){
        
        $prev_num = 0;
        foreach ($node->field_survey_add_questions[LANGUAGE_NONE] as $question_arr) {
          
          //Media Info
          $file = file_load($question_arr['field_survey_add_media'][LANGUAGE_NONE][0]['fid']);
          $media = $file->uri;
          $media_type = strtolower(substr(strrchr($media, '.'), 1));
          $media_path = $base_url . str_replace('public://', '/sites/default/files/', $media);
          echo '<h2>Question ' . ($prev_num + 1) . ' Details:</h2>';
          ?>
           <div class="field">
              <div class="field-label"><?php print t('Question:');  ?></div>
              <div class="field-items"><?php echo ucwords($question_arr['field_survey_question'][LANGUAGE_NONE][0]['value']) . '?'; ?></div>
            </div>
            <div class="field">
              <div class="field-label"><?php print t('Skip Question:');  ?></div>
              <div class="field-items"><?php echo ucwords($question_arr['field_survey_skip'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <?php 
            if(!empty($media_type)){
            if($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif'){?>
              <div class="field">
                <div class="field-label"><?php print t('Add Media:');  ?></div>
                <div class="field-items"><img src="<?php echo $media_path; ?>" height="100" width="130"/></div>
              </div>
            <?php }  else { ?>
              <div class="field">
                <div class="field-label"><?php print t('Add Media:');  ?></div>
                <div class="field-items">
                  <video width="140" height="145" controls="controls">
                    <source src="<?php echo $media ?>" type="video/mp4"> 
                    <object> 
                      <embed  src="<?php echo $media ?>"> 
                    </object> 
                  </video>
               </div>
              </div>
            <?php } }?>
           <div class="field">
              <div class="field-label"><?php print t('Answer Type:');  ?></div>
              <div class="field-items"><?php echo ucwords($question_arr['field_survey_answer_type'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <div class="field">
              <div class="field-label"><?php print t('Answer Option 1:');  ?></div>
              <div class="field-items"><?php echo itg_survey_get_answer_type_name($question_arr['field_survey_answer_option_1'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
           <?php
              $more_ans_num = 2;
              foreach($question_arr['field_survey_answer_option_2'][LANGUAGE_NONE] as $more_ans_arr){
              if(!empty($more_ans_arr['value'])){
                echo '<div class="field">';
                echo '<div class="field-label">'.t('Answer Option').' '.$more_ans_num.':</div>';
                echo '<div class="field-items">'.$more_ans_arr['value'].'</div></div>';
              }
                $more_ans_num++;
              }
         $prev_num++; 
         
        }
      } else {
      $num = 0;
        foreach ($node->field_survey_add_questions[LANGUAGE_NONE] as $question_arr) {
          $question_detail = entity_load('field_collection_item', array($question_arr['value']));
          
          //Media Info
          $media = $question_detail[$question_arr['value']]->field_survey_add_media[LANGUAGE_NONE][0]['uri'];
          $media_type = strtolower(substr(strrchr($media, '.'), 1));
          $media_path = $base_url . str_replace('public://', '/sites/default/files/', $media);
          echo '<h2>Question ' . ($num + 1) . ' Details:</h2>';
          ?>
      
          <div class="field">
            <div class="field-label"><?php print t('Question:'); ?></div>
            <div class="field-items"><?php echo ucwords($question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value']) . '?'; ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Skip Question:'); ?></div>
            <div class="field-items"><?php echo ucwords($question_detail[$question_arr['value']]->field_survey_skip[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <?php 
          if(!empty($media_type)){
          if($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif'){?>
              <div class="field">
                <div class="field-label"><?php print t('Add Media:'); ?></div>
                <div class="field-items"><img src="<?php echo $media_path; ?>" height="100" width="130"/></div>
              </div>
          <?php }  else { ?>
                <div class="field">
                  <div class="field-label"><?php print t('Add Media:'); ?></div>
                  <div class="field-items">
                    <video width="140" height="145" controls="controls">
                      <source src="<?php echo $media ?>" type="video/mp4"> 
                      <object> 
                        <embed  src="<?php echo $media ?>"> 
                      </object> 
                    </video>
                 </div>
                </div>
          <?php } }?>
          <div class="field">
            <div class="field-label"><?php print t('Answer Type:'); ?></div>
            <div class="field-items"><?php echo itg_survey_get_answer_type_name($question_detail[$question_arr['value']]->field_survey_answer_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Answer Option 1:'); ?></div>
            <div class="field-items"><?php echo ucwords($question_detail[$question_arr['value']]->field_survey_answer_option_1[LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <?php
            if(count($question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE]) > 0){
              $more_ans_num = 2;
              foreach($question_detail[$question_arr['value']]->field_survey_answer_option_2[LANGUAGE_NONE] as $more_ans_arr){
                echo '<div class="field">';
                echo '<div class="field-label">'.t('Answer Option').' '.$more_ans_num.':</div>';
                echo '<div class="field-items">'.$more_ans_arr['value'].'</div></div>';
                $more_ans_num++;
              }
            }
     $num++;
   }
 }
     ?>
 </div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>