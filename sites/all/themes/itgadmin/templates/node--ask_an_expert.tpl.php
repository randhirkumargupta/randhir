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
            <div class="field-label"><?php print t('Name :'); ?></div>
            <div class="field-items"><?php print $node->field_user_name[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
        
        <div class="field">
            <div class="field-label"><?php print t('Email :'); ?></div>
            <div class="field-items"><?php print $node->field_user_email[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
        
        <div class="field">
            <div class="field-label"><?php print t('City :'); ?></div>
            <div class="field-items"><?php print $node->field_user_city[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
        
        <div class="field">
            <div class="field-label"><?php print t('State :'); ?></div>
            <div class="field-items"><?php print $node->field_user_state[LANGUAGE_NONE][0]['value']; ?></div>
          </div>
        
        <?php $identity = $node->field_disclose_your_identity[LANGUAGE_NONE][0]['value']; 
        if($identity == '1') {
        ?> 
       
        <div class="field">
            <div class="field-label"><?php print t('Disclose Your Identity :'); ?></div>
            <div class="field-items"><?php print t("Yes"); ?></div>
          </div>
        <?php
        }
        ?>
        
    </div>
  <?php endif; ?>

  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

