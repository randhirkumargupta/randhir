<?php

/**
 * @file
 * Theme implementation for poll form in tab display.
 * 
 */
ksort($data);
foreach ($data as $key => $value) {
  $output .= '<div class="' . $key . '">' . $key . '</div>';
}
foreach ($data as $key => $value) {
  $output .= '<div class="' . $key . '">';
  foreach ($value as $program) {

    //$output .= '<div class="daywise">' . $program["daywise"] . '</div>';
    $output .= '<div class="title">' . $program["session_title"] . '</div>';
    $output .= '<div class="time">' . $program["start_time"] . 'to' . $program["end_time"] . '</div>';
    foreach ($program['speaker'] as $speaker) {
      $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
      $output .= '<label>Speaker:</label>';
      $output .= '<div class="speaker-title">' . $spk_detail[0]->title . '</div>';
      $output .= '<div class="speaker-image"><img src=' . image_style_url("thumbnail", $spk_detail[0]->uri) . '/></div>';
    }
  }
  $output .= '</div>';
}
print $output;
?>