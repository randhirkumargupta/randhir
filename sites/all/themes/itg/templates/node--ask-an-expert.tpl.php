<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
    <header>
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($display_submitted): ?>
        <p class="submitted">
          <?php print $user_picture; ?>
          <?php print $submitted; ?>
        </p>
      <?php endif; ?>

      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    //print render($content);
    
    ?>
   <div class="field field-name-field-user-name field-type-text field-label-inline clearfix"><div class="field-label">Question:&nbsp;</div><div class="field-items"><div class="field-item even"><?php print $title; ?></div></div></div>
   <?php
   // get identity value of ask an expert front end user
   $identity = $content['field_user_name']['#object']->field_disclose_your_identity[LANGUAGE_NONE]['0']['value'];
   if (!empty($identity)) {
     print render($content['field_user_name']);
     print render($content['field_user_email']);
   }
   print render($content['field_user_city']);
   print render($content['field_user_state']);
   print '<div class="field-label"><strong>Post date:</strong>&nbsp;</div><div class="field-items">'.format_date($node->created, 'ask_an_expert').'</div>';
   ?>
  <?php print render($content['field_user_message']);?>
  
  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
