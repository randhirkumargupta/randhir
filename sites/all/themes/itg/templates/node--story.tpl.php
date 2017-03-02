<?php
if (!empty($content)):
  global $base_url, $user;
  // get related content associated with story
  $related_content = $content['related_content'];
  // condition for buzz
  if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
    $class_buzz = 'buzz-feedback';
  }
  if (!empty($related_content)) {
    $class_related = ' buzz-related';
  }
  if (!empty($node->field_story_listicle[LANGUAGE_NONE])) {
    $class_listicle = ' buzz-feedback listicle-feedback';
  }
  // prepare url for sharing
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
  $short_url = shorten_url($actual_link, 'goo.gl');
  $fb_title = addslashes($node->title);
  $share_desc = '';
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);

  // get total share count
  $tot_count = $content['total_share_count'];

  // get global comment config    

  $config_name = trim($global_comment_last_record[0]->config_name);

  // get comment count

  $get_comment_count = $content['comment_count'];

  // get developing story status

  $get_develop_story_status = $content['develop_story_status'];

  //get follow story status

  $follow_status = $content["follow_status"];
  
  //get byline id based on order reorder

  $byline_id = $content["byline_id"];

  //get byline detail
  if (!empty($byline_id)) {
    $reporter_node = node_load($byline_id);
  }
  
  if (function_exists('itg_get_front_activity_info'))
  {
    $opt = itg_get_front_activity_info($node->nid, $node->type, $user->uid, 'read_later', $status = '');
  }
