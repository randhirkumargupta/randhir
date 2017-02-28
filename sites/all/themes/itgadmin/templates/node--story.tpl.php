<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
    <?php
    $promote_class = "";
    if (!isset($node->op) && in_array('Social Media', $user->roles)) {
      $promote_class = 'promote-content';
    }
    ?>
    <div class='<?php echo $promote_class; ?>'>
      <?php if ($view_mode == 'full'): ?>
        <?php print render($content['links']['flag']); ?>
        <a href="javascript:;" class="close-preview">&nbsp;</a>
        <?php
        // Load custom block for social media integration 
        global $user;
        ?>        
        <div class="basic-details content-box">
          <h2><?php
            $termdata = "";
            if ($node->field_primary_category['und'][0]['value'] != "" && isset($node->field_primary_category['und'])) {
              $termdata = itg_videogallery_get_term_name($node->field_primary_category['und'][0]['value']);
            }
            print t('Quick File');
            ?></h2>
          <div class="content-details">
            <?php print render($content['field_story_magazine_story_issue']); ?>
            <?php print render($content['field_story_select_magazine']); ?>
            <?php print render($content['field_story_select_supplement']); ?>
            <?php print render($content['field_story_issue_date']); ?>
            <div class="field">
              <div class="field-label"><?php print t('Long headline:'); ?></div>
              <div class="field-items"><?php print $title; ?></div>
            </div>
            <?php
            $emojy_position = $content['field_emoji_position']['#object']->field_emoji_position[LANGUAGE_NONE];
            if (isset($emojy_position) && is_array($emojy_position) && !empty($emojy_position)) {
              foreach ($emojy_position as $emogy_key => $emogy_val) {
                $emogy_pos[] = $emojy_position[$emogy_key]['value'];
              }
              if (in_array('left', $emogy_pos) && in_array('right', $emogy_pos)) {
                print "<div class='emogy-left'><span class='title'>Emogy Left:</span><span class='emogy-val'>" . $content['field_emoji_2']['#object']->field_emoji_2[LANGUAGE_NONE][0]['value'] . '</span></div>';
                print "<div class='emogy-right'><span class='title'>Emogy Right:</span><span class='emogy-val'>" . $content['field_emoji']['#object']->field_emoji[LANGUAGE_NONE][0]['value'] . '</span></div>';
              } else if (in_array('right', $emogy_pos)) {
                print "<div class='emogy-right'><span class='title'>Emogy Right:</span><span class='emogy-val'>" . $content['field_emoji']['#object']->field_emoji[LANGUAGE_NONE][0]['value'] . '</span></div>';
              } else if (in_array('left', $emogy_pos)) {
                print "<div class='emogy-left'><span class='title'>Emogy Left:</span><span class='emogy-val'>" . $content['field_emoji_2']['#object']->field_emoji_2[LANGUAGE_NONE][0]['value'] . '</span></div>';
              }
            }
            ?>

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
            <div class="field field-name-field-story-categoryprim field-type-taxonomy-term-reference field-label-above"><div class="field-label">Primary Category:&nbsp;</div><div class="field-items"><div class="field-item even"><?php echo $termdata; ?></div></div></div>
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
            <?php
            if (isset($content['body']['#object']->field_story_associate_lead) && is_array($content['body']['#object']->field_story_associate_lead)) {
              if ($content['body']['#object']->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
                print render($content['field_associate_photo_gallery']);
              } else if ($content['body']['#object']->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') {
                print render($content['field_story_associate_video']);
              }
            }
            ?>
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
                    break;

                  case 'facebook_instant_article':
                    print render($content['field_facebook_audio_position']);
                    print render($content['field_facebook_instant_audio_url']);
                    print render($content['field_animated_image_position']);
                    print render($content['field_facebook_animated_image']);
                    print render($content['field_facebook_map_position']);
                    print render($content['field_map_embed_code']);
                    //print render($content['field_facebook_gallery_associate']);                        
                    print render($content['field_social_embed_code_position']);
                    print render($content['field_social_embed_code']);
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
              <?php //print render($content['field_story_client_title']);  ?>
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
        $templates = render($content['field_story_select_templates']);
        if (!empty($templates)):
          ?>
          <div class="Templates">
            <h2><?php print t('Templates'); ?></h2>
            <div class="content-details">
              <div class="listicle">
                <?php if ($node->field_story_select_templates[LANGUAGE_NONE][0]['value'] == 'listicle') { ?>
                  <?php print render($content['field_story_select_templates']); ?>
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
                      <?php
                      $template_type = $node->field_story_listicle[LANGUAGE_NONE];
                      foreach ($template_type as $tpl_key => $tpl_val) {
                        print "<div class='lst-desc'><span class='lst-lable'>Listicle description</span>" . $template_type[$tpl_key]['field_story_listicle_description'][LANGUAGE_NONE][0]['value'] . "</span></div>";
                        print "<div class='lst-type'><span class='lst-lable'>Listicle type</span>" . $template_type[$tpl_key]['field_story_listicle_type'][LANGUAGE_NONE][0]['value'] . "</span></div>";
                        print "<div class='lst-color'><span class='lst-lable'>Listicle Color</span>" . $template_type[$tpl_key]['field_listicle_color'][LANGUAGE_NONE][0]['value'] . "</span></div>";
                      }
                    }
                    ?>
                    <?php
                    if ($content['field_story_select_templates']['#object']->field_story_select_templates[LANGUAGE_NONE][0]['value'] == 'quote') {
                      print render($content['field_story_quote_title']);
                      print render($content['field_story_quote_image']);
                      print render($content['field_story_template_quotes']);
                    } else if ($content['field_story_select_templates']['#object']->field_story_select_templates[LANGUAGE_NONE][0]['value'] == 'factoid') {
                      print render($content['field_story_factoids_title']);
                      print render($content['field_story_template_factoids']);
                    }
                    ?>
                    <?php
                    if ($node->field_story_select_templates[LANGUAGE_NONE][0]['value'] == 'buzz') {
                      $template_type = $node->field_story_template_buzz[LANGUAGE_NONE];
                      foreach ($template_type as $tpl_key => $tpl_val) {
//                          print $template_type[$tpl_key]['field_buzz_image'][LANGUAGE_NONE][0]['value'];
                        print "<div class='lst-desc'><span class='lst-lable'>HeadLine</span>" . $template_type[$tpl_key]['field_buzz_headline'][LANGUAGE_NONE][0]['value'] . "</span></div>";
//                          print "<div class='lst-type'><span class='lst-lable'>Image</span>" . $template_type[$tpl_key]['field_buzz_image'][LANGUAGE_NONE][0]['value'] . "</span></div>";
                        print "<div class='lst-color'><span class='lst-lable'>Buzz Description</span>" . $template_type[$tpl_key]['field_buzz_description'][LANGUAGE_NONE][0]['value'] . "</span></div>";
                      }
                    }
                    ?>
                  </div>
                </div>
              </div>
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
              <?php print render($content['field_story_expertise']); ?>
              <?php
              if (!empty($content['field_story_expert_image'])) {
                print render($content['field_story_expert_image']);
              }
              ?>
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
                print '<div class="field"><div class="field-label">' . $h_count . ':</div><div class="field-items">' . $high['value'] . '</div></div>';
                $h_count++;
              }
              ?>
            </div>  
          </div>
        <?php endif; ?>
        <!-- render story movie fields -->
        <div class="movie-details content-box">
          <h2><?php print t('Movies'); ?></h2>
          <div class="content-details">
            <?php print render($content['field_story_rating']); ?>
            <?php print render($content['field_mega_review_cast']); ?>
            <?php print render($content['field_mega_review_director']); ?>
            <?php print render($content['field_mega_review_movie_plot']); ?>
          </div>
        </div>
        <!-- render story technology fields -->
        <div class="tech-details content-box">
          <h2><?php print t('Technology'); ?></h2>
          <div class="content-details">
            <?php print render($content['field_story_technology_rating']); ?>
            <?php print render($content['field_story_tech_review_chunk']); ?>
            <?php
            $story_tech = $node->field_story_technology[LANGUAGE_NONE];
            foreach ($story_tech as $tpl_key => $tpl_val) {
              print "<div class='lst-desc'><span class='lst-lable'>Sample Photo Title</span>" . $story_tech[$tpl_key]['field_technology_photo_title'][LANGUAGE_NONE][0]['value'] . "</span></div>";
            }
            ?>
          </div>
        </div>
        <!-- render photo story fields -->
        <?php if ($node->field_story_type[LANGUAGE_NONE][0]['value'] == 'photo_story') : ?>
          <div class="photo-story-details content-box">
            <h2><?php print t('photo story'); ?></h2>
            <div class="content-details">
              <?php
              $photo_story_data = $node->field_photo_story[LANGUAGE_NONE];
              foreach ($photo_story_data as $fsd_key => $fsd_val) {
//                          print $photo_story_data[$fsd_key]['field_photo_story_image'];
                print "<div class='psd'><span class='psd-title'>Photo Story Description :</span>" . $photo_story_data[$fsd_key]['field_photo_story_description'][LANGUAGE_NONE][0]['value'] . '</span></div>';
              }
              ?>
            </div>
          </div>
        <?php endif; // end of photo story ?>
      <?php endif; // end of view mode full condition ?>
    </div>
    <?php
    if (!isset($node->op) && in_array('Social Media', $user->roles)):
      $block = module_invoke('itg_social_media', 'block_view', 'social_media_form');
      $data_in = itg_social_media_check_node_exist_lock($node->nid);
      global $user;
      if ($data_in[0]->uid == $user->uid || empty($data_in)) {

        itg_social_media_enter_in_lock($node->nid);
        ?>
        <div class="promote-sidebar">
          <?php print render($block['content']); ?>
        </div>
        <?php
      } else {
        ?>
        <div class="promote-sidebar">
          <div class="promote-lock">Someone  is already working on this</div>
        </div> 
      <?php }
      ?>
    <?php endif; ?>
  </div>
  <?php
  // code for comment hide and show based on condition
  if ($node->field_story_configurations[LANGUAGE_NONE][0]['value'] == 'comment') {
    print render($content['comment_form']);
    print render($content['comments']);
  }
  ?>
<?php endif; ?>

