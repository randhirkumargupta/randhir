<div class="row">
    <div class="col-md-12">
        <div class="video-slider-images">
            <ul class="slick-thumbs-slider">
                <?php foreach ($rows as $index => $row): ?>
                    <li >
                      <?php print $row['title']; ?>
                        <?php print $row['field_itg_funalytics_image']; ?>
                    </li>
                <?php endforeach; ?>
            </ul>            
        </div>        
    </div>

</div>