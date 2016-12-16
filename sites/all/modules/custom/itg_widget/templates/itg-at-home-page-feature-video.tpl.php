<?php
  global $base_url;
  $default_image_src = $base_url . "/" . drupal_get_path('theme', 'aajtak') . "/images/default_for_all.png";
  $default_image_fornt = "<img src='" . $default_image_src . "' alt='Images'>";
?>
<?php foreach($data as $node_data) : ?>

  
  <?php if(!empty($node_data->field_story_extra_large_image['und'][0]['uri'])) : ?>
    <?php echo $default_image_fornt; ?>
    <?php else : ?>
    <?php
     $image_src =  image_style_url("at_big_story_front_promoted_image", $node_data['uri']);
     $image = '<img src="'.$image_src.'" />';
     print l($image , 'node/'.$node_data['nid'] , array('html' => TRUE)); ?>
  <?php endif; ?>


  <?php
    if (!empty($node_data->field_primary_category)) {
      $term_data = taxonomy_term_load($node_data->field_primary_category['und'][0]['tid']);
      print $term_data->title;
    }
  ?>

<?php print l(mb_strimwidth($node_data->title, 0, 65, ".."), 'node/' . $node_data->nid); ?>


<?php 
  if(isset($node_data->uid) && !empty($node_data->uid)) {
    $user_load_data = user_load($node_data->uid);
    print l($user_load_data->name , 'user/'.$user_load_data->uid);
  }
?>

<?php print date('m:s' , time($node_data->created));?>
<?php print t("IST"); ?>

<?php endforeach; ?>
