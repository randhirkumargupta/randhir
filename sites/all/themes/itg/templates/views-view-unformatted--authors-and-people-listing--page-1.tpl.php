<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
global $base_url;
?>
<?php
foreach ($view->result as $id => $item): ?>
<div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
<div class="people-listing">
  <div class="pic">
   <?php if (empty($item->_field_data['nid']['entity']->field_story_extra_large_image['und'][0]['uri'])) { ?>
            <?php
              $img = "<img width='170' height='127'  src='" . file_create_url(file_default_scheme() . '://../sites/all/themes/itg/images/' . 'itg_image170x127.jpg') . "' alt='' title=''/>";
              print l($img, 'node/' . $item->nid, array('html' => TRUE));

           }
           else {
            $image = theme('image_style',array(
                        'style_name' => 'widget_small',
                        'path' => $item->_field_data['nid']['entity']->field_story_extra_large_image['und'][0]['uri'],
                        'attributes' => array('class' => 'custom-inline', 'style' => 'border:1px solid #aaa;')
                      )
                    );
           print l($image, 'node/' . $item->nid, array('html' => TRUE));

          } ?>
  </div>
  <div class="detail">
       <div class="people-right" >
            <h3><?php print l($item->node_title , 'node/' . $item->nid) ?></h3>

            <p><?php print mb_strimwidth(html_entity_decode(strip_tags($item->field_body[0]['rendered']['#markup'])), 0, 245, "..");  ?></p>
      </div>
  </div>
</div>
</div>
<?php endforeach; ?>
