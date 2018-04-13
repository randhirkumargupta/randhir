<?php
global $base_url;
?>
<footer id="footer">
  <div class="footer-latest">
  <figcaption on="tap:AMP.setState({expanded1: !expanded1})"
      tabindex="0"
      role="button"
      [class]="expanded1 ? 'expanded1' : ''">
    <div class="footer-top-link">
    <?php print drupal_render($data['footer-top-menu']); ?>
    </div>
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
    
      <span [text]="expanded1 ? '&#9660;' : '&#9650;'">&#9650;</span>
    </figcaption>
</div>
</footer>

