<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * Theme implementation for Blog form in display.
 */
?>
<div id="BlogBasicDetails">
  <h2 class="story-title"><?php print t('Basic Details'); ?></h2>
  <?php print drupal_render($form['title']); ?>
  <?php print drupal_render($form['field_story_extra_large_image']); ?>
  <?php print drupal_render($form['field_common_short_description']); ?>
</div>
<div id="BlogDetails">
  <h2 class="story-title"><?php print t('Blog Description'); ?></h2>
  <?php print drupal_render($form['field_blog_long_description']); ?>
</div>
<div id="Bloggers">
  <h2 class="story-title"><?php print t('Bloggers Name'); ?></h2>
  <?php print drupal_render($form['field_blog_bloggers']); ?>
</div>
<div id="categorySection">
  <h2 class="story-title"><?php print t('Section'); ?></h2>
  <?php print drupal_render($form['field_story_category']); ?>
  <?php print drupal_render($form['field_primary_cat_data']); ?>
  <?php print drupal_render($form['category_holder']); ?>
</div>
<div id="configuration">
  <h2 class="story-title"><?php print t('Configurations'); ?></h2>
  <?php print drupal_render($form['field_blog_configuration']); ?>
  <?php print drupal_render($form['field_story_comment_question']); ?>
</div>
<!--<div id="Relatedcontent">
  <h2 class="story-title">Related content</h2>
  <?php //print drupal_render($form['field_common_related_content']); ?>
</div>-->
<h2 id="title-metatags" class="story-title"><?php print t('Remarks'); ?></h2>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>