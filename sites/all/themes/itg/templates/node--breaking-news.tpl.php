<?php

/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
global $base_url;
?>

<div class="live-block">

<?php

if (!empty($content)):

    $type = $node->field_type['und']['0']['value'];
    if ($type === 'Live Blog') {
        $title = $node->title;
        ?>
    <h1><span><?php print ($type) ?></span>: <?php print ($title) ?></h1>
    <p class="short-discription"> <?php print ($node->field_label['und']['0']['value'])?></p>
    <?php
        }
    ?>
    <iframe width="100%" height="360" frameborder="0" style="z-index:4" class="media__video--responsive" id="livetv_video1" scrolling="no" allowfullscreen="" src="http://livestream.com/accounts/11965022/events/4086327/player?width=640&amp;height=360&amp;autoPlay=true&amp;mute=false"></iframe>
    <?php
        if (!empty($node->field_breaking_content_details[LANGUAGE_NONE])) {
            $breaking_output.= '';
            foreach ($node->field_breaking_content_details['und'] as $blog_item) {
                $field_collection_ids[] = $blog_item['value'];
            }
            rsort($field_collection_ids);

            foreach ($field_collection_ids as $breaking_item) {

                $breaking_output.= '<div class="breaking-section">';

                $field_collection_id = $breaking_item;
                $entity = entity_load('field_collection_item', array($field_collection_id));
                $pub_time = date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800);
                $breaking_output.= '<div class="breaking-date">' . $pub_time . ' IST</div>';
                $breaking_output.= '<div class="breaking-discription">' . $entity[$field_collection_id]->field_breaking_tile['und'][0]['value'] . '</div><div class="social-share"><ul><li><a class="share" href="#"><i class="fa fa-share-alt"></i></a></li><li><a href="#" class="facebook"><i class="fa fa-facebook"></i></a></li><li><a href="#" class="twitter"><i class="fa fa-twitter"></i></a></li><li><a href="#" class="google"></a></li></ul></div>';
                $breaking_output.= '</div>';
            }
            print $breaking_output;
        }

    endif;
?>
</div>