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
          <?php // print render($links) ?>
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
          <?php // print render($content) ?>

          <?php if ($view_mode == 'full'): ?>
            <div class="content-node-view">
              <h2><?php print t('Basic Details'); ?></h2>
              <div class="content-details">
                <div class="field">
                  <div class="field-label"><?php print t('Title'); ?></div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>

                <div class="field"> 
                  <div class="field-label"><?php print t('Description'); ?></div>
                  <div class="field-items"><?php print render($content['body']); ?></div>
                </div> 
              </div></div>                            
            <?php
            $browsemediaextralarg = render($content['field_story_extra_large_image']);
            $browsemedialarg = render($content['field_story_large_image']);
            $browsemediamediu = render($content['field_story_medium_image']);
            $browsemediasmal = render($content['field_story_small_image']);
            if (!empty($browsemediaextralarg) || !empty($browsemedialarg) || !empty($browsemediamediu) || !empty($browsemediasmal)):
              ?>
              <div class="content-node-view">
                <h2><?php print t('Browse Media'); ?></h2>
                <div class="content-details">
                  <?php print render($content['field_story_extra_large_image']); ?>
                  <?php print render($content['field_story_large_image']); ?>
                  <?php print render($content['field_story_medium_image']); ?>
                  <?php print render($content['field_story_small_image']); ?>
                </div>
              </div>
            <?php endif; ?>

            <div class="content-node-view">
              <h2><?php print t('Syndication'); ?></h2>
              <div class="content-details">      
                <?php
                $syndication = render($content['field_recipe_syndication']);
                $client_title = render($content['field_story_client_title']);
                ?>

                <?php if (!empty($syndication) || !empty($client_title)): ?>
                  <div class="description-details content-box">

                    <?php if (!empty($client_title)): ?>
                      <div class="breaking-content-details"><?php print render($content['field_story_client_title']); ?></div> 
                    <?php endif; ?>
                  </div>
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
                </div>
              </div>
            <?php endif; ?>
          </div>

        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($layout): ?>
    </div></div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>



