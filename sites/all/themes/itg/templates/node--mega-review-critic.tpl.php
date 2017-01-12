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
    //print render($content);    
    ?>
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
                <a title="share on google+" class="def-cur-pointer" onclick="return googleplusbtn('<?php print $actual_link; ?>')"><i class="fa fa-google-plus"></i></a>                
            </span>
            <span>
                <a class="def-cur-pointer" title ="share on facebook" onclick="fbpop('<?php print $actual_link;?>', '<?php print $fb_title; ?>', '<?php print $share_desc; ?>', '<?php print $image;?>', '<?php print $base_url; ?>', '<?php print $node->nid; ?>')"><i class="fa fa-facebook"></i></a>
            </span>
            <span>
                <a class="def-cur-pointer" title="share on twitter" onclick="twitter_popup('<?php print urlencode($node->title);?>', '<?php print urlencode($short_url); ?>')"><i class="fa fa-twitter"></i></a>                
            </span>            
            <span>
                <?php
                if ($config_name == 'vukkul') {
                  ?>
                  <a class= "def-cur-pointer" onclick ="scrollToAnchor('vuukle-emotevuukle_div');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
                <?php } if ($config_name == 'other') { ?> 
                  <a class= "def-cur-pointer" onclick ="scrollToAnchor('other-comment');" title="comment"><i class="fa fa-comment" aria-hidden="true"></i></a>
                <?php } ?>
                
                <!--<dfn>1522</dfn>-->
            </span>
        </div>
    </div>
    <div class="movie-review-wrapper">
        <!--<div class="col-md-7">-->
        <div class="movie-trailer">        
            <?php print render($content['field_mega_review_youtube_url']); ?>
        </div>    
        <!--</div>-->
        <!--<div class="col-md-5">-->
        <div class="movie-review-text">
            <?php $cast_name = render($content['field_mega_review_cast']); ?>
            <?php if (!empty($cast_name)): ?>
            <div class="review-row">
                <dfn class="review-label">Cast :</dfn>
                <span class="review-txt"><?php print $cast_name; ?></span>
            </div>
            <?php endif; ?>
            <?php $director = render($content['field_mega_review_director']); ?>
            <?php if (!empty($director)): ?>
            <div class="review-row">
                <dfn class="review-label">Director :</dfn>
                <span class="review-txt"><?php print $director; ?></span>
            </div>
            <?php endif; ?>
            <?php $plot = render($content['field_mega_review_movie_plot']); ?>
            <?php if (!empty($plot)): ?>
            <div class="review-row">
                <dfn class="review-label">Plot :</dfn>
                <span class="review-txt"><?php print $plot; ?></span>
            </div>
            <?php endif; ?>
            <div class="movie-reviewer our-review"></div>
            <div class="movie-reviewer movie-reviewer-other"></div>
        </div>
        <!--</div>-->
       
    </div>
     <div class="bottom-movie-desc"><?php print $bottom_desc; ?></div>
    <div class="other-reviews">
        <!-- Print reviews -->
        <?php $average_ratings = 0; ?>
        <?php $num_of_ratings = 0; ?>
        <?php $external_review = $internal_review = FALSE; ?>
        <?php foreach ($node->field_mega_review_review['und'] as $field_collection): ?>   
          <div class="other-reviews-row">
              <?php $reviews = entity_load('field_collection_item', array($field_collection['value'])) ?>     
              <!-- Review Headline -->
              <?php if ($reviews[$field_collection['value']]->field_story_review_type['und'][0]['value'] == 'external'): ?>
                <?php print '<h2>' . t('Other Reviewers') . '</h2>'; ?>
              <?php endif; ?>
              
              <h2><?php print l($reviews[$field_collection['value']]->field_buzz_headline['und'][0]['value'], $reviews[$field_collection['value']]->field_mega_review_url_link['und'][0]['value']); ?></h2>
              <div class="other-reviews-posted-on">
                  <!-- Byline reporter -->
                  <!-- Get Multiple reviewers name -->
                  <?php $reviewers = array(); ?>                  
                  <?php foreach ($reviews[$field_collection['value']]->field_story_reporter['und'] as $reviewer_name): ?>                  
                    <?php $reviewers[] = $reviewer_name['entity']->title ?>
                  <?php endforeach; ?>
                  <!-- Print External review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type['und'][0]['value'] == 'external' && !$external_review): ?>
                    <div id="external-review" style="display:none;">
                        <p><?php print $reviews[$field_collection['value']]->field_story_reporter['und'][0]['entity']->title; ?></p>                      
                        <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating['und'][0]['value'] * 20; ?>%"></span>
                    </div>                  
                    <?php $external_review == TRUE; ?>
                  <?php endif; ?>

                  <!-- Print internal review. -->
                  <?php if ($reviews[$field_collection['value']]->field_story_review_type['und'][0]['value'] == 'internal' && !$internal_review): ?>
                    <div id="internal-review" style="display:none;">
                        <p><?php print implode(', ', $reviewers); ?></p>
                        <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating['und'][0]['value'] * 20; ?>%"></span>
                    </div>                  
                    <?php $internal_review == TRUE; ?>
                  <?php endif; ?>

                  <span class="other-reviews-by"><?php print t('By') . ' ' . implode(', ', $reviewers); ?></span>
                  <!-- Created date -->
                  <span class="other-reviews-date"><?php print format_date($node->created, 'custom', 'F d, Y'); ?></span>
                  <!-- Ratings -->    
                  <?php $average_ratings += $reviews[$field_collection['value']]->field_story_rating['und'][0]['value']; ?>
                  <?php ++$num_of_ratings; ?>
                  <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating['und'][0]['value'] * 20; ?>%"></span>
              </div>
              <?php $full_desc = $reviews[$field_collection['value']]->field_mega_review_description['und'][0]['value'] ?>
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
        <?php endforeach; ?>  
        <?php $average_rating = (float) $average_ratings / $num_of_ratings ?>  
        <?php $average_rating = round($average_rating, 1); ?>
        <?php $average_rating = itg_common_round_rating($average_rating); ?>
        <div id="average-ratings" style="display:none;"><?php print $average_rating * 20; ?>%</div> 
    </div>
    <div class="photos-videos-wrapper">
        <!-- Print video -->
        <?php $asso_photo_gallery = $asso_vid_id = 0; ?>        
        <?php $asso_photo_gallery = $node->field_associate_photo_gallery['und'][0]['target_id'];
        ; ?>
        <?php $asso_vid_id = $node->field_story_associate_video['und'][0]['target_id']; ?>
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
                      $large_image = theme(
                          'image_style', array(
                        'style_name' => empty($asso_vid_class) ? 'mrass_video' : 'anchors_landing',
                        'path' => $video_node->field_story_extra_large_image['und'][0]['uri'],
                          )
                      );
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
            <?php $asso_photo_gallery = $node->field_associate_photo_gallery['und'][0]['target_id'];
            ; ?>
<?php if ($asso_photo_gallery): ?>
              <div class="movie-photos <?php print $ass_photo_class; ?>">
                  <div class="movie-data">
                      <h3><span>PHOTOS</span></h3>
                      <?php
                      $photo_node = node_load($asso_photo_gallery);
                      $small_image = theme(
                          'image_style', array(
                          'style_name' => empty($ass_photo_class) ? 'mrass_video' : 'anchors_landing',
                        'path' => $photo_node->field_story_extra_large_image['und'][0]['uri'],
                          )
                      );
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
    <div class="vukkul-comment">
        <div id="vuukle-emote"></div>
        <div id="vuukle_div"></div>

        <?php
        if (function_exists('vukkul_view')) {
          vukkul_view();
        }
        ?>

    </div>

<?php print render($content['links']); ?>    
<?php print render($content['comments']); ?>  
</article>
