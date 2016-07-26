<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
      <?php if ($view_mode == 'full'): ?>
                <?php //pr($content['field_story_reporter']); die; ?>
                <h1><?php print $content['field_story_long_head_line']['#object']->title;?></h1>
                <div class="reporter"><?php print($content['field_story_reporter']['#object']->field_story_reporter['und'][0]['entity']->title);  ?></div>
                <div class="story-body"><?php print $content['body']['#object']->body['und'][0]['value']; ?></div>
       
      <?php endif; // end of view mode full condition ?>
  </div>
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