<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Theme implementation for Blog form in display.
 */
?>
<div id="BlogBasicDetails">
  <h2 class="story-title">Basic Details</h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_blog_image']); ?>
  <?php print drupal_render($form['field_blog_short_description']); ?>
</div>
<div id="BlogDetails">
  <h2 class="story-title">Blog Description</h2>
  <?php print drupal_render($form['field_blog_long_description']); ?>
</div>
<div id="Bloggers">
  <h2 class="story-title">Bloggers Name</h2>
  <?php print drupal_render($form['field_blog_blogger']); ?>
</div>
<div id="categorySection">
  <h2 class="story-title">Section</h2>
  <?php print drupal_render($form['field_story_category']); ?>
</div>
<h2 id="title-metatags" class="story-title">Meta Tags</h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>