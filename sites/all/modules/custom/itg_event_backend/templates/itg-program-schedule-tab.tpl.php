<?php

/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
ksort($data);
$output = '<div class="program-sub-title">Program Schedule</div>';
foreach ($data as $key => $value) {
  $output .= '<div class="' . $key . '">' . $key . '</div>';
}
foreach ($data as $key => $value) {
  $output .= '<div class="' . $key . '">';
  $session_result = '';
  foreach ($value as $program) {
    $media = $program["daywise"].'--'.$program["session_title"].'--'.$program["start_time"].'--'.$program["end_time"];
    $session_result = itg_event_backend_get_session_photo_video($media);
    foreach($session_result['photo'] as $session){
      if(!empty($session)){
        $output_photo .= l(t('Session Photo'), 'node/'.$session, array("attributes" => array("target" => "_blank")));
      }
    }
    foreach($session_result['video'] as $session){
      if(!empty($session)){
        $output_video .= l(t('Session Video'), 'node/'.$session, array("attributes" => array("target" => "_blank")));
      }
    }
    foreach($session_result['audio'] as $session){
      if(!empty($session)){
        $output_audio .= l(t('Session Audio'), 'node/'.$session, array("attributes" => array("target" => "_blank")));
      }
    }
   // $output .= '<div class="daywise">' . $program["daywise"] . '</div>';
    $output .= $output_photo .' - '.$output_video.' - '.$output_audio;
    $output .= '<div class="title">' . $program["session_title"] . '</div>';
    $output .= '<div class="time">' . $program["start_time"] . 'to' . $program["end_time"] . '</div>';
    foreach ($program['speaker'] as $speaker) {
      $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
      $output .= '<label>Speaker:</label>';
      $output .= '<div class="speaker-title">' . l(t($spk_detail[0]->title), "node/".$spk_detail[0]->nid, array("attributes" => array("target" => "_blank"))) . '</div>';
      $img = '<img src=' . image_style_url("thumbnail", $spk_detail[0]->uri).'/>';
      $output .= '<div class="speaker-image">'.l($img ,"node/".$spk_detail[0]->nid, array("attributes" => array("target" => "_blank"), "html" => TRUE)).'</div>';
      $output .= '<div class="speaker-designation">'.$spk_detail[0]->field_story_new_title_value.'</div>';
    }
  }
  $output .= '</div>';
}
print $output;
?>