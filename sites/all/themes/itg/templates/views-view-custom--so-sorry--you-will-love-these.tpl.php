<?php
global $base_url;
?>

<ul class="photo-list">
    <?php foreach ($rows as $key => $value) : ?>
        <li class="col-md-3">
            <div class="tile">
                <figure>
                    <div class="large-image">
                        <?php if (!empty($value['field_story_extra_large_image'])) : ?>
                            <a href="<?php print $base_url . '/' . "sosorry/" . $value['nid'] . "" ?>" class="pic">
                                <?php print $value['field_story_extra_large_image'] ?>
                            </a>
                        <?php else : ?>
                            <a href="<?php print $base_url . '/' . "sosorry/ " . $value['nid'] . "" ?>" class="pic">
                                
                                <img width='170' height='127'  src='<?php print $base_url . "/" . drupal_get_path('theme', 'itg'); ?>/images/default_video.jpg' />
                            </a>
                        <?php endif; ?>
                        <figcaption><i class="fa fa-play-circle"></i> <?php print $value['field_video_duration']; ?></figcaption>
                </figure>
                <span class="posted-on"><?php print date ('D, d M, Y',  strtotime($value['created'])) ?></span>
                <?php print l($value['title'], $base_url . '/' . "sosorry/" . $value['nid'] . "") ?>
            </div>
        </li>
    <?php endforeach; ?>
</ul>

