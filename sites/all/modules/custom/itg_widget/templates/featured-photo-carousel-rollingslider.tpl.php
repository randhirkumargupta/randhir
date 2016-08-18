<?php
if (!empty($data)) {  ?>

  <div class="container">
    <div class="carousel">
      <div class="slides">                     
        <?php $i = 1;
        $countd = 1;
        foreach ($data as $entity_data_node) { ?>

          <div class="slideItem"> 
            <a href="#">
              <?php //print $entity_data_node['file_url'];  ?>
              <img src="/itgcms/sites/all/themes/itg/images/demo-photo.jpg">
              <span class="flex-count"><?php echo $entity_data_node['count']; ?> Images </span>
            </a>
            <span class="pic-tit"><?php print $entity_data_node['caption']; ?></span>
          </div>  

        <?php $i++;
} ?>

      </div>
    </div>
  </div>

<?php } else { ?>
  No Feature content found
<?php } ?>

  
  
