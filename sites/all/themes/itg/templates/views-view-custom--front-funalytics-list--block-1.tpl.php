        <span class="close-popup"><i class="fa fa-times" aria-hidden="true"></i></span>
        <div class="funalytics-slider-wrapper">
            <div class="funalytics-slider">
                <?php foreach ($rows as $index => $row): ?>
                    <div>
                      <div class="title"><?php print $row['title']; ?></div>
                      <div class="pic"><?php print $row['field_itg_funalytics_image']; ?></div>
                    </div>
                <?php endforeach; ?>
            </div>            
        </div> 