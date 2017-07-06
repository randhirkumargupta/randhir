<?php
global $base_url, $user;
if (!empty($content)):
  // get related content associated with story
  $related_content = $content['related_content'];
  // condition for buzz
  $class_buzz = '';
  if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
    $class_buzz = 'buzz-feedback';
  }
  $class_related = '';
  if (!empty($related_content)) {
    $class_related = ' buzz-related';
  }
  $class_listicle = '';
  if (!empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
    $class_listicle = ' buzz-feedback listicle-feedback';
  }
  // prepare url for sharing
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
  $short_url = shorten_url($actual_link, 'goo.gl');
  $fb_title = addslashes($node->title);
  $share_desc = '';
  $image = '';
  if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
  }

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

  $migrated_count = $content["migrated_count"];
  //get byline id based on order reorder

  $byline_id = $content["byline_id"];

  //get byline detail
  $reporter_node = '';
  if (!empty($byline_id)) {
    $reporter_node = node_load($byline_id);
  }
  
  // get posted by info
  $node_author = $content["author"];
  /*if (function_exists('itg_get_front_activity_info')) {
    $opt = $content["front_activity_info"];
  }*/
  $opt = $content["front_activity_info"];
  $photo_story_section_class = '';
  if ($node->field_story_type[LANGUAGE_NONE][0]['value'] == 'photo_story') {
    $photo_story_section_class = ' photo-story-section';
  }
  ?>
  <div class="story-section <?php print $class_buzz . "" . $class_related . "" . $class_listicle. $photo_story_section_class;?>">
    <div class='<?php print $classes ?>'>      
      
      <?php
      $pipelinetext = "";
      if (!empty($node->field_story_new_title) && !empty($node->field_story_redirection_url_titl)) {
        $pipelinetext = ' <span class="story-pipline">||</span> <a target="_blank" href="' . $node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'] . '">' . ucfirst($node->field_story_new_title[LANGUAGE_NONE][0]['value']) . '</a>';
      }
      if (!empty($get_develop_story_status)) {
        ?>
      <h1  title="<?php echo strip_tags($content['amp_title']);?>"><?php print $content['amp_title'] . $pipelinetext; ?> <i class="fa fa-circle" aria-hidden="true" title="Development story"></i></h1>
          <?php
        }
        else {
          ?>
        <h1 title="<?php echo strip_tags($content['amp_title']);?>"><?php print $content['amp_title'] . $pipelinetext; ?></h1>
      <?php } ?>
      <?php
      //code for Associate lead
      $associate_type = '';
      $associate_id = '';

      if (isset($node->field_story_associate_lead[LANGUAGE_NONE][0]['value']) && $node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
        $associate_type = 'gallery';
        $associate_id = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
      }
      else if (isset($node->field_story_associate_lead[LANGUAGE_NONE][0]['value']) && $node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') {
        $associate_type = 'video';
        $associate_id = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
      }

      $clidk_class_slider = "";
      $widget_data = '';

      if ($associate_type != "" && $associate_id != "") {
        $clidk_class_slider = 'associate-content-block';
        $widget_data = $associate_type . '-' . $associate_id;
      }

      //code end for Associate lead
      ?>

      <div class="story-left-section">
        <?php if (empty($node->field_story_template_buzz[LANGUAGE_NONE]) && empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>
          <div class="story-left"> 
              <div class="posted-by">
                  <span><?php if(!empty($reporter_node->title)) { print t('By ' . $reporter_node->title) . ' | '; } ?></span>
                  <span><?php print date('F j, Y', $node->created); ?>   </span>
              </div>
          </div>
        <?php } ?>
        <!-- For buzzfeed section start -->
        <?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE]) || !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>                       
          <div class="buzzfeed-byline">
            <div class="posted-by">
                  <span><?php if(!empty($reporter_node->title)) { print t('By ' . $reporter_node->title) . ' | '; } ?></span>
                  <span><?php print date('F j, Y', $node->created); ?>   </span>
              </div>
          </div>

        <?php } ?>
        <!-- Check the story type whether it is a photo story or not-->
        <?php if ((!empty($node->field_story_type) && $node->field_story_type[LANGUAGE_NONE][0]['value'] == 'other_story') || (empty($node->field_story_type))) { ?>
          <div class="story-right <?php
          if (!empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
            echo 'listicle-page';
          }
          ?>">
          <?php
             //associate_lead
             $associate_lead = $node->field_story_associate_lead[LANGUAGE_NONE][0]['value'];
             $associate_photo = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id'];
             $associate_video = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id'];
             $class = '';
             if (!empty($associate_lead) && (isset($associate_photo) || isset($associate_video))) {
               $class = 'story-associate-content';
             }
          ?>
            <div class="<?php echo $class; ?>">
              <?php if (!empty($associate_lead) && (isset($associate_photo) || isset($associate_video))) { ?>
                <!--<div id="videogallery-iframe">
                  <img class="loading-popup" src="<?php print $base_url; ?>/sites/all/themes/itg/images/reload.gif" alt="loading" />
                </div>-->
              <?php } ?>                      
              <?php
              if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                ?>
                <div class="stryimg" ><?php
                  if (empty($widget_data) && empty($node->field_story_template_guru[und][0][value])) {
                    $story_image = '';
                    if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    }
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    else {
                      $file_uri = $base_url . '/sites/all/themes/itg/images/itg_image647x363.jpg';
                    }
                    print '<amp-img height="363" width="647" layout="responsive"  alt="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'].'" title="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'].'" src="' . $file_uri . '"></amp-img>';
                  }
                  else {
                    if(empty($node->field_story_template_guru[und][0][value])) {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    else {
                      $file_uri = $base_url . '/sites/all/themes/itg/images/itg_image647x363.jpg';
                    }
                    print '<a href="javascript:void(0);" class="' . $clidk_class_slider . '" data-widget="' . $widget_data . '">'
                        . '<amp-img height="363" width="647" layout="responsive"  alt="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'].'" title="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'].'" src="' . $file_uri . '"></amp-img>'
                        . '<span class="story-photo-icon">';
                    ?>        

                    <?php if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'video') { ?>
                      <!--<i class="fa fa-play-circle"></i>-->
                      <?php
                    }
                    else if ($node->field_story_associate_lead[LANGUAGE_NONE][0]['value'] == 'gallery') {
                      ?>                    
                      <!--<i class="fa fa-camera"></i>-->
                      <?php
                    }
                    print '</span></a>';
                    }
                  }
                  ?>

                  <?php
                  if (!empty($getimagetags)) {
                    foreach ($getimagetags as $key => $tagval) {
                      $urltags = addhttp($tagval->tag_url);
                      print '<div class="tagview" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;" ><div class="square"></div><div  class="person" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;"><a href="' . $urltags . '" target="_blank">' . ucfirst($tagval->tag_title) . '</a></div></div>';
                    }
                  }
                 
                  ?>
                  <?php
                }
                else {
                  ?>

                  <div class="stryimg"><?php
                    
                    
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    
                    if (!empty($getimagetags)) {
                      $file_uri = file_create_url($story_image);
                    }
                    else {
                      $file_uri = $base_url . '/sites/all/themes/itg/images/itg_image647x363.jpg';
                    }
            
                    print '<a href="javascript:void(0);" class="' . $clidk_class_slider . '" data-widget="' . $widget_data . '">'
                        . '<amp-img height="363" width="647" layout="responsive"  alt="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt'].'" title="'.$node->field_story_extra_large_image[LANGUAGE_NONE][0]['title'].'" src="' . $file_uri . '"></amp-img>'
                        . '</a>';
                    if (!empty($getimagetags)) {
                      foreach ($getimagetags as $key => $tagval) {
                        $urltags = addhttp($tagval->tag_url);
                        print '<div class="tagview" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;" ><div class="square"></div><div  class="person" style="left:' . $tagval->x_coordinate . 'px;top:' . $tagval->y_coordinate . 'px;"><a href="' . $urltags . '" target="_blank">' . ucfirst($tagval->tag_title) . '</a></div></div>';
                      }
                    }
                    ?>
                  <?php } 
                  if (function_exists('itg_story_get_image_info')) {
                    $getImageInfo = itg_story_get_image_info($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                  } ?>
                      
                  <?php if (!empty($node->field_story_extra_large_image[LANGUAGE_NONE])) { ?>
                    <?php if(empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>
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
                      <?php if (isset($getImageInfo[0]->image_photo_grapher) && !empty($getImageInfo[0]->image_photo_grapher)) { ?>
                        <div class="photoby-text"><?php print $getImageInfo[0]->image_photo_grapher; ?></div>
                      <?php } ?>
                    </div>
                  <?php } }?>     



                </div>
                <?php if (isset($getImageInfo[0]->image_caption) && empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>    
                  <div class="image-alt"><?php print $getImageInfo[0]->image_caption; ?></div>
                <?php } ?>                            
              </div>
              <div class="story-movie">
                <?php if (!empty($node->field_story_rating)): ?>
                  <div class="movie-rating">
                      <div class="grey-star"><amp-img src="<?php print $base_url .'/'. path_to_theme().'/images/rating-grey.png'?>" width="111" height="18"></amp-img></div>
                      <div class="red-star" style="width: <?php print $node->field_story_rating[LANGUAGE_NONE]['0']['value'] * 22 . "px"; ?>"><amp-img src="<?php print $base_url .'/'. path_to_theme().'/images/rating-red.png'?>" width="111" height="18"></amp-img></div>
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
                // check video is delete form video content   
                if (function_exists('itg_videogallery_remove_delete_video_form_body_html_body')) {
                  itg_videogallery_remove_delete_video_form_body_html_body($story_body);
                }
                if (strpos($story_body, '[ITG:FACTOIDS]')) {
                  $factoidsBlock = '';
                  if (isset($node->field_story_template_factoids) && !empty($node->field_story_template_factoids)) {
                    $factoidsSocialShare['title'] = $node->field_story_factoids_title[LANGUAGE_NONE][0]['value'];
                    $factoidsSocialShare_title = preg_replace("/'/", "\\'", $factoidsSocialShare['title']);
                    $factoidsSocial_share_title = htmlentities($factoidsSocialShare_title, ENT_QUOTES);
                    $factoidsSocialShare['share_desc'] = $node->field_story_template_factoids[LANGUAGE_NONE][0]['value'];
                    $factoidsSocialShare['icons'] = '<div class="factoids-page">
                                 <div class="fun-facts"><h2>' . t('Funfacts') . '</h2> </div></div>';
                    $factoidsSocialShare['slider'] = '<div class="factoids-slider"><ul>';
                    foreach ($node->field_story_template_factoids[LANGUAGE_NONE] as $key => $value) {
                      $factoidsSocialShare['slider'] .='<li><span>' . $value['value'] . '</span></li>';
                    }
                    $factoidsSocialShare['slider'] .= '</ul></div>';
                    $factoidsBlock = $factoidsSocialShare['icons'] . $factoidsSocialShare['slider'];
                  }
                  $story_body = str_replace('[ITG:FACTOIDS]', $factoidsBlock, $story_body);
                }
                
                $movie_html = itg_story_movie_image_plugin_data($node->nid, 'amp');
                if (strpos($story_body, '[ITG:TECH-PHOTOS]')) {
                  if (!empty($node->field_story_technology['und'])) {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', $movie_html, $story_body);
                  }
                  else {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', '', $story_body);
                  }
                }
                if (isset($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
                  print '<h3 class="listical_title">' . $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] . '</h3>';
                }

                if (!empty($node->field_story_listicle[LANGUAGE_NONE]) && !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
                  $buzz_output.= '';
                  $num = 1;
                  foreach ($node->field_story_listicle['und'] as $buzz_item) {
                    $listicletype = '';
                    $listicle_output.= '<div class="listicle-detail">';
                    $field_collection_id = $buzz_item['value'];
                    $entity = entity_load('field_collection_item', array($field_collection_id));
                    $type = $entity[$field_collection_id]->field_story_listicle_type['und'][0]['value'];
                    $description = $entity[$field_collection_id]->field_story_listicle_description['und'][0]['value'];
                    //$color = $entity[$field_collection_id]->field_listicle_color['und'][0]['value'];
                    $color = $entity[$field_collection_id]->field_listicle_color_new['und'][0]['jquery_colorpicker'];
                    $li_type = $node->field_story_templates[LANGUAGE_NONE][0]['value'];
                    $color = ($color) ? $color : '#000000';
                    if ($li_type == 'bullet_points') {
                      $listicle_output.= '<span class="bullet_points"></span>';
                    }
                    else {
                      $listicle_output.= '<span>' . $num . '</span>';
                    }
                    if (isset($type)) {
                      $listicletype = '<span class="listicle-type" style="color: #' . $color . '">' . $type . ': </span>';
                    }
                    $listicle_output.= '<div class="listicle-description">' . $listicletype . $description . '</div>';
                    $listicle_output.= '</div>';
                    $num++;
                  }
                  print $listicle_output;
                }
                else {
                  // Print story body
                  print $story_body;
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
          <?php
        }
        else {
          ?>
          <div class="story-right <?php
      if (!empty($node->field_story_type[LANGUAGE_NONE])) {
        echo 'photo-story';
      }
          ?>">
               <?php
                 if (!empty($node->field_photo_story)) {
                   //$output = itg_story_photo_story_html($node->nid);
                   $output = itg_story_photo_amp_html($node->nid);
                   print $output;
                 }
                 ?>
            <!-- for photo story bottom slider, loop has been repeated again -->
            <?php
            if (!empty($node->field_photo_story)) {
              //$html_output = itg_story_photo_story_bottom_html($node->nid);
              $html_output = itg_story_photo_amp_bottom_html($node->nid);
              print $html_output;
            }
            ?>
          </div>
        <?php } ?>
        <div class="clearfix"></div>
        <!-- condition for buzz  -->

        <?php
        $buzz_output = '';
        if (!empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
          $buzz_output.= '';
          $buzz = 1;
          foreach ($node->field_story_template_buzz['und'] as $buzz_item) {
            $buzz_output.= '<div class="buzz-section">';
            $field_collection_id = $buzz_item['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $buzz_imguri = '';
            if(!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
            $buzz_imguri = _itg_photogallery_fid($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
            }
            $share_uri = '';
            if(!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
            $file = file_load($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
            $share_uri = $file->uri;
            }
            
            $share_image = file_create_url($share_uri);
            //$img = '<img title="' . $entity[$field_collection_id]->field_buzz_image['und'][0]['title'] . '" src="' . image_style_url("buzz_image", $buzz_imguri) . '" alt="' . $entity[$field_collection_id]->field_buzz_image['und'][0]['alt'] . '" />';
            $img = '<amp-img height="539" width="770" layout="responsive"  alt="'.$entity[$field_collection_id]->field_buzz_image['und'][0]['alt'].'" title="'.$entity[$field_collection_id]->field_buzz_image['und'][0]['title'].'" src="' . image_style_url("buzz_image", $buzz_imguri) . '"></amp-img>';
            if (!empty($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])) {
              $buzz_output.= '<h1><span>' . $buzz . '</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
              if (!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
                $buzz_title = preg_replace("/'/", "\\'", $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']);
                $buzz_title_share = htmlentities($buzz_title, ENT_QUOTES);
                if (function_exists('itg_story_get_image_info')) {
                    $getImageInfo = itg_story_get_image_info($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
                }
                $buzz_output.= '<div class="buzz-img-wrapper"><div class="buzz-img"><div class="social-share">
              <ul>
              <li><i class="fa fa-share-alt"></i></li>
              
              <li><amp-social-share type="twitter" width="25" height="25"
              data-param-text="' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '"
              data-param-url="' . $short_url . '">
              </amp-social-share>
              </li>
              
              <li><amp-social-share type="facebook" width="25" height="25"
              data-param-app_id="254325784911610" data-param-quote="' . $buzz_title_share . '"
              data-param-url="' . $actual_link . '"></amp-social-share>
              </li>
                
              <li><amp-social-share type="gplus" width="25" height="25"
              data-param-url="'.$actual_link.'">
              </amp-social-share>
              </li>
              
              </ul>
          </div>' . $img . '</div><div class="photoby">' . $getImageInfo[0]->image_photo_grapher . '</div></div><div class="image-alt">' . $getImageInfo[0]->image_caption . '</div>';
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

        <div class="section-left-bototm">
        </div>
        <div class="amp-taboola">
        <amp-embed width=100 height=500
             type=taboola
             layout=responsive
             heights="(min-width:1907px) 39%, (min-width:1200px) 46%, (min-width:780px) 64%, (min-width:480px) 98%, (min-width:460px) 167%, 196%"
             data-publisher="amp-demo"
             data-mode="thumbnails-a"
             data-placement="Ads Example"
             data-article="auto">
        </amp-embed>
        </div>
          <!-- code for related content -->   
          <?php if (!empty($related_content) && empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>
            <div class="related-story related-story-bottom">
              <?php
              $block = module_invoke('itg_front_end_common', 'block_view', 'related_story_amp_block');
              print render($block['content']);
              ?>
            </div>
            <!-- For buzzlfeed section end --> 
            <?php
          }
          ?>
             
      </div>            
    </div>               

  <?php endif; ?>