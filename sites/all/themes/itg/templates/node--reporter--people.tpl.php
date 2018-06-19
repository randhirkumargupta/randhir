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
    </header>
  <?php endif; ?>

  <?php
  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  unset($content);
  $block = module_invoke('itg_widget', 'block_view', 'anchor_langing_page_menu');
  print $block['content'];
  ?>
  <?php if(!empty($solr_story_data)):?>
  <div class="main-story-wrapper">
    <h3>Latest News About <?php print $title; ?></h3>
    <ul class="people-story-wrapper">
      <?php foreach($solr_story_data as $key => $value): ?>
        <li class="col-md-3 people-li <?php print $value->bundle .'-'.$value->entity_id; ?>">
          <div class="tile">
            <figure>
              <a href="/<?php print $value->path_alias; ?>"><img src="<?php print $value->sm_field_custom_story_extra_small_url[0]; ?>" alt="<?php print $value->label; ?>" title="<?php print $value->label; ?>" width="88" height="50"></a>
            </figure>
            <p title="<?php print $value->label; ?>">
              <a href="/<?php print $value->path_alias; ?>"><?php print $value->label; ?></a>
            </p>
          </div>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
  <?php endif; ?>
  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>


<?php if(!empty($solr_video_data)):?>
<div class="main-video-wrapper">
  <h3>VIDEOS</h3>
  <ul class="people-video-list">
    <?php foreach($solr_video_data as $key => $value): ?>
      <li class="col-md-3 people-li <?php print $value->bundle .'-'.$value->entity_id; ?>">
        <div class="title">
          <figure>
            <a href="/<?php print $value->path_alias; ?>"><img src="<?php print $value->sm_field_custom_story_small_large_url[0]; ?>" alt="<?php print $value->label; ?>" title="<?php print $value->label; ?>" width="170" height="96"></a>
              <figcaption><i class="fa fa-play-circle"></i><?php print $value->sm_field_video_duration[0]; ?></figcaption>
          </figure>
          <span class="posted-on"><?php print date('D, d M, Y', strtotime($value->ds_created)); ?></span>
          <p title="<?php print $value->label; ?>">
            <a href="/<?php print $value->path_alias; ?>"><?php print $value->label; ?></a>
          </p>
          </div>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
<?php endif; ?>

<?php print_r($solr_photo_data)); die(123);if(!empty($solr_photo_data)):?>
<div class="main-photo-wrapper">
  <h3>PHOTO</h3>
  <ul class="people-photo-list">
    <?php foreach($solr_photo_data as $key => $value): ?>
      <?php
        $count_image_text = '';
        if(isset($value->im_field_photo_enable[0]) && !empty($value->im_field_photo_enable[0])){
          $count_image = count(explode(',', $value->im_field_photo_enable[0]));
          $count_image_text = ($count_image > 1)?"$count images": "$count image";
        }
      ?>
      <li class="col-md-3 people-li <?php print $value->bundle .'-'.$value->entity_id; ?>">
        <div class="title">
          <figure>
            <a href="/<?php print $value->path_alias; ?>"><img src="<?php print $value->sm_field_custom_story_small_large_url[0]; ?>" alt="<?php print $value->label; ?>" title="<?php print $value->label; ?>" width="170" height="96"></a>
              <figcaption><i class="fa fa-camera"></i><?php print $count_image_text; ?></figcaption>
          </figure>
          <span class="posted-on"><?php print date('D, d M, Y', strtotime($value->ds_created)); ?></span>
          <p title="<?php print $value->label; ?>">
            <a href="/<?php print $value->path_alias; ?>"><?php print $value->label; ?></a>
          </p>
          </div>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
<?php endif; ?>
</article>
