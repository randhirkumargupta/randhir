<div class="slider_besrCollage slider_outer">
    <?php foreach($data as $index => $row) { 
         $file_uri = $row['uri'];
      ?>
    <div>
      <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $row['nid']); ?>" target="_blank">
       <?php if (!empty($file_uri)) : ?>
               <img src="<?php print $file_uri; ?>" alt="" title="" width="125" align="left" height="93" />
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