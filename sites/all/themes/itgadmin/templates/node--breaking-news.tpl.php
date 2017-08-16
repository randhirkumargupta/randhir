<?php if (!empty($content)): ?>
  <div class='<?php print $classes ?>'>
    <?php if ($view_mode == 'full'): ?>
      <a href="javascript:;" class="close-preview">&nbsp;</a>
      <div class="content-node-view">
        <h2><?php print t('Basic Details'); ?></h2>
        <div class="content-details">
          <?php print render($content['field_type']); ?>
          <?php
          if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Live Blog') {
          if($node->field_story_expires[LANGUAGE_NONE][0]['value'] == 'Yes') {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Live TV:'); ?></div>
            <div class="field-items"><?php print 'Yes'; ?></div>
          </div>
          <?php  
          }
          else {
          ?>
            <div class="field">
            <div class="field-label"><?php print t('Live TV:'); ?></div>
            <div class="field-items"><?php print 'No'; ?></div>
          </div>
          <?php  
          }
          }
          ?>
            
          <div class="field">
            <div class="field-label"><?php print t('Breaking Text:'); ?></div>
            <div class="field-items"><h1><?php print $title; ?></h1></div>
          </div>

          <?php $short_des = render($content['field_common_short_description']);
          ?>
          <?php if (!empty($short_des)): ?>
            <?php
            if (!empty($short_des)):
              print render($content['field_common_short_description']);
              ?>
            <?php endif; ?>

          <?php endif; ?>
          <div class="field">
            <?php
            $type = $node->field_type[LANGUAGE_NONE][0]['value'];
            if ($type == 'Live Blog'):

              print '<div class="field-label">'.t('Section').'</div>';
              print '<div class="field-items">';
              foreach ($node->field_story_category[LANGUAGE_NONE] as $value) {
                print '<div>' . t($value[taxonomy_term]->name) . '</div>';
              }
              print '</div>';
            endif;
            ?>
           
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
      
       <?php
            $highlight = render($content['field_story_highlights']);
            if (!empty($highlight)):
              ?>
              <div class="expert-details content-box">
                  <h2><?php print t('Highlights'); ?></h2>
                  <div class="content-details">
                      <?php
                      $h_count = 1;
                      foreach ($node->field_story_highlights['und'] as $high) {
                        print '<div class="field"><div class="field-label">'.$h_count.':</div><div class="field-items">'.t($high['value']).'</div></div>';
                        $h_count++;
                      }
                      ?>
                  </div>  
              </div>
            <?php endif; ?>

      <div class="content-node-view">
       
        <div class="content-details">
    <?php
    if (isset($node->op) && $node->op == 'Preview') {
    $num = 0;
        foreach ($node->field_breaking_content_details[LANGUAGE_NONE] as $news_arr) {
          $sn = $num + 1;
          echo '<h2>'.t('Content').' ' . $sn . ' '.t('Details').':</h2>';
         ?>
          <div class="field">
            <div class="field-label"><?php print t('Title');  ?>:</div>
            <div class="field-items"><?php echo $news_arr['field_breaking_tile'][LANGUAGE_NONE][0]['value']; ?></div>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <?php if(!empty($news_arr['field_mark_as_breaking_band'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label"><?php print t('Mark as Breaking band :') ?> </div>
            <div class="field-items"><?php echo t('Yes'); ?></div>
            <?php } ?>
            <?php } ?>
            <?php if(!empty($news_arr['field_notification_'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label"><?php print t('Notification :');  ?> </div>
            <div class="field-items"><?php echo t('Yes'); ?></div>
            <?php } ?>
            <?php if(!empty($news_arr['field_mobile_subscribers'][LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label"><?php print t('Mobile subscribers :'); ?></div>
            <div class="field-items"><?php
                      foreach ($news_arr['field_mobile_subscribers'][LANGUAGE_NONE] as $subs) {
                        print $subs['value'].'<br/>';
            } 
                      ?></div>
            <?php } ?>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <div class ="field-label"><?php print t('Publish Time : '); ?></div>
            <div class="field-items"><?php 
            echo date("H:i", strtotime($news_arr['field_breaking_publish_time'][LANGUAGE_NONE][0]['value']) + 19800 );
            ?></div>
            <?php } ?>
            <?php if($news_arr['field_breaking_redirection_url'][LANGUAGE_NONE][0]['value'] != '') { ?>
            <div class ="field-label"><?php print t('Redirection url :');  ?> </div>
            <div class="field-items"><?php echo $news_arr['field_breaking_redirection_url'][LANGUAGE_NONE][0]['value']; ?></div>
          <?php } ?>  
          </div>
            
    <?php
    $num++;
        }
    }
    else
    {
       $num = 0;
        foreach ($node->field_breaking_content_details[LANGUAGE_NONE] as $news_arr) {
          $ans_detail = entity_load('field_collection_item', array($news_arr['value']));
          $sn = $num + 1;
          echo '<h2>'.t('Content').' ' . $sn . ' '.t('Details').':</h2>';
         
      ?>
          <div class="field">
            <div class="field-label">Title:</div>
            <div class="field-items"><?php echo $ans_detail[$news_arr['value']]->field_breaking_tile[LANGUAGE_NONE][0]['value']; ?></div>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <?php if(!empty($ans_detail[$news_arr['value']]->field_mark_as_breaking_band[LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label">Mark as Breaking band : </div>
            <div class="field-items"><?php echo t('Yes'); ?></div>
            <?php } ?>
            <?php } ?>
            <?php if(!empty($ans_detail[$news_arr['value']]->field_notification_[LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label"><?php print t('Notification :');  ?> </div>
            <div class="field-items"><?php echo t('Yes'); ?></div>
            <?php } ?>
            <?php if(!empty($ans_detail[$news_arr['value']]->field_mobile_subscribers[LANGUAGE_NONE][0]['value'])) { ?>
            <div class ="field-label"><?php print t('Mobile subscribers :'); ?> </div>
            <div class="field-items"><?php
                      foreach ($ans_detail[$news_arr['value']]->field_mobile_subscribers[LANGUAGE_NONE] as $subs) {
                        print $subs['value'].'<br/>';
            } 
                      ?></div>
            <?php } ?>
            <?php if($node->field_type[LANGUAGE_NONE][0]['value'] == 'Breaking News') { ?>
            <div class ="field-label"><?php print t('Publish Time :'); ?> </div>
            <div class="field-items"><?php 
            echo date("H:i", strtotime($ans_detail[$news_arr['value']]->field_breaking_publish_time[LANGUAGE_NONE][0]['value']) + 19800 );
            ?></div>
            <?php } ?>
            <?php if($ans_detail[$news_arr['value']]->field_breaking_redirection_url[LANGUAGE_NONE][0]['value'] != '') { ?>
            <div class ="field-label"><?php print t('Redirection url :'); ?> </div>
            <div class="field-items"><?php echo $ans_detail[$news_arr['value']]->field_breaking_redirection_url[LANGUAGE_NONE][0]['value']; ?></div>
          <?php } ?>  
          </div>  
            
            <?php
            $num++;
        }
    }
    ?>
            
        </div>
      </div>

  <?php endif; // end of view mode full condition ?>
  </div>
<?php endif; ?>


