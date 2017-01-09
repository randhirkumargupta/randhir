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
  <h2 class="story-title"><?php print t('Basic Details'); ?></h2>
  <?php print drupal_render($form['field_recipe_content_type']); ?>
  <?php print drupal_render($form['field_recipe_video']); ?>
  <?php print drupal_render($form['field_recipe_audio']); ?>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_recipe_long_headline']); ?>
  <?php print drupal_render($form['field_story_reporter']); ?>
  <?php print drupal_render($form['field_story_courtesy']); ?>
  <?php print drupal_render($form['field_recipe_ingredients']); ?>
  <?php print drupal_render($form['field_recipe_garnishing']); ?>
  <?php print drupal_render($form['field_associate_photo_gallery']); ?>

  
</div>

<div id="RecipeDetails">
  <h2 class="story-title"><?php print t('Recipe Details'); ?></h2>
  <?php print drupal_render($form['field_recipe_food_type']); ?>
  <?php print drupal_render($form['field_recipe_cuisine_type']); ?>
  <?php print drupal_render($form['field_recipe_meal_for']); ?>
  <?php print drupal_render($form['field_recipe_calorie_type']); ?>
  <?php print drupal_render($form['field_recipe_calorie_count']); ?>
  <?php print drupal_render($form['field_recipe_time']); ?>
  <?php print drupal_render($form['field_recipe_ailment']); ?>
  <?php print drupal_render($form['field_recipe_meal_type']); ?>
  <?php print drupal_render($form['field_recipe_festivals']); ?>
  <?php print drupal_render($form['field_story_kicker_text']); ?>
  <?php print drupal_render($form['field_recipe_description']); ?>
</div>
<div id="RecipeImages">
  <h2 class="story-title"><?php print t('Recipe Images'); ?></h2>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <?php print drupal_render($form['field_story_large_image']); ?>
  <?php print drupal_render($form['field_story_medium_image']); ?>
  <?php print drupal_render($form['field_story_small_image']); ?>
     <?php print drupal_render($form['field_recipe_writer_image']); ?>
</div>
<div id="SocialMedia">
  <h2 class="story-title"><?php print t('Social Media'); ?></h2>
  <?php print drupal_render($form['field_story_social_media_integ']); ?>
  <!-- Facebook fields -->
  <?php print drupal_render($form['field_story_facebook_narrative']); ?>
  <?php print drupal_render($form['field_story_facebook_image']); ?>
  <?php print drupal_render($form['field_story_facebook_vdescripti']); ?>
  <?php print drupal_render($form['field_story_facebook_video']); ?>
  
  <!-- Twitter fields -->
  <?php print drupal_render($form['field_story_tweet']); ?>
  <?php print drupal_render($form['field_story_tweet_image']); ?>
  <?php print drupal_render($form['field_story_twitter_video_desc']); ?>
  <?php print drupal_render($form['field_story_twitter_video']); ?>
</div>
<div id="RecipeSyndication">
  <h2 class="story-title"><?php print t('Syndication'); ?></h2>
  <?php print drupal_render($form['field_story_syndication']); ?>
</div>

<div id="RecipeCategory">
  <h2 class="story-title"><?php print t('Recipe Category'); ?></h2>
  <?php print drupal_render($form['field_story_category']); ?>
   <?php print drupal_render($form['field_primary_cat_data']); ?>
  
</div>

<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>