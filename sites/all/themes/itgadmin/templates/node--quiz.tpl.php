<?php
 global $base_url;
 $get_all_category = taxonomy_get_parents_all($node->field_survey_category[LANGUAGE_NONE][0]['tid']);
 foreach($get_all_category as $categories) {
   $all_categories[] = $categories->name;
 }
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

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
          <div class="content-node-view">
          <div class="basic-details content-box">
            <h2><?php echo t('Basic Details'); ?></h2>
            <div class="content-details">
              <div class="field">
                <div class="field-label"><?php echo t('Title:'); ?></div>
                <div class="field-items"><?php echo $title; ?></div>
              </div>
              <div class="field">
                <div class="field-label"><?php echo t('Quiz Instructions:'); ?></div>
                <div class="field-items"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
              </div>
              <div class="field">
                <div class="field-label"><?php echo t('Quiz Type:'); ?></div>
                <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $node->field_quiz_type[LANGUAGE_NONE][0]['value'])); ?></div>
              </div>
              
              <?php if($node->field_quiz_type[LANGUAGE_NONE][0]['value'] == 'immediate') { ?>
              <div class="field">
                <div class="field-label"><?php echo t('Immediate Result:'); ?></div>
                <div class="field-items">
                  <?php 
                  if ($node->field_quiz_immediate_result[LANGUAGE_NONE][0]['value'] == 'qwr') { 
                    echo t('Question Wise Result');
                  } 
                  else {
                    echo t('At the End');
                  } 
                  ?>
                </div>
              </div>
              <?php } else { ?>
              <div class="field">
                <div class="field-label"><?php print t('Winners:'); ?></div>
                <div class="field-items">
                  <?php
                  if (empty($node->field_quiz_winners[LANGUAGE_NONE][0]['value'])) {
                    echo t('None');
                  }
                  else {
                    echo $node->field_quiz_winners[LANGUAGE_NONE][0]['value'];
                  }
                  ?>
                </div>
              </div>
              
              <?php } ?>
              <div class="field">
                <div class="field-label"><?php echo t('Quiz Scoring Type:'); ?></div>
                <div class="field-items"><?php echo ucwords($node->field_quiz_scoring_type[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <div class="field">
                <div class="field-label"><?php echo t('Questions Display Sequence:'); ?></div>
                <div class="field-items"><?php echo ucwords($node->field_quiz_display_sequence[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <div class="field">
                <div class="field-label"><?php echo t('Quiz Questions Format:'); ?></div>
                <div class="field-items"><?php echo ucfirst($node->field_survey_questions_format[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
            </div>
          </div>
        </div>
      <div class="content-node-view">
          <div class="expert-details content-box">
            <h2><?php echo t('Categorization'); ?></h2>
            <div class="content-details">
              <div class="field">
                <div class="field-label"><?php echo t('Section & categories:'); ?></div>
                <div class="field-items">
                  <?php
                  $total_cat = count($all_categories);
                  for($i = $total_cat-1; $i >= 0; $i--) {
                    $separator = $i ? '->' : '';
                    echo $all_categories[$i]. $separator;
                  }
                  ?>
                </div>
              </div>
            </div>
          </div>
     </div>
      <?php
      if (isset($node->op) && $node->op == 'Preview') { ?>
       <div class="content-node-view">
          <div class="expert-details content-box">
            <h2><?php echo t('Add Quiz Questions'); ?></h2>
            <div class="content-details">
        <?php 
        $ques_num = 0;
        foreach ($node->field_quiz_add_questions[LANGUAGE_NONE] as $question_arr) {
          
          //Media Info
          $file = file_load($question_arr['field_survey_add_media'][LANGUAGE_NONE][0]['fid']);
          $media = $file->uri;
          $media_type = strtolower(substr(strrchr($media, '.'), 1));
          $media_path = $base_url . str_replace('public://', '/sites/default/files/', $media);
          echo '<div style="margin-top:10px"><strong>Question ' . ($ques_num + 1).':</strong></div>';
          ?>
              <div class="field">
                 <div class="field-label"><?php print t('Question:'); ?></div>
                 <div class="field-items"><?php echo ucwords($question_arr['field_survey_question'][LANGUAGE_NONE][0]['value']) . '?'; ?></div>
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
              <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $question_arr['field_quiz_answer_type'][LANGUAGE_NONE][0]['value'])); ?></div>
            </div>
          <?php if($node->field_quiz_scoring_type[LANGUAGE_NONE][0]['value'] == 'weight') {?>    
          <div class="field">
            <div class="field-label"><?php print t('Weightage:'); ?></div>
            <div class="field-items"><?php echo $question_arr['field_quiz_weightage'][LANGUAGE_NONE][0]['value']; ?></div>
          </div>
          <?php } ?>   
            <div class="field">
              <div class="field-label"><?php print t('Answer Option:'); ?></div>
              <div class="field-items"><?php echo ucwords($question_arr['field_quiz_option'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
          <?php
          
          // Answer details
          $answer_options = $question_arr['field_quiz_options_answer'][LANGUAGE_NONE];
          $ans_num = 1;
          foreach ($answer_options as $answer_options_arr) { 
            if($answer_options_arr['field_quiz_answer_text'][LANGUAGE_NONE][0]['value'] != 'A') {
            ?>
              <div class="field">
                 <div class="field-label"><?php print t('Answer'); ?> <?php echo $ans_num; ?>:</div>
                 <div class="field-items"><?php echo ucwords($answer_options_arr['field_quiz_answer_text'][LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <div class="field">
                 <div class="field-label"><?php print t('Correct Answer:'); ?></div>
                 <div class="field-items"><?php echo $answer_options_arr['field_quiz_correct_answer'][LANGUAGE_NONE][0]['value'] ? ucwords($answer_options_arr['field_quiz_correct_answer'][LANGUAGE_NONE][0]['value']) : t('No'); ?></div>
              </div>
           <?php 
            }
            $ans_num++;
          }
         $ques_num++; 
          } ?>
    </div> 
  </div> 
 </div> 
        
         <?php  } else { ?>
      <div class="content-node-view">
          <div class="expert-details content-box">
            <h2><?php echo t('Add Quiz Questions'); ?></h2>
            <div class="content-details">
       <?php
        $ques_num = 0;
        foreach ($node->field_quiz_add_questions[LANGUAGE_NONE] as $question_arr) {
          $question_detail = entity_load('field_collection_item', array($question_arr['value']));
          
          //Media Info
          $media = $question_detail[$question_arr['value']]->field_survey_add_media[LANGUAGE_NONE][0]['uri'];
          $media_type = strtolower(substr(strrchr($media, '.'), 1));
          $media_path = $base_url . str_replace('public://', '/sites/default/files/', $media);
          echo '<div style="margin-top:10px"><strong>'.t('Question').' ' . ($ques_num + 1).':</strong></div>';
          ?>
      
          <div class="field">
            <div class="field-label"><?php echo t('Question:'); ?></div>
            <div class="field-items"><?php echo ucwords($question_detail[$question_arr['value']]->field_survey_question[LANGUAGE_NONE][0]['value']) . '?'; ?></div>
          </div>

          <?php 
          if(!empty($media_type)){
          if($media_type == 'jpg' || $media_type == 'jpeg' || $media_type == 'png' || $media_type == 'gif'){ ?>
              <div class="field">
                <div class="field-label"><?php echo t('Add Media:'); ?></div>
                <div class="field-items"><img src="<?php echo $media_path; ?>" height="100" width="130"/></div>
              </div>
          <?php }  else { ?>
                <div class="field">
                  <div class="field-label"><?php echo t('Add Media:'); ?></div>
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
            <div class="field-label"><?php echo t('Answer Type:'); ?></div>
            <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $question_detail[$question_arr['value']]->field_quiz_answer_type[LANGUAGE_NONE][0]['value'])); ?></div>
          </div>
          <?php if($node->field_quiz_scoring_type[LANGUAGE_NONE][0]['value'] == 'weight') { ?>    
          <div class="field">
            <div class="field-label"><?php echo t('Weightage:'); ?></div>
            <div class="field-items"><?php echo $question_detail[$question_arr['value']]->field_quiz_weightage[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
          <?php } ?>    
          <div class="field">
            <div class="field-label"><?php echo t('Answer Option:'); ?></div>
            <div class="field-items"><?php echo ucwords($question_detail[$question_arr['value']]->field_quiz_option[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
              
          <?php
          // Answer details
          $answer_options = $question_detail[$question_arr['value']]->field_quiz_options_answer[LANGUAGE_NONE];
          $ans_num = 1;
          foreach ($answer_options as $answer_options_arr) {
              $answer_detail = entity_load('field_collection_item', array($answer_options_arr['value'])); ?>
              <div class="field">
                 <div class="field-label"><?php echo t('Answer'); ?><?php echo $ans_num; ?>:</div>
                 <div class="field-items"><?php echo ucwords($answer_detail[$answer_options_arr['value']]->field_quiz_answer_text[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <div class="field">
                 <div class="field-label"><?php echo t('Correct Answer:'); ?></div>
                 <div class="field-items"><?php echo $answer_detail[$answer_options_arr['value']]->field_quiz_correct_answer[LANGUAGE_NONE][0]['value'] ? ucwords($answer_detail[$answer_options_arr['value']]->field_quiz_correct_answer[LANGUAGE_NONE][0]['value']) : t('No'); ?></div>
              </div>
           <?php 
           $ans_num++;
          }
     $ques_num++;
   } ?>
   </div> 
  </div> 
 </div> 
      
<?php } ?>
  <div class="content-node-view">
      <div class="expert-details content-box">
        <h2><?php echo t('Publish/Unpublish'); ?></h2>
        <div class="content-details">
          <div class="field">
            <div class="field-label">Published:</div>
            <div class="field-items"><?php echo $node->status ? t('Yes'):t('No'); ?></div>
          </div>
        </div>
      </div>
    </div>
      
</div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>