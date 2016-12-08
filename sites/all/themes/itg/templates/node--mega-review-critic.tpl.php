<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
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
                <i>4.3K</i>
                SHARES
            </span> 
            <span>
                <i class="fa fa-facebook" aria-hidden="true"></i>
                <dfn>1522</dfn>
            </span>
            <span>
                <i class="fa fa-twitter" aria-hidden="true"></i>
                <dfn>1522</dfn>
            </span>
            <span>
                <i class="fa fa-google-plus" aria-hidden="true"></i>
                <dfn>1522</dfn>
            </span>
            <span>
                <i class="fa fa-comment" aria-hidden="true"></i>
                <dfn>1522</dfn>
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
            <div class="review-row">
                <dfn class="review-label">Cast :</dfn>
                <span class="review-txt"><?php print render($content['field_mega_review_cast']); ?></span>
            </div>
            <div class="review-row">
                <dfn class="review-label">Director :</dfn>
                <span class="review-txt"><?php print render($content['field_mega_review_director']); ?></span>
            </div>
            <div class="review-row">
                <dfn class="review-label">Plot :</dfn>
                <span class="review-txt"><?php print render($content['field_mega_review_movie_plot']); ?></span>
            </div>
            <?php ?>
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
              <h2><?php print $reviews[$field_collection['value']]->field_buzz_headline['und'][0]['value']; ?></h2>
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
                        'style_name' => 'mrass_video',
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
                  <div class="photo-title"><?php print $video_node->title; ?></div>

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
                        'style_name' => 'mrass_video',
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
                  <div class="photo-title"><?php print $photo_node->title; ?></div>
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
