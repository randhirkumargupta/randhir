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
                <?php
                $long_headline = render($content['field_recipe_long_headline']);
                if (!empty($long_headline)):
                  print render($content['field_recipe_long_headline']);
                  ?>
                <?php endif; ?>
                <?php
                $strap = render($content['field_story_short_headline']);
                if (!empty($strap)):
                  print render($content['field_story_short_headline']);
                  ?>
                <?php endif; ?>
                <?php
                $kicker = render($content['field_story_kicker_text']);
                if (!empty($kicker)):
                  print render($content['field_story_kicker_text']);
                  ?>
                <?php endif; ?>
               <?php
                $byline = render($content['field_story_reporter']);
                if (!empty($byline)):
                  print render($content['field_story_reporter']);
                  ?>
                <?php endif; ?>
                <?php
                $byline = render($content['field_stroy_city']);
                if (!empty($byline)):
                  print render($content['field_stroy_city']);
                  ?>
                <?php endif; ?>
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
            $browsemediawriter = render($content['field_recipe_writer_image']);
            if (!empty($browsemediaextralarg) || !empty($browsemedialarg) || !empty($browsemediamediu) || !empty($browsemediasmal)|| !empty($browsemediawriter)):
              ?>
              <div class="content-node-view">
                <h2><?php print t('Browse Media'); ?></h2>
                <div class="content-details">
                  <?php print render($content['field_story_extra_large_image']); ?>
                  <?php print render($content['field_story_large_image']); ?>
                  <?php print render($content['field_story_medium_image']); ?>
                  <?php print render($content['field_story_small_image']); ?>
                  <?php print render($content['field_recipe_writer_image']); ?>
                </div>
              </div>
            <?php endif; ?>

            <div class="content-node-view">
              <h2><?php print t('Syndication'); ?></h2>
              <div class="content-details">      
                <?php
                $syndication = render($content['field_recipe_syndication']);
                ?>

                <?php if (!empty($syndication)): ?>
                  <div class="description-details content-box">
                    <?php if (!empty($syndication)): ?>
                      <div class="breaking-content-details">
                       <div class="field">
                         <div class="field-label">Syndication: </div>
                         <div class="field-items"><?php print ('yes'); ?></div>
                       </div>
                     </div>
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
                <?php endif; ?>
                </div>
              </div>
            
        <?php endif; ?>
      </div>
    <?php endif; ?>

    <?php if ($layout): ?>
    </div></div>
<?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>




