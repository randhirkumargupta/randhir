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
          <div class="field-label"><?php print t('Template:'); ?></div>
          <div class="field-items"><?php echo ucfirst(itg_common_get_node_title($node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id'])); ?></div>
        </div>
      <?php
      if (isset($node->op) && $node->op == 'Preview') {
        if($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'] == 'automatic') { ?>
          <div class="field">
            <div class="field-label"><?php print t('Frequency:'); ?></div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_frequency[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      <?php if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'daily') { ?>
          <div class="field">
            <div class="field-label"><?php print t('Time:'); ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
      <?php } if ($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'weekly') { ?>
          <div class="field">
            <div class="field-label"><?php print t('Time:'); ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Day:'); ?></div>
            <div class="field-items"><?php echo $node->field_newsl_day[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'monthly') { ?>
         <div class="field">
            <div class="field-label"><?php print t('Time:'); ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Date:'); ?></div>
            <div class="field-items"><?php echo $node->field_newsl_date[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } ?>
          <div class="field">
            <div class="field-label"><?php print t('Newsletter Content:'); ?></div>
            <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'])).' news'; ?></div>
          </div>
        <?php } else {
        
        $template_node = node_load($node->field_newsl_select_template[LANGUAGE_NONE][0]['target_id']);
        $headline = $template_node->field_newst_header_headline[LANGUAGE_NONE][0]['value'];
        $logo = image_style_url("thumbnail", $template_node->field_newst_logo[LANGUAGE_NONE][0]['uri']);
        $banner = $template_node->field_newst_banner[LANGUAGE_NONE][0]['uri'];
        $footer = $template_node->body[LANGUAGE_NONE][0]['value'];
       ?>
      <div class="newsletter-templates">
      <div class="newsletter-header">
       <div class="newsletter-headline"><?php echo $headline; ?></div>
       <div class="newsletter-logo"><img src="<?php echo $logo; ?>" /></div>
       <div class="newsletter-banner"><img src="<?php echo str_replace('public://', $base_url.'/sites/default/files/',$banner ); ?>" alt="" /></div>
      </div>
        <div class="newsletter-list-parent">
       <?php
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          
          $content_id = $news_arr['field_news_cid'][LANGUAGE_NONE][0]['target_id'];

          $title = $news_arr['field_news_title'][LANGUAGE_NONE][0]['value'];
          $kicker = $news_arr['field_news_kicker'][LANGUAGE_NONE][0]['value'];
          
          if($news_arr['field_news_thumbnail'][LANGUAGE_NONE][0]['fid']){
          $file = file_load($news_arr['field_news_thumbnail'][LANGUAGE_NONE][0]['fid']);
          $thumbnail = image_style_url("thumbnail", $file->uri); 
          }
          else {
            $thumbnail = $base_url.'/'.drupal_get_path('module', 'itg_newsletter').'/image/no-image.png';
          }

          
          if($news_arr['field_news_type'][LANGUAGE_NONE][0]['value'] == 'internal') {
              $link = 'node/'.$news_arr['field_news_cid'][LANGUAGE_NONE][0]['target_id'];
              $content_id = $news_arr['field_news_cid'][LANGUAGE_NONE][0]['target_id'];
            } else {
              $link = $news_arr['field_news_external_url'][LANGUAGE_NONE][0]['value'];
              $content_id = $link;
          }
          
          if($content_id) {
          ?>
          <div class="newsletter-list">
            <div class="newsletter-thumbnail"><img style="width:100px; height: 100px" src="<?php echo $thumbnail; ?>" /></div>  
            <div class="title-kicker">
              <div class="newsletter-title"><?php echo $title; ?></div>
              <div class="newsletter-kicker"><?php echo $kicker; ?></div>
            </div>
          </div>
        <?php } }?>
        </div>  
         <div class="newsletter-footer"><?php echo $footer; ?></div>
      </div>
        <?php } 
      } else { ?>
         <div class="field">
            <div class="field-label"><?php print t('Newsletter Type:');  ?></div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      
        <?php 
        if($node->field_newsl_newsletter_type[LANGUAGE_NONE][0]['value'] == 'automatic'){ ?>
         <div class="field">
            <div class="field-label"><?php print t('Frequency:');  ?></div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_frequency[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      <?php if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'daily') { ?>
          <div class="field">
            <div class="field-label"><?php print t('Time:');  ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
      <?php } if ($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'weekly') { ?>
          <div class="field">
            <div class="field-label"><?php print t('Time:');  ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Day:');  ?></div>
            <div class="field-items"><?php echo $node->field_newsl_day[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } if($node->field_newsl_frequency[LANGUAGE_NONE][0]['value'] == 'monthly') { ?>
         <div class="field">
            <div class="field-label"><?php print t('Time:');  ?></div>
            <div class="field-items"><?php echo $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
          <div class="field">
            <div class="field-label"><?php print t('Date:');  ?></div>
            <div class="field-items"><?php echo $node->field_newsl_date[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
      <?php } ?>
          <div class="field">
            <div class="field-label"><?php print t('Newsletter Content');  ?>:</div>
            <div class="field-items"><?php echo ucwords(str_replace('_', ' ', $node->field_newsl_newsletter_content[LANGUAGE_NONE][0]['value'])).' news'; ?></div>
          </div>
        <?php } else { ?>
         <div class="field">
            <div class="field-label"><?php print t('Schedule');  ?>:</div>
            <div class="field-items"><?php echo ucwords($node->field_newsl_schedule[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
      <?php if($node->field_newsl_schedule[LANGUAGE_NONE][0]['value'] == 'later') {?>
          <div class="field">
            <div class="field-label"><?php print t('Time');  ?>:</div>
            <div class="field-items"><?php echo  $node->field_newsl_time[LANGUAGE_NONE][0]['value'].':00'; ?></div>
          </div>
         <div class="field">
            <div class="field-label"><?php print t('Date');  ?>:</div>
            <div class="field-items"><?php echo date('d/m/Y', strtotime($node->field_survey_start_date[LANGUAGE_NONE][0]['value'])); ?></div>
          </div>
      <?php } 
     
        //Render field collection items
        $num = 0;
        foreach ($node->field_newsl_add_news[LANGUAGE_NONE] as $news_arr) {
          $news_detail = entity_load('field_collection_item', array($news_arr['value']));
          $sn = $num + 1;
          echo '<h2>'.t('News').' ' . $sn . ' '.t('Details').':</h2>';
          
          $thumbnail = image_style_url("thumbnail", $news_detail[$news_arr['value']]->field_news_thumbnail[LANGUAGE_NONE][0]['uri']);
    
          ?>
          <div class="field">
            <div class="field-label"><?php print t('News Content');  ?>:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value']); ?></div>
          </div>

        <?php if ($news_detail[$news_arr['value']]->field_news_type[LANGUAGE_NONE][0]['value'] == 'internal') {?>
          <div class="field">
            <div class="field-label"><?php print t('Content ID');  ?>:</div>
            <div class="field-items"><?php echo $news_detail[$news_arr['value']]->field_news_cid[LANGUAGE_NONE][0]['target_id']; ?></div>
          </div>
        <?php } else { ?>
         <div class="field">
            <div class="field-label"><?php print t('External URL');  ?>:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_external_url[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
        <?php } ?>
          <div class="field">
            <div class="field-label"><?php print t('Title');  ?>:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_title[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <?php if(!empty($news_detail[$news_arr['value']]->field_news_kicker[LANGUAGE_NONE][0]['value'])) {?>
          <div class="field">
            <div class="field-label"><?php print t('Kicker');  ?>:</div>
            <div class="field-items"><?php echo ucwords($news_detail[$news_arr['value']]->field_news_kicker[LANGUAGE_NONE][0]['value']); ?></div>
          </div>
          <?php } ?>
          <?php if($news_detail[$news_arr['value']]->field_news_thumbnail[LANGUAGE_NONE][0]['uri']){ ?>
          <div class="field">
            <div class="field-label"><?php print t('Thumbnail');  ?>:</div>
            <div class="field-items"><img src="<?php echo $thumbnail; ?>" /></div>
          </div>
          <?php } ?>
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