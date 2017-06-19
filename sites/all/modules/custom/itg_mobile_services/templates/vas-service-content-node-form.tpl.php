<div id="BasicDetails">
  <?php print drupal_render($form['field_service_association_title']); ?>
  <?php print drupal_render($form['field_footer']); ?>
  <?php print drupal_render($form['field_service_frequency']); ?>
  <?php print drupal_render($form['field_service_frequency_date']); ?>
  <?php print drupal_render($form['field_service_content']); ?>
</div>
<?php print drupal_render_children($form); ?>
<div><?php print drupal_render($form['actions']); ?></div>