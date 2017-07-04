<a href="javascript:;" class="close-preview">&nbsp;</a>
<?php if (!empty($pre_object)) print render($pre_object) ?>

<div class='<?php print $classes ?> clearfix' <?php print ($attributes) ?>>
    <?php if (!empty($layout) && (!empty($submitted) || !empty($links))): ?>
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

            <?php if (!empty($layout) && (!empty($submitted) || !empty($links))): ?>
          </div></div>
    <?php endif; ?>

    <?php if (!empty($layout)): ?>
      <div class='column-main'><div class='column-wrapper'>
            <?php endif; ?>

            <?php if (!empty($title_prefix)) print render($title_prefix); ?>

            <?php if (!empty($title_suffix)) print render($title_suffix); ?>

            <?php if (!empty($content)): ?>
              <div class='<?php print !empty($hook) ? $hook : ''; ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>

                  <!--      for preview-->
                  <?php if ($view_mode == 'full') { ?>
                    <div class="field">
                        <div class="field-label"><?php print t('Movie Title:'); ?></div>
                        <div class="field-items"><?php print render($title); ?></div>
                    </div>
                    <?php print render($content['field_mega_review_cast']); ?>
                    <?php print render($content['field_mega_review_type']); ?>
                    <?php print render($content['field_mega_review_director']); ?>
                    <?php print render($content['field_mega_review_movie_plot']); ?>
                    <?php print render($content['field_mega_review_youtube_url']); ?>
                    <?php print render($content['field_mega_review_photo_gallery']); ?>
                    <?php print render($content['field_mega_review_twitter']); ?>
                    <div class="field">
                        <div class="field-label"><?php print t('Image:'); ?></div>
                        <div class="field-items"><?php print render($content['field_story_extra_large_image']); ?></div>
                    </div>
                    <?php print render($content['field_mega_review_video']); ?>
                    <?php
                    $mega_output = '';
                    if (isset($node->op) && $node->op == 'Preview') {
                      $mega_output.= '';
                      foreach ($node->field_mega_review_review['und'] as $mega_item):
                        $byline_id = $mega_item['field_story_reporter']['und'][0]['target_id'];
                        $reporter_node = node_load($byline_id);
                        $mega_output.= '<div class="buzz-section">';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Review type:') . '</div><div class="field-items">' . $mega_item['field_story_review_type'][LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Headline:') . '</div><div class="field-items">' . $mega_item['field_buzz_headline'][LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Reviewer:') . '</div><div class="field-items">' . $reporter_node->title . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Review URL Link:') . '</div><div class="field-items">' . $mega_item['field_mega_review_url_link'][LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Description:') . '</div><div class="field-items">' . $mega_item['field_mega_review_description'][LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Rating:') . '</div><div class="field-items">' . $mega_item['field_story_rating'][LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '</div>';
                        $mega_output.= '<hr/><br/>';
                      endforeach;
                      ?>
                      
                    <?php
                    }
                    else {
                      $mega_output.= '';
                      foreach ($node->field_mega_review_review['und'] as $mega_item):
                        $ans_detail = entity_load('field_collection_item', array($mega_item['value']));
                        
                        $byline_id = $ans_detail[$mega_item['value']]->field_story_reporter['und'][0]['target_id'];
                        $reporter_node = node_load($byline_id);
                        $mega_output.= '<div class="buzz-section">';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Review type:') . '</div><div class="field-items">' . $ans_detail[$mega_item['value']]->field_story_review_type[LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Headline:') . '</div><div class="field-items">' . $ans_detail[$mega_item['value']]->field_buzz_headline[LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Reviewer:') . '</div><div class="field-items">' . $reporter_node->title . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Review URL Link:') . '</div><div class="field-items">' . $ans_detail[$mega_item['value']]->field_mega_review_url_link[LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Description:') . '</div><div class="field-items">' . $ans_detail[$mega_item['value']]->field_mega_review_description[LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '<div class="field"><div class="field-label">' . t('Rating:') . '</div><div class="field-items">' . $ans_detail[$mega_item['value']]->field_story_rating[LANGUAGE_NONE][0]['value'] . '</div></div>';
                        $mega_output.= '</div>';
                        $mega_output.= '<hr/><br/>';
                      endforeach;
                    }

                    if (!empty($mega_output)) {
                      ?>
                      <div class="Templates-buzz">
                          <h2><?php print t('Movie Review'); ?></h2>

                          <div class="content-details">
                              <?php print $mega_output; ?>
                          </div>
                      </div>
                      <?php
                    }
                  }
                  ?>
                  <!--end preview-->
              </div>
<?php endif; ?>

            <?php if (!empty($layout)): ?>
          </div></div>
            <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

