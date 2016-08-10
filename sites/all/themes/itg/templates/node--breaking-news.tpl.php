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
        $breaking = 1;
        foreach ($node->field_breaking_content_details['und'] as $breaking_item) {

            $breaking_output.= '<div class="breaking-section">';

            $field_collection_id = $breaking_item['value'];
            $entity = entity_load('field_collection_item', array($field_collection_id));
            $pub_time =  date("H:i", strtotime($entity[$field_collection_id]->field_breaking_publish_time['und'][0]['value']) + 19800 );
            $breaking_output.= '<div class="breaking-discription"><span>' . $breaking . '</span>' . $entity[$field_collection_id]->field_breaking_tile['und'][0]['value'] . '</div>';
            $breaking_output.= '<div class="breaking-discription">' . $pub_time . ' IST</div>';
            $breaking_output.= '</div>';
            $breaking++;
        }
        print $breaking_output;
    }

endif;
?>
</div>