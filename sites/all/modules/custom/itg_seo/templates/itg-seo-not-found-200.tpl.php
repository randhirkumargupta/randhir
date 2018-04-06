<?php
/**
 * Template page for not found page
 * 
 * @file: itg-seo-not-found.tpl.php
 */
global $base_url;
?>
<div class="page-error">
  <div class="row">
    <div class="col-md-12">
      <p class="go-back">
          <?php print t('The Content has expired and can no longer be used.'); ?>
      </p>
      <span class="error-or">OR</span>
      <h3><?php print t('Check out Latest Headlines'); ?></h3>
      <ul class="latest-headlines-list">
        <?php
        echo render($data);
        ?>
          
      </ul>
    </div>
  </div>
</div>
