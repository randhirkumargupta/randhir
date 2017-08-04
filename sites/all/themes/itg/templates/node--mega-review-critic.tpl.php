<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

?>
<?php
  // config for sharing
  global $base_url; 
  $nid = check_plain(arg(1));   
  $actual_link = 'http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI'];
  $short_url = shorten_url($actual_link, 'goo.gl');
  $fb_title = addslashes($node->title);
  $share_desc = '';
  $image = file_create_url($node->field_story_extra_large_image[LANGUAGE_NONE][0]['uri']);
  
  // get global comment config
  if (function_exists('global_comment_last_record')) {      
    $last_record = $global_comment_last_record;
    $config_name = trim($last_record[0]->config_name);
  }
    
  // get facebook share count 
  if (function_exists('itg_total_share_count')) {
    $tot_count = itg_total_share_count($actual_link);
  }
  if(function_exists('itg_report_get_node_share')) {
      $tot_count = itg_report_get_node_share($nid, $tot_count);
  }

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || !$page && $title): ?>
      <header>
          <?php print render($title_prefix); ?>
          <?php if (!$page && $title): ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
          <?php endif; ?>
          <?php print render($title_suffix); ?>

          <?php if ($display_submitted): ?>
            <p class="submitted">
                <?php print $user_picture; ?>
                <?php print $submitted; ?>
            </p>
          <?php endif; ?>

          <?php if ($unpublished): ?>
            <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
          <?php endif; ?>
      </header>
    <?php endif; ?>

    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);  
    ?>
