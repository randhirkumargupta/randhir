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
  <div class="rating-and-social-wrapper">
    <div class="movie-rating" data-star-value="60%"></div>
    <div class="social-info">
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
        <!-- Large Image -->
        <?php
        $large_image = theme(
          'image_style', 
          array(
            'style_name' => 'cart_172x240',
            'path' => $node->field_story_extra_large_image['und'][0]['uri'],
          )
        );
        print $large_image;
        ?>
      </div>
    <!--</div>-->
    <!--<div class="col-md-5">-->
      <div class="movie-review-text">
        <div class="review-row">
          <dfn class="review-label">Cast :</dfn>
          <span class="review-txt">Deepika Padukone, Ranbir Kapoor</span>
        </div>
        <div class="review-row">
          <dfn class="review-label">Director :</dfn>
          <span class="review-txt">Imtiaz</span>
        </div>
        <div class="review-row">
          <dfn class="review-label">Plot :</dfn>
          <span class="review-txt">Ved and Tara are on a holiday in Corsica. And what happens in Corsica, stays in Corsica. </span>
        </div>
        <div class="movie-reviewer">
          <h3>OUR REVIEWERS</h3>
          <p>Ananya Bhattacharya, ITGD</p>
          <div class="movie-reviewer-rating">
            
          </div>
        </div>
        <div class="movie-reviewer movie-reviewer-other">
          <h3>OTHER REVIEWERS</h3>
          <p>Ananya Bhattacharya, ITGD</p>
          <div class="movie-reviewer-rating">
            
          </div>
        </div>
      </div>
    <!--</div>-->
  </div>
  <div class="other-reviews">
  <!-- Print reviews -->
  <?php foreach ($node->field_mega_review_review['und'] as $field_collection): ?>   
  <div class="other-reviews-row">
    <?php $reviews = entity_load('field_collection_item', array($field_collection['value'])) ?>     
    <!-- Review Headline -->
    <h2><?php print $reviews[$field_collection['value']]->field_buzz_headline['und'][0]['value']; ?></h2>
    <div class="other-reviews-posted-on">
    <!-- Byline reporter -->
    
    <span class="other-reviews-by"><?php print t('By') . ' ' . $reviews[$field_collection['value']]->field_story_reporter['und'][0]['entity']->title; ?></span>
    <!-- Created date -->
    <span class="other-reviews-date"><?php print format_date($node->created, 'custom', 'F d, Y'); ?></span>
    <!-- Ratings -->
    <span class="other-reviews-rating" data-star-value="<?php print $reviews[$field_collection['value']]->field_story_rating['und'][0]['value'] * 20; ?>%"></span>
    </div>
    <!-- Review description -->
    <div class="other-reviews-desc"><?php print $reviews[$field_collection['value']]->field_mega_review_description['und'][0]['value']; ?></div>
  </div>
  <?php endforeach; ?>
    </div>
  <div class="photos-videos-wrapper">
    <!-- Print video -->
    <div class="movie-videos">
      <h3><span>MOVIE VIDEOS</span></h3>
      <?php print render($content['field_mega_review_youtube_url']); ?>
    </div>

    <!-- Photos -->
    <div class="movie-photos">
      <h3><span>MOVIE PHOTOS</span></h3>
      <?php
      $small_image = theme(
        'image_style', array(
        'style_name' => 'cart_172x240',
        'path' => $node->field_story_small_image['und'][0]['uri'],
        )
      );

      print $small_image;
      ?>
    </div>
  </div>
  <div class="career-graph">
    <?php
    $block = module_invoke('itg_reports', 'block_view', 'itg_report_career_graph');
    print render($block['content']);
    ?>
  </div>
  <?php print render($content['links']); ?>    
  <?php print render($content['comments']); ?>  
</article>
