<div class="videogallery-slider"> 
    
    <?php foreach ($rows as $index => $row): ?>
        <figure class="" img-fid=" <?php print $row['fid']; ?>">
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
                        <?php print $row['field_images_1']; ?>
                    </li>
                <?php endforeach; ?>
            </ul>            
        </div>        
    </div>

</div>