<!--    mobile social share-->
<div class="comment-mobile desktop-hide">
    <ul>
        <li class="mail-to-author"><a title ="Mail to author" href="mailto:support@indiatoday.in"><i class="fa fa-envelope"></i> <?php print t('Mail to author'); ?></a></li>
        <li><a href="#" title = "whatsapp"><i class="fa fa-whatsapp"></i></a></li>
        <?php
        if ($config_name == 'vukkul') {
            ?>
            <li><a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment"></i></a></li>
        <?php } if ($config_name == 'other') { ?> 
            <li><a class="def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment"></i></a></li>
        <?php } ?>
        <li><a href="#" title ="share" class="share-icon"><i class="fa fa-share-alt"></i></a>
    </ul>
    <ul class="social-share">
        <li><a title = "share on facebook" class="def-cur-pointer" onclick="fbpop('<?php print $actual_link; ?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image; ?>', '<?php print $base_url; ?>', '<?php print $nid; ?>')"><i class="fa fa-facebook"></i></a></li>
        <li><a title = "share on twitter" class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" href="javascript:" onclick="twitter_popup('<?php print urlencode($node->title); ?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a></li>
        <li><a title="share on google+" class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" href="#" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a></li>

    </ul> 
</div>
    
    <!-- Title -->
    <h1><?php print $node->title; ?></h1>
    <div class="movie-description">        
        <?php $movie_desc = render($content['field_story_movie_description']); ?>
        <?php $top_desc = explode('|', $movie_desc) ?>
        <?php $bottom_desc = count($top_desc) == 2 ? $top_desc[1] : ''; ?>    
        <?php print $top_desc[0]; ?>  
    </div>
    <div class="rating-and-social-wrapper">
        <div class="movie-rating">                      
        </div>
        <div class="social-info">     
            <span class="share-count">
                <i><?php if(!empty($tot_count)) { print $tot_count;} else { print 0; } ?></i>
                SHARES
            </span> 
            <span>
                <a title="share on google+" class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="google_share" data-status="1" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>                
            </span>
            <span>
                <a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link;?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>', '<?php print $base_url; ?>', '<?php print $node->nid; ?>')"><i class="fa fa-facebook"></i></a>
            </span>
            <span>
                <a class="user-activity def-cur-pointer" rel="<?php print $node->nid; ?>" data-tag="<?php print $node->type; ?>" data-activity="twitter_share" data-status="1" title="share on twitter" onclick="twitter_popup('<?php print urlencode($node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>                
            </span>            
            <span>
                <?php
                if ($config_name == 'vukkul') {
                  ?>
                  <a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
                <?php } if ($config_name == 'other') { ?> 
                  <a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
                <?php } ?>
              
            </span>
        </div>
    </div>
    <div class="movie-review-wrapper">
        
        <div class="movie-trailer">        
            <?php print render($content['field_mega_review_youtube_url']); ?>
        </div>    
        
        <div class="movie-review-text">
            <?php $cast_name = $node->field_mega_review_cast['und'][0]['entity']->title; ?>
            <?php if (!empty($cast_name)): ?>
            <div class="review-row">
                <dfn class="review-label"><?php print t('Cast :'); ?></dfn>
                <span class="review-txt"><?php print $cast_name; ?></span>
            </div>
            <?php endif; ?>
            <?php $director = $node->field_mega_review_director['und'][0]['value']; ?>
            <?php if (!empty($director)): ?>
            <div class="review-row">
                <dfn class="review-label"><?php print t('Director :'); ?></dfn>
                <span class="review-txt"><?php print $director; ?></span>
            </div>
            <?php endif; ?>
            <?php $plot = $node->field_mega_review_movie_plot['und'][0]['value']; ?>
            <?php if (!empty($plot)): ?>
            <div class="review-row">
                <dfn class="review-label"><?php print t('Plot :'); ?></dfn>
                <span class="review-txt"><?php print $plot; ?></span>
            </div>
            <?php endif; ?>
            <div class="movie-reviewer our-review"></div>
            <div class="movie-reviewer movie-reviewer-other"></div>
        </div>
       
    </div>
     <div class="bottom-movie-desc"><?php print $bottom_desc; ?></div>
    <div class="other-reviews">
        <!-- Print reviews -->
        <?php $average_ratings = 0; ?>
        <?php $num_of_ratings = 0; ?>
      <!------------------------------------------------------------------------------------------------------->
        <?php $external_review = $internal_review = FALSE; ?>
        <?php foreach ($node->field_mega_review_review[LANGUAGE_NONE] as $field_collection):$reviews = entity_load('field_collection_item', array($field_collection['value']));    

         if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] != 'external') { ?>
          <div class="other-reviews-row">
              <!-- Review Headline -->
              
              
              <h2><?php print l($reviews[$field_collection['value']]->field_buzz_headline[LANGUAGE_NONE][0]['value'], $reviews[$field_collection['value']]->field_mega_review_url_link[LANGUAGE_NONE][0]['value']); ?></h2>
              <div class="other-reviews-posted-on">
                  <!-- Byline reporter -->
                  <!-- Get Multiple reviewers name -->
                  <?php $reviewers = array(); ?>                  
                  <?php foreach ($reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE] as $reviewer_name): ?>                  
                    <?php $reviewers[] = $reviewer_name['entity']->title ?>
                  <?php endforeach; ?>
                  
                  <!-- Print External review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'external'): ?>
                    <!--<div id="external-review" style="display:none;">-->
                    <?php
                      $external = $reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE][0]['entity']->title;
                      $external_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
                      $external_review .='<p>'.$external.'</p>                      
                      <span class="other-reviews-rating" data-star-value="'.$external_rating.'%"></span>';                        
                    ?>

                    <?php endif; ?>

                  <!-- Print internal review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'internal'): ?>
                    
                    <?php
                      $internal = $reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE][0]['entity']->title;
                      $internal_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
                      $internal_review .='<p>'.$internal.'</p>                      
                      <span class="other-reviews-rating" data-star-value="'.$internal_rating.'%"></span>';                        
                    ?>                      
                   
                  <?php endif; ?>

                  <span class="other-reviews-by"><?php print t('By') . ' ' . implode(', ', $reviewers); ?></span>
                  <!-- Created date -->
                  <span class="other-reviews-date"><?php print format_date($node->created, 'custom', 'F d, Y'); ?></span>
                  <!-- Ratings -->    
                  <?php $average_ratings += $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value']; ?>
                  <?php ++$num_of_ratings; ?>
                  <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20; ?>%"></span>
              </div>
              <?php $full_desc = $reviews[$field_collection['value']]->field_mega_review_description[LANGUAGE_NONE][0]['value'] ?>
              <!-- Review description -->
              <div class="other-reviews-desc">
                  <div class="less-content">
                      <?php
                      echo mb_strimwidth(strip_tags($full_desc), 0, 245, "..");
                      ?>
                      <?php if (strlen($full_desc) > 245) { ?>
                        <a href="javascript:void(0)" class="anchor-action read-more"> More[+]</a>
                    </div>

                    <div class="full-content" style="display: none">
                        <?php echo $full_desc; ?>
                        <a href="javascript:void(0)" class="anchor-action read-less"> Less[-]</a>
                      <?php } ?>
                  </div>
              </div>
          </div>
         <?php  } endforeach; ?> 
      
      
       <?php foreach ($node->field_mega_review_review[LANGUAGE_NONE] as $field_collection): 
                    $reviews = entity_load('field_collection_item', array($field_collection['value']));    

         if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'external') { ?>
         
         <div class="other-reviews-row">
              <!-- Review Headline -->
            
                <?php print '<h2>' . t('Other Reviewers') . '</h2>'; ?>
             
              
              <h2><?php print l($reviews[$field_collection['value']]->field_buzz_headline[LANGUAGE_NONE][0]['value'], $reviews[$field_collection['value']]->field_mega_review_url_link[LANGUAGE_NONE][0]['value']); ?></h2>
              <div class="other-reviews-posted-on">
                  <!-- Byline reporter -->
                  <!-- Get Multiple reviewers name -->
                  <?php $reviewers = array(); ?>                  
                  <?php foreach ($reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE] as $reviewer_name): ?>                  
                    <?php $reviewers[] = $reviewer_name['entity']->title ?>
                  <?php endforeach; ?>
                  
                  <!-- Print External review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'external'): ?>
                    <!--<div id="external-review" style="display:none;">-->
                    <?php
                      $external = $reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE][0]['entity']->title;
                      $external_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
                      $external_review .='<p>'.$external.'</p>                      
                      <span class="other-reviews-rating" data-star-value="'.$external_rating.'%"></span>';                        
                    ?>

                   
                  <?php endif; ?>

                  <!-- Print internal review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] == 'internal'): ?>
                    <!--<div id="internal-review" style="display:none;">-->
                    <?php
                      $internal = $reviews[$field_collection['value']]->field_story_reporter[LANGUAGE_NONE][0]['entity']->title;
                      $internal_rating = $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20;
                      $internal_review .='<p>'.$internal.'</p>                      
                      <span class="other-reviews-rating" data-star-value="'.$internal_rating.'%"></span>';                        
                    ?>                      
                   
                  <?php endif; ?>

                  <span class="other-reviews-by"><?php print t('By') . ' ' . implode(', ', $reviewers); ?></span>
                  <!-- Created date -->
                  <span class="other-reviews-date"><?php print format_date($node->created, 'custom', 'F d, Y'); ?></span>
                  <!-- Ratings -->    
                  <?php $average_ratings += $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value']; ?>
                  <?php ++$num_of_ratings; ?>
                  <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] * 20; ?>%"></span>
              </div>
              <?php $full_desc = $reviews[$field_collection['value']]->field_mega_review_description[LANGUAGE_NONE][0]['value'] ?>
              <!-- Review description -->
              <div class="other-reviews-desc">
                  <div class="less-content">
                      <?php
                      echo mb_strimwidth(strip_tags($full_desc), 0, 245, "..");
                      ?>
                      <?php if (strlen($full_desc) > 245) { ?>
                        <a href="javascript:void(0)" class="anchor-action read-more"> More[+]</a>
                    </div>

                    <div class="full-content" style="display: none">
                        <?php echo $full_desc; ?>
                        <a href="javascript:void(0)" class="anchor-action read-less"> Less[-]</a>
                      <?php } ?>
                  </div>
              </div>
          </div>
         <?php } endforeach; ?> 
      <!------------------------------------------------------------------------------------------------------->
      <div id="internal-review" style="display:none;"><?php echo $internal_review; ?></div>
      <div id="external-review" style="display:none;"><?php echo $external_review; ?></div>
        <?php $average_rating = (float) $average_ratings / $num_of_ratings ?>  
        <?php $average_rating = round($average_rating, 1); ?>
        <?php $average_rating = itg_common_round_rating($average_rating); ?>
        <div id="average-ratings" style="display:none;"><?php print $average_rating * 20; ?>%</div> 
    </div>
    <div class="photos-videos-wrapper">
        <!-- Print video -->
        <?php $asso_photo_gallery = $asso_vid_id = 0; ?>        
        <?php $asso_photo_gallery = $node->field_associate_photo_gallery[LANGUAGE_NONE][0]['target_id']; ?>
        <?php $asso_vid_id = $node->field_story_associate_video[LANGUAGE_NONE][0]['target_id']; ?>
        <!-- Video or photo thumbnail full page logic. -->
        <?php
        if ($asso_photo_gallery > 1 && $asso_vid_id > 1) {
          $asso_vid_class = '';
          $ass_photo_class = '';
        }
        elseif ($asso_photo_gallery > 1) {
          $ass_photo_class = 'full-width';
        }
        elseif ($asso_vid_id > 1) {
          $asso_vid_class = 'full-width';
        }
        ?>

        <div class="row">

        <?php if ($asso_vid_id): ?>
              <div class="movie-videos <?php print $asso_vid_class; ?>">
                  <div class="movie-data">
                      <h3><span>MOVIE VIDEOS</span></h3>
                      <?php
                      $video_node = node_load($asso_vid_id);
                      if(!empty($video_node->field_story_medium_image[LANGUAGE_NONE][0]['uri'])) {
                      $final_image = image_style_url("anchors_landing",$video_node->field_story_medium_image[LANGUAGE_NONE][0]['uri']);
                      } else {
                      $final_image = $base_url.'/sites/all/themes/itg/images/itg_image370x208.jpg';
                      }
                      $large_image = '<img src="' . $final_image . '" alt="image">';
                      print l($large_image, 'node/' . $video_node->nid, array('html' => TRUE, 'attributes' => array('target' => '_blank')));
                      ?>
              <?php $video_date = format_date($video_node->created, 'custom', 'D, d M, Y'); ?>

                      <div class="img-count">
                          <i class="fa fa-play-circle"></i> <?php print $video_node->field_video_duration['und'][0]['value']; ?>
                      </div>
                  </div>

                  <div class="photo-date"><?php print $video_date ?></div>
                  <div class="photo-title"><?php print l($video_node->title, 'node/' . $video_node->nid, array('html' => TRUE, 'attributes' => array('target' => '_blank'))); ?></div>

              </div>

        <?php endif; ?>
        <!-- Photos -->
        <?php $asso_photo_gallery = $node->field_associate_photo_gallery['und'][0]['target_id'];?>
        <?php if ($asso_photo_gallery): ?>
              <div class="movie-photos <?php print $ass_photo_class; ?>">
                  <div class="movie-data">
                      <h3><span><?php print t('PHOTOS'); ?></span></h3>
                      <?php
                      $photo_node = node_load($asso_photo_gallery);
                      if(!empty($photo_node->field_story_medium_image[LANGUAGE_NONE][0]['uri'])) {
                      $final_image = image_style_url("anchors_landing",$photo_node->field_story_medium_image[LANGUAGE_NONE][0]['uri']);
                      } else {
                       $final_image = $base_url.'/sites/all/themes/itg/images/itg_image370x208.jpg'; 
                      }
                      $small_image = '<img src="' . $final_image . '" alt="image">';
                      $image_count = count($photo_node->field_gallery_image['und']);
                      print l($small_image, 'node/' . $photo_node->nid, array('html' => TRUE, 'attributes' => array('target' => '_blank')));
                      ?>
                      <div class="img-count">
                          <i class="fa fa-camera"></i> <?php print $image_count . t(' Images'); ?>
                      </div>
                 </div>
                 <?php $photo_date = format_date($photo_node->created, 'custom', 'D, d M, Y'); ?>
                  <div class="photo-date"><?php print $photo_date ?></div>
                  <div class="photo-title"><?php print l($photo_node->title, 'node/' . $photo_node->nid, array('html' => TRUE, 'attributes' => array('target' => '_blank'))); ?></div>
              </div>
        <?php endif; ?>
        </div>
    </div>
    <div class="career-graph">
        <?php
        $block = module_invoke('itg_reports', 'block_view', 'itg_report_career_graph');
        print render($block['content']);
        ?>
    </div>
     <?php if ($config_name == 'vukkul') { ?>
       <div class="vukkul-comment">
           <div id="vuukle-emote"></div>
           <div id="vuukle_div"></div>
           <?php if (function_exists('vukkul_view')) {
                   vukkul_view();
                 }
           ?>
       </div>
    <?php
     }
     if ($config_name == 'other') {
    ?>
    <div id="other-comment">
      <?php
        $block = module_invoke('itg_ugc_comment', 'block_view', 'ugc_form_comment_block');
        print render($block['content']);
      ?>
    </div>
<?php } ?>

<?php print render($content['links']); ?>
</article>
