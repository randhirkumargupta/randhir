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
  </main>
</div>
