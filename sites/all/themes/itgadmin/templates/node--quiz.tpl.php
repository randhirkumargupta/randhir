<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>

      <?php if (!empty($links) && !$teaser): ?>
        <div class='<?php print $hook ?>-links clearfix'>
          <?php print render($links) ?>
        </div>
      <?php endif; ?>

      <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      </div>
    </div>
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

          <?php if ($view_mode == 'full'): ?>
          <div class="content-node-view">
            <div class="basic-details content-box">
              <h2><?php echo t('Basic Details'); ?></h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label"><?php echo t('Title'); ?>:</div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>
                
                <?php
                $quiz_body = render($content['body']);
                if (!empty($quiz_body)): print render($content['body']);
                endif;

                $field_quiz_type = render($content['field_quiz_type']);
                if (!empty($field_quiz_type)): print render($content['field_quiz_type']);
                endif;

                if($content['field_quiz_type']['#items'][0]['value'] == 'immediate'){
                  print render($content['field_quiz_immediate_result']);
                }

                $source_id = render($content['field_story_source_id']);
                if (!empty($source_id)): print render($content['field_story_source_id']);
                endif;

                $quiz_scoring_type = render($content['field_quiz_scoring_type']);
                if (!empty($quiz_scoring_type)): print render($content['field_quiz_scoring_type']);
                endif;

                $display_sequence = render($content['field_quiz_display_sequence']);
                if (!empty($display_sequence)): print render($content['field_quiz_display_sequence']);
                endif;
                ?>
                
              </div>
            </div>
          </div>
          <div class="content-node-view">
                <div class="expert-details content-box">
                  <h2><?php echo t('Section'); ?></h2>
                  <div class="content-details">
                     <?php
                      $story_category = render($content['field_survey_category']);
                      if (!empty($story_category)): print render($content['field_survey_category']);
                      endif;
                      ?>
                  </div>
                </div>
          </div>
          
              <?php
             if (isset($node->op) && $node->op == 'Preview') {
              $output = '';
              $imgfid = '';
              $items = field_get_items('node', $node, 'field_quiz_add_questions');
               foreach ($items as $imagecollection) {
                 
                if (isset($imagecollection['field_survey_question'][LANGUAGE_NONE]) && !empty($imagecollection['field_survey_question'][LANGUAGE_NONE])) {
                    $output .=  '<div class="field"><div class="field-label">Question</div><div class="field-items">'.$imagecollection['field_survey_question'][LANGUAGE_NONE][0]['value'].'</div></div>';
                  }
                  
                if(isset($imagecollection['field_survey_add_media'][LANGUAGE_NONE])){
                $imgfid = $imagecollection['field_survey_add_media'][LANGUAGE_NONE][0]['fid'];
                }
                if ($imgfid != 0) {
                  if (module_exists('itg_photogallery')) {
                    if (!empty($imgfid)) {
                      $imguri = _itg_photogallery_fid($imgfid);
                      $style = 'thumbnail';
                      $output .='<div class="field"><div class="field-label">Media:</div><div class="field-items"><img src="' . image_style_url($style, $imguri) . '"/></div></div>';
                    }
                  }
                }
                if (isset($imagecollection['field_quiz_answer_type'][LANGUAGE_NONE]) && !empty($imagecollection['field_quiz_answer_type'][LANGUAGE_NONE])) {
                      $output .= '<div class="field"><div class="field-label">Answer Type:</div><div class="field-items">'.$imagecollection['field_quiz_answer_type'][LANGUAGE_NONE][0]['value'].'</div></div>';
                    }  
                  if ($content['field_quiz_scoring_type']['#items'][0]['value'] == 'weight' && isset($imagecollection['field_quiz_weightage'][LANGUAGE_NONE]) && !empty($imagecollection['field_quiz_weightage'][LANGUAGE_NONE])) {
                    $output .= '<div class="field"><div class="field-label">Weightage:</div><div class="field-items">'.$imagecollection['field_quiz_weightage'][LANGUAGE_NONE][0]['value'].'</div></div>';
                  }
                  $output .= '<div class="sub-field-quiz">'; //$output_sub
                  $imgfid_new = '';
                foreach($imagecollection['field_quiz_options_answer'][LANGUAGE_NONE] as $key => $subfield){
                    //$output .= '<div class="sub-field-quiz-inner">';
                    if (isset($subfield['field_quiz_option'][LANGUAGE_NONE]) && !empty($subfield['field_quiz_option'][LANGUAGE_NONE])) {
                      $output .= '<div class="field"><div class="field-label">Options:</div><div class="field-items">'.$subfield['field_quiz_option'][LANGUAGE_NONE][0]['value'].'</div></div>';
                    }
                    if (isset($subfield['field_quiz_answer_text'][LANGUAGE_NONE]) && !empty($subfield['field_quiz_answer_text'][LANGUAGE_NONE][0]['value'])) {
                      $output .= '<div class="field"><div class="field-label">Answer:</div><div class="field-items">'.$subfield['field_quiz_answer_text'][LANGUAGE_NONE][0]['value'].'</div></div>';
                    }
                    if(isset($subfield['field_quiz_answer_image'][LANGUAGE_NONE])){
                      $imgfid_new = $subfield['field_quiz_answer_image'][LANGUAGE_NONE][0]['fid'];
                       if ($imgfid_new != 0) {
                        if (module_exists('itg_photogallery')) {
                          if (!empty($imgfid_new)) {
                            $img_uri = _itg_photogallery_fid($imgfid_new);
                            $style = 'thumbnail';
                            $output .='<div class="field"><div class="field-label">Answer:</div><div class="field-items"><img src="' . image_style_url($style, $img_uri) . '"/></div></div>';
                          }
                        }
                      }
                    }
                  if(isset($subfield['field_quiz_answer_video'][LANGUAGE_NONE])){
                      $videofid = $subfield['field_quiz_answer_video'][LANGUAGE_NONE][0]['fid'];
                      if ($videofid != 0) {
                        if (module_exists('itg_photogallery')) {
                          if (!empty($videofid)) {
                            $video_uri = _itg_photogallery_fid($videofid);
                            $output .= '<div class="field"><div class="field-label">Answer:</div><div class="field-items">'.$video_uri.'</div></div>';
                          }
                        }
                      }
                    }
                  if (isset($subfield['field_quiz_correct_answer'][LANGUAGE_NONE][0]['value']) && !empty($subfield['field_quiz_correct_answer'][LANGUAGE_NONE][0]['value'])) {
                      $output .= '<div class="field"><div class="field-label">Correct Answer:</div><div class="field-items">'.$subfield['field_quiz_correct_answer'][LANGUAGE_NONE][0]['value'].'</div></div>';
                    }
                     
                   // $output .= "</div>";    
                } //endforeach sub field collection
                $output .= "</div>";
            } //endforeach main filed collection

              if (isset($output) && !empty($output)){
                ?>
          <div class="content-node-view">
                <div class="expert-details content-box">
                  <h2><?php echo t('Quiz Question'); ?></h2>
                  <div class="content-details">     
      <?php echo $output; ?>  
                  </div>
                </div>
        </div>
              <?php } 
              
              } else{              
                ?>
                <div class="content-node-view">
                  <div class="expert-details content-box">
                  <h2><?php echo t('Quiz Question'); ?></h2>
                  <div class="content-details">   
                  <?php
                    $field_poll_answer = render($content['field_quiz_add_questions']);
                      if (!empty($field_poll_answer)): print render($content['field_quiz_add_questions']);
                      endif;
                      ?>
                   </div>
                  </div>
                </div>
                    <?php
                     } ?> 

              <?php endif; ?>

          
          <div class="content-node-view">
            <div class="quiz-date">
              <h2><?php echo t('Date Settings'); ?></h2>
              <div class="content-details">
                <?php
                $start_date = render($content['field_survey_start_date']);
                if (!empty($start_date)): print render($content['field_survey_start_date']);
                endif;
                ?>
                <?php
                $end_date = render($content['field_survey_end_date']);
                if (!empty($end_date)): print render($content['field_survey_end_date']);
                endif;
                ?>
              </div>
            </div>
        </div>
         
         </div>
      <?php endif; ?>
        
      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object)  ?>
