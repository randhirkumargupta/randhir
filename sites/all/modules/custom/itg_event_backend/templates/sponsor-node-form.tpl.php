<?php
/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
?>

<div id="GalleryIndividualImages">
  <h2 class="story-title"><?php echo t('Basic Details'); ?></h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_sponser_logo']); ?> 
  <?php print drupal_render($form['body']); ?>
</div>

<!--<h2 id="title-metatags" class="story-title"><?php //echo t('SEO Meta Tags'); ?></h2>-->
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>
