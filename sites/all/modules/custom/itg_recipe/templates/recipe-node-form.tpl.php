<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * @file
 * Theme implementation for Recipe form in display.
 */
?>

<div id="RecipeBasicDetails">
  <h2 class="story-title">Basic Details</h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_recipe_content_type']); ?>
  <?php print drupal_render($form['field_recipe_video']); ?>
  <?php print drupal_render($form['field_recipe_audio']); ?>
  <?php print drupal_render($form['field_recipe_strap_headline']); ?>
  <?php print drupal_render($form['field_recipe_long_headline']); ?>
  <?php print drupal_render($form['field_recipe_wap_headline']); ?>
  <?php print drupal_render($form['field_recipe_kicker_headline']); ?>
  <?php print drupal_render($form['field_story_reporter']); ?>
  <?php print drupal_render($form['field_story_courtesy']); ?>
  <?php print drupal_render($form['field_stroy_city']); ?>
</div>

<div id="RecipeDetails">
  <h2 class="story-title">Recipe Details</h2>
  <?php print drupal_render($form['field_recipe_description']); ?>
  <?php print drupal_render($form['field_recipe_cuisine_type']); ?>
  <?php print drupal_render($form['field_recipe_meal_for']); ?>
  <?php print drupal_render($form['field_recipe_calorie_type']); ?>
  <?php print drupal_render($form['field_recipe_calorie_count']); ?>
  <?php print drupal_render($form['field_recipe_time']); ?>
  <?php print drupal_render($form['field_recipe_ailment']); ?>
  <?php print drupal_render($form['field_recipe_meal_type']); ?>
  <?php print drupal_render($form['field_recipe_festivals']); ?>
  <?php print drupal_render($form['field_recipe_ingredient']); ?>
</div>
<div id="RecipeImages">
  <h2 class="story-title">Recipe Images</h2>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
  <?php print drupal_render($form['field_recipe_mobile_image']); ?>
</div>
<div id="RecipeSyndication">
  <h2 class="story-title">Syndication</h2>
  <?php print drupal_render($form['field_recipe_syndication']); ?>
  <?php print drupal_render($form['field_story_client_title']); ?>
</div>

<div id="RecipeSection">
  <h2 class="story-title">Recipe Section</h2>
  <?php print drupal_render($form['field_story_category']); ?>
</div>
<h2 id="title-metatags" class="story-title">Meta Tags</h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>