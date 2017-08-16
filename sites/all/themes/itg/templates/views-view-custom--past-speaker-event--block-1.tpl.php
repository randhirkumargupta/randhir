<?php global $base_url; ?>
<div id="past-speaker-slider" class="past-speaker">
<?php foreach ($rows as $row): ?>

  <div class="past-speaker-list">
  <?php

  if (!empty($row['field_story_extra_large_image'])) {
    print $row['field_story_extra_large_image'];
  }
  else {
    $img = "<img width='103' height='103'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/imgpsh_fullsize103x103.png' alt='' />";
    print l($img, $row['php'] . '/speaker-details', array('query' => array('speaker' => $row['nid']), 'html' => TRUE));
  }
  ?>
  <div class="views-field-title" title="<?php echo strip_tags($row['title']);?>"><?php print $row['title']; ?></div>
    <div class="views-field-field-story-new-title"><?php print $row['field_celebrity_pro_occupation']; ?></div>
</div>
<?php endforeach; ?>
</div>
<script>
  jQuery(document).ready(function(){
    jQuery('#past-speaker-slider').slick({
      infinite: true,
      slidesToShow: 3,
      slidesToScroll: 1,
      nextArrow: "<i class='fa fa-chevron-right'></i>",
      prevArrow: "<i class='fa fa-chevron-left'></i>"
    });
  });
</script>