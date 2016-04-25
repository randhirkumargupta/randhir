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
          <div class="field-label">Subject Line:</div>
          <div class="field-items"><?php echo $title; ?></div>
        </div>
        <div class="field">
          <div class="field-label">Header Headline:</div>
          <div class="field-items"><?php echo ucwords($node->field_newsl_header_headline[LANGUAGE_NONE][0]['value']); ?></div>
        </div>
        <div class="field">
          <div class="field-label">Main Headline:</div>
          <div class="field-items"><?php echo ucwords($node->field_newsl_main_headline[LANGUAGE_NONE][0]['value']); ?></div>
        </div>
        <div class="field">
          <div class="field-label">Property (Website Name):</div>
          <div class="field-items"><?php echo $node->field_newsl_website_name[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></div>
        </div>
      
      <?php
      if (isset($node->op) && $node->op == 'Preview'){
        
        $prev_num = 0;
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          echo '<h2>News ' . ($prev_num + 1) . ' Details:</h2>';
          ?>
           <div class="field">
              <div class="field-label">Headline:</div>
              <div class="field-items"><?php echo ucwords($news_arr['field_news_headline'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <div class="field">
              <div class="field-label">Ordering:</div>
              <div class="field-items"><?php echo ucwords($news_arr['field_news_ordering'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
           <div class="field">
              <div class="field-label">Type:</div>
              <div class="field-items"><?php echo ucwords($news_arr['field_news_type'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <div class="field">
              <div class="field-label">Story ID:</div>
              <div class="field-items"><?php echo $news_arr['field_news_story_id'][LANGUAGE_NONE][0]['target_id']; ?></div>
            </div>
            <div class="field">
              <div class="field-label">Description:</div>
              <div class="field-items"><?php echo ucwords($news_arr['field_news_description'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
            <div class="field">
              <div class="field-label">Kicker:</div>
              <div class="field-items"><?php echo ucwords($news_arr['field_field_news_kicker'][LANGUAGE_NONE][0]['value']); ?></div>
            </div>
           <?php
         $prev_num++; 
         
        }
      } else {
      $num = 0;
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          $news_detail = entity_load('field_collection_item', array($news_arr['value']));
          echo '<h2>News ' . ($num + 1) . ' Details:</h2>';
          ?>
      
          <div class="field">
            <div class="field-label">Headline:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_headline[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Ordering:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_ordering[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Type:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Story ID:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_story_id[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Description:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_description[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Kicker:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_field_news_kicker[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
            <?php
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