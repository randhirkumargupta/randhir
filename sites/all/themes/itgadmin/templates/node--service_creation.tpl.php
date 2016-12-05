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
                  <a href="<?php print $node_url ?>"><?php print $title ?></a>
              </h2>
            <?php endif; ?>

            <?php if (!empty($title_suffix)) print render($title_suffix); ?>

            <?php if (!empty($content)): ?>
              <div class='<?php print $hook ?>-content clearfix <?php if (!empty($is_prose)) print 'prose' ?>'>
                  <div class="content-node-view">               
                      <div class="content-view">
                          <?php print render($content['field_short_description']); ?>
                          <?php print render($content['field_astro_service']); ?>
                          <?php print render($content['field_service_delivery_mode']); ?>
                          <?php print render($content['field_mobile_xml_format']); ?>
                          <?php print render($content['field_service_fetch_link']); ?>
                          <?php print render($content['field_mobile_number']); ?>
                          <div class="field field-name-field-story-expiry-date field-type-datetime field-label-above">
                              <div class="field-label">Expiry Date:&nbsp;</div>
                                <div class="field-items">
                                      <div class="field-item even">
                                          <span class="date-display-single" property="dc:date" datatype="xsd:dateTime">
                                              <?php print date("l, F j, Y", strtotime($node->field_story_expiry_date[LANGUAGE_NONE][0]['value'])); ?>
                                          </span>
                                      </div>
                                </div>
                              </div>
                          </div>
                          
                          <?php print render($content['field_service_title']); ?>
                          <?php print render($content['field_service_char_limit']); ?>
      
                      </div>
                  </div>  
              </div>
            <?php endif; ?>

            <?php if ($layout): ?>
          </div></div>
    <?php endif; ?>
</div>

<?php if (!empty($post_object)) print render($post_object) ?>

