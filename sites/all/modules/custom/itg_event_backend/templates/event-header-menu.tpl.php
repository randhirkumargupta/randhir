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
$menu_font_color = $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] ? $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] : '#f7ee23';
?>
<div id="block-menu-menu-event-menu" class="container event-header-menu-container">
  <div class="row">
    <div class="col-md-8" style="color:<?php print $menu_font_color; ?>">
      <ul class="menu">
          <?php 
            if ($event_config_home) {
              print '<li>'.l('Home', $base_url,  array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_programme) {
              print '<li>'.l('Programme', 'programme', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_speakers) {
              print '<li>'.l('Speakers', 'speakers', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            print '<li>'.l('Registration', 'event-registration', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';

            if ($event_config_sponsors) {
              print '<li>'.l('Sponsors', 'sponsors', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_photo) {
              print '<li>'.l('Photo', '#', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_video) {
              print '<li>'.l('Video', '#', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_flashback) {
              print '<li>'.l('Fashback', 'flashback', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

          ?>
        <li><?php print l('Sing and Win', 'sing-and-win', array('attributes' => array("style" => "color:$menu_font_color"))); ?></li>
      </ul>
    </div>
    <div class="col-md-4">
      <div class="event-detail" style="text-align: center; color:#FFF">
        <span class="event-str-date"><?php print $event_start_date; ?> </span>
        <span class="event-vanue-detail-place" ><?php print $event_location; ?></span>                
      </div>            
    </div>        
  </div>
</div>
