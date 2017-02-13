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
  <table class="views-table ">
      <tr>
          <th>  Highlights Text :    </th>
          <td> <?php echo $field_highlights_text ?></td>
      </tr>
      <tr>
          <th>  URL :   </th>
          <td><?php echo $field_highlights_url; ?></td>
      </tr>
      
      <?php if ($field_emoji_condition == 0) : ?>
        <tr>
            <th> Display Condition :   </th>
            <td> <?php echo t("Thumb") ?></td>
        </tr>
      <?php endif; ?>
        
      <?php if ($field_emoji_condition == "none") : ?>
        <tr>
            <th> Display Condition :   </th>
            <td> <?php echo t("None") ?></td>
        </tr>
      <?php endif; ?>
        
        
      <!-- Show only Emoji In case of 1 -->
      <?php if ($field_emoji_condition == 1) : ?>
        <tr>
            <th> Display Condition :   </th>
            <td> <?php echo t("Emoji"); ?></td>
        </tr>
        <?php if ($field_field_emoji_highlights_1 > 0) : ?>
          <tr>
              <th> field_emoji_title_1 :   </th>
              <td><?php echo $field_field_emoji1_title; ?></td>
          </tr>
          <tr>
              <th> field_emoji_highlights_1 :   </th>
              <td> <?php echo $field_field_emoji_highlights_1; ?></td>
          </tr>
        <?php endif; ?>

        <?php if ($field_field_emoji_highlights_2 > 0) : ?>

          <tr>
              <th> field_emoji_title_2 :   </th>
              <td><?php echo $field_field_emoji2_title; ?></td>
          </tr>
          <tr>
              <th> field_emoji_highlights_2 :   </th>
              <td> <?php echo $field_field_emoji_highlights_2; ?></td>
          </tr>
        <?php endif; ?>

        <?php if ($field_field_emoji_highlights_3 > 0) : ?>

          <tr>
              <th> field_emoji_title_3 :   </th>
              <td><?php echo $field_field_emoji3_title; ?></td>
          </tr>
          <tr>
              <th> field_emoji_highlights_3 :   </th>
              <td> <?php echo $field_field_emoji_highlights_3; ?></td>
          </tr>
        <?php endif; ?>
      <?php endif; ?>
  </table>
<?php } ?>
