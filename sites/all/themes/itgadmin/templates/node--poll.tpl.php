<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>
      <!-- add && !$teaser for hide comment link -->
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
                    <div class="field-label"><?php echo t('Poll Question'); ?>:</div>
                    <div class="field-items"><?php print $title; ?></div>                    
                  </div>
                  <?php
                  $poll_question_text = render($content['field_poll_question_text']);
                  if (!empty($poll_question_text)): print render($content['field_poll_question_text']);
                  endif;
                  ?>
                  <?php
                  $poll_question_image = render($content['field_poll_question_image']);
                  if (!empty($poll_question_image)): print render($content['field_poll_question_image']);
                  endif;
                  ?>
                  <?php
                  $poll_question_video = render($content['field_poll_question_video']);
                  if (!empty($poll_question_video)): print render($content['field_poll_question_video']);
                  endif;
                  ?>

                  <?php
                  if (isset($node->op) && $node->op == 'Preview') {
                    $output = '';
                    $imgfid = '';
                    $items = field_get_items('node', $node, 'field_poll_answer');
                    $ansnumber = 1;
                    foreach ($items as $imagecollection) {
                      if (isset($imagecollection['field_poll_answer_image'][LANGUAGE_NONE])) {
                        $imgfid = $imagecollection['field_poll_answer_image'][LANGUAGE_NONE][0]['fid'];
                      }
                      $output .= '<div>';
                      if ($imgfid != 0) {

                        if (module_exists('itg_photogallery')) {
                          if (!empty($imgfid)) {
                            $imguri = _itg_photogallery_fid($imgfid);
                            $style = 'thumbnail';
                            $output .='<div class="field"><div class="field-label">Answer ' . $ansnumber . ':</div><div class="field-items"><img src="' . image_style_url($style, $imguri) . '"/></div></div>';
                          }
                        }
                      }
                      if (isset($imagecollection['field_poll_answer_text'][LANGUAGE_NONE]) && !empty($imagecollection['field_poll_answer_text'][LANGUAGE_NONE][0]['value'])) {
                        $output .= '<div class="field"><div class="field-label">Answer ' . $ansnumber . ':</div><div class="field-items"><div class="ans-text"><span>' . $imagecollection['field_poll_answer_text'][LANGUAGE_NONE][0]['value'] . '</span></div></div></div>';
                      }

                      $output .= '</div>';
                      $ansnumber++;
                    }
                    if (isset($output) && !empty($output)) {
                      echo '<div>' . $output . '</div>';
                    }
                  }
                  else {
                    $ansnumber = 1;
                    foreach ($node->field_poll_answer[LANGUAGE_NONE] as $answer_arr) {
                      $ans_detail = entity_load('field_collection_item', array($answer_arr['value']));
                      $ans_image = $ans_detail[$answer_arr['value']]->field_poll_answer_image;
                      $ans_text = $ans_detail[$answer_arr['value']]->field_poll_answer_text;
                       if (isset($ans_image[LANGUAGE_NONE])) {
                        $imgfid = $ans_image[LANGUAGE_NONE][0]['fid'];
                      }
                      $output .= '<div>';
                      if ($imgfid != 0) {

                        if (module_exists('itg_photogallery')) {
                          if (!empty($imgfid)) {
                            $imguri = _itg_photogallery_fid($imgfid);
                            $style = 'thumbnail';
                            $output .='<div class="field"><div class="field-label">'.t('Answer').' ' . $ansnumber . ':</div><div class="field-items"><img src="' . image_style_url($style, $imguri) . '"/></div></div>';
                          }
                        }
                      }
                      if (isset($ans_text[LANGUAGE_NONE]) && !empty($ans_text[LANGUAGE_NONE][0]['value'])) {
                        $output .= '<div class="field"><div class="field-label">'.t('Answer').' ' . $ansnumber . ':</div><div class="field-items"><div class="ans-text"><span>' . $ans_text[LANGUAGE_NONE][0]['value'] . '</span></div></div></div>';
                      }

                      $output .= '</div>';
                      $ansnumber++;
                    }
                    if (isset($output) && !empty($output)) {
                      echo '<div>' . $output . '</div>';
                    }

                  }
                  ?>
                  <?php
                  $field_story_url = render($content['field_story_url']);
                  if (!empty($field_story_url)): print render($content['field_story_url']);
                  endif;
                  ?>
                  <?php
                  $field_poll_banner = render($content['field_poll_banner']);
                  if (!empty($field_poll_banner)): print render($content['field_poll_banner']);
                  endif;
                  ?>
                  <?php
                  $field_poll_call_to_action_image = render($content['field_poll_call_to_action_image']);
                  if (!empty($field_poll_call_to_action_image)): print render($content['field_poll_call_to_action_image']);
                  endif;
                  ?>
                </div>
              </div>
            </div>
          <?php endif; ?>


          <div class="content-node-view">
            <div class="poll-details">                            
              <h2><?php echo t('Configuration'); ?></h2>
              <div class="content-details">               
                <?php
                $field_poll_start_date = render($content['field_poll_start_date']);
                if (!empty($field_poll_start_date)): print render($content['field_poll_start_date']);
                endif;
                ?>
                <?php
                $field_end_date = render($content['field_poll_end_date']);
                if (!empty($field_end_date)): print render($content['field_poll_end_date']);
                endif;
                ?>
                <?php
                $field_result_format = render($content['field_result_format']);
                if (!empty($field_result_format)): print render($content['field_result_format']);
                endif;
                ?>
                <?php
                $field_display_result = render($content['field_display_result']);
                if (!empty($field_display_result)): print render($content['field_display_result']);
                endif;
                ?>
                <?php
                $field_associate_poll = render($content['field_associate_poll']);
                if (!empty($field_associate_poll)): print render($content['field_associate_poll']);
                endif;
                ?>
                <?php print render($content['poll_count']); ?>
              </div>
            </div>
          </div>
          <?php if ($node->op != 'Preview'): ?>
            <div class="current-poll-result">
              <?php
              if (isset($node->field_associate_poll[LANGUAGE_NONE])) {
                $associat_nid = $node->field_associate_poll[LANGUAGE_NONE][0]['target_id'];
                print views_embed_view('poll_listing', 'block_2', $associat_nid);
              }
              ?>
            </div>
            <?php endif; ?>

        </div>
<?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
      <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
