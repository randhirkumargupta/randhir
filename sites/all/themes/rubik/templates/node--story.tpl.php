<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>
<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
      <?php endif; ?>

      <?php if (!empty($submitted)): ?>
<!--        <div class='<?php print $hook ?>-submitted clearfix'><?php //print $submitted ?></div>-->
      <?php endif; ?>
        <?php
        //p($node);
        echo $node->moderation_history_block;
        ?>
      <!-- add && !$teaser for hide comment link -->
      <?php if (!empty($links) && !$teaser): ?>
        <div class='<?php print $hook ?>-links clearfix'>
          <?php print render($links) ?>
        </div>
      <?php endif; ?>

      <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
      </div>
    </div>
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
          <div class="basic-details content-box">
            <h2>Basic Details</h2>
            <div class="content-details">
              <?php print render($content['field_story_magazine_story_issue']); ?>
              <?php print render($content['field_story_select_magazine']); ?>
              <?php print render($content['field_story_select_supplement']); ?>
              <?php print render($content['field_story_long_head_line']); ?>
              <div class="field">
                <div class="field-label">Story Title:</div>
                <div class="field-items"><?php print $title; ?></div>
              </div>
              <?php print render($content['field_story_short_headline']); ?>
              <?php print render($content['field_story_redirection_url']); ?>
              <?php print render($content['field_story_new_title']); ?>
              <?php print render($content['field_story_redirection_url_titl']); ?>
              <?php print render($content['field_story_magazine_headline']); ?>
              <?php print render($content['field_story_magazine_kicker_text']); ?>
              <?php print render($content['field_stroy_city']); ?>
              <?php print render($content['field_story_courtesy']); ?>
              <?php print render($content['field_story_reporter']); ?>
            </div>
          </div>
             <?php 
              $expert = render($content['field_story_expert_name']); 
              if(!empty($expert)):?>
          <div class="expert-details content-box">
            <h2>Expert Details</h2>
            <div class="content-details">
              <?php print render($content['field_story_expert_name']); ?>
              <?php print render($content['field_story_expert_image']); ?>
              <?php print render($content['field_story_expert_description']); ?>
            </div>  
          </div>
             <?php endif; ?>
          <div class="story-content content-box">
            <h2>Story Content</u></h2>
            <div class="content-details"><?php print render($content['body']); ?></div>

          </div>
            <?php 
              $configuration = render($content['field_story_configurations']); 
              if(!empty($configuration)):?>
          <div class="configuration content-box">
            <h2>Configuration</h2>
            <div class="content-details"><?php print render($content['field_story_configurations']); ?>
            <?php print render($content['field_story_rating']); ?>
            <?php print render($content['field_story_client_title']); ?>
            <?php print render($content['field_story_media_files_syndicat']); ?>
            </div>
          </div>
            
             <?php endif; ?>
            <?php 
              $comment_question = render($content['field_story_configurations']);
              if(!empty($comment_question)):?>
          <div class="Comment content-box">
            <h2>Comment Question</h2>
            <div class="content-details"><?php print render($content['field_story_comment_question']); ?>
            </div>
          </div>
            <?php endif; ?>
            <?php 
            $social_media = render($content['field_story_social_media_integ']);
             if(!empty($social_media)):?>
          <div class="SocialMedia content-box">
            <h2>Social Media</h2>
            <div class="content-details"><?php print render($content['field_story_social_media_integ']); ?></div>
          </div>
            <?php endif;?>
             <?php 
              $facebook_narrative = render($content['field_story_facebook_narrative']);
              if(!empty($facebook_narrative)):?>
          <div class="Facebook-narretive content-box">
            <h2>Facebook Narrative</h2>
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
            <h2>Twitter</h2>
            <div class="content-details"><?php print render($content['field_story_tweet']); ?></div>
          </div>
            <?php endif;?>
            <?php 
            $browsemedia = render($content['field_story_extra_large_image']);  
            if(!empty($browsemedia)):?>
          <div class="BrowseMedia">
            <h2>BrowseMedia</h2>
            <div class="content-details">
            <?php print render($content['field_story_extra_large_image']); ?>
            <?php print render($content['field_story_large_image']); ?>
            <?php print render($content['field_story_medium_image']); ?>
            <?php print render($content['field_story_small_image']); ?>
            <?php print render($content['field_story_extra_small_image']); ?>
            </div>
          </div>
           <?php endif;?>
           <?php 
           $templates = render($content['field_story_templates']);
           if(!empty($templates)):?>
          <div class="Templates">
            <h2>Templates</h2>
            
            <div class="content-details">
            <?php print render($content['field_story_templates']); ?>
            <?php $vr=$content['field_story_templates']['#items']['0']['value'];  ?>    
            <?php $fr= $node->field_story_template_guru[LANGUAGE_NONE]; ?>
            <div class="field">
              <div class="field-label">Templates Guru: </div>
              <div class="field-items">
            <?php if($vr == 'bullet_points') { ?>
                <ul>
            <?php
            foreach($fr as $key => $val){ ?>
                
            <li><?php print $val['value']; ?></li>  
            
            <?php } } ?>
                </ul>
                
            <?php if($vr == 'number_list') {?>
                <ol>
            <?php foreach($fr as $key => $val){ ?>
                                    
             <li><?php print $val['value']; ?></li> <?php } }?>
                       
                </ol>
              </div>
            </div>
             <div class="quotes"><?php print render($content['field_story_template_quotes']); ?></div>
             <div class="factoids"><?php print render($content['field_story_template_factoids']); ?></div>
            </div>
          </div>
            <?php endif;?>
            <div class="Templates-buzz">
            <h2>Templates Buzz</h2>
            <div class="content-details">
            <?php print render($content['field_story_template_buzz']); ?>
            <?php print render($content['field_story_template_buzz_field_buzz_image']); ?>
            <?php print render($content['field_buzz_description']); ?>
            </div>
          </div>
            <div class="Story-details">
            <h2>Story Details</h2>
            <div class="content-details">
            <?php print render($content['field_story_expiry_date']); ?>
            <?php print render($content['field_story_kicker_text']); ?>
            <?php print render($content['field_story_itg_tags']); ?>
            <?php print render($content['field_story_category']); ?>
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