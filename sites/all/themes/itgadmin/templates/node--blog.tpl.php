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
          <?php //print render($links) ?>
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
<!--        <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
          <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
          <a href="<?php print $node_url ?>"><?php print $title ?></a>
          
        </h2>-->
      <?php endif; ?>

      <?php if (!empty($title_suffix)) print render($title_suffix); ?>

      <?php if (!empty($content)): ?>
        <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
          <?php //print render($content) ?>

          <?php if ($view_mode == 'full'): ?>
            <div class="content-node-view">
              <h2><?php print t('Basic Details'); ?></h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label"><?php print t('Title'); ?></div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>

                <?php
                $browsemedialarge = render($content['field_blog_image']);
                if (!empty($browsemedialarge)) :
                  ?>
                  <?php print render($content['field_story_extra_large_image']); ?>

                <?php endif; ?>
                <?php
                $short_description = render($content['field_blog_short_description']);
                if (!empty($short_description)):
                  print render($content['field_blog_short_description']);
                  ?>
                <?php endif; ?>
              </div></div>
              <div class="content-node-view">
                <h2><?php print t('Blog Description'); ?></h2>
                <div class="content-details">      
                  <?php
                  $long_description = render($content['field_blog_long_description']);
                  if (!empty($long_description)):
                    print render($content['field_blog_long_description']);
                    ?>
                  <?php endif; ?>
                </div>
              </div>
              <div class="content-node-view">
                <h2><?php print t('Bloggers'); ?></h2>
                <div class="content-details">
                  <?php
                  $bloggers = render($content['field_blog_bloggers']);
                  if (!empty($bloggers)):
                    print render($content['field_blog_bloggers']);
                    ?>
                  <?php endif; ?>
                </div>
              </div>

              <div class="content-node-view">
                <h2><?php print t('Sections'); ?></h2>
                <div class="content-details">
                  <?php
                  $selection = render($content['field_story_category']);
                  if (!empty($selection)):
                    print render($content['field_story_category']);
                    ?>
                  <?php endif; ?>
                  </div>
                </div>
     
          <?php endif; ?>
            <?php 
            print render($content['comment_form']);
            print render($content['comments']);
            ?>
        </div>
      <?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
