<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
    <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      <div class='column-side'><div class='column-wrapper'>
            <?php endif; ?>

            <?php if (!empty($submitted)): ?>
              <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
            <?php endif; ?>
            <!-- add && !$teaser for hide comment link -->
            <?php if (!empty($links) && !$teaser): ?>
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
                  <?php
                  //print render($content) 
                  // print '<pre>';
                  //print_r($content);
                  //print '</pre>';
                  ?>

                  <?php if ($view_mode == 'full'): ?>
                    <div class="basic-details">
                        <h1><u>Basic Details</u></h1>

                        <div><?php print render($content['field_story_magazine_story_issue']); ?></div>
                        <div><?php print render($content['field_story_select_magazine']); ?></div>
                        <div><?php print render($content['field_story_select_supplement']); ?></div>
                        <div><?php print render($content['field_story_long_head_line']); ?></div>
                        <div class="field-label-new">Story Title:</div> <div><?php print $title; ?></div>
                        <div><?php print render($content['field_story_short_headline']); ?></div>
                        <div><?php print render($content['field_story_redirection_url']); ?></div>
                        <div><?php print render($content['field_story_new_title']); ?></div>
                        <div><?php print render($content['field_story_redirection_url_titl']); ?></div>
                        <div><?php print render($content['field_story_magazine_headline']); ?></div>
                        <div><?php print render($content['field_story_magazine_kicker_text']); ?></div>
                        <div><?php print render($content['field_stroy_city']); ?></div>
                        <div><?php print render($content['field_story_courtesy']); ?></div>
                        <div><?php print render($content['field_story_reporter']); ?></div>

                    </div>
                    <div class="expert-details">
                        <h1><u>Expert Details</u></h1>
                        <div><?php print render($content['field_story_expert_name']); ?></div>
                        <div><?php print render($content['field_story_expert_image']); ?></div>
                        <div><?php print render($content['field_story_expert_description']); ?></div>

                    </div>

                    <div class="story-content">
                        <h1><u>Story Content</u></h1>
                        <?php print render($content['body']); ?>

                    </div>
                    <div class="configuration">
                        <h1><u>Configuration</u></h1>
                        <?php print render($content['field_story_configurations']); ?>
                    </div>
                    <div class="configuration">
                        <h1><u>Comment Question</u></h1>
                        <?php print render($content['field_story_comment_question']); ?>
                    </div>

                    <div class="SocialMedia">
                        <h1><u>Social Media</u></h1>
                        <?php print render($content['field_story_social_media_integ']); ?>
                    </div>

                    <div class="Facebook-narretive">
                        <h1><u>Facebook Narrative </u></h1>
                        <?php print render($content['field_story_facebook_narrative']); ?>
                        <?php print render($content['field_story_facebook_image']); ?>
                    </div>

                    <div class="Twitter">
                        <h1><u>Twitter</u></h1>
                        <?php print render($content['field_story_tweet']); ?>
                    </div>

                    <div class="BrowseMedia">
                        <h1><u>BrowseMedia</u></h1>
                        <?php print render($content['field_story_extra_large_image']); ?>
                        <?php print render($content['field_story_large_image']); ?>
                        <?php print render($content['field_story_medium_image']); ?>
                        <?php print render($content['field_story_small_image']); ?>
                        <?php print render($content['field_story_extra_small_image']); ?>

                    </div>

                    <div class="Templates">
                        <h1><u>Templates</u></h1>
                        <?php print render($content['field_story_templates']); ?>
                        <?php print render($content['field_story_template_guru']); ?>
                        <?php print render($content['field_story_template_quotes']); ?>
                        <?php print render($content['field_story_template_factoids']); ?>

                    </div>
                    <div class="Templates-buzz">
                        <h1><u>Templates Buzz</u></h1>
                        <?php print render($content['field_story_template_buzz']); ?>
                        <?php print render($content['field_story_template_buzz_field_buzz_image']); ?>
                        <?php print render($content['field_buzz_description']); ?>

                    </div>
                    <div class="Story-details">
                        <h1><u>Story Details</u></h1>
                        <?php print render($content['field_story_expiry_date']); ?>
                        <?php print render($content['field_story_rating']); ?>
                        <?php print render($content['field_story_kicker_text']); ?>
                        <?php print render($content['field_story_category']); ?>
                    </div>
                  <?php endif; ?>
              </div>
            <?php endif; ?>

            <?php if ($layout): ?>
          </div></div>
    <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>
