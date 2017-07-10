<?php
global $base_url;
?>

<footer id="footer">
  <div class="footer-top-link">
    <?php print drupal_render($data['footer-top-menu']); ?>
  </div>
  <amp-accordion disable-session-states>
    <section>
      <h2>
        <span class="show-more"><i class="fa fa-chevron-up"></i></span>
        <span class="show-less"><i class="fa fa-chevron-down"></i></span>
      </h2>
      <div class="footer-bottom-menu">
        <div class="menu-col">
          <h4><?php print t('Publications:'); ?></h4>
          <?php print drupal_render($data['publications_footer']); ?>
        </div>
        <div class="menu-col">
          <h4><?php print t('Television:'); ?></h4>
          <?php print drupal_render($data['television_footer']); ?>
          <h4><?php print t('Radio:'); ?></h4>
          <?php print drupal_render($data['radio_footer']); ?>
        </div>
        <div class="menu-col">
          <h4><?php print t('Education:'); ?></h4>
          <?php print drupal_render($data['education_footer']); ?>
          <h4>Online Shopping:</h4>
          <?php print drupal_render($data['shopping_footer']); ?>
        </div>
        <div class="menu-col">
          <h4><?php print t('Events:'); ?></h4>
          <?php print drupal_render($data['events_footer']); ?>
        </div>
        <div class="menu-col">
          <h4><?php print t('Printing:'); ?></h4>
          <?php print drupal_render($data['printing_footer']); ?>
          <h4><?php print t('Welfare'); ?></h4>
          <?php print drupal_render($data['welfare_footer']); ?>
          <h4><?php print t('Music:'); ?></h4>
          <?php print drupal_render($data['music_footer']); ?>
        </div>              
        <div class="menu-col">
          <h4><?php print t('Syndications:'); ?></h4>
          <?php print drupal_render($data['syndication_footer']); ?>
          <h4><?php print t('Distribution:'); ?></h4>
          <?php print drupal_render($data['distribution_footer']); ?>
          <h4><?php print t('Useful Links :'); ?></h4>
          <?php print drupal_render($data['useful_footer']); ?>
        </div>
          <div class="copyright"><?php print t('Copyright &copy;'); ?> <?php echo date("Y") ?> <?php print t('Living Media India Limited. For reprint rights: Syndications Today'); ?></div>
      </div>
    </section>
  </amp-accordion>
  
</footer>