?>
  <div class="story-section <?php print $class_buzz . "" . $class_related . "" . $class_listicle;
                if ($node->field_story_type[LANGUAGE_NONE][0]['value'] == 'photo_story') {
                  echo ' photo-story-section';
                }
              ?>">
      <div class='<?php print $classes ?>'>
          <?php //pr($node);   ?> 
          <div class="comment-mobile desktop-hide">
              <ul>
                  <li class="later">
                                          <?php
                                          if ($user->uid > 0)
                                          {
                                           if (empty($opt['status']) || $opt['status'] == 0)
                                            {
                                              ?> 
                                              <a title = "Read Later" href="javascript:void(0)" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i><span><?php print t('READ LATER'); ?></span></a>
                                            <?php }
                                            else
                                            { ?>
                                              <a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i><span><?php print t('READ LATER'); ?></span></a>
                                            <?php
                                            }
                                          }
                                          else
                                          {
                                            if (function_exists(itg_sso_url))
                                            {
                                              print itg_sso_url('<i class="fa fa-bookmark"></i> <span>' . t('READ LATER') . '</span>', t('READ LATER'));
                                            }
                                          }
                                          ?>
                                      </li>
                  <li class="mail-to-author"><a title ="Mail to author" href="mailto:support@indiatoday.in"><i class="fa fa-envelope"></i><?php //print t('Mail to author'); ?></a></li>
                  <li><a href="#" title = "whatsapp"><i class="fa fa-whatsapp"></i></a></li>
                  <?php
                  if ($config_name == 'vukkul') {
                    ?>
                    <li><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                  <?php } if ($config_name == 'other') { ?> 
                    <li><a class="def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                  <?php } ?>
                  <li><a href="javascript:void(0)" title ="share" class="share-icon"><i class="fa fa-share-alt"></i></a>
              </ul>
              <ul class="social-share">
                  <li><a title = "share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                  <li><a title = "share on twitter" href="javascript:void(0)" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                  <li><a title="share on google+" href="javascript:void(0)" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>

              </ul> 
          </div>
          <?php
          $pipelinetext = "";
          if (!empty($node->field_story_new_title) && !empty($node->field_story_redirection_url_titl)) {
            $pipelinetext = ' <span class="story-pipline">||</span> <a target="_blank" href="' . $node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'] . '">' . ucfirst($node->field_story_new_title[LANGUAGE_NONE][0]['value']) . '</a>';
          }
          if (!empty($get_develop_story_status)) {
            ?>
          <h1><?php
                  if (function_exists('itg_common_get_smiley_title')) {
                    print itg_common_get_smiley_title($node->nid, 0, 255) . $pipelinetext;
                  }
                  else {
                    print $node->title . $pipelinetext;
                  }
                  ?> <i class="fa fa-circle" aria-hidden="true" title="Development story"></i></h1>
          <?php }
          else { ?>
            <h1><?php 
            if(function_exists('itg_common_get_smiley_title')) {
              print itg_common_get_smiley_title($node->nid , 0, 255) . $pipelinetext;
            }
            else {
              print $node->title . $pipelinetext;
            }
            ?></h1>
          <?php global $user;
        if(in_array('Social Media', $user->roles)) {?>
         <a class="def-cur-pointer colorbox-load" title="promote" href="<?php print $base_url; ?>/itg-social-media-promote/<?php echo $node->nid;?>?width=850&height=850&iframe=true&type=<?php print $video_node->type; ?>"><span>promote</span></a>   
        <?php }?>
          <?php } ?>
          <?php
          $associate_type = '';
          $associate_id = '';

          if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
            $associate_type = 'gallery';
            $associate_id = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
          }
          else if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') {
            $associate_type = 'video';
            $associate_id = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
          }
          $clidk_class_slider = "";
          $widget_data = '';
          if ($associate_type != "" && $associate_id !="") {
            $clidk_class_slider = 'associate-content-block';
            $widget_data = $associate_type . '-' . $associate_id;
          }
          
          ?>
  <!--           <a href="javascript:void(0)" class="associate-content-block" data-widget="<?php //echo $associate_type; ?>-<?php // echo $associate_id; ?>">click here</a>-->            
          <div class="story-left-section">
  <?php if (empty($node->field_story_template_buzz[LANGUAGE_NONE]) && empty($node->field_story_listicle[LANGUAGE_NONE])) { ?>
                <div class="story-left">
                    <div class="byline">              
                        <div class="profile-pic">

                            <?php
                            $file = $reporter_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                            if (!empty($file)) {
                              print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                            }
                            else {
                              $file = 'default_images/user-default.png';
                              print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                            }
                            ?>
                        </div>
                        <div class="profile-detail">                  
                            <ul>
                                <li class="title"><?php print t($reporter_node->title); ?></li>
                                <?php
                                $twitter_handle = $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
                                $twitter_handle = str_replace('@', '', $twitter_handle);
                                if (!empty($twitter_handle)) {
                                  ?>
                                  <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];                                         ?></li>                
    <?php } ?>
                            </ul>
                            <ul class="date-update">
                                <li class="mailto mhide"><i class="fa fa-envelope-o"></i> &nbsp;<?php
                                    $email = $reporter_node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
                                    print "<a title ='Mail To Author' href='mailto:support@indiatoday.in'>" . t('Mail To Author') . "</a>";
                                    ?></li>
                                <li class="mhide"><span class="share-count"><?php
                                        if (!empty($tot_count)) {
                                          print $tot_count;
                                        }
                                        else {
                                          print 0;
                                        }
                                        ?></span><?php print t('SHARES'); ?></li>
                                <li><?php print date('F j, Y', $node->created); ?>   </li>
                                <li><?php print t('UPDATED');?> <?php print date('H:i', $node->changed);
                                print t(' IST');
                                        ?></li>
    <?php if (!empty($node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name)) { ?>
                                  <li>
      <?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?>
                                  </li>
                                <?php } ?>
                            </ul>
                            <ul class="social-links mhide">
                                <li><a title = "share on facebook" href="javascript:void(0)"  onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                                <li><a title = "share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                                <li><a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                                <?php
                                if ($config_name == 'vukkul') {
                                  ?>
                                  <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                                <?php } if ($config_name == 'other') { ?> 
                                  <li><a class="def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                                <?php } 
                                if ($user->uid > 0)
                                          {
                                            if (empty($opt['status']) || $opt['status'] == 0)
                                            {
                                              ?> 
                                  <li class="left-later"><span> <a title = "Read Later" href="javascript:void(0)" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i><?php print t('READ LATER'); ?></a><span class="flag-throbber">&nbsp;</span></span></li>
                                            <?php }
                                            else
                                            { ?>
                                  <li><span> <a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer unflag-action"><i class="fa fa-bookmark"></i><?php print t('READ LATER'); ?></a><span class="flag-throbber">&nbsp;</span></span></li>
                                            <?php
                                            }
                                          }
                                          else
                                          {
                                            if (function_exists(itg_sso_url))
                                            {
                                              print '<li>'.itg_sso_url('<i class="fa fa-bookmark"></i> <span>' . t('READ LATER') . '</span>', t('READ LATER')).'</li>';
                                            }
                                          } ?>
                            </ul>
                        </div>
                    </div>
                            <?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                      <div class="briefcase mhide">
                          <h4><?php print t('Highlights'); ?></h4>
                          <ul>
                      <?php
                      foreach ($node->field_story_highlights['und'] as $high) {
                        print '<li>' . $high['value'] . '</li>';
                      }
                      ?>
                          </ul>
                      </div>
                        <?php } if (!empty($related_content)) { ?>
                      <!--related content-->
                      <div class="related-story-page">
                      <?php
                      $block = module_invoke('itg_front_end_common', 'block_view', 'related_story_left_block');
                      print render($block['content']);
                      ?>
                      </div>


                        <?php } ?>
                </div>
                      <?php } ?>
              <!-- For buzzfeed section start -->
                          <?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE]) || !empty($node->field_story_listicle[LANGUAGE_NONE])) { ?>                       
                <div class="buzzfeed-byline">
                    <div class="byline">
                        <div class="profile-pic">
                            <?php
                            $file = $reporter_node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                            if (!empty($file)) {
                              print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                            }
                            else {
                              $file = 'default_images/user-default.png';
                              print theme('image_style', array('style_name' => 'user_picture', 'path' => $file));
                            }
                            ?>
                        </div>
                        <div class="profile-detail">
                            <ul>
                                <li class="title"><?php print $reporter_node->title; ?></li>
    <?php
    $twitter_handle = $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];
    $twitter_handle = str_replace('@', '', $twitter_handle);
    if (!empty($twitter_handle)) {
      ?>
                                  <li class="twitter"><a title="Follow on Twitter" href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];                                       ?></li>                
                                <?php } ?>
                            </ul>
                            <ul class="date-update">
                                <li><?php print date('F j, Y', $node->created); ?>   </li>
                                <li>UPDATED <?php print date('H:i', $node->changed); ?> IST</li>
    <?php if (!empty($node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name)) {
      ?>
                                  <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></li>
    <?php } ?>
                            </ul>

                        </div>
                        <div class="social-share-story">
                            <ul class="">
                                <li><div id="fb-root"></div><a title = "share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                                <li><a title = "share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                                <li><a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                                    <?php if ($config_name == 'vukkul'): ?>
                                  <li><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                                    <?php endif; ?>
                                    <?php if ($config_name == 'other'): ?> 
                                  <li><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                                    <?php endif; ?>

                                <li class="later">
                                          <?php
                                          if ($user->uid > 0)
                                          {
                                            if (empty($opt['status']) || $opt['status'] == 0)
                                            {
                                              ?> 
                                              <a title = "Read Later" href="javascript:void(0)" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="read_later" data-status="1" class="def-cur-pointer"><i class="fa fa-bookmark"></i><span><?php print t('READ LATER'); ?></span></a>
                                            <?php }
                                            else
                                            { ?>
                                              <a title = "Read Later" href="javascript:void(0)" class="def-cur-pointer active"><i class="fa fa-bookmark"></i><span><?php print t('READ LATER'); ?></span></a>
                                            <?php
                                            }
                                          }
                                          else
                                          {
                                            if (function_exists(itg_sso_url))
                                            {
                                              print itg_sso_url('<i class="fa fa-bookmark"></i> <span>' . t('READ LATER') . '</span>', t('READ LATER'));
                                            }
                                          }
                                          ?>
                                      </li>

                            </ul>
                        </div>
                    </div>
                </div>

  <?php } ?>
              <!-- Check the story type whether it is a photo story or not-->
               <?php if ((!empty($node->field_story_type) && $node->field_story_type[LANGUAGE_NONE][0]['value'] == 'other_story') || (empty($node->field_story_type))) { ?>
              <div class="story-right <?php
  if (!empty($node->field_story_listicle[LANGUAGE_NONE])) {
    echo 'listicle-page';
  }
  ?>">
                  <?php
                  $associate_lead = $node->field_story_associate_lead[LANGUAGE_NONE][0]['value'];
                  $associate_photo = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
                  $associate_video = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
                  if(!empty($associate_lead) && !empty($associate_photo) || !empty($associate_video)) {
                      $class = 'story-associate-content';
                  } 
                  ?>
                  <div class="<?php echo $class; ?>">
                      <?php
                  if(!empty($associate_lead) && !empty($associate_video)) {?>
                    <div id="videogallery-iframe">
                          <img class="loading-popup" src="<?php print $base_url; ?>/sites/all/themes/itg/images/reload.gif" alt="loading" />
                      </div>
                  <?php }
                  ?>                      
                      <?php
                      $clidk_class_slider = "";
                      $widget_data = '';
                      if ($associate_type != "" && $associate_id !="") {
                        $clidk_class_slider = 'associate-content-block';
                        $widget_data = $associate_type . '-' . $associate_id;
                      }
                      if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                        // imgtags" img-fid="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];" use for image tagging
                        ?>
                        <div class="stryimg" ><?php
                        if(empty($widget_data)){
                          $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                            if(file_exists($story_image)) {
                              $file_uri = file_create_url($story_image);
                            } else {
                              $file_uri =  $base_url. '/sites/all/themes/itg/images/itg_image647x363.jpg';
                            }
                          print '<img  alt="" title="" src="' . $file_uri . '">';
                        } else {
                        $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                        $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                        if(file_exists($story_image)){
                          $file_uri = file_create_url($story_image);
                        } else {
                          $file_uri =  $base_url. '/sites/all/themes/itg/images/itg_image647x363.jpg';
                        }
                        print '<a href="javascript:void(0);" class="' . $clidk_class_slider . '" data-widget="' . $widget_data . '"><img  alt="" title="' . $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] . '" src="' . $file_uri . '"><span class="story-photo-icon">';
                        ?>        

                            <?php if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') { ?>
                              <i class="fa fa-play-circle"></i>
                            <?php }
                            else if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') { ?>                    
                              <i class="fa fa-camera"></i>
                            <?php } print '</span></a>'; } ?>

                            <?php
                            if (!empty($getimagetags)) {
                              foreach ($getimagetags as $key => $tagval) {
                                $urltags = addhttp($tagval->tag_url);
                                print '<div class="tagview" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;" ><div class="square"></div><div  class="person" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;"><a href="' . $urltags . '" target="_blank">' . ucfirst($tagval->tag_title) . '</a></div></div>';
                              }
                            }
                            // print theme('image_style', array('style_name' => 'story_image', 'path' => $story_image));
                            ?>
                                <?php
                              }
                              else {
                                ?>

                            <div class="stryimg"><?php
                                $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                                //print theme('image_style', array('style_name' => 'buzz_image', 'path' => $story_image));
                                $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                                $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                                $file_uri = file_create_url($story_image);
                                print '<a href="javascript:void(0);" class="' . $clidk_class_slider . '" data-widget="' . $widget_data . '"><img  alt="" title="' . $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'] . '" src="' . $file_uri . '"><span class="story-photo-icon">        
                                    <i class="fa fa-play-circle"></i>
                                    <i class="fa fa-camera"></i></span></a>';
                                if (!empty($getimagetags)) {
                                  foreach ($getimagetags as $key => $tagval) {
                                    $urltags = addhttp($tagval->tag_url);
                                    print '<div class="tagview" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;" ><div class="square"></div><div  class="person" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;"><a href="' . $urltags . '" target="_blank">' . ucfirst($tagval->tag_title) . '</a></div></div>';
                                  }
                                }
                                ?>
                              <?php } ?>
                                
                      <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
                                <div class="photoby">
                                  <?php if (!empty($node->field_story_technology_rating[LANGUAGE_NONE][0]['value'])) { ?>
                                  <div class="story-img-rating">
                                    <?php 
                                    // added technology rating field value for story technology
                                      $tech_rating = $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'];
                                      echo $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'] . '/10'; 
                                    ?>
                                  </div>
                                  <?php } ?>
                                  <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'])) { ?>
                                  <div class="photoby-text"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>
                                  <?php } ?>
                                </div>
                      <?php } ?>     
                               
                            
                           
                          </div>
  <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'])) { ?>    
                            <div class="image-alt"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?></div>
                              <?php } ?>                            
                      </div>

                              <?php
                              if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                                if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) {
                                  ?>
                          <div class="briefcase desktop-hide">
                              <h4><?php print t('Briefcase'); ?></h4>
                              <ul>
                          <?php
                          foreach ($node->field_story_highlights['und'] as $high) {
                            print '<li>' . $high['value'] . '</li>';
                          }
                          ?>
                              </ul>
                          </div>
                              <?php
                            }
                          }
                          ?>

                      <div class="story-movie">
                                      <?php if (!empty($node->field_story_rating)): ?>
                            <div class="movie-rating" data-star-value="<?php print $node->field_story_rating[LANGUAGE_NONE]['0']['value'] * 20 . "%"; ?>">

                            </div>                            
                                      <?php endif; ?>
                          <div class="movie-detail">
                                      <?php if (!empty($node->field_mega_review_cast)): ?>
                                <div class="cast">
                                    <span class="title"> <?php print t('Cast:'); ?></span>
                                    <span class="detail"> <?php
                                        $cast_ref_id = $node->field_mega_review_cast[LANGUAGE_NONE];
                                        $count = sizeof($cast_ref_id);
                                        for ($i = 0; $i < $count; $i++) {
                                          $entity_obj = entity_load('node', array($cast_ref_id[$i]['target_id']));
                                          $cast = $entity_obj[$cast_ref_id[$i]['target_id']]->title;
                                          print $cast;
                                          if ($i < ($count - 1)) {
                                            echo ', ';
                                          }
                                        }
                                        ?></span>
                                </div>
  <?php endif; ?>
  <?php if (!empty($node->field_mega_review_director)): ?>
                                <div class="director">
                                    <span class="title"> <?php print t('Director:'); ?></span>                                 
                                    <span class="detail"> <?php print $node->field_mega_review_director[LANGUAGE_NONE]['0']['value']; ?></span>
                                </div>
                          <?php endif; ?>
                          <?php if (!empty($node->field_mega_review_movie_plot)): ?>
                                <div class="plot">
                                    <span class="title"> <?php print t('Plot:'); ?></span>                                    
                                    <span class="detail"> <?php print $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value']; ?></span>
                                </div>
                          <?php endif; ?>
                          </div>                            
                      </div>
                      <div class="description">
                          <?php
                          $story_body = $node->body['und'][0]['value'];
                          if (strpos($story_body, '[ITG:SURVEY:')) {
                            if (preg_match('/ITG:SURVEY:([0-9]+)/', $story_body, $matches_survey)) {
                              $survey_nid = $matches_survey[1];
                            }
                            $story_body = str_replace('[ITG:SURVEY:' . $survey_nid . ']', '', $story_body);
                          }
                          if (strpos($story_body, '[ITG:QUIZ:')) {
                            if (preg_match('/ITG:QUIZ:([0-9]+)/', $story_body, $matches_quiz)) {
                              $quiz_nid = $matches_quiz[1];
                            }
                            $story_body = str_replace('[ITG:QUIZ:' . $quiz_nid . ']', '', $story_body);
                          }
                          if (strpos($story_body, '[ITG:POLL:')) {
                            if (preg_match('/ITG:POLL:([0-9]+)/', $story_body, $matches_poll)) {
                              $poll_nid = $matches_poll[1];
                            }
                            $story_body = str_replace('[ITG:POLL:' . $poll_nid . ']', '', $story_body);
                          }
                          if (strpos($story_body, '[ITG:FACTOIDS]')) {
                            $factoidsBlock = '';
                            if (isset($node->field_story_template_factoids) && !empty($node->field_story_template_factoids)) {
                              $factoidsSocialShare['title'] = $node->field_story_factoids_title[LANGUAGE_NONE][0]['value'];
                              $factoidsSocialShare_title = preg_replace("/'/", "\\'", $factoidsSocialShare['title']);
                              $factoidsSocial_share_title = htmlentities($factoidsSocialShare_title, ENT_QUOTES);
                              $factoidsSocialShare['share_desc'] = $node->field_story_template_factoids[LANGUAGE_NONE][0]['value'];
                              $factoidsSocialShare['icons'] = '<div class="factoids-page">
                                 <div class="fun-facts"><h2>' . $factoidsSocialShare['title'] . '</h2> </div><div class="social-share"><ul>     
                                 <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                                 <li><a title = "share on facebook" class="facebook" href="javascript:void(0)" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $factoidsSocial_share_title . "'" . ', ' . "'" . $factoidsSocialShare['share_desc'] . "'" . ', ' . "'" . $image . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                                 <li><a title = "share on twitter" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="twitter_share" data-status="1" class="user-activity twitter" href="javascript:" onclick="twitter_popup(\'' . urlencode($factoidsSocialShare['share_desc']) . ',' . urlencode($short_url) . '\')"><i class="fa fa-twitter"></i></a></li>
                                 <li><a class="user-activity google" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="google_share" data-status="1" title="share on google+" href="javascript:void(0)" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')"></a></li>
                                 </ul></div></div>';
                              $factoidsSocialShare['slider'] = '<div class="factoids-slider"><ul>';
                              foreach ($node->field_story_template_factoids[LANGUAGE_NONE] as $key => $value) {
                                $factoidsSocialShare['slider'] .='<li><span>' . $value['value'] . '</span></li>';
                              }
                              $factoidsSocialShare['slider'] .= '</ul></div>';
                              $factoidsBlock = $factoidsSocialShare['icons'] . $factoidsSocialShare['slider'];
                            }
                            $story_body = str_replace('[ITG:FACTOIDS]', $factoidsBlock, $story_body);
                          }
                          if (strpos($story_body, '[ITG:EXPERT-CHUNK]')) {
                            $expertDetails = '';
                            if (!empty($node->field_story_expert_name)) {
                              $expertDetails .= '<div class="story-expert-opinion"><h4>' . t('Expert Opinion') . '</h4>';
                              $expertDetails .= '<div class="expert-detail row"><div class="left-side col-md-8 col-sm-8 col-xs-8"><p class="name">' . $node->field_story_expert_name['und'][0]['value'] . '</p>';
                              if (!empty($node->field_story_expertise)) {
                                $expertDetails .= '<p>' . $node->field_story_expertise[LANGUAGE_NONE][0]['value'] . '</p>';
                              }
                              $expertDetails .= '</div>';
                            }
                            if (!empty($node->field_story_expert_image)) {
                              if (!empty($node->field_story_expert_image[LANGUAGE_NONE][0]['uri'])) {
                                $expertDetailsImage = file_create_url($node->field_story_expert_image[LANGUAGE_NONE][0]['uri']);
                              }
                              else {
                                $expertDetailsImage = $base_url . '/sites/all/themes/itg/images/user-default-expert.jpg';
                              }
                            }
                            $expertDetails .= '<div class="right-side col-md-4 col-sm-4 col-xs-4"><img src="' . $expertDetailsImage . '" alt="" /></div></div>';
                            if (!empty($node->field_story_expert_description)) {
                              $expertDetails .= '<h2>' . $node->field_story_expert_description['und'][0]['value'] . '</h2>';
                            }
                            $expertDetails .= '</div>';

                            if (!empty($node->field_story_expert_description['und'][0]['value']) && !empty($node->field_story_expert_name)) {
                              $story_body = str_replace('[ITG:EXPERT-CHUNK]', $expertDetails, $story_body);
                            }
                            else {
                              $story_body = str_replace('[ITG:EXPERT-CHUNK]', '', $story_body);
                            }
                          }
                          $movie_html = itg_story_movie_image_plugin_data($node->nid);
                          if (strpos($story_body, '[ITG:TECH-PHOTOS]')) {
                            if (!empty($node->field_story_technology['und'])) {
                              $story_body = str_replace('[ITG:TECH-PHOTOS]', $movie_html, $story_body);
                            }
                            else {
                              $story_body = str_replace('[ITG:TECH-PHOTOS]', '', $story_body);
                            }
                          }
                          if ($node->field_story_template_guru[LANGUAGE_NONE][0]['value']) {
                            print '<h3 class="listical_title">' . $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] . '</h3>';
                          }

                          if (!empty($node->field_story_listicle[LANGUAGE_NONE])) {
                            $wrapper = entity_metadata_wrapper('node', $node);
                            $num = 1;
                            foreach ($wrapper->field_story_listicle as $i):
                              $listicletype = '';

                              print '<div class="listicle-detail">';
                              $type = $i->field_story_listicle_type->value();
                              $description = $i->field_story_listicle_description->value();
                              $color = $i->field_listicle_color->value();
                              $li_type = $node->field_story_templates[LANGUAGE_NONE][0]['value'];
                              $color = ($color) ? $color : '#000000';
                              if ($li_type == 'bullet_points') {
                                print '<span class="bullet_points"></span>';
                              }
                              else {
                                print '<span>' . $num . '</span>';
                              }

                              if (isset($type)) {
                                $listicletype = '<span class="listicle-type" style="color: ' . $color . '">' . $type . ': </span>';
                              }
                              print '<div class="listicle-description">' . $listicletype . $description . '</div>';
                              print '</div>';
                              $num++;
                            endforeach;
                          }
                          else {
                            // Print story body
                            print $story_body;
                          }
                          // If survey is associated with story, render survey form
                          if (strpos($node->body['und'][0]['value'], '[ITG:SURVEY:')) {
                            $story_body_survey = str_replace($story_body, itg_survey_pqs_associate_with_story('[ITG:SURVEY:' . $survey_nid . ']'), $story_body);
                            print $story_body_survey;
                          }
                          // If quiz is associated with story, render quiz form
                          if (strpos($node->body['und'][0]['value'], '[ITG:QUIZ:')) {
                            $story_body_quiz = str_replace($story_body, itg_survey_pqs_associate_with_story('[ITG:QUIZ:' . $quiz_nid . ']'), $story_body);
                            print $story_body_quiz;
                          }
                          // If Poll Associated with story node.
                          if (strpos($node->body['und'][0]['value'], '[ITG:POLL:')) {
                            $story_body_poll = str_replace($story_body, itg_survey_pqs_associate_poll_with_story($poll_nid), $story_body);
                            print $story_body_poll;
                          }
                          ?>
                      </div>
                      <!-- render story technology chunk -->
  <?php
  if (!empty($node->field_story_tech_review_chunk[LANGUAGE_NONE][0]['value'])) {
    ?>
                        <div class="story-tech-chunk">
                <?php if (!empty($node->field_story_technology_rating[LANGUAGE_NONE][0]['value'])) { ?>
                              <span class="tech-rating">
                  <?php echo $node->field_story_technology_rating[LANGUAGE_NONE][0]['value'] . '/10'; ?>
                              </span>
                <?php } ?>
                <?php print render($content['field_story_tech_review_chunk']); ?>
                        </div>
              <?php } ?>
                  </div>
              </div>
              <?php } else { ?>
              <div class="story-right <?php
                if (!empty($node->field_story_type[LANGUAGE_NONE])) {
                  echo 'photo-story';
                }
              ?>">
              <?php 
                if (!empty($node->field_photo_story)) {
                  $output = itg_story_photo_story_html($node->nid);
                  print $output;
                }
              ?>
                  <!-- for photo story bottom slider, loop has been repeated again -->
                  <?php 
                if (!empty($node->field_photo_story)) {
                  $html_output = itg_story_photo_story_bottom_html($node->nid);
                  print $html_output;
                }
              ?>
              </div>
              <?php } ?>
              <div class="clearfix"></div>
              <!-- condition for buzz  -->

              <?php
              if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                $buzz_output.= '';
                $buzz = 1;
                foreach ($node->field_story_template_buzz['und'] as $buzz_item) {
                  $buzz_output.= '<div class="buzz-section">';
                  $field_collection_id = $buzz_item['value'];
                  $entity = entity_load('field_collection_item', array($field_collection_id));
                  $buzz_imguri = _itg_photogallery_fid($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
                  $file = file_load($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
                  $share_uri = $file->uri;
                  $share_image = file_create_url($share_uri);
                  $img = '<img title="' . $entity[$field_collection_id]->field_buzz_image['und'][0]['title'] . '" src="' . image_style_url("buzz_image", $buzz_imguri) . '" alt="" />';
                  if (!empty($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])) {
                    $buzz_output.= '<h1><span>' . $buzz . '</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
                    if (!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
                      $buzz_title = preg_replace("/'/", "\\'", $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']);
                      $buzz_title_share = htmlentities($buzz_title, ENT_QUOTES);
                      $buzz_output.= '<div class="buzz-img"><div class="social-share">
              <ul>
              <li><a title = "share" href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
              <li><a title = "share on facebook" class= "facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $buzz_title_share . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $share_image . "'" . ', ' . "'" . $base_url . "'" . ', ' . "'" . $nid . "'" . ')" class="facebook"><i class="fa fa-facebook"></i></a></li>
              <li><a title = "share on twitter" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="twitter_share" data-status="1" href="javascript:" onclick="twitter_popup(' . "'" . urlencode($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')" class="user-activity twitter"><i class="fa fa-twitter"></i></a></li>
              <li><a title="share on google+" href="javascript:" rel="'.$node->nid.'" data-tag="'.$node->type.'" data-activity="google_share" data-status="1" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="user-activity google"><i class="fa fa-google-plus"></i></a></li>
              </ul>
          </div>' . $img . '</div><div class="photoby">' . $entity[$field_collection_id]->field_buzz_image['und'][0]['alt'] . '</div><div class="image-alt">' . $entity[$field_collection_id]->field_buzz_image['und'][0]['title'] . '</div>';
                    }
                    if (!empty($entity[$field_collection_id]->field_buzz_description['und'][0]['value'])) {
                      $buzz_output.= '<div class="buzz-discription">' . $entity[$field_collection_id]->field_buzz_description['und'][0]['value'] . '</div>';
                    }
                    $buzz_output.= '</div>';
                    $buzz++;
                  }
                }
                print $buzz_output;
              }
              ?>

              <!-- code for like dislike -->

              <?php
              $get_val = '0' . arg(1);
              if (function_exists('itg_flag_get_count')) {
                $like = itg_flag_get_count($get_val, 'like_count');
                $dislike = itg_flag_get_count($get_val, 'dislike_count');
              }
              if (!empty($like['like_count'])) {
                $like_count = $like['like_count'];
              }
              if (!empty($dislike['dislike_count'])) {
                $dislike_count = $dislike['dislike_count'];
              }
              $pid = "voted_" . $get_val;
              $like = "no-of-likes_" . $get_val;
              $dislike = "no-of-dislikes_" . $get_val;
              ?>
              <div class="agbutton story-like-dislike">
                  <div id="name-dv"><?php print t('Do You Like This Story'); ?>
                      <span id="lky"><button title="Like" id="like_count" rel="<?php print $get_val; ?>" data-tag="sty"><i class="fa fa-thumbs-o-up"></i> <span id="<?php print $like; ?>"><?php print $like_count; ?></span> </button>
                          <span id="sty-dv" style="display:none">Awesome! </br> Now share the story </br> <a title="share on facebook" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a> 
                              <a title="share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:void(0)" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
                              <a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="javascript:void(0)" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>
                          <?php
                          if ($config_name == 'vukkul') {
                            ?>
                                <a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
  <?php } if ($config_name == 'other') { ?> 
                                <a onclick ="scrollToAnchor('other-comment');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
  <?php } ?>
                          </span></span>
                      <span id="dlky"> <button title="Dislike" id="dislike_count" rel="<?php print $get_val; ?>" data-tag="dsty"><i class="fa fa-thumbs-o-down"></i> <span id="<?php print $dislike; ?>"><?php print $dislike_count; ?></span></button>
  <?php
  if ($config_name == 'vukkul') {
    ?>
                            <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><?php print t('comments'); ?></a></span> 

                          <?php } if ($config_name == 'other') { ?> 
                            <span id="dsty-dv" style="display:none"><?php print t('Too bad.'); ?></br> <?php print t("Tell us what you didn't like in the"); ?> <a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><?php print t('comments'); ?></a></span> 
                          <?php } ?>

                      </span>                                       
                  </div>                          
                  <p class="error-msg" id="<?php print $pid; ?>"></p>
              </div>

              <!-- End here -->


              <div class="section-left-bototm">
                  <div class="social-list">
                      <ul>
                                      <?php if ($user->uid > 0): ?>
                            <li class="mhide"><a title = "Submit Your Story" class="def-cur-pointer" href="<?php print $base_url; ?>/personalization/my-content/"><i class="fa fa-share"></i><span><?php print t('Submit Your Story'); ?></span></a></li>
                          <?php else: ?>
                            <li class="mhide"><a title = "Submit Your Story" class="def-cur-pointer colorbox-load" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=470&iframe=true&type=<?php print $node->type; ?>"><i class="fa fa-share"></i><span><?php print t('Submit Your Story'); ?></span></a></li>
                          <?php endif; ?>
                          <li class="mhide"><div id="fb-root"></div><a title = "share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                          <li class="mhide"><a title = "share on twitter" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                          <li class="mhide"><a title="share on google+" class="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="#" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                                  <?php
                                  if ($config_name == 'vukkul') {
                                    ?>
                            <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i> <span><?php
                            if (function_exists(itg_vukkul_comment_count)) {
                              print itg_vukkul_comment_count('story_' . arg(1));
                            }
                            ?></span></a></li>
                              <?php } if ($config_name == 'other') { ?> 
                            <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span><?php print $get_comment_count; ?></span></a></li>
                              <?php } ?>
                          <li class="mhide"><span class="share-count"><?php
                            if (!empty($tot_count)) {
                              print $tot_count;
                            }
                            else {
                              print 0;
                            }
                            ?></span> SHARES</li>
                      <?php if ($user->uid > 0): if (!empty($follow_status['nid']) && $follow_status['status'] == '1'): ?>  
                              <li class="mhide follow-story"><a title = "Unfollow Story" href="javascript:" id="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="follow_story" data-status="0" class="def-cur-pointer">Unfollow Story</a></li>
                        <?php else: ?>
                              <li class="mhide follow-story"><a title = "Follow the Story" href="javascript:" id="user-activity" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="follow_story" data-status="1" class="def-cur-pointer">Follow the Story</a></li>
                        <?php endif;
                      else:
                        ?>
                            <li class="mhide"><?php
                        if (function_exists(itg_sso_url)) {
                          print itg_sso_url('follow story');
                        }
                        ?></li>
                      <?php endif; ?>

                      </ul>
                  </div>

  <?php if (!empty($node->field_story_snap_post[LANGUAGE_NONE][0]['value'])) { ?>    
                    <div class="snap-post">
                        <div class="discription"><?php print $node->field_story_snap_post[LANGUAGE_NONE][0]['value']; ?></div>
                            <?php
                            $like = itg_flag_get_count(arg(1), 'like_count');
                            $dislike = itg_flag_get_count(arg(1), 'dislike_count');
                            if (!empty($like['like_count'])) {
                              $like_count = '(' . $like['like_count'] . ')';
                            }
                            if (!empty($dislike['dislike_count'])) {
                              $dislike_count = '(' . $dislike['dislike_count'] . ')';
                            }
                            $pid = "voted_" . arg(1);
                            $like = "no-of-likes_" . arg(1);
                            $dislike = "no-of-dislikes_" . arg(1);
                            ?>
                        <div class="agbutton"><button title ="Like" id="like_count" rel="<?php print arg(1); ?>">Like <span id="<?php print $like; ?>"><?php print $like_count; ?></span> </button> <button title ="Dislike" id="dislike_count" rel="<?php print arg(1); ?>">Dislike <span id="<?php print $dislike; ?>"><?php print $dislike_count; ?></span></button>  <a href="<?php echo $base_url; ?>/snappost"> More from Snap post</a><p class="error-msg" id="<?php print $pid; ?>"></p></div>
                    </div>
                      <?php } ?>
                  <div class="tags">
                      <ul>
                          <li><i class="fa fa-tags"></i> <?php print t('Tags :'); ?></li>        
                      <?php
                      foreach ($node->field_story_itg_tags['und'] as $tags) {
                        $published_tag = $tags['taxonomy_term']->field_tags_status[LANGUAGE_NONE][0]['value'];
                        if ($published_tag == 'Published') {
                          $term = taxonomy_term_load($tags['tid']);
                          $t_name = $term->name;
                          $comma_sep_tag[] = $t_name;
                          print '<li><a target="_blank" href="' . $base_url . '/site-search?keyword=' . $t_name . '">#' . $t_name . '</a></li>';
                        }
                      }
                      ?>
                      </ul>
                  </div>
                  <!-- For buzzfeed section stary --> 

              <?php if (!empty($related_content) && !empty($node->field_story_template_buzz[LANGUAGE_NONE])) { ?>
                    <div class="related-story related-story-bottom">
    <?php
    $block = module_invoke('itg_front_end_common', 'block_view', 'related_story_bottom_block');
    print render($block['content']);
    ?>
                    </div>
                    <!-- For buzzfeed section end --> 
                  <?php } 
                  
                if(!empty($node->field_story_configurations['und'])) {
                                 foreach ($node->field_story_configurations['und'] as $value) {
                                   $config[] = $value['value'];
                                 }
                               }
                  ?>

              </div>

              <?php
              if (function_exists('taboola_view')) {
                taboola_view();
              }
              ?>

                  <?php
                  if ($config_name == 'vukkul' && in_array('comment', $config)) {
                    if (!empty($node->field_story_comment_question['und'][0]['value'])) {
                    $question = 'Q:'.$node->field_story_comment_question['und'][0]['value'];
                  }
                  ?>
              <div class="c_ques"><?php print $question; ?></div>
                <div class="vukkul-comment">
                    <div id="vuukle-emote"></div>
                    <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

                </div>
    <?php
                }
                if ($config_name == 'other' && in_array('comment', $config)) {
                 ?>
                    <div id="other-comment">
                        <?php
                        $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
                        print render($block['content']);
                        ?>
                    </div>
                  <?php
                } ?>
          </div>            
      </div>               

<?php endif; ?>