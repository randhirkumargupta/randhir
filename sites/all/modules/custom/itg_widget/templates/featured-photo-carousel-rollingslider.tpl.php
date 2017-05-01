<?php
//p($entity_data_node);
global $base_url;

//drupal_add_css('', array('type' => 'inline', 'scope' => 'footer'));

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
<!--            <a href="<?php //echo $base_url ?>/node/<?php //print $entity_data_node['nid']; ?>">-->
              <a title="<?php echo $entity_data_node['title']; ?>" href="<?php print $entity_data_node['node_url']; ?>?category=<?php print $entity_data_node['cat']; ?>&sid=<?php print $entity_data_node['sid']; ?>">
              <?php// print $entity_data_node['file_url']; ?>
                <img src="<?php print $entity_data_node['file_url']; ?>" title="<?php echo $entity_data_node['image_title']; ?>" alt="<?php echo $entity_data_node['image_alt']; ?>" />
              <?php
              $itext = '';
              if ($entity_data_node['count'] > 1) {
                $itext = 'Images';
              }
              elseif ($entity_data_node['count'] == 1) {
                $itext = 'Image';
              }
              ?>
            <!--<img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg" alt="" />-->
              <span class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count'] . ' ' . $itext; ?></span>
              <span class="pic-tit"><?php print $entity_data_node['title']; ?></span>
              <span class="overlay"></span>
            </a>

          </div>  

    <?php $i++;
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

