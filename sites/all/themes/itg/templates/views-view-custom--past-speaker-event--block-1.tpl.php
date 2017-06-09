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
<style>
.past-speaker .views-field-title{
  text-transform: uppercase;
  padding: 10px 0 0;
}
.past-speaker .views-field-field-story-new-title{
  font-size: 13px;
  color: #8d8d8d;
}
.past-speaker .slick-list{
  max-width: 620px;
  margin: 0 auto;
}
.past-speaker .slick-arrow{
  position: absolute;
  width: 30px;
  height: 30px;
  top: 0;
  bottom: 0;
  margin: auto 0;
  font-size: 20px;
  line-height: 30px;
  text-align: center;
}
.past-speaker .slick-arrow.fa-chevron-right{right: 0;}
.past-speaker-list{ text-align: center;}
.past-speaker a{display: block;}
.past-speaker a img{border-radius: 50%; display: inline-block; vertical-align: top;}
#block-views-past-speaker-event-block-1 .block-title{
  font-size: 24px;
  color: #ef3c24;
  font-family: "Roboto Slab", sans-serif;
  margin-bottom: 15px;
}
</style>
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