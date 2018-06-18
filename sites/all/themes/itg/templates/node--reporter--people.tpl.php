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
    <h3<?php print $title_attributes; ?>>Latest News About <?php print $title; ?></h3>
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
  <?php endif; ?>
  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
