<div class="col-sm-12 related-story-list">
    <div class="row">
    <div class="clearfix">
    <?php 
    if(is_array($data) && count($data) > 0) {

     foreach ($data as $key => $value){ 
       $file_uri = $value['uri'];
         ?>
         <div class="midstoryleft">
             <a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $value['nid']); ?>" target="_blank">
       <?php if (!empty($file_uri)) : ?>
               <img src="<?php print $file_uri; ?>" alt="" title="" width="125" align="left" height="93" />
       <?php else : ?>
                 <img src="<?php print  file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image483x271.jpg'); ?>" width="125" align="left" height="93" />
       <?php endif; ?>
             </a>
           <div class="midstorydetail">
               <div class="midstorytitle"><a href="<?php echo $base_url . '/' . drupal_get_path_alias("node/" . $value['nid']); ?>" target="_blank"><?php print $value['title']; ?></a>
               </div>
               <div class="midstoryintro"><?php print $value['title']; ?></div>
           </div>
         </div>
    <?php

     }
    }  
    ?>
    </div>
        </div>

</div>