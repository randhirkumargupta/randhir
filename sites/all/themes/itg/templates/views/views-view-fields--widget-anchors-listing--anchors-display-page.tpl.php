<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($view->result as $item): ?>
<div class="anchor-listing">
  <div class="pic">
   <?php if (empty($item->field_story_extra_large_image[0]['raw']['uri'])) { ?>
            <?php
              $img = "<img width='170' height='127'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/itg_image170x127.jpg' alt=''/>";
              print l($img, 'node/' . $item->nid, array('html' => TRUE));
              
           } 
           else { 
            $image = theme('image_style',array(
                        'style_name' => 'widget_small',
                        'path' => $item->field_story_extra_large_image[0]['raw']['uri'],
                        'attributes' => array('class' => 'custom-inline', 'style' => 'border:1px solid #aaa;')
                      )
                    );
            print $image;

          } ?> 
       <?php if (function_exists('itg_follow_unfollow_print')) { ?>    
      <span class="attended-link">
        <?php 
            $followers = itg_get_followers($item->nid);
            if(!empty($followers)) {
              print itg_get_followers($item->nid) . " followers";
            } 
        ?>
      </span>
      <?php } ?>  
  </div>
  <div class="detail">
       <div class="anchor-right" >
            <h3><?php print $item->node_title; ?></h3>
            <p><?php print mb_strimwidth(html_entity_decode(strip_tags($item->field_body[0]['rendered']['#markup'])), 0, 245, "..");  ?></p>
            <?php if (function_exists('itg_follow_unfollow_print')) { ?>
            <p><?php print itg_follow_unfollow_print($item->nid); ?></p>
            <?php } ?>
      </div>
  </div>
</div>  
<?php endforeach; ?>