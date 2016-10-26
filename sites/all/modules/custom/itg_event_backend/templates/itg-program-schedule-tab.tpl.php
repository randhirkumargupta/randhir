<?php
/**
 * @file
 * Theme implementation for poll form in tab display. 
 */
global $base_url;
$actual_host_name = itg_event_get_host_name();
if($actual_host_name) {
  $baseurl = $actual_host_name.'/';
}
else {
  $baseurl = $base_url.'/';
}

ksort($data);
foreach ($data as $key => $value) {
  $tabs .= '<li data-tag="Day-' . $key . '" class="Day-' . $key . '">Day ' . $key . '</li>';
}

$banner_img = drupal_get_path('module', 'itg_event_backend').'/event_home_banner.jpeg';
?>
<div style="margin-bottom: 20px;"><img src="<?php echo $base_url.'/'.$banner_img; ?>" width="100%"/></div>
<h2 class="block-title">Session wise coverage</h2>
<div class="program-sub-title">Program Schedule</div>
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
      $story_title = itg_event_backend_get_session_story_title($media);
      $output_story_title = '';
      foreach ($story_title['story_title'] as $title) {
        if (!empty($title)) {
          $output_story_title = '<p style="margin-bottom:10px"><i class="fa fa-story-title"></i>'.$title.'</p>';
        }
      }
      
      $output_photo = '';
      foreach ($session_result['photo'] as $session) {
        if (!empty($session)) {
          $output_photo = l('<i class="fa fa-camera"></i> ' . t('Session Photo'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      $output_video = '';
      foreach ($session_result['video'] as $session) {
        if (!empty($session)) {
          $output_video = l('<i class="fa fa-video-camera"></i> ' . t('Session Video'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      $output_audio = '';
      foreach ($session_result['audio'] as $session) {
        if (!empty($session)) {
          $output_audio = l('<i class="fa fa-headphones"></i> ' . t('Session Audio'), 'node/' . $session, array("attributes" => array("target" => "_blank"), 'html' => TRUE));
        }
      }
      ?>
      <div class="side-right"><div class="title"><?php print $program["session_title"]; ?></div> 
        <div class="listing-detail"><div class="section-part"><?php print $output_story_title. ' '. $output_photo . ' ' . $output_video . ' ' . $output_audio; ?></div>
          <div class="profile-detail">
            <?php
            foreach ($program['speaker'] as $speaker) {
              $spk_detail = itg_event_backend_get_speaker_details($speaker['target_id']);
              print '<div class="profile-loop"><label>Speaker:</label>';
              $spk_title = '<div class="speaker-title"><a href="'.$baseurl.'node/'.$spk_detail[0]->nid.'" target="_blank">'.$spk_detail[0]->title.'</a></div>';
              $img = '<img src=' . image_style_url("event_speaker_program_72x72", $spk_detail[0]->uri) . '/>';
              print '<div class="speaker-image"><a href="'.$baseurl.'node/'.$spk_detail[0]->nid.'" target="_blank">'.$img.'</a></div>';
              print '<div class="speaker-designation">' . $spk_title . $spk_detail[0]->field_story_new_title_value . '</div></div>';
            }
            ?>
          </div></div></div> 
      <div class="side-left"><div class="time"><?php print $program["start_time"] . ' to ' . $program["end_time"]; ?> </div></div>
      <?php
    }
    print '</div>';
  }
  ?>
