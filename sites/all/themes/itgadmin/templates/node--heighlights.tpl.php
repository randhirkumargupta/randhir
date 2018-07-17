<div class="node node-heighlights-div">
<?php foreach ($node->field_highlights['und'] as $keys => $value) { ?>
  <?php
  $highlight_items = entity_load('field_collection_item', array($value['value']));
  $field_highlights_text = $highlight_items[$value['value']]->field_highlights_text[LANGUAGE_NONE][0]['value'];
  $field_highlights_url = $highlight_items[$value['value']]->field_highlights_url[LANGUAGE_NONE][0]['value'];
  $field_field_emoji1_title = $highlight_items[$value['value']]->field_field_emoji1_title[LANGUAGE_NONE][0]['value'];
  $field_field_emoji2_title = $highlight_items[$value['value']]->field_field_emoji2_title[LANGUAGE_NONE][0]['value'];
  $field_field_emoji3_title = $highlight_items[$value['value']]->field_field_emoji3_title[LANGUAGE_NONE][0]['value'];
  $field_field_emoji_highlights_1 = $highlight_items[$value['value']]->field_field_emoji_highlights_1[LANGUAGE_NONE][0]['value'];
  $field_field_emoji_highlights_2 = $highlight_items[$value['value']]->field_field_emoji_highlights_2[LANGUAGE_NONE][0]['value'];
  $field_field_emoji_highlights_3 = $highlight_items[$value['value']]->field_field_emoji_highlights_3[LANGUAGE_NONE][0]['value'];
  $field_emoji_condition = $highlight_items[$value['value']]->field_emoji_condition[LANGUAGE_NONE][0]['value'];
  ?>
  <div class="field-group">
      <div class="field">
          <div class="field-label">  <?php print t('Highlights Text : ');  ?>   </div>
          <div class="field-items"> <?php echo $field_highlights_text ?></div>
      </div>
      <div class="field">
          <div class="field-label">  <?php print t('URL : ');  ?>    </div>
          <div class="field-items"> <?php echo $field_highlights_url; ?> </div>
      </div>
      
      <?php if ($field_emoji_condition == 0) : ?>
        <div class="field">
            <div class="field-label"> <?php print t('Display Condition :');  ?> </div>
            <div class="field-items"> <?php echo t("Thumb") ?></div>
        </div>
      <?php endif; ?>
        
      <?php if ($field_emoji_condition == "none") : ?>
        <div class="field">
            <div class="field-label"> <?php print t('Display Condition :');  ?>   </div>
            <div class="field-items"> <?php echo t("None") ?></div>
        </div>
      <?php endif; ?>
        
        
      <!-- Show only Emoji In case of 1 -->
      <?php if ($field_emoji_condition == 1) : ?>
        <div class="field">
            <div class="field-label"> Display Condition :   </div>
            <div class="field-items"> <?php echo t("Emoji"); ?></div>
        </div>
        <?php if ($field_field_emoji_highlights_1 > 0) : ?>
          <div class="field">
              <div class="field-label"> field_emoji_title_1 :   </div>
              <div class="field-items"><?php echo $field_field_emoji1_title; ?></div>
          </div>
          <div class="field">
              <div class="field-label"> field_emoji_highlights_1 :   </div>
              <div class="field-items"> <?php echo ($field_field_emoji_highlights_1) ?   t("Yes") : t("No") ; ?></div>
          </div>
        <?php endif; ?>

        <?php if ($field_field_emoji_highlights_2 > 0) : ?>

          <div class="field">
              <div class="field-label"> field_emoji_title_2 :   </div>
              <div class="field-items"><?php echo $field_field_emoji2_title; ?></div>
          </div>
          <div class="field">
              <div class="field-label"> field_emoji_highlights_2 :   </div>
              <div class="field-items"> <?php echo ($field_field_emoji_highlights_2) ?   t("Yes") : t("No") ; ?></div>
          </div>
        <?php endif; ?>

        <?php if ($field_field_emoji_highlights_3 > 0) : ?>

          <div class="field">
              <div class="field-label"> <?php print t('field_emoji_title_3 :');  ?>   </div>
              <div class="field-items"><?php echo $field_field_emoji3_title; ?></div>
          </div>
          <div class="field">
              <div class="field-label"> <?php print t('field_emoji_highlights_3 :');  ?>   </div>
              <div class="field-items"> <?php echo ($field_field_emoji_highlights_3) ?   "Yes" : "No" ; ?></div>
          </div>
        <?php endif; ?>
      <?php endif; ?>
  </div>
<?php } ?>
</div>
