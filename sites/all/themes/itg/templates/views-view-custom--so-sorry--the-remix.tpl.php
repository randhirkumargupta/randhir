<?php
global $base_url;
$remix_data = $rows[0];
?>

<div class="sosorry-social">
    <ul>
        <li><a href="#"><i class="fa fa-facebook"></i></a></li>
        <li><a href="#"><i class="fa fa-twitter"></i></a></li>
        <li><a href="#"><i class="fa fa-google-plus"></i></a></li>
        <li><a href="#"><i class="fa fa-rss"></i></a></li>        
    </ul>
</div>


<h2>THE <span>REMIX</span></h2>
<div class="large-image">
  <?php if (!empty($remix_data['field_story_extra_large_image'])) : ?>
    <a href="<?php print $base_url . '/' . "sosorry/" . $remix_data['nid'] . "" ?>" class="pic">
      <?php print $remix_data['field_story_extra_large_image'] ?>
    </a>
  <?php else : ?>
    <a href="<?php print $base_url . '/' . "sosorry/video/" . $remix_data['nid'] . "" ?>" class="pic">
      <img  src="<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_for_all.png" />
    </a>
  <?php endif; ?>
</div>
<div class="title">
  <?php print l(mb_strimwidth($remix_data['title'], 0, 45, ".."), $base_url . '/' . "sosorry/" . $remix_data['nid'] . ""); ?>
</div>