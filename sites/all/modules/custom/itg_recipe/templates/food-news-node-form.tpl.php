<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Theme implementation for Food News form in display.
 */
?>
<div id="RecipeBasicDetails">
  <h2 class="story-title"><?php print t('Basic Details'); ?></h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_recipe_long_headline']); ?>
  <?php print drupal_render($form['field_story_kicker_text']); ?>
  <?php print drupal_render($form['field_story_reporter']); ?>
  <?php print drupal_render($form['field_stroy_city']); ?>
  <?php print drupal_render($form['body']); ?>
</div>
<div id="RecipeImages">
  <h2 class="story-title"><?php print t('Food News Images'); ?></h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_recipe_writer_image']); ?>
</div>
<div id="RecipeSyndication">
  <h2 class="story-title"><?php print t('Syndication'); ?></h2>
  <?php print drupal_render($form['field_story_syndication']); ?>
</div>

<div id="RecipeSection">
  <h2 class="story-title"><?php print t('Section'); ?></h2>
  <?php print drupal_render($form['field_story_category']); ?>
   <?php print drupal_render($form['field_primary_cat_data']); ?>
</div>

<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>