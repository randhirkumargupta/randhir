<?php if (is_array($data) && count($data) > 0) {  ?>
<div class="slider_besrCollage slider_outer">
    <?php foreach($data as $index => $row) { 
         $file = file_load($row['field_story_extra_large_image_fid']);
         $image = file_create_url($file->uri);
      ?>
    <div>
      <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>" target="_blank">
       <?php if (!empty($image)) : ?>
               <img src="<?php print $image; ?>" alt="" title="" width="125" align="left" height="93" />
       <?php else : ?>
                 <img src="<?php print  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg'); ?>" width="125" align="left" height="93" />
       <?php endif; ?>
      </a>

                <div class="carousel-caption">
                <?php echo l(mb_strimwidth(strip_tags($row['title']), 0, 105, ".."), $base_url . '/' . drupal_get_path_alias("node/{$row['nid']}")) ?>
                  
                </div>
        </div>
  <?php } ?>
</div>
<?php } ?>

<script>
jQuery(document).ready(function () {
    jQuery('.slider_outer').slick({
        slidesToShow: 1,
        slidesToScroll: 1,
        arrows: true,
        fade: false
    });
});
</script>

