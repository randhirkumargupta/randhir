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
  <?php print $node->title; ?>
  
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
  <!-- Print reviews -->
  <?php foreach ($node->field_mega_review_review['und'] as $field_collection): ?>    
    <?php $reviews = entity_load('field_collection_item', array($field_collection['value'])) ?>    
    <!-- Review Headline -->
    <?php print $reviews[$field_collection['value']]->field_buzz_headline['und'][0]['value']; ?>
    <!-- Byline reporter -->
    <?php print t('By') . $reviews[$field_collection['value']]->field_story_reporter['und'][0]['value']; ?>
    <!-- Created date -->
    <?php print format_date($node->created, 'custom', 'F d, Y'); ?>
    <!-- Ratings -->
    <?php print $reviews[$field_collection['value']]->field_story_rating['und'][0]['value']; ?>
    <!-- Review description -->
    <?php print $reviews[$field_collection['value']]->field_mega_review_description['und'][0]['value']; ?>
  <?php endforeach; ?>
  <!-- Print video -->
  <?php print render($content['field_mega_review_youtube_url']); ?>
  <!-- Photos -->
  <?php
    $small_image = theme(
      'image_style',
      array(
        'style_name' => 'cart_172x240',
        'path' => $node->field_story_small_image['und'][0]['uri'],
      )  
    );
    
    print $small_image;
  ?>
  <?php print render($content['links']); ?>    
  <?php print render($content['comments']); ?>  
</article>
