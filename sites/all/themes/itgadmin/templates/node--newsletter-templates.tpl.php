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
      <?php 
        $logo = image_style_url("thumbnail", $node->field_newst_logo[LANGUAGE_NONE][0]['uri']);
        $banner = $node->field_newst_banner[LANGUAGE_NONE][0]['uri'];
       ?>

      <div class="field">
        <div class="field-label"><?php print t('Template Name:'); ?></div>
        <div class="field-items"><?php echo ucwords($node->title); ?></div>
      </div>
      <div class="field">
        <div class="field-label"><?php print t('Subject Line:'); ?></div>
        <div class="field-items"><?php echo ucwords($node->field_news_title[LANGUAGE_NONE][0]['value']); ?></div>
      </div>
       <div class="field">
        <div class="field-label"><?php print t('Header Headline:'); ?></div>
        <div class="field-items"><?php echo ucwords($node->field_newst_header_headline[LANGUAGE_NONE][0]['value']); ?></div>
      </div>
      <?php if(!empty($node->field_newst_main_headline[LANGUAGE_NONE][0]['value'])) { ?>
       <div class="field">
        <div class="field-label"><?php print t('Main Headline:'); ?></div>
        <div class="field-items"><?php echo ucwords($node->field_newst_main_headline[LANGUAGE_NONE][0]['value']); ?></div>
      </div>
      <?php } if($node->field_newst_logo[LANGUAGE_NONE][0]['uri']) { ?>
       <div class="field">
        <div class="field-label"><?php print t('Logo:'); ?></div>
        <div class="field-items"><img src="<?php echo $logo; ?>"></div>
      </div>
      <?php } ?>
       <div class="field">
        <div class="field-label"><?php print t('Banner:'); ?></div>
        <div class="field-items"><img src="<?php echo str_replace('public://', $base_url.'/sites/default/files/', $banner ); ?>" alt="" width="100" height="100"/></div>
      </div>
      <?php if($node->body[LANGUAGE_NONE][0]['value']) { ?>
      <div class="field">
        <div class="field-label"><?php print t('Footer:'); ?></div>
        <div class="field-items"><?php echo $node->body[LANGUAGE_NONE][0]['value']; ?></div>
      </div>
      <?php } ?>
 </div>   
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>