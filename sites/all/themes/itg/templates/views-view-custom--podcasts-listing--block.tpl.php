<h3><span><?php print t("Other podcast") ?></span></h3>
<ul class="photo-list">    
<?php foreach ($rows as $index => $row): ?>
    <li class="col-md-3">
        <div class="tile">
            <?php if(!empty($row['field_story_extra_large_image'])) : ?>
            <figure>                
                <?php print $row['field_story_extra_large_image'] ?>    
                    <figcaption><i class="fa fa-volume-up" aria-hidden="true"></i> 9:10</figcaption>
                <?php endif;?>
            </figure>
            <?php if(!empty($row['created'])) : ?>
            <span class="posted-on"><?php print $row['created'] ?></span>        
    <?php endif;?>
             <?php if(!empty($row['title'])) : ?>
        <?php print $row['title'] ?>
    <?php endif;?>

        </div>
    </li>    

<?php endforeach; ?>
</ul>