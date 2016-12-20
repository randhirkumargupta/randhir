<?php
if (!empty($content)):
    global $base_url;
    ?>
    <?php
    if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
        $class_buzz = 'buzz-feedback';
    }
    // prepare url for sharing
    $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    $short_url = shorten_url($actual_link, 'goo.gl');
    $fb_title = addslashes($node->title);
    $share_desc = '';
    $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
    if (function_exists(itg_facebook_share_count)) {
    $fb_count = itg_facebook_share_count($actual_link);
    }

    if (function_exists(itg_google_share_count)) {
      $google_count = itg_google_share_count($actual_link);
    }

    $fb_google_count = $fb_count + $google_count;
  ?>
    <div class="story-section <?php print $class_buzz; ?>">
        <div class='<?php print $classes ?>'>
            <?php //pr($node);  ?> 
            <div class="comment-mobile desktop-hide">
                <ul>
                    <li><a href="#"><i class="fa fa-envelope"></i> Mail to author</a></li>
                    <li><a href="#"><i class="fa fa-whatsapp"></i></a></li>
                    <li><a href="#"><i class="fa fa-comment"></i></a></li>
                    <li><a href="#"><i class="fa fa-share-alt"></i></a></li>              
                </ul>

            </div>
            <h1><?php print $node->title; ?></h1>
            <div class="story-left-section">
                <?php if (empty($node->field_story_template_buzz[LANGUAGE_NONE]) && empty($node->field_story_listicle[LANGUAGE_NONE])) { ?>
                    <div class="story-left">
                        <div class="byline"><?php
                            $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
                            $reporter_node = node_load($byline_id);
                            ?>                      
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
                                        <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];                                        ?></li>                
                                    <?php } ?>
                                </ul>
                                <ul class="date-update">
                                    <li class="mailto mhide"><i class="fa fa-envelope-o"></i> &nbsp;<?php
                                        $email = $reporter_node->field_reporter_email_id[LANGUAGE_NONE][0]['value'];
                                        print "<a href='mailto:support@indiatoday.in'>Mail To Author</a>";
                                        ?></li>
                                    <li class="mhide"><span class="share-count"><?php if(!empty($fb_google_count)) { print $fb_google_count;} else { print 0; } ?></span>SHARES</li>
                                    <li><?php print date('F j, Y', $node->created); ?>   </li>
                                    <li>UPDATED <?php print date('H:i', $node->changed); ?> IST</li>
                                    <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></li>
                                </ul>
                                <ul class="social-links mhide">
                                    <li><a href="javascript:" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a></li>
                                    <li><a href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                                    <li><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                                        <?php
                                        if (function_exists(global_comment_last_record)) {
                                          $last_record = $global_comment_last_record;
                                          $config_name = trim($last_record[0]->config_name);
                                        }
                                        if ($config_name == 'vukkul') {
                                          ?>
                                          <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
                                        <?php } if ($config_name == 'other') { ?> 
                                          <li><a class="def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
                                        <?php } ?>
                              
                                    <?php global $user; ?>
                                    <?php if ($user->uid > 0): ?>
                                        <?php $read_later = flag_create_link('my_saved_content', $node->nid); ?>                      
                                        <li><?php print $read_later; ?></li>
                                    <?php else: ?>
                                        <?php print '<li>' . l('<i class="fa fa-bookmark"></i> READ LATER', 'user/login', array('html' => TRUE, 'attributes' => array('title' => 'READ LATER'))) . '</li>'; ?>
                                    <?php endif; ?>                      
                                </ul>
                            </div>
                        </div>
                        <?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
                            <div class="briefcase mhide">
                                <h4><?php print t('Briefcase'); ?></h4>
                                <ul>
                                    <?php
                                    foreach ($node->field_story_highlights['und'] as $high) {
                                        print '<li>' . $high['value'] . '</li>';
                                    }
                                    ?>
                                </ul>
                            </div>
                        <?php } ?>
                    </div>  
                <?php } ?>
                <div class="story-right <?php
                if (!empty($node->field_story_listicle[LANGUAGE_NONE])) {
                    echo 'listicle-page';
                }
                ?>">
                         <?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE]) || !empty($node->field_story_listicle[LANGUAGE_NONE])) { ?>
                        <!-- For buzzfeed section start -->
                        <div class="byline"><?php
                            $byline_id = $node->field_story_reporter[LANGUAGE_NONE][0]['target_id'];
                            $reporter_node = node_load($byline_id);
                            ?>
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
                                        <li class="twitter"><a href="https://twitter.com/<?php print $twitter_handle; ?>" class="twitter-follow-button" data-show-count="false">Follow @TwitterDev</a><script async src="//platform.twitter.com/widgets.js" charset="utf-8"></script><?php //print $reporter_node->field_reporter_twitter_handle[LANGUAGE_NONE][0]['value'];                                       ?></li>                
                                    <?php } ?>
                                </ul>
                                <ul class="date-update">
                                    <li><?php print date('F j, Y', $node->created); ?>   </li>
                                    <li>UPDATED <?php print date('H:i', $node->changed); ?> IST</li>
                                    <li><?php print $node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name; ?></li>
                                </ul>
                            </div>
                        </div>

                        <!-- For buzzfeed section end -->

                    <?php } ?>

                    <?php
                    if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                        // imgtags" img-fid="<?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid'];" use for image tagging
                        ?>
                        <div class="stryimg" ><?php
                            $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];

                            $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);

                            $file_uri = file_create_url($story_image);
                            print '<img alt="" src="' . $file_uri . '">';
                            if (!empty($getimagetags)) {

                                foreach ($getimagetags as $key => $tagval) {
                                    $urltags=addhttp($tagval->tag_url);
                                    print '<div class="tagview" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;" ><div class="square"></div><div  class="person" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;"><a href="'.$urltags.'" target="_blank">' . ucfirst($tagval->tag_title) . '</a></div></div>';;

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
                    print theme('image_style', array('style_name' => 'buzz_image', 'path' => $story_image));
                            ?>
                            <?php } ?>
                            <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
                                <div class="photoby"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']; ?></div>
                            <?php } ?>
                        </div>
                        <?php if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'])) { ?>    
                        <div class="image-alt"><?php print $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']; ?></div>
                        <?php } ?>
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
                              $factoidsSocialShare['share_desc'] = $node->field_story_template_factoids[LANGUAGE_NONE][0]['value'];
                              $factoidsSocialShare['icons'] = '<div class="factoids-page">
                                 <div class="fun-facts"><h2>' . $factoidsSocialShare['title'] . '</h2> </div><div class="social-share"><ul>     
                                 <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
                                 <li><a class="facebook" href="javascript:void(0)" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . addslashes(htmlspecialchars($factoidsSocialShare['title'], ENT_QUOTES)) . "'" . ', ' . "'" . $factoidsSocialShare['share_desc'] . "'" . ', ' . "'" . $img . "'" . ')"><i class="fa fa-facebook"></i></a></li>
                                 <li><a class="twitter" href="javascript:" onclick="twitter_popup(\'' . urlencode($factoidsSocialShare['share_desc']) . ',' . urlencode($short_url) . '\')"><i class="fa fa-twitter"></i></a></li>
                                 <li><a class="google" title="share on google+" href="javascript:void(0)" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')"></a></li>
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
                              if(!empty($node->field_story_expert_image[LANGUAGE_NONE][0]['uri'])) {
                              $expertDetailsImage = file_create_url($node->field_story_expert_image[LANGUAGE_NONE][0]['uri']);
                              
                              }
                              else
                              {
                                $expertDetailsImage = $base_url . '/sites/all/themes/itg/images/user-default-expert.jpg';
     
                              }
                            }
                            $expertDetails .= '<div class="right-side col-md-4 col-sm-4 col-xs-4"><img src="' . $expertDetailsImage . '"></div></div>';
                            if (!empty($node->field_story_expert_description)) {
                              $expertDetails .= '<h2>' . $node->field_story_expert_description['und'][0]['value'] . '</h2>';
                            }
                              $expertDetails .= '</div>';
                            $story_body = str_replace('[ITG:EXPERT-CHUNK]', $expertDetails, $story_body);
                          }

                          if (!empty($node->field_story_listicle[LANGUAGE_NONE])) {

                            $wrapper = entity_metadata_wrapper('node', $node);
                            $num = 1;
                            foreach ($wrapper->field_story_listicle as $i):
                              $listicletype = '';
                              print '<div class="listicle-detail">';
                              $type = $i->field_story_listicle_type->value();
                              $description = $i->field_story_listicle_description->value();
                              $color = $i->field_story_listicle_color->value();
                              $color = ($color['rgb']) ? $color['rgb'] : '#000000';
                              print '<span>' . $num . '</span>';
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
                  </div>
              </div>

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
                        $img = '<img src="' . image_style_url("buzz_image", $buzz_imguri) . '">';
                        if (!empty($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])) {
                            $buzz_output.= '<h1><span>' . $buzz . '</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
                            if (!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
                              $buzz_title = preg_replace("/'/", "\\'", $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']);
                              $buzz_title_share= htmlentities($buzz_title, ENT_QUOTES);
                              $buzz_output.= '<div class="buzz-img"><div class="social-share">
              <ul>
              <li><a href="javascript:void(0)" class="share"><i class="fa fa-share-alt"></i></a></li>
              <li><a class= "facebook def-cur-pointer" onclick="fbpop(' . "'" . $actual_link . "'" . ', ' . "'" . $buzz_title_share . "'" . ', ' . "'" . $share_desc . "'" . ', ' . "'" . $share_image . "'" . ', ' . "'" . $base_url . "'". ', ' . "'" . $nid . "'".')" class="facebook"><i class="fa fa-facebook"></i></a></li>
              <li><a href="javascript:" onclick="twitter_popup(' . "'" . urlencode($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']) . "'" . ', ' . "'" . urlencode($short_url) . "'" . ')" class="twitter"><i class="fa fa-twitter"></i></a></li>
              <li><a title="share on google+" href="#" onclick="return googleplusbtn(' . "'" . $actual_link . "'" . ')" class="google"><i class="fa fa-google-plus"></i></a></li>
              </ul>
          </div>' . $img . '</div>';
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
                  $get_val = '0'.arg(1);
                  $like = itg_flag_get_count($get_val, 'like_count');
                  $dislike = itg_flag_get_count($get_val, 'dislike_count');
                  if (!empty($like)) {
                    $like_count = $like;
                  }
                  if (!empty($dislike)) {
                    $dislike_count = $dislike;
                  }
                  $pid = "voted_" . $get_val;
                  $like = "no-of-likes_" . $get_val;
                  $dislike = "no-of-dislikes_" . $get_val;
                 
                  ?>
                  <div class="agbutton story-like-dislike">
                      <div id="name-dv"><?php print t('Do You Like This Story'); ?>
                      <span id="lky"><button id="like_count" rel="<?php print $get_val; ?>" data-tag="sty"><i class="fa fa-thumbs-o-up"></i> <span id="<?php print $like; ?>"><?php print $like_count; ?></span> </button>
                          <span id="sty-dv" style="display:none">Awesome! </br> Now share the story </br> <a onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>')"><i class="fa fa-facebook"></i></a> 
                          <a href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>
                          <a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>
                          <?php
                              if ($config_name == 'vukkul') {
                                ?>
                          <a onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                          <?php } if ($config_name == 'other') { ?> 
                                <a onclick ="scrollToAnchor('other-comment');" title="comment" class="def-cur-pointer"><i class="fa fa-comment"></i></a>
                              <?php } ?>
                          </span></span>
                            <span id="dlky"> <button id="dislike_count" rel="<?php print $get_val; ?>" data-tag="dsty"><i class="fa fa-thumbs-o-down"></i> <span id="<?php print $dislike; ?>"><?php print $dislike_count; ?></span></button>
                                <?php
                              if ($config_name == 'vukkul') {
                                ?>
                                <span id="dsty-dv" style="display:none"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment">Too bad.</br> Tell us what you didn't like in the comment section</a></span> 
                            
                              <?php } if ($config_name == 'other') { ?> 
                                <span id="dsty-dv" style="display:none"><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment">Too bad.</br> Tell us what you didn't like in the comment section</a></span> 
                              <?php } ?>
                                
                            </span>                                       
                        </div>                          
                  <p class="error-msg" id="<?php print $pid; ?>"></p>
                  </div>
                
                <!-- End here -->
                
                
                <div class="section-left-bototm">
                    <div class="social-list">
                        <ul>
                            <?php if($user->uid > 0): ?>
                            <li class="mhide"><a class="def-cur-pointer colorbox-load" href="<?php print $base_url; ?>/personalization/my-content/<?php print $node->type; ?>"><i class="fa fa-share"></i></a> <span><a class="def-cur-pointer colorbox-load" href="<?php print $base_url; ?>/personalization/my-content/<?php print $node->type; ?>">Submit Your Story</a></span></li>
                            <?php else: ?>
                            <li class="mhide"><a class="def-cur-pointer colorbox-load" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $node->type; ?>"><i class="fa fa-share"></i></a> <span><a class="def-cur-pointer colorbox-load" href="<?php print $base_url; ?>/node/add/ugc?width=650&height=650&iframe=true&type=<?php print $node->type;?>">Submit Your Story</a></span></li>
                            <?php endif; ?>
                            <li class="mhide"><div id="fb-root"></div><a class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
                            <li class="mhide"><a href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
                            <li class="mhide"><a title="share on google+" href="#" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>
                              <?php
                              if ($config_name == 'vukkul') {
                                ?>
                            <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i> <span><?php  
                            if(function_exists(itg_vukkul_comment_count)) {
                              print itg_vukkul_comment_count('story_' . arg(1));
                            }
                            ?></span></a></li>
                              <?php } if ($config_name == 'other') { ?> 
                                <li class="mhide"><a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i> <span><?php print $comment_count; ?></span></a></li>
                              <?php } ?>
                            <!--<li class="mhide"><a href="#"><i class="fa fa-comment"></i></a> <span>1522</span></li>-->
                            <li class="mhide"><span class="share-count"><?php if(!empty($fb_google_count)) { print $fb_google_count;} else { print 0; } ?></span> SHARES</li>
                            <!--<li><span>Edited by</span> Arunava Chatterjee</li>-->
                            
                             <?php if ($user->uid > 0){ ?>
                                        <?php $follow_story = flag_create_link('follow', $node->nid); ?>                      
                                        <li><?php print $follow_story; ?></li>
                                          <?php
                                          }
                                          elseif ($user->uid == 0) {
                                            if ($_SERVER['HTTP_HOST'] == PARENT_SSO) {
                                              ?>

                                        <li> <a href="javascript:void(0)" onclick="CenterWindow (550, 500, 50, 'http://<?php print PARENT_SSO; ?>/saml_login/other/domain_info', 'indiatoday');" class="def-cur-pointer">follow the Story</a></li>
                                             
                                              <?php
                                            }
                                            else {
                                              ?>
                                        <li> <a href="javascript:void(0)" onclick="Go (550, 500, 50, 'indiatoday', '', '<?php print PARENT_SSO; ?>', '/saml_login/other')" class="def-cur-pointer">follow the Story</a></li>

                                              <?php
                                            }
                                          }
                                          ?>    
                                  
                        </ul>
                    </div>

                    <?php if (!empty($node->field_story_snap_post[LANGUAGE_NONE][0]['value'])) { ?>    
                        <div class="snap-post">
                            <div class="discription"><?php print $node->field_story_snap_post[LANGUAGE_NONE][0]['value']; ?></div>
                            <?php
                            $like = itg_flag_get_count(arg(1), 'like_count');
                            $dislike = itg_flag_get_count(arg(1), 'dislike_count');
                            if (!empty($like)) {
                                $like_count = '(' . $like . ')';
                            }
                            if (!empty($dislike)) {
                                $dislike_count = '(' . $dislike . ')';
                            }
                            $pid = "voted_" . arg(1);
                            $like = "no-of-likes_" . arg(1);
                            $dislike = "no-of-dislikes_" . arg(1);
                            ?>
                            <div class="agbutton"><button id="like_count" rel="<?php print arg(1); ?>">Like <span id="<?php print $like; ?>"><?php print $like_count; ?></span> </button> <button id="dislike_count" rel="<?php print arg(1); ?>">Dislike <span id="<?php print $dislike; ?>"><?php print $dislike_count; ?></span></button>  <a href="<?php echo $base_url; ?>/snappost"> More from Snap post</a><p class="error-msg" id="<?php print $pid; ?>"></p></div>
                        </div>
                    <?php } ?>
                    <div class="tags">
                        <ul>
                            <li><i class="fa fa-tags"></i> Tags :</li>        
                            <?php
                            foreach ($node->field_story_itg_tags['und'] as $tags) {
                                $published_tag = $tags['taxonomy_term']->field_tags_status[LANGUAGE_NONE][0]['value'];
                                if ($published_tag == 'Published') {
                                    $term = taxonomy_term_load($tags['tid']);
                                    $t_name = $term->name;
                                    $comma_sep_tag[] = $t_name;
                                    print '<li>#' . $t_name . '</li>';
                                }
                            }
                            ?>
                        </ul>
                    </div>
                </div>

                <?php
                if (function_exists('taboola_view')) {
                    taboola_view();
                }
                ?>

                <?php
                if (function_exists(global_comment_last_record)) {
                    $last_record = $global_comment_last_record;
                    $config_name = trim($last_record[0]->config_name);
                }
                if ($config_name == 'vukkul') {
                    ?>
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
                if ($config_name == 'other') {
                    ?>
                    <div id="other-comment">
                        <?php print render($content['comment_form']); ?>
                        <?php print render($content['comments']); ?>
                    </div>
                <?php } ?>
            </div>
        </div>
    <?php endif; ?>
