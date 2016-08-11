<?php 
if (!empty($data)) {
    ?>
    <div class="flexslider">
        <ul class="slides"> 
            <?php
            foreach ($data as $entity_data_node) {
                ?>
                <li>
                    <a href="<?php echo  $entity_data_node['node_url']; ?>"><?php print $entity_data_node['file_url']; ?></a>
                    <div class="detail">
                        <p class="flex-count"><i class="fa fa-camera" aria-hidden="true"></i> <?php echo  $entity_data_node['count']; ?> Images</p>
                        <p class="flex-caption"><?php print $entity_data_node['caption']; ?></p>
                    </div>
                </li>
    <?php } ?>
        </ul>
    </div>


<?php } else { ?>
    No Feature content found
<?php } ?>