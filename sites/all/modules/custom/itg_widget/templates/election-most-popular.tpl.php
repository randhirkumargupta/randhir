<div class="row">    
    <?php
    global $base_url;
    foreach ($data as $index => $row) {
        $row = (array)$row;
        $video_class = "";
        if (strtolower($row['type']) == 'videogallery') {
            $video_class = 'video-icon';
        }
        ?>
        <div class="col-md-3 col-sm-3 col-xs-6">
            <a class="<?php echo $video_class; ?>" href="<?php echo FRONT_URL . '/' . drupal_get_path_alias("node/{$row['nid']}") ?>">
                <?php
                if ($row['uri'] != "") {
                  ?>
                    <img src="<?php print image_style_url("video_landing_page_170_x_127", $row['uri']); ?>" alt="<?php echo $row['title'];?>" title="<?php echo $row['title'];?>" />
                 <?php
                }
                else {
                    print "<img  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') ."' alt='' title='' />";
                }
                ?>
            </a>
            <p title="<?php print $row['title'];?>">            
            <?php
             print $row['title'];
            ?>
            </p>            
        </div>         
<?php } ?>    
</div>
