<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
    <?php //print render($content) ?>
    <?php if ($view_mode == 'full'): ?>
      <a href="javascript:;" class="close-preview">&nbsp;</a>
      <div class="content-node-view">
        <h2>Basic Details</h2>
        <div class="content-details">
          <?php print render($content['field_type']); ?>
          <?php print render($content['field_content_type']); ?>
          <?php
          if($node->field_story_expires[LANGUAGE_NONE][0]['value'] == 'Yes') {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Live TV:'); ?></div>
            <div class="field-items"><?php print 'Yes'; ?></div>
          </div>
          <?php  
          }
          ?>
          <div class="field">
            <div class="field-label"><?php print t('Breaking Text:'); ?></div>
            <div class="field-items"><h1><?php print $title; ?></h1></div>
          </div>

          <?php $short_des = render($content['field_label']);
          ?>
          <?php if (!empty($short_des)): ?>
            <?php
            if (!empty($short_des)):
              print render($content['field_label']);
              ?>
            <?php endif; ?>

          <?php endif; ?>
          <div class="field">
            <?php
            $type = $node->field_type[LANGUAGE_NONE][0]['value'];
            if ($type == 'Live Blog'):

              print '<div class="field-label">Section</div>';
              print '<div class="field-items">';
              foreach ($node->field_section[LANGUAGE_NONE] as $value) {
                print '<div>' . $value[taxonomy_term]->name . '</div>';
              }
              print '</div>';
            endif;
            ?>
            <?php
            //$keywords = render($content['field_story_itg_tags']);

            //if (!empty($keywords)):
              ?>
              <!--<div class="display content-box">
              <?php print render($content['field_story_itg_tags']); ?>
              </div>-->
    <?php //endif; ?>
          </div>
        </div>
      </div>

      <?php
      $display_on = render($content['field_display_on']);
      $cnd = $content['field_display_on']['#items']['0']['value'];
      if (!empty($display_on)):
        ?>
        <div class="content-node-view">
          <?php if ($cnd != ''): ?>
            <h2><?php print t('Display on'); ?></h2>
            <?php endif ?>
          <div class="content-details">
            <?php
            if ($cnd == 'Home Page'):
              print render($content['field_display_on']);
            endif;
            if ($cnd == 'Section'):
              print render($content['field_section']);
            endif;
            ?>
          </div>
        </div>
      <?php endif; ?>

      <?php
      $browsemedia = render($content['field_story_extra_large_image']);
      if (!empty($browsemedia)):
        ?>
        <div class="content-node-view">
          <h2><?php print t('Browse Media'); ?></h2>
          <div class="content-details">
        <?php print render($content['field_story_extra_large_image']); ?>
          </div>
        </div>
    <?php endif; ?>

      <div class="content-node-view">
       
        <div class="content-details">
    <?php  //print render($content['field_breaking_content_details']); 
    
    $num = 0;
        foreach ($node->field_breaking_content_details[LANGUAGE_NONE] as $news_arr) {
          $sn = $num + 1;
          echo '<h2>Content ' . $sn . ' Details:</h2>';
          //p($news_arr);
          ?>
          <div class="field">
            <div class="field-label">Title:</div>
            <div class="field-items"><?php echo $news_arr['field_breaking_tile'][LANGUAGE_NONE][0]['value']; ?></div>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <?php if(!empty($news_arr['field_mark_as_breaking_band'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label">Mark as Breaking band : </div>
            <div class="field-items"><?php echo 'Yes'; ?></div>
            <?php } ?>
            <?php } ?>
            <?php if(!empty($news_arr['field_notification_'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label">Notification : </div>
            <div class="field-items"><?php echo 'Yes'; ?></div>
            <?php } ?>
            <?php if(!empty($news_arr['field_mobile_subscribers'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label">Mobile subscribers : </div>
            <div class="field-items"><?php
                      foreach ($news_arr['field_mobile_subscribers'][LANGUAGE_NONE] as $subs) {
                        print $subs['value'].'<br/>';
            } 
                      ?></div>
            <?php } ?>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <div class ="field-label">Publish Time : </div>
            <div class="field-items"><?php echo $news_arr['field_breaking_publish_time'][LANGUAGE_NONE][0]['value']; ?></div>
            <?php } ?>
            <?php if($news_arr['field_breaking_redirection_url'][LANGUAGE_NONE][0]['value'] != '') { ?>
            <div class ="field-label">Redirection url : </div>
            <div class="field-items"><?php echo $news_arr['field_breaking_redirection_url'][LANGUAGE_NONE][0]['value']; ?></div>
          <?php } ?>  
          </div>
            
    <?php
    $num++;
        }
    ?>
            
        </div>
      </div>

  <?php endif; // end of view mode full condition ?>
  </div>
<?php endif; ?>


