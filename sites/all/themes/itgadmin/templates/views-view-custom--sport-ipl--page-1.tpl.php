<div class="page-sports-photo">
<div class="view-content">
    <ul class="photo-list"> 
        <?php foreach ($rows as $index => $row) {
            ?>

            <li class="col-md-3">

                <div class="tile">
                    <figure><?php print $row['field_story_extra_large_image']; ?>
                        <figcaption><i class="fa fa-camera"></i> <?php echo $row['delta']; ?></figcaption>
                    </figure>
                    <span class="posted-on"><?php echo $row['created']; ?></span>
                    <?php print ucfirst($row['title']); ?>
                </div>         
            </li>
        <?php }; ?>
    </ul>
</div>
</div>