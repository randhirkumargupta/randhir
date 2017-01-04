<?php
/**
 * @file
 * Event Header menu
 * 
 */
global $base_url;
$arg = arg();
if($arg[0] == 'event') {
  $baseurl = $base_url.'/'.$arg[0].'/'.$arg[1];
} elseif(!empty($arg[1]) && is_numeric($arg[1])) {//shravan
  $baseurl = $base_url.'/'.drupal_get_path_alias('node/'.  $arg[1]);
} else {
  $baseurl = $base_url;
}

$node = itg_event_backend_get_event_node('node');
if (!empty($node) && ($node->type == 'event_backend')) {//shravan
  $event_start_date = date('F d, Y', strtotime($node->field_event_start_date[LANGUAGE_NONE][0]['value']));
  $event_location = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
  $event_config_home = $node->field_config_home[LANGUAGE_NONE][0]['value'];
  $event_config_programme = $node->field_config_programme[LANGUAGE_NONE][0]['value'];
  $event_config_speakers = $node->field_config_speakers[LANGUAGE_NONE][0]['value'];
  $event_config_sponsors = $node->field_config_sponsors[LANGUAGE_NONE][0]['value'];
  $event_config_flashback = $node->field_config_flashback[LANGUAGE_NONE][0]['value'];
  //$event_config_photo = $node->field_config_photo[LANGUAGE_NONE][0]['value'];
  //$event_config_video = $node->field_config_video[LANGUAGE_NONE][0]['value'];
  $menu_font_color = $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] ? $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] : '#f7ee23';

?>

<div id="block-menu-menu-event-menu" class="container event-header-menu-container">
  <div class="row">
    <div class="col-md-8" style="color:<?php print $menu_font_color; ?>">
      <ul class="menu">
          <?php 
            if ($event_config_home) {
              print '<li>'.l('Home', $baseurl,  array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_programme) {
              print '<li>'.l('Programme', $baseurl.'/programme', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_speakers) {
              print '<li>'.l('Speakers', $baseurl.'/speakers', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            print '<li>'.l('Registration', $baseurl.'/registration', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';

            if ($event_config_sponsors) {
              print '<li>'.l('Sponsors', $baseurl.'/sponsors', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }

            if ($event_config_flashback) {
              $flash_old = itg_event_backend_flashback($node->nid);
              $flash_old_event = '';
              if(!empty($flash_old)){
                $flash_old_event = $flash_old;
              }
              print '<li>'.l('Flashback', 'node/'.$node->nid, array('attributes' => array("style" => "color:$menu_font_color"))).$flash_old_event.'</li>';
            }
            
            if ($node->nid) {
              print '<li>'.l('Sing and Win', $baseurl.'/sing-and-win', array('attributes' => array("style" => "color:$menu_font_color"))).'</li>';
            }
          ?>
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
<?php } ?>
