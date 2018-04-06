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
		<div class="col-md-4">&nbsp;</div>
    <div class="col-md-4">
      <p class="go-back">
          <?php print t('The Content has expired.'); ?></br> <?php print t('Open the'); ?> <a href="<?php print url(''); ?>"><?php print t('India Today'); ?></a> <?php print t('homepage for me'); ?>
      </p>
      <span class="error-or">OR</span>
      <h3><?php print t('Check out Latest Headlines'); ?></h3>
      <ul class="latest-headlines-list">
        <?php
        echo render($data);
        ?>
          
      </ul>
    </div>
    <div class="col-md-4">&nbsp;</div>
  </div>
</div>
