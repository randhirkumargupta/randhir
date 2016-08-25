<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
      <?php if ($view_mode == 'full'): ?>
      <?php //print render($content['links']['flag']); ?>
        <a href="javascript:;" class="close-preview">&nbsp;</a>
        <?php
        // Load custom block for social media integration 
        global $user;        
        if (!isset($node->op) && in_array('Social Media', $user->roles)):
          $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
          ?>
          <div class="itg-smi">
              <button data-id="smi-popup" class="btn data-popup-link">Promote Content</button>
          </div>
          <div id="smi-popup" class="itg-popup">
              <div class="popup-content">
                <div class="popup-head">
                    <div class="popup-title">&nbsp;</div>
                    <a class="itg-close-popup" href="javascript:;"> Close </a>
                </div>
                <div class="popup-body">
                    <?php print render($block['content']); ?>
                </div>
              </div>
          </div>
        <?php endif; ?>        
        <div class="basic-details content-box">
            <h2><?php print t('Quick File'); ?></h2>
            <div class="content-details">
                <?php print render($content['field_story_magazine_story_issue']); ?>
                <?php print render($content['field_story_select_magazine']); ?>
                <?php print render($content['field_story_select_supplement']); ?>
                <?php print render($content['field_story_issue_date']); ?>
                <div class="field">
                    <div class="field-label"><?php print t('Long headline:'); ?></div>
                    <div class="field-items"><?php print $title; ?></div>
                </div>

                <?php print render($content['field_story_redirection_url']); ?>
               
                <?php print render($content['field_story_redirection_url_titl']); ?>
                <?php print render($content['field_story_magazine_headline']); ?>
                <?php print render($content['field_story_magazine_kicker_text']); ?>
                <?php
                $story_kicker = $content['field_story_kicker_text'];
                if (!empty($story_kicker)):
                  print render($content['field_story_kicker_text']);
                endif;
                ?>
                <?php print render($content['field_stroy_city']); ?>
                <?php print render($content['field_story_category']); ?>
                <?php
                $extra_large = $content['field_story_extra_large_image'];
                if (!empty($extra_large)):
                  print render($content['field_story_extra_large_image']);
                endif;
                ?>
                <?php print render($content['field_story_itg_tags']); ?>
                <?php print render($content['field_story_courtesy']); ?>
                <?php print render($content['field_story_reporter']); ?>
                <div class="field field-name-field-story-body">
                    <div class="field-label">Story Body:&nbsp;</div>
                    <div class="field-items">
                        <div class="field-item even"><?php print render($content['body']); ?></div>
                    </div>
                </div>

            </div>
        </div>
        <?php
        $short_headline = render($content['field_story_short_headline']);
        if (!empty($short_headline)):
          ?>
          <div class="expert-details content-box">
              <h2><?php print t('More Details'); ?></h2>
              <div class="content-details">
                  <?php print render($content['field_story_short_headline']); ?>
                  <?php print render($content['field_story_long_head_line']); ?>
                  <?php print render($content['field_story_new_title']); ?>
                  <?php print render($content['field_story_rating']); ?>
                  <?php print render($content['field_story_redirection_url_titl']); ?>
                  <?php print render($content['field_story_courtesy']); ?>
                  <?php print render($content['field_story_snap_post']); ?>

              </div>  
          </div>
        <?php endif; ?>

        <?php
        $social_media = render($content['field_story_social_media_integ']);
        if (!empty($social_media)):
          ?>
          <div class="SocialMedia content-box">
              <h2><?php print t('Social Media'); ?></h2>
              <div class="content-details"><?php print render($content['field_story_social_media_integ']); ?>                  
                  <?php foreach ($node->field_story_social_media_integ['und'] as $value): ?>
                    <?php
                    switch ($value['value']) {
                      case 'facebook':
                        print render($content['field_story_facebook_narrative']);
                        print render($content['field_story_facebook_image']);
                        print render($content['field_story_facebook_vdescripti']);
                        print render($content['field_story_facebook_video']);

                        break;
                      case 'twitter':
                        print render($content['field_story_tweet']);
                        print render($content['field_story_tweet_image']);
                        print render($content['field_story_twitter_video_desc']);
                        print render($content['field_story_twitter_video']);                        
                    }
                    ?>
                  <?php endforeach; ?>
              </div>
          </div>
        <?php endif; ?>

        <?php
        $configuration = render($content['field_story_configurations']);
        if (!empty($configuration)):
          ?>
          <div class="configuration content-box">
              <h2><?php print t('Configuration'); ?></h2>
              <div class="content-details"><?php print render($content['field_story_configurations']); ?>
                  <?php //print render($content['field_story_client_title']); ?>
                  <?php print render($content['field_story_media_files_syndicat']); ?>
              </div>
          </div>

        <?php endif; ?>
        <?php
        $comment_question = render($content['field_story_configurations']);
        if (!empty($comment_question)):
          ?>
          <div class="Comment content-box">
              <div class="content-details"><?php print render($content['field_story_comment_question']); ?>
              </div>
          </div>
        <?php endif; ?>

        <div class="Story-details">
            <h2><?php print t('Date & Time'); ?></h2>
            <div class="content-details">
                <?php print render($content['field_story_schedule_date_time']); ?>
                <?php $story_exp_chk = $content['field_story_expires']['#items']['0']['value']; ?>
                <?php
                if (!empty($story_exp_chk)):
                  print render($content['field_story_expiry_date']);
                endif;
                ?>

            </div>
        </div>

        <?php
        $templates = render($content['field_story_templates']);
        if (!empty($templates)):
          ?>
          <div class="Templates">
              <h2><?php print t('Templates'); ?></h2>

              <div class="content-details">
                  <?php print render($content['field_story_templates']); ?>
                  <?php $vr = $content['field_story_templates']['#items']['0']['value']; ?>    
                  <?php $fr = $node->field_story_template_guru[LANGUAGE_NONE]; ?>
                  <div class="field">
                      <div class="field-label"><?php
                          if (!empty($fr)):
                            print t('Templates Guru:');
                          endif;
                          ?> </div>
                      <div class="field-items">
                          <?php if ($vr == 'bullet_points'): ?>
                            <ul>
                                <?php foreach ($fr as $key => $val): ?>                
                                  <li><?php print $val['value']; ?></li>
                                <?php endforeach; ?>
                            </ul>
                          <?php endif; ?>
                          <?php if ($vr == 'number_list'): ?>
                            <ol>
                                <?php foreach ($fr as $key => $val): ?>
                                  <li><?php print $val['value']; ?></li> 
                                <?php endforeach; ?>
                            </ol>
                          <?php endif; ?>
                      </div>
                  </div>
                  <div class="quotes"><?php print render($content['field_story_template_quotes']); ?></div>
                  <div class="factoids"><?php print render($content['field_story_template_factoids']); ?></div>
              </div>
          </div>
        <?php endif; ?>

        <?php
        $buzz_output.= '';
        foreach ($node->field_story_template_buzz['und'] as $buzz_item):
          $buzz_img_fid = $buzz_item['field_buzz_image']['und'][0]['fid'];
          $buzz_output.= '<div class="buzz-section">';
          if ($buzz_img_fid != NULL || $buzz_img_fid != ''):
            $buzz_imguri = _itg_photogallery_fid($buzz_img_fid);
            $img = '<img src="' . image_style_url("thumbnail", $buzz_imguri) . '">';
          endif;
          $buzz_output.= '<div class="field"><div class="field-label">Headline:</div><div class="field-items">' . $buzz_item['field_buzz_headline']['und'][0]['value'] . '</div></div>';
          $buzz_output.= '<div class="field"><div class="field-label">Image:</div><div class="field-items">' . $img . '</div></div>';
          $buzz_output.= '<div class="field"><div class="field-label">Description:</div><div class="field-items">' . $buzz_item['field_buzz_description']['und'][0]['value'] . '</div></div>';
          $buzz_output.= '</div>';
        endforeach;
        ?>
        <?php if (!empty($buzz_item['field_buzz_headline']['und'][0]['value'])): ?>
          <div class="Templates-buzz">
              <h2><?php print t('Templates Buzz'); ?></h2>

              <div class="content-details">
                  <?php print $buzz_output; ?>
              </div>
          </div>
        <?php endif; ?>
        <?php
        $expert = render($content['field_story_expert_name']);
        if (!empty($expert)):
          ?>
          <div class="expert-details content-box">
              <h2><?php print t('Expert Chunk'); ?></h2>
              <div class="content-details">
                  <?php print render($content['field_story_expert_name']); ?>
                  <?php print render($content['field_story_expert_image']); ?>
                  <?php print render($content['field_story_expert_description']); ?>
              </div>  
          </div>
        <?php endif; ?>
            <?php
            $highlight = render($content['field_story_highlights']);
            if (!empty($highlight)):
              ?>
              <div class="expert-details content-box">
                  <h2><?php print t('Brief case'); ?></h2>
                  <div class="content-details">
                      <?php
                      $h_count = 1;
                      foreach ($node->field_story_highlights['und'] as $high) {
                        print '<div class="field"><div class="field-label">'.$h_count.':</div><div class="field-items">'.$high['value'].'</div></div>';
                        $h_count++;
                      }
                      ?>
                  </div>  
              </div>
            <?php endif; ?>
      <?php endif; // end of view mode full condition ?></div>
  <?php
  // code for comment hide and show based on condition
  if ($node->field_story_configurations[LANGUAGE_NONE][0]['value'] == 'comment') {
    print render($content['comment_form']);
    print render($content['comments']);
  }
  ?>
<?php endif; ?>