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
  $actual_link = 'http://' . $_SERVER['HTTP_HOST'] .'/amp'. $_SERVER['REQUEST_URI'];
  $amp_link = str_replace('?amp', '', $actual_link);
  $short_url = $amp_link;
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

  $byline_id_mobile = $byline_id = $content["byline_id"];

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
  $node_title = $content['amp_title'];
  $node_image_alt = '';
  $node_image_title = '';
  $node_image_alt = str_replace(array('\'', '"'), '', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['alt']); 
  $node_image_title = str_replace(array('\'', '"'), '', $node->field_story_extra_large_image[LANGUAGE_NONE][0]['title']);
  // source type array
  $source_type_arr = array('PTI' , 'IANS', 'ANI');
  // Rich Snippet for Story
$mainEntityOfPage = FRONT_URL . '/' . $node->path['alias'];
if (is_array($node->workbench_moderation) && !empty($node->workbench_moderation) && $node->workbench_moderation['current']->state == 'published') {
$publisheddate = date('Y-m-d\TH:i:s+5:30', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value']));
} else {
$publisheddate = date('Y-m-d\TH:i:s+5:30', $node->changed);
}
$modified_date = date('Y-m-d\TH:i:s+5:30', $node->changed);
$description = strip_tags(substr(str_replace("&#13;", "", $node->body[LANGUAGE_NONE][0]['value']),0,120));
$story_kicker = strip_tags(str_replace(array('&#13;','"'), "", $node->field_story_kicker_text[LANGUAGE_NONE][0]['value']));
$meta_description = $node->metatags[LANGUAGE_NONE]['description']['value'];
$description_text = !empty($story_kicker) ? $story_kicker : $meta_description;
$logo = FRONT_URL . '/' . drupal_get_path('theme', $theme_key) . '/logo.png';
  ?>
  <div class="story-section <?php print $class_buzz . "" . $class_related . "" . $class_listicle. $photo_story_section_class;?>" itemscope="" itemtype="http://schema.org/NewsArticle" id="story">
    <link itemprop="mainEntityOfPage" href="<?php print $mainEntityOfPage; ?>"/>
    <div itemprop="publisher" itemscope="" itemtype="https://schema.org/Organization">
		<div itemprop="logo" content="<?php print $logo; ?>" itemscope="" itemtype="https://schema.org/ImageObject">
			<meta itemprop="url" content="<?php print $logo; ?>">
			<meta itemprop="width" content="600">
			<meta itemprop="height" content="60">
		</div>
		<meta itemprop="name" content="India Today">
		<link itemprop="sameAs" href="https://www.indiatoday.in">
	</div>
    <div class='<?php print $classes ?>'>      
      
      <?php
      $pipelinetext = "";
      if (!empty($node->field_story_new_title) && !empty($node->field_story_redirection_url_titl)) {
        $pipelinetext = ' <span class="story-pipline">||</span> <a target="_blank" href="' . $node->field_story_redirection_url_titl[LANGUAGE_NONE][0]['value'] . '">' . ucfirst($node->field_story_new_title[LANGUAGE_NONE][0]['value']) . '</a>';
      }
      if (!empty($get_develop_story_status)) {
        ?>
      <h1  title="<?php echo strip_tags($node_title);?>"><?php print $content['amp_title'] . $pipelinetext; ?> <i class="fa fa-circle" aria-hidden="true" title="Development story"></i></h1>
          <?php
        }
        else {
          ?>
        <h1 title="<?php echo strip_tags($node_title);?>"><?php print $content['amp_title'] . $pipelinetext; ?></h1>
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
                  <?php
				  $byline_detail = $byline_id[0];
				  $extra_large_file = file_load($byline_detail['extra_large_image']);
					$bylineextra_large_image = $extra_large_file->uri;
					?>
					<div class="profile-pic">
					  <?php
					  if(!empty($bylineextra_large_image)) {
						  $file = image_style_url('user_picture', $bylineextra_large_image);
						}
						else {
						  $file = file_create_url(file_default_scheme() . '://images/default-user.png');
						}
						print '<amp-img height="50" width="50" layout="responsive" alt="" title="" src="'.$file.'"></amp-img>';
					  ?>
					</div>
					<div class="profile-detail">
					<ul class="profile-byline">
						<span itemprop="author" itemscope="" itemtype="https://schema.org/Person">
					<?php
					  if(is_array($byline_id_mobile) && count($byline_id_mobile) > 0) {
					   echo '<li><ul>';	  	
					   foreach($byline_id_mobile as $mobile_key => $mobile_val) {
						  if (!empty($mobile_val['title'])) { ?>	 
							 <li class="title" itemprop="name"><?php if(!empty($mobile_val['title'])) { print t($mobile_val['title']); } ?></li>
						<?php }      	
						   }
					  echo '</ul></li>';
						} 
					  if (!empty($node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name)) {
						?>
						<li><?php
							$city = array();
							foreach ($node->field_stroy_city[LANGUAGE_NONE] as $key => $term_value) {
							  $city[] = $node->field_stroy_city[LANGUAGE_NONE][$key]['taxonomy_term']->name;
							}
							print implode(' | ', $city);
							?>
						</li>
						<?php 
						  } 
						?>
					  <li itemprop="datePublished" content="<?php print $publisheddate; ?>"><?php print date('F j, Y', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'])); ?> <span itemprop="dateModified" content="<?php print $modified_date; ?>">UPDATED</span> 
					  <?php
					  if (in_array($node->field_story_source_type[LANGUAGE_NONE][0]['value'], $source_type_arr)) {
							print date('H:i', $node->created);
						}
						else {
							print date('H:i', $node->changed);
						}
					  ?>
					   IST </li>
					  </ul>
                 </div>
              </div>
          </div>
        <?php } ?>
        <!-- For buzzfeed section start -->
        <?php if (!empty($node->field_story_template_buzz[LANGUAGE_NONE]) || !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>                       
          <div class="buzzfeed-byline">
            <div class="posted-by">
                  <?php
				  $byline_detail = $byline_id[0];
				  $extra_large_file = file_load($byline_detail['extra_large_image']);
					$bylineextra_large_image = $extra_large_file->uri;
					?>
					<div class="profile-pic">
					  <?php
					  if(!empty($bylineextra_large_image)) {
						  $file = image_style_url('user_picture', $bylineextra_large_image);
						}
						else {
						  $file = file_create_url(file_default_scheme() . '://images/default-user.png');
						}
						print '<amp-img height="50" width="50" layout="responsive" alt="" title="" src="'.$file.'"></amp-img>';
					  ?>
					</div>
					<div class="profile-detail">
					<ul class="profile-byline">
					<span itemprop="author" itemscope="" itemtype="https://schema.org/Person">
					<?php
					  if(is_array($byline_id_mobile) && count($byline_id_mobile) > 0) {
					   echo '<li><ul>';	  	
					   foreach($byline_id_mobile as $mobile_key => $mobile_val) {
						  if (!empty($mobile_val['title'])) { ?>	 
							 <li class="title" itemprop="name"><?php if(!empty($mobile_val['title'])) { print t($mobile_val['title']); } ?></li>
						<?php }      	
						   }
					  echo '</ul></li>';
						} 
					  if (!empty($node->field_stroy_city[LANGUAGE_NONE][0]['taxonomy_term']->name)) {
						?>
						<li><?php
							$city = array();
							foreach ($node->field_stroy_city[LANGUAGE_NONE] as $key => $term_value) {
							  $city[] = $node->field_stroy_city[LANGUAGE_NONE][$key]['taxonomy_term']->name;
							}
							print implode(' | ', $city);
							?>
						</li>
						<?php 
						  } 
						?>
					  <li><?php print date('F j, Y', strtotime($node->field_itg_content_publish_date[LANGUAGE_NONE][0]['value'])); ?> UPDATED 
					  <?php
					  if (in_array($node->field_story_source_type[LANGUAGE_NONE][0]['value'], $source_type_arr)) {
							print date('H:i', $node->created);
						}
						else {
							print date('H:i', $node->changed);
						}
					  ?>
					   IST </li>
					  </ul>
                 </div>
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
              // code for srcset
                /*$extra_large_image_src_set = '';
                if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
                 $extra_large_image_uri = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
                 $extra_large_image_data = getimagesize($extra_large_image_uri);
                 $extra_large_image_src_set = $extra_large_image_uri . ' ' . $extra_large_image_data[0] . 'w';
                }
                $large_image_src_set = '';
                if(!empty($node->field_story_large_image[LANGUAGE_NONE][0]['uri'])) {
                  $large_image_uri = file_create_url($node->field_story_large_image[LANGUAGE_NONE][0]['uri']);
                  $large_image_data = getimagesize($large_image_uri);
                  $large_image_src_set = ', ' .$large_image_uri . ' ' . $large_image_data[0] . 'w';
                }
                $medium_image_src_set = '';
                if(!empty($node->field_story_medium_image[LANGUAGE_NONE][0]['uri'])) {
                  $medium_image_uri = file_create_url($node->field_story_medium_image[LANGUAGE_NONE][0]['uri']);
                  $medium_image_data = getimagesize($medium_image_uri);
                  $medium_image_src_set = ', ' .$medium_image_uri . ' ' . $medium_image_data[0] . 'w';
                }
                $small_image_src_set = '';
                if(!empty($node->field_story_small_image[LANGUAGE_NONE][0]['uri'])) {
                  $small_image_uri = file_create_url($node->field_story_small_image[LANGUAGE_NONE][0]['uri']);
                  $small_image_data = getimagesize($small_image_uri);
                  $small_image_src_set = ', ' .$small_image_uri . ' ' . $small_image_data[0] . 'w';
                }
                $extra_small_image_src_set = '';
                if(!empty($node->field_story_extra_small_image[LANGUAGE_NONE][0]['uri'])) {
                  $extra_small_image_uri = file_create_url($node->field_story_extra_small_image[LANGUAGE_NONE][0]['uri']);
                  $extra_small_image_data = getimagesize($extra_small_image_uri);
                  $extra_small_image_src_set = ', ' .$extra_small_image_uri . ' ' . $extra_small_image_data[0] . 'w';
                }
                
                $image_repo_srcset = $extra_large_image_src_set.$large_image_src_set.$medium_image_src_set.$small_image_src_set.$extra_small_image_src_set;
                if(empty($image_repo_srcset)) {
                  $image_repo_srcset =  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image647x363.jpg').' 647w';
                }*/
              if (empty($node->field_story_template_buzz[LANGUAGE_NONE])) {
                ?>
                <div class="stryimg" ><?php
                
                  if (empty($widget_data)) {
                    $story_image = '';
                    if(!empty($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'])) {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    }
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    if (isset($file_uri)) {
                      print '<amp-img height="363" width="647" layout="responsive"  alt="'.$node_image_alt.'" title="'.$node_image_title.'" src="' . $file_uri . '"><div fallback>offline</div></amp-img>';
				    }
                  }
                  else {
                    if(empty($node->field_story_template_guru['und'][0]['value'])) {
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                    }
                    if (isset($file_uri)) {
                       print '<amp-img height="363" width="647" layout="responsive"  alt="'.$node_image_alt.'" title="'.$node_image_title.'" src="' . $file_uri . '"><div fallback>offline</div></amp-img>'
                        . '<span class="story-photo-icon">';
                    }
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
                    print '</span>';
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

                  <div class="stryimg" itemprop="associatedMedia image" itemscope="" itemtype="https://schema.org/ImageObject" id="stryimg"><?php
                     
                    $story_image = $node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri'];
                    $getimagetags = itg_image_croping_get_image_tags_by_fid($node->field_story_extra_large_image[LANGUAGE_NONE][0]['fid']);
                    if (file_exists($story_image)) {
                      $file_uri = file_create_url($story_image);
                      //$icon_detail = '<span class="story-photo-icon"><i class="fa fa-play-circle"></i>
                                    //<i class="fa fa-camera"></i></span>';
                    }
                     if (isset($file_uri)) {
                      print '<amp-img height="363" width="647" layout="responsive"  alt="'.$node_image_alt.'" title="'.$node_image_title.'" src="' . $file_uri . '" itemprop = "contentUrl"><div fallback>offline</div></amp-img>';
                     }
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
                      <?php if (!empty($node->field_story_tech_pros_cons_ratin[LANGUAGE_NONE][0]['value'])) { ?>
                        <div class="story-img-rating">
                          <?php
                          // added technology rating field value for story technology
                          $tech_rating = $node->field_story_tech_pros_cons_ratin[LANGUAGE_NONE][0]['value'];
                          echo $node->field_story_tech_pros_cons_ratin[LANGUAGE_NONE][0]['value'] . '/10';
                          ?>
                        </div>
                      <?php } ?>
                      <?php if (isset($getImageInfo[0]->image_photo_grapher) && !empty($getImageInfo[0]->image_photo_grapher)) { ?>
                        <div class="photoby-text"><?php print $getImageInfo[0]->image_photo_grapher; ?></div>
                      <?php } ?>
                    </div>
                  <?php } }?>     


				
                    <meta itemprop="url" content="<?php print $file_uri; ?>">
					<meta itemprop="width" content="647"><meta itemprop="height" content="363">
					<div class="image-alt" itemprop="description"><?php print $node_image_alt; ?></div>
                </div>
                <?php if (isset($getImageInfo[0]->image_caption) && empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) { ?>    
                  <div class="image-alt"><?php print $getImageInfo[0]->image_caption; ?></div>
											<?php } ?>                            
										</div>
							<?php if (!empty($node->field_story_highlights[LANGUAGE_NONE][0]['value'])) { ?>
								<div class="briefcase mhide">
									<h4><?php print t('HIGHLIGHTS'); ?></h4>
									<ul>
										<?php
										foreach ($node->field_story_highlights['und'] as $high) {
											print '<li>' . $high['value'] . '</li>';
										}
										?>
									</ul>
								</div>              
              <?php } ?>
              
              <div class="story-movie">
                <?php if (!empty($node->field_story_rating)): ?>
                  <div class="movie-rating" data-star-value="<?php print $node->field_story_rating[LANGUAGE_NONE]['0']['value'] * 20 . "%"; ?>">                      
                  </div>                            
                <?php endif; ?>
                <div class="movie-detail">
                   <?php if (!empty($node->field_mega_review_movie_plot)): ?>
                    <div class="plot">
                      <span class="title"> <?php print t('Movie Name:'); ?></span>                                    
                      <span class="detail"> <?php print $node->field_mega_review_movie_plot[LANGUAGE_NONE]['0']['value']; ?></span>
                    </div>
                  <?php endif; ?>  
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
                 
                </div>                            
              </div>
              <div class="description" itemprop="articleBody">
                <?php
                if(function_exists('itg_custom_amp_body_filter')) {
                $story_body = itg_custom_amp_body_filter($node->body['und'][0]['value']);
                } else {
                $story_body = $node->body['und'][0]['value'];
                }
                $story_body = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $story_body);
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
                    $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$amp_link.'&title='.$factoidsSocialShare['share_desc'];
                    $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($factoidsSocialShare['share_desc']).'&url='.$short_url.'&via=IndiaToday';
                    $google_url = 'https://plus.google.com/share?url='.  urlencode($amp_link);

                    $factoidsSocialShare['icons'] = '<div class="factoids-page">
                                 <div class="fun-facts"><h2>' . $factoidsSocialShare['title'] . '</h2> </div></div>';
                                 /*
                                  <div class="social-share">
                                  <amp-accordion disable-session-states>
                                  <section>
                                  <h2>
                                    <span class="show-more"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
                                    <span class="show-less"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
                                  </h2>
                                  <ul>     
                                 <li><a href="'.$twitter_url.'" target="_blank" title="share on twitter"><i class="fa fa-twitter-square" aria-hidden="true"></i></a></li>
                                 <li><a href="'.$fb_url.'" target="_blank" title="share on facebook"><i class="fa fa-facebook-official" aria-hidden="true"></i></a></li>
                                 <li><a href="'.$google_url.'" target="_blank" title="share on G+"><i class="fa fa-google-plus-square" aria-hidden="true"></i></a></li>
                                 </ul>
                                 </section>
                                 </amp-accordion>
                                 </div>
                                 </div>'; */
                    $factoidsSocialShare['slider'] = '<div class="factoids-slider"><div class="scroll-x"><ul>';
                    foreach ($node->field_story_template_factoids[LANGUAGE_NONE] as $key => $value) {
                      $factoidsSocialShare['slider'] .='<li><span>' . $value['value'] . '</span></li>';
                    }
                    $factoidsSocialShare['slider'] .= '</ul></div></div>';
                    $factoidsBlock = $factoidsSocialShare['icons'] . $factoidsSocialShare['slider'];
                  }
                  $story_body = str_replace('[ITG:FACTOIDS]', $factoidsBlock, $story_body);
                }
                
                // remove poll from body
                if (preg_match('/ITG:POLL:([0-9]+)/', $story_body, $matches_poll)) {
                    $poll_nid = $matches_poll[1];
                }
                if (strpos($node->body['und'][0]['value'], '[ITG:POLL:'.$poll_nid.']')) {
                  $story_body = str_replace('[ITG:POLL:'.$poll_nid.']', '', $story_body);
                }
                
                // remove quiz from body
                if (preg_match('/ITG:QUIZ:([0-9]+)/', $story_body, $matches_quiz)) {
                    $quiz_nid = $matches_quiz[1];
                }
                if (strpos($node->body['und'][0]['value'], '[ITG:QUIZ:'.$quiz_nid.']')) {
                  $story_body = str_replace('[ITG:QUIZ:'.$quiz_nid.']', '', $story_body);
                }
                
                // remove survey from body
                if (preg_match('/ITG:SURVEY:([0-9]+)/', $story_body, $matches_survey)) {
                    $survey_nid = $matches_survey[1];
                }
                if (strpos($node->body['und'][0]['value'], '[ITG:SURVEY:'.$survey_nid.']')) {
                  $story_body = str_replace('[ITG:SURVEY:'.$survey_nid.']', '', $story_body);
                }
                
                $movie_html = $content['amp_movie_plugin'];
                if (strpos($story_body, '[ITG:TECH-PHOTOS]')) {
                  if (!empty($node->field_story_technology['und'])) {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', $movie_html, $story_body);
                  }
                  else {
                    $story_body = str_replace('[ITG:TECH-PHOTOS]', '', $story_body);
                  }
                }
                // Code for Tech Photo gallery
                if (strpos($story_body, '[ITG:TECH-PHOTO-GALLERY]')) { 
                  if ((!empty($node->field_technology_photogallery['und']))) {
				    if(itg_common_get_node_status($node->field_technology_photogallery['und'][0]['target_id']) == 1){
                      $gallery_node = node_load($node->field_technology_photogallery['und'][0]['target_id']);
                      $tech_gallery_images = $gallery_node->field_gallery_image[LANGUAGE_NONE];
                      $tech_gallery_alias = drupal_get_path_alias('node/' . $gallery_node->nid);
                      $photo_gallery_html = itg_story_photogallery_plugin_data($tech_gallery_images, $tech_gallery_alias, 'amp');
                      $story_body = str_replace('[ITG:TECH-PHOTO-GALLERY]', $photo_gallery_html, $story_body);
					}
					else{
					  $story_body = str_replace('[ITG:TECH-PHOTO-GALLERY]', '', $story_body);
					}
                  }
                  else {
                    $story_body = str_replace('[ITG:TECH-PHOTO-GALLERY]', '', $story_body);
                  }
                }
                // Remove Expert chunk
                if (strpos($story_body, '[ITG:EXPERT-CHUNK]')) {
					$story_body = str_replace('[ITG:EXPERT-CHUNK]', '', $story_body);
				}                
                //code for listicle story
                if (strpos($story_body, '[ITG:LISTICLES]')) {
                  $listicle_output = '';
                  if (!empty($node->field_story_listicle[LANGUAGE_NONE]) && !empty($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
                  if (isset($node->field_story_template_guru[LANGUAGE_NONE][0]['value'])) {
                    $listicle_output.= '<h3 class="listical_title">' . $node->field_story_template_guru[LANGUAGE_NONE][0]['value'] . '</h3>';
                  }
                  $buzz_output.= '';
                  $num = 1;
                  foreach ($node->field_story_listicle['und'] as $buzz_item) {
                    $listicletype = '';
                    $listicle_output.= '<div class="listicle-detail">';
                    $field_collection_id = $buzz_item['value'];
                    $entity = entity_load('field_collection_item', array($field_collection_id));
                    $type = $entity[$field_collection_id]->field_story_listicle_type['und'][0]['value'];
                    $description = $entity[$field_collection_id]->field_story_listicle_description['und'][0]['value'];
                    $li_type = $node->field_story_templates[LANGUAGE_NONE][0]['value'];
                    if ($li_type == 'bullet_points') {
                      $listicle_output.= '<span class="bullet_points"></span>';
                    }
                    else {
                      $listicle_output.= '<span>' . $num . '</span>';
                    }
                    if (isset($type)) {
                      $listicletype = '<span class="listicle-type">' . $type . ': </span>';
                    }
                    $listicle_output.= '<div class="listicle-description">' . $listicletype . $description . '</div>';
                    $listicle_output.= '</div>';
                    $num++;
                  }
                  //print $listicle_output;
                  print $story_body = str_replace('[ITG:LISTICLES]', $listicle_output, $story_body);
                 }
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
                  <?php 
                  $tech_review_chunk = $node->field_story_tech_review_chunk['und'][0]['value'];
                  preg_match_all('/<img.*src=\"(.*)\".*>/isU', $tech_review_chunk, $matches);
                  $i = 0;
                  foreach ($matches[0] as $images) {
                    $src = $matches[1][$i];
                    list($width, $height, $type, $attr) = getimagesize($src);
                    $layout_responsive = ($width > 300) ? 'layout="responsive"' : '';
                    $img = ' <amp-img  src="' . $src . '" alt="" height="' . $height . '" width="' . $width . '" ' . $layout_responsive . '></amp-img>  ';
                    $tech_review_chunk = str_replace($images, $img, $tech_review_chunk);
                    $i++;
                  }
                  print $tech_review_chunk; 
                  ?>
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
                   $output = $content['amp_photo_story_html'];
                   print $output;
                 }
                 ?>
            <!-- for photo story bottom slider, loop has been repeated again -->
            <?php
            if (!empty($node->field_photo_story)) {
              //$html_output = itg_story_photo_story_bottom_html($node->nid);
              $html_output = $content['amp_photo_story_bottom_html'];
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
                /*$buzz_image_src_set = '';
                if(!empty($buzz_imguri)) {
                 $buzz_image_uri = file_create_url($buzz_imguri);
                 $buzz_image_data = getimagesize($buzz_image_uri);
                 $buzz_image_src_set = $buzz_image_uri . ' ' . $buzz_image_data[0] . 'w';
                }*/
            
            $img = '<amp-img height="539" width="770" layout="responsive"  alt="'.$entity[$field_collection_id]->field_buzz_image['und'][0]['alt'].'" title="'.$entity[$field_collection_id]->field_buzz_image['und'][0]['title'].'" src="' . image_style_url("buzz_image", $buzz_imguri) . '"><div fallback>offline</div></amp-img>';
            if (!empty($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'])) {
              $buzz_output.= '<h1><span>' . $buzz . '</span>' . $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</h1>';
              if (!empty($entity[$field_collection_id]->field_buzz_image['und'][0]['fid'])) {
                $buzz_title = preg_replace("/'/", "\\'", $entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']);
                $buzz_title_share = htmlentities($buzz_title, ENT_QUOTES);
                if (function_exists('itg_story_get_image_info')) {
                    $getImageInfo = itg_story_get_image_info($entity[$field_collection_id]->field_buzz_image['und'][0]['fid']);
                }
                $fb_url = 'https://www.facebook.com/sharer/sharer.php?u='.$amp_link.'&title='.$buzz_title_share.'&picture='.$share_image;
                $twitter_url = 'https://twitter.com/intent/tweet?text='.urlencode($entity[$field_collection_id]->field_buzz_headline[LANGUAGE_NONE][0]['value']).'&url='.$short_url.'&via=IndiaToday';
                $google_url = 'https://plus.google.com/share?url='.  urlencode($amp_link);
                $buzz_photo_class = '';
                if(empty($getImageInfo[0]->image_photo_grapher)) {
                  $buzz_photo_class = 'no-caption';
                }
                $buzz_output.= '<div class="buzz-img-wrapper '.$buzz_photo_class.'"><div class="buzz-img"><div class="social-share">
                  <amp-accordion disable-session-states>
                <section>
                  <h2>
                    <span class="show-more"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
                    <span class="show-less"><i class="fa fa-share-alt" aria-hidden="true"></i></span>
                  </h2>
              <ul>
              <li><a href="'.$twitter_url.'" target="_blank" title="share on twitter"><i class="fa fa-twitter-square" aria-hidden="true"></i></a></li>
              <li><a href="'.$fb_url.'" target="_blank" title="share on facebook"><i class="fa fa-facebook-official" aria-hidden="true"></i></a></li>
              <li><a href="'.$google_url.'" target="_blank" title="share on G+"><i class="fa fa-google-plus-square" aria-hidden="true"></i></a></li>
              
              </ul>
              </section>
              </amp-accordion>
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
        <?php if(!empty(variable_get('amp_taboola_ad_script'))) { ?>
          <div class="amp-taboola">
            <?php print variable_get('amp_taboola_ad_script'); ?>
          </div>
        <?php } ?>
        <?php if(!empty(variable_get('amp_story_second_ad'))) { ?>
          <div class="custom-amp-ad ad-btf">
            <?php print variable_get('amp_story_second_ad'); ?> 
          </div>
        <?php } ?>
          <!-- code for related content -->   
          <?php if (!empty($related_content)) { ?>
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
