<?php 
  $data_tb_region_item = '';
  if(drupal_is_front_page()){
   $data_tb_region_item = 'data-tb-region-item';  
  }
?>
<div class="row">
    <div class="col-md-12">
        <div class="auto-block-1">
            <div class="fifa-top-story">
                <?php
                global $base_url;
                foreach ($rows as $index => $row) {
                  $desc = $row['title'];
                  if (function_exists('itg_common_remove_extra_html')) {
                    $desc = itg_common_remove_extra_html($desc);
                  }
                  
                    ?>
                    <div class="fifa-post fifa-post-first">                        
                        <?php
                        if ($row['field_story_large_image'] != "") {
                          print $row['field_story_medium_image'];
                        }
                        else {
                          print "<img  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg') ."' alt='' title='' />";
                        }
                        ?> 

                        <h3 <?php echo $data_tb_region_item;?> title="<?php echo strip_tags($desc); ?>">                         
                            <?php
                            if (function_exists('itg_common_get_smiley_title')) {
                              echo l(itg_common_get_smiley_title($row['nid'], 0, 77), "node/" . $row['nid'], array("html" => TRUE));
                            }
                            else {
                              echo l(mb_strimwidth(html_entity_decode(strip_tags($desc)), 0, 70, ".."), "node/" . $row['nid']);
                            }
                          ?>
                        </h3>           
                    </div>
            <?php } ?>
            </div>
        </div>    
    </div>
</div>

