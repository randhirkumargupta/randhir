<?php
/**
 * @file
 * Event Header menu
 * 
 */
global $base_url;
$node = itg_event_backend_get_event_node('node');
$event_start_date = date('F d, Y', strtotime($node->field_event_start_date[LANGUAGE_NONE][0]['value']));
$event_location = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
$event_config_home = $node->field_config_home[LANGUAGE_NONE][0]['value'];
$event_config_programme = $node->field_config_programme[LANGUAGE_NONE][0]['value'];
$event_config_speakers = $node->field_config_speakers[LANGUAGE_NONE][0]['value'];
$event_config_sponsors = $node->field_config_sponsors[LANGUAGE_NONE][0]['value'];
$event_config_flashback = $node->field_config_flashback[LANGUAGE_NONE][0]['value'];
$event_config_photo = $node->field_config_photo[LANGUAGE_NONE][0]['value'];
$event_config_video = $node->field_config_video[LANGUAGE_NONE][0]['value'];

?>
<div class="event-header-menu-container">
  <?php 
  if ($event_config_home) {
    print '<span class="event-menu-home">'.l('Home', $base_url).'</span>';
  }
  if ($event_config_programme) {
    print '<span class="event-menu-programme">'.l('Programme', 'programme').'</span>';
  }
  if ($event_config_speakers) {
    print '<span class="event-menu-speakers">'.l('Speakers', 'speakers').'</span>';
  }
  print '<span class="event-menu-registration">'.l('Registration', 'event-registration').'</span>';
  if ($event_config_sponsors) {
    print '<span class="event-menu-sponsors">'.l('Sponsors', 'sponsors').'</span>';
  }
  if ($event_config_flashback) {
    print '<span class="event-menu-fashback">'.l('Fashback', 'flashback').'</span>';
  }
  if ($event_config_flashback) {
    print '<span class="event-menu-fashback">'.l('Fashback', 'flashback').'</span>';
  }
  if ($event_config_flashback) {
    print '<span class="event-menu-fashback">'.l('Fashback', 'flashback').'</span>';
  }
  ?>
<span class="event-menu-home"><?php print l('Sing and Win', 'sing-and-win'); ?></span>
  <span class="event-menu-vanue-detail">
    <span class="event-vanue-detail-date"><?php print $event_start_date; ?></span>
    <span class="event-vanue-detail-place"><?php print $event_location; ?></span>
  </span>
</div>
