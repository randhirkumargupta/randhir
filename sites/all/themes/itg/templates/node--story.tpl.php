<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
      <?php if ($view_mode == 'full'): ?>
               
        <div class="basic-details content-box">
            
            <div class="content-details">
                
                <?php print render($content['field_story_long_head_line']); ?>
                <div class="field field-name-field-story-body">
                    <div class="field-label">Story Body:&nbsp;</div>
                    <div class="field-items">
                        <div class="field-item even"><?php print render($content['body']); ?></div>
                    </div>
                </div>

            </div>
        </div>
       
      <?php endif; // end of view mode full condition ?></div>
  <?php
  // code for comment hide and show based on condition

  if ($node->field_story_configurations[LANGUAGE_NONE][0]['value'] == 'comment') {
    ?>
    <?php if (!empty($node->field_story_comment_question[LANGUAGE_NONE][0]['value'])) { ?>
      <div class="node comm-ques"> <?php print render($content['field_story_comment_question']); ?></div>
    <?php } ?>
    <?php
    print render($content['comment_form']);
    print render($content['comments']);
  }
  ?>
<?php endif; ?>