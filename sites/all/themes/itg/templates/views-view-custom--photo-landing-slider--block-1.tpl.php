<div class="videogallery-slider"> 
    
    <?php foreach ($rows as $index => $row): ?>
        <figure class="" data-img-fid=" <?php print $row['fid']; ?>">
            <?php print $row['field_images']; ?>                    
        </figure>
    <?php endforeach; ?>       
</div>

<div class="row">
    <div class="col-md-12">
        <div class="video-slider-images">
            <ul class="slick-thumbs-slider">
                <?php foreach ($rows as $index => $row): ?>
                    <li >
                        <?php
                      if (!empty($row['field_photo_small_image'])) {
                        print $row['field_photo_small_image'];
                      }
                      else {
                        print '<img  src="' . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image88x66.jpg').'" alt="" title="" />';
                      }
                      ?>
                    </li>
                <?php endforeach; ?>
            </ul>            
        </div>        
    </div>

</div>