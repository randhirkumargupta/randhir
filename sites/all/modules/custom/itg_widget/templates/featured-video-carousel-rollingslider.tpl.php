<?php
global $base_url;
if (!empty($data)) {
  ?>

  <div class="container">
    <div class="carousel">
      <div class="slides">                     
        <?php
        $i = 1;
        $countd = 1;
        foreach ($data as $entity_data_node) {
          ?>
          <div class="slideItem"> 
              <a title="<?php echo $entity_data_node['title']; ?>" href="<?php print $entity_data_node['node_url']; ?>?category=<?php print $entity_data_node['cat']; ?>&sid=<?php print $entity_data_node['sid']; ?>&pcat=<?php print $entity_data_node['primary_category']; ?>">
              <?php //print $entity_data_node['file_url']; ?>
                <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
            <!--<img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg" alt="" />-->
              <span class="flex-count" style="text-align: right"><i class="fa fa-play-circle"></i></span>
              <span class="pic-tit"><?php print $entity_data_node['title']; ?></span>
              <span class="overlay"></span>
            </a>

          </div>  

          <?php
          $i++;
        }
        ?>

      </div>
    </div>
  </div>

<?php } ?>

  <!--This Uncompressed CSS is for photo rolling slider to set title and image count visibleness for centered image.  -->
<style>
.carousel .slides .slideItem[style*="width: 645px"] span{
    opacity: 1;
      -webkit-transition: all 500ms ease .2s;
    -moz-transition: all 500ms ease .2s;
    -o-transition: all 500ms ease .2s;
    transition: all 500ms ease .2s;
}
.carousel .slides .slideItem[style*="width: 645px"] span.overlay{
    opacity: 0;
      -webkit-transition: all 500ms ease .2s;
    -moz-transition: all 500ms ease .2s;
    -o-transition: all 500ms ease .2s;
    transition: all 500ms ease .2s;
}
</style>  
