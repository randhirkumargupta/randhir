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
        <div class="field-label">Idea Headline:</div>
        <div class="field-items"><?php echo ucwords($node->title); ?></div>
      </div>
      <div class="field">
        <div class="field-label">Idea Brief:</div>
        <div class="field-items"><?php echo ucfirst($node->body[LANGUAGE_NONE][0]['value']); ?></div>
      </div>
      <div class="field">
        <div class="field-label">Section:</div>
        <div class="field-items"><?php echo $node->field_story_category[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
      </div>
      <?php if($node->field_quiz_answer_image[LANGUAGE_NONE][0]['uri']) {?>
       <div class="field">
        <div class="field-label">Image:</div>
        <div class="field-items"><img src="<?php echo image_style_url("thumbnail", $node->field_quiz_answer_image[LANGUAGE_NONE][0]['uri']); ?>"></div>
      </div>
      <?php } ?>
      <?php if($node->field_quiz_answer_video[LANGUAGE_NONE][0]['uri']) {?>
       <div class="field">
        <div class="field-label">Video:</div>
        <div class="field-items">
          <video width="120" controls="controls">
            <source src="<?php $node->field_quiz_answer_video[LANGUAGE_NONE][0]['uri']; ?>" type="video/mp4"> 
            <object> 
              <embed  src="<?php $node->field_quiz_answer_video[LANGUAGE_NONE][0]['uri']; ?>"> 
            </object> 
          </video>
        </div>
      </div>
      <?php } ?>
 </div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>