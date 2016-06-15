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
?>
<div class="view-popup">
  <?php if ($title): ?>
    <h1 class="page__title title" id="page-title"><?php print $title; ?></h1>
  <?php endif; ?>
  <?php print $messages; ?>
  <?php print render($page['content']); ?>
</div>