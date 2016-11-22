<?php
/**
 * @file
 *   Career graph page template.
 */
?>

<?php foreach ($output as $key => $value): ?>
<?php
  $actor_pic = theme(
    'image_style', array(
      'style_name' => 'cart_172x240',
      'path' => $actor[$key]['pic_uri'],
    )
  );
?>
  <ul type="square">
      <li><?php print t('Career Graph'); ?></li>
      <li><?php print $actor[$key]['name']; ?></li>      
      <li><?php print $actor_pic; ?></li>
  </ul>
  <?php print drupal_render($value); ?>
<?php endforeach; ?>


