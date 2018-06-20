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
  ?>
  <?php
  if(!empty($solr_story_data)):?>
    <ul class="author-story-wrapper">
      <?php foreach($solr_story_data as $key => $value): ?>
        <li class="col-md-3 <?php print $value->bundle .'-'.$value->entity_id; ?>">
          <div class="tile">
            <figure>
              <a href="/<?php print $value->path_alias; ?>"><img src="<?php print $value->sm_field_custom_story_small_large_url[0]; ?>" alt="<?php print $value->label; ?>" title="<?php print $value->label; ?>" width="170" height="96"></a>
            </figure>
            <span class="posted-on"><?php print date('D, d M, Y', strtotime($value->ds_created)); ?></span>
            <p title="<?php print $value->label; ?>">
              <a href="/<?php print $value->path_alias; ?>"><?php print $value->label; ?></a>
            </p>
          </div>
        </li>
      <?php endforeach; ?>
    </ul>
  <?php endif; ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
<div class="wrapper-tabola">
<?php
if (function_exists('taboola_view')) {
    taboola_view();
  }
?>
</div>
