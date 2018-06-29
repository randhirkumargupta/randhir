<style type="text/css">
.node-type-reporter.section-anchor h1.page__title{display:none;}
</style>
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
<?php
print views_embed_view('video_list_of_category', 'block_2');
?>
  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</article>
