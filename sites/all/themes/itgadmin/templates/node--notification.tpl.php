<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $status: Flag for published status.
 * 
 * @ingroup themeable
 */
?>
<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    <div class='column-side'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($submitted)): ?>
    <div class='<?php print $hook ?>-submitted clearfix'><?php print $submitted ?></div>
  <?php endif; ?>

  <?php if (!empty($links)): ?>
    <div class='<?php print $hook ?>-links clearfix'>
      <?php print render($links) ?>
    </div>
  <?php endif; ?>

  <?php if ($layout && (!empty($submitted) || !empty($links))): ?>
    </div></div>
  <?php endif; ?>

  <?php if ($layout): ?>
    <div class='column-main'><div class='column-wrapper'>
  <?php endif; ?>

  <?php if (!empty($title_prefix)) print render($title_prefix); ?>

  <?php if (!empty($title) && !$page): ?>
    <h2 <?php if (!empty($title_attributes)) print $title_attributes ?>>
      <?php if (!empty($new)): ?><span class='new'><?php print $new ?></span><?php endif; ?>
      <?php print $title ?>
    </h2>
  <?php endif; ?>

  <?php if (!empty($title_suffix)) print render($title_suffix); ?>

  <?php if (!empty($content)): ?>
    <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
      <div class="content-node-view">
          <div class="basic-details content-box">
            <h2><?php echo t('Notification Details'); ?></h2>
            <div class="content-details">
              <div class="field">
                <div class="field-label"><?php print t('Select Device:'); ?></div>
                <div class="field-items"><?php
                    foreach ($node->field_ntf_select_device[LANGUAGE_NONE] as $device_arr) {
                      $device_name .= $device_arr['value'] . ', ';
                    }
                    print ucwords(rtrim($device_name, ", "));
 
                 ?>
                </div>
              </div>

              <div class="field">
                <div class="field-label"><?php print t('Schedule:'); ?></div>
                <div class="field-items"><?php print date('d/m/Y h:i', strtotime($node->field_ntf_schedule[LANGUAGE_NONE][0]['value'])); ?></div>
              </div>

              <div class="field">
                <div class="field-label"><?php print t('Message Title:'); ?></div>
                <div class="field-items"><?php print ucwords($node->title); ?></div>
              </div>

              <?php if ($node->field_cm_redirection_url[LANGUAGE_NONE][0]['value']) { ?>
                <div class="field">
                  <div class="field-label"><?php print t('Message URL:') ?></div>
                  <div class="field-items"><?php print $node->field_cm_redirection_url[LANGUAGE_NONE][0]['value']; ?></div>
                </div>
              <?php } ?>
              
              <?php if($node->body[LANGUAGE_NONE][0]['value']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Custom Data:'); ?></div>
                <div class="field-items"><?php print ucfirst($node->body[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <?php } ?>
              
              <?php if($node->field_news_cid[LANGUAGE_NONE][0]['target_id']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Assign Story:'); ?></div>
                <div class="field-items"><?php print $node->field_news_cid['und'][0]['target_id']; ?></div>
              </div>
              <?php } ?>
            </div>
          </div>
        </div>
      <div class="content-node-view">
          <div class="basic-details content-box">
            <h2><?php echo t('Android Details'); ?></h2>
            <div class="content-details">
              
              <?php if($node->field_survey_question[LANGUAGE_NONE][0]['value']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Android Header:'); ?></div>
                <div class="field-items"><?php print ucwords($node->field_survey_question[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <?php } ?>
              
              <?php if($node->field_ntf_android_vibration[LANGUAGE_NONE][0]['value']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Android Force Vibration:'); ?></div>
                <div class="field-items"><?php print $node->field_ntf_android_vibration[LANGUAGE_NONE][0]['value'] ? 'Yes' : 'No'; ?></div>
              </div>
              <?php } ?>
              
              <?php if($node->field_ntf_android_sound[LANGUAGE_NONE][0]['value']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Android Sound:'); ?></div>
                <div class="field-items"><?php print ucwords($node->field_ntf_android_sound[LANGUAGE_NONE][0]['value']); ?></div>
              </div>
              <?php } ?>
              
              <?php if($node->field_news_thumbnail[LANGUAGE_NONE][0]['fid']) { ?>
              <div class="field">
                <div class="field-label"><?php print t('Android Custom Icon:'); ?></div>
                <div class="field-items"><img src="<?php print image_style_url("thumbnail", $node->field_news_thumbnail[LANGUAGE_NONE][0]['uri']); ?>" /></div>
              </div>
              <?php } ?>
              
              <?php if($node->field_newst_banner[LANGUAGE_NONE][0]['fid']) { ?> 
              <div class="field">
                <div class="field-label"><?php print t('Custom Banner:'); ?></div>
                <div class="field-items"><img src="<?php print image_style_url("thumbnail", $node->field_newst_banner[LANGUAGE_NONE][0]['uri']); ?>" /></div>
              </div>
              <?php } ?>
              
            </div>
          </div>
        </div>   
 </div>   
  <?php endif; ?>
  <?php if ($layout): ?>
    </div></div>
  <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>