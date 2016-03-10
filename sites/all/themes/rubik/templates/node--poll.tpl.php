<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
        <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
      <?php endif; ?>
        <?php
        //p($node);
        echo $node->moderation_history_block;
        ?>
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
        <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
          <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
          <a href="<?php print $node_url ?>"><?php print $title ?></a>
        </h2>
      <?php endif; ?>

      <?php if (!empty($title_suffix)) print render($title_suffix); ?>

      <?php if (!empty($content)): ?>
        <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
          <?php
          //print render($content) 
          // print '<pre>';
          //print_r($content);
          //print '</pre>';
          ?>

          <?php if ($view_mode == 'full'): ?>

            <div class="basic-details content-box">
              <h2>Poll Title</h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label">Poll Title:</div>
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
              </div>
            </div>
            
              <?php
              $output = '';
              $imgfid = '';
              $items = field_get_items('node', $node, 'field_poll_answer');
              foreach ($items as $imagecollection) {
                if(isset($imagecollection['field_poll_answer_image']['und'])){
                $imgfid = $imagecollection['field_poll_answer_image']['und'][0]['fid'];
                }
                if ($imgfid != 0) {
                  $output .= '<li>';
                  if (module_exists('itg_photogallery')) {
                    if (!empty($imgfid)) {
                      $imguri = _itg_photogallery_fid($imgfid);
                      $style = 'thumbnail';
                      $output .='<img src="' . image_style_url($style, $imguri) . '"/>';
                    }
                  }
                }
                  if (isset($imagecollection['field_poll_answer_text']['und']) && !empty($imagecollection['field_poll_answer_text']['und'])) {
                    $output .= '<div class="ans-text"><span>' . $imagecollection['field_poll_answer_text']['und'][0]['value'] . '</span></div>';
                  }

                  $output .= '</li>';
              }
              if (isset($output) && !empty($output)):
                ?>
                <div class="expert-details content-box">
                  <h2>Poll Answer</h2>
                  <div class="content-details">     
      <?php echo '<ul>' . $output . '</ul>'; ?>     
                  </div>
                </div>
              <?php endif; ?> 
            <?php endif; ?>
          
          
            <div class="poll-details">
              <h2>Poll Details</h2>
              <div class="content-details">
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
                
                <?php
                $field_poll_start_date = render($content['field_poll_start_date']);
                if (!empty($field_poll_start_date)): print render($content['field_poll_start_date']);
                endif;
                ?>
                <?php
                $field_end_date = render($content['field_end_date']);
                if (!empty($field_end_date)): print render($content['field_end_date']);
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
              </div>
            </div>


          
          
         </div>
      <?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object)  ?>
