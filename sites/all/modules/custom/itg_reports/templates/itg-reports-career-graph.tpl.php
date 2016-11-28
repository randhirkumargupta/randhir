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
      'style_name' => 'mr_graph_pic',
      'path' => $actor[$key]['pic_uri'],
    )
  );
?>
<div class="career-graph-data">
    <div class="gray-bg"><?php print t('Career Graph'); ?></div>
    <div class="black-bg"><?php print $actor[$key]['name']; ?></div>
    <?php print $actor_pic; ?>
</div>  
  <?php print drupal_render($value); ?>
<?php endforeach; ?>


