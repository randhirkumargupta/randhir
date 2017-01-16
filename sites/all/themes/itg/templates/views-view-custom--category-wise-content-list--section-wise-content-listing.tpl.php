<?php
global $base_url;
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php

?>
<?php if (!empty($title)): ?>
    <h3><?php print $title; ?></h3>
<?php endif; ?>

    <?php foreach ($rows as $id => $row): ?>
        <div class="catagory-listing">
            <div class="pic">
                <?php if ($row['field_story_small_image'] != ''): ?>
                    <?php print $row['field_story_small_image']; ?>
                <?php else: ?>
                    <?php if ($row['type'] == 'videogallery'): ?>
                        <?php $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/default_video.jpg' />"; ?>
                    <?php else: ?>
                        <?php $image_link = "<img width='170' height='127'  src='" . $base_url . "/" . drupal_get_path('theme', 'itg') . "/images/default_for_all.png' />"; ?>
                        <?php print l($image_link, "node/" . $row['nid'], array("html" => true)); ?>
                    <?php endif; ?>    
                <?php endif; ?>

            </div>
            <div class="detail"><h3><?php print $row['title'];  ?></h3>
                <?php if (strtolower($row['type']) == 'story'): ?>
                    <p><?php print $row['field_story_kicker_text']; ?></p>
                <?php elseif ($row['type'] == 'photogallery'): ?>
                    <p><?php print $row['field_gallery_kicer']; ?></p>
                <?php elseif ($row['type'] == 'photogallery'): ?>
                    <p><?php print $row['field_story_expert_description']; ?></p>
                <?php endif; ?>
            </div>
        </div>
<?php endforeach; ?>