<?php

/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */

/**
 * Rename "Add Term" to "Add Category"
 * Remove primary local task link (Edit and manage fields links from right top side)
 */
global $base_url, $user;
?>

<div id="page">
  <div style="width:800px;"></div>
  <main id="main">
    <section id="content" class="container" role="main">
      <?php print render($page['highlighted']); ?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print render($page['form_tab']); ?>
      <?php print $messages; ?>
      <?php print render($tabs); ?>
      <?php print render($page['help']); ?>
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </section>

    

    <?php
      // Render the sidebars to see if there's anything in them.
      $sidebar_first  = render($page['sidebar_first']);
      $sidebar_second = render($page['sidebar_second']);
    ?>

    <?php if ($sidebar_first || $sidebar_second): ?>
      <aside class="sidebars">
        <?php print $sidebar_first; ?>
        <?php print $sidebar_second; ?>
      </aside>
    <?php endif; ?>

  </main>

  <?php print render($page['footer']); ?>

</div>

<?php print render($page['bottom']); ?>
