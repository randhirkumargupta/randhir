<?php
//p($entity_data_node);
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
            
           <a href="<?php print $entity_data_node['node_url']; ?>?category=<?php print $entity_data_node['cat']; ?>&sid=<?php print $entity_data_node['sid']; ?>">
              <span class="flex-count"><i class="fa fa-camera"></i> <?php echo $entity_data_node['count'] . ' ' . $itext; ?></span>
              <span class="pic-tit" title="<?php echo $entity_data_node['title']; ?>"><?php print $entity_data_node['title']; ?></span>
              <span title="<?php echo $entity_data_node['image_title']; ?>" class="overlay"></span>
            </a>
          </div>  

    <?php $i++;
  }
  ?>

      </div>
    </div>
  </div>

<?php } ?>
