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
          <a href="<?php print url(''); ?>"><img src="<?php echo $base_url . '/sites/all/themes/itg/images/error_403.png';?>" alt=""/></a>
        <p>You are not authorized to access this page.</p>
      </div>
    </div>
    <div class="col-md-6">
      <p class="go-back">
          I want to go <a href="javascript:history.back()">BACK</a> from where I came </br> Open the <a href="<?php print url(''); ?>">India Today</a> homepage for me
      </p>
      <span class="error-or">OR</span>
      <h3>Check out Latest Headlines</h3>
      <ul class="latest-headlines-list">
          <?php 
          $query = db_select('node', 'n')
                  ->fields('n', array('title', 'nid'))
                  ->condition('n.status', 'published')
                  ->range(0,4)
                  ->orderBy('n.created', 'DESC');
          $result = $query->execute()->fetchAll();
          foreach ($result as $key => $val) {
          ?>
          <a href="<?php print url('node/'. $val->nid); ?>" target="_blank"><li><?php print_r($val->title); ?></li></a>
          <?php } ?>
      </ul>
    </div>
  </div>
</div>