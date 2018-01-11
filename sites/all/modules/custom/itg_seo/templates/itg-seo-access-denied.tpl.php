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
    <div class="col-md-6">
      <div class="page-error-pic">
        <a href="<?php print url(''); ?>"><img src="<?php echo $base_url . '/sites/all/themes/itg/images/error_403.png';?>" alt="" title=""/></a>
        <p><?php print t('You are not authorized to access this page.'); ?></p>
      </div>
    </div>
    <div class="col-md-6">
      <p class="go-back">
          <?php print t('I want to go'); ?> <a href="javascript:history.back()"><?php print t('BACK'); ?></a> <?php print t('from where I came'); ?> </br> <?php print t('Open the');?> <a href="<?php print url(''); ?>"><?php print t('India Today'); ?></a> <?php print t('homepage for me'); ?>
      </p>
      <span class="error-or"><?php print t('OR'); ?></span>
      <h3><?php print t('Check out Latest Headlines'); ?></h3>
      <ul class="latest-headlines-list">
        <?php
        echo render($data);
        ?>
          
      </ul>
    </div>
  </div>
</div>