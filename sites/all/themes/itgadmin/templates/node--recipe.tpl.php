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
          <?php print render($links) ?>
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
          <?php //print render($content)  ?>            
          <?php if ($view_mode == 'full'): ?>
            <div class="content-node-view">
              <h2><?php print t('Basic Details'); ?></h2>              
              <?php
              // Load custom block for social media integration              
              if (!isset($node->op)) {
                echo '<div class="itg_smi">'. l(t('Create Social media'), 'itg-social-media/edit-content/'.$node->type.'/'.$node->nid, array('attributes' => array('class' => 'button'))) .'</div>';
                $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
                print render($block['content']);
              }              
              ?>
              <div class="content-details">
                <div class="field">
                  <div class="field-label"><?php print t('Strap headline (Short Headline)'); ?></div>
                  <div class="field-items"><?php print $title; ?></div>
                </div>

                <?php
                $content_type = render($content['field_recipe_content_type']);
                if (!empty($content_type)):
                  print render($content['field_recipe_content_type']);
                  ?>
                <?php endif; ?>
                <?php
                $type_audio = render($content['field_recipe_audio']);
                if (!empty($type_audio)):
                  print render($content['field_recipe_audio']);
                  ?>
                <?php endif; ?>
                <?php
                $type_video = render($content['field_recipe_video']);
                if (!empty($type_video)):
                  print render($content['field_recipe_video']);
                  ?>
                <?php endif; ?>
                <?php
                $food_type = render($content['field_recipe_food_type']);
                if (!empty($food_type)):
                  print render($content['field_recipe_food_type']);
                  ?>
                <?php endif; ?>
                <?php
                $long_headline = render($content['field_recipe_long_headline']);
                if (!empty($long_headline)):
                  print render($content['field_recipe_long_headline']);
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
                $courtesy = render($content['field_story_courtesy']);
                if (!empty($courtesy)):
                  print render($content['field_story_courtesy']);
                  ?>
                <?php endif; ?>
                <?php
                $ingredients = render($content['field_recipe_ingredients']);
                if (!empty($ingredients)):
                  print str_replace("<br />" , ",", nl2br(render($content['field_recipe_ingredients'])));
                  ?> 
                <?php endif; ?>
                <?php
                $garnishing = render($content['field_recipe_garnishing']);
                if (!empty($garnishing)):
                  print str_replace("<br />" , ",", nl2br(render($content['field_recipe_garnishing'])));
                  ?> 
                <?php endif; ?>
                <?php
                $photo_gallery = render($content['field_associate_photo_gallery']);
                if (!empty($photo_gallery)):
                  print render($content['field_associate_photo_gallery']);
                  ?> 
                <?php endif; ?>
              </div>
            </div>

            <div class="content-node-view">
              <h2><?php print t('Recipe Details'); ?></h2>
              <div class="content-details">
                <?php
                $cuisine_type = render($content['field_recipe_cuisine_type']);
                if (!empty($cuisine_type)):
                  print render($content['field_recipe_cuisine_type']);
                  ?>
                <?php endif; ?>
                <?php
                $meal_for = render($content['field_recipe_meal_for']);
                if (!empty($meal_for)):
                  print render($content['field_recipe_meal_for']);
                  ?>
                <?php endif; ?>
                <?php
                $calorie_type = render($content['field_recipe_calorie_type']);
                if (!empty($calorie_type)):
                  print render($content['field_recipe_calorie_type']);
                  ?>
                <?php endif; ?>
                <?php
                $calorie_count = render($content['field_recipe_calorie_count']);
                if (!empty($calorie_count)):
                  print render($content['field_recipe_calorie_count']);
                  ?>
                <?php endif; ?>
                <?php
                $time = render($content['field_recipe_time']);
                if (!empty($time)):
                  print render($content['field_recipe_time']);
                  ?>
                <?php endif; ?>
                <?php
                $ailment = render($content['field_recipe_ailment']);
                if (!empty($ailment)):
                  print render($content['field_recipe_ailment']);
                  ?>
                <?php endif; ?>
                <?php
                $meal_type = render($content['field_recipe_meal_type']);
                if (!empty($meal_type)):
                  print render($content['field_recipe_meal_type']);
                  ?>
                <?php endif; ?>
                <?php
                $festivals = render($content['field_recipe_festivals']);
                if (!empty($festivals)):
                  print render($content['field_recipe_festivals']);
                  ?>
                <?php endif; ?>
                <?php
                $description = render($content['field_recipe_description']);
                if (!empty($description)):
                  print render($content['field_recipe_description']);
                  ?>
                <?php endif; ?>
              </div>
            </div>

            <?php
            $browsemediaextralarge = render($content['field_story_extra_large_image']);
            $browsemedialarge = render($content['field_story_large_image']);
            $browsemediamedium = render($content['field_story_medium_image']);
            $browsemediasmall = render($content['field_story_small_image']);
            $browsemediawriter = render($content['field_recipe_writer_image']);
            if (!empty($browsemediaextralarge) || !empty($browsemedialarge) || !empty($browsemediamedium) || !empty($browsemediasmall) || !empty($browsemediawriter)):
              ?>
              <div class="content-node-view">
                <h2><?php print t('Recipe Images'); ?></h2>
                <div class="content-details">
                  <?php print render($content['field_story_extra_large_image']); ?>
                  <?php print render($content['field_story_large_image']); ?>
                  <?php print render($content['field_story_medium_image']); ?>
                  <?php print render($content['field_story_small_image']); ?>
                  <?php print render($content['field_recipe_writer_image']); ?>
                </div>
              </div>
            <?php endif; ?>
          
          <?php 
            $social_media = render($content['field_story_social_media_integ']);
             if(!empty($social_media)):?>
              <div class="SocialMedia content-box">
                <h2><?php print t('Social Media'); ?></h2>
                <div class="content-details"><?php print render($content['field_story_social_media_integ']); ?></div>
              </div>
            <?php endif;?>
             <?php 
              $facebook_narrative = render($content['field_story_facebook_narrative']);
              if(!empty($facebook_narrative)):?>
                <div class="Facebook-narretive content-box">
                  <h2><?php print t('Facebook Narrative'); ?></h2>
                  <div class="content-details">
                    <?php print render($content['field_story_facebook_narrative']); ?>
                    <?php print render($content['field_story_facebook_image']); ?>
                  </div>
                </div>
             <?php endif;?>
            <?php 
              $twitter = render($content['field_story_tweet']);
              if(!empty($twitter)):?>
                <div class="Twitter content-box">
                  <h2><?php print t('Twitter'); ?></h2>
                  <div class="content-details">
                    <?php print render($content['field_story_tweet']); ?>
                  </div>
                </div>
            <?php endif;?>
          
            <div class="content-node-view">
              <h2><?php print t('Syndication'); ?></h2>
              <div class="content-details">      
                <?php
                $syndication = render($content['field_recipe_syndication']);
                ?>
               
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
              </div>

            </div>
            <div class="content-node-view">
              <h2><?php print t('Recipe Section'); ?></h2>
              <div class="content-details">
                <?php
                $section = render($content['field_story_category']);
                if (!empty($section)):
                  ?>    
                  <?php print render($content['field_story_category']); ?>
                <?php endif; ?>
              </div>
            </div>
            <?php
          // end of view mode full condition
          endif;
          ?>

        </div>
      <?php endif; ?>

      <?php if ($layout): ?>
      </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object)  ?>