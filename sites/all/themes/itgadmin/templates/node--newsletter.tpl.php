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
          <div class="field-label">Template:</div>
          <div class="field-items"><?php echo l(ucwords($title), 'node/'.$node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'], array('attributes' => array('target'=>'_blank'))) ; ?></div>
        </div>
      <?php
      if (isset($node->op) && $node->op == 'Preview'){
        
        $prev_num = 0;
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          $sn = $prev_num + 1;
          echo '<h2>News ' . $sn . ' Details:</h2>';
         $prev_num++; 
         
        }
      } else { ?>
         <div class="field">
            <div class="field-label">Newsletter Type:</div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      
        <?php 
        if($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'] == 'automatic'){ ?>
         <div class="field">
            <div class="field-label">Frequency:</div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_frequency[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      <?php if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'daily') { ?>
          <div class="field">
            <div class="field-label">Time:</div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
      <?php } if ($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'weekly') { ?>
          <div class="field">
            <div class="field-label">Time:</div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label">Day:</div>
            <div class="field-items"><?php echo $node->field_newsl_day[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'monthly') { ?>
         <div class="field">
            <div class="field-label">Time:</div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label">Date:</div>
            <div class="field-items"><?php echo $node->field_newsl_date[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } ?>
          <div class="field">
            <div class="field-label">Newsletter Content:</div>
            <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'])).' news'; ?></div>
          </div>
        <?php } else { ?>
          <div class="field">
            <div class="field-label">Time:</div>
            <div class="field-items"><?php echo  $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
         <div class="field">
            <div class="field-label">Date:</div>
            <div class="field-items"><?php echo date('d/m/Y', strtotime($node->field_survey_start_date[LANGUAGE_NONE][0]['value'])); ?></div>
          </div>
      
        <?php
        $num = 0;
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          $news_detail = entity_load('field_collection_item', array($news_arr['value']));
          $sn = $num + 1;
          echo '<h2>News ' . $sn . ' Details:</h2>';
          ?>
          <div class="field">
            <div class="field-label">News Content:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Content Type:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_ctype[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
        <?php if ($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value'] == 'internal') {?>
          <div class="field">
            <div class="field-label">Content ID:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_cid[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
        <?php } else { ?>
         <div class="field">
            <div class="field-label">External URL:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_external_url[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
        <?php } ?>
          <div class="field">
            <div class="field-label">Title:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_title[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <div class="field">
            <div class="field-label">Kicker:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_kicker[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      
     <?php
     $num++;
   } //Foreach loop
  } //Else condition for manual
 } //Else condition for view
?>
      
 </div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>