<?php
/**
 * @file
 * Theme implementation for poll form in tab display. 
 */
global $base_url;
$arg = arg();

if (!empty($arg[1]) && is_numeric($arg[1]) && $arg[0] == 'node') {
  $host_node = node_load($arg[1]);
}

/*$host_detail = itg_event_backend_get_redirect_record('redirect', $base_url); me
if (empty($host_detail) && !empty($arg1) && is_numeric($arg1)) {
  $host_node = node_load($arg1);
} else {
    if (!empty($host_detail['source'])) {
      $host_node_arr = explode('/', $host_detail['source']);
    }
    if (!empty($host_node_arr[1])) {
      $host_node = node_load($host_node_arr[1]);
    }
}*/

$current_date = strtotime(date('Y-m-d  H:i:s'));
if (!empty($host_node) && ($host_node->type == 'event_backend')) {
  $event_start_date = strtotime($host_node->field_event_start_date[LANGUAGE_NONE][0]['value']);
  $event_close_date = strtotime($host_node->field_event_close_date[LANGUAGE_NONE][0]['value']);

  // Css variables
  $heading_background_color = $host_node->	field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->	field_e_heading_bck_color[LANGUAGE_NONE][0]['rgb'] : '#eee';
  $font_color = $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_highlighted_font_color[LANGUAGE_NONE][0]['rgb'] : '#ef2a24';
  $content_font_color = $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_content_font_color[LANGUAGE_NONE][0]['rgb'] : '#000';
  $program_title_font_color = $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_program_title_color[LANGUAGE_NONE][0]['rgb'] : '#000';
  $tab_highlighted_color = $host_node->field_e_tab_color[LANGUAGE_NONE][0]['rgb'] ? $host_node->field_e_tab_color[LANGUAGE_NONE][0]['rgb'] : '#eee';

$actual_host_name = itg_event_get_host_name();
if($actual_host_name) {
  $baseurl = $actual_host_name.'/';
}
/*else { me
  $baseurl = $base_url.'/';
}*/


if($current_date < $event_close_date) {
if (!empty($data)) {
ksort($data);
$tabs = '';
foreach ($data as $key => $value) {
  $tabs .= '<li style="background: '.$tab_highlighted_color.'" data-tag="Day-' . $key . '" class="event-program-tabs Day-' . $key . '">Day ' . $key . '</li>';
}
// if for live event
$output = '';
if ($current_date > $event_start_date && $current_date < $event_close_date) {
  $output .= itg_event_backend_get_highlights_block();
}
elseif ($current_date < $event_start_date && $current_date < $event_close_date) {
  $output = '<h2 class="block-title">'.$host_node->title.'</h2>';
  $output .= '<div style="margin-bottom: 20px;">'.$host_node->body[LANGUAGE_NONE][0]['value'].'</div>';
}
//$banner_img = drupal_get_path('module', 'itg_event_backend').'/event_home_banner.jpeg';
print $output;
?>
<h2 class="block-title"><?php print t('Session wise coverage'); ?></h2>
<div class="program-sub-title" style="color: <?php echo $program_title_font_color; ?>; background: <?php print $heading_background_color;?>">Program Schedule</div>
<?php
print '<div class="top-tab"><ul>' . $tabs . '</ul></div>';
foreach ($data as $key => $value) {
  ?>
  <div class="<?php print 'Day-'.$key; ?> event-listing common-class">
    <?php
    $session_result = '';
    foreach ($value as $program) {
      $media = $program["daywise"] . '--' . $program["session_title"] . '--' . $program["start_time"] . '--' . $program["end_time"];
      $session_result = itg_event_backend_get_session_photo_video($media);
      $sponsors_data = itg_event_backend_get_session_sponsor($media);
     
     $sponsor_all_data = "";
     $sponsor_tags = "";
      if(!empty($sponsors_data)) {
         $sponsor_all_data = node_load($sponsors_data['sponsor']);
     }
    
     if($sponsor_all_data->field_sponser_logo[LANGUAGE_NONE][0]['uri'] != "") {
         $sponsors_data_parent = "sponsors-parent";
         $sponsor_tags = '<div class="spncor-tag"><span>Powered By</span><img src=' . image_style_url("sponsor85___33", $sponsor_all_data->field_sponser_logo[LANGUAGE_NONE][0]['uri']) . ' alt="" /></div>';
     }
      $story_title = itg_event_backend_get_session_story_title($media, $content_font_color);
      $output_story_title = '';
      foreach ($story_title['story_title'] as $title) {
        if (!empty($title)) {
          $output_story_title = '<p><i class="fa fa-story-title"></i>'.$title.'</p>';
        }
      }
      
      $output_media = '';
      $max = max(array(count($session_result['photo']), count($session_result['video']), count($session_result['audio'])));
      for($i = 0; $i < $max; $i++) {
        if (!empty($session_result['photo'][$i])) {
          $output_media .= l('<i class="fa fa-camera"></i> ' . t('Session Photo'), $base_url.'/'.drupal_get_path_alias('node/'. $session_result['photo'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
        }
        if (!empty($session_result['video'][$i])) {
          $output_media .= l('<i class="fa fa-video-camera"></i> ' . t('Session Video'), $base_url.'/'.drupal_get_path_alias('node/'. $session_result['video'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
        }
        if (!empty($session_result['audio'][$i])) {
          $output_media .= l('<i class="fa fa-headphones"></i> ' . t('Session Audio'), $base_url.'/'.drupal_get_path_alias('node/'. $session_result['audio'][$i]), array("attributes" => array("target" => "_blank", "style" => "color: $font_color"), 'html' => TRUE));
        }
        $output_media .= '<br>';
      }
      ?>
      <div class="side-right"><div class="title <?php echo $sponsors_data_parent; ?>" style="background: <?php print $heading_background_color; ?>"><?php print $program["session_title"]; ?><?php echo $sponsor_tags;?></div> 
        <div class="listing-detail"><div class="section-part"><?php print $output_story_title. ' ' . $output_media; ?></div>
          <div class="profile-detail">
            <?php
            foreach ($program['speaker'] as $speaker) {
              $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
              if(!empty($spk_detail)){
              print '<div class="profile-loop"><label style="color:'.$font_color.'">Speaker:</label>';
              //$spk_title = '<div class="speaker-title"><a href="'.$baseurl.'node/'.$spk_detail[0]->nid.'" target="_blank" style="color:'.$content_font_color.'">'.$spk_detail[0]->title.'</a></div>';
              $spk_title = '<div class="speaker-title">'.l(t($spk_detail[0]->title), $baseurl.'speaker-details', array('attributes' => array('style' => 'color:'.$content_font_color),'query' => array('speaker' => $spk_detail[0]->nid))).'</div>';
              if(!empty($spk_detail[0]->uri)){
                $img = '<img src=' . image_style_url("event_speaker_program_72x72", $spk_detail[0]->uri) . ' alt="" />';
              }else{
                $img = "<img width='72' height='72'  src='" . $base_url . '/' . drupal_get_path('theme', 'itg') . "/images/program-speaker.jpg' alt='' />";
              }
              //print '<div class="speaker-image"><a href="'.$baseurl.'node/'.$spk_detail[0]->nid.'" target="_blank">'.$img.'</a></div>';
              print '<div class="speaker-image">'. l($img, $baseurl.'speaker-details', array('query' => array('speaker' => $spk_detail[0]->nid), 'html' => TRUE)).'</div>';
              print '<div class="speaker-designation" style="color:'.$content_font_color.'">' . t($spk_title . $spk_detail[0]->field_story_new_title_value) . '</div></div>';
              }
            }
            ?>
          </div>
        </div>
      </div> 
      <div class="side-left"><div class="time" style="color:<?php print $font_color; ?>"><?php print $program["start_time"] . ' to ' . $program["end_time"]; ?> </div></div>
      <?php
    }
    print '</div>';
  }
}
} else {
  $block = block_load('itg_event_backend', 'post_event_block');
  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
  $output = render($render_array);
  print $output;
}
}
?>