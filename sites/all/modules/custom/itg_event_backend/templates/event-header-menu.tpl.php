<?php
/**
 * @file
 * Event Header menu
 * 
 */
global $base_url;
$arg = arg();
if($arg[0] == 'event') {  
  $baseurl = $base_url.'/'.$arg[1].'/'.$arg[2];
} elseif(!empty($arg[1]) && is_numeric($arg[1]) && $arg[0] == 'node') {
  $baseurl = $base_url.'/'.drupal_get_path_alias('node/'.  $arg[1]);
} 
$node = itg_event_backend_get_event_node('node');
if (!empty($node) && ($node->type == 'event_backend')) {
  $event_start_date = date('F d, Y', strtotime($node->field_event_start_date[LANGUAGE_NONE][0]['value']));
  $registration_close = strtotime($node->field_registration_close_date[LANGUAGE_NONE][0]['value']);
  $event_close = strtotime($node->field_event_close_date[LANGUAGE_NONE][0]['value']);
  $force_registration_flag = $node->field_force_registration_open[LANGUAGE_NONE][0]['value'];
  $event_location = $node->field_story_kicker_text[LANGUAGE_NONE][0]['value'];
  $event_config_home = $node->field_config_home[LANGUAGE_NONE][0]['value'];
  $event_config_programme = $node->field_config_programme[LANGUAGE_NONE][0]['value'];
  $event_config_speakers = $node->field_config_speakers[LANGUAGE_NONE][0]['value'];
  $event_config_sponsors = $node->field_config_sponsors[LANGUAGE_NONE][0]['value'];
  $event_config_flashback = $node->field_config_flashback[LANGUAGE_NONE][0]['value'];
  $event_type = $node->field_event_types[LANGUAGE_NONE][0]['tid'];
  
  $menu_font_color = $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] ? $node->field_e_menu_font_color[LANGUAGE_NONE][0]['rgb'] : '#f7ee23';
  $menu_highlights_color = $node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] ? $node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] : '#f7ee24';
  $home_menu = (arg(0) == 'node' && is_numeric(arg(1))) ? $menu_highlights_color : $menu_font_color;
  $program_menu = (arg(0) == 'event' && (arg(3) == 'programme')) ? $menu_highlights_color : $menu_font_color;
  $speakers_menu = (arg(0) == 'event' && ((arg(3) == 'speakers') || arg(3) == 'speaker-details')) ? $menu_highlights_color : $menu_font_color;
  $registration_menu = (arg(0) == 'event' && (arg(3) == 'registration')) ? $menu_highlights_color : $menu_font_color;
  $sponsors_menu = (arg(0) == 'event' && ((arg(3) == 'sponsors') || arg(3) == 'sponsor-details')) ? $menu_highlights_color : $menu_font_color;
?>

<div id="block-menu-menu-event-menu" class="container event-header-menu-container">
  <div class="row">
    <div class="col-md-8 col-sm-8" style="color:<?php print $menu_font_color; ?>">
        <div class="wrap-mobile-social">
            <a class="mobile-nav" href="javascript:void(0)"><i class="fa fa-bars"></i></a>
            <div class="social-share">
                <a href="#"><i class="fa fa-facebook" aria-hidden="true"></i></a>
                <a href="#"><i class="fa fa-twitter" aria-hidden="true"></i></a>
                <div class="search-icon-parent">
                  <a href="javascript:void(0)" class="search-icon-default" title=""><i class="fa fa-search"></i></a>
                  <a href="javascript:void(0)" class="search-icon-search" title=""><i class="fa fa-search"></i></a>
                  <div class="globle-search">
                    <input class="search-text" placeholder="Type here" type="text" value="">
                  </div>
                </div>
            </div>                           
        </div>
      <ul class="menu">
          <?php 
            if ($event_config_home) {
              print '<li>'.l('Home', $baseurl,  array('attributes' => array("style" => "color:$home_menu"))).'</li>';
            }

            if ($event_config_programme) {
              print '<li>'.l('Programme', $baseurl.'/programme', array('attributes' => array("style" => "color:$program_menu"))).'</li>';
            }

            if ($event_config_speakers) {
              print '<li>'.l('Speakers', $baseurl.'/speakers', array('attributes' => array("style" => "color:$speakers_menu"))).'</li>';
            }
            //if(($registration_close >= time() && !empty($registration_close)) || ($force_registration_flag == 1) || (empty($registration_close) && $event_close >= time())) {
              print '<li>'.l('Registration', $baseurl.'/registration', array('attributes' => array("style" => "color:$registration_menu"))).'</li>';
            //}
            if ($event_config_sponsors) {
              print '<li>'.l('Sponsors', $baseurl.'/sponsors', array('attributes' => array("style" => "color:$sponsors_menu"))).'</li>';
            }

            if ($event_config_flashback) {
              $flash_old = itg_event_backend_flashback($node->nid, $menu_font_color, $event_type);
              $flash_old_event = '';
              if(!empty($flash_old)){
                $flash_old_event = $flash_old['menu'];
              }
              print '<li>'.l('Flashback', 'node/'.$flash_old['top'], array('attributes' => array("style" => "color:$menu_font_color"))).$flash_old_event.'</li>';
            }            

          ?>
      </ul>
    </div>
    <div class="col-md-4 col-sm-4">
      <div class="event-detail">
        <span class="event-str-date"><?php print $event_start_date; ?> </span>
        <span class="event-vanue-detail-place" ><?php print $event_location; ?></span>                
      </div>            
    </div>        
  </div>
</div>
<?php } ?>
