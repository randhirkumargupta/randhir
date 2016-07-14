<div class="rundown-slug-details">
  <div class="field">
    <div class="field-label"><?php print t('Story Title'); ?>:</div>
    <div class="field-items"><?php print $result['story_title']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Story Duration'); ?>:</div>
    <div class="field-items"><?php print $result['story_duration']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Story Created'); ?>:</div>
    <div class="field-items"><?php print format_date($result['story_created'], $type = 'itg_date_with_time', $format = '', $timezone = NULL, $langcode = NULL); ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Story Created By'); ?>:</div>
    <div class="field-items"><?php print $result['story_created_by']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Story Modified'); ?>:</div>
    <div class="field-items"><?php print format_date($result['story_modified'], $type = 'itg_date_with_time', $format = '', $timezone = NULL, $langcode = NULL); ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Story Modified By'); ?>:</div>
    <div class="field-items"><?php print $result['story_modified_by']; ?></div>
  </div>
  <?php foreach ($result['story_custom_data'] as $label => $story_custom_data): ?>
    <?php if ($story_custom_data != ''): ?>
      <div class="field">
        <div class="field-label"><?php print t($label); ?>:</div>
        <div class="field-items"><?php print $story_custom_data; ?></div>
      </div>
    <?php endif; ?>
  <?php endforeach; ?>

  <div class="field">
    <div class="field-label"><?php print t('Element Type'); ?>:</div>
    <div class="field-items"><?php print $result['element_type']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Element Duration'); ?>:</div>
    <div class="field-items"><?php print $result['element_dur']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Clip Name'); ?>:</div>
    <div class="field-items"><?php print $result['clipname']; ?></div>
  </div>
  <div class="field">
    <div class="field-label"><?php print t('Text'); ?>:</div>
    <div class="field-items"><?php print html_entity_decode($result['text']); ?></div>
  </div>
</div>
