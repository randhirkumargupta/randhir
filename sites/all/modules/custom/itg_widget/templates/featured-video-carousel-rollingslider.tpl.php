<?php
//p($entity_data_node);
global $base_url;
if (!empty($data)) {  ?>

  <div class="container">
    <div class="carousel">
      <div class="slides">                     
        <?php $i = 1;
        $countd = 1;
        foreach ($data as $entity_data_node) { ?>

          <div class="slideItem"> 
              <a href="<?php echo $base_url?>/node/<?php print $entity_data_node['nid']; ?>">
              <?php //print $entity_data_node['file_url'];  ?>
              <img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg">
              <span class="flex-count" style="text-align: right"><i class="fa fa-play-circle"></i></span>
              <span class="pic-tit"><?php print $entity_data_node['title']; ?></span>
            </a>
            
          </div>  

        <?php $i++;
} ?>

      </div>
    </div>
  </div>

<?php } else { ?>
  No Feature content found
<?php } ?>

  
